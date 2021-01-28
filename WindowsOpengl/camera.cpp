#include "stdafx.h"
#include "objetob.h"
#include "shader.h"
#include "texture.h"
#include "material.h"
#include "malha.h"
#include "objeto.h"
#include "camera.h"

camera* activecamera = new camera;


camera::camera(void):
	nearClip(0.1f),
	farClip(100.f),
	left(-1.f),
	right(1.f),
	botton(-1.f),
	top(1.f),
	fov(0.500f),
	aspect(1.0f),
	center(0,0,0),
	up(0.0f, 1.0f, 0.0f)
{
	lpos = vec3(-5, -5, 0);
	gpos = vec3(10, 1, 0);
	center = vec3(0, 0, 0);

	matrix.V = glm::lookAt(gpos, center, up); //pos, center, up
	matrix.P = glm::perspective(fov, aspect, nearClip, farClip);	//perspective(fovy, aspect, zNear, zFar)

}


camera::~camera(void)
{
}

void camera::calcMatrix()
{
	matrix.V = glm::lookAt(gpos, center, up); //pos, center, up
	matrix.P = glm::perspective(fov, aspect, nearClip, farClip);	//perspective(fovy, aspect, zNear, zFar)
}




void MVPexample() {
	vec3 objPoss = vec3(1, 1, 1);
	vec3 light_position = vec3(-20.0f, -20.0f, 0.0f);
	vec3 view_position = vec3(0.0f, 0.0f, 50.0f);

	mat4 model_matrix = glm::translate(glm::identity<mat4>(), vec3(0, 0, 0));	//mat4, pos
	mat4 view_matrix = glm::lookAt(view_position, vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f)); //pos, center, up
	mat4 proj_matrix = glm::perspective(50.0f, 1.0f, 0.1f, 1000.0f);	//perspective(fovy, aspect, zNear, zFar)

	mat4 mv_matrix = view_matrix * model_matrix;

	model_matrix = glm::scale(model_matrix, vec3(1, 1, 1));
	model_matrix = glm::rotate(model_matrix, 1.0f, vec3(1, 1, 1));
	mat4 light_proj_matrix = glm::frustum(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 200.0f);	//frustum( left,  right,  bottom,  top,  nearVal,  farVal)
	mat4 light_view_matrix = glm::lookAt(light_position, vec3(0.0f), vec3(0.0f, 1.0f, 0.0f));
}

