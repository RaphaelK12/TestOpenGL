#pragma once
class camera :
	public objetob
{
public:
	camera(void);
	~camera(void);
	float nearClip;
	float farClip;
	float left;
	float right;
	float botton;
	float top;
	float fov;
	float aspect;
	vec3 center;
	vec3 up;


	void calcMatrix();


};

extern camera* activecamera;


