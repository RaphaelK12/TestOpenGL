#pragma once

class material
{
public:
	material(void);
	material(string name);
	~material(void);
	material* atach(void);
	void detach(void);
	void setShaderVariables();
	int active(matrix_block* m);
	int read(string filename);
	void reset(void);
	void setMatrix(matrix_block* m);

	static uint g_count;
	uint type;
	uint count;
	uint mIndex;
	uint castShadows;
	uint receiveShadows;
	uint renderable;
	uint transparent;
	uint alphaBlendMode;
	uint colorBlendMode;
	uint cullFace;
	uint dephtTest;
	uint dephtWrite;
	uint shadingModel;
		 

	vec2 polygonOffset;
	vec4 mColor1;			// color passed to program
	vec4 mColor2;			// color passed to program
	vec4 mColor3;			// color passed to program
	vec4 mDifuse;			// color passed to program
	vec4 mAmbient;			// color passed to program
	vec4 mEmission;			// color passed to program
	vec4 mTranslucenci;		// color passed to program
	vec4 mSadowsColor;		// color passed to program

	vec4 mSpecular;			// color passed to program
	vec4 mReflex;			// color passed to program
	vec4 mShinines;			// color passed to program

	std::string mName;
	std::string mFileName;
	//std::vector<std::string> shaderNames;
	std::string mShaderName;
	std::vector<texture*> mTextures;	// textures objects
	//std::vector<std::tuple<uint, std::string>> texture;	// textures objects
	//std::vector<std::string> textureName;	// textures objects
	//std::vector<char*> textureData;	// textures objects // not necessary
	//std::vector<uint> mTextures;	// textures objects
	shader *mShader;
};

extern std::vector<material*> g_material_list;
