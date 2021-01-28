#pragma once

class objetob
{
public:
	objetob(void);
	objetob(std::string &nome, uint tipo, vec4 &Pos, vec4 &Rot, vec4 &sz, vec3 *boundBox, float raio);
	~objetob(void);
	uint type;
	static uint g_count;	// total number of shaders actual in the program
	uint count;				// number of times the shader is used
	uint mIndex;			// index of this shader in global list of shaders
	std::string name;
	vec4 lrot;		// rotation for each object
	vec3 lsize;		// size for each object
	vec3 lpos;		// position for each object

	vec4 grot;		// rotation for each object
	vec3 gsize;		// size for each object
	vec3 gpos;		// position for each object
	// matrix block
	matrix_block matrix; 
	vec3 bb[8];		// bounding box of this object, used to make tests on rendering objects
	float raius;	// radius of this object, used to make tests on rendering objects, to render or discard from rendering
};

