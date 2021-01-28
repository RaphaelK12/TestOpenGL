#include "StdAfx.h"
#include "shader.h"

std::vector<shader*> g_shader_list;

uint shader::g_count = 0;

const char defaultVS[] = 
"#version 330 core\n"
"layout (location = 0) in vec4 Position;\n"
"out vec4 VertPosition;\n"
"void main(void){\n"
"	vec4 pos = ftransform()*vec4(0.5,0.5,0.5,0.5);//	vec4 pos = Position;\n"
"	VertPosition = pos;\n"
"	gl_Position = pos*vec4(0.5,0.5,0.5,0.5);\n"
"}\n"
;

const char defaultFS[] = 
"#version 330 core\n"
"layout (location = 0) out vec4 fragColor;\n"
//"layout (depth_unchanged) in float gl_FragDepth;\n"
"in vec4 VertPosition;\n"
"void main(void){\n"
"	fragColor = vec4(VertPosition*0.5+0.5);\n"
"}\n"
;

const char defaultFSmagenta[] = 
"#version 330 core\n"
"layout (location = 0) out vec4 fragColor;\n"
//"layout (depth_unchanged) in float gl_FragDepth;\n"
"in vec4 VertPosition;\n"
"void main(void){\n"
"	fragColor = vec4(1,0.2,1,1);\n"
"}\n"
;



shader::~shader(void)
{
	deleteShaders();
	if(program)
		glDeleteProgram(program);
	name.clear();
	shadersName.clear();
	VS.clear();
	TC.clear();
	TE.clear();
	GS.clear();
	FS.clear();
	VSsrc.clear();
	TCsrc.clear();
	TEsrc.clear();
	GSsrc.clear();
	FSsrc.clear();
	if (g_shader_list.size() >= mIndex)
		g_shader_list[mIndex] = 0;
	g_count--;
}

shader::shader(void):
	count(0),
	program(0),
	VShader(0),	
	TCShader(0),	
	TEShader(0),	
	GShader(0),	
	FShader(0),	
	//CShader(0),
	shadersFilesExistent(0),
	shadersSourceLoaded(0),
	shadersObjLoaded(0),
	programUsable(0)
{
	//count++;
	g_count++;
	g_shader_list.push_back(this);
	mIndex = g_shader_list.size() - 1;

	shadersName = "default";
	getExistentShaderFilenamesFromSingleName(shadersName);
	readSrcFromFilenames();
	shadersObjLoaded = generateShadersAndProgram(1);
}

shader::shader(const string &fileName):
	count(0),
	program(0),
	VShader(0),	
	TCShader(0),	
	TEShader(0),	
	GShader(0),	
	FShader(0),	
	//CShader(0),
	shadersFilesExistent(0),
	shadersSourceLoaded(0),
	shadersObjLoaded(0),
	programUsable(0)
{
	//count++;
	g_count++;
	g_shader_list.push_back(this);
	mIndex = g_shader_list.size() - 1;

	shadersName = fileName;
	if((shadersFilesExistent = getExistentShaderFilenamesFromSingleName(fileName))>1)
		if((shadersSourceLoaded = readSrcFromFilenames())>1)
			shadersObjLoaded = generateShadersAndProgram(1);
}

shader::shader(const char *fileName):
	count(0),
	program(0),
	VShader(0),	
	TCShader(0),	
	TEShader(0),	
	GShader(0),	
	FShader(0),	
	//CShader(0),
	shadersFilesExistent(0),
	shadersSourceLoaded(0),
	shadersObjLoaded(0),
	programUsable(0)
{
	//count++;
	g_count++;
	g_shader_list.push_back(this);
	mIndex = g_shader_list.size() - 1;

	shadersName = fileName;
	if((shadersFilesExistent = getExistentShaderFilenamesFromSingleName(fileName))>1)
		if((shadersSourceLoaded = readSrcFromFilenames())>1)
			shadersObjLoaded = generateShadersAndProgram(1);
}

shader::shader(const char *vs, const char *fs, const char *tc, const char *te, const char *gs/*, const char* cs=0*/):
	count(0),
	program(0),
	VShader(0),	
	TCShader(0),	
	TEShader(0),	
	GShader(0),	
	FShader(0),	
	//CShader(0),
	shadersFilesExistent(0),
	shadersSourceLoaded(0),
	shadersObjLoaded(0),
	programUsable(0)
{
	//count++;
	g_count++;
	g_shader_list.push_back(this);
	mIndex = g_shader_list.size() - 1;

	if(vs)
		VS = vs;
	if(tc)
		TC = tc;
	if(te)
		TE = te;
	if(gs)
		GS = gs;
	if(fs)
		FS = fs;
	//if(cs)
	//	CS = cs;
	if((shadersSourceLoaded = readSrcFromFilenames())>1)
		shadersObjLoaded = generateShadersAndProgram(1);
}

shader::shader(const string& vs, const string& fs, const string& tc, const string& te, const string& gs/*, const string cs=0*/) :
	count(0),
	program(0),
	VShader(0),	
	TCShader(0),	
	TEShader(0),	
	GShader(0),	
	FShader(0),	
	//CShader(0),
	shadersFilesExistent(0),
	shadersSourceLoaded(0),
	shadersObjLoaded(0),
	programUsable(0)
{
	//count++;
	g_count++;
	g_shader_list.push_back(this);
	mIndex = g_shader_list.size() - 1;

	VS = vs;
	TC = tc;
	TE = te;
	GS = gs;
	FS = fs;
	//CS = cs;
	if((shadersSourceLoaded = readSrcFromFilenames())>1)
		shadersObjLoaded = generateShadersAndProgram(1);
}

void shader::shader2(const char *fileName)
{
    // 1. retrieve the vertex/fragment source code from filePath
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try 
    {
        // open files
		FILE *vs = 0;
		FILE *fs = 0;
		string file = fileName;
		vs = fopen((file + ".vs").c_str(), "r");
		if(!vs){
			std::cout << "::ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ::" << file << ".vs" << std::endl;
			return;
		};
		fs = fopen((file + ".fs").c_str(), "r");
		if(!fs){
			fclose(vs);
			std::cout << "::ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ::" << file << ".fs" << std::endl;
			return;
		};
		fclose(vs);
		fclose(fs);
		vs = fs = 0;

        vShaderFile.open(file+".vs");
        fShaderFile.open(file+".fs");
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();		
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        VSsrc = vShaderStream.str();
        FSsrc = fShaderStream.str();			
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ:" << fileName << std::endl;
    }
    const char* vShaderCode = VSsrc.c_str();
    const char* fShaderCode = FSsrc.c_str();
    // 2. compile shaders
    //unsigned int vertex, fragment;
    //int success;
    //char infoLog[512];
    // vertex shader
    VShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(VShader, 1, &vShaderCode, NULL);
    glCompileShader(VShader);
    checkCompileErrors(VShader, "VERTEX");
    // fragment Shader
    FShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(FShader, 1, &fShaderCode, NULL);
    glCompileShader(FShader);
    checkCompileErrors(FShader, "FRAGMENT");
    // shader Program
    program = glCreateProgram();
    glAttachShader(program, VShader);
    glAttachShader(program, FShader);
    glLinkProgram(program);
    if(!checkCompileErrors(program, "PROGRAM"))
		programUsable = 1;
    // delete the shaders as they're linked into our program now and no longer necessery
    glDeleteShader(VShader);
    glDeleteShader(FShader);

}

uint shader::getExistentShaderFilenamesFromSingleName(const string &fileName){
	string fname = fileName;
	uint size;
	size = fname.size();
	char ext[] = ".ff"; 
	ext[0] = fname[size-3];
	ext[1] = fname[size-2];
	ext[2] = fname[size-1];

	if(ext[0] == '.' && 
		(_v[0] == ext || _v[1] == ext || _v[2] == ext || _v[3] == ext || _v[4] == ext || _v[5] == ext))
	{
		fname.resize(size-3);
	}

	FILE * f = NULL;
	uint cnt = 0;
	//int notext = 1;
	//f = fopen(fname.c_str(), "r");
	//if(fname[fname.size()-5]!= '.'&& fname[fname.size()-4]!= '.'&& fname[fname.size()-3]!= '.')
	//	notext=0;
	name = fname;
	string vs = name+".vs";
	string fs = name+".fs";
	string tc = name+".tc";
	string te = name+".te";
	string gs = name+".gs";
	string cs = name+".cs";
	if(f = fopen(vs.c_str(), "r")){
		VS = vs;
		cnt++;
		fclose(f);
	}
	if(f = fopen(fs.c_str(), "r")){
		FS = fs;
		cnt++;
		fclose(f);
	}
	if(f = fopen(tc.c_str(), "r")){
		TC = tc;
		cnt++;
		fclose(f);
	}
	if(f = fopen(te.c_str(), "r")){
		TE = te;
		cnt++;
		fclose(f);
	}
	if(f = fopen(gs.c_str(), "r")){
		GS = gs;
		cnt++;
		fclose(f);
	}
	//if(cnt<2){
	//	if(f = fopen(cs.c_str(), "r")){
	//		CS = cs;
	//		cnt++;
	//		fclose(f);
	//	}
	//}
	return cnt;
}

uint shader::readSrcFromFilenames(){
    //std::ifstream ShaderFile;
    //ShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    //try 
    //{
    //    ShaderFile.open(fname);
    //    std::stringstream ShaderStream;
    //    ShaderStream << ShaderFile.rdbuf();
    //    ShaderFile.close();
    //    VSsrc = ShaderStream.str();
    //}
    //catch (std::ifstream::failure e)
    //{
    //    std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ:" << fname << std::endl;
    //}
	uint cnt=0;
	if(VS.size()>3){
		std::ifstream ShaderFile;
		ShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
		try 
		{
			ShaderFile.open(VS);
			std::stringstream ShaderStream;
			ShaderStream << ShaderFile.rdbuf();
			ShaderFile.close();
			VSsrc = ShaderStream.str();
			cnt++;
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_READ:" << VS << std::endl;
		}
	}
	if(TC.size()>3){
		std::ifstream ShaderFile;
		ShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
		try 
		{
			ShaderFile.open(TC);
			std::stringstream ShaderStream;
			ShaderStream << ShaderFile.rdbuf();
			ShaderFile.close();
			TCsrc = ShaderStream.str();
			cnt++;
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_READ:" << TC << std::endl;
		}
	}
	if(TE.size()>3){
		std::ifstream ShaderFile;
		ShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
		try 
		{
			ShaderFile.open(TE);
			std::stringstream ShaderStream;
			ShaderStream << ShaderFile.rdbuf();
			ShaderFile.close();
			TEsrc = ShaderStream.str();
			cnt++;
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_READ:" << TE << std::endl;
		}
	}
	if(GS.size()>3){
		std::ifstream ShaderFile;
		ShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
		try 
		{
			ShaderFile.open(GS);
			std::stringstream ShaderStream;
			ShaderStream << ShaderFile.rdbuf();
			ShaderFile.close();
			GSsrc = ShaderStream.str();
			cnt++;
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_READ:" << GS << std::endl;
		}
	}
	if(FS.size()>3){
		std::ifstream ShaderFile;
		ShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
		try 
		{
			ShaderFile.open(FS);
			std::stringstream ShaderStream;
			ShaderStream << ShaderFile.rdbuf();
			ShaderFile.close();
			FSsrc = ShaderStream.str();
			cnt++;
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_READ:" << FS << std::endl;
		}
	}
	//if(CS.size()>3){
	//	std::ifstream ShaderFile;
	//	ShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
	//	try 
	//	{
	//		ShaderFile.open(CS);
	//		std::stringstream ShaderStream;
	//		ShaderStream << ShaderFile.rdbuf();
	//		ShaderFile.close();
	//		CSsrc = ShaderStream.str();
	//		cnt++;
	//	}
	//	catch (std::ifstream::failure e)
	//	{
	//		std::cout << "ERROR::SHADER::FILE_NOT_READ:" << CS << std::endl;
	//	}
	//}
	return cnt;
}

// activate the shader
// ------------------------------------------------------------------------
int shader::compile(){
	if((VSsrc.size()>3 && FSsrc.size()>3) /*|| CSsrc.size()>3*/){
		shadersObjLoaded = generateShadersAndProgram(1);
		return programUsable;
	}
	else
	{
		if((VS.size()>3 && FS.size()>3) /*|| CS.size()>3*/){
			if((shadersSourceLoaded = readSrcFromFilenames())>1)
				shadersObjLoaded = generateShadersAndProgram(1);
				return programUsable;
		}
		else
		{
			if(shadersName.size()>3){
				if((shadersFilesExistent = getExistentShaderFilenamesFromSingleName(shadersName))>1)
					if((shadersSourceLoaded = readSrcFromFilenames())>1)
						shadersObjLoaded = generateShadersAndProgram(1);
						return programUsable;
			}
		}
	}
	return programUsable;
}

int shader::setSource(string &src, ShaderType type){
	switch(type){
	case ShaderType::SHADER_FRAGMENT:
			FSsrc = src;
			return 1;
		case ShaderType::SHADER_VERTEX:
			VSsrc = src;
			return 1;
		case ShaderType::SHADER_TESSELATIONC:
			TCsrc = src;
			return 1;
		case ShaderType::SHADER_TESSELATIONE:
			TEsrc = src;
			return 1;
		case ShaderType::SHADER_GEOMETRY:
			GSsrc = src;
			return 1;
		//case ShaderType::SHADER_COMPUTE:
		//	CSsrc = src;
			//return 1;
		default:
			return 0;
	}
	return 0;
}

int shader::setSource(const char *src, ShaderType type){
	switch(type){
		case ShaderType::SHADER_FRAGMENT:
			FSsrc = src;
			return 1;
		case ShaderType::SHADER_VERTEX:
			VSsrc = src;
			return 1;
		case ShaderType::SHADER_TESSELATIONC:
			TCsrc = src;
			return 1;
		case ShaderType::SHADER_TESSELATIONE:
			TEsrc = src;
			return 1;
		case ShaderType::SHADER_GEOMETRY:
			GSsrc = src;
			return 1;
		//case ShaderType::SHADER_COMPUTE:
		//	CSsrc = src;
			//return 1;
		default:
			return 0;
	}
	return 0;
}

int shader::setSource(string& fs, string& vs, string& tc, string& te, string& gs) {
	if(fs.size()>3)
		FSsrc = fs;
	if (vs.size() > 3)
		VSsrc = vs;
	if (tc.size() > 3)
		TCsrc = tc;
	if (te.size() > 3)
		TEsrc = te;
	if (gs.size() > 3)
		GSsrc = gs;
	return 1;
}

int shader::setSource(const char* fs, const char* vs, const char* tc, const char* te, const char* gs) {
	if (fs)
		FSsrc = fs;
	if (vs)
		VSsrc = vs;
	if (tc)
		TCsrc = tc;
	if (te)
		TEsrc = te;
	if (gs)
		GSsrc = gs;
	return 1;
}

uint shader::generateShadersAndProgram( int deleteShaderObjs){
	glUseProgram(0);
	if (program)
		glDeleteProgram(program);

	program = glCreateProgram();
	const char * str;
	uint cnt = 0;
	if(VSsrc.size()>3){
		VShader = glCreateShader(GL_VERTEX_SHADER);	
		str = VSsrc.c_str();
		glShaderSource(VShader, 1, &str, NULL);
		glCompileShader(VShader);
		cnt+=checkCompileErrors(VShader, "VertexShader");
		glAttachShader(program, VShader);
	}
	if(TCsrc.size()>3){
		TCShader = glCreateShader(GL_TESS_CONTROL_SHADER);	
		str = TCsrc.c_str();
		glShaderSource(TCShader, 1, &str, NULL);
		glCompileShader(TCShader);
		cnt+=checkCompileErrors(TCShader, "TessControlShader");
		glAttachShader(program, TCShader);
	}
	if(TEsrc.size()>3){
		TEShader = glCreateShader(GL_TESS_EVALUATION_SHADER);	
		str = TEsrc.c_str();
		glShaderSource(TEShader, 1, &str, NULL);
		glCompileShader(TEShader);
		cnt+=checkCompileErrors(TEShader, "TessEvaluationShader");
		glAttachShader(program, TEShader);
	}
	if(GSsrc.size()>3){
		GShader = glCreateShader(GL_GEOMETRY_SHADER);	
		str = GSsrc.c_str();
		glShaderSource(GShader, 1, &str, NULL);
		glCompileShader(GShader);
		cnt+=checkCompileErrors(GShader, "GeometryShader");
		glAttachShader(program, GShader);
	}
	if(FSsrc.size()>3){
		FShader = glCreateShader(GL_FRAGMENT_SHADER);
		str = FSsrc.c_str();
		glShaderSource(FShader, 1, &str, NULL);
		glCompileShader(FShader);
		cnt+=checkCompileErrors(FShader, "FragmentShader");
		glAttachShader(program, FShader);
	}
	//if(CSsrc.size()>3){
	//	if(cnt<2){
	//		CShader = glCreateShader(GL_COMPUTE_SHADER);	
	//		str = CSsrc.c_str();
	//		glShaderSource(CShader, 1, &str, NULL);
	//		glCompileShader(CShader);
	//		cnt+=checkCompileErrors(CShader, "ComputeShader");
	//		glAttachShader(program, CShader);
	//	}
	//}
	glLinkProgram(program);
    programUsable = checkCompileErrors(program, "PROGRAM");
    // delete the shaders as they're linked into our program now and no longer necessery

	if(deleteShaderObjs && programUsable)
		deleteShaders();
	return cnt;
}

uint shader::use() const
{ 
	if(program && programUsable){
		glUseProgram(program); 
		return 1;
	}
 	return 0;
}

void shader::deleteShaders()
{
	if (VShader) {
		glDeleteShader(VShader);
		VShader = 0;
	}
	if (TCShader) {
		glDeleteShader(TCShader);
	}
	if (TEShader) {
		glDeleteShader(TEShader);
	}
	if (GShader) {
		glDeleteShader(GShader);
	}
	if (FShader) {
		glDeleteShader(FShader);
	}
	//if(CShader )
	//	glDeleteShader(CShader );

	VShader =
		TCShader =
		TEShader =
		GShader =
		FShader =
		/*CShader =*/0;
}

shader* shader::atach(void) {
	count++;
	return this;
}

void shader::detach(void) {
	count--;
	if (count <= 0) {
		g_shader_list[mIndex] = NULL;
		delete this;
	}
}


// utility function for checking shader compilation/linking errors.
// ------------------------------------------------------------------------
uint shader::checkCompileErrors(GLuint shader, string type)
{
	GLint success;
	GLint size;
	GLchar* infoLog;
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &size);
		if (!success || size > 1)
		{
			infoLog = new GLchar[size + 2];
			infoLog[size] = 0;
			glGetShaderInfoLog(shader, size - 1, NULL, infoLog);
			std::cout << " -- -----\nERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog <<
				"\n -- --------------------------------------------------- -- " << std::endl;
			delete[] infoLog;
			return success;
		}
		return success;
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		glGetProgramiv(shader, GL_INFO_LOG_LENGTH, &size);
		if (!success || size > 1)
		{
			infoLog = new GLchar[size + 1];
			infoLog[size] = 0;
			glGetProgramInfoLog(shader, size - 1, NULL, infoLog);
			std::cout << " -- ------\nERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog <<
				"\n -- --------------------------------------------------- -- " << std::endl;
			delete[] infoLog;
			return success;
		}
		return success;
	}
}

// utility uniform functions
// ------------------------------------------------------------------------
void shader::setBool(const string &uname, bool value) const
{         
    glUniform1i(glGetUniformLocation(program, uname.c_str()), (int)value); 
}
// ------------------------------------------------------------------------
void shader::setInt(const string &uname, int value) const
{ 
    glUniform1i(glGetUniformLocation(program, uname.c_str()), value); 
}
// ------------------------------------------------------------------------
void shader::setFloat(const string &uname, float value) const
{ 
    glUniform1f(glGetUniformLocation(program, uname.c_str()), value); 
}
// ------------------------------------------------------------------------
void shader::setVec2(const string &uname, const vec2 &value) const
{ 
    glUniform2fv(glGetUniformLocation(program, uname.c_str()), 1, &value[0]); 
}
void shader::setVec2(const string &uname, float x, float y) const
{ 
    glUniform2f(glGetUniformLocation(program, uname.c_str()), x, y); 
}
// ------------------------------------------------------------------------
void shader::setVec3(const string &uname, const vec3 &value) const
{ 
    glUniform3fv(glGetUniformLocation(program, uname.c_str()), 1, &value[0]); 
}
void shader::setVec3(const string &uname, float x, float y, float z) const
{ 
    glUniform3f(glGetUniformLocation(program, uname.c_str()), x, y, z); 
}
// ------------------------------------------------------------------------
void shader::setVec4(const string &uname, const vec4 &value) const
{ 
    glUniform4fv(glGetUniformLocation(program, uname.c_str()), 1, &value[0]); 
}
void shader::setVec4(const string &uname, float x, float y, float z, float w) const
{ 
    glUniform4f(glGetUniformLocation(program, uname.c_str()), x, y, z, w); 
}
// ------------------------------------------------------------------------
void shader::setMat2(const string &uname, const mat2 &mat) const
{
    glUniformMatrix2fv(glGetUniformLocation(program, uname.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void shader::setMat3(const string &uname, const mat3 &mat) const
{
    glUniformMatrix3fv(glGetUniformLocation(program, uname.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void shader::setMat4(const string &uname, const mat4 &mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(program, uname.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void shader::setUniform(const string &uname, const bool &val) const
{
    glUniform1i(glGetUniformLocation(program, uname.c_str()), (int)val);
}
void shader::setUniform(const string &uname, const int &val) const
{
    glUniform1i(glGetUniformLocation(program, uname.c_str()), val);
}
void shader::setUniform(const string &uname, const uint &val) const
{
    glUniform1ui(glGetUniformLocation(program, uname.c_str()), val);
}
void shader::setUniform(const string &uname, const float &val) const
{
    glUniform1f(glGetUniformLocation(program, uname.c_str()), val);
}
void shader::setUniform(const string &uname, const double &val) const
{
    glUniform1d(glGetUniformLocation(program, uname.c_str()), val);
}
void shader::setUniform(const string &uname, const vec2 &val) const
{
    glUniform2fv(glGetUniformLocation(program, uname.c_str()), 1, &val.x); 
}
void shader::setUniform(const string &uname, const vec3 &val) const
{
    glUniform3fv(glGetUniformLocation(program, uname.c_str()), 1, &val.x);
}
void shader::setUniform(const string &uname, const vec4 &val) const
{
    glUniform4fv(glGetUniformLocation(program, uname.c_str()), 1, &val.x);
}
void shader::setUniform(const string &uname, const mat2 &val) const
{
    glUniformMatrix2fv(glGetUniformLocation(program, uname.c_str()), 1, GL_FALSE, &val[0][0]);
}
void shader::setUniform(const string &uname, const mat3 &val) const
{
    glUniformMatrix3fv(glGetUniformLocation(program, uname.c_str()), 1, GL_FALSE, &val[0][0]);
}
void shader::setUniform(const string &uname, const mat4 &val) const
{
    glUniformMatrix4fv(glGetUniformLocation(program, uname.c_str()), 1, GL_FALSE, &val[0][0]);
}









