#pragma once

//GLuint uniforms_buffer = 0;

enum class objType {
	objNone=0,
	objEsfera,
	objTorus,
	objCilindro,
	objCone,
	objBox,
	objQuad,
	objTriangulo,
};

class objeto :
	public objetob
{
public:
	objeto();
	objeto(objeto *parent, objType t, vec3 Pos=vec3(0), vec3 Rot= vec3(0), vec3 Size= vec3(0), uint3 Res = uint3(3, 3, 3));
	objeto(objeto *parent);
	~objeto();

	static uint g_count;	// total number of shaders actual in the program
	uint count;				// number of times the shader is used
	uint mIndex;			// index of this shader in global list of shaders

	//std::vector<material*> Material;	// material usado? override malha properties
	std::vector<malha*> malhas;	// geometria do objeto
	std::vector<objeto*> child;
	objeto* parent;

	int atach();

	void detach();

	void calcMatrix();

	void setMatrix();

	void draw();

	void refreshGlobal(vec3 p, vec3 s, vec4 r);


	// SET

	// add position to object, works in local coordinates
	void move(vec3 plus);
	// add size to object, works in local coordinates
	void resize(vec3 size);
	// add rotation to object, works in local coordinates
	void rotate(vec4 rotation);
	// move object to local position, works in local coordinates
	void moveto(vec3 to);
	// move object to local position, works in local coordinates
	void setpos(vec3 position);
	// resize object in local space, works in local coordinates
	void setsize(vec3 tosize);
	// set object totation in local space, works in local coordinates
	void setrotation(vec3 rotation);
	// set the position in local space
	vec3 setLocalPosition();
	// set the rotation in local space
	vec3 setLocalRotation();
	// set the size in local space
	vec3 setLocalSize();

	// set the position in GLOBAL space
	vec3 setGlobalPosition();
	// set the rotation in GLOBAL space
	vec3 setGlobalRotation();
	// set the size in GLOBAL space
	vec3 setGlobalSize();


	// GET

	// returns the position in local space
	vec3 getLocalPosition();
	// returns the rotation in local space
	vec3 getLocalRotation();
	// returns the size in local space
	vec3 getLocalSize();

	// get the position in GLOBAL space
	vec3 getGlobalPosition();
	// get the rotation in GLOBAL space
	vec3 getGlobalRotation();
	// get the size in GLOBAL space
	vec3 getGlobalSize();

};


