#pragma once
#ifndef _wogl_h
#define _wogl_h 1
#include "resource.h"
#include "manager.h"
//#include "stdafx.h"

typedef struct GLContextStruct
{
	HWND hwnd;
	HDC hdc;
	HGLRC hglrc;
	GLuint sx;
	GLuint sy;
	WNDCLASS wc;

} GLContext;

typedef struct KeyMap
{
	ushort lshift : 1;	//1
	ushort rshift : 1;	//2
	ushort lctrl : 1;	//3
	ushort rctrl : 1;	//4
	ushort lalt : 1;	//5
	ushort ralt : 1;	//6
	ushort space : 1;	//7
	ushort win : 1;		//8
	ushort up : 1;		//9
	ushort down : 1;	//10
	ushort capsl : 1;	//11
	ushort numl : 1;	//12
	ushort scroll : 1;	//13

} KeyMap, * pKeyMap;
//int a[sizeof KeyMap];

void onRenderScene(void);
void onResize(int x, int y, WPARAM wParam, LPARAM lParam);
void onMove(int x, int y, WPARAM wParam, LPARAM lParam);
void onPaint(PAINTSTRUCT* rc, WPARAM wParam, LPARAM lParam);
void onMouseWhell(int val, WPARAM wParam, LPARAM lParam);
void onMouseMove(int x, int y, WPARAM wParam, LPARAM lParam);
void onMousePress(int x, int y, WPARAM wParam, LPARAM lParam, int up, int n);
void onComand(int cmd, WPARAM wParam, LPARAM lParam);
void onKeyPress(int key, WPARAM wParam, LPARAM lParam, pKeyMap keymap);

void drawSphere(int xres, int yres, float3 size);
void drawCube(float3 size, GLint type);





#endif
