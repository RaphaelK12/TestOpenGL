#ifndef _manager_h
#define _manager_h 1

//#include "Vectors.h"

#include "cTimer.h"
#include "texture.h"
#include "objetob.h"
#include "shader.h"
#include "material.h"
#include "projetor.h"
#include "malha.h"
#include "bone.h"
#include "skeleton.h"
#include "objeto.h"
#include "ligith.h"
#include "texto.h"
#include "camera.h"




// not needed
//class vertex{
//	vec3 pos;
//	vec3 normal;
//	//vec3 color;
//	vec2 texcord;
//};

// utility class for shader manager
class shader2{
	//shader(){};
	//~shader(){};

	uint glProgram;		// gl program object (contain the compiled shaders).

	uint glVShader;		// gl vertex shader object
	uint glTCShader;	// gl tesselator control shader object
	uint glTShader;		// gl tesselator shader object
	uint glTEhader;		// gl tesselator evaluator shader object
	uint glGShader;		// gl geometri shader object
	uint glFShader;		// gl fragment shader object

};

// utility class for material manager
class material2{
public:
	uint type;
	uint castShadows,
		 receiveShadows,
		 renderable,
		 transparent,
		 alphaBlendMode,
		 colorBlendMode,
		 cullFace,
		 dephtTest,
		 dephtWrite,
		 shadingModel;
		 
	std::string name;

	vec2 polygonOffset;
	vec4 mColor1;			// color passed to program
	vec4 mColor2;			// color passed to program
	vec4 mColor3;			// color passed to program
	vec4 mDifuse;			// color passed to program
	vec4 mAmbient;			// color passed to program
	vec4 mEmission;			// color passed to program
	vec4 mTranslucenci;			// color passed to program
	vec4 mSadowsColor;			// color passed to program

	vec4 mSpecular;			// color passed to program
	vec4 mReflex;			// color passed to program
	vec4 mShinines;			// color passed to program


	std::vector<uint > textures;	// textures objects
	std::vector<char*> textureName;	// textures objects
	//std::vector<char*> textureData;	// textures objects // not necessary
	//std::vector<uint> mTextures;	// textures objects
	shader *mShader;
};

// Classe para armazenamento e gerenciamento de malha (vertices, indices, normal, cor, mapaUV, ...).
class malha2{
public:
	//malha(){ // need corrections
	//	//pNormal=0;

	//	//piVertex=0;
	//	//piNormal=0;

	//	//nVertex=0;
	//	//nNormal=0;

	//	//niVertex=0;
	//	//niNormal=0;

	//	//for(int i = 0; i<4; i++){
	//	//	pUv[i]    = 0;
	//	//	pColor[i] = 0;
	//		//piUv[i]   = 0;
	//		//piColor[i]= 0;
	//		//nUv[i]    = 0;
	//		//nColor[i] = 0;
	//		//niUv[i]   = 0;
	//		//niColor[i]= 0;
	//	//}

	//	EBO=0;
	//	VBO=0;
	//	VBA=0;
	//}
	//~malha(){ // need corrections
	//	//if(pVertex)
	//	//	delete[] pVertex;
	//	//if(pNormal)
	//	//	delete[] pNormal;

	//	//if(piVertex)
	//	//	delete[] piVertex;
	//	//if(piNormal)
	//	//	delete[] piNormal;

	//	//for(int i = 0; i<4; i++){
	//	//	if(pUv[i] )
	//	//		delete[] pUv[i];
	//	//	pUv[i] = 0;
	//	//	nUv[i] = 0;
	//	//	if(pColor[i])
	//	//		delete[] pColor[i];
	//	//	pColor[i] = 0;
	//	//	nColor[i] = 0;
	//	//}

	//	//for(int i = 0; i<4; i++){
	//		//if(piUv[i] )
	//		//	delete[] piUv[i];
	//		//piUv[i] = 0;
	//		//niUv[i] = 0;
	//		//if(piColor[i])
	//		//	delete[] piColor[i];
	//		//piColor[i] = 0;
	//		//niColor[i] = 0;
	//	//}

	//	//pVertex=0;
	//	//pNormal=0;

	//	//piVertex=0;
	//	//piNormal=0;


	//	//nVertex=0;
	//	//nNormal=0;

	//	//niVertex=0;
	//	//niNormal=0;

	//	//if(EBO);
	//	//if(VBO);
	//	//if(VBA);
	//}

	uint type;
	uint EBO;
	uint VBO;
	uint VBA;

	uint nIndex;
	ushort nVertex;

	std::vector<vec3> pVertex;
	std::vector<vec3> pNormal;
	std::vector<vec2> pUv;
	std::vector<vec3> pColor1;
	std::vector<vec4> pColor2;

	std::vector<float>pOther1;
	std::vector<vec2> pOther2;
	std::vector<vec3> pOther3;
	std::vector<vec4> pOther4;

	std::vector<usvec3> *pIndex;
	material *mMaterial;	// material usado

	std::string name;


	void draw(int instances){
		
	};

};

// class for manage objects
class objeto2{
public:
	uint type;
	material *Material;	// material usado? override malha properties
	malha *malhas;	// geometria do objeto
	vec4 position; // position for each object
	vec4 rotation; // rotation for each object
	vec4 size;		// size for each object
	std::string name;
	std::vector<vec4> colors;
	std::vector<char*> colorsNames;

};

class light2{
	uint type;
	uint distance;
	uint force;
	vec2 inerAngle;
	vec2 outerAngle;
	vec3 size;

	vec4 diffuse; // Dcli
	vec4 specular; // Scli
	vec4 position; // Ppli
	vec4  halfVector; // Derived: Hi
	vec3  spotDirection; // Sdli
	float spotExponent; // Srli
	float spotCutoff; // Crli
	// (range: [0.0,90.0], 180.0)
	float spotCosCutoff; // Derived: cos(Crli)
	// (range: [1.0,0.0],-1.0)
	float constantAttenuation; // K0
	float linearAttenuation; // K1
	float quadraticAttenuation;// K2
};

class bone2{
	vec4 pos;
	vec4 rot;
	vec4 size;
	vec4 pos2;
	int num;  // used in definitions of BONE_HEAD, BONE_NECK, BONE_CLAVICLE,...
	bone *next; // chain
	bone *prev;
};

class skeleton2{
	std::vector<bone> bones;
};


//int a0[sizeof shader];
//int a1[sizeof material];
//int a2[sizeof malha];
//int a3[sizeof objeto];
//int a4[sizeof malha::pVertex];
//int a5[sizeof malha::pIndex];
//int a6[sizeof light];
//int a7[sizeof bone];
//int a8[sizeof skeleton];
//int a8[sizeof std::string];



class text2
{
public:
	text2();
	text2(char * t);
	~text2();
	void draw(vec4 &color, vec2 &size, vec3 &pos, vec3 &rot);
	void constructVBO();

	std::string txt;
	malha *obj;
	int len;
	vec4 color;
	vec2 size;
	vec3 pos;
	vec3 rot;
	vec2 *uvs;
	vec2 *quads;
};






int drawText(const char* txt, vec2 position/*=vec2(0.f,0.f)*/, vec2 size/*=vec2(1.f,1.f)*/, vec4 color/*=vec4(1.f,1.f,1.f,1.f)*/, vec2 rot/*=vec2(0.f,0.f)*/);


#endif
