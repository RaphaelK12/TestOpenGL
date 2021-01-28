#pragma once
#ifndef stdafx_h
#define stdafx_h 1
//#define GL_GLEXT_PROTOTYPES 1
//#include "targetver.h"

#define _CRT_SECURE_NO_WARNINGS 1
#define _USE_MATH_DEFINES 1
#include "VectorsGLM.h"
#include <windows.h>
#include <WinBase.h>
#include <minwindef.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <list>
#include <tuple>
#include <fstream>
#include <sstream>
#include <istream>
#include <string>
#include <iostream>
#include <limits.h>

#include <stdlib.h>
#include <gl/GL.h>

#include "core+ext.h"
#include "GLgetFunctions.h"

#define _avoid_unessessary_include_defines 1
#if _avoid_unessessary_include_defines
#define WGL_3DL_stereo_control 1
#define WGL_EXT_display_color_table 1
#define WGL_EXT_make_current_read 1
#define WGL_EXT_pbuffer 1
#define WGL_EXT_pixel_format 1
#define WGL_I3D_digital_video_control 1
#define WGL_I3D_gamma 1
#define WGL_I3D_image_buffer 1
#define WGL_I3D_swap_frame_lock 1
#define WGL_I3D_swap_frame_usage 1
#define WGL_NV_copy_image 1
#define WGL_NV_delay_before_swap 1
#define WGL_NV_gpu_affinity 1
#define WGL_NV_present_video 1
#define WGL_NV_vertex_array_range 1
#define WGL_NV_video_capture 1
#define WGL_NV_video_output 1
#define WGL_OML_sync_control 1
#endif
#include "wgl+wglext.h"
#if _avoid_unessessary_include_defines
#undef WGL_3DL_stereo_control 
#undef WGL_EXT_display_color_table 
#undef WGL_EXT_make_current_read 
#undef WGL_EXT_pbuffer 
#undef WGL_EXT_pixel_format 
#undef WGL_I3D_digital_video_control 
#undef WGL_I3D_gamma 
#undef WGL_I3D_image_buffer 
#undef WGL_I3D_swap_frame_lock 
#undef WGL_I3D_swap_frame_usage 
#undef WGL_NV_copy_image 
#undef WGL_NV_delay_before_swap 
#undef WGL_NV_gpu_affinity 
#undef WGL_NV_present_video 
#undef WGL_NV_vertex_array_range 
#undef WGL_NV_video_capture 
#undef WGL_NV_video_output 
#undef WGL_OML_sync_control 
#endif
#include "WGlGetFunctions.h"

//extern int LoadOGL();
//extern int LoadWGL();
//

#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glaux.lib")




//#include <gl/GLU.h>
//#include <gl/GLAUX.H>
//#include <tchar.h>
//#include "gl3w.h"
//#include <gl/glcorearb.h>
//#include <gl/glext.h>
//#include <gl/wgl.h>
//#include <gl/wglext.h>
//#include <gl/glxext.h>
//#include <gl/GLAUX.h>
//#include <gl/GLU.h>
//#include <gl/glx.h>

typedef   signed char      schar;
typedef unsigned char      uchar;
typedef unsigned short     ushort;
typedef unsigned int       uint;
typedef unsigned long long ulong;
typedef   signed long long slong;

struct matrix_block
{
	mat4     M;
	mat4     V;
	mat4     P;
	mat4     MV;
	mat4     MVP;
};


//extern GLContext ctx;

//#include "Vectors.h"
//#include "Matrix.h"




// TODO: reference additional headers your program requires here



#endif // stdafx_h