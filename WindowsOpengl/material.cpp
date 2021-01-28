#include "StdAfx.h"
#include "shader.h"
#include "texture.h"
#include "material.h"
#include "objetob.h"
#include "camera.h"

uint material::g_count = 0;

std::vector<material*> g_material_list;

material::material(void) :
	mIndex(0),
	mShader(0),
	mName("default"),
	mFileName("default.mat"),
	//std::vector<std::string> shaderNames;
	mShaderName("default")

{
	reset();
	//count++;
	g_count++;
	g_material_list.push_back(this);
	mIndex = g_material_list.size() - 1;
	mShader = new shader(mShaderName);
	mShader->atach();
}

material::material(string mname):
	mIndex(0),
	mShader(0)
{
	reset();
	//count++;
	g_count++;
	g_material_list.push_back(this);
	mIndex = g_material_list.size() - 1;
	int c = 0;
	if (!read(mname)) {
		mName="default";
		mFileName="default.mat";
		//std::vector<std::string> shaderNames;
		mShaderName="default";
	}
	if (mName.size()<1) {
		mName="default";
		c++;
	}
	if (mFileName.size()<1) {
		mFileName ="default.mat";
		c++;
	}
	if (mShaderName.size()<1) {
		mShaderName ="default";
		c++;
	}
	if (c == 3)
		reset();
	mShader = new shader(mShaderName);
	mShader->atach();

}

material::~material(void)
{
	type=0;

	mName.clear();
	mFileName.clear();
	//std::vector<std::string> shaderNames;
	mShaderName.clear();
	mTextures.clear();	// textures objects
	//std::vector<std::tuple<uint, std::string>> texture;	// textures objects
	//std::vector<std::string> textureName;	// textures objects
	//std::vector<char*> textureData;	// textures objects // not necessary
	//std::vector<uint> mTextures;	// textures objects
	mShader->detach();
	mShader = 0;
	g_count--;
}

void material::reset(void) {
	type = 0;
	count = 0;
	//mIndex = 0;
	castShadows = 1;
	receiveShadows = 1;
	renderable = 1;
	transparent = 0;
	alphaBlendMode = GL_BLEND_SRC_ALPHA;
	colorBlendMode = GL_BLEND_COLOR;
	cullFace = GL_FRONT_FACE;
	dephtTest = 1;
	dephtWrite = 1;
	shadingModel = 1;
	if (mShader)
		mShader->detach();
	mShader = 0;
	polygonOffset = vec2(0.0, 0.0);
	//mColor =		vec4(1.0, 0.3, 1.0, 1.0);			// color passed to program
	mColor1 =		vec4(1.0, 0.3, 1.0, 1.0);			// color passed to program
	mColor2 =		vec4(1.0, 0.3, 1.0, 1.0);			// color passed to program
	mColor3 =		vec4(1.0, 0.3, 1.0, 1.0);			// color passed to program
	mDifuse =		vec4(1.0, 0.3, 1.0, 1.0);			// color passed to program
	mAmbient =		vec4(0.1, 0.1, 0.1, 1.0);		// color passed to program
	mEmission =		vec4(0.0, 0.0, 0.1, 0.0);				// color passed to program
	mTranslucenci = vec4(0.01, 0.01, 0.01, 0.0);		// color passed to program
	mSadowsColor =	vec4(0.0, 0.0, 0.0, 0.0);			// color passed to program
	mSpecular =		vec4(1.0, 1.0, 1.0, 1.0);			// color passed to program
	mReflex =		vec4(1.0, 1.0, 1.0, 1.0);			// color passed to program
	mShinines =		vec4(128.0, 128.0, 128.0, 1.0);			// color passed to program
	mName.clear();
	mFileName.clear();
	mShaderName.clear();
	if (mTextures.size())
		for (uint i = 0; i < mTextures.size(); i++) {
			mTextures[i]->detach();
			mTextures[i] = 0;
		}
	mTextures.clear();
}

int material::read(string filename) {
	string file = filename;
	string fr = "Material";
	int i;
	if (file.size() >= 1) {
		FILE* f = fopen(filename.c_str(), "r");
		if (!f) {
			file = filename + string(".mat");
			f = fopen(file.c_str(), "r");
		}
		if (!f)
			return 0;
		char* txt = new char[100];
		//mName.resize(100);
		//mFileName.resize(100);
		//mShaderName.resize(100);
		mTextures.resize(10);
		mTextures[0] = new texture;
		mTextures[1] = new texture;
		mTextures[2] = new texture;
		mTextures[3] = new texture;
		mTextures[4] = new texture;
		mTextures[5] = new texture;
		mTextures[6] = new texture;
		mTextures[7] = new texture;
		mTextures[8] = new texture;
		mTextures[9] = new texture;
		//mTextures[0]->fileName.resize(100);
		//mTextures[1]->fileName.resize(100);
		//mTextures[2]->fileName.resize(100);
		//mTextures[3]->fileName.resize(100);
		//mTextures[4]->fileName.resize(100);
		//mTextures[5]->fileName.resize(100);
		//mTextures[6]->fileName.resize(100);
		//mTextures[7]->fileName.resize(100);
		//mTextures[8]->fileName.resize(100);
		//mTextures[9]->fileName.resize(100);
		i = fscanf(f, "%s\n", txt);
		if (fr != txt) {
			fclose(f);
			delete[] txt;
			return 0;
		}
		i = fscanf(f, "i  type: 				%i\n", &type);
		i = fscanf(f, "i  castShadows:			%i\n", &castShadows);
		i = fscanf(f, "i  receiveShadows:		%i\n", &receiveShadows);
		i = fscanf(f, "i  renderable:			%i\n", &renderable);
		i = fscanf(f, "i  transparent:			%i\n", &transparent);
		i = fscanf(f, "i  alphaBlendMode:		%i\n", &alphaBlendMode);
		i = fscanf(f, "i  colorBlendMode:		%i\n", &colorBlendMode);
		i = fscanf(f, "i  cullFace:				%i\n", &cullFace);
		i = fscanf(f, "i  dephtTest:			%i\n", &dephtTest);
		i = fscanf(f, "i  dephtWrite:			%i\n", &dephtWrite);
		i = fscanf(f, "i  shadingModel:			%i\n", &shadingModel);
		i = fscanf(f, "v2 polygonOffset:		%f %f\n", &polygonOffset.x, &polygonOffset.y);
		i = fscanf(f, "v4 color1:				%f %f %f %f\n", &mColor1.r, &mColor1.g, &mColor1.b, &mColor1.a);
		i = fscanf(f, "v4 color2:				%f %f %f %f\n", &mColor2.r, &mColor2.g, &mColor2.b, &mColor2.a);
		i = fscanf(f, "v4 color3:				%f %f %f %f\n", &mColor3.r, &mColor3.g, &mColor3.b, &mColor3.a);
		i = fscanf(f, "v4 diffuse:				%f %f %f %f\n", &mDifuse.r, &mDifuse.g, &mDifuse.b, &mDifuse.a);
		i = fscanf(f, "v4 ambient:				%f %f %f %f\n", &mAmbient.r, &mAmbient.g, &mAmbient.b, &mAmbient.a);
		i = fscanf(f, "v4 emission:				%f %f %f %f\n", &mEmission.r, &mEmission.g, &mEmission.b, &mEmission.a);
		i = fscanf(f, "v4 translucenci:			%f %f %f %f\n", &mTranslucenci.r, &mTranslucenci.g, &mTranslucenci.b, &mTranslucenci.a);
		i = fscanf(f, "v4 sadowsColor:			%f %f %f %f\n", &mSadowsColor.r, &mSadowsColor.g, &mSadowsColor.b, &mSadowsColor.a);
		i = fscanf(f, "v4 specular:				%f %f %f %f\n", &mSpecular.r, &mSpecular.g, &mSpecular.b, &mSpecular.a);
		i = fscanf(f, "v4 reflex:				%f %f %f %f\n", &mReflex.r, &mReflex.g, &mReflex.b, &mReflex.a);
		i = fscanf(f, "v4 shinines:				%f %f %f %f\n", &mShinines.r, &mShinines.g, &mShinines.b, &mShinines.a);
		i = fscanf(f, "s  name:					%s\n", txt);	mName = txt;
		i = fscanf(f, "s  fileName:				%s\n", txt);	mFileName = txt;
		i = fscanf(f, "s  shaderName:			%s\n", txt);	mShaderName = txt;
		i = fscanf(f, "s  textures:				%s ", txt);		mTextures[0]->fileName = txt;
		i = fscanf(f, "%s ", txt);								mTextures[1]->fileName = txt;
		i = fscanf(f, "%s ", txt);								mTextures[2]->fileName = txt;
		i = fscanf(f, "%s ", txt);								mTextures[3]->fileName = txt;
		i = fscanf(f, "%s ", txt);								mTextures[4]->fileName = txt;
		i = fscanf(f, "%s ", txt);								mTextures[5]->fileName = txt;
		i = fscanf(f, "%s ", txt);								mTextures[6]->fileName = txt;
		i = fscanf(f, "%s ", txt);								mTextures[7]->fileName = txt;
		i = fscanf(f, "%s ", txt);								mTextures[8]->fileName = txt;
		i = fscanf(f, "%s ", txt);								mTextures[9]->fileName = txt;

		fclose(f);
		delete[] txt;

		if (mShader) {
			if (mShader->name != mShaderName) {
				mShader->detach();
				mShader = new shader(mShaderName);
				mShader->atach();
			}
		}
	}
	return 1;
}

material* material::atach(void){
	count++;
	return this;
}

void material::detach(void){
	count--;
	if (count <= 0){
		g_material_list[mIndex]=NULL;
		delete this;
	}
}

void material::setShaderVariables() {
	if (!mShader)
		return;
	//mShader->setUniform("mt.color", mColor);
	mShader->setUniform("mt.color1", mColor1);
	mShader->setUniform("mt.color2", mColor2);
	mShader->setUniform("mt.color3", mColor3);
	mShader->setUniform("mt.diffuse", mDifuse);
	mShader->setUniform("mt.ambient", mAmbient);
	mShader->setUniform("mt.emission", mEmission);
	mShader->setUniform("mt.translucenci", mTranslucenci);
	mShader->setUniform("mt.sadowsColor", mSadowsColor);
	mShader->setUniform("mt.specular", mSpecular);
	mShader->setUniform("mt.reflex", mReflex);
	mShader->setUniform("mt.shinines", mShinines);
}

int material::active(matrix_block* m) {
	if (!mShader) {
		mShader = new shader(mShaderName);
		mShader->atach();
	}
	mShader->use();
	setShaderVariables();
	setMatrix(m);
	return 1;
}

void material::setMatrix(matrix_block* m) {
	if (!mShader || !m)
		return;
	mShader->setUniform("mt_model", m->M);						  //	uniform mat4 mt_model;
	mShader->setUniform("mt_view", m->V);						  //	uniform mat4 mt_view;
	mShader->setUniform("mt_projection", m->P);					  //	uniform mat4 mt_projection;
	mShader->setUniform("mt_modelView", m->MV);					  //	uniform mat4 mt_modelView;
	mShader->setUniform("mt_modelViewProjection", m->MVP);		  // 	uniform mat4 mt_modelViewProjection;
	mShader->setUniform("viewPos", activecamera->gpos);		  // 	uniform mat4 mt_modelViewProjection;

}

