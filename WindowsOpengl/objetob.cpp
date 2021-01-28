#include "StdAfx.h"
#include "objetob.h"

std::vector<objetob*> g_objetob_list;

uint objetob::g_count = 0;


objetob::objetob(void):
	type(0),	count(0),	mIndex(0),	lpos(0),	lrot(0),	lsize(1),	gpos(0),	grot(0),	gsize(1),	raius(0), bb()
{
	g_count++;
	g_objetob_list.push_back(this);
	mIndex = g_objetob_list.size() - 1;
}

objetob::objetob(std::string& nome, uint tipo, vec4& Pos, vec4& Rot, vec4& sz, vec3* boundBox, float raio):
	count(0),
	mIndex(0)
{
	g_count++;
	g_objetob_list.push_back(this);
	mIndex = g_objetob_list.size() - 1;

	name = nome;
	type = tipo;
	lpos = Pos;	
	lrot = Rot;	
	lsize = sz;
	//M;		
	//V;		
	//P;		
	//MV;		
	//MVP;	
	if(boundBox)
		memcpy(bb, boundBox, 8 * sizeof(vec3));
	raius = raio;
}

objetob::~objetob(void)
{
	if (g_objetob_list.size() >= mIndex)
		g_objetob_list[mIndex] = 0;
	g_count--;
}



