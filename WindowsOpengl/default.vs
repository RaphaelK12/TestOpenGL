#version 410 core

// Per-vertex inputs
layout (location = 0) in vec4 inPosition;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec2 inUv1;
layout (location = 3) in vec4 inColor1;
layout (location = 4) in vec3 inTangent;
layout (location = 5) in vec3 inBiTangent;
layout (location = 6) in vec2 inUv2;
layout (location = 7) in vec2 inUv3;
layout (location = 8) in vec4 inColor2;
layout (location = 9) in vec4 inColor3;

// Matrices we'll need
uniform mat4 mt_model;
uniform mat4 mt_view;
uniform mat4 mt_projection;
uniform mat4 mt_modelView;
uniform mat4 mt_modelViewProjection;

// Outputs to fragment shader
out VS_OUT
{
	vec4 position;
	vec4 position_M;
	vec4 position_V;
	vec4 position_P;
	vec4 position_MV;
	vec4 position_MVP;

	vec3 normal;	// normal
	vec3 lightDir;	// Light
	vec2 uv1;		// first uv
	
	// rarely used, not necessary
	vec2 uv2;		// Second uv possible not used
	vec4 color1;		// vertex color 
	vec4 color2;	// vertex color 
} vs_out;

vec3 light_pos = vec3(5, 0, 0);

void main(void){
	// Calculate view-space coordinate
	vec4 P = mt_model * inPosition;

	// Calculate normal in view-space
	// vs_out.N = mat3(mt_modelView) * inNormal;
	mat3 normalMatrix = mat3(transpose(inverse(mt_model)));
	vs_out.normal = normalize(vec3( normalMatrix * inNormal));

	// Calculate light vector
	vs_out.lightDir = light_pos - P.xyz;

	vs_out.position		= inPosition; // local
	vs_out.position_M	= mt_model * inPosition; // global
	vs_out.position_V	= mt_view * inPosition; // global
	vs_out.position_P	= mt_projection * inPosition;
	vs_out.position_MV	= mt_modelView * inPosition;  // global view
	vs_out.position_MVP = mt_modelViewProjection * inPosition; // global projection
	vs_out.uv1=inUv1;
	vs_out.color1=inColor2;

	// Calculate the clip-space position of each vertex
	gl_Position = mt_modelViewProjection * inPosition;
}
