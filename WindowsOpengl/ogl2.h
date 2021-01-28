#ifndef _ogl2_h
#define _ogl2_h 1
#include "manager.h"


//#include "stdafx.h"

typedef struct KeyMap
{
	char lshift:1;
	char rshift:1;
	char lctrl:1;
	char rctrl:1;
	char lalt:1;
	char ralt:1;
	char space:1;
	char win:1;
} KeyMap, *pKeyMap;
//int a[sizeof KeyMap];

typedef struct GLContextStruct
{
	HWND hwnd;
	HDC hdc;
	HGLRC hglrc;
	GLuint sx;
	GLuint sy;
	WNDCLASS wc;

} GLContext;

void onRenderScene(void);
void onResize(		int x,	int y,		WPARAM wParam, LPARAM lParam);
void onMove(		int x,	int y,		WPARAM wParam, LPARAM lParam);
void onPaint(		PAINTSTRUCT *rc,	WPARAM wParam, LPARAM lParam);
void onMouseWhell(	int val,			WPARAM wParam, LPARAM lParam);
void onMouseMove(	int x,	int y,		WPARAM wParam, LPARAM lParam);
void onMousePress(	int x,	int y,		WPARAM wParam, LPARAM lParam,  int up, int n);
void onComand(		int cmd,			WPARAM wParam, LPARAM lParam);
void onKeyPress(	int key,			WPARAM wParam, LPARAM lParam, pKeyMap keymap);

void drawSphere(int xres, int yres, float3 size);
void drawCube(float3 size, GLint type);





#endif
