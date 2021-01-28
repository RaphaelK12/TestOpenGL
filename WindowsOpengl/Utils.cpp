#include "stdafx.h"
#include "Utils.h"

inline float deg (float n) {
	return n/RADIANS_PER_DEGREE;
}
inline float rad (float n) {
	return n*RADIANS_PER_DEGREE;
}

//inline double deg (double n) {
//	return n/RADIANS_PER_DEGREE;
//}
//inline double rad (double n) {
//	return n*RADIANS_PER_DEGREE;
//}


float3 rotate_around_axis(float3& p, float3& axis, float angle)
{
	float costheta = cosf(angle);
	float sintheta = sinf(angle);
	float3 r;

	r.x = ((costheta + (1 - costheta) * axis.x * axis.x) * p.x) +
		(((1 - costheta) * axis.x * axis.y - axis.z * sintheta) * p.y) +
		(((1 - costheta) * axis.x * axis.z + axis.y * sintheta) * p.z);

	r.y = (((1 - costheta) * axis.x * axis.y + axis.z * sintheta) * p.x) +
		((costheta + (1 - costheta) * axis.y * axis.y) * p.y) +
		(((1 - costheta) * axis.y * axis.z - axis.x * sintheta) * p.z);

	r.z = (((1 - costheta) * axis.x * axis.z - axis.y * sintheta) * p.x) +
		(((1 - costheta) * axis.y * axis.z + axis.x * sintheta) * p.y) +
		((costheta + (1 - costheta) * axis.z * axis.z) * p.z);

	return r;
}

GLuint compile_shaders(const GLchar* vertex_shader_source, const GLchar* fragment_shader_source)
{
	GLuint vertex_shader;
	GLuint fragment_shader;
	GLuint program;
	const GLchar** vs = &vertex_shader_source;
	const GLchar** fs = &fragment_shader_source;

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, vs, NULL);
	glCompileShader(vertex_shader);

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, fs, NULL);
	glCompileShader(fragment_shader);

	program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	return program;
}

void drawRandPoints(int num) {
	srand(5);
	glPointSize(1.5);
	vec3 a;
	glBegin(GL_POINTS);
	glColor3f(1.2f, 1.f, 0.f);
	for (int i = 0; i < num; i++) {
		float r = rand() / 40000.f, g = rand() / 40000.f - rand() / 40000.f;

		a.x = pow(r, 0.125f) * sin(i * 0.1f * g) * 0.5f;
		a.y = pow(r, 0.125f) * cos(i * 0.1f * g) * 0.5f;
		a.z = pow(g, 0.5f) / 10.f;
		//b.x=sin(rand()/(long double)40000.0);
		//b.y=sin(rand()/(long double)40000.0);
		//b.z=sin(rand()/(long double)40000.0);
		//c.x=sin(rand()/(long double)40000.0);
		//c.y=sin(rand()/(long double)40000.0);
		//c.z=sin(rand()/(long double)40000.0);
		//pow((long double)rand(), (long double)0.1
		//a.x = pow((long double)a.x, (long double)0.2);
		//a.y = pow((long double)a.y, (long double)0.2);
		//a.z = pow((long double)a.z, (long double)0.2);
		//b.x = pow((long double)b.x, (long double)0.2);
		//b.y = pow((long double)b.y, (long double)0.2);
		//b.z = pow((long double)b.z, (long double)0.2);
		//c.x = pow((long double)c.x, (long double)0.2);
		//c.y = pow((long double)c.y, (long double)0.2);
		//c.z = pow((long double)c.z, (long double)0.2);

		glVertex3fv(&a.x);
		//glVertex3fv (b.i);
		//glVertex3fv (c.i);
	}
	glEnd();

}

void drawAxis() {
	glLineWidth(2.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1);
	glEnd();

}

void drawGrid() {
	glLineWidth(1.0f);
	for (int i = -10; i <= 10; i++) {
		glBegin(GL_LINES);
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex3f(i * 0.1f, -1, 0);
		glVertex3f(i * 0.1f, 1, 0);
		glEnd();
	}
	for (int i = -10; i <= 10; i++) {
		glBegin(GL_LINES);
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex3f(-1, i * 0.1f, 0);
		glVertex3f(1, i * 0.1f, 0);
		glEnd();
	}
}


int makeSphere(int xres, int yres, float3 size, int *nvert, int *nindex, vec3 **ver, vec3 **nor, usvec3 **ind){
	xres = min(max(abs(xres),3),255);
	yres = min(max(abs(yres)-2,1),256);
	*nvert = xres * yres + 2;
	*nindex = xres * yres * 2;
	vec3 *v = new vec3[*nvert];
	if(!v)
		return 0;
	vec3 *n = new vec3[*nvert];
	if (!n) {
		delete v;
		return 0;
	}
	usvec3 *i = new usvec3[*nindex];
	if(!i) {
		delete v;
		delete n;
		return 0;
	}
	float vx = PI/(xres+0)*2, vy = PI/(yres+1);
	float px=0,py=0,pz=0, spy=0;
	int p=1, x, y;

	// vextex positions
	// top
	v[0] = vec3(0.0f, 0.0f, size.z);
	n[0] = vec3(0.0f, 0.0f, 1.0f);
	// center
	vec3 vec;
	for( y = 1; y <= yres; y++){
		for( x = 0; x < xres; x++){
			px=x*vx; py = y*vy; 
			spy = sin(py);
			vec = vec3 (sin(px)*sin(py), cos(px)*sin(py), cos(py));

			v[p] = vec * size;
			//n[p] = vec;
			n[p] = normalize(vec);
			//v[p] = vec3 (sin(px)*sin(py)*size.x, cos(py)*size.y, cos(px)*sin(py)*size.z);
			p++;
		}
	}
	// booton
	v[p] = vec3(0.0f, 0.0f, -size.z);
	n[p] = vec3(0.0f, 0.0f, -1.0f);


	// indexes
	// top
	p=0;
	for( y = 1; y < xres; y++){
		i[p] = usvec3(0, y+1, y);
		p++;
	}
	i[p] = usvec3(0, 1, y);
	p++;

	//center
	y=1;
	x=y+xres;
	int sx=x, sy=0;
	for(int a=0 ; a < yres-1; a++){
		int sx=x, sy=y;
		for(int b=0 ; b < xres-1; b++, x++, y++){
			i[p] = usvec3(x, y, x+1);
			p++;
			i[p] = usvec3(x+1, y, y+1);
			p++;
		}
		i[p] = usvec3(x, y, sx);
		p++;
		i[p] = usvec3(y+1, y, sy);
		//i[p] = usvec3(y, sx, x+1);
		//p++;
		//i[p] = usvec3(y, sy-1, y+1);

		p++;
		x++;
		y++;
	}

	// booton
	for(y = *nvert - xres; y < *nvert-1; y++){
		i[p] = usvec3(*nvert-1, y-1, y);
		p++;
	}
	i[p] = usvec3(*nvert-1, y-1, *nvert - xres-1);
	*ver = v; *ind=i, *nor = n;

	return 1;
}

void makeTorus(int xres, int yres, float3 size) {
	xres = max(xres, 3);
	yres = max(yres, 3);

	int tnvert = xres * yres;
	int tnindex = xres * yres * 2;

	vec3 *tvert = new vec3[tnvert];
	vec3 *tnorm = new vec3[tnvert];
	usvec3*tindex = new usvec3[tnindex];

	float vx = PI / xres * 2.0f, vy = PI / yres * 2.0f;
	float px = 0, py = 0, pz = 0;
	// attributes
	int p = 0, y = 0, x = 0;
	for (y = 0; y < yres; y++) {
		py = y * vy;
		for (x = 0; x < xres; x++) {
			px = x * vx;
			float
				xb = sin(px) * size.x,   // big circle x
				yb = cos(px) * size.y,   // big circle y

				xs = sin(py) * size.x,   // small circle x
				ys = cos(py) * size.y,   // small circle y
				z = cos(py) * size.z / 2; // small circle z: nedded because the size(/2)
			tvert[p] = vec3(xb + (xs * xb), yb + (xs * yb), z);
			p++;
			//glVertex3f(xb+(xs*xb), yb+(xs*yb), z);
		}
	}


	//center
	p = 0;
	y = 0;
	x = y + xres;
	int sx = x, sy = 0;
	for (int a = 0; a < yres - 1; a++) {
		int sx = x, sy = y;
		for (int b = 0; b < xres - 1; b++, x++, y++) {
			tindex[p] = usvec3(y, x, x + 1);
			p++;
			tindex[p] = usvec3(y, x + 1, y + 1);
			p++;
		}
		tindex[p] = usvec3(y, x, sx);
		p++;
		tindex[p] = usvec3(y, y + 1, sy);
		//tindex[p] = usvec3(y, sx, x+1);
		//p++;
		//tindex[p] = usvec3(y, sy-1, y+1);
		p++;
		x++;
		y++;
	}

	// booton
	for (x = 0, y = tnvert - xres; y < tnvert, p < tnindex;) {
		if (x >= xres)
			//tindex[p] = usvec3(y-yres, x, x+1);
			tindex[p] = usvec3(0, 0, 0);
		else
			tindex[p] = usvec3(y, x, x + 1);
		//tindex[p] = usvec3(tnvert-1, y, y-1);
		p++;

		if (x >= xres)
			tindex[p] = usvec3(0, 0, 0);
		//tindex[p] = usvec3(y, y+1, x-xres);
		else
			tindex[p] = usvec3(y, x + 1, y + 1);
		//tindex[p] = usvec3(tnvert-1, y+1, y-1);
		p++;
		y++;
		x++;
	}

	tindex[tnindex - 2] = usvec3(xres - 1, 0, tnvert - 1);
	tindex[tnindex - 1] = usvec3(tnvert - xres, tnvert - 1, 0);
	//tindex[tnindex-1] = usvec3(0, 0, 0);
	//tindex[tnindex-2] = usvec3(0, 0, 0);
	//tindex[tnindex-1] = usvec3(0, 0, 0);

	vec3 faceNormal;
	for (p = 0; p < tnindex; p++) {
		faceNormal = calcNormal(tvert[tindex[p].x], tvert[tindex[p].y], tvert[tindex[p].z]);
		tnorm[tindex[p].x] += faceNormal;
		tnorm[tindex[p].y] += faceNormal;
		tnorm[tindex[p].z] += faceNormal;
	}
	for (p = 0; p < tnvert; p++) {
		tnorm[p] = normalize(tnorm[p]);
	}
	p = 0;




}


void drawSphere2(int xres, int yres, float3 size) {
	xres = max(xres, 3);
	yres = max(yres, 2);
	float vx = PI / xres * 2.0f, vy = PI / yres;
	float px = 0, py = 0, pz = 0;
	// attributes
	glPointSize(3);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	// big sphere
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, size.y, 0);
	for (int y = 1; y < yres; y++) {
		for (int x = 0; x < xres; x++) {
			px = x * vx + 0.001f; py = y * vy + 0.001f;
			glVertex3f(sin(px) * sin(py) * size.x, cos(py) * size.y, cos(px) * sin(py) * size.z);
		}
	}
	glVertex3f(0.0f, -size.y, 0.0f);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0, size.y, 0);
	for (int y = 1; y < yres; y++) {
		for (int x = 0; x < xres; x++) {
			px = x * vx + 0.001f; py = y * vy + 0.001f;
			glVertex3f(sin(px) * sin(py) * size.x, cos(py) * size.y, cos(px) * sin(py) * size.z);
		}
	}
	glVertex3f(0.0f, -size.y, 0.0f);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.3f, 0.0f);
	glVertex3f(0.0f, size.y, 0.0f);
	for (int y = 1; y < yres; y++) {
		for (int x = 0; x < xres; x++) {
			px = x * vx + 0.001f; py = y * vy + 0.001f;
			glVertex3f(sin(px) * sin(py) * size.x, cos(py) * size.y, cos(px) * sin(py) * size.z);
		}
	}
	glVertex3f(0.0f, -size.y, 0.0f);
	glEnd();

	// small sphere
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f, 1.0f, 1.0f);
	for (py = -PI; py < PI; py += vy) {
		for (px = -PI; px < PI; px += vx) {
			glVertex3f(sin(px) / 2 * sin(py) * size.x, (cos(py) / 2) * size.y, cos(px) / 2 * sin(py) * size.z);
		}
	}
	glEnd();
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.3f, 0.0f);
	for (py = -PI; py < PI; py += vy) {
		for (px = -PI; px < PI; px += vx) {
			glVertex3f(sin(px) / 2.0f * sin(py) * size.x, (cos(py) / 2.0f) * size.y, cos(px) / 2.0f * sin(py) * size.z);
		}
	}
	glEnd();
}

void drawSphere(int xres, int yres, float3 size, int nindex, vec3 *vert, usvec3 * index) {
	//drawSphere2(xres, yres, sizex, sizey, sizez);
	glLineWidth(1.0f);
	//xres = max(xres,3);
	//yres = max(yres,2);
	//float vx = PI/xres*2, vy = PI/yres;
	//float px=0,py=0,pz=0;

	glPointSize(3);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	//glPolygonOffset(0, -10.5);
	glEnable(GL_POLYGON_OFFSET_FILL);
	//glBegin (GL_TRIANGLES);
	//	for(int i=0; i<nindex; i++){
	//		glColor3fv (vert[index[i].x].i);
	//		glVertex3fv (vert[index[i].x].i);
	//		glColor3fv (vert[index[i].y].i);
	//		glVertex3fv (vert[index[i].y].i);
	//		glColor3fv (vert[index[i].z].i);
	//		glVertex3fv (vert[index[i].z].i);
	//	}
	//glEnd ();
	//glDisable(GL_POLYGON_OFFSET_FILL);

	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < nindex; i++) {
		glColor3f(0.75f, 0.75f, 0.0f);
		glVertex3fv(&vert[index[i].x].x);
		//glColor3fv (&vert[index[i].y].x);
		glVertex3fv(&vert[index[i].y].x);
		//glColor3fv (&vert[index[i].z].x);
		glVertex3fv(&vert[index[i].z].x);
	}
	glEnd();

	glBegin(GL_POINTS);
	for (int i = 0; i < nindex; i++) {
		glColor3f(1.0f, 0.1f, 0.0f);
		glVertex3fv(&vert[index[i].x].x);
		//glColor3fv (&vert[index[i].y].x);
		glVertex3fv(&vert[index[i].y].x);
		//glColor3fv (&vert[index[i].z].x);
		glVertex3fv(&vert[index[i].z].x);
	}
	glEnd();
}

void drawCube(float3 size, GLint type) {

	glPointSize(3);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	//Mesh { // Cube mesh
 //     8;
 //      1.000000; 1.000000;-1.000000;,
 //      1.000000;-1.000000;-1.000000;,
 //     -1.000000;-1.000000;-1.000000;,
 //     -1.000000; 1.000000;-1.000000;,
 //      1.000000; 1.000000; 1.000000;,
 //      1.000000;-1.000000; 1.000000;,
 //     -1.000000;-1.000000; 1.000000;,
 //     -1.000000; 1.000000; 1.000000;;
 //     12;
 //     3;0,3,1;,
 //     3;4,5,7;,
 //     3;0,1,4;,
 //     3;1,2,5;,
 //     3;4,7,0;,
 //     3;3,2,1;,
 //     3;5,6,7;,
 //     3;1,5,4;,
 //     3;2,6,5;,
 //     3;7,3,0;,
 //     3;2,3,6;,
 //     3;3,7,6;;
	//MeshNormals { // Cube normals
 //       12;
 //       -0.000000;-0.000000;-1.000000;,
 //        0.000000; 0.000000; 1.000000;,
 //        1.000000; 0.000000;-0.000000;,
 //        0.000000;-1.000000; 0.000000;,
 //        0.000000; 1.000000; 0.000000;,
 //        0.000000; 0.000000;-1.000000;,
 //        0.000000;-0.000000; 1.000000;,
 //        1.000000; 0.000000; 0.000000;,
 //        0.000000;-1.000000; 0.000000;,
 //       -0.000000; 1.000000; 0.000000;,
 //       -1.000000; 0.000000; 0.000000;,
 //       -1.000000; 0.000000; 0.000000;;
 //       12;
 //       3;0,0,0;,
 //       3;1,1,1;,
 //       3;2,2,2;,
 //       3;3,3,3;,
 //       3;4,4,4;,
 //       3;5,5,5;,
 //       3;6,6,6;,
 //       3;7,7,7;,
 //       3;8,8,8;,
 //       3;9,9,9;,
 //       3;10,10,10;,
 //       3;11,11,11;;
	// } // End of Cube normals

	vec3 v[8] = {
		vec3(1.0f, -1.0f, -1.0f),
		vec3(1.0f, -1.0f,  1.0f),
		vec3(-1.0f, -1.0f,  1.0f),
		vec3(-1.0f, -1.0f, -1.0f),
		vec3(1.0f,  1.0f, -1.0f),
		vec3(1.0f,  1.0f,  1.0f),
		vec3(-1.0f,  1.0f,  1.0f),
		vec3(-1.0f,  1.0f, -1.0f)
	};
	vec2 vt[14] = {
		vec2(1.0f,  0.0f),
		vec2(0.5f, -0.5f),
		vec2(1.0f, -0.5f),
		vec2(0.5f,  1.0f),
		vec2(1.0f,  0.5f),
		vec2(1.0f,  1.0f),
		vec2(1.5f,  0.5f),
		vec2(1.5f,  0.0f),
		vec2(0.5f,  0.0f),
		vec2(-0.5f,  0.0f),
		vec2(0.0f,  0.5f),
		vec2(-0.5f,  0.5f),
		vec2(0.5f,  0.5f),
		vec2(0.0f,  0.0f)
	};
	vec3 vn[6] = {
		vec3(0.0f, -1.0f,  0.0f),
		vec3(0.0f,  1.0f,  0.0f),
		vec3(1.0f,  0.0f,  0.0f),
		vec3(0.0f,  0.0f,  1.0f),
		vec3(0.0f,  0.0f, -1.0f),
		vec3(-1.0f,  0.0f,  0.0f)
	};

	//v/t/n
	uchar3 fv[12] = {
		uchar3(2, 4, 1),
		uchar3(8, 6, 5),
		uchar3(5, 2, 1),
		uchar3(6, 3, 2),
		uchar3(1, 8, 5),
		uchar3(2, 3, 4),
		uchar3(8, 7, 6),
		uchar3(5, 6, 2),
		uchar3(6, 7, 3),
		uchar3(1, 4, 8),
		uchar3(7, 4, 3),
		uchar3(7, 8, 4)
	};
	uchar3 ft[12] = {
		uchar3(1 ,  2 ,  3),
		uchar3(4 ,  5 ,  6),
		uchar3(7 ,  1 ,  8),
		uchar3(5 ,  9 ,  1),
		uchar3(10,  11,  12),
		uchar3(1 ,  9 ,  2),
		uchar3(4 ,  13,  5),
		uchar3(7 ,  5 ,  1),
		uchar3(5 ,  13,  9),
		uchar3(10,  14,  11),
		uchar3(13,  14,  9),
		uchar3(13,  11,  14)
	};
	uchar3 fn[12] = {
		uchar3(1, 1, 1),
		uchar3(2, 2, 2),
		uchar3(3, 3, 3),
		uchar3(4, 4, 4),
		uchar3(5, 5, 5),
		uchar3(1, 1, 1),
		uchar3(2, 2, 2),
		uchar3(3, 3, 3),
		uchar3(4, 4, 4),
		uchar3(5, 5, 5),
		uchar3(6, 6, 6),
		uchar3(6, 6, 6)
	};


	float3 vertex[8] = {
		float3(0.5f, 0.5f, 0.5f) * size,
		float3(0.5f,-0.5f, 0.5f) * size,
		float3(-0.5f,-0.5f, 0.5f) * size,
		float3(-0.5f, 0.5f, 0.5f) * size,
		float3(0.5f, 0.5f,-0.5f) * size,
		float3(0.5f,-0.5f,-0.5f) * size,
		float3(-0.5f,-0.5f,-0.5f) * size,
		float3(-0.5f, 0.5f,-0.5f) * size
	};

	uchar3 index[12] = {
		uchar3(1, 3, 2), //up
		uchar3(1, 0, 3),

		uchar3(0, 4, 3), // left
		uchar3(3, 4, 7),

		uchar3(3, 7, 2), //front
		uchar3(2, 7, 6),

		uchar3(1, 6, 5), //right
		uchar3(1, 2, 6),

		uchar3(1, 5, 0), //back
		uchar3(0, 5, 4),

		uchar3(6, 7, 4), // down
		uchar3(5, 6, 4)
	};

	glPolygonOffset(-1.5, -1.5);
	glEnable(GL_POLYGON_OFFSET_FILL);
	if (type & 0x1) {
		glBegin(GL_TRIANGLES);
		glColor3f(0.2f, 0.00f, 0.5f);
		for (int i = 0; i < 12; i++) {
			glVertex3fv(&vertex[index[i].x].x);
			glVertex3fv(&vertex[index[i].y].x);
			glVertex3fv(&vertex[index[i].z].x);
		}
		glEnd();
	}
	glDisable(GL_POLYGON_OFFSET_FILL);
	if (type & 0x2) {
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0f, 0.9f, 0.0f);
		for (int i = 0; i < 12; i++) {
			glVertex3fv(&vertex[index[i].x].x);
			glVertex3fv(&vertex[index[i].y].x);
			glVertex3fv(&vertex[index[i].z].x);
		}
		glEnd();
	}
	if (type & 0x4) {
		glBegin(GL_POINTS);
		glColor3f(1.0f, 0.1f, 0.0f);
		for (int i = 0; i < 12; i++) {
			glVertex3fv(&vertex[index[i].x].x);
			glVertex3fv(&vertex[index[i].y].x);
			glVertex3fv(&vertex[index[i].z].x);
		}
		glEnd();
	}
}

void drawTorus(int xres, int yres, float3 size) {
	xres = max(xres, 3);
	yres = max(yres, 3);
	float vx = PI / xres * 2.0f, vy = PI / yres * 2.0f;
	float px = 0, py = 0, pz = 0;
	// attributes
	glPointSize(3);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	// big sphere

	//glBegin (GL_POINTS);
	//glColor3f (1.0f, 0.3f, 0.0f);
	//	glVertex3f (0.0f, size.y,0.0f);
	//	for(int x = 0; x < xres; x++){
	//		for(int y = 1; y < yres; y++){
	//			px=x*vx+0.001f; py = y*vy+0.001f; 
	//			glVertex3f (sin(px)*sin(py)*size.x, cos(py)*size.y, cos(px)*sin(py)*size.z);
	//		}
	//	}
	//	glVertex3f (0.0f, -size.y,0.0f);
	//glEnd ();

	//glBegin (GL_POINTS);
	//glColor3f (1.0f, 0.3f, 0.0f);
	//	for(int x = 0; x < xres; x++){
	//		for(int y = 1; y <= yres; y++){
	//			px=x*vx+0.001f; py = y*vy+0.001f;

	//			float X=sin(px)*size.x*5,
	//				  Y=cos(px)*size.y*5,
	//				  Z=cos(py)*size.z;

	//			//glVertex3f(sin(px)*size.x, cos(px)*size.y+sin(py), 0.1*size.z+cos(py));
	//			glVertex3f(X+(sin(py)*size.x), Y+(cos(py)*size.y), Z*1);
	//		}
	//	}
	//glEnd ();
	//glBegin (GL_LINE_STRIP);
	//glColor3f (1.0f, 0.3f, 0.0f);
	//	for(int x = 0; x < xres; x++){
	//		for(int y = 1; y <= yres; y++){
	//			px=x*vx+0.001f; py = y*vy+0.001f;

	//			float x1 = sin(px) * size.x * 5,
	//				  y1 = cos(px) * size.y * 5,
	//				  z  = cos(py) * size.z,

	//				  x2 = sin(py) * size.x,
	//				  y2 = cos(py) * size.y;


	//			//glVertex3f(sin(px)*size.x, cos(px)*size.y+sin(py), 0.1*size.z+cos(py));
	//			glVertex3f(x1+(x2*y1), y1+(y2*x1), z);
	//		}
	//	}
	//glEnd ();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f);
	for (int y = 0; y < yres; y++) {
		py = y * vy;
		for (int x = 0; x < xres; x++) {
			px = x * vx;
			float
				xb = sin(px) * size.x,   // big circle x
				yb = cos(px) * size.y,   // big circle y

				xs = sin(py) * size.x,   // small circle x
				ys = cos(py) * size.y,   // small circle y
				z = cos(py) * size.z / 2; // small circle z: nedded because the size(/2)
			//glColor3f (xb+(xs*xb), yb+(xs*yb), z);
			glVertex3f(xb + (xs * xb), yb + (xs * yb), z);
			//big circle
			//glVertex3f(xb, yb, 0);
			//small circle
			//glVertex3f(xs, ys, 0);
		}
	}
	glEnd();

	int numc = 5, numt = 20;
	glColor3f(1.0f, 0.3f, 0.0f);
	double TWOPI = 2 * PI;
	for (int i = 0; i < numc; i++) {
		glBegin(GL_LINE_STRIP);
		for (int j = 0; j <= numt; j++) {
			double s = (i) % numc;
			double t = j % numt;
			double x = (0.5 + 0.1 * cos(s * TWOPI / numc)) * cos(t * TWOPI / numt);
			double y = (0.5 + 0.1 * cos(s * TWOPI / numc)) * sin(t * TWOPI / numt);
			double z = 0.1 * sin(s * TWOPI / numc);
			//glVertex3d(1 * x, 1 * y, 1 * z);
		}
		glEnd();
	}
}

void drawTorus2(int xres, int yres, float3 size, int tnindex, vec3* tvert, usvec3* tindex) {
	//drawSphere2(xres, yres, sizex, sizey, sizez);
	glLineWidth(1.0f);
	//xres = max(xres,3);
	//yres = max(yres,2);
	//float vx = PI/xres*2, vy = PI/yres;
	//float px=0,py=0,pz=0;

	glPointSize(3);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	//glPolygonOffset(0, -10.5);
	glEnable(GL_POLYGON_OFFSET_FILL);
	//glBegin (GL_TRIANGLES);
	//	for(int i=0; i<tnindex; i++){
	//		glColor3fv ((tnorm[tindex[i].y]).i);
	//		glVertex3fv(tvert[tindex[i].y].i);
	//		glColor3fv ((tnorm[tindex[i].x]).i);
	//		glVertex3fv(tvert[tindex[i].x].i);
	//		glColor3fv ((tnorm[tindex[i].z]).i);
	//		glVertex3fv(tvert[tindex[i].z].i);
	//	}
	//glEnd ();
	glDisable(GL_POLYGON_OFFSET_FILL);

	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < tnindex; i++) {
		glColor3f(0.75f, 0.75f, 0.0f);
		glVertex3fv(&tvert[tindex[i].x].x);
		//glColor3fv(&tvert[tindex[i].y].x);
		glVertex3fv(&tvert[tindex[i].y].x);
		//glColor3fv(&tvert[tindex[i].z].x);
		glVertex3fv(&tvert[tindex[i].z].x);
	}
	glEnd();

	glBegin(GL_POINTS);
	for (int i = 0; i < tnindex; i++) {
		glColor3f(1.0f, 0.1f, 0.0f);
		glVertex3fv(&tvert[tindex[i].x].x);
		//glColor3fv(&tvert[tindex[i].y].x);
		glVertex3fv(&tvert[tindex[i].y].x);
		//glColor3fv(&tvert[tindex[i].z].x);
		glVertex3fv(&tvert[tindex[i].z].x);
	}
	glEnd();
}




LONGLONG freq = 0, count1 = 0, count2 = 0;
LONGLONG resetTime() {
	LONGLONG tmp = count1 - count2;
	QueryPerformanceCounter((LARGE_INTEGER*)&count1);
	QueryPerformanceCounter((LARGE_INTEGER*)&count2);
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	return tmp;
}
float getTime() {
	return float((count2 - count1) * (1000000.0 / freq));
}
float setTime() {
	QueryPerformanceCounter((LARGE_INTEGER*)&count2);
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	return float((count2 - count1) * (1000000.0 / freq));
}

LONGLONG resetTime2() {
	LONGLONG tmp = count1 - count2;
	count1 = __rdtsc();
	count2 = count1;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	return tmp;
}
float getTime2() {
	return float((count2 - count1) * (1000000.0 / freq));
}
float setTime2() {
	count2 = __rdtsc();
	return float((count2 - count1) * (1000000.0 / freq));
}



frame::frame(): c1(0,0), c2(0,0), p(0,0) {}
frame::frame(vec2 _c1, vec2 _c2, vec2 _p): c1(_c1), c2(_c2), p(_p) {}

frame::~frame() {}
frame::frame(const frame& f) {
	c1 = f.c1;
	c2 = f.c2;
	p  = f.p;
}
frame& frame::operator = (const frame& f)   {
	c1 = f.c1;
	c2 = f.c2;
	p  = f.p;
	return *this;
}
frame& frame::operator = (const frame* f)  {
	c1 = f->c1;
	c2 = f->c2;
	p  = f->p;
	return *this;
}


animation::~animation() {}
animation::animation() {}

animation::animation(std::vector<frame>& f) {
	if (f.size() >= 1) {
		frames.resize(f.size());
		for (int i = 0; i < f.size(); i++) {
			frames[i] = f[i];
		}
	}
}

animation::animation(animation& a) {
	if (a.frames.size() >= 1) {
		frames.resize(a.frames.size());
		for (int i = 0; i < a.frames.size(); i++) {
			frames[i] = a.frames[i];
		}
	}
}

animation::animation(animation* a) {
	if (a->frames.size() >= 1) {
		frames.resize(a->frames.size());
		for (int i = 0; i < a->frames.size(); i++) {
			frames[i] = a->frames[i];
		}
	}

}

animation& animation::operator = (animation& a){
	if (a.frames.size() >= 1) {
		frames.resize(a.frames.size());
		for (int i = 0; i < a.frames.size(); i++) {
			frames[i] = a.frames[i];
		}
	}
	return *this;
}

animation& animation::operator = (animation* a){
	if (a->frames.size() >= 1) {
		frames.resize(a->frames.size());
		for (int i = 0; i < a->frames.size(); i++) {
			frames[i] = a->frames[i];
		}
	}
	return *this;
}

float animation::getFrame(float t){
	int sz = frames.size();
	int vl = sz/2;
	int cur = vl;
	float r = 0;
	frame f1;
	frame f2;
	t = fmodf(t, frames[sz - 1].p.x);
	if (t < 0.f)
		t += frames[sz - 1].p.x;
	if (t > frames[sz - 1].p.x)
		t -= frames[sz - 1].p.x;
	if (sz == 0)
		return 0;
	if ((sz == 1) || (t == 0.f))
		return frames[0].p.y;
	while (vl>0) {
		vl /= 2;
		if (frames[cur].p.x >= t) {
			cur += vl;
		}
		else if (frames[cur].p.x <= t) {
			cur -= vl;
		}
	}
	if (frames[cur].p.x <= t && frames[cur + 1].p.x >= t) {
		f1 = frames[cur];
		f2 = frames[cur + 1];
	}
	else if (frames[cur-1].p.x <= t && frames[cur ].p.x >= t) {
		f1 = frames[cur-1];
		f2 = frames[cur];
	}
	float time = (t-f1.p.x) /(f2.p.x - f1.p.x);
	return fBezier2(f1, f2, time);
}

float fBezier2(frame& f1, frame& f2, float t) {
	vec2 r = bezier4(f1.p, f2.c1, f2.c2, f2.p, t);
	return r.y;
}


bezier2d::~bezier2d() {}
bezier2d::bezier2d() {}

bezier2d::bezier2d(std::vector<bz2d>& f) {
	if (f.size() >= 1) {
		frames.resize(f.size());
		for (int i = 0; i < f.size(); i++) {
			frames[i] = f[i];
		}
	}
}

bezier2d::bezier2d(bezier2d& a) {
	if (a.frames.size() >= 1) {
		frames.resize(a.frames.size());
		for (int i = 0; i < a.frames.size(); i++) {
			frames[i] = a.frames[i];
		}
	}
}

bezier2d::bezier2d(bezier2d* a) {
	if (a->frames.size() >= 1) {
		frames.resize(a->frames.size());
		for (int i = 0; i < a->frames.size(); i++) {
			frames[i] = a->frames[i];
		}
	}

}

bezier2d& bezier2d::operator = (bezier2d& a){
	if (a.frames.size() >= 1) {
		frames.resize(a.frames.size());
		for (int i = 0; i < a.frames.size(); i++) {
			frames[i] = a.frames[i];
		}
	}
	return *this;
}

bezier2d& bezier2d::operator = (bezier2d* a){
	if (a->frames.size() >= 1) {
		frames.resize(a->frames.size());
		for (int i = 0; i < a->frames.size(); i++) {
			frames[i] = a->frames[i];
		}
	}
	return *this;
}

float2 bezier2d::getPos(int p1, int p2, float t){
	int sz = frames.size();
	p1 = p1 % sz;
	if (p1 < 0)
		p1 += sz;
	if (p1 >sz)
		p1 -= sz;
	p2 = p2 % sz;
	if (p2 < 0)
		p2 += sz;
	if (p2 >sz)
		p2 -= sz;
	float2 r = bezier4(frames[p1].p, frames[p2].c1, frames[p2].c2, frames[p2].p, t);
	return r;
}



bezier3d::~bezier3d() {}
bezier3d::bezier3d() {}

bezier3d::bezier3d(std::vector<bz3d>& f) {
	if (f.size() >= 1) {
		frames.resize(f.size());
		for (int i = 0; i < f.size(); i++) {
			frames[i] = f[i];
		}
	}
}

bezier3d::bezier3d(bezier3d& a) {
	if (a.frames.size() >= 1) {
		frames.resize(a.frames.size());
		for (int i = 0; i < a.frames.size(); i++) {
			frames[i] = a.frames[i];
		}
	}
}

bezier3d::bezier3d(bezier3d* a) {
	if (a->frames.size() >= 1) {
		frames.resize(a->frames.size());
		for (int i = 0; i < a->frames.size(); i++) {
			frames[i] = a->frames[i];
		}
	}

}

bezier3d& bezier3d::operator = (bezier3d& a){
	if (a.frames.size() >= 1) {
		frames.resize(a.frames.size());
		for (int i = 0; i < a.frames.size(); i++) {
			frames[i] = a.frames[i];
		}
	}
	return *this;
}

bezier3d& bezier3d::operator = (bezier3d* a){
	if (a->frames.size() >= 1) {
		frames.resize(a->frames.size());
		for (int i = 0; i < a->frames.size(); i++) {
			frames[i] = a->frames[i];
		}
	}
	return *this;
}

float3 bezier3d::getPos(int p1, int p2, float t){
	int sz = frames.size();
	p1 = p1 % sz;
	if (p1 < 0)
		p1 += sz;
	if (p1 >sz)
		p1 -= sz;
	p2 = p2 % sz;
	if (p2 < 0)
		p2 += sz;
	if (p2 >sz)
		p2 -= sz;
	float3 r = bezier4(frames[p1].p, frames[p2].c1, frames[p2].c2, frames[p2].p, t);
	return r;
}








