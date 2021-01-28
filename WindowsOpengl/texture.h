#pragma once
class texture
{
public:
	texture(void);
	~texture(void);
	void atach();
	void detach();
	uint type;
	std::string name;
	std::string fileName;
	uint globj;
	usvec2 res;
	uint format;
	uint dataType;
	uint dataSize;
	void *data;

};

