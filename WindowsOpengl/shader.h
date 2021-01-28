#pragma once
#include "core+ext.h"
#include "GLFunctions.h"
using std::string;

extern const char defaultVS[];

extern const char defaultFS[];

//FILE *ShaderLOG;

/* class shader: wraper to opengl glsl to load, compile, link and use shader and program.
   usage:
    shader s;
	s.getExistentShaderFilenamesFromSingleName("myShaderFile");
	s.readSrcFromFilenames()
	s.generateShadersAndProgram(true)
	if(!s.use()){
		something goes wrong
	}

    shader s("myShaderFile");
	if(!s.use()){
		something goes wrong
	}

    shader s("myShaderFile.vs", "myShaderFile.fs");
	if(!s.use()){
		something goes wrong
	}

    shader s("myShaderFile.vs", "myShaderFile.fs", "myShaderFile.tc", "myShaderFile.te", "myShaderFile.gs");
	if(!s.use()){
		something goes wrong
	}

*/
enum class ShaderType {
	SHADER_FRAGMENT = 1,
	SHADER_VERTEX,
	SHADER_TESSELATIONC,
	SHADER_TESSELATIONE,
	SHADER_GEOMETRY,
	//SHADER_COMPUTE,
	SHADER_PROGRAM,
};

const string _v[]={".fs", ".vs", ".te", ".tc", ".gs", ".cs"};

class shader
{
public:
	static uint g_count;	// total number of shaders actual in the program
	uint count;				// number of times the shader is used
	uint mIndex;			// index of this shader in global list of shaders

	uint program;			// gl program object (contain the compiled shaders).
	uint VShader;			// gl vertex shader object
	uint TCShader;			// gl tesselator control shader object
	uint TEShader;			// gl tesselator evaluator shader object
	uint GShader;			// gl geometri shader object
	uint FShader;			// gl fragment shader object
	//GLuint CShader;			// gl fragment shader object

	uint shadersFilesExistent;
	uint shadersSourceLoaded;
	uint shadersObjLoaded;
	uint programUsable;

	string name;			// name of this shader
	string shadersName;		// name of shaders(without extension to load all .vs .tc .ts .te .gs .fs .cs

	string  VS;			// gl vertex shader name
	string  TC;			// gl tesselator control shader name
	string  TE;			// gl tesselator evaluator shader name
	string  GS;			// gl geometri shader name
	string  FS;			// gl fragment shader name
	//string  CS;			// gl compute shader name

	string  VSsrc;		// gl vertex shader source
	string  TCsrc;		// gl tesselator control shader source
	string  TEsrc;		// gl tesselator evaluator shader source
	string  GSsrc;		// gl geometri shader source
	string  FSsrc;		// gl fragment shader source
	//string  CSsrc;		// gl compute shader source

    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------

	~shader(void);

	shader(void);

	shader(const string &fileName);

    shader(const char* fileName);

    shader(const char* vs, const char* fs, const char* tc=0, 
		   const char* te=0, const char* gs=0/*, const char* cs=0*/);

    shader(const string &vs, const string &fs, const string &tc=0, 
		   const string &te=0, const string &gs=0/*, const string cs=0*/);

    void shader2(const char* fileName);

	shader* atach(void);

	void detach(void);

	uint getExistentShaderFilenamesFromSingleName(const string &fileName);

	uint readSrcFromFilenames();

    // activate the shader
    // ------------------------------------------------------------------------
	int compile();

	// Set shader source code src = text source code, type = vertex, fragment, tesselation, ...
	// ------------------------------------------------------------------------
	int setSource(string& src, ShaderType type);

	int setSource(const char* src, ShaderType type);

	int setSource(string& fs, string& vs, string& tc, string& te, string& gs);

	int setSource(const char* fs, const char* vs, const char* tc, const char* te, const char* gs);

	uint generateShadersAndProgram( int deleteShaderObjs = TRUE);

    uint use() const;

	void deleteShaders();

    // utility uniform functions
    // ------------------------------------------------------------------------
    void setBool(const string &uname, bool value) const;
    // ------------------------------------------------------------------------
    void setInt(const string &uname, int value) const;
    // ------------------------------------------------------------------------
    void setFloat(const string &uname, float value) const;
    // ------------------------------------------------------------------------
    void setVec2(const string &uname, const vec2 &value) const;

    void setVec2(const string &uname, float x, float y) const;
    // ------------------------------------------------------------------------
    void setVec3(const string &uname, const vec3 &value) const;
    void setVec3(const string &uname, float x, float y, float z) const;
    // ------------------------------------------------------------------------
    void setVec4(const string &uname, const vec4 &value) const;
    void setVec4(const string &uname, float x, float y, float z, float w) const;
    // ------------------------------------------------------------------------
    void setMat2(const string &uname, const mat2 &mat) const;
    // ------------------------------------------------------------------------
    void setMat3(const string &uname, const mat3 &mat) const;
    // ------------------------------------------------------------------------
    void setMat4(const string &uname, const mat4 &mat) const;
    // ------------------------------------------------------------------------
    void setUniform(const string &uname, const bool &val) const;
    void setUniform(const string &uname, const int &val) const;
    void setUniform(const string &uname, const uint &val) const;
    void setUniform(const string &uname, const float &val) const;
    void setUniform(const string &uname, const double &val) const;
    void setUniform(const string &uname, const vec2 &val) const;
    void setUniform(const string &uname, const vec3 &val) const;
    void setUniform(const string &uname, const vec4 &val) const;
    void setUniform(const string &uname, const mat2 &val) const;
    void setUniform(const string &uname, const mat3 &val) const;
    void setUniform(const string &uname, const mat4 &val) const;

private:
    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    uint checkCompileErrors(GLuint shader, string type);


};

extern std::vector<shader*> g_shader_list;

