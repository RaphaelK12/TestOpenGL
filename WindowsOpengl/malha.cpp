#include "StdAfx.h"
#include "shader.h"
#include "texture.h"
#include "material.h"
#include "malha.h"
#include "Utils.h"

std::vector<malha*> g_malha_list;

uint malha::g_count = 0;


malha::malha(void):
	count(0),
	mIndex(0),
	VBO(0),
	VAO(0),
	EBO(0),
	nIndex(0),
	nVertex(0)/*,
	pBuffers{0,0,0,0,0,0,0,0,0,0}*/
{
	g_count++;
	g_malha_list.push_back(this);
	mIndex = g_malha_list.size() - 1;
	mMaterial = new material("default");
	mMaterial->atach();
	//memset(pBuffers, 0, sizeof(pBuffers));
}

malha::~malha(void)
{
	pVertex.clear();
	pIndex.clear();

	pPosition.clear();
	pNormal.clear();
	pUv.clear();
	pColor.clear();

	pTangent.clear();
	pBiTangent.clear();
	pUv1.clear();
	pUv2.clear();
	pColor1.clear();
	pColor2.clear();

	name.clear();
	fileName.clear();

	glDeleteBuffers(sizeof(pBuffers) / sizeof(pBuffers[0]), pBuffers);
	memset(pBuffers, 0, sizeof(pBuffers));

	if (VBO)
		glDeleteBuffers(1, &VBO);
	if (EBO)
		glDeleteBuffers(1, &EBO);
	if (VAO)
		glDeleteVertexArrays(1, &VAO);
	if (mMaterial)
		mMaterial->detach();

	nVertex = 0;
	nIndex = 0;
	VBO = 0;
	EBO = 0;
	VAO = 0;
	mMaterial = NULL;

	if (g_malha_list.size() >= mIndex)
		g_malha_list[mIndex] = 0;
	g_count--;
}

void malha::free(void)
{
	pVertex.clear();
	pIndex.clear();

	pPosition.clear();
	pNormal.clear();
	pUv.clear();
	pColor.clear();
	
	pTangent.clear();
	pBiTangent.clear();
	pUv1.clear();
	pUv2.clear();
	pColor1.clear();
	pColor2.clear();
	
	name.clear();
	fileName.clear();

	glDeleteBuffers(sizeof(pBuffers)/sizeof(pBuffers[0]), pBuffers);
	memset(pBuffers, 0, sizeof(pBuffers));

	if (VBO)
		glDeleteBuffers(1, &VBO);
	if (EBO)
		glDeleteBuffers(1, &EBO);
	if (VAO)
		glDeleteVertexArrays(1, &VAO);
	if(mMaterial)
		mMaterial->detach();

	nVertex=0;
	nIndex=0;
	VBO = 0;
	EBO = 0;
	VAO = 0;
	mMaterial=NULL;
}

//	Maker basics
void malha::makeTorus(uint xres, uint yres, float3 size, float internSize){
	// refazer para adicionar um plano distorcido em torus para melhor mapeamento uv, 
	// precisa recalcular normais das bordas para evitar recortes.
	// fazer o mesmo com esfera.
	free();
	xres = max(xres,3);
	yres = max(yres,3);
	nVertex = xres*yres;
	nIndex = xres * yres * 2;

	pVertex.resize(nVertex);
	pIndex.resize(nIndex);

	float vx = PI/xres*2.0f, vy = PI/yres*2.0f;
	float px=0,py=0;
	// attributes
	uint p = 0, y = 0, x = 0;
	float	xb,// big circle x
			yb,// big circle y
			xs,// small circle x
			z;// small circle z: nedded because the size(/2)
	for (y = 0; y < yres; y++) {
		py = y * vy;
			z = cos(py) * size.z / 2;		// small circle z: nedded because the size(/2)
		for (x = 0; x < xres; x++) {
			px = x * vx;

			xb = sin(px) * size.x / 2;		// big circle x
			yb = cos(px) * size.y / 2;		// big circle y
			xs = internSize + sin(py) * size.x;		// small circle x
			//ys = cos(py) * size.y,		// small circle y
			pVertex[p].position = vec3(xb + (xs * xb), yb + (xs * yb), z);
			p++;
		}
	}


	//center
	p=0;
	y=0;
	x=y+xres;
	uint sx=x, sy=0;
	for(uint a=0 ; a < yres-1; a++){
		uint sx=x, sy=y;
		for(uint b=0 ; b < xres-1; b++, x++, y++){
			pIndex[p] = usvec3(y, x+1, x);
			p++;
			pIndex[p] = usvec3(y, y+1, x+1);
			p++;
		}
		pIndex[p] = usvec3(y, sx, x);
		p++;
		pIndex[p] = usvec3(y, sy, y+1);
		//pIndex[p] = usvec3(y, sx, x+1);
		//p++;
		//pIndex[p] = usvec3(y, sy-1, y+1);
		p++;
		x++;
		y++;
	}

	// booton
	for(x =0, y = nVertex - xres; y < nVertex && p<nIndex;){
		if(x>=xres)
			//pIndex[p] = usvec3(y-yres, x, x+1);
			pIndex[p] = usvec3(0, 0, 0);
		else
			pIndex[p] = usvec3(y, x+1, x);
		//pIndex[p] = usvec3(nVertex-1, y, y-1);
		p++;

		if(x>=xres)
			pIndex[p] = usvec3(0, 0, 0);
			//pIndex[p] = usvec3(y, y+1, x-xres);
		else
			pIndex[p] = usvec3(y, y+1, x+1);
		//pIndex[p] = usvec3(nVertex-1, y+1, y-1);
		p++;
		y++;
		x++;
	}

	pIndex[nIndex-2] = usvec3(xres-1, nVertex-1, 0);
	pIndex[nIndex-1] = usvec3(nVertex-xres, 0, nVertex-1);

	vec3 faceNormal;
	for(p = 0; p < nIndex; p++){
		faceNormal = calcNormal(pVertex[pIndex[p].x].position, pVertex[pIndex[p].y].position, pVertex[pIndex[p].z].position);
		pVertex[pIndex[p].x].normal += faceNormal;
		pVertex[pIndex[p].y].normal += faceNormal;
		pVertex[pIndex[p].z].normal += faceNormal;
	}
	for (p = 0; p < nVertex; p++){
		pVertex[p].normal = normalize(pVertex[p].normal);
	}
	for (p = 0; p < nVertex; p++){
		pVertex[p].uv = vec2(pVertex[p].position.x, pVertex[p].position.y+pVertex[p].position.z);
	}
	p=0;


	name = "Torus";

}

void malha::makeSphere(uint xres, uint yres, float3 size) {
	xres = min(max(abs(int(xres)), 3), 255);
	yres = min(max(abs(int(yres)) - 2, 1), 256);
	nVertex = xres * yres + 2;
	nIndex = xres * yres * 2;

	pVertex.resize(nVertex);
	//pNormal.resize(nVertex);
	pIndex.resize(nIndex);

	//vec3* v = new vec3[nVertex];
	//vec3* n = new vec3[nVertex];
	//usvec3* i = new usvec3[nIndex];

	float vx = PI / (xres + 0) * 2, vy = PI / (yres + 1);
	float px = 0, py = 0, pz = 0, spy = 0;
	uint p = 1, x, y;

	// vextex positions
	// top
	pVertex[0].position = vec3(0.0f, 0.0f, size.z);
	pVertex[0].normal = vec3(0.0f, 0.0f, 1.0f);
	// center
	vec3 vec;
	for (y = 1; y <= yres; y++) {
		for (x = 0; x < xres; x++) {
			px = x * vx; py = y * vy;
			spy = sin(py);
			vec = vec3(sin(px) * sin(py), cos(px) * sin(py), cos(py));

			pVertex[p].position = vec * size;
			//n[p] = vec;
			pVertex[p].normal = normalize(vec);
			//v[p] = vec3 (sin(px)*sin(py)*size.x, cos(py)*size.y, cos(px)*sin(py)*size.z);
			p++;
		}
	}
	// booton
	pVertex[p].position = vec3(0.0f, 0.0f, -size.z);
	pVertex[p].normal = vec3(0.0f, 0.0f, -1.0f);


	// indexes
	// top
	p = 0;
	for (y = 1; y < xres; y++) {
		pIndex[p] = usvec3(0, y + 1, y);
		p++;
	}
	pIndex[p] = usvec3(0, 1, y);
	p++;

	//center
	y = 1;
	x = y + xres;
	uint sx = x, sy = 0;
	for (uint a = 0; a < yres - 1; a++) {
		uint sx = x, sy = y;
		for (uint b = 0; b < xres - 1; b++, x++, y++) {
			pIndex[p] = usvec3(x, y, x + 1);
			p++;
			pIndex[p] = usvec3(x + 1, y, y + 1);
			p++;
		}
		pIndex[p] = usvec3(x, y, sx);
		p++;
		pIndex[p] = usvec3(y + 1, y, sy);
		//i[p] = usvec3(y, sx, x+1);
		//p++;
		//i[p] = usvec3(y, sy-1, y+1);

		p++;
		x++;
		y++;
	}

	// booton
	for (y = nVertex - xres; y < nVertex - 1; y++) {
		pIndex[p] = usvec3(nVertex - 1, y - 1, y);
		p++;
	}
	pIndex[p] = usvec3(nVertex - 1, y - 1, nVertex - xres - 1);

	for (p = 0; p < nVertex; p++) {
		pVertex[p].uv = vec2(pVertex[p].position.x, pVertex[p].position.y + pVertex[p].position.z);
	}
	p = 0;
	name = "Esfera";
}

void malha::makeTorus2(uint xres, uint yres, float3 size, float internSize){
	// refazer para adicionar um plano distorcido em torus para melhor mapeamento uv, 
	// precisa recalcular normais das bordas para evitar recortes.
	// fazer o mesmo com esfera.
	free();
	xres = max(xres,3);
	yres = max(yres,3);
	nVertex = xres*yres;
	nIndex = xres * yres * 2;

	pVertex.resize(nVertex);
	pIndex.resize(nIndex);

	float vx = PI/xres*2.0f, vy = PI/yres*2.0f;
	float px=0,py=0;
	// attributes
	uint p = 0, y = 0, x = 0;
	float	xb,// big circle x
			yb,// big circle y
			xs,// small circle x
			z;// small circle z: nedded because the size(/2)
	for (y = 0; y < yres; y++) {
		py = y * vy;
			z = cos(py) * size.z / 2;		// small circle z: nedded because the size(/2)
		for (x = 0; x < xres; x++) {
			px = x * vx;

			xb = sin(px) * size.x / 2;		// big circle x
			yb = cos(px) * size.y / 2;		// big circle y
			xs = internSize + sin(py) * size.x;		// small circle x
			//ys = cos(py) * size.y,		// small circle y
			pVertex[p].position = vec3(xb + (xs * xb), yb + (xs * yb), z);
			p++;
		}
	}


	//center
	p=0;
	y=0;
	x=y+xres;
	uint sx=x, sy=0;
	for(uint a=0 ; a < yres-1; a++){
		uint sx=x, sy=y;
		for(uint b=0 ; b < xres-1; b++, x++, y++){
			pIndex[p] = usvec3(y, x, x+1);
			p++;
			pIndex[p] = usvec3(y, x+1, y+1);
			p++;
		}
		pIndex[p] = usvec3(y, x, sx);
		p++;
		pIndex[p] = usvec3(y, y+1, sy);
		//pIndex[p] = usvec3(y, sx, x+1);
		//p++;
		//pIndex[p] = usvec3(y, sy-1, y+1);
		p++;
		x++;
		y++;
	}

	// booton
	for(x =0, y = nVertex - xres; y < nVertex && p<nIndex;){
		if(x>=xres)
			//pIndex[p] = usvec3(y-yres, x, x+1);
			pIndex[p] = usvec3(0, 0, 0);
		else
			pIndex[p] = usvec3(y, x, x+1);
		//pIndex[p] = usvec3(nVertex-1, y, y-1);
		p++;

		if(x>=xres)
			pIndex[p] = usvec3(0, 0, 0);
			//pIndex[p] = usvec3(y, y+1, x-xres);
		else
			pIndex[p] = usvec3(y, x+1, y+1);
		//pIndex[p] = usvec3(nVertex-1, y+1, y-1);
		p++;
		y++;
		x++;
	}

	pIndex[nIndex-2] = usvec3(xres-1, 0, nVertex-1);
	pIndex[nIndex-1] = usvec3(nVertex-xres, nVertex-1, 0);

	vec3 faceNormal;
	for(p = 0; p < nIndex; p++){
		faceNormal = calcNormal(pVertex[pIndex[p].x].position, pVertex[pIndex[p].y].position, pVertex[pIndex[p].z].position);
		pVertex[pIndex[p].x].normal += faceNormal;
		pVertex[pIndex[p].y].normal += faceNormal;
		pVertex[pIndex[p].z].normal += faceNormal;
	}
	for (p = 0; p < nVertex; p++){
		pVertex[p].normal = normalize(pVertex[p].normal);
	}
	for (p = 0; p < nVertex; p++){
		pVertex[p].uv = vec2(pVertex[p].position.x, pVertex[p].position.y+pVertex[p].position.z);
	}
	p=0;




}

void malha::makeSphere2(uint xres, uint yres, float3 size) {
	xres = min(max(abs(int(xres)), 3), 255);
	yres = min(max(abs(int(yres)) - 2, 1), 256);
	nVertex = xres * yres + 2;
	nIndex = xres * yres * 2;

	pVertex.resize(nVertex);
	//pNormal.resize(nVertex);
	pIndex.resize(nIndex);

	//vec3* v = new vec3[nVertex];
	//vec3* n = new vec3[nVertex];
	//usvec3* i = new usvec3[nIndex];

	float vx = PI / (xres + 0) * 2, vy = PI / (yres + 1);
	float px = 0, py = 0, pz = 0, spy = 0;
	uint p = 1, x, y;

	// vextex positions
	// top
	pVertex[0].position = vec3(0.0f, 0.0f, size.z);
	pVertex[0].normal = vec3(0.0f, 0.0f, 1.0f);
	// center
	vec3 vec;
	for (y = 1; y <= yres; y++) {
		for (x = 0; x < xres; x++) {
			px = x * vx; py = y * vy;
			spy = sin(py);
			vec = vec3(sin(px) * sin(py), cos(px) * sin(py), cos(py));

			pVertex[p].position = vec * size;
			//n[p] = vec;
			pVertex[p].normal = normalize(vec);
			//v[p] = vec3 (sin(px)*sin(py)*size.x, cos(py)*size.y, cos(px)*sin(py)*size.z);
			p++;
		}
	}
	// booton
	pVertex[p].position = vec3(0.0f, 0.0f, -size.z);
	pVertex[p].normal = vec3(0.0f, 0.0f, -1.0f);


	// indexes
	// top
	p = 0;
	for (y = 1; y < xres; y++) {
		pIndex[p] = usvec3(0, y + 1, y);
		p++;
	}
	pIndex[p] = usvec3(0, 1, y);
	p++;

	//center
	y = 1;
	x = y + xres;
	uint sx = x, sy = 0;
	for (uint a = 0; a < yres - 1; a++) {
		uint sx = x, sy = y;
		for (uint b = 0; b < xres - 1; b++, x++, y++) {
			pIndex[p] = usvec3(x, y, x + 1);
			p++;
			pIndex[p] = usvec3(x + 1, y, y + 1);
			p++;
		}
		pIndex[p] = usvec3(x, y, sx);
		p++;
		pIndex[p] = usvec3(y + 1, y, sy);
		//i[p] = usvec3(y, sx, x+1);
		//p++;
		//i[p] = usvec3(y, sy-1, y+1);

		p++;
		x++;
		y++;
	}

	// booton
	for (y = nVertex - xres; y < nVertex - 1; y++) {
		pIndex[p] = usvec3(nVertex - 1, y - 1, y);
		p++;
	}
	pIndex[p] = usvec3(nVertex - 1, y - 1, nVertex - xres - 1);

	for (p = 0; p < nVertex; p++) {
		pVertex[p].uv = vec2(pVertex[p].position.x, pVertex[p].position.y + pVertex[p].position.z);
	}
	p = 0;

}

void malha::makeCone2(uint xres, uint yres, float3 size){
	free();
	xres = min(max(abs(int(xres)), 3), 255);
	yres = 1;
	nVertex = xres * 2 * yres + 2;
	nIndex = xres * yres * 2;

	pVertex.resize(nVertex);
	//pNormal.resize(nVertex);
	pIndex.resize(nIndex);

	//vec3* v = new vec3[nVertex];
	//vec3* n = new vec3[nVertex];
	//usvec3* i = new usvec3[nIndex];

	float vx = PI / (xres + 0) * 2, vy = PI / (yres + 1);
	float px = 0, py = 0, pz = 0, spy = 0;
	uint p = 1, x, y;

	// vextex positions
	// top
	pVertex[0].position = vec3(0.0f, 0.0f, size.z);
	pVertex[0].normal = vec3(0.0f, 0.0f, 1.0f);
	// center
	vec3 vec;
	y = 1; 
	{
		for (x = 0; x < xres; x++) {
			px = x * vx; py = y * vy;
			spy = sin(py);
			vec = vec3(sin(px) * spy, cos(px) * sin(py), 0);
			pVertex[p].position = vec * size;
			p++;
		}
	}
	y = 1; 
	{
		for (x = 0; x < xres; x++) {
			px = x * vx; py = y * vy;
			spy = sin(py);
			vec = vec3(sin(px) * spy, cos(px) * sin(py), 0);
			pVertex[p].position = vec * size;
			p++;
		}
	}
	// booton
	pVertex[p].position = vec3(0.0f, 0.0f, 0);
	pVertex[p].normal = vec3(0.0f, 0.0f, -1.0f);


	// indexes
	// top
	p = 0;
	for (y = 1; y < xres; y++) {
		pIndex[p] = usvec3(0, y + 1, y);
		p++;
	}
	pIndex[p] = usvec3(0, 1, y);
	p++;


	// booton
	for (y = nVertex - xres; y < nVertex - 1; y++) {
		pIndex[p] = usvec3(nVertex - 1, y - 1, y);
		p++;
	}
	pIndex[p] = usvec3(nVertex - 1, y - 1, nVertex - xres - 1);

	for (p = 0; p < nVertex; p++) {
		pVertex[p].uv = vec2(pVertex[p].position.x, pVertex[p].position.y + pVertex[p].position.z);
	}
	p = 0;
	name = "Cone";
}

void malha::makeCone(uint xres, uint yres, float3 size) {
	// refazer para adicionar um plano distorcido em torus para melhor mapeamento uv, 
	// precisa recalcular normais das bordas para evitar recortes.
	// fazer o mesmo com esfera.
	free();
	xres = max(xres, 3);
	yres = 1;
	nVertex = xres * 3 + 1;
	nIndex = xres * 4 * 2;

	pVertex.resize(nVertex);
	pIndex.resize(nIndex);

	float vx = PI / (xres + 0) * 2, vy = PI / (yres + 1);
	float px = 0, py = 0, pz = 0, spy = 0;
	uint p = 0, x, y;

	// vextex positions
	// top
	vec3 vec;
	// center
	y = 1;
	{
		for (x = 0; x < xres; x++) {
			vec = vec3(0,0, 0.5f);
			pVertex[p].position = vec * size;
			p++;
		}
	}

	y = 1;
	{
		for (x = 0; x < xres; x++) {
			px = x * vx; py = y * vy;
			spy = sin(py);
			vec = vec3(sin(px) * spy, cos(px) * sin(py), -0.5f);
			pVertex[p].position = vec * size;
			p++;
		}
	}
	// booton
	y = 1;
	{
		for (x = 0; x < xres; x++) {
			px = x * vx; py = y * vy;
			spy = sin(py);
			vec = vec3(sin(px) * spy, cos(px) * sin(py), -0.5f);
			pVertex[p].position = vec * size;
			p++;
		}
	}
	pVertex[p].position = vec3(0.0f, 0.0f, -0.5f);


	// indexes
	// top
	// center
	p = 0;
	y = 0;
	x = y + xres;
	uint sx = x, sy = 0;
	{
		uint sx = x, sy = y;
		for (uint b = 0; b < xres - 1; b++, x++, y++) {
			pIndex[p] = usvec3(y, x + 1, x);
			p++;
			p++;
		}
		pIndex[p] = usvec3(y, sx, x);
		p++;
		pIndex[p] = usvec3(y, sy, y + 1);
		p++;
		x++;
		y++;
	}


	// booton
	for (y = nVertex - xres; y < nVertex - 1; y++) {
		pIndex[p] = usvec3(nVertex - 1, y - 1, y);
		p++;
	}
	pIndex[p] = usvec3(nVertex - 1, y - 1, nVertex - xres - 1);


	vec3 faceNormal;
	for (p = 0; p < nIndex; p++) {
		faceNormal = calcNormal(pVertex[pIndex[p].x].position, pVertex[pIndex[p].y].position, pVertex[pIndex[p].z].position);
		pVertex[pIndex[p].x].normal += faceNormal;
		pVertex[pIndex[p].y].normal += faceNormal;
		pVertex[pIndex[p].z].normal += faceNormal;
	}
	for (p = 0; p < nVertex; p++) {
		pVertex[p].normal = normalize(pVertex[p].normal);
	}
	for (p = 0; p < nVertex; p++) {
		pVertex[p].uv = vec2(pVertex[p].position.x, pVertex[p].position.y + pVertex[p].position.z);
	}
	p = 0;

	name = "Cilinder";
}

void malha::makeCilinder(uint xres, uint yres, float3 size) {
	// refazer para adicionar um plano distorcido em torus para melhor mapeamento uv, 
	// precisa recalcular normais das bordas para evitar recortes.
	// fazer o mesmo com esfera.
	free();
	xres = max(xres, 3);
	yres = 1;
	nVertex = xres * 4 + 2;
	nIndex = xres * 4 * 2;

	pVertex.resize(nVertex);
	pIndex.resize(nIndex);

	float vx = PI / (xres + 0) * 2, vy = PI / (yres + 1);
	float px = 0, py = 0, pz = 0, spy = 0;
	uint p = 1, x, y;

	// vextex positions
	// top
	pVertex[0].position = vec3(0.0f, 0.0f, 0.5f*size.z);
	//pVertex[0].normal = vec3(0.0f, 0.0f, 1.0f);
	vec3 vec;
	y = 1;
	{
		for (x = 0; x < xres; x++) {
			px = x * vx; py = y * vy;
			spy = sin(py);
			vec = vec3(sin(px) * spy, cos(px) * sin(py), 0.5f);
			pVertex[p].position = vec * size;
			p++;
		}
	}
	// center
	y = 1;
	{
		for (x = 0; x < xres; x++) {
			px = x * vx; py = y * vy;
			spy = sin(py);
			vec = vec3(sin(px) * spy, cos(px) * sin(py), 0.5f);
			pVertex[p].position = vec * size;
			p++;
		}
	}

	y = 1;
	{
		for (x = 0; x < xres; x++) {
			px = x * vx; py = y * vy;
			spy = sin(py);
			vec = vec3(sin(px) * spy, cos(px) * sin(py), -0.5f);
			pVertex[p].position = vec * size;
			p++;
		}
	}
	// booton
	y = 1;
	{
		for (x = 0; x < xres; x++) {
			px = x * vx; py = y * vy;
			spy = sin(py);
			vec = vec3(sin(px) * spy, cos(px) * sin(py), -0.5f);
			pVertex[p].position = vec * size;
			p++;
		}
	}
	pVertex[p].position = vec3(0.0f, 0.0f, -0.5f);
	//pVertex[p].normal = vec3(0.0f, 0.0f, -1.0f);


// indexes
// top
	p = 0;
	for (y = 1; y < xres; y++) {
		pIndex[p] = usvec3(0, y + 1, y);
		p++;
	}
	pIndex[p] = usvec3(0, 1, y);
	p++;

	//center
	//p = 0;
	y = 1 + xres;
	x = y + xres;
	uint sx = x, sy = 0;
	{
		uint sx = x, sy = y;
		for (uint b = 0; b < xres - 1; b++, x++, y++) {
			pIndex[p] = usvec3(y, x + 1, x);
			p++;
			pIndex[p] = usvec3(y, y + 1, x + 1);
			p++;
		}
		pIndex[p] = usvec3(y, sx, x);
		p++;
		pIndex[p] = usvec3(y, sy, y + 1);
		//pIndex[p] = usvec3(y, sx, x+1);
		//p++;
		//pIndex[p] = usvec3(y, sy-1, y+1);
		p++;
		x++;
		y++;
	}


	// booton
	for (y = nVertex - xres; y < nVertex - 1; y++) {
		pIndex[p] = usvec3(nVertex - 1, y - 1, y);
		p++;
	}
	pIndex[p] = usvec3(nVertex - 1, y - 1, nVertex - xres - 1);


	vec3 faceNormal;
	for (p = 0; p < nIndex; p++) {
		faceNormal = calcNormal(pVertex[pIndex[p].x].position, pVertex[pIndex[p].y].position, pVertex[pIndex[p].z].position);
		pVertex[pIndex[p].x].normal += faceNormal;
		pVertex[pIndex[p].y].normal += faceNormal;
		pVertex[pIndex[p].z].normal += faceNormal;
	}
	for (p = 0; p < nVertex; p++) {
		pVertex[p].normal = normalize(pVertex[p].normal);
	}
	for (p = 0; p < nVertex; p++) {
		pVertex[p].uv = vec2(pVertex[p].position.x, pVertex[p].position.y + pVertex[p].position.z);
	}
	p = 0;


	name = "Cilinder";

}

void malha::makeBox(uint xres, uint yres, float3 size) {
	free();
	nVertex = 24;
	nIndex = 12;

	pPosition.resize(nVertex);
	pNormal.resize(nVertex);
	pIndex.resize(nIndex);

	vec3 sz = vec3(0.5f, 0.5f, 0.5f) * size;


	pPosition[0]  = vec3(-1, -1, -1) * sz;  // frente
	pPosition[1]  = vec3(-1, -1,  1) * sz;  
	pPosition[2]  = vec3( 1, -1, -1) * sz;  
	pPosition[3]  = vec3( 1, -1,  1) * sz;  
										    
	pPosition[4]  = vec3( 1, -1, -1) * sz;  // direita
	pPosition[5]  = vec3( 1,  1, -1) * sz;  
	pPosition[6]  = vec3( 1, -1,  1) * sz;  
	pPosition[7]  = vec3( 1,  1,  1) * sz;  
										    
	pPosition[8]  = vec3( 1,  1, -1) * sz;  // tras
	pPosition[9]  = vec3( 1,  1,  1) * sz;  
	pPosition[10] = vec3(-1,  1, -1) * sz;  
	pPosition[11] = vec3(-1,  1,  1) * sz;  
										    
	pPosition[12] = vec3(-1,  1, -1) * sz;  // esquerda
	pPosition[13] = vec3(-1,  1,  1) * sz;  
	pPosition[14] = vec3(-1, -1, -1) * sz;  
	pPosition[15] = vec3(-1, -1,  1) * sz;  
										    
	pPosition[16] = vec3(-1, -1, -1) * sz;  // baixo
	pPosition[17] = vec3(-1,  1, -1) * sz;  
	pPosition[18] = vec3( 1, -1, -1) * sz;  
	pPosition[19] = vec3( 1,  1, -1) * sz;  
							 			    
	pPosition[20] = vec3(-1,  1,  1) * sz;  // cima
	pPosition[21] = vec3(-1, -1,  1) * sz;
	pPosition[22] = vec3( 1,  1,  1) * sz;
	pPosition[23] = vec3( 1, -1,  1) * sz;


	pIndex[0]  = usvec3( 0,  2,  1); // baixo
	pIndex[1]  = usvec3( 1,  2,  3);
			   
	pIndex[2]  = usvec3( 4,  5,  6); // frente
	pIndex[3]  = usvec3( 5,  7,  6);
			   
	pIndex[4]  = usvec3( 8, 10,  9); // cima
	pIndex[5]  = usvec3( 9, 10, 11);
			   
	pIndex[6]  = usvec3(12, 14, 13); // traz
	pIndex[7]  = usvec3(13, 14, 15);
			   
	pIndex[8]  = usvec3(16, 17, 18); // direita
	pIndex[9]  = usvec3(17, 19, 18);

	pIndex[10] = usvec3(20, 21, 22); // esquerda
	pIndex[11] = usvec3(21, 23, 22);


	vec3 faceNormal;
	for (uint p = 0; p < nIndex; p++) {
		faceNormal = calcNormal(pPosition[pIndex[p].x], pPosition[pIndex[p].y], pPosition[pIndex[p].z]);
		pNormal[pIndex[p].x] += faceNormal;
		pNormal[pIndex[p].y] += faceNormal;
		pNormal[pIndex[p].z] += faceNormal;
	}
	for (uint p = 0; p < nVertex; p++) {
		pNormal[p] = normalize(pNormal[p]);
	}
}

void malha::makeQuad(uint xres, uint yres, float3 size){
	free();
	nVertex = 4;
	nIndex = 2;

	pVertex.resize(nVertex);
	pIndex.resize(nIndex);
	vec3 sz = vec3(0.5f, 0.5f, 0.5f)*size;

	// vertex
	pVertex[0].position = vec3(-1, -1, 0) * sz;
	pVertex[1].position = vec3(-1,  1, 0) * sz;
	pVertex[2].position = vec3( 1, -1, 0) * sz;
	pVertex[3].position = vec3( 1,  1, 0) * sz;

	// index
	pIndex[0] = usvec3(0, 1, 2);
	pIndex[1] = usvec3(1, 2, 3);

	// uv
	pVertex[0].uv = vec2(-1, -1);
	pVertex[1].uv = vec2(-1,  1);
	pVertex[2].uv = vec2( 1, -1);
	pVertex[3].uv = vec2( 1,  1);

	// color
	pVertex[0].color = byte4(255, 255, 255, 255);
	pVertex[1].color = byte4(255, 255, 255, 255);
	pVertex[2].color = byte4(255, 255, 255, 255);
	pVertex[3].color = byte4(255, 255, 255, 255);

	// normal
	pVertex[0].normal = calcNormal(pVertex[pIndex[0].x].position, pVertex[pIndex[0].y].position, pVertex[pIndex[0].z].position);

	pVertex[0].normal = normalize(pVertex[0].normal);
	pVertex[1].normal = pVertex[0].normal;
	pVertex[2].normal = pVertex[0].normal;
	pVertex[3].normal = pVertex[0].normal;


}

void malha::makeTriangle(uint xres, uint yres, float3 size) {
	free();
	nVertex = 3;
	nIndex = 1;

	pVertex.resize(nVertex);
	pIndex.resize(nIndex);
	vec3 sz = vec3(0.5f, 0.5f, 0.5f) * size;

	// vertex
	pVertex[0].position = vec3(-1, -1, 0) * sz;
	pVertex[1].position = vec3( 0,  1, 0) * sz;
	pVertex[2].position = vec3( 1, -1, 0) * sz;

	// index
	pIndex[0] = usvec3(0, 1, 2);

	// uv
	pVertex[0].uv = vec2(  0, 0);
	pVertex[1].uv = vec2(0.5, 1);
	pVertex[2].uv = vec2(  1, 0);

	// color
	pVertex[0].color = byte4(255, 255, 255, 255);
	pVertex[1].color = byte4(255, 255, 255, 255);
	pVertex[2].color = byte4(255, 255, 255, 255);

	// normal
	pVertex[0].normal = calcNormal(pVertex[pIndex[0].x].position, pVertex[pIndex[0].y].position, pVertex[pIndex[0].z].position);

	pVertex[0].normal = normalize(pVertex[0].normal);
	pVertex[1].normal = pVertex[0].normal;
	pVertex[2].normal = pVertex[0].normal;
}

void malha::makeNormals() {
	int p = 0;
	if(pVertex.size()>2 && pIndex.size() >= 1 && nVertex == (pVertex.size()-1) && nIndex == pIndex.size() - 1){
		vec3 faceNormal;
		for (p = 0; p < nIndex; p++) {
			faceNormal = calcNormal(pVertex[pIndex[p].x].position, pVertex[pIndex[p].y].position, pVertex[pIndex[p].z].position);
			pVertex[pIndex[p].x].normal += faceNormal;
			pVertex[pIndex[p].y].normal += faceNormal;
			pVertex[pIndex[p].z].normal += faceNormal;
		}
		for (p = 0; p < nVertex; p++) {
			pVertex[p].normal = normalize(pVertex[p].normal);
		}
	}
	else if (pPosition.size() > 2 && pIndex.size() >= 1 && nVertex == (pPosition.size() - 1) && nIndex == pIndex.size() - 1) {
		if(pNormal.size() != nVertex)
			pNormal.resize(nVertex);
		vec3 faceNormal;
		for (p = 0; p < nIndex; p++) {
			faceNormal = calcNormal(pPosition[pIndex[p].x], pPosition[pIndex[p].y], pPosition[pIndex[p].z]);
			pNormal[pIndex[p].x] += faceNormal;
			pNormal[pIndex[p].y] += faceNormal;
			pNormal[pIndex[p].z] += faceNormal;
		}
		for (p = 0; p < nVertex; p++) {
			pNormal[p] = normalize(pNormal[p]);
		}
	}
}

void malha::CreateBuffer() {
	// standard mesh with position, normal, uv and color interleaved
	if (nVertex > 1 && pVertex.size() == nVertex && nIndex)
	{
		int i = pVertex.size();
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, pVertex.size() * sizeof(pVertex[0]), pVertex.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, pIndex.size() * sizeof(pIndex[0]), pIndex.data(), GL_STATIC_DRAW);

		// vertex positions
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)0); // (void*)offsetof(vertex, position))
		// vertex normals
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, normal));
		// vertex texture coords
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, uv));
		// vertex color
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 4, GL_BYTE, GL_TRUE, sizeof(vertex), (void*)offsetof(vertex, color));

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

	}
	// not interleaved atributes, need position and any other atribute is not required, but if available is used
	else if (nVertex > 1 && pPosition.size() == nVertex && nIndex)
	{
		glGenVertexArrays(1, &VAO);
		//glCreateVertexArrays(1, &VAO);// Create the vertex array object
		glGenBuffers(sizeof(pBuffers) / sizeof(pBuffers[0]), &pBuffers[0]);// Get create then buffers
		//glCreateBuffers(4, &buffer[0]);// Get create two buffers
		glGenBuffers(1, &EBO);
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(VAO);
		//glGenBuffers(1, &VBO);
		//glBindBuffer(GL_ARRAY_BUFFER, VBO);
		//glBufferData(GL_ARRAY_BUFFER, pVertex.size() * sizeof(pVertex[0]), pVertex.data(), GL_STATIC_DRAW);
		uint i = 0;
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, pIndex.size() * sizeof(pIndex[0]), pIndex.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, pBuffers[i]);
		glNamedBufferStorage(pBuffers[i], pPosition.size() * sizeof(pPosition[0]), pPosition.data(), 0);// Initialize the first buffer
		glVertexArrayVertexBuffer(VAO, i, pBuffers[i], 0, sizeof(pPosition[0]));// Bind it to the vertex array - offset zero, stride = sizeof(vec3)
		glVertexArrayAttribFormat(VAO, i, 3, GL_FLOAT, GL_FALSE, 0);// Tell OpenGL what the format of the attribute is
		glVertexArrayAttribBinding(VAO, i, i);// Tell OpenGL which vertex buffer binding to use for this attribute
		glEnableVertexArrayAttrib(VAO, i);// Enable the attribute
		glEnableVertexAttribArray(i);
		i++;
		if (pNormal.size() == nVertex) {
			glBindBuffer(GL_ARRAY_BUFFER, pBuffers[i]);
			glNamedBufferStorage(pBuffers[i], pNormal.size() * sizeof(pNormal[0]), pNormal.data(), 0);// Perform similar initialization for the second buffer
			glVertexArrayVertexBuffer(VAO, i, pBuffers[i], 0, sizeof(pNormal[0]));
			glVertexArrayAttribFormat(VAO, i, 3, GL_FLOAT, GL_FALSE, 0);
			glVertexArrayAttribBinding(VAO, i, i);
			glEnableVertexAttribArray(i);
		}
		i++;
		if (pUv.size() == nVertex) {
			glBindBuffer(GL_ARRAY_BUFFER, pBuffers[i]);
			glNamedBufferStorage(pBuffers[i], pUv.size() * sizeof(pUv[0]), pUv.data(), 0);// Perform similar initialization for the second buffer
			glVertexArrayVertexBuffer(VAO, i, pBuffers[i], 0, sizeof(pUv[0]));
			glVertexArrayAttribFormat(VAO, i, 2, GL_FLOAT, GL_FALSE, 0);
			glVertexArrayAttribBinding(VAO, i, i);
			glEnableVertexAttribArray(i);
		}
		i++;
		if (pColor.size() == nVertex) {
			glBindBuffer(GL_ARRAY_BUFFER, pBuffers[i]);
			glNamedBufferStorage(pBuffers[i], pColor.size() * sizeof(pColor[0]), pColor.data(), 0);// Perform similar initialization for the second buffer
			glVertexArrayVertexBuffer(VAO, i, pBuffers[i], 0, sizeof(pColor[0]));
			glVertexArrayAttribFormat(VAO, i, 4, GL_BYTE, GL_FALSE, 0);
			glVertexArrayAttribBinding(VAO, i, i);
			glEnableVertexAttribArray(i);
		}
		i++;
		if (pTangent.size() == nVertex) {
			glBindBuffer(GL_ARRAY_BUFFER, pBuffers[i]);
			glNamedBufferStorage(pBuffers[i], pTangent.size() * sizeof(pTangent[0]), pTangent.data(), 0);// Perform similar initialization for the second buffer
			glVertexArrayVertexBuffer(VAO, i, pBuffers[i], 0, sizeof(pTangent[0]));
			glVertexArrayAttribFormat(VAO, i, 3, GL_FLOAT, GL_FALSE, 0);
			glVertexArrayAttribBinding(VAO, i, i);
			glEnableVertexAttribArray(i);
		}
		i++;
		if (pBiTangent.size() == nVertex) {
			glBindBuffer(GL_ARRAY_BUFFER, pBuffers[i]);
			glNamedBufferStorage(pBuffers[i], pBiTangent.size() * sizeof(pBiTangent[0]), pBiTangent.data(), 0);// Perform similar initialization for the second buffer
			glVertexArrayVertexBuffer(VAO, i, pBuffers[i], 0, sizeof(pBiTangent[0]));
			glVertexArrayAttribFormat(VAO, i, 3, GL_FLOAT, GL_FALSE, 0);
			glVertexArrayAttribBinding(VAO, i, i);
			glEnableVertexAttribArray(i);
		}
		i++;
		if (pUv1.size() == nVertex) {
			glBindBuffer(GL_ARRAY_BUFFER, pBuffers[i]);
			glNamedBufferStorage(pBuffers[i], pUv1.size() * sizeof(pUv1[0]), pUv1.data(), 0);// Perform similar initialization for the second buffer
			glVertexArrayVertexBuffer(VAO, i, pBuffers[i], 0, sizeof(pUv1[0]));
			glVertexArrayAttribFormat(VAO, i, 2, GL_FLOAT, GL_FALSE, 0);
			glVertexArrayAttribBinding(VAO, i, i);
			glEnableVertexAttribArray(i);
		}
		i++;
		if (pUv2.size() == nVertex) {
			glBindBuffer(GL_ARRAY_BUFFER, pBuffers[i]);
			glNamedBufferStorage(pBuffers[i], pUv2.size() * sizeof(pUv2[0]), pUv2.data(), 0);// Perform similar initialization for the second buffer
			glVertexArrayVertexBuffer(VAO, i, pBuffers[i], 0, sizeof(pUv2[0]));
			glVertexArrayAttribFormat(VAO, i, 2, GL_FLOAT, GL_FALSE, 0);
			glVertexArrayAttribBinding(VAO, i, i);
			glEnableVertexAttribArray(i);
		}
		i++;
		if (pColor1.size() == nVertex) {
			glBindBuffer(GL_ARRAY_BUFFER, pBuffers[i]);
			glNamedBufferStorage(pBuffers[i], pColor1.size() * sizeof(pColor1[0]), pColor1.data(), 0);// Perform similar initialization for the second buffer
			glVertexArrayVertexBuffer(VAO, i, pBuffers[i], 0, sizeof(pColor1[0]));
			glVertexArrayAttribFormat(VAO, i, 4, GL_BYTE, GL_FALSE, 0);
			glVertexArrayAttribBinding(VAO, i, i);
			glEnableVertexAttribArray(i);
		}
		i++;
		if (pColor2.size() == nVertex) {
			glBindBuffer(GL_ARRAY_BUFFER, pBuffers[i]);
			glNamedBufferStorage(pBuffers[i], pColor2.size() * sizeof(pColor2[0]), pColor2.data(), 0);// Perform similar initialization for the second buffer
			glVertexArrayVertexBuffer(VAO, i, pBuffers[i], 0, sizeof(pColor2[0]));
			glVertexArrayAttribFormat(VAO, i, 4, GL_BYTE, GL_FALSE, 0);
			glVertexArrayAttribBinding(VAO, i, i);
			glEnableVertexAttribArray(i);
		}
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	// example bindlles buffers
	if(0){
		GLuint buffer[2];
		GLuint vao;
		static const GLfloat positions[] = { 1 };
		static const GLfloat colors[] = { 1 };
		glCreateVertexArrays(1, &vao);// Create the vertex array object
		glCreateBuffers(2, &buffer[0]);// Get create two buffers
		glNamedBufferStorage(buffer[0], sizeof(positions), positions, 0);// Initialize the first buffer
		glVertexArrayVertexBuffer(vao, 0, buffer[0], 0, sizeof(vec3));// Bind it to the vertex array - offset zero, stride = sizeof(vec3)
		glVertexArrayAttribFormat(vao, 0, 3, GL_FLOAT, GL_FALSE, 0);// Tell OpenGL what the format of the attribute is
		glVertexArrayAttribBinding(vao, 0, 0);// Tell OpenGL which vertex buffer binding to use for this attribute
		glEnableVertexArrayAttrib(vao, 0);// Enable the attribute
		glNamedBufferStorage(buffer[1], sizeof(colors), colors, 0);// Perform similar initialization for the second buffer
		glVertexArrayVertexBuffer(vao, 1, buffer[1], 0, sizeof(vec3));
		glVertexArrayAttribFormat(vao, 1, 3, GL_FLOAT, GL_FALSE, 0);
		glVertexArrayAttribBinding(vao, 1, 1);
		glEnableVertexAttribArray(1);
	}	
	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	//glBindVertexArray(0);	   
}

void malha::setMatrix(matrix_block* m) {
	if (mMaterial) {
		mMaterial->active(m);
	}
	else {
		mMaterial = new material("default");
		mMaterial->atach();
		mMaterial->active(m);
	}
}

void malha::draw(matrix_block *m){
	if (!VAO)
		CreateBuffer();
	setMatrix(m);
	glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glDrawElements(GL_TRIANGLES, pIndex.size()*sizeof(pIndex[0])/2, GL_UNSIGNED_SHORT, 0);
	glBindVertexArray(0);
}

int malha::atach() {
	count++;
	return count;
}

void malha::detach() {
	count--;
	if (count <= 0) {
		g_malha_list[mIndex] = NULL;
		delete this;
	}
}





