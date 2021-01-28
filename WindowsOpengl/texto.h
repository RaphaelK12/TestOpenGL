#pragma once
class texto : 
	public malha
{
public:
	texto(void);
	texto(const char* txt);
	texto(std::string txt);

	~texto(void);

	void draw(/*vec4 &color, vec2 &size, vec3 &pos, vec3 &rot*/);
	void constructVBO();
	void make(std::string txt);

	std::string text;
	uint len;
	uint nIndex;
	malha *obj;
	vec4 color;
	std::vector<vec3> v;
	std::vector<usvec4> f;
	std::vector<vec2> uv;

};


