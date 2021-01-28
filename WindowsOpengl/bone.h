#pragma once
class bone: public objetob
{
public:
	bone(void);
	~bone(void);
	vec4 pos2;
	int num;  // used in definitions of BONE_HEAD, BONE_NECK, BONE_CLAVICLE,...
	bone *next; // chain
	bone *prev;

};

