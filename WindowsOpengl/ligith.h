#pragma once
class ligith: public objetob
{
public:
	ligith(void);
	~ligith(void);
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

