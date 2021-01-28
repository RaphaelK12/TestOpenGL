#include <Windows.h>
#include <stdio.h>
#include "gl\gl.h"
#include "core+ext.h"
#include "GLfunctions.h"
#define GL_WIN_MAIN 1
#undef GLFunctions_h
#include "GLFunctions.h"

#ifndef _opengl32_dll_
#define _opengl32_dll_ 1
HMODULE opengl32_dll = NULL;
#endif

#ifndef invalidPointer
#define	invalidPointer (p == (void*)0x0 || (p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) || (p == (void*)-1) )
#endif

FILE *LogGlGetFunctions_py = NULL;
char GlBuffer256[256];

// char * GL_GetFunc1(char * type, char * ext){
	// sprintf(GlBuffer256, "%s%s", type, ext);
	// return GlBuffer256;
// };

 void *GL_GetF(const char *name)
{
	void *p = (void *)wglGetProcAddress(name);
	// opengl32.dll
	if	(p == (void*)0x0  ||
		(p == (void*)0x1) ||
		(p == (void*)0x2) ||
		(p == (void*)0x3) ||
		(p == (void*)-1) )
	{
		p = (void *)GetProcAddress(opengl32_dll, name);
	}
    if  (p == (void*)0x0  ||
        (p == (void*)0x1) ||
        (p == (void*)0x2) ||
        (p == (void*)0x3) ||
        (p == (void*)-1) )
    {
        p = NULL;
    }
	fprintf(LogGlGetFunctions_py, "	%x : %s\n", p, name);
	return p;
}
 void *GL_GetF2(const char *name)
{
	void * p;
		p = (void *)wglGetProcAddress(name);
	// opengl32.dll
	if	(invalidPointer)
	{
		p = (void *)GetProcAddress(opengl32_dll, name);
	}
	fprintf(LogGlGetFunctions_py, "	%x : %s\n", p, name);
	
    if  (invalidPointer)
    {
		// ARB
		sprintf(GlBuffer256, "%s%s\0\0", name, "ARB");
		p = (void *)wglGetProcAddress(GlBuffer256);
		if	(invalidPointer)
		{
			p = (void *)GetProcAddress(opengl32_dll, GlBuffer256);
		}
		
		// EXT
		if  (invalidPointer)
		{
			sprintf(GlBuffer256, "%s%s\0\0", name, "EXT");
			p = (void *)wglGetProcAddress(GlBuffer256);
			if	(invalidPointer)
			{
				p = (void *)GetProcAddress(opengl32_dll, GlBuffer256);
			}
		}
		
		// NV
		if  (invalidPointer)
		{
			sprintf(GlBuffer256, "%s%s\0\0", name, "NV");
			p = (void *)wglGetProcAddress(GlBuffer256);
			if	(invalidPointer)
			{
				p = (void *)GetProcAddress(opengl32_dll, GlBuffer256);
			}
		}
		
		// AMD
		if  (invalidPointer)
		{
			sprintf(GlBuffer256, "%s%s\0\0", name, "AMD");
			p = (void *)wglGetProcAddress(GlBuffer256);
			if	(invalidPointer)
			{
				p = (void *)GetProcAddress(opengl32_dll, GlBuffer256);
			}
		}
		
		// ATI
		if  (invalidPointer)
		{
			sprintf(GlBuffer256, "%s%s\0\0", name, "ATI");
			p = (void *)wglGetProcAddress(GlBuffer256);
			if	(invalidPointer)
			{
				p = (void *)GetProcAddress(opengl32_dll, GlBuffer256);
			}
		}
		
		// NVX
		if  (invalidPointer)
		{
			sprintf(GlBuffer256, "%s%s\0\0", name, "NVX");
			p = (void *)wglGetProcAddress(GlBuffer256);
			if	(invalidPointer)
			{
				p = (void *)GetProcAddress(opengl32_dll, GlBuffer256);
			}
		}
		if	(invalidPointer)
			p = NULL;
		if	(!invalidPointer)
			fprintf(LogGlGetFunctions_py, "	  %x : %s\n", p, GlBuffer256);
	}
	return p;
}

#define GL_GetFuncEXT(type,name) name=(type)GL_GetF(#name);

#define GL_GetFunc(type,name) name=(type)GL_GetF2(#name); 

/*#define GL_GetFunc(type,name) name=(type)GL_GetF(#name);          	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "ARB"));         	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "EXT"));         	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "NV"));          	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "AMD"));         	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "ATI"));         	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "NVX"));         	

if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "3DFX"));      	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "AMDX"));      	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "APPLE"));     	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "GREMEDY"));    	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "HP"));        	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "I3D"));       	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "IBM"));       	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "INGR"));      	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "INTEL"));     	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "KHR"));       	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "KTX"));       	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "MESA"));      	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "OES"));       	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "OVR"));       	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "PGI"));       	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "SGI"));       	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "SGIS"));      	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "SGIX"));      	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "SUN"));       	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "SUNX"));      	\
if(!name) name=(type)GL_GetF(GL_GetFunc1(#name , "WIN"));       	*/



 int LoadOGL(){
	LogGlGetFunctions_py = fopen("LogGlGetFunctions.py", "wb");
	if (!opengl32_dll)
	 opengl32_dll = LoadLibraryA("opengl32.dll");
    #ifdef GL_VERSION_1_0
	#ifndef __gl_h_
	#ifndef __GL_H__
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_1_0\n");
    GL_GetFunc(PFNGLCULLFACEPROC                                ,glCullFace                 );
    GL_GetFunc(PFNGLFRONTFACEPROC                               ,glFrontFace                );
    GL_GetFunc(PFNGLHINTPROC                                    ,glHint                     );
    GL_GetFunc(PFNGLLINEWIDTHPROC                               ,glLineWidth                );
    GL_GetFunc(PFNGLPOINTSIZEPROC                               ,glPointSize                );
    GL_GetFunc(PFNGLPOLYGONMODEPROC                             ,glPolygonMode              );
    GL_GetFunc(PFNGLSCISSORPROC                                 ,glScissor                  );
    GL_GetFunc(PFNGLTEXPARAMETERFPROC                           ,glTexParameterf            );
    GL_GetFunc(PFNGLTEXPARAMETERFVPROC                          ,glTexParameterfv           );
    GL_GetFunc(PFNGLTEXPARAMETERIPROC                           ,glTexParameteri            );
    GL_GetFunc(PFNGLTEXPARAMETERIVPROC                          ,glTexParameteriv           );
    GL_GetFunc(PFNGLTEXIMAGE1DPROC                              ,glTexImage1D               );
    GL_GetFunc(PFNGLTEXIMAGE2DPROC                              ,glTexImage2D               );
    GL_GetFunc(PFNGLDRAWBUFFERPROC                              ,glDrawBuffer               );
    GL_GetFunc(PFNGLCLEARPROC                                   ,glClear                    );
    GL_GetFunc(PFNGLCLEARCOLORPROC                              ,glClearColor               );
    GL_GetFunc(PFNGLCLEARSTENCILPROC                            ,glClearStencil             );
    GL_GetFunc(PFNGLCLEARDEPTHPROC                              ,glClearDepth               );
    GL_GetFunc(PFNGLSTENCILMASKPROC                             ,glStencilMask              );
    GL_GetFunc(PFNGLCOLORMASKPROC                               ,glColorMask                );
    GL_GetFunc(PFNGLDEPTHMASKPROC                               ,glDepthMask                );
    GL_GetFunc(PFNGLDISABLEPROC                                 ,glDisable                  );
    GL_GetFunc(PFNGLENABLEPROC                                  ,glEnable                   );
    GL_GetFunc(PFNGLFINISHPROC                                  ,glFinish                   );
    GL_GetFunc(PFNGLFLUSHPROC                                   ,glFlush                    );
    GL_GetFunc(PFNGLBLENDFUNCPROC                               ,glBlendFunc                );
    GL_GetFunc(PFNGLLOGICOPPROC                                 ,glLogicOp                  );
    GL_GetFunc(PFNGLSTENCILFUNCPROC                             ,glStencilFunc              );
    GL_GetFunc(PFNGLSTENCILOPPROC                               ,glStencilOp                );
    GL_GetFunc(PFNGLDEPTHFUNCPROC                               ,glDepthFunc                );
    GL_GetFunc(PFNGLPIXELSTOREFPROC                             ,glPixelStoref              );
    GL_GetFunc(PFNGLPIXELSTOREIPROC                             ,glPixelStorei              );
    GL_GetFunc(PFNGLREADBUFFERPROC                              ,glReadBuffer               );
    GL_GetFunc(PFNGLREADPIXELSPROC                              ,glReadPixels               );
    GL_GetFunc(PFNGLGETBOOLEANVPROC                             ,glGetBooleanv              );
    GL_GetFunc(PFNGLGETDOUBLEVPROC                              ,glGetDoublev               );
    GL_GetFunc(PFNGLGETERRORPROC                                ,glGetError                 );
    GL_GetFunc(PFNGLGETFLOATVPROC                               ,glGetFloatv                );
    GL_GetFunc(PFNGLGETINTEGERVPROC                             ,glGetIntegerv              );
    GL_GetFunc(PFNGLGETSTRINGPROC                               ,glGetString                );
    GL_GetFunc(PFNGLGETTEXIMAGEPROC                             ,glGetTexImage              );
    GL_GetFunc(PFNGLGETTEXPARAMETERFVPROC                       ,glGetTexParameterfv        );
    GL_GetFunc(PFNGLGETTEXPARAMETERIVPROC                       ,glGetTexParameteriv        );
    GL_GetFunc(PFNGLGETTEXLEVELPARAMETERFVPROC                  ,glGetTexLevelParameterfv   );
    GL_GetFunc(PFNGLGETTEXLEVELPARAMETERIVPROC                  ,glGetTexLevelParameteriv   );
    GL_GetFunc(PFNGLISENABLEDPROC                               ,glIsEnabled                );
    GL_GetFunc(PFNGLDEPTHRANGEPROC                              ,glDepthRange               );
    GL_GetFunc(PFNGLVIEWPORTPROC                                ,glViewport                 );
    #endif /* __GL_H__ GL_VERSION_1_0 */
    #endif /* __gl_h_  GL_VERSION_1_0 */
    #endif /* GL_VERSION_1_0 */

    #ifdef GL_VERSION_1_1
	#ifndef __gl_h_
	#ifndef __GL_H__
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_1_1\n");
	GL_GetFunc(PFNGLDRAWARRAYSPROC                        ,glDrawArrays                 );
	GL_GetFunc(PFNGLDRAWELEMENTSPROC                      ,glDrawElements               );
	GL_GetFunc(PFNGLGETPOINTERVPROC                       ,glGetPointerv                );
	GL_GetFunc(PFNGLPOLYGONOFFSETPROC                     ,glPolygonOffset              );
	GL_GetFunc(PFNGLCOPYTEXIMAGE1DPROC                    ,glCopyTexImage1D             );
	GL_GetFunc(PFNGLCOPYTEXIMAGE2DPROC                    ,glCopyTexImage2D             );
	GL_GetFunc(PFNGLCOPYTEXSUBIMAGE1DPROC                 ,glCopyTexSubImage1D          );
	GL_GetFunc(PFNGLCOPYTEXSUBIMAGE2DPROC                 ,glCopyTexSubImage2D          );
	GL_GetFunc(PFNGLTEXSUBIMAGE1DPROC                     ,glTexSubImage1D              );
	GL_GetFunc(PFNGLTEXSUBIMAGE2DPROC                     ,glTexSubImage2D              );
	GL_GetFunc(PFNGLBINDTEXTUREPROC                       ,glBindTexture                );
	GL_GetFunc(PFNGLDELETETEXTURESPROC                    ,glDeleteTextures             );
	GL_GetFunc(PFNGLGENTEXTURESPROC                       ,glGenTextures                );
	GL_GetFunc(PFNGLISTEXTUREPROC                         ,glIsTexture                  );
    #endif /* __GL_H__ GL_VERSION_1_1 */
    #endif /* __gl_h_ GL_VERSION_1_1 */
    #endif /* GL_VERSION_1_1 */

    #ifdef GL_VERSION_1_2
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_1_2\n");
	GL_GetFunc(PFNGLDRAWRANGEELEMENTSPROC                  ,glDrawRangeElements     );
    GL_GetFunc(PFNGLTEXIMAGE3DPROC                         ,glTexImage3D            );
    GL_GetFunc(PFNGLTEXSUBIMAGE3DPROC                      ,glTexSubImage3D         );
    GL_GetFunc(PFNGLCOPYTEXSUBIMAGE3DPROC                  ,glCopyTexSubImage3D     );
    #endif /* GL_VERSION_1_2 */

    #ifdef GL_VERSION_1_3
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_1_3\n");
    GL_GetFunc(PFNGLACTIVETEXTUREPROC                                  ,glActiveTexture                        );
    GL_GetFunc(PFNGLSAMPLECOVERAGEPROC                                 ,glSampleCoverage                       );
    GL_GetFunc(PFNGLCOMPRESSEDTEXIMAGE3DPROC                           ,glCompressedTexImage3D                 );
    GL_GetFunc(PFNGLCOMPRESSEDTEXIMAGE2DPROC                           ,glCompressedTexImage2D                 );
    GL_GetFunc(PFNGLCOMPRESSEDTEXIMAGE1DPROC                           ,glCompressedTexImage1D                 );
    GL_GetFunc(PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC                        ,glCompressedTexSubImage3D              );
    GL_GetFunc(PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC                        ,glCompressedTexSubImage2D              );
    GL_GetFunc(PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC                        ,glCompressedTexSubImage1D              );
    GL_GetFunc(PFNGLGETCOMPRESSEDTEXIMAGEPROC                          ,glGetCompressedTexImage                );
    GL_GetFunc(PFNGLCLIENTACTIVETEXTUREPROC                            ,glClientActiveTexture                  );
    GL_GetFunc(PFNGLMULTITEXCOORD1DPROC                                ,glMultiTexCoord1d                      );
    GL_GetFunc(PFNGLMULTITEXCOORD1DVPROC                               ,glMultiTexCoord1dv                     );
    GL_GetFunc(PFNGLMULTITEXCOORD1FPROC                                ,glMultiTexCoord1f                      );
    GL_GetFunc(PFNGLMULTITEXCOORD1FVPROC                               ,glMultiTexCoord1fv                     );
    GL_GetFunc(PFNGLMULTITEXCOORD1IPROC                                ,glMultiTexCoord1i                      );
    GL_GetFunc(PFNGLMULTITEXCOORD1IVPROC                               ,glMultiTexCoord1iv                     );
    GL_GetFunc(PFNGLMULTITEXCOORD1SPROC                                ,glMultiTexCoord1s                      );
    GL_GetFunc(PFNGLMULTITEXCOORD1SVPROC                               ,glMultiTexCoord1sv                     );
    GL_GetFunc(PFNGLMULTITEXCOORD2DPROC                                ,glMultiTexCoord2d                      );
    GL_GetFunc(PFNGLMULTITEXCOORD2DVPROC                               ,glMultiTexCoord2dv                     );
    GL_GetFunc(PFNGLMULTITEXCOORD2FPROC                                ,glMultiTexCoord2f                      );
    GL_GetFunc(PFNGLMULTITEXCOORD2FVPROC                               ,glMultiTexCoord2fv                     );
    GL_GetFunc(PFNGLMULTITEXCOORD2IPROC                                ,glMultiTexCoord2i                      );
    GL_GetFunc(PFNGLMULTITEXCOORD2IVPROC                               ,glMultiTexCoord2iv                     );
    GL_GetFunc(PFNGLMULTITEXCOORD2SPROC                                ,glMultiTexCoord2s                      );
    GL_GetFunc(PFNGLMULTITEXCOORD2SVPROC                               ,glMultiTexCoord2sv                     );
    GL_GetFunc(PFNGLMULTITEXCOORD3DPROC                                ,glMultiTexCoord3d                      );
    GL_GetFunc(PFNGLMULTITEXCOORD3DVPROC                               ,glMultiTexCoord3dv                     );
    GL_GetFunc(PFNGLMULTITEXCOORD3FPROC                                ,glMultiTexCoord3f                      );
    GL_GetFunc(PFNGLMULTITEXCOORD3FVPROC                               ,glMultiTexCoord3fv                     );
    GL_GetFunc(PFNGLMULTITEXCOORD3IPROC                                ,glMultiTexCoord3i                      );
    GL_GetFunc(PFNGLMULTITEXCOORD3IVPROC                               ,glMultiTexCoord3iv                     );
    GL_GetFunc(PFNGLMULTITEXCOORD3SPROC                                ,glMultiTexCoord3s                      );
    GL_GetFunc(PFNGLMULTITEXCOORD3SVPROC                               ,glMultiTexCoord3sv                     );
    GL_GetFunc(PFNGLMULTITEXCOORD4DPROC                                ,glMultiTexCoord4d                      );
    GL_GetFunc(PFNGLMULTITEXCOORD4DVPROC                               ,glMultiTexCoord4dv                     );
    GL_GetFunc(PFNGLMULTITEXCOORD4FPROC                                ,glMultiTexCoord4f                      );
    GL_GetFunc(PFNGLMULTITEXCOORD4FVPROC                               ,glMultiTexCoord4fv                     );
    GL_GetFunc(PFNGLMULTITEXCOORD4IPROC                                ,glMultiTexCoord4i                      );
    GL_GetFunc(PFNGLMULTITEXCOORD4IVPROC                               ,glMultiTexCoord4iv                     );
    GL_GetFunc(PFNGLMULTITEXCOORD4SPROC                                ,glMultiTexCoord4s                      );
    GL_GetFunc(PFNGLMULTITEXCOORD4SVPROC                               ,glMultiTexCoord4sv                     );
    GL_GetFunc(PFNGLLOADTRANSPOSEMATRIXFPROC                           ,glLoadTransposeMatrixf                 );
    GL_GetFunc(PFNGLLOADTRANSPOSEMATRIXDPROC                           ,glLoadTransposeMatrixd                 );
    GL_GetFunc(PFNGLMULTTRANSPOSEMATRIXFPROC                           ,glMultTransposeMatrixf                 );
    GL_GetFunc(PFNGLMULTTRANSPOSEMATRIXDPROC                           ,glMultTransposeMatrixd                 );
    #endif /* GL_VERSION_1_3 */

    #ifdef GL_VERSION_1_4
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_1_4\n");
    GL_GetFunc(PFNGLBLENDFUNCSEPARATEPROC                          ,glBlendFuncSeparate                );
    GL_GetFunc(PFNGLMULTIDRAWARRAYSPROC                            ,glMultiDrawArrays                  );
    GL_GetFunc(PFNGLMULTIDRAWELEMENTSPROC                          ,glMultiDrawElements                );
    GL_GetFunc(PFNGLPOINTPARAMETERFPROC                            ,glPointParameterf                  );
    GL_GetFunc(PFNGLPOINTPARAMETERFVPROC                           ,glPointParameterfv                 );
    GL_GetFunc(PFNGLPOINTPARAMETERIPROC                            ,glPointParameteri                  );
    GL_GetFunc(PFNGLPOINTPARAMETERIVPROC                           ,glPointParameteriv                 );
    GL_GetFunc(PFNGLFOGCOORDFPROC                                  ,glFogCoordf                        );
    GL_GetFunc(PFNGLFOGCOORDFVPROC                                 ,glFogCoordfv                       );
    GL_GetFunc(PFNGLFOGCOORDDPROC                                  ,glFogCoordd                        );
    GL_GetFunc(PFNGLFOGCOORDDVPROC                                 ,glFogCoorddv                       );
    GL_GetFunc(PFNGLFOGCOORDPOINTERPROC                            ,glFogCoordPointer                  );
    GL_GetFunc(PFNGLSECONDARYCOLOR3BPROC                           ,glSecondaryColor3b                 );
    GL_GetFunc(PFNGLSECONDARYCOLOR3BVPROC                          ,glSecondaryColor3bv                );
    GL_GetFunc(PFNGLSECONDARYCOLOR3DPROC                           ,glSecondaryColor3d                 );
    GL_GetFunc(PFNGLSECONDARYCOLOR3DVPROC                          ,glSecondaryColor3dv                );
    GL_GetFunc(PFNGLSECONDARYCOLOR3FPROC                           ,glSecondaryColor3f                 );
    GL_GetFunc(PFNGLSECONDARYCOLOR3FVPROC                          ,glSecondaryColor3fv                );
    GL_GetFunc(PFNGLSECONDARYCOLOR3IPROC                           ,glSecondaryColor3i                 );
    GL_GetFunc(PFNGLSECONDARYCOLOR3IVPROC                          ,glSecondaryColor3iv                );
    GL_GetFunc(PFNGLSECONDARYCOLOR3SPROC                           ,glSecondaryColor3s                 );
    GL_GetFunc(PFNGLSECONDARYCOLOR3SVPROC                          ,glSecondaryColor3sv                );
    GL_GetFunc(PFNGLSECONDARYCOLOR3UBPROC                          ,glSecondaryColor3ub                );
    GL_GetFunc(PFNGLSECONDARYCOLOR3UBVPROC                         ,glSecondaryColor3ubv               );
    GL_GetFunc(PFNGLSECONDARYCOLOR3UIPROC                          ,glSecondaryColor3ui                );
    GL_GetFunc(PFNGLSECONDARYCOLOR3UIVPROC                         ,glSecondaryColor3uiv               );
    GL_GetFunc(PFNGLSECONDARYCOLOR3USPROC                          ,glSecondaryColor3us                );
    GL_GetFunc(PFNGLSECONDARYCOLOR3USVPROC                         ,glSecondaryColor3usv               );
    GL_GetFunc(PFNGLSECONDARYCOLORPOINTERPROC                      ,glSecondaryColorPointer            );
    GL_GetFunc(PFNGLWINDOWPOS2DPROC                                ,glWindowPos2d                      );
    GL_GetFunc(PFNGLWINDOWPOS2DVPROC                               ,glWindowPos2dv                     );
    GL_GetFunc(PFNGLWINDOWPOS2FPROC                                ,glWindowPos2f                      );
    GL_GetFunc(PFNGLWINDOWPOS2FVPROC                               ,glWindowPos2fv                     );
    GL_GetFunc(PFNGLWINDOWPOS2IPROC                                ,glWindowPos2i                      );
    GL_GetFunc(PFNGLWINDOWPOS2IVPROC                               ,glWindowPos2iv                     );
    GL_GetFunc(PFNGLWINDOWPOS2SPROC                                ,glWindowPos2s                      );
    GL_GetFunc(PFNGLWINDOWPOS2SVPROC                               ,glWindowPos2sv                     );
    GL_GetFunc(PFNGLWINDOWPOS3DPROC                                ,glWindowPos3d                      );
    GL_GetFunc(PFNGLWINDOWPOS3DVPROC                               ,glWindowPos3dv                     );
    GL_GetFunc(PFNGLWINDOWPOS3FPROC                                ,glWindowPos3f                      );
    GL_GetFunc(PFNGLWINDOWPOS3FVPROC                               ,glWindowPos3fv                     );
    GL_GetFunc(PFNGLWINDOWPOS3IPROC                                ,glWindowPos3i                      );
    GL_GetFunc(PFNGLWINDOWPOS3IVPROC                               ,glWindowPos3iv                     );
    GL_GetFunc(PFNGLWINDOWPOS3SPROC                                ,glWindowPos3s                      );
    GL_GetFunc(PFNGLWINDOWPOS3SVPROC                               ,glWindowPos3sv                     );
    GL_GetFunc(PFNGLBLENDCOLORPROC                                 ,glBlendColor                       );
    GL_GetFunc(PFNGLBLENDEQUATIONPROC                              ,glBlendEquation                    );
    #endif /* GL_VERSION_1_4 */

    #ifdef GL_VERSION_1_5
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_1_5\n");
    GL_GetFunc(PFNGLGENQUERIESPROC                               ,glGenQueries                               );
    GL_GetFunc(PFNGLDELETEQUERIESPROC                            ,glDeleteQueries                            );
    GL_GetFunc(PFNGLISQUERYPROC                                  ,glIsQuery                                  );
    GL_GetFunc(PFNGLBEGINQUERYPROC                               ,glBeginQuery                               );
    GL_GetFunc(PFNGLENDQUERYPROC                                 ,glEndQuery                                 );
    GL_GetFunc(PFNGLGETQUERYIVPROC                               ,glGetQueryiv                               );
    GL_GetFunc(PFNGLGETQUERYOBJECTIVPROC                         ,glGetQueryObjectiv                         );
    GL_GetFunc(PFNGLGETQUERYOBJECTUIVPROC                        ,glGetQueryObjectuiv                        );
    GL_GetFunc(PFNGLBINDBUFFERPROC                               ,glBindBuffer                               );
    GL_GetFunc(PFNGLDELETEBUFFERSPROC                            ,glDeleteBuffers                            );
    GL_GetFunc(PFNGLGENBUFFERSPROC                               ,glGenBuffers                               );
    GL_GetFunc(PFNGLISBUFFERPROC                                 ,glIsBuffer                                 );
    GL_GetFunc(PFNGLBUFFERDATAPROC                               ,glBufferData                               );
    GL_GetFunc(PFNGLBUFFERSUBDATAPROC                            ,glBufferSubData                            );
    GL_GetFunc(PFNGLGETBUFFERSUBDATAPROC                         ,glGetBufferSubData                         );
    GL_GetFunc(PFNGLMAPBUFFERPROC                                ,glMapBuffer                                );
    GL_GetFunc(PFNGLUNMAPBUFFERPROC                              ,glUnmapBuffer                              );
    GL_GetFunc(PFNGLGETBUFFERPARAMETERIVPROC                     ,glGetBufferParameteriv                     );
    GL_GetFunc(PFNGLGETBUFFERPOINTERVPROC                        ,glGetBufferPointerv                        );
    #endif /* GL_VERSION_1_5 */

    #ifdef GL_VERSION_2_0
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_2_0\n");
    GL_GetFunc(PFNGLBLENDEQUATIONSEPARATEPROC                                  ,glBlendEquationSeparate              );
    GL_GetFunc(PFNGLDRAWBUFFERSPROC                                            ,glDrawBuffers                        );
    GL_GetFunc(PFNGLSTENCILOPSEPARATEPROC                                      ,glStencilOpSeparate                  );
    GL_GetFunc(PFNGLSTENCILFUNCSEPARATEPROC                                    ,glStencilFuncSeparate                );
    GL_GetFunc(PFNGLSTENCILMASKSEPARATEPROC                                    ,glStencilMaskSeparate                );
    GL_GetFunc(PFNGLATTACHSHADERPROC                                           ,glAttachShader                       );
    GL_GetFunc(PFNGLBINDATTRIBLOCATIONPROC                                     ,glBindAttribLocation                 );
    GL_GetFunc(PFNGLCOMPILESHADERPROC                                          ,glCompileShader                      );
    GL_GetFunc(PFNGLCREATEPROGRAMPROC                                          ,glCreateProgram                      );
    GL_GetFunc(PFNGLCREATESHADERPROC                                           ,glCreateShader                       );
    GL_GetFunc(PFNGLDELETEPROGRAMPROC                                          ,glDeleteProgram                      );
    GL_GetFunc(PFNGLDELETESHADERPROC                                           ,glDeleteShader                       );
    GL_GetFunc(PFNGLDETACHSHADERPROC                                           ,glDetachShader                       );
    GL_GetFunc(PFNGLDISABLEVERTEXATTRIBARRAYPROC                               ,glDisableVertexAttribArray           );
    GL_GetFunc(PFNGLENABLEVERTEXATTRIBARRAYPROC                                ,glEnableVertexAttribArray            );
    GL_GetFunc(PFNGLGETACTIVEATTRIBPROC                                        ,glGetActiveAttrib                    );
    GL_GetFunc(PFNGLGETACTIVEUNIFORMPROC                                       ,glGetActiveUniform                   );
    GL_GetFunc(PFNGLGETATTACHEDSHADERSPROC                                     ,glGetAttachedShaders                 );
    GL_GetFunc(PFNGLGETATTRIBLOCATIONPROC                                      ,glGetAttribLocation                  );
    GL_GetFunc(PFNGLGETPROGRAMIVPROC                                           ,glGetProgramiv                       );
    GL_GetFunc(PFNGLGETPROGRAMINFOLOGPROC                                      ,glGetProgramInfoLog                  );
    GL_GetFunc(PFNGLGETSHADERIVPROC                                            ,glGetShaderiv                        );
    GL_GetFunc(PFNGLGETSHADERINFOLOGPROC                                       ,glGetShaderInfoLog                   );
    GL_GetFunc(PFNGLGETSHADERSOURCEPROC                                        ,glGetShaderSource                    );
    GL_GetFunc(PFNGLGETUNIFORMLOCATIONPROC                                     ,glGetUniformLocation                 );
    GL_GetFunc(PFNGLGETUNIFORMFVPROC                                           ,glGetUniformfv                       );
    GL_GetFunc(PFNGLGETUNIFORMIVPROC                                           ,glGetUniformiv                       );
    GL_GetFunc(PFNGLGETVERTEXATTRIBDVPROC                                      ,glGetVertexAttribdv                  );
    GL_GetFunc(PFNGLGETVERTEXATTRIBFVPROC                                      ,glGetVertexAttribfv                  );
    GL_GetFunc(PFNGLGETVERTEXATTRIBIVPROC                                      ,glGetVertexAttribiv                  );
    GL_GetFunc(PFNGLGETVERTEXATTRIBPOINTERVPROC                                ,glGetVertexAttribPointerv            );
    GL_GetFunc(PFNGLISPROGRAMPROC                                              ,glIsProgram                          );
    GL_GetFunc(PFNGLISSHADERPROC                                               ,glIsShader                           );
    GL_GetFunc(PFNGLLINKPROGRAMPROC                                            ,glLinkProgram                        );
    GL_GetFunc(PFNGLSHADERSOURCEPROC                                           ,glShaderSource                       );
    GL_GetFunc(PFNGLUSEPROGRAMPROC                                             ,glUseProgram                         );
    GL_GetFunc(PFNGLUNIFORM1FPROC                                              ,glUniform1f                          );
    GL_GetFunc(PFNGLUNIFORM2FPROC                                              ,glUniform2f                          );
    GL_GetFunc(PFNGLUNIFORM3FPROC                                              ,glUniform3f                          );
    GL_GetFunc(PFNGLUNIFORM4FPROC                                              ,glUniform4f                          );
    GL_GetFunc(PFNGLUNIFORM1IPROC                                              ,glUniform1i                          );
    GL_GetFunc(PFNGLUNIFORM2IPROC                                              ,glUniform2i                          );
    GL_GetFunc(PFNGLUNIFORM3IPROC                                              ,glUniform3i                          );
    GL_GetFunc(PFNGLUNIFORM4IPROC                                              ,glUniform4i                          );
    GL_GetFunc(PFNGLUNIFORM1FVPROC                                             ,glUniform1fv                         );
    GL_GetFunc(PFNGLUNIFORM2FVPROC                                             ,glUniform2fv                         );
    GL_GetFunc(PFNGLUNIFORM3FVPROC                                             ,glUniform3fv                         );
    GL_GetFunc(PFNGLUNIFORM4FVPROC                                             ,glUniform4fv                         );
    GL_GetFunc(PFNGLUNIFORM1IVPROC                                             ,glUniform1iv                         );
    GL_GetFunc(PFNGLUNIFORM2IVPROC                                             ,glUniform2iv                         );
    GL_GetFunc(PFNGLUNIFORM3IVPROC                                             ,glUniform3iv                         );
    GL_GetFunc(PFNGLUNIFORM4IVPROC                                             ,glUniform4iv                         );
    GL_GetFunc(PFNGLUNIFORMMATRIX2FVPROC                                       ,glUniformMatrix2fv                   );
    GL_GetFunc(PFNGLUNIFORMMATRIX3FVPROC                                       ,glUniformMatrix3fv                   );
    GL_GetFunc(PFNGLUNIFORMMATRIX4FVPROC                                       ,glUniformMatrix4fv                   );
    GL_GetFunc(PFNGLVALIDATEPROGRAMPROC                                        ,glValidateProgram                    );
    GL_GetFunc(PFNGLVERTEXATTRIB1DPROC                                         ,glVertexAttrib1d                     );
    GL_GetFunc(PFNGLVERTEXATTRIB1DVPROC                                        ,glVertexAttrib1dv                    );
    GL_GetFunc(PFNGLVERTEXATTRIB1FPROC                                         ,glVertexAttrib1f                     );
    GL_GetFunc(PFNGLVERTEXATTRIB1FVPROC                                        ,glVertexAttrib1fv                    );
    GL_GetFunc(PFNGLVERTEXATTRIB1SPROC                                         ,glVertexAttrib1s                     );
    GL_GetFunc(PFNGLVERTEXATTRIB1SVPROC                                        ,glVertexAttrib1sv                    );
    GL_GetFunc(PFNGLVERTEXATTRIB2DPROC                                         ,glVertexAttrib2d                     );
    GL_GetFunc(PFNGLVERTEXATTRIB2DVPROC                                        ,glVertexAttrib2dv                    );
    GL_GetFunc(PFNGLVERTEXATTRIB2FPROC                                         ,glVertexAttrib2f                     );
    GL_GetFunc(PFNGLVERTEXATTRIB2FVPROC                                        ,glVertexAttrib2fv                    );
    GL_GetFunc(PFNGLVERTEXATTRIB2SPROC                                         ,glVertexAttrib2s                     );
    GL_GetFunc(PFNGLVERTEXATTRIB2SVPROC                                        ,glVertexAttrib2sv                    );
    GL_GetFunc(PFNGLVERTEXATTRIB3DPROC                                         ,glVertexAttrib3d                     );
    GL_GetFunc(PFNGLVERTEXATTRIB3DVPROC                                        ,glVertexAttrib3dv                    );
    GL_GetFunc(PFNGLVERTEXATTRIB3FPROC                                         ,glVertexAttrib3f                     );
    GL_GetFunc(PFNGLVERTEXATTRIB3FVPROC                                        ,glVertexAttrib3fv                    );
    GL_GetFunc(PFNGLVERTEXATTRIB3SPROC                                         ,glVertexAttrib3s                     );
    GL_GetFunc(PFNGLVERTEXATTRIB3SVPROC                                        ,glVertexAttrib3sv                    );
    GL_GetFunc(PFNGLVERTEXATTRIB4NBVPROC                                       ,glVertexAttrib4Nbv                   );
    GL_GetFunc(PFNGLVERTEXATTRIB4NIVPROC                                       ,glVertexAttrib4Niv                   );
    GL_GetFunc(PFNGLVERTEXATTRIB4NSVPROC                                       ,glVertexAttrib4Nsv                   );
    GL_GetFunc(PFNGLVERTEXATTRIB4NUBPROC                                       ,glVertexAttrib4Nub                   );
    GL_GetFunc(PFNGLVERTEXATTRIB4NUBVPROC                                      ,glVertexAttrib4Nubv                  );
    GL_GetFunc(PFNGLVERTEXATTRIB4NUIVPROC                                      ,glVertexAttrib4Nuiv                  );
    GL_GetFunc(PFNGLVERTEXATTRIB4NUSVPROC                                      ,glVertexAttrib4Nusv                  );
    GL_GetFunc(PFNGLVERTEXATTRIB4BVPROC                                        ,glVertexAttrib4bv                    );
    GL_GetFunc(PFNGLVERTEXATTRIB4DPROC                                         ,glVertexAttrib4d                     );
    GL_GetFunc(PFNGLVERTEXATTRIB4DVPROC                                        ,glVertexAttrib4dv                    );
    GL_GetFunc(PFNGLVERTEXATTRIB4FPROC                                         ,glVertexAttrib4f                     );
    GL_GetFunc(PFNGLVERTEXATTRIB4FVPROC                                        ,glVertexAttrib4fv                    );
    GL_GetFunc(PFNGLVERTEXATTRIB4IVPROC                                        ,glVertexAttrib4iv                    );
    GL_GetFunc(PFNGLVERTEXATTRIB4SPROC                                         ,glVertexAttrib4s                     );
    GL_GetFunc(PFNGLVERTEXATTRIB4SVPROC                                        ,glVertexAttrib4sv                    );
    GL_GetFunc(PFNGLVERTEXATTRIB4UBVPROC                                       ,glVertexAttrib4ubv                   );
    GL_GetFunc(PFNGLVERTEXATTRIB4UIVPROC                                       ,glVertexAttrib4uiv                   );
    GL_GetFunc(PFNGLVERTEXATTRIB4USVPROC                                       ,glVertexAttrib4usv                   );
    GL_GetFunc(PFNGLVERTEXATTRIBPOINTERPROC                                    ,glVertexAttribPointer                );
    #endif /* GL_VERSION_2_0 */

    #ifdef GL_VERSION_2_1
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_2_1\n");
    GL_GetFunc(PFNGLUNIFORMMATRIX2X3FVPROC                    ,glUniformMatrix2x3fv       );
    GL_GetFunc(PFNGLUNIFORMMATRIX3X2FVPROC                    ,glUniformMatrix3x2fv       );
    GL_GetFunc(PFNGLUNIFORMMATRIX2X4FVPROC                    ,glUniformMatrix2x4fv       );
    GL_GetFunc(PFNGLUNIFORMMATRIX4X2FVPROC                    ,glUniformMatrix4x2fv       );
    GL_GetFunc(PFNGLUNIFORMMATRIX3X4FVPROC                    ,glUniformMatrix3x4fv       );
    GL_GetFunc(PFNGLUNIFORMMATRIX4X3FVPROC                    ,glUniformMatrix4x3fv       );
    #endif /* GL_VERSION_2_1 */

    #ifdef GL_VERSION_3_0
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_3_0\n");
    GL_GetFunc(PFNGLCOLORMASKIPROC                                            ,glColorMaski                                  );
    GL_GetFunc(PFNGLGETBOOLEANI_VPROC                                         ,glGetBooleani_v                               );
    GL_GetFunc(PFNGLGETINTEGERI_VPROC                                         ,glGetIntegeri_v                               );
    GL_GetFunc(PFNGLENABLEIPROC                                               ,glEnablei                                     );
    GL_GetFunc(PFNGLDISABLEIPROC                                              ,glDisablei                                    );
    GL_GetFunc(PFNGLISENABLEDIPROC                                            ,glIsEnabledi                                  );
    GL_GetFunc(PFNGLBEGINTRANSFORMFEEDBACKPROC                                ,glBeginTransformFeedback                      );
    GL_GetFunc(PFNGLENDTRANSFORMFEEDBACKPROC                                  ,glEndTransformFeedback                        );
    GL_GetFunc(PFNGLBINDBUFFERRANGEPROC                                       ,glBindBufferRange                             );
    GL_GetFunc(PFNGLBINDBUFFERBASEPROC                                        ,glBindBufferBase                              );
    GL_GetFunc(PFNGLTRANSFORMFEEDBACKVARYINGSPROC                             ,glTransformFeedbackVaryings                   );
    GL_GetFunc(PFNGLGETTRANSFORMFEEDBACKVARYINGPROC                           ,glGetTransformFeedbackVarying                 );
    GL_GetFunc(PFNGLCLAMPCOLORPROC                                            ,glClampColor                                  );
    GL_GetFunc(PFNGLBEGINCONDITIONALRENDERPROC                                ,glBeginConditionalRender                      );
    GL_GetFunc(PFNGLENDCONDITIONALRENDERPROC                                  ,glEndConditionalRender                        );
    GL_GetFunc(PFNGLVERTEXATTRIBIPOINTERPROC                                  ,glVertexAttribIPointer                        );
    GL_GetFunc(PFNGLGETVERTEXATTRIBIIVPROC                                    ,glGetVertexAttribIiv                          );
    GL_GetFunc(PFNGLGETVERTEXATTRIBIUIVPROC                                   ,glGetVertexAttribIuiv                         );
    GL_GetFunc(PFNGLVERTEXATTRIBI1IPROC                                       ,glVertexAttribI1i                             );
    GL_GetFunc(PFNGLVERTEXATTRIBI2IPROC                                       ,glVertexAttribI2i                             );
    GL_GetFunc(PFNGLVERTEXATTRIBI3IPROC                                       ,glVertexAttribI3i                             );
    GL_GetFunc(PFNGLVERTEXATTRIBI4IPROC                                       ,glVertexAttribI4i                             );
    GL_GetFunc(PFNGLVERTEXATTRIBI1UIPROC                                      ,glVertexAttribI1ui                            );
    GL_GetFunc(PFNGLVERTEXATTRIBI2UIPROC                                      ,glVertexAttribI2ui                            );
    GL_GetFunc(PFNGLVERTEXATTRIBI3UIPROC                                      ,glVertexAttribI3ui                            );
    GL_GetFunc(PFNGLVERTEXATTRIBI4UIPROC                                      ,glVertexAttribI4ui                            );
    GL_GetFunc(PFNGLVERTEXATTRIBI1IVPROC                                      ,glVertexAttribI1iv                            );
    GL_GetFunc(PFNGLVERTEXATTRIBI2IVPROC                                      ,glVertexAttribI2iv                            );
    GL_GetFunc(PFNGLVERTEXATTRIBI3IVPROC                                      ,glVertexAttribI3iv                            );
    GL_GetFunc(PFNGLVERTEXATTRIBI4IVPROC                                      ,glVertexAttribI4iv                            );
    GL_GetFunc(PFNGLVERTEXATTRIBI1UIVPROC                                     ,glVertexAttribI1uiv                           );
    GL_GetFunc(PFNGLVERTEXATTRIBI2UIVPROC                                     ,glVertexAttribI2uiv                           );
    GL_GetFunc(PFNGLVERTEXATTRIBI3UIVPROC                                     ,glVertexAttribI3uiv                           );
    GL_GetFunc(PFNGLVERTEXATTRIBI4UIVPROC                                     ,glVertexAttribI4uiv                           );
    GL_GetFunc(PFNGLVERTEXATTRIBI4BVPROC                                      ,glVertexAttribI4bv                            );
    GL_GetFunc(PFNGLVERTEXATTRIBI4SVPROC                                      ,glVertexAttribI4sv                            );
    GL_GetFunc(PFNGLVERTEXATTRIBI4UBVPROC                                     ,glVertexAttribI4ubv                           );
    GL_GetFunc(PFNGLVERTEXATTRIBI4USVPROC                                     ,glVertexAttribI4usv                           );
    GL_GetFunc(PFNGLGETUNIFORMUIVPROC                                         ,glGetUniformuiv                               );
    GL_GetFunc(PFNGLBINDFRAGDATALOCATIONPROC                                  ,glBindFragDataLocation                        );
    GL_GetFunc(PFNGLGETFRAGDATALOCATIONPROC                                   ,glGetFragDataLocation                         );
    GL_GetFunc(PFNGLUNIFORM1UIPROC                                            ,glUniform1ui                                  );
    GL_GetFunc(PFNGLUNIFORM2UIPROC                                            ,glUniform2ui                                  );
    GL_GetFunc(PFNGLUNIFORM3UIPROC                                            ,glUniform3ui                                  );
    GL_GetFunc(PFNGLUNIFORM4UIPROC                                            ,glUniform4ui                                  );
    GL_GetFunc(PFNGLUNIFORM1UIVPROC                                           ,glUniform1uiv                                 );
    GL_GetFunc(PFNGLUNIFORM2UIVPROC                                           ,glUniform2uiv                                 );
    GL_GetFunc(PFNGLUNIFORM3UIVPROC                                           ,glUniform3uiv                                 );
    GL_GetFunc(PFNGLUNIFORM4UIVPROC                                           ,glUniform4uiv                                 );
    GL_GetFunc(PFNGLTEXPARAMETERIIVPROC                                       ,glTexParameterIiv                             );
    GL_GetFunc(PFNGLTEXPARAMETERIUIVPROC                                      ,glTexParameterIuiv                            );
    GL_GetFunc(PFNGLGETTEXPARAMETERIIVPROC                                    ,glGetTexParameterIiv                          );
    GL_GetFunc(PFNGLGETTEXPARAMETERIUIVPROC                                   ,glGetTexParameterIuiv                         );
    GL_GetFunc(PFNGLCLEARBUFFERIVPROC                                         ,glClearBufferiv                               );
    GL_GetFunc(PFNGLCLEARBUFFERUIVPROC                                        ,glClearBufferuiv                              );
    GL_GetFunc(PFNGLCLEARBUFFERFVPROC                                         ,glClearBufferfv                               );
    GL_GetFunc(PFNGLCLEARBUFFERFIPROC                                         ,glClearBufferfi                               );
    GL_GetFunc(PFNGLGETSTRINGIPROC                                            ,glGetStringi                                  );
    GL_GetFunc(PFNGLISRENDERBUFFERPROC                                        ,glIsRenderbuffer                              );
    GL_GetFunc(PFNGLBINDRENDERBUFFERPROC                                      ,glBindRenderbuffer                            );
    GL_GetFunc(PFNGLDELETERENDERBUFFERSPROC                                   ,glDeleteRenderbuffers                         );
    GL_GetFunc(PFNGLGENRENDERBUFFERSPROC                                      ,glGenRenderbuffers                            );
    GL_GetFunc(PFNGLRENDERBUFFERSTORAGEPROC                                   ,glRenderbufferStorage                         );
    GL_GetFunc(PFNGLGETRENDERBUFFERPARAMETERIVPROC                            ,glGetRenderbufferParameteriv                  );
    GL_GetFunc(PFNGLISFRAMEBUFFERPROC                                         ,glIsFramebuffer                               );
    GL_GetFunc(PFNGLBINDFRAMEBUFFERPROC                                       ,glBindFramebuffer                             );
    GL_GetFunc(PFNGLDELETEFRAMEBUFFERSPROC                                    ,glDeleteFramebuffers                          );
    GL_GetFunc(PFNGLGENFRAMEBUFFERSPROC                                       ,glGenFramebuffers                             );
    GL_GetFunc(PFNGLCHECKFRAMEBUFFERSTATUSPROC                                ,glCheckFramebufferStatus                      );
    GL_GetFunc(PFNGLFRAMEBUFFERTEXTURE1DPROC                                  ,glFramebufferTexture1D                        );
    GL_GetFunc(PFNGLFRAMEBUFFERTEXTURE2DPROC                                  ,glFramebufferTexture2D                        );
    GL_GetFunc(PFNGLFRAMEBUFFERTEXTURE3DPROC                                  ,glFramebufferTexture3D                        );
    GL_GetFunc(PFNGLFRAMEBUFFERRENDERBUFFERPROC                               ,glFramebufferRenderbuffer                     );
    GL_GetFunc(PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC                   ,glGetFramebufferAttachmentParameteriv         );
    GL_GetFunc(PFNGLGENERATEMIPMAPPROC                                        ,glGenerateMipmap                              );
    GL_GetFunc(PFNGLBLITFRAMEBUFFERPROC                                       ,glBlitFramebuffer                             );
    GL_GetFunc(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC                        ,glRenderbufferStorageMultisample              );
    GL_GetFunc(PFNGLFRAMEBUFFERTEXTURELAYERPROC                               ,glFramebufferTextureLayer                     );
    GL_GetFunc(PFNGLMAPBUFFERRANGEPROC                                        ,glMapBufferRange                              );
    GL_GetFunc(PFNGLFLUSHMAPPEDBUFFERRANGEPROC                                ,glFlushMappedBufferRange                      );
    GL_GetFunc(PFNGLBINDVERTEXARRAYPROC                                       ,glBindVertexArray                             );
    GL_GetFunc(PFNGLDELETEVERTEXARRAYSPROC                                    ,glDeleteVertexArrays                          );
    GL_GetFunc(PFNGLGENVERTEXARRAYSPROC                                       ,glGenVertexArrays                             );
    GL_GetFunc(PFNGLISVERTEXARRAYPROC                                         ,glIsVertexArray                               );
    #endif /* GL_VERSION_3_0 */

    #ifdef GL_VERSION_3_1
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_3_1\n");
    GL_GetFunc(PFNGLDRAWARRAYSINSTANCEDPROC                              ,glDrawArraysInstanced                  );
    GL_GetFunc(PFNGLDRAWELEMENTSINSTANCEDPROC                            ,glDrawElementsInstanced                );
    GL_GetFunc(PFNGLTEXBUFFERPROC                                        ,glTexBuffer                            );
    GL_GetFunc(PFNGLPRIMITIVERESTARTINDEXPROC                            ,glPrimitiveRestartIndex                );
    GL_GetFunc(PFNGLCOPYBUFFERSUBDATAPROC                                ,glCopyBufferSubData                    );
    GL_GetFunc(PFNGLGETUNIFORMINDICESPROC                                ,glGetUniformIndices                    );
    GL_GetFunc(PFNGLGETACTIVEUNIFORMSIVPROC                              ,glGetActiveUniformsiv                  );
    GL_GetFunc(PFNGLGETACTIVEUNIFORMNAMEPROC                             ,glGetActiveUniformName                 );
    GL_GetFunc(PFNGLGETUNIFORMBLOCKINDEXPROC                             ,glGetUniformBlockIndex                 );
    GL_GetFunc(PFNGLGETACTIVEUNIFORMBLOCKIVPROC                          ,glGetActiveUniformBlockiv              );
    GL_GetFunc(PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC                        ,glGetActiveUniformBlockName            );
    GL_GetFunc(PFNGLUNIFORMBLOCKBINDINGPROC                              ,glUniformBlockBinding                  );
    #endif /* GL_VERSION_3_1 */

    #ifdef GL_VERSION_3_2
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_3_2\n");
    GL_GetFunc(PFNGLDRAWELEMENTSBASEVERTEXPROC                                  ,glDrawElementsBaseVertex                      );
    GL_GetFunc(PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC                             ,glDrawRangeElementsBaseVertex                 );
    GL_GetFunc(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC                         ,glDrawElementsInstancedBaseVertex             );
    GL_GetFunc(PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC                             ,glMultiDrawElementsBaseVertex                 );
    GL_GetFunc(PFNGLPROVOKINGVERTEXPROC                                         ,glProvokingVertex                             );
    GL_GetFunc(PFNGLFENCESYNCPROC                                               ,glFenceSync                                   );
    GL_GetFunc(PFNGLISSYNCPROC                                                  ,glIsSync                                      );
    GL_GetFunc(PFNGLDELETESYNCPROC                                              ,glDeleteSync                                  );
    GL_GetFunc(PFNGLCLIENTWAITSYNCPROC                                          ,glClientWaitSync                              );
    GL_GetFunc(PFNGLWAITSYNCPROC                                                ,glWaitSync                                    );
    GL_GetFunc(PFNGLGETINTEGER64VPROC                                           ,glGetInteger64v                               );
    GL_GetFunc(PFNGLGETSYNCIVPROC                                               ,glGetSynciv                                   );
    GL_GetFunc(PFNGLGETINTEGER64I_VPROC                                         ,glGetInteger64i_v                             );
    GL_GetFunc(PFNGLGETBUFFERPARAMETERI64VPROC                                  ,glGetBufferParameteri64v                      );
    GL_GetFunc(PFNGLFRAMEBUFFERTEXTUREPROC                                      ,glFramebufferTexture                          );
    GL_GetFunc(PFNGLTEXIMAGE2DMULTISAMPLEPROC                                   ,glTexImage2DMultisample                       );
    GL_GetFunc(PFNGLTEXIMAGE3DMULTISAMPLEPROC                                   ,glTexImage3DMultisample                       );
    GL_GetFunc(PFNGLGETMULTISAMPLEFVPROC                                        ,glGetMultisamplefv                            );
    GL_GetFunc(PFNGLSAMPLEMASKIPROC                                             ,glSampleMaski                                 );
    #endif /* GL_VERSION_3_2 */

    #ifdef GL_VERSION_3_3
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_3_3\n");
    GL_GetFunc(PFNGLBINDFRAGDATALOCATIONINDEXEDPROC                          ,glBindFragDataLocationIndexed           );
    GL_GetFunc(PFNGLGETFRAGDATAINDEXPROC                                     ,glGetFragDataIndex                      );
    GL_GetFunc(PFNGLGENSAMPLERSPROC                                          ,glGenSamplers                           );
    GL_GetFunc(PFNGLDELETESAMPLERSPROC                                       ,glDeleteSamplers                        );
    GL_GetFunc(PFNGLISSAMPLERPROC                                            ,glIsSampler                             );
    GL_GetFunc(PFNGLBINDSAMPLERPROC                                          ,glBindSampler                           );
    GL_GetFunc(PFNGLSAMPLERPARAMETERIPROC                                    ,glSamplerParameteri                     );
    GL_GetFunc(PFNGLSAMPLERPARAMETERIVPROC                                   ,glSamplerParameteriv                    );
    GL_GetFunc(PFNGLSAMPLERPARAMETERFPROC                                    ,glSamplerParameterf                     );
    GL_GetFunc(PFNGLSAMPLERPARAMETERFVPROC                                   ,glSamplerParameterfv                    );
    GL_GetFunc(PFNGLSAMPLERPARAMETERIIVPROC                                  ,glSamplerParameterIiv                   );
    GL_GetFunc(PFNGLSAMPLERPARAMETERIUIVPROC                                 ,glSamplerParameterIuiv                  );
    GL_GetFunc(PFNGLGETSAMPLERPARAMETERIVPROC                                ,glGetSamplerParameteriv                 );
    GL_GetFunc(PFNGLGETSAMPLERPARAMETERIIVPROC                               ,glGetSamplerParameterIiv                );
    GL_GetFunc(PFNGLGETSAMPLERPARAMETERFVPROC                                ,glGetSamplerParameterfv                 );
    GL_GetFunc(PFNGLGETSAMPLERPARAMETERIUIVPROC                              ,glGetSamplerParameterIuiv               );
    GL_GetFunc(PFNGLQUERYCOUNTERPROC                                         ,glQueryCounter                          );
    GL_GetFunc(PFNGLGETQUERYOBJECTI64VPROC                                   ,glGetQueryObjecti64v                    );
    GL_GetFunc(PFNGLGETQUERYOBJECTUI64VPROC                                  ,glGetQueryObjectui64v                   );
    GL_GetFunc(PFNGLVERTEXATTRIBDIVISORPROC                                  ,glVertexAttribDivisor                   );
    GL_GetFunc(PFNGLVERTEXATTRIBP1UIPROC                                     ,glVertexAttribP1ui                      );
    GL_GetFunc(PFNGLVERTEXATTRIBP1UIVPROC                                    ,glVertexAttribP1uiv                     );
    GL_GetFunc(PFNGLVERTEXATTRIBP2UIPROC                                     ,glVertexAttribP2ui                      );
    GL_GetFunc(PFNGLVERTEXATTRIBP2UIVPROC                                    ,glVertexAttribP2uiv                     );
    GL_GetFunc(PFNGLVERTEXATTRIBP3UIPROC                                     ,glVertexAttribP3ui                      );
    GL_GetFunc(PFNGLVERTEXATTRIBP3UIVPROC                                    ,glVertexAttribP3uiv                     );
    GL_GetFunc(PFNGLVERTEXATTRIBP4UIPROC                                     ,glVertexAttribP4ui                      );
    GL_GetFunc(PFNGLVERTEXATTRIBP4UIVPROC                                    ,glVertexAttribP4uiv                     );
    GL_GetFunc(PFNGLVERTEXP2UIPROC                                           ,glVertexP2ui                            );
    GL_GetFunc(PFNGLVERTEXP2UIVPROC                                          ,glVertexP2uiv                           );
    GL_GetFunc(PFNGLVERTEXP3UIPROC                                           ,glVertexP3ui                            );
    GL_GetFunc(PFNGLVERTEXP3UIVPROC                                          ,glVertexP3uiv                           );
    GL_GetFunc(PFNGLVERTEXP4UIPROC                                           ,glVertexP4ui                            );
    GL_GetFunc(PFNGLVERTEXP4UIVPROC                                          ,glVertexP4uiv                           );
    GL_GetFunc(PFNGLTEXCOORDP1UIPROC                                         ,glTexCoordP1ui                          );
    GL_GetFunc(PFNGLTEXCOORDP1UIVPROC                                        ,glTexCoordP1uiv                         );
    GL_GetFunc(PFNGLTEXCOORDP2UIPROC                                         ,glTexCoordP2ui                          );
    GL_GetFunc(PFNGLTEXCOORDP2UIVPROC                                        ,glTexCoordP2uiv                         );
    GL_GetFunc(PFNGLTEXCOORDP3UIPROC                                         ,glTexCoordP3ui                          );
    GL_GetFunc(PFNGLTEXCOORDP3UIVPROC                                        ,glTexCoordP3uiv                         );
    GL_GetFunc(PFNGLTEXCOORDP4UIPROC                                         ,glTexCoordP4ui                          );
    GL_GetFunc(PFNGLTEXCOORDP4UIVPROC                                        ,glTexCoordP4uiv                         );
    GL_GetFunc(PFNGLMULTITEXCOORDP1UIPROC                                    ,glMultiTexCoordP1ui                     );
    GL_GetFunc(PFNGLMULTITEXCOORDP1UIVPROC                                   ,glMultiTexCoordP1uiv                    );
    GL_GetFunc(PFNGLMULTITEXCOORDP2UIPROC                                    ,glMultiTexCoordP2ui                     );
    GL_GetFunc(PFNGLMULTITEXCOORDP2UIVPROC                                   ,glMultiTexCoordP2uiv                    );
    GL_GetFunc(PFNGLMULTITEXCOORDP3UIPROC                                    ,glMultiTexCoordP3ui                     );
    GL_GetFunc(PFNGLMULTITEXCOORDP3UIVPROC                                   ,glMultiTexCoordP3uiv                    );
    GL_GetFunc(PFNGLMULTITEXCOORDP4UIPROC                                    ,glMultiTexCoordP4ui                     );
    GL_GetFunc(PFNGLMULTITEXCOORDP4UIVPROC                                   ,glMultiTexCoordP4uiv                    );
    GL_GetFunc(PFNGLNORMALP3UIPROC                                           ,glNormalP3ui                            );
    GL_GetFunc(PFNGLNORMALP3UIVPROC                                          ,glNormalP3uiv                           );
    GL_GetFunc(PFNGLCOLORP3UIPROC                                            ,glColorP3ui                             );
    GL_GetFunc(PFNGLCOLORP3UIVPROC                                           ,glColorP3uiv                            );
    GL_GetFunc(PFNGLCOLORP4UIPROC                                            ,glColorP4ui                             );
    GL_GetFunc(PFNGLCOLORP4UIVPROC                                           ,glColorP4uiv                            );
    GL_GetFunc(PFNGLSECONDARYCOLORP3UIPROC                                   ,glSecondaryColorP3ui                    );
    GL_GetFunc(PFNGLSECONDARYCOLORP3UIVPROC                                  ,glSecondaryColorP3uiv                   );
    #endif /* GL_VERSION_3_3 */

    #ifdef GL_VERSION_4_0
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_4_0\n");
    GL_GetFunc(PFNGLMINSAMPLESHADINGPROC                                   ,glMinSampleShading                             );
    GL_GetFunc(PFNGLBLENDEQUATIONIPROC                                     ,glBlendEquationi                               );
    GL_GetFunc(PFNGLBLENDEQUATIONSEPARATEIPROC                             ,glBlendEquationSeparatei                       );
    GL_GetFunc(PFNGLBLENDFUNCIPROC                                         ,glBlendFunci                                   );
    GL_GetFunc(PFNGLBLENDFUNCSEPARATEIPROC                                 ,glBlendFuncSeparatei                           );
    GL_GetFunc(PFNGLDRAWARRAYSINDIRECTPROC                                 ,glDrawArraysIndirect                           );
    GL_GetFunc(PFNGLDRAWELEMENTSINDIRECTPROC                               ,glDrawElementsIndirect                         );
    GL_GetFunc(PFNGLUNIFORM1DPROC                                          ,glUniform1d                                    );
    GL_GetFunc(PFNGLUNIFORM2DPROC                                          ,glUniform2d                                    );
    GL_GetFunc(PFNGLUNIFORM3DPROC                                          ,glUniform3d                                    );
    GL_GetFunc(PFNGLUNIFORM4DPROC                                          ,glUniform4d                                    );
    GL_GetFunc(PFNGLUNIFORM1DVPROC                                         ,glUniform1dv                                   );
    GL_GetFunc(PFNGLUNIFORM2DVPROC                                         ,glUniform2dv                                   );
    GL_GetFunc(PFNGLUNIFORM3DVPROC                                         ,glUniform3dv                                   );
    GL_GetFunc(PFNGLUNIFORM4DVPROC                                         ,glUniform4dv                                   );
    GL_GetFunc(PFNGLUNIFORMMATRIX2DVPROC                                   ,glUniformMatrix2dv                             );
    GL_GetFunc(PFNGLUNIFORMMATRIX3DVPROC                                   ,glUniformMatrix3dv                             );
    GL_GetFunc(PFNGLUNIFORMMATRIX4DVPROC                                   ,glUniformMatrix4dv                             );
    GL_GetFunc(PFNGLUNIFORMMATRIX2X3DVPROC                                 ,glUniformMatrix2x3dv                           );
    GL_GetFunc(PFNGLUNIFORMMATRIX2X4DVPROC                                 ,glUniformMatrix2x4dv                           );
    GL_GetFunc(PFNGLUNIFORMMATRIX3X2DVPROC                                 ,glUniformMatrix3x2dv                           );
    GL_GetFunc(PFNGLUNIFORMMATRIX3X4DVPROC                                 ,glUniformMatrix3x4dv                           );
    GL_GetFunc(PFNGLUNIFORMMATRIX4X2DVPROC                                 ,glUniformMatrix4x2dv                           );
    GL_GetFunc(PFNGLUNIFORMMATRIX4X3DVPROC                                 ,glUniformMatrix4x3dv                           );
    GL_GetFunc(PFNGLGETUNIFORMDVPROC                                       ,glGetUniformdv                                 );
    GL_GetFunc(PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC                       ,glGetSubroutineUniformLocation                 );
    GL_GetFunc(PFNGLGETSUBROUTINEINDEXPROC                                 ,glGetSubroutineIndex                           );
    GL_GetFunc(PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC                       ,glGetActiveSubroutineUniformiv                 );
    GL_GetFunc(PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC                     ,glGetActiveSubroutineUniformName               );
    GL_GetFunc(PFNGLGETACTIVESUBROUTINENAMEPROC                            ,glGetActiveSubroutineName                      );
    GL_GetFunc(PFNGLUNIFORMSUBROUTINESUIVPROC                              ,glUniformSubroutinesuiv                        );
    GL_GetFunc(PFNGLGETUNIFORMSUBROUTINEUIVPROC                            ,glGetUniformSubroutineuiv                      );
    GL_GetFunc(PFNGLGETPROGRAMSTAGEIVPROC                                  ,glGetProgramStageiv                            );
    GL_GetFunc(PFNGLPATCHPARAMETERIPROC                                    ,glPatchParameteri                              );
    GL_GetFunc(PFNGLPATCHPARAMETERFVPROC                                   ,glPatchParameterfv                             );
    GL_GetFunc(PFNGLBINDTRANSFORMFEEDBACKPROC                              ,glBindTransformFeedback                        );
    GL_GetFunc(PFNGLDELETETRANSFORMFEEDBACKSPROC                           ,glDeleteTransformFeedbacks                     );
    GL_GetFunc(PFNGLGENTRANSFORMFEEDBACKSPROC                              ,glGenTransformFeedbacks                        );
    GL_GetFunc(PFNGLISTRANSFORMFEEDBACKPROC                                ,glIsTransformFeedback                          );
    GL_GetFunc(PFNGLPAUSETRANSFORMFEEDBACKPROC                             ,glPauseTransformFeedback                       );
    GL_GetFunc(PFNGLRESUMETRANSFORMFEEDBACKPROC                            ,glResumeTransformFeedback                      );
    GL_GetFunc(PFNGLDRAWTRANSFORMFEEDBACKPROC                              ,glDrawTransformFeedback                        );
    GL_GetFunc(PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC                        ,glDrawTransformFeedbackStream                  );
    GL_GetFunc(PFNGLBEGINQUERYINDEXEDPROC                                  ,glBeginQueryIndexed                            );
    GL_GetFunc(PFNGLENDQUERYINDEXEDPROC                                    ,glEndQueryIndexed                              );
    GL_GetFunc(PFNGLGETQUERYINDEXEDIVPROC                                  ,glGetQueryIndexediv                            );
    #endif /* GL_VERSION_4_0 */

    #ifdef GL_VERSION_4_1
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_4_1\n");
    GL_GetFunc(PFNGLRELEASESHADERCOMPILERPROC                                   ,glReleaseShaderCompiler                   );
    GL_GetFunc(PFNGLSHADERBINARYPROC                                            ,glShaderBinary                            );
    GL_GetFunc(PFNGLGETSHADERPRECISIONFORMATPROC                                ,glGetShaderPrecisionFormat                );
    GL_GetFunc(PFNGLDEPTHRANGEFPROC                                             ,glDepthRangef                             );
    GL_GetFunc(PFNGLCLEARDEPTHFPROC                                             ,glClearDepthf                             );
    GL_GetFunc(PFNGLGETPROGRAMBINARYPROC                                        ,glGetProgramBinary                        );
    GL_GetFunc(PFNGLPROGRAMBINARYPROC                                           ,glProgramBinary                           );
    GL_GetFunc(PFNGLPROGRAMPARAMETERIPROC                                       ,glProgramParameteri                       );
    GL_GetFunc(PFNGLUSEPROGRAMSTAGESPROC                                        ,glUseProgramStages                        );
    GL_GetFunc(PFNGLACTIVESHADERPROGRAMPROC                                     ,glActiveShaderProgram                     );
    GL_GetFunc(PFNGLCREATESHADERPROGRAMVPROC                                    ,glCreateShaderProgramv                    );
    GL_GetFunc(PFNGLBINDPROGRAMPIPELINEPROC                                     ,glBindProgramPipeline                     );
    GL_GetFunc(PFNGLDELETEPROGRAMPIPELINESPROC                                  ,glDeleteProgramPipelines                  );
    GL_GetFunc(PFNGLGENPROGRAMPIPELINESPROC                                     ,glGenProgramPipelines                     );
    GL_GetFunc(PFNGLISPROGRAMPIPELINEPROC                                       ,glIsProgramPipeline                       );
    GL_GetFunc(PFNGLGETPROGRAMPIPELINEIVPROC                                    ,glGetProgramPipelineiv                    );
    GL_GetFunc(PFNGLPROGRAMUNIFORM1IPROC                                        ,glProgramUniform1i                        );
    GL_GetFunc(PFNGLPROGRAMUNIFORM1IVPROC                                       ,glProgramUniform1iv                       );
    GL_GetFunc(PFNGLPROGRAMUNIFORM1FPROC                                        ,glProgramUniform1f                        );
    GL_GetFunc(PFNGLPROGRAMUNIFORM1FVPROC                                       ,glProgramUniform1fv                       );
    GL_GetFunc(PFNGLPROGRAMUNIFORM1DPROC                                        ,glProgramUniform1d                        );
    GL_GetFunc(PFNGLPROGRAMUNIFORM1DVPROC                                       ,glProgramUniform1dv                       );
    GL_GetFunc(PFNGLPROGRAMUNIFORM1UIPROC                                       ,glProgramUniform1ui                       );
    GL_GetFunc(PFNGLPROGRAMUNIFORM1UIVPROC                                      ,glProgramUniform1uiv                      );
    GL_GetFunc(PFNGLPROGRAMUNIFORM2IPROC                                        ,glProgramUniform2i                        );
    GL_GetFunc(PFNGLPROGRAMUNIFORM2IVPROC                                       ,glProgramUniform2iv                       );
    GL_GetFunc(PFNGLPROGRAMUNIFORM2FPROC                                        ,glProgramUniform2f                        );
    GL_GetFunc(PFNGLPROGRAMUNIFORM2FVPROC                                       ,glProgramUniform2fv                       );
    GL_GetFunc(PFNGLPROGRAMUNIFORM2DPROC                                        ,glProgramUniform2d                        );
    GL_GetFunc(PFNGLPROGRAMUNIFORM2DVPROC                                       ,glProgramUniform2dv                       );
    GL_GetFunc(PFNGLPROGRAMUNIFORM2UIPROC                                       ,glProgramUniform2ui                       );
    GL_GetFunc(PFNGLPROGRAMUNIFORM2UIVPROC                                      ,glProgramUniform2uiv                      );
    GL_GetFunc(PFNGLPROGRAMUNIFORM3IPROC                                        ,glProgramUniform3i                        );
    GL_GetFunc(PFNGLPROGRAMUNIFORM3IVPROC                                       ,glProgramUniform3iv                       );
    GL_GetFunc(PFNGLPROGRAMUNIFORM3FPROC                                        ,glProgramUniform3f                        );
    GL_GetFunc(PFNGLPROGRAMUNIFORM3FVPROC                                       ,glProgramUniform3fv                       );
    GL_GetFunc(PFNGLPROGRAMUNIFORM3DPROC                                        ,glProgramUniform3d                        );
    GL_GetFunc(PFNGLPROGRAMUNIFORM3DVPROC                                       ,glProgramUniform3dv                       );
    GL_GetFunc(PFNGLPROGRAMUNIFORM3UIPROC                                       ,glProgramUniform3ui                       );
    GL_GetFunc(PFNGLPROGRAMUNIFORM3UIVPROC                                      ,glProgramUniform3uiv                      );
    GL_GetFunc(PFNGLPROGRAMUNIFORM4IPROC                                        ,glProgramUniform4i                        );
    GL_GetFunc(PFNGLPROGRAMUNIFORM4IVPROC                                       ,glProgramUniform4iv                       );
    GL_GetFunc(PFNGLPROGRAMUNIFORM4FPROC                                        ,glProgramUniform4f                        );
    GL_GetFunc(PFNGLPROGRAMUNIFORM4FVPROC                                       ,glProgramUniform4fv                       );
    GL_GetFunc(PFNGLPROGRAMUNIFORM4DPROC                                        ,glProgramUniform4d                        );
    GL_GetFunc(PFNGLPROGRAMUNIFORM4DVPROC                                       ,glProgramUniform4dv                       );
    GL_GetFunc(PFNGLPROGRAMUNIFORM4UIPROC                                       ,glProgramUniform4ui                       );
    GL_GetFunc(PFNGLPROGRAMUNIFORM4UIVPROC                                      ,glProgramUniform4uiv                      );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX2FVPROC                                 ,glProgramUniformMatrix2fv                 );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX3FVPROC                                 ,glProgramUniformMatrix3fv                 );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX4FVPROC                                 ,glProgramUniformMatrix4fv                 );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX2DVPROC                                 ,glProgramUniformMatrix2dv                 );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX3DVPROC                                 ,glProgramUniformMatrix3dv                 );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX4DVPROC                                 ,glProgramUniformMatrix4dv                 );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC                               ,glProgramUniformMatrix2x3fv               );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC                               ,glProgramUniformMatrix3x2fv               );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC                               ,glProgramUniformMatrix2x4fv               );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC                               ,glProgramUniformMatrix4x2fv               );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC                               ,glProgramUniformMatrix3x4fv               );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC                               ,glProgramUniformMatrix4x3fv               );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC                               ,glProgramUniformMatrix2x3dv               );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC                               ,glProgramUniformMatrix3x2dv               );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC                               ,glProgramUniformMatrix2x4dv               );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC                               ,glProgramUniformMatrix4x2dv               );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC                               ,glProgramUniformMatrix3x4dv               );
    GL_GetFunc(PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC                               ,glProgramUniformMatrix4x3dv               );
    GL_GetFunc(PFNGLVALIDATEPROGRAMPIPELINEPROC                                 ,glValidateProgramPipeline                 );
    GL_GetFunc(PFNGLGETPROGRAMPIPELINEINFOLOGPROC                               ,glGetProgramPipelineInfoLog               );
    GL_GetFunc(PFNGLVERTEXATTRIBL1DPROC                                         ,glVertexAttribL1d                         );
    GL_GetFunc(PFNGLVERTEXATTRIBL2DPROC                                         ,glVertexAttribL2d                         );
    GL_GetFunc(PFNGLVERTEXATTRIBL3DPROC                                         ,glVertexAttribL3d                         );
    GL_GetFunc(PFNGLVERTEXATTRIBL4DPROC                                         ,glVertexAttribL4d                         );
    GL_GetFunc(PFNGLVERTEXATTRIBL1DVPROC                                        ,glVertexAttribL1dv                        );
    GL_GetFunc(PFNGLVERTEXATTRIBL2DVPROC                                        ,glVertexAttribL2dv                        );
    GL_GetFunc(PFNGLVERTEXATTRIBL3DVPROC                                        ,glVertexAttribL3dv                        );
    GL_GetFunc(PFNGLVERTEXATTRIBL4DVPROC                                        ,glVertexAttribL4dv                        );
    GL_GetFunc(PFNGLVERTEXATTRIBLPOINTERPROC                                    ,glVertexAttribLPointer                    );
    GL_GetFunc(PFNGLGETVERTEXATTRIBLDVPROC                                      ,glGetVertexAttribLdv                      );
    GL_GetFunc(PFNGLVIEWPORTARRAYVPROC                                          ,glViewportArrayv                          );
    GL_GetFunc(PFNGLVIEWPORTINDEXEDFPROC                                        ,glViewportIndexedf                        );
    GL_GetFunc(PFNGLVIEWPORTINDEXEDFVPROC                                       ,glViewportIndexedfv                       );
    GL_GetFunc(PFNGLSCISSORARRAYVPROC                                           ,glScissorArrayv                           );
    GL_GetFunc(PFNGLSCISSORINDEXEDPROC                                          ,glScissorIndexed                          );
    GL_GetFunc(PFNGLSCISSORINDEXEDVPROC                                         ,glScissorIndexedv                         );
    GL_GetFunc(PFNGLDEPTHRANGEARRAYVPROC                                        ,glDepthRangeArrayv                        );
    GL_GetFunc(PFNGLDEPTHRANGEINDEXEDPROC                                       ,glDepthRangeIndexed                       );
    GL_GetFunc(PFNGLGETFLOATI_VPROC                                             ,glGetFloati_v                             );
    GL_GetFunc(PFNGLGETDOUBLEI_VPROC                                            ,glGetDoublei_v                            );
    #endif /* GL_VERSION_4_1 */

    #ifdef GL_VERSION_4_2
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_4_2\n");
    GL_GetFunc(PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC                             ,glDrawArraysInstancedBaseInstance                 );
    GL_GetFunc(PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC                           ,glDrawElementsInstancedBaseInstance               );
    GL_GetFunc(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC                 ,glDrawElementsInstancedBaseVertexBaseInstance     );
    GL_GetFunc(PFNGLGETINTERNALFORMATIVPROC                                         ,glGetInternalformativ                             );
    GL_GetFunc(PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC                              ,glGetActiveAtomicCounterBufferiv                  );
    GL_GetFunc(PFNGLBINDIMAGETEXTUREPROC                                            ,glBindImageTexture                                );
    GL_GetFunc(PFNGLMEMORYBARRIERPROC                                               ,glMemoryBarrier                                   );
    GL_GetFunc(PFNGLTEXSTORAGE1DPROC                                                ,glTexStorage1D                                    );
    GL_GetFunc(PFNGLTEXSTORAGE2DPROC                                                ,glTexStorage2D                                    );
    GL_GetFunc(PFNGLTEXSTORAGE3DPROC                                                ,glTexStorage3D                                    );
    GL_GetFunc(PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC                              ,glDrawTransformFeedbackInstanced                  );
    GL_GetFunc(PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC                        ,glDrawTransformFeedbackStreamInstanced            );
    #endif /* GL_VERSION_4_2 */

    #ifdef GL_VERSION_4_3
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_4_3\n");
    GL_GetFunc(PFNGLCLEARBUFFERDATAPROC                                        ,glClearBufferData                             );
    GL_GetFunc(PFNGLCLEARBUFFERSUBDATAPROC                                     ,glClearBufferSubData                          );
    GL_GetFunc(PFNGLDISPATCHCOMPUTEPROC                                        ,glDispatchCompute                             );
    GL_GetFunc(PFNGLDISPATCHCOMPUTEINDIRECTPROC                                ,glDispatchComputeIndirect                     );
    GL_GetFunc(PFNGLCOPYIMAGESUBDATAPROC                                       ,glCopyImageSubData                            );
    GL_GetFunc(PFNGLFRAMEBUFFERPARAMETERIPROC                                  ,glFramebufferParameteri                       );
    GL_GetFunc(PFNGLGETFRAMEBUFFERPARAMETERIVPROC                              ,glGetFramebufferParameteriv                   );
    GL_GetFunc(PFNGLGETINTERNALFORMATI64VPROC                                  ,glGetInternalformati64v                       );
    GL_GetFunc(PFNGLINVALIDATETEXSUBIMAGEPROC                                  ,glInvalidateTexSubImage                       );
    GL_GetFunc(PFNGLINVALIDATETEXIMAGEPROC                                     ,glInvalidateTexImage                          );
    GL_GetFunc(PFNGLINVALIDATEBUFFERSUBDATAPROC                                ,glInvalidateBufferSubData                     );
    GL_GetFunc(PFNGLINVALIDATEBUFFERDATAPROC                                   ,glInvalidateBufferData                        );
    GL_GetFunc(PFNGLINVALIDATEFRAMEBUFFERPROC                                  ,glInvalidateFramebuffer                       );
    GL_GetFunc(PFNGLINVALIDATESUBFRAMEBUFFERPROC                               ,glInvalidateSubFramebuffer                    );
    GL_GetFunc(PFNGLMULTIDRAWARRAYSINDIRECTPROC                                ,glMultiDrawArraysIndirect                     );
    GL_GetFunc(PFNGLMULTIDRAWELEMENTSINDIRECTPROC                              ,glMultiDrawElementsIndirect                   );
    GL_GetFunc(PFNGLGETPROGRAMINTERFACEIVPROC                                  ,glGetProgramInterfaceiv                       );
    GL_GetFunc(PFNGLGETPROGRAMRESOURCEINDEXPROC                                ,glGetProgramResourceIndex                     );
    GL_GetFunc(PFNGLGETPROGRAMRESOURCENAMEPROC                                 ,glGetProgramResourceName                      );
    GL_GetFunc(PFNGLGETPROGRAMRESOURCEIVPROC                                   ,glGetProgramResourceiv                        );
    GL_GetFunc(PFNGLGETPROGRAMRESOURCELOCATIONPROC                             ,glGetProgramResourceLocation                  );
    GL_GetFunc(PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC                        ,glGetProgramResourceLocationIndex             );
    GL_GetFunc(PFNGLSHADERSTORAGEBLOCKBINDINGPROC                              ,glShaderStorageBlockBinding                   );
    GL_GetFunc(PFNGLTEXBUFFERRANGEPROC                                         ,glTexBufferRange                              );
    GL_GetFunc(PFNGLTEXSTORAGE2DMULTISAMPLEPROC                                ,glTexStorage2DMultisample                     );
    GL_GetFunc(PFNGLTEXSTORAGE3DMULTISAMPLEPROC                                ,glTexStorage3DMultisample                     );
    GL_GetFunc(PFNGLTEXTUREVIEWPROC                                            ,glTextureView                                 );
    GL_GetFunc(PFNGLBINDVERTEXBUFFERPROC                                       ,glBindVertexBuffer                            );
    GL_GetFunc(PFNGLVERTEXATTRIBFORMATPROC                                     ,glVertexAttribFormat                          );
    GL_GetFunc(PFNGLVERTEXATTRIBIFORMATPROC                                    ,glVertexAttribIFormat                         );
    GL_GetFunc(PFNGLVERTEXATTRIBLFORMATPROC                                    ,glVertexAttribLFormat                         );
    GL_GetFunc(PFNGLVERTEXATTRIBBINDINGPROC                                    ,glVertexAttribBinding                         );
    GL_GetFunc(PFNGLVERTEXBINDINGDIVISORPROC                                   ,glVertexBindingDivisor                        );
    GL_GetFunc(PFNGLDEBUGMESSAGECONTROLPROC                                    ,glDebugMessageControl                         );
    GL_GetFunc(PFNGLDEBUGMESSAGEINSERTPROC                                     ,glDebugMessageInsert                          );
    GL_GetFunc(PFNGLDEBUGMESSAGECALLBACKPROC                                   ,glDebugMessageCallback                        );
    GL_GetFunc(PFNGLGETDEBUGMESSAGELOGPROC                                     ,glGetDebugMessageLog                          );
    GL_GetFunc(PFNGLPUSHDEBUGGROUPPROC                                         ,glPushDebugGroup                              );
    GL_GetFunc(PFNGLPOPDEBUGGROUPPROC                                          ,glPopDebugGroup                               );
    GL_GetFunc(PFNGLOBJECTLABELPROC                                            ,glObjectLabel                                 );
    GL_GetFunc(PFNGLGETOBJECTLABELPROC                                         ,glGetObjectLabel                              );
    GL_GetFunc(PFNGLOBJECTPTRLABELPROC                                         ,glObjectPtrLabel                              );
    GL_GetFunc(PFNGLGETOBJECTPTRLABELPROC                                      ,glGetObjectPtrLabel                           );
    #endif /* GL_VERSION_4_3 */

    #ifdef GL_VERSION_4_4
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_4_4\n");
    GL_GetFunc(PFNGLBUFFERSTORAGEPROC                          ,glBufferStorage              );
    GL_GetFunc(PFNGLCLEARTEXIMAGEPROC                          ,glClearTexImage              );
    GL_GetFunc(PFNGLCLEARTEXSUBIMAGEPROC                       ,glClearTexSubImage           );
    GL_GetFunc(PFNGLBINDBUFFERSBASEPROC                        ,glBindBuffersBase            );
    GL_GetFunc(PFNGLBINDBUFFERSRANGEPROC                       ,glBindBuffersRange           );
    GL_GetFunc(PFNGLBINDTEXTURESPROC                           ,glBindTextures               );
    GL_GetFunc(PFNGLBINDSAMPLERSPROC                           ,glBindSamplers               );
    GL_GetFunc(PFNGLBINDIMAGETEXTURESPROC                      ,glBindImageTextures          );
    GL_GetFunc(PFNGLBINDVERTEXBUFFERSPROC                      ,glBindVertexBuffers          );
    #endif /* GL_VERSION_4_4 */

    #ifdef GL_VERSION_4_5
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_4_5\n");
      GL_GetFunc(PFNGLCLIPCONTROLPROC                                              ,glClipControl                                      );
    GL_GetFunc(PFNGLCREATETRANSFORMFEEDBACKSPROC                                 ,glCreateTransformFeedbacks                         );
    GL_GetFunc(PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC                              ,glTransformFeedbackBufferBase                      );
    GL_GetFunc(PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC                             ,glTransformFeedbackBufferRange                     );
    GL_GetFunc(PFNGLGETTRANSFORMFEEDBACKIVPROC                                   ,glGetTransformFeedbackiv                           );
    GL_GetFunc(PFNGLGETTRANSFORMFEEDBACKI_VPROC                                  ,glGetTransformFeedbacki_v                          );
    GL_GetFunc(PFNGLGETTRANSFORMFEEDBACKI64_VPROC                                ,glGetTransformFeedbacki64_v                        );
    GL_GetFunc(PFNGLCREATEBUFFERSPROC                                            ,glCreateBuffers                                    );
     GL_GetFunc(PFNGLNAMEDBUFFERSTORAGEPROC                                       ,glNamedBufferStorage                               );
     GL_GetFunc(PFNGLNAMEDBUFFERDATAPROC                                          ,glNamedBufferData                                  );
     GL_GetFunc(PFNGLNAMEDBUFFERSUBDATAPROC                                       ,glNamedBufferSubData                               );
    GL_GetFunc(PFNGLCOPYNAMEDBUFFERSUBDATAPROC                                   ,glCopyNamedBufferSubData                           );
     GL_GetFunc(PFNGLCLEARNAMEDBUFFERDATAPROC                                     ,glClearNamedBufferData                             );
     GL_GetFunc(PFNGLCLEARNAMEDBUFFERSUBDATAPROC                                  ,glClearNamedBufferSubData                          );
     GL_GetFunc(PFNGLMAPNAMEDBUFFERPROC                                           ,glMapNamedBuffer                                   );
     GL_GetFunc(PFNGLMAPNAMEDBUFFERRANGEPROC                                      ,glMapNamedBufferRange                              );
     GL_GetFunc(PFNGLUNMAPNAMEDBUFFERPROC                                         ,glUnmapNamedBuffer                                 );
     GL_GetFunc(PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC                              ,glFlushMappedNamedBufferRange                      );
     GL_GetFunc(PFNGLGETNAMEDBUFFERPARAMETERIVPROC                                ,glGetNamedBufferParameteriv                        );
    GL_GetFunc(PFNGLGETNAMEDBUFFERPARAMETERI64VPROC                              ,glGetNamedBufferParameteri64v                      );
     GL_GetFunc(PFNGLGETNAMEDBUFFERPOINTERVPROC                                   ,glGetNamedBufferPointerv                           );
     GL_GetFunc(PFNGLGETNAMEDBUFFERSUBDATAPROC                                    ,glGetNamedBufferSubData                            );
    GL_GetFunc(PFNGLCREATEFRAMEBUFFERSPROC                                       ,glCreateFramebuffers                               );
     GL_GetFunc(PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC                             ,glNamedFramebufferRenderbuffer                     );
     GL_GetFunc(PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC                               ,glNamedFramebufferParameteri                       );
     GL_GetFunc(PFNGLNAMEDFRAMEBUFFERTEXTUREPROC                                  ,glNamedFramebufferTexture                          );
     GL_GetFunc(PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC                             ,glNamedFramebufferTextureLayer                     );
    GL_GetFunc(PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC                               ,glNamedFramebufferDrawBuffer                       );
    GL_GetFunc(PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC                              ,glNamedFramebufferDrawBuffers                      );
    GL_GetFunc(PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC                               ,glNamedFramebufferReadBuffer                       );
    GL_GetFunc(PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC                           ,glInvalidateNamedFramebufferData                   );
    GL_GetFunc(PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC                        ,glInvalidateNamedFramebufferSubData                );
    GL_GetFunc(PFNGLCLEARNAMEDFRAMEBUFFERIVPROC                                  ,glClearNamedFramebufferiv                          );
    GL_GetFunc(PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC                                 ,glClearNamedFramebufferuiv                         );
    GL_GetFunc(PFNGLCLEARNAMEDFRAMEBUFFERFVPROC                                  ,glClearNamedFramebufferfv                          );
    GL_GetFunc(PFNGLCLEARNAMEDFRAMEBUFFERFIPROC                                  ,glClearNamedFramebufferfi                          );
    GL_GetFunc(PFNGLBLITNAMEDFRAMEBUFFERPROC                                     ,glBlitNamedFramebuffer                             );
     GL_GetFunc(PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC                              ,glCheckNamedFramebufferStatus                      );
     GL_GetFunc(PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC                           ,glGetNamedFramebufferParameteriv                   );
     GL_GetFunc(PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC                 ,glGetNamedFramebufferAttachmentParameteriv         );
    GL_GetFunc(PFNGLCREATERENDERBUFFERSPROC                                      ,glCreateRenderbuffers                              );
     GL_GetFunc(PFNGLNAMEDRENDERBUFFERSTORAGEPROC                                 ,glNamedRenderbufferStorage                         );
     GL_GetFunc(PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC                      ,glNamedRenderbufferStorageMultisample              );
     GL_GetFunc(PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC                          ,glGetNamedRenderbufferParameteriv                  );
    GL_GetFunc(PFNGLCREATETEXTURESPROC                                           ,glCreateTextures                                   );
    GL_GetFuncEXT(PFNGLTEXTUREBUFFERPROC                                            ,glTextureBuffer                                    );
    GL_GetFuncEXT(PFNGLTEXTUREBUFFERRANGEPROC                                       ,glTextureBufferRange                               );
     GL_GetFuncEXT(PFNGLTEXTURESTORAGE1DPROC                                         ,glTextureStorage1D                                 );
     GL_GetFuncEXT(PFNGLTEXTURESTORAGE2DPROC                                         ,glTextureStorage2D                                 );
     GL_GetFuncEXT(PFNGLTEXTURESTORAGE3DPROC                                         ,glTextureStorage3D                                 );
    GL_GetFuncEXT(PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC                              ,glTextureStorage2DMultisample                      );
    GL_GetFuncEXT(PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC                              ,glTextureStorage3DMultisample                      );
    GL_GetFuncEXT(PFNGLTEXTURESUBIMAGE1DPROC                                        ,glTextureSubImage1D                                );
    GL_GetFuncEXT(PFNGLTEXTURESUBIMAGE2DPROC                                        ,glTextureSubImage2D                                );
    GL_GetFuncEXT(PFNGLTEXTURESUBIMAGE3DPROC                                        ,glTextureSubImage3D                                );
    GL_GetFuncEXT(PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC                              ,glCompressedTextureSubImage1D                      );
    GL_GetFuncEXT(PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC                              ,glCompressedTextureSubImage2D                      );
    GL_GetFuncEXT(PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC                              ,glCompressedTextureSubImage3D                      );
    GL_GetFuncEXT(PFNGLCOPYTEXTURESUBIMAGE1DPROC                                    ,glCopyTextureSubImage1D                            );
    GL_GetFuncEXT(PFNGLCOPYTEXTURESUBIMAGE2DPROC                                    ,glCopyTextureSubImage2D                            );
    GL_GetFuncEXT(PFNGLCOPYTEXTURESUBIMAGE3DPROC                                    ,glCopyTextureSubImage3D                            );
    GL_GetFuncEXT(PFNGLTEXTUREPARAMETERFPROC                                        ,glTextureParameterf                                );
    GL_GetFuncEXT(PFNGLTEXTUREPARAMETERFVPROC                                       ,glTextureParameterfv                               );
    GL_GetFuncEXT(PFNGLTEXTUREPARAMETERIPROC                                        ,glTextureParameteri                                );
    GL_GetFuncEXT(PFNGLTEXTUREPARAMETERIIVPROC                                      ,glTextureParameterIiv                              );
    GL_GetFuncEXT(PFNGLTEXTUREPARAMETERIUIVPROC                                     ,glTextureParameterIuiv                             );
    GL_GetFuncEXT(PFNGLTEXTUREPARAMETERIVPROC                                       ,glTextureParameteriv                               );
    GL_GetFuncEXT(PFNGLGENERATETEXTUREMIPMAPPROC                                    ,glGenerateTextureMipmap                            );
    GL_GetFuncEXT(PFNGLBINDTEXTUREUNITPROC                                          ,glBindTextureUnit                                  );
    GL_GetFuncEXT(PFNGLGETTEXTUREIMAGEPROC                                          ,glGetTextureImage                                  );
    GL_GetFuncEXT(PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC                                ,glGetCompressedTextureImage                        );
    GL_GetFuncEXT(PFNGLGETTEXTURELEVELPARAMETERFVPROC                               ,glGetTextureLevelParameterfv                       );
    GL_GetFuncEXT(PFNGLGETTEXTURELEVELPARAMETERIVPROC                               ,glGetTextureLevelParameteriv                       );
    GL_GetFuncEXT(PFNGLGETTEXTUREPARAMETERFVPROC                                    ,glGetTextureParameterfv                            );
    GL_GetFuncEXT(PFNGLGETTEXTUREPARAMETERIIVPROC                                   ,glGetTextureParameterIiv                           );
    GL_GetFuncEXT(PFNGLGETTEXTUREPARAMETERIUIVPROC                                  ,glGetTextureParameterIuiv                          );
    GL_GetFuncEXT(PFNGLGETTEXTUREPARAMETERIVPROC                                    ,glGetTextureParameteriv                            );
    GL_GetFunc(PFNGLCREATEVERTEXARRAYSPROC                                       ,glCreateVertexArrays                               );
     GL_GetFunc(PFNGLDISABLEVERTEXARRAYATTRIBPROC                                 ,glDisableVertexArrayAttrib                         );
     GL_GetFunc(PFNGLENABLEVERTEXARRAYATTRIBPROC                                  ,glEnableVertexArrayAttrib                          );
    GL_GetFunc(PFNGLVERTEXARRAYELEMENTBUFFERPROC                                 ,glVertexArrayElementBuffer                         );
    GL_GetFunc(PFNGLVERTEXARRAYVERTEXBUFFERPROC                                  ,glVertexArrayVertexBuffer                          );
    GL_GetFunc(PFNGLVERTEXARRAYVERTEXBUFFERSPROC                                 ,glVertexArrayVertexBuffers                         );
    GL_GetFunc(PFNGLVERTEXARRAYATTRIBBINDINGPROC                                 ,glVertexArrayAttribBinding                         );
    GL_GetFunc(PFNGLVERTEXARRAYATTRIBFORMATPROC                                  ,glVertexArrayAttribFormat                          );
    GL_GetFunc(PFNGLVERTEXARRAYATTRIBIFORMATPROC                                 ,glVertexArrayAttribIFormat                         );
    GL_GetFunc(PFNGLVERTEXARRAYATTRIBLFORMATPROC                                 ,glVertexArrayAttribLFormat                         );
    GL_GetFunc(PFNGLVERTEXARRAYBINDINGDIVISORPROC                                ,glVertexArrayBindingDivisor                        );
    GL_GetFunc(PFNGLGETVERTEXARRAYIVPROC                                         ,glGetVertexArrayiv                                 );
    GL_GetFunc(PFNGLGETVERTEXARRAYINDEXEDIVPROC                                  ,glGetVertexArrayIndexediv                          );
    GL_GetFunc(PFNGLGETVERTEXARRAYINDEXED64IVPROC                                ,glGetVertexArrayIndexed64iv                        );
    GL_GetFunc(PFNGLCREATESAMPLERSPROC                                           ,glCreateSamplers                                   );
    GL_GetFunc(PFNGLCREATEPROGRAMPIPELINESPROC                                   ,glCreateProgramPipelines                           );
    GL_GetFunc(PFNGLCREATEQUERIESPROC                                            ,glCreateQueries                                    );
    GL_GetFunc(PFNGLGETQUERYBUFFEROBJECTI64VPROC                                 ,glGetQueryBufferObjecti64v                         );
    GL_GetFunc(PFNGLGETQUERYBUFFEROBJECTIVPROC                                   ,glGetQueryBufferObjectiv                           );
    GL_GetFunc(PFNGLGETQUERYBUFFEROBJECTUI64VPROC                                ,glGetQueryBufferObjectui64v                        );
    GL_GetFunc(PFNGLGETQUERYBUFFEROBJECTUIVPROC                                  ,glGetQueryBufferObjectuiv                          );
    GL_GetFunc(PFNGLMEMORYBARRIERBYREGIONPROC                                    ,glMemoryBarrierByRegion                            );
      GL_GetFunc(PFNGLGETTEXTURESUBIMAGEPROC                                       ,glGetTextureSubImage                               );
      GL_GetFunc(PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC                             ,glGetCompressedTextureSubImage                     );
     GL_GetFunc(PFNGLGETGRAPHICSRESETSTATUSPROC                                   ,glGetGraphicsResetStatus                           );
     GL_GetFunc(PFNGLGETNCOMPRESSEDTEXIMAGEPROC                                   ,glGetnCompressedTexImage                           );
     GL_GetFunc(PFNGLGETNTEXIMAGEPROC                                             ,glGetnTexImage                                     );
     GL_GetFunc(PFNGLGETNUNIFORMDVPROC                                            ,glGetnUniformdv                                    );
     GL_GetFunc(PFNGLGETNUNIFORMFVPROC                                            ,glGetnUniformfv                                    );
     GL_GetFunc(PFNGLGETNUNIFORMIVPROC                                            ,glGetnUniformiv                                    );
     GL_GetFunc(PFNGLGETNUNIFORMUIVPROC                                           ,glGetnUniformuiv                                   );
     GL_GetFunc(PFNGLREADNPIXELSPROC                                              ,glReadnPixels                                      );
     GL_GetFunc(PFNGLGETNMAPDVPROC                                                ,glGetnMapdv                                        );
     GL_GetFunc(PFNGLGETNMAPFVPROC                                                ,glGetnMapfv                                        );
     GL_GetFunc(PFNGLGETNMAPIVPROC                                                ,glGetnMapiv                                        );
     GL_GetFunc(PFNGLGETNPIXELMAPFVPROC                                           ,glGetnPixelMapfv                                   );
     GL_GetFunc(PFNGLGETNPIXELMAPUIVPROC                                          ,glGetnPixelMapuiv                                  );
     GL_GetFunc(PFNGLGETNPIXELMAPUSVPROC                                          ,glGetnPixelMapusv                                  );
     GL_GetFunc(PFNGLGETNPOLYGONSTIPPLEPROC                                       ,glGetnPolygonStipple                               );
     GL_GetFunc(PFNGLGETNCOLORTABLEPROC                                           ,glGetnColorTable                                   );
     GL_GetFunc(PFNGLGETNCONVOLUTIONFILTERPROC                                    ,glGetnConvolutionFilter                            );
     GL_GetFunc(PFNGLGETNSEPARABLEFILTERPROC                                      ,glGetnSeparableFilter                              );
     GL_GetFunc(PFNGLGETNHISTOGRAMPROC                                            ,glGetnHistogram                                    );
     GL_GetFunc(PFNGLGETNMINMAXPROC                                               ,glGetnMinmax                                       );
      GL_GetFunc(PFNGLTEXTUREBARRIERPROC                                           ,glTextureBarrier                                   );
    #endif /* GL_VERSION_4_5 */

    #ifdef GL_VERSION_4_6
	fprintf(LogGlGetFunctions_py, "\nGL_VERSION_4_6\n");
    GL_GetFunc(PFNGLSPECIALIZESHADERPROC                                ,glSpecializeShader                      );
    GL_GetFunc(PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC                    ,glMultiDrawArraysIndirectCount          );
    GL_GetFunc(PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC                  ,glMultiDrawElementsIndirectCount        );
    GL_GetFunc(PFNGLPOLYGONOFFSETCLAMPPROC                              ,glPolygonOffsetClamp                    );
    #endif /* GL_VERSION_4_6 */

	
    #ifdef GL_ARB_imaging
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_imaging\n");
    GL_GetFunc(PFNGLCOLORTABLEPROC                                    ,glColorTable                   );
    GL_GetFunc(PFNGLCOLORTABLEPARAMETERFVPROC                         ,glColorTableParameterfv        );
    GL_GetFunc(PFNGLCOLORTABLEPARAMETERIVPROC                         ,glColorTableParameteriv        );
    GL_GetFunc(PFNGLCOPYCOLORTABLEPROC                                ,glCopyColorTable               );
    GL_GetFunc(PFNGLGETCOLORTABLEPROC                                 ,glGetColorTable                );
    GL_GetFunc(PFNGLGETCOLORTABLEPARAMETERFVPROC                      ,glGetColorTableParameterfv     );
    GL_GetFunc(PFNGLGETCOLORTABLEPARAMETERIVPROC                      ,glGetColorTableParameteriv     );
    GL_GetFunc(PFNGLCOLORSUBTABLEPROC                                 ,glColorSubTable                );
    GL_GetFunc(PFNGLCOPYCOLORSUBTABLEPROC                             ,glCopyColorSubTable            );
    GL_GetFunc(PFNGLCONVOLUTIONFILTER1DPROC                           ,glConvolutionFilter1D          );
    GL_GetFunc(PFNGLCONVOLUTIONFILTER2DPROC                           ,glConvolutionFilter2D          );
    GL_GetFunc(PFNGLCONVOLUTIONPARAMETERFPROC                         ,glConvolutionParameterf        );
    GL_GetFunc(PFNGLCONVOLUTIONPARAMETERFVPROC                        ,glConvolutionParameterfv       );
    GL_GetFunc(PFNGLCONVOLUTIONPARAMETERIPROC                         ,glConvolutionParameteri        );
    GL_GetFunc(PFNGLCONVOLUTIONPARAMETERIVPROC                        ,glConvolutionParameteriv       );
    GL_GetFunc(PFNGLCOPYCONVOLUTIONFILTER1DPROC                       ,glCopyConvolutionFilter1D      );
    GL_GetFunc(PFNGLCOPYCONVOLUTIONFILTER2DPROC                       ,glCopyConvolutionFilter2D      );
    GL_GetFunc(PFNGLGETCONVOLUTIONFILTERPROC                          ,glGetConvolutionFilter         );
    GL_GetFunc(PFNGLGETCONVOLUTIONPARAMETERFVPROC                     ,glGetConvolutionParameterfv    );
    GL_GetFunc(PFNGLGETCONVOLUTIONPARAMETERIVPROC                     ,glGetConvolutionParameteriv    );
    GL_GetFunc(PFNGLGETSEPARABLEFILTERPROC                            ,glGetSeparableFilter           );
    GL_GetFunc(PFNGLSEPARABLEFILTER2DPROC                             ,glSeparableFilter2D            );
    GL_GetFunc(PFNGLGETHISTOGRAMPROC                                  ,glGetHistogram                 );
    GL_GetFunc(PFNGLGETHISTOGRAMPARAMETERFVPROC                       ,glGetHistogramParameterfv      );
    GL_GetFunc(PFNGLGETHISTOGRAMPARAMETERIVPROC                       ,glGetHistogramParameteriv      );
    GL_GetFunc(PFNGLGETMINMAXPROC                                     ,glGetMinmax                    );
    GL_GetFunc(PFNGLGETMINMAXPARAMETERFVPROC                          ,glGetMinmaxParameterfv         );
    GL_GetFunc(PFNGLGETMINMAXPARAMETERIVPROC                          ,glGetMinmaxParameteriv         );
    GL_GetFunc(PFNGLHISTOGRAMPROC                                     ,glHistogram                    );
    GL_GetFunc(PFNGLMINMAXPROC                                        ,glMinmax                       );
    GL_GetFunc(PFNGLRESETHISTOGRAMPROC                                ,glResetHistogram               );
    GL_GetFunc(PFNGLRESETMINMAXPROC                                   ,glResetMinmax                  );
    #endif /* GL_ARB_imaging */

    #ifdef GL_ARB_ES3_2_compatibility
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_ES3_2_compatibility\n");
    GL_GetFuncEXT(PFNGLPRIMITIVEBOUNDINGBOXARBPROC              ,glPrimitiveBoundingBoxARB );
    #endif /* GL_ARB_ES3_2_compatibility */

    #ifdef GL_ARB_bindless_texture
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_bindless_texture\n");
    GL_GetFuncEXT(PFNGLGETTEXTUREHANDLEARBPROC                                ,glGetTextureHandleARB                );
    GL_GetFuncEXT(PFNGLGETTEXTURESAMPLERHANDLEARBPROC                         ,glGetTextureSamplerHandleARB         );
	GL_GetFuncEXT(PFNGLMAKETEXTUREHANDLERESIDENTARBPROC                       ,glMakeTextureHandleResidentARB       );
	GL_GetFuncEXT(PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC                    ,glMakeTextureHandleNonResidentARB    );
	GL_GetFuncEXT(PFNGLGETIMAGEHANDLEARBPROC                                  ,glGetImageHandleARB                  );
	GL_GetFuncEXT(PFNGLMAKEIMAGEHANDLERESIDENTARBPROC                         ,glMakeImageHandleResidentARB         );
	GL_GetFuncEXT(PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC                      ,glMakeImageHandleNonResidentARB      );
	GL_GetFuncEXT(PFNGLUNIFORMHANDLEUI64ARBPROC                               ,glUniformHandleui64ARB               );
    GL_GetFuncEXT(PFNGLUNIFORMHANDLEUI64VARBPROC                              ,glUniformHandleui64vARB              );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC                        ,glProgramUniformHandleui64ARB        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC                       ,glProgramUniformHandleui64vARB       );
    GL_GetFuncEXT(PFNGLISTEXTUREHANDLERESIDENTARBPROC                         ,glIsTextureHandleResidentARB         );
	GL_GetFuncEXT(PFNGLISIMAGEHANDLERESIDENTARBPROC                           ,glIsImageHandleResidentARB           );
	GL_GetFuncEXT(PFNGLVERTEXATTRIBL1UI64ARBPROC                              ,glVertexAttribL1ui64ARB              );
	GL_GetFuncEXT(PFNGLVERTEXATTRIBL1UI64VARBPROC                             ,glVertexAttribL1ui64vARB             );
	GL_GetFuncEXT(PFNGLGETVERTEXATTRIBLUI64VARBPROC                           ,glGetVertexAttribLui64vARB           );
    #endif /* GL_ARB_bindless_texture */

    #ifdef GL_ARB_cl_event
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_cl_event\n");
    GL_GetFuncEXT(PFNGLCREATESYNCFROMCLEVENTARBPROC               ,glCreateSyncFromCLeventARB );
    #endif /* GL_ARB_cl_event */

    #ifdef GL_ARB_color_buffer_float
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_color_buffer_float\n");
    GL_GetFuncEXT(PFNGLCLAMPCOLORARBPROC               ,glClampColorARB );
    #endif /* GL_ARB_color_buffer_float */

    #ifdef GL_ARB_compute_variable_group_size
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_compute_variable_group_size\n");
    GL_GetFuncEXT(PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC               ,glDispatchComputeGroupSizeARB );
    #endif /* GL_ARB_compute_variable_group_size */

    #ifdef GL_ARB_debug_output
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_debug_output\n");
	GL_GetFuncEXT(PFNGLDEBUGMESSAGECONTROLARBPROC                  ,glDebugMessageControlARB   );
	GL_GetFuncEXT(PFNGLDEBUGMESSAGEINSERTARBPROC                   ,glDebugMessageInsertARB    );
	GL_GetFuncEXT(PFNGLDEBUGMESSAGECALLBACKARBPROC                 ,glDebugMessageCallbackARB  );
	GL_GetFuncEXT(PFNGLGETDEBUGMESSAGELOGARBPROC                   ,glGetDebugMessageLogARB    );
    #endif /* GL_ARB_debug_output */

    #ifdef GL_ARB_draw_buffers
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_draw_buffers\n");
    GL_GetFuncEXT(PFNGLDRAWBUFFERSARBPROC               ,glDrawBuffersARB );
    #endif /* GL_ARB_draw_buffers */

    #ifdef GL_ARB_draw_buffers_blend
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_draw_buffers_blend\n");
	GL_GetFuncEXT(PFNGLBLENDEQUATIONIARBPROC	                        ,glBlendEquationiARB             );
	GL_GetFuncEXT(PFNGLBLENDEQUATIONSEPARATEIARBPROC                  ,glBlendEquationSeparateiARB     );
	GL_GetFuncEXT(PFNGLBLENDFUNCIARBPROC                              ,glBlendFunciARB                 );
    GL_GetFuncEXT(PFNGLBLENDFUNCSEPARATEIARBPROC                      ,glBlendFuncSeparateiARB         );
    #endif /* GL_ARB_draw_buffers_blend */

    #ifdef GL_ARB_draw_instanced
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_draw_instanced\n");
    GL_GetFuncEXT(PFNGLDRAWARRAYSINSTANCEDARBPROC                    ,glDrawArraysInstancedARB      );
    GL_GetFuncEXT(PFNGLDRAWELEMENTSINSTANCEDARBPROC                  ,glDrawElementsInstancedARB    );
    #endif /* GL_ARB_draw_instanced */

    #ifdef GL_ARB_fragment_program
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_fragment_program\n");
    GL_GetFuncEXT(PFNGLPROGRAMSTRINGARBPROC                                ,glProgramStringARB                   );
    GL_GetFuncEXT(PFNGLBINDPROGRAMARBPROC                                  ,glBindProgramARB                     );
    GL_GetFuncEXT(PFNGLDELETEPROGRAMSARBPROC                               ,glDeleteProgramsARB                  );
    GL_GetFuncEXT(PFNGLGENPROGRAMSARBPROC                                  ,glGenProgramsARB                     );
    GL_GetFuncEXT(PFNGLPROGRAMENVPARAMETER4DARBPROC                        ,glProgramEnvParameter4dARB           );
    GL_GetFuncEXT(PFNGLPROGRAMENVPARAMETER4DVARBPROC                       ,glProgramEnvParameter4dvARB          );
    GL_GetFuncEXT(PFNGLPROGRAMENVPARAMETER4FARBPROC                        ,glProgramEnvParameter4fARB           );
    GL_GetFuncEXT(PFNGLPROGRAMENVPARAMETER4FVARBPROC                       ,glProgramEnvParameter4fvARB          );
    GL_GetFuncEXT(PFNGLPROGRAMLOCALPARAMETER4DARBPROC                      ,glProgramLocalParameter4dARB         );
    GL_GetFuncEXT(PFNGLPROGRAMLOCALPARAMETER4DVARBPROC                     ,glProgramLocalParameter4dvARB        );
    GL_GetFuncEXT(PFNGLPROGRAMLOCALPARAMETER4FARBPROC                      ,glProgramLocalParameter4fARB         );
    GL_GetFuncEXT(PFNGLPROGRAMLOCALPARAMETER4FVARBPROC                     ,glProgramLocalParameter4fvARB        );
    GL_GetFuncEXT(PFNGLGETPROGRAMENVPARAMETERDVARBPROC                     ,glGetProgramEnvParameterdvARB        );
    GL_GetFuncEXT(PFNGLGETPROGRAMENVPARAMETERFVARBPROC                     ,glGetProgramEnvParameterfvARB        );
    GL_GetFuncEXT(PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC                   ,glGetProgramLocalParameterdvARB      );
    GL_GetFuncEXT(PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC                   ,glGetProgramLocalParameterfvARB      );
    GL_GetFuncEXT(PFNGLGETPROGRAMIVARBPROC                                 ,glGetProgramivARB                    );
    GL_GetFuncEXT(PFNGLGETPROGRAMSTRINGARBPROC                             ,glGetProgramStringARB                );
    GL_GetFuncEXT(PFNGLISPROGRAMARBPROC                                    ,glIsProgramARB                       );
    #endif /* GL_ARB_fragment_program */

    #ifdef GL_ARB_geometry_shader4
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_geometry_shader4\n");
	GL_GetFuncEXT(PFNGLPROGRAMPARAMETERIARBPROC                        ,glProgramParameteriARB 		  );
	GL_GetFuncEXT(PFNGLFRAMEBUFFERTEXTUREARBPROC                       ,glFramebufferTextureARB          );
	GL_GetFuncEXT(PFNGLFRAMEBUFFERTEXTURELAYERARBPROC	                 ,glFramebufferTextureLayerARB     );
	GL_GetFuncEXT(PFNGLFRAMEBUFFERTEXTUREFACEARBPROC 	                 ,glFramebufferTextureFaceARB      );
    #endif /* GL_ARB_geometry_shader4 */

    #ifdef GL_ARB_gl_spirv
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_gl_spirv\n");
    GL_GetFuncEXT(PFNGLSPECIALIZESHADERARBPROC              ,glSpecializeShaderARB  );
    #endif /* GL_ARB_gl_spirv */

    #ifdef GL_ARB_gpu_shader_int64
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_gpu_shader_int64\n");
    GL_GetFuncEXT(PFNGLUNIFORM1I64ARBPROC                                   ,glUniform1i64ARB              );
    GL_GetFuncEXT(PFNGLUNIFORM2I64ARBPROC                                   ,glUniform2i64ARB              );
    GL_GetFuncEXT(PFNGLUNIFORM3I64ARBPROC                                   ,glUniform3i64ARB              );
    GL_GetFuncEXT(PFNGLUNIFORM4I64ARBPROC                                   ,glUniform4i64ARB              );
    GL_GetFuncEXT(PFNGLUNIFORM1I64VARBPROC                                  ,glUniform1i64vARB             );
    GL_GetFuncEXT(PFNGLUNIFORM2I64VARBPROC                                  ,glUniform2i64vARB             );
    GL_GetFuncEXT(PFNGLUNIFORM3I64VARBPROC                                  ,glUniform3i64vARB             );
    GL_GetFuncEXT(PFNGLUNIFORM4I64VARBPROC                                  ,glUniform4i64vARB             );
    GL_GetFuncEXT(PFNGLUNIFORM1UI64ARBPROC                                  ,glUniform1ui64ARB             );
    GL_GetFuncEXT(PFNGLUNIFORM2UI64ARBPROC                                  ,glUniform2ui64ARB             );
    GL_GetFuncEXT(PFNGLUNIFORM3UI64ARBPROC                                  ,glUniform3ui64ARB             );
    GL_GetFuncEXT(PFNGLUNIFORM4UI64ARBPROC                                  ,glUniform4ui64ARB             );
    GL_GetFuncEXT(PFNGLUNIFORM1UI64VARBPROC                                 ,glUniform1ui64vARB            );
    GL_GetFuncEXT(PFNGLUNIFORM2UI64VARBPROC                                 ,glUniform2ui64vARB            );
    GL_GetFuncEXT(PFNGLUNIFORM3UI64VARBPROC                                 ,glUniform3ui64vARB            );
    GL_GetFuncEXT(PFNGLUNIFORM4UI64VARBPROC                                 ,glUniform4ui64vARB            );
    GL_GetFuncEXT(PFNGLGETUNIFORMI64VARBPROC                                ,glGetUniformi64vARB           );
    GL_GetFuncEXT(PFNGLGETUNIFORMUI64VARBPROC                               ,glGetUniformui64vARB          );
    GL_GetFuncEXT(PFNGLGETNUNIFORMI64VARBPROC                               ,glGetnUniformi64vARB          );
    GL_GetFuncEXT(PFNGLGETNUNIFORMUI64VARBPROC                              ,glGetnUniformui64vARB         );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM1I64ARBPROC                            ,glProgramUniform1i64ARB       );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM2I64ARBPROC                            ,glProgramUniform2i64ARB       );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM3I64ARBPROC                            ,glProgramUniform3i64ARB       );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM4I64ARBPROC                            ,glProgramUniform4i64ARB       );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM1I64VARBPROC                           ,glProgramUniform1i64vARB      );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM2I64VARBPROC                           ,glProgramUniform2i64vARB      );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM3I64VARBPROC                           ,glProgramUniform3i64vARB      );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM4I64VARBPROC                           ,glProgramUniform4i64vARB      );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM1UI64ARBPROC                           ,glProgramUniform1ui64ARB      );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM2UI64ARBPROC                           ,glProgramUniform2ui64ARB      );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM3UI64ARBPROC                           ,glProgramUniform3ui64ARB      );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM4UI64ARBPROC                           ,glProgramUniform4ui64ARB      );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM1UI64VARBPROC                          ,glProgramUniform1ui64vARB     );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM2UI64VARBPROC                          ,glProgramUniform2ui64vARB     );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM3UI64VARBPROC                          ,glProgramUniform3ui64vARB     );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM4UI64VARBPROC                          ,glProgramUniform4ui64vARB     );
    #endif /* GL_ARB_gpu_shader_int64 */

    #ifdef GL_ARB_indirect_parameters
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_indirect_parameters\n");
	GL_GetFuncEXT(PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC                   ,glMultiDrawArraysIndirectCountARB     );
	GL_GetFuncEXT(PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC                 ,glMultiDrawElementsIndirectCountARB   );
    #endif /* GL_ARB_indirect_parameters */

    #ifdef GL_ARB_instanced_arrays
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_instanced_arrays\n");
    GL_GetFuncEXT(PFNGLVERTEXATTRIBDIVISORARBPROC              ,glVertexAttribDivisorARB );
    #endif /* GL_ARB_instanced_arrays */

    #ifdef GL_ARB_matrix_palette
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_matrix_palette\n");
    GL_GetFuncEXT(PFNGLCURRENTPALETTEMATRIXARBPROC                 ,glCurrentPaletteMatrixARB        );
    GL_GetFuncEXT(PFNGLMATRIXINDEXUBVARBPROC                       ,glMatrixIndexubvARB              );
    GL_GetFuncEXT(PFNGLMATRIXINDEXUSVARBPROC                       ,glMatrixIndexusvARB              );
    GL_GetFuncEXT(PFNGLMATRIXINDEXUIVARBPROC                       ,glMatrixIndexuivARB              );
    GL_GetFuncEXT(PFNGLMATRIXINDEXPOINTERARBPROC                   ,glMatrixIndexPointerARB          );
    #endif /* GL_ARB_matrix_palette */

    #ifdef GL_ARB_multisample
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_multisample\n");
    GL_GetFuncEXT(PFNGLSAMPLECOVERAGEARBPROC              ,glSampleCoverageARB );
    #endif /* GL_ARB_multisample */

    #ifdef GL_ARB_multitexture
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_multitexture\n");
    GL_GetFuncEXT(PFNGLACTIVETEXTUREARBPROC                         ,glActiveTextureARB             );
    GL_GetFuncEXT(PFNGLCLIENTACTIVETEXTUREARBPROC                   ,glClientActiveTextureARB       );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD1DARBPROC                       ,glMultiTexCoord1dARB           );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD1DVARBPROC                      ,glMultiTexCoord1dvARB          );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD1FARBPROC                       ,glMultiTexCoord1fARB           );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD1FVARBPROC                      ,glMultiTexCoord1fvARB          );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD1IARBPROC                       ,glMultiTexCoord1iARB           );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD1IVARBPROC                      ,glMultiTexCoord1ivARB          );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD1SARBPROC                       ,glMultiTexCoord1sARB           );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD1SVARBPROC                      ,glMultiTexCoord1svARB          );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD2DARBPROC                       ,glMultiTexCoord2dARB           );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD2DVARBPROC                      ,glMultiTexCoord2dvARB          );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD2FARBPROC                       ,glMultiTexCoord2fARB           );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD2FVARBPROC                      ,glMultiTexCoord2fvARB          );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD2IARBPROC                       ,glMultiTexCoord2iARB           );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD2IVARBPROC                      ,glMultiTexCoord2ivARB          );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD2SARBPROC                       ,glMultiTexCoord2sARB           );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD2SVARBPROC                      ,glMultiTexCoord2svARB          );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD3DARBPROC                       ,glMultiTexCoord3dARB           );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD3DVARBPROC                      ,glMultiTexCoord3dvARB          );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD3FARBPROC                       ,glMultiTexCoord3fARB           );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD3FVARBPROC                      ,glMultiTexCoord3fvARB          );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD3IARBPROC                       ,glMultiTexCoord3iARB           );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD3IVARBPROC                      ,glMultiTexCoord3ivARB          );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD3SARBPROC                       ,glMultiTexCoord3sARB           );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD3SVARBPROC                      ,glMultiTexCoord3svARB          );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD4DARBPROC                       ,glMultiTexCoord4dARB           );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD4DVARBPROC                      ,glMultiTexCoord4dvARB          );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD4FARBPROC                       ,glMultiTexCoord4fARB           );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD4FVARBPROC                      ,glMultiTexCoord4fvARB          );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD4IARBPROC                       ,glMultiTexCoord4iARB           );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD4IVARBPROC                      ,glMultiTexCoord4ivARB          );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD4SARBPROC                       ,glMultiTexCoord4sARB           );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD4SVARBPROC                      ,glMultiTexCoord4svARB          );
    #endif /* GL_ARB_multitexture */

    #ifdef GL_ARB_occlusion_query
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_occlusion_query\n");
    GL_GetFuncEXT(PFNGLGENQUERIESARBPROC                            ,glGenQueriesARB              );
    GL_GetFuncEXT(PFNGLDELETEQUERIESARBPROC                         ,glDeleteQueriesARB           );
    GL_GetFuncEXT(PFNGLISQUERYARBPROC                               ,glIsQueryARB                 );
    GL_GetFuncEXT(PFNGLBEGINQUERYARBPROC                            ,glBeginQueryARB              );
    GL_GetFuncEXT(PFNGLENDQUERYARBPROC                              ,glEndQueryARB                );
    GL_GetFuncEXT(PFNGLGETQUERYIVARBPROC                            ,glGetQueryivARB              );
    GL_GetFuncEXT(PFNGLGETQUERYOBJECTIVARBPROC                      ,glGetQueryObjectivARB        );
    GL_GetFuncEXT(PFNGLGETQUERYOBJECTUIVARBPROC                     ,glGetQueryObjectuivARB       );
    #endif /* GL_ARB_occlusion_query */

    #ifdef GL_ARB_parallel_shader_compile
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_parallel_shader_compile\n");
    GL_GetFuncEXT(PFNGLMAXSHADERCOMPILERTHREADSARBPROC              ,glMaxShaderCompilerThreadsARB );
    #endif /* GL_ARB_parallel_shader_compile */

    #ifdef GL_ARB_point_parameters
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_point_parameters\n");
    GL_GetFuncEXT(PFNGLPOINTPARAMETERFARBPROC                ,glPointParameterfARB  );
    GL_GetFuncEXT(PFNGLPOINTPARAMETERFVARBPROC               ,glPointParameterfvARB );
    #endif /* GL_ARB_point_parameters */

    #ifdef GL_ARB_robustness
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_robustness\n");
    GL_GetFuncEXT(PFNGLGETGRAPHICSRESETSTATUSARBPROC                   ,glGetGraphicsResetStatusARB        );
    GL_GetFuncEXT(PFNGLGETNTEXIMAGEARBPROC                             ,glGetnTexImageARB                  );
    GL_GetFuncEXT(PFNGLREADNPIXELSARBPROC                              ,glReadnPixelsARB                   );
    GL_GetFuncEXT(PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC                   ,glGetnCompressedTexImageARB        );
    GL_GetFuncEXT(PFNGLGETNUNIFORMFVARBPROC                            ,glGetnUniformfvARB                 );
    GL_GetFuncEXT(PFNGLGETNUNIFORMIVARBPROC                            ,glGetnUniformivARB                 );
    GL_GetFuncEXT(PFNGLGETNUNIFORMUIVARBPROC                           ,glGetnUniformuivARB                );
    GL_GetFuncEXT(PFNGLGETNUNIFORMDVARBPROC                            ,glGetnUniformdvARB                 );
    GL_GetFuncEXT(PFNGLGETNMAPDVARBPROC                                ,glGetnMapdvARB                     );
    GL_GetFuncEXT(PFNGLGETNMAPFVARBPROC                                ,glGetnMapfvARB                     );
    GL_GetFuncEXT(PFNGLGETNMAPIVARBPROC                                ,glGetnMapivARB                     );
    GL_GetFuncEXT(PFNGLGETNPIXELMAPFVARBPROC                           ,glGetnPixelMapfvARB                );
    GL_GetFuncEXT(PFNGLGETNPIXELMAPUIVARBPROC                          ,glGetnPixelMapuivARB               );
    GL_GetFuncEXT(PFNGLGETNPIXELMAPUSVARBPROC                          ,glGetnPixelMapusvARB               );
    GL_GetFuncEXT(PFNGLGETNPOLYGONSTIPPLEARBPROC                       ,glGetnPolygonStippleARB            );
    GL_GetFuncEXT(PFNGLGETNCOLORTABLEARBPROC                           ,glGetnColorTableARB                );
    GL_GetFuncEXT(PFNGLGETNCONVOLUTIONFILTERARBPROC                    ,glGetnConvolutionFilterARB         );
    GL_GetFuncEXT(PFNGLGETNSEPARABLEFILTERARBPROC                      ,glGetnSeparableFilterARB           );
    GL_GetFuncEXT(PFNGLGETNHISTOGRAMARBPROC                            ,glGetnHistogramARB                 );
    GL_GetFuncEXT(PFNGLGETNMINMAXARBPROC                               ,glGetnMinmaxARB                    );
    #endif /* GL_ARB_robustness */

    #ifdef GL_ARB_sample_locations
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_sample_locations\n");
    GL_GetFuncEXT(PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC                       ,glFramebufferSampleLocationsfvARB           );
    GL_GetFuncEXT(PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC                  ,glNamedFramebufferSampleLocationsfvARB      );
    GL_GetFuncEXT(PFNGLEVALUATEDEPTHVALUESARBPROC                                ,glEvaluateDepthValuesARB                    );
    #endif /* GL_ARB_sample_locations */

    #ifdef GL_ARB_sample_shading
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_sample_shading\n");
    GL_GetFuncEXT(PFNGLMINSAMPLESHADINGARBPROC              ,glMinSampleShadingARB );
    #endif /* GL_ARB_sample_shading */

    #ifdef GL_ARB_shader_objects
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_shader_objects\n");
    GL_GetFuncEXT(PFNGLDELETEOBJECTARBPROC                             ,glDeleteObjectARB               );
    GL_GetFuncEXT(PFNGLGETHANDLEARBPROC                                ,glGetHandleARB                  );
    GL_GetFuncEXT(PFNGLDETACHOBJECTARBPROC                             ,glDetachObjectARB               );
    GL_GetFuncEXT(PFNGLCREATESHADEROBJECTARBPROC                       ,glCreateShaderObjectARB         );
    GL_GetFuncEXT(PFNGLSHADERSOURCEARBPROC                             ,glShaderSourceARB               );
    GL_GetFuncEXT(PFNGLCOMPILESHADERARBPROC                            ,glCompileShaderARB              );
    GL_GetFuncEXT(PFNGLCREATEPROGRAMOBJECTARBPROC                      ,glCreateProgramObjectARB        );
    GL_GetFuncEXT(PFNGLATTACHOBJECTARBPROC                             ,glAttachObjectARB               );
    GL_GetFuncEXT(PFNGLLINKPROGRAMARBPROC                              ,glLinkProgramARB                );
    GL_GetFuncEXT(PFNGLUSEPROGRAMOBJECTARBPROC                         ,glUseProgramObjectARB           );
    GL_GetFuncEXT(PFNGLVALIDATEPROGRAMARBPROC                          ,glValidateProgramARB            );
    GL_GetFuncEXT(PFNGLUNIFORM1FARBPROC                                ,glUniform1fARB                  );
    GL_GetFuncEXT(PFNGLUNIFORM2FARBPROC                                ,glUniform2fARB                  );
    GL_GetFuncEXT(PFNGLUNIFORM3FARBPROC                                ,glUniform3fARB                  );
    GL_GetFuncEXT(PFNGLUNIFORM4FARBPROC                                ,glUniform4fARB                  );
    GL_GetFuncEXT(PFNGLUNIFORM1IARBPROC                                ,glUniform1iARB                  );
    GL_GetFuncEXT(PFNGLUNIFORM2IARBPROC                                ,glUniform2iARB                  );
    GL_GetFuncEXT(PFNGLUNIFORM3IARBPROC                                ,glUniform3iARB                  );
    GL_GetFuncEXT(PFNGLUNIFORM4IARBPROC                                ,glUniform4iARB                  );
    GL_GetFuncEXT(PFNGLUNIFORM1FVARBPROC                               ,glUniform1fvARB                 );
    GL_GetFuncEXT(PFNGLUNIFORM2FVARBPROC                               ,glUniform2fvARB                 );
    GL_GetFuncEXT(PFNGLUNIFORM3FVARBPROC                               ,glUniform3fvARB                 );
    GL_GetFuncEXT(PFNGLUNIFORM4FVARBPROC                               ,glUniform4fvARB                 );
    GL_GetFuncEXT(PFNGLUNIFORM1IVARBPROC                               ,glUniform1ivARB                 );
    GL_GetFuncEXT(PFNGLUNIFORM2IVARBPROC                               ,glUniform2ivARB                 );
    GL_GetFuncEXT(PFNGLUNIFORM3IVARBPROC                               ,glUniform3ivARB                 );
    GL_GetFuncEXT(PFNGLUNIFORM4IVARBPROC                               ,glUniform4ivARB                 );
    GL_GetFuncEXT(PFNGLUNIFORMMATRIX2FVARBPROC                         ,glUniformMatrix2fvARB           );
    GL_GetFuncEXT(PFNGLUNIFORMMATRIX3FVARBPROC                         ,glUniformMatrix3fvARB           );
    GL_GetFuncEXT(PFNGLUNIFORMMATRIX4FVARBPROC                         ,glUniformMatrix4fvARB           );
    GL_GetFuncEXT(PFNGLGETOBJECTPARAMETERFVARBPROC                     ,glGetObjectParameterfvARB       );
    GL_GetFuncEXT(PFNGLGETOBJECTPARAMETERIVARBPROC                     ,glGetObjectParameterivARB       );
    GL_GetFuncEXT(PFNGLGETINFOLOGARBPROC                               ,glGetInfoLogARB                 );
    GL_GetFuncEXT(PFNGLGETATTACHEDOBJECTSARBPROC                       ,glGetAttachedObjectsARB         );
    GL_GetFuncEXT(PFNGLGETUNIFORMLOCATIONARBPROC                       ,glGetUniformLocationARB         );
    GL_GetFuncEXT(PFNGLGETACTIVEUNIFORMARBPROC                         ,glGetActiveUniformARB           );
    GL_GetFuncEXT(PFNGLGETUNIFORMFVARBPROC                             ,glGetUniformfvARB               );
    GL_GetFuncEXT(PFNGLGETUNIFORMIVARBPROC                             ,glGetUniformivARB               );
    GL_GetFuncEXT(PFNGLGETSHADERSOURCEARBPROC                          ,glGetShaderSourceARB            );
    #endif /* GL_ARB_shader_objects */

    #ifdef GL_ARB_shading_language_include
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_shading_language_include\n");
    GL_GetFuncEXT(PFNGLNAMEDSTRINGARBPROC                             ,glNamedStringARB              );
    GL_GetFuncEXT(PFNGLDELETENAMEDSTRINGARBPROC                       ,glDeleteNamedStringARB        );
    GL_GetFuncEXT(PFNGLCOMPILESHADERINCLUDEARBPROC                    ,glCompileShaderIncludeARB     );
    GL_GetFuncEXT(PFNGLISNAMEDSTRINGARBPROC                           ,glIsNamedStringARB            );
    GL_GetFuncEXT(PFNGLGETNAMEDSTRINGARBPROC                          ,glGetNamedStringARB           );
    GL_GetFuncEXT(PFNGLGETNAMEDSTRINGIVARBPROC                        ,glGetNamedStringivARB         );
    #endif /* GL_ARB_shading_language_include */

    #ifdef GL_ARB_sparse_buffer
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_sparse_buffer\n");
    GL_GetFuncEXT(PFNGLBUFFERPAGECOMMITMENTARBPROC                     ,glBufferPageCommitmentARB        );
    GL_GetFuncEXT(PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC                ,glNamedBufferPageCommitmentEXT   );
    GL_GetFuncEXT(PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC                ,glNamedBufferPageCommitmentARB   );
    #endif /* GL_ARB_sparse_buffer */

    #ifdef GL_ARB_sparse_texture
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_sparse_texture\n");
    GL_GetFuncEXT(PFNGLTEXPAGECOMMITMENTARBPROC              ,glTexPageCommitmentARB );
    #endif /* GL_ARB_sparse_texture */

    #ifdef GL_ARB_texture_buffer_object
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_texture_buffer_object\n");
    GL_GetFuncEXT(PFNGLTEXBUFFERARBPROC              ,glTexBufferARB );
    #endif /* GL_ARB_texture_buffer_object */

    #ifdef GL_ARB_texture_compression
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_texture_compression\n");
    GL_GetFuncEXT(PFNGLCOMPRESSEDTEXIMAGE3DARBPROC                     ,glCompressedTexImage3DARB      );
    GL_GetFuncEXT(PFNGLCOMPRESSEDTEXIMAGE2DARBPROC                     ,glCompressedTexImage2DARB      );
	GL_GetFuncEXT(PFNGLCOMPRESSEDTEXIMAGE1DARBPROC 	                 ,glCompressedTexImage1DARB      );
	GL_GetFuncEXT(PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC	                 ,glCompressedTexSubImage3DARB   );
	GL_GetFuncEXT(PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC	                 ,glCompressedTexSubImage2DARB   );
	GL_GetFuncEXT(PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC	                 ,glCompressedTexSubImage1DARB   );
	GL_GetFuncEXT(PFNGLGETCOMPRESSEDTEXIMAGEARBPROC  	                 ,glGetCompressedTexImageARB     );
    #endif /* GL_ARB_texture_compression */

    #ifdef GL_ARB_transpose_matrix
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_transpose_matrix\n");
    GL_GetFuncEXT(PFNGLLOADTRANSPOSEMATRIXFARBPROC                ,glLoadTransposeMatrixfARB     );
    GL_GetFuncEXT(PFNGLLOADTRANSPOSEMATRIXDARBPROC                ,glLoadTransposeMatrixdARB     );
    GL_GetFuncEXT(PFNGLMULTTRANSPOSEMATRIXFARBPROC                ,glMultTransposeMatrixfARB     );
    GL_GetFuncEXT(PFNGLMULTTRANSPOSEMATRIXDARBPROC                ,glMultTransposeMatrixdARB     );
    #endif /* GL_ARB_transpose_matrix */

    #ifdef GL_ARB_vertex_blend
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_vertex_blend\n");
    GL_GetFuncEXT(PFNGLWEIGHTBVARBPROC                        ,glWeightbvARB         );
    GL_GetFuncEXT(PFNGLWEIGHTSVARBPROC                        ,glWeightsvARB         );
    GL_GetFuncEXT(PFNGLWEIGHTIVARBPROC                        ,glWeightivARB         );
    GL_GetFuncEXT(PFNGLWEIGHTFVARBPROC                        ,glWeightfvARB         );
    GL_GetFuncEXT(PFNGLWEIGHTDVARBPROC                        ,glWeightdvARB         );
    GL_GetFuncEXT(PFNGLWEIGHTUBVARBPROC                       ,glWeightubvARB        );
    GL_GetFuncEXT(PFNGLWEIGHTUSVARBPROC                       ,glWeightusvARB        );
    GL_GetFuncEXT(PFNGLWEIGHTUIVARBPROC                       ,glWeightuivARB        );
    GL_GetFuncEXT(PFNGLWEIGHTPOINTERARBPROC                   ,glWeightPointerARB    );
    GL_GetFuncEXT(PFNGLVERTEXBLENDARBPROC                     ,glVertexBlendARB      );
    #endif /* GL_ARB_vertex_blend */

    #ifdef GL_ARB_vertex_buffer_object
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_vertex_buffer_object\n");
    GL_GetFuncEXT(PFNGLBINDBUFFERARBPROC                           ,glBindBufferARB              );
    GL_GetFuncEXT(PFNGLDELETEBUFFERSARBPROC                        ,glDeleteBuffersARB           );
    GL_GetFuncEXT(PFNGLGENBUFFERSARBPROC                           ,glGenBuffersARB              );
    GL_GetFuncEXT(PFNGLISBUFFERARBPROC                             ,glIsBufferARB                );
    GL_GetFuncEXT(PFNGLBUFFERDATAARBPROC                           ,glBufferDataARB              );
    GL_GetFuncEXT(PFNGLBUFFERSUBDATAARBPROC                        ,glBufferSubDataARB           );
    GL_GetFuncEXT(PFNGLGETBUFFERSUBDATAARBPROC                     ,glGetBufferSubDataARB        );
    GL_GetFuncEXT(PFNGLMAPBUFFERARBPROC                            ,glMapBufferARB               );
    GL_GetFuncEXT(PFNGLUNMAPBUFFERARBPROC                          ,glUnmapBufferARB             );
    GL_GetFuncEXT(PFNGLGETBUFFERPARAMETERIVARBPROC                 ,glGetBufferParameterivARB    );
    GL_GetFuncEXT(PFNGLGETBUFFERPOINTERVARBPROC                    ,glGetBufferPointervARB       );
    #endif /* GL_ARB_vertex_buffer_object */

    #ifdef GL_ARB_vertex_program
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_vertex_program\n");
    GL_GetFuncEXT(PFNGLVERTEXATTRIB1DARBPROC                          ,glVertexAttrib1dARB             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB1DVARBPROC                         ,glVertexAttrib1dvARB            );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB1FARBPROC                          ,glVertexAttrib1fARB             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB1FVARBPROC                         ,glVertexAttrib1fvARB            );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB1SARBPROC                          ,glVertexAttrib1sARB             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB1SVARBPROC                         ,glVertexAttrib1svARB            );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB2DARBPROC                          ,glVertexAttrib2dARB             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB2DVARBPROC                         ,glVertexAttrib2dvARB            );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB2FARBPROC                          ,glVertexAttrib2fARB             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB2FVARBPROC                         ,glVertexAttrib2fvARB            );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB2SARBPROC                          ,glVertexAttrib2sARB             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB2SVARBPROC                         ,glVertexAttrib2svARB            );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB3DARBPROC                          ,glVertexAttrib3dARB             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB3DVARBPROC                         ,glVertexAttrib3dvARB            );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB3FARBPROC                          ,glVertexAttrib3fARB             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB3FVARBPROC                         ,glVertexAttrib3fvARB            );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB3SARBPROC                          ,glVertexAttrib3sARB             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB3SVARBPROC                         ,glVertexAttrib3svARB            );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4NBVARBPROC                        ,glVertexAttrib4NbvARB           );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4NIVARBPROC                        ,glVertexAttrib4NivARB           );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4NSVARBPROC                        ,glVertexAttrib4NsvARB           );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4NUBARBPROC                        ,glVertexAttrib4NubARB           );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4NUBVARBPROC                       ,glVertexAttrib4NubvARB          );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4NUIVARBPROC                       ,glVertexAttrib4NuivARB          );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4NUSVARBPROC                       ,glVertexAttrib4NusvARB          );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4BVARBPROC                         ,glVertexAttrib4bvARB            );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4DARBPROC                          ,glVertexAttrib4dARB             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4DVARBPROC                         ,glVertexAttrib4dvARB            );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4FARBPROC                          ,glVertexAttrib4fARB             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4FVARBPROC                         ,glVertexAttrib4fvARB            );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4IVARBPROC                         ,glVertexAttrib4ivARB            );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4SARBPROC                          ,glVertexAttrib4sARB             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4SVARBPROC                         ,glVertexAttrib4svARB            );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4UBVARBPROC                        ,glVertexAttrib4ubvARB           );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4UIVARBPROC                        ,glVertexAttrib4uivARB           );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4USVARBPROC                        ,glVertexAttrib4usvARB           );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBPOINTERARBPROC                     ,glVertexAttribPointerARB        );
    GL_GetFuncEXT(PFNGLENABLEVERTEXATTRIBARRAYARBPROC                 ,glEnableVertexAttribArrayARB    );
    GL_GetFuncEXT(PFNGLDISABLEVERTEXATTRIBARRAYARBPROC                ,glDisableVertexAttribArrayARB   );
    GL_GetFuncEXT(PFNGLGETVERTEXATTRIBDVARBPROC                       ,glGetVertexAttribdvARB          );
    GL_GetFuncEXT(PFNGLGETVERTEXATTRIBFVARBPROC                       ,glGetVertexAttribfvARB          );
    GL_GetFuncEXT(PFNGLGETVERTEXATTRIBIVARBPROC                       ,glGetVertexAttribivARB          );
    GL_GetFuncEXT(PFNGLGETVERTEXATTRIBPOINTERVARBPROC                 ,glGetVertexAttribPointervARB    );
    #endif /* GL_ARB_vertex_program */

    #ifdef GL_ARB_vertex_shader
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_vertex_shader\n");
    GL_GetFuncEXT(PFNGLBINDATTRIBLOCATIONARBPROC                   ,glBindAttribLocationARB      );
    GL_GetFuncEXT(PFNGLGETACTIVEATTRIBARBPROC                      ,glGetActiveAttribARB         );
    GL_GetFuncEXT(PFNGLGETATTRIBLOCATIONARBPROC                    ,glGetAttribLocationARB       );
    #endif /* GL_ARB_vertex_shader */

    #ifdef GL_ARB_window_pos
	fprintf(LogGlGetFunctions_py, "\nGL_ARB_window_pos\n");
    GL_GetFuncEXT(PFNGLWINDOWPOS2DARBPROC                   ,glWindowPos2dARB       );
    GL_GetFuncEXT(PFNGLWINDOWPOS2DVARBPROC                  ,glWindowPos2dvARB      );
    GL_GetFuncEXT(PFNGLWINDOWPOS2FARBPROC                   ,glWindowPos2fARB       );
    GL_GetFuncEXT(PFNGLWINDOWPOS2FVARBPROC                  ,glWindowPos2fvARB      );
    GL_GetFuncEXT(PFNGLWINDOWPOS2IARBPROC                   ,glWindowPos2iARB       );
    GL_GetFuncEXT(PFNGLWINDOWPOS2IVARBPROC                  ,glWindowPos2ivARB      );
    GL_GetFuncEXT(PFNGLWINDOWPOS2SARBPROC                   ,glWindowPos2sARB       );
    GL_GetFuncEXT(PFNGLWINDOWPOS2SVARBPROC                  ,glWindowPos2svARB      );
    GL_GetFuncEXT(PFNGLWINDOWPOS3DARBPROC                   ,glWindowPos3dARB       );
    GL_GetFuncEXT(PFNGLWINDOWPOS3DVARBPROC                  ,glWindowPos3dvARB      );
    GL_GetFuncEXT(PFNGLWINDOWPOS3FARBPROC                   ,glWindowPos3fARB       );
    GL_GetFuncEXT(PFNGLWINDOWPOS3FVARBPROC                  ,glWindowPos3fvARB      );
    GL_GetFuncEXT(PFNGLWINDOWPOS3IARBPROC                   ,glWindowPos3iARB       );
    GL_GetFuncEXT(PFNGLWINDOWPOS3IVARBPROC                  ,glWindowPos3ivARB      );
    GL_GetFuncEXT(PFNGLWINDOWPOS3SARBPROC                   ,glWindowPos3sARB       );
    GL_GetFuncEXT(PFNGLWINDOWPOS3SVARBPROC                  ,glWindowPos3svARB      );
    #endif /* GL_ARB_window_pos */

	
	
    #ifdef GL_KHR_blend_equation_advanced
	fprintf(LogGlGetFunctions_py, "\nGL_KHR_blend_equation_advanced\n");
    GL_GetFuncEXT(PFNGLBLENDBARRIERKHRPROC                            ,glBlendBarrierKHR  );
    #endif /* GL_KHR_blend_equation_advanced */

    #ifdef GL_KHR_parallel_shader_compile
	fprintf(LogGlGetFunctions_py, "\nGL_KHR_parallel_shader_compile\n");
    GL_GetFuncEXT(PFNGLMAXSHADERCOMPILERTHREADSKHRPROC                     ,glMaxShaderCompilerThreadsKHR );
    #endif /* GL_KHR_parallel_shader_compile */

	

    #ifdef GL_OES_byte_coordinates
	fprintf(LogGlGetFunctions_py, "\nGL_OES_byte_coordinates\n");
    GL_GetFuncEXT(PFNGLMULTITEXCOORD1BOESPROC                    ,glMultiTexCoord1bOES        );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD1BVOESPROC                   ,glMultiTexCoord1bvOES       );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD2BOESPROC                    ,glMultiTexCoord2bOES        );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD2BVOESPROC                   ,glMultiTexCoord2bvOES       );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD3BOESPROC                    ,glMultiTexCoord3bOES        );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD3BVOESPROC                   ,glMultiTexCoord3bvOES       );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD4BOESPROC                    ,glMultiTexCoord4bOES        );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD4BVOESPROC                   ,glMultiTexCoord4bvOES       );
    GL_GetFuncEXT(PFNGLTEXCOORD1BOESPROC                         ,glTexCoord1bOES             );
    GL_GetFuncEXT(PFNGLTEXCOORD1BVOESPROC                        ,glTexCoord1bvOES            );
    GL_GetFuncEXT(PFNGLTEXCOORD2BOESPROC                         ,glTexCoord2bOES             );
    GL_GetFuncEXT(PFNGLTEXCOORD2BVOESPROC                        ,glTexCoord2bvOES            );
    GL_GetFuncEXT(PFNGLTEXCOORD3BOESPROC                         ,glTexCoord3bOES             );
    GL_GetFuncEXT(PFNGLTEXCOORD3BVOESPROC                        ,glTexCoord3bvOES            );
    GL_GetFuncEXT(PFNGLTEXCOORD4BOESPROC                         ,glTexCoord4bOES             );
    GL_GetFuncEXT(PFNGLTEXCOORD4BVOESPROC                        ,glTexCoord4bvOES            );
    GL_GetFuncEXT(PFNGLVERTEX2BOESPROC                           ,glVertex2bOES               );
    GL_GetFuncEXT(PFNGLVERTEX2BVOESPROC                          ,glVertex2bvOES              );
    GL_GetFuncEXT(PFNGLVERTEX3BOESPROC                           ,glVertex3bOES               );
    GL_GetFuncEXT(PFNGLVERTEX3BVOESPROC                          ,glVertex3bvOES              );
    GL_GetFuncEXT(PFNGLVERTEX4BOESPROC                           ,glVertex4bOES               );
    GL_GetFuncEXT(PFNGLVERTEX4BVOESPROC                          ,glVertex4bvOES              );
    #endif /* GL_OES_byte_coordinates */

    #ifdef GL_OES_fixed_point
	fprintf(LogGlGetFunctions_py, "\nGL_OES_fixed_point\n");
    GL_GetFuncEXT(PFNGLALPHAFUNCXOESPROC                               ,glAlphaFuncxOES                   );
    GL_GetFuncEXT(PFNGLCLEARCOLORXOESPROC                              ,glClearColorxOES                  );
    GL_GetFuncEXT(PFNGLCLEARDEPTHXOESPROC                              ,glClearDepthxOES                  );
    GL_GetFuncEXT(PFNGLCLIPPLANEXOESPROC                               ,glClipPlanexOES                   );
    GL_GetFuncEXT(PFNGLCOLOR4XOESPROC                                  ,glColor4xOES                      );
    GL_GetFuncEXT(PFNGLDEPTHRANGEXOESPROC                              ,glDepthRangexOES                  );
    GL_GetFuncEXT(PFNGLFOGXOESPROC                                     ,glFogxOES                         );
    GL_GetFuncEXT(PFNGLFOGXVOESPROC                                    ,glFogxvOES                        );
    GL_GetFuncEXT(PFNGLFRUSTUMXOESPROC                                 ,glFrustumxOES                     );
    GL_GetFuncEXT(PFNGLGETCLIPPLANEXOESPROC                            ,glGetClipPlanexOES                );
    GL_GetFuncEXT(PFNGLGETFIXEDVOESPROC                                ,glGetFixedvOES                    );
    GL_GetFuncEXT(PFNGLGETTEXENVXVOESPROC                              ,glGetTexEnvxvOES                  );
    GL_GetFuncEXT(PFNGLGETTEXPARAMETERXVOESPROC                        ,glGetTexParameterxvOES            );
    GL_GetFuncEXT(PFNGLLIGHTMODELXOESPROC                              ,glLightModelxOES                  );
    GL_GetFuncEXT(PFNGLLIGHTMODELXVOESPROC                             ,glLightModelxvOES                 );
    GL_GetFuncEXT(PFNGLLIGHTXOESPROC                                   ,glLightxOES                       );
    GL_GetFuncEXT(PFNGLLIGHTXVOESPROC                                  ,glLightxvOES                      );
    GL_GetFuncEXT(PFNGLLINEWIDTHXOESPROC                               ,glLineWidthxOES                   );
    GL_GetFuncEXT(PFNGLLOADMATRIXXOESPROC                              ,glLoadMatrixxOES                  );
    GL_GetFuncEXT(PFNGLMATERIALXOESPROC                                ,glMaterialxOES                    );
    GL_GetFuncEXT(PFNGLMATERIALXVOESPROC                               ,glMaterialxvOES                   );
    GL_GetFuncEXT(PFNGLMULTMATRIXXOESPROC                              ,glMultMatrixxOES                  );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD4XOESPROC                          ,glMultiTexCoord4xOES              );
    GL_GetFuncEXT(PFNGLNORMAL3XOESPROC                                 ,glNormal3xOES                     );
    GL_GetFuncEXT(PFNGLORTHOXOESPROC                                   ,glOrthoxOES                       );
    GL_GetFuncEXT(PFNGLPOINTPARAMETERXVOESPROC                         ,glPointParameterxvOES             );
    GL_GetFuncEXT(PFNGLPOINTSIZEXOESPROC                               ,glPointSizexOES                   );
    GL_GetFuncEXT(PFNGLPOLYGONOFFSETXOESPROC                           ,glPolygonOffsetxOES               );
    GL_GetFuncEXT(PFNGLROTATEXOESPROC                                  ,glRotatexOES                      );
    GL_GetFuncEXT(PFNGLSCALEXOESPROC                                   ,glScalexOES                       );
    GL_GetFuncEXT(PFNGLTEXENVXOESPROC                                  ,glTexEnvxOES                      );
    GL_GetFuncEXT(PFNGLTEXENVXVOESPROC                                 ,glTexEnvxvOES                     );
    GL_GetFuncEXT(PFNGLTEXPARAMETERXOESPROC                            ,glTexParameterxOES                );
    GL_GetFuncEXT(PFNGLTEXPARAMETERXVOESPROC                           ,glTexParameterxvOES               );
    GL_GetFuncEXT(PFNGLTRANSLATEXOESPROC                               ,glTranslatexOES                   );
    GL_GetFuncEXT(PFNGLACCUMXOESPROC                                   ,glAccumxOES                       );
    GL_GetFuncEXT(PFNGLBITMAPXOESPROC                                  ,glBitmapxOES                      );
    GL_GetFuncEXT(PFNGLBLENDCOLORXOESPROC                              ,glBlendColorxOES                  );
    GL_GetFuncEXT(PFNGLCLEARACCUMXOESPROC                              ,glClearAccumxOES                  );
    GL_GetFuncEXT(PFNGLCOLOR3XOESPROC                                  ,glColor3xOES                      );
    GL_GetFuncEXT(PFNGLCOLOR3XVOESPROC                                 ,glColor3xvOES                     );
    GL_GetFuncEXT(PFNGLCOLOR4XVOESPROC                                 ,glColor4xvOES                     );
    GL_GetFuncEXT(PFNGLCONVOLUTIONPARAMETERXOESPROC                    ,glConvolutionParameterxOES        );
    GL_GetFuncEXT(PFNGLCONVOLUTIONPARAMETERXVOESPROC                   ,glConvolutionParameterxvOES       );
    GL_GetFuncEXT(PFNGLEVALCOORD1XOESPROC                              ,glEvalCoord1xOES                  );
    GL_GetFuncEXT(PFNGLEVALCOORD1XVOESPROC                             ,glEvalCoord1xvOES                 );
    GL_GetFuncEXT(PFNGLEVALCOORD2XOESPROC                              ,glEvalCoord2xOES                  );
    GL_GetFuncEXT(PFNGLEVALCOORD2XVOESPROC                             ,glEvalCoord2xvOES                 );
    GL_GetFuncEXT(PFNGLFEEDBACKBUFFERXOESPROC                          ,glFeedbackBufferxOES              );
    GL_GetFuncEXT(PFNGLGETCONVOLUTIONPARAMETERXVOESPROC                ,glGetConvolutionParameterxvOES    );
    GL_GetFuncEXT(PFNGLGETHISTOGRAMPARAMETERXVOESPROC                  ,glGetHistogramParameterxvOES      );
    GL_GetFuncEXT(PFNGLGETLIGHTXOESPROC                                ,glGetLightxOES                    );
    GL_GetFuncEXT(PFNGLGETMAPXVOESPROC                                 ,glGetMapxvOES                     );
    GL_GetFuncEXT(PFNGLGETMATERIALXOESPROC                             ,glGetMaterialxOES                 );
    GL_GetFuncEXT(PFNGLGETPIXELMAPXVPROC                               ,glGetPixelMapxv                   );
    GL_GetFuncEXT(PFNGLGETTEXGENXVOESPROC                              ,glGetTexGenxvOES                  );
    GL_GetFuncEXT(PFNGLGETTEXLEVELPARAMETERXVOESPROC                   ,glGetTexLevelParameterxvOES       );
    GL_GetFuncEXT(PFNGLINDEXXOESPROC                                   ,glIndexxOES                       );
    GL_GetFuncEXT(PFNGLINDEXXVOESPROC                                  ,glIndexxvOES                      );
    GL_GetFuncEXT(PFNGLLOADTRANSPOSEMATRIXXOESPROC                     ,glLoadTransposeMatrixxOES         );
    GL_GetFuncEXT(PFNGLMAP1XOESPROC                                    ,glMap1xOES                        );
    GL_GetFuncEXT(PFNGLMAP2XOESPROC                                    ,glMap2xOES                        );
    GL_GetFuncEXT(PFNGLMAPGRID1XOESPROC                                ,glMapGrid1xOES                    );
    GL_GetFuncEXT(PFNGLMAPGRID2XOESPROC                                ,glMapGrid2xOES                    );
    GL_GetFuncEXT(PFNGLMULTTRANSPOSEMATRIXXOESPROC                     ,glMultTransposeMatrixxOES         );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD1XOESPROC                          ,glMultiTexCoord1xOES              );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD1XVOESPROC                         ,glMultiTexCoord1xvOES             );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD2XOESPROC                          ,glMultiTexCoord2xOES              );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD2XVOESPROC                         ,glMultiTexCoord2xvOES             );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD3XOESPROC                          ,glMultiTexCoord3xOES              );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD3XVOESPROC                         ,glMultiTexCoord3xvOES             );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD4XVOESPROC                         ,glMultiTexCoord4xvOES             );
    GL_GetFuncEXT(PFNGLNORMAL3XVOESPROC                                ,glNormal3xvOES                    );
    GL_GetFuncEXT(PFNGLPASSTHROUGHXOESPROC                             ,glPassThroughxOES                 );
    GL_GetFuncEXT(PFNGLPIXELMAPXPROC                                   ,glPixelMapx                       );
    GL_GetFuncEXT(PFNGLPIXELSTOREXPROC                                 ,glPixelStorex                     );
    GL_GetFuncEXT(PFNGLPIXELTRANSFERXOESPROC                           ,glPixelTransferxOES               );
    GL_GetFuncEXT(PFNGLPIXELZOOMXOESPROC                               ,glPixelZoomxOES                   );
    GL_GetFuncEXT(PFNGLPRIORITIZETEXTURESXOESPROC                      ,glPrioritizeTexturesxOES          );
    GL_GetFuncEXT(PFNGLRASTERPOS2XOESPROC                              ,glRasterPos2xOES                  );
    GL_GetFuncEXT(PFNGLRASTERPOS2XVOESPROC                             ,glRasterPos2xvOES                 );
    GL_GetFuncEXT(PFNGLRASTERPOS3XOESPROC                              ,glRasterPos3xOES                  );
    GL_GetFuncEXT(PFNGLRASTERPOS3XVOESPROC                             ,glRasterPos3xvOES                 );
    GL_GetFuncEXT(PFNGLRASTERPOS4XOESPROC                              ,glRasterPos4xOES                  );
    GL_GetFuncEXT(PFNGLRASTERPOS4XVOESPROC                             ,glRasterPos4xvOES                 );
    GL_GetFuncEXT(PFNGLRECTXOESPROC                                    ,glRectxOES                        );
    GL_GetFuncEXT(PFNGLRECTXVOESPROC                                   ,glRectxvOES                       );
    GL_GetFuncEXT(PFNGLTEXCOORD1XOESPROC                               ,glTexCoord1xOES                   );
    GL_GetFuncEXT(PFNGLTEXCOORD1XVOESPROC                              ,glTexCoord1xvOES                  );
    GL_GetFuncEXT(PFNGLTEXCOORD2XOESPROC                               ,glTexCoord2xOES                   );
    GL_GetFuncEXT(PFNGLTEXCOORD2XVOESPROC                              ,glTexCoord2xvOES                  );
    GL_GetFuncEXT(PFNGLTEXCOORD3XOESPROC                               ,glTexCoord3xOES                   );
    GL_GetFuncEXT(PFNGLTEXCOORD3XVOESPROC                              ,glTexCoord3xvOES                  );
    GL_GetFuncEXT(PFNGLTEXCOORD4XOESPROC                               ,glTexCoord4xOES                   );
    GL_GetFuncEXT(PFNGLTEXCOORD4XVOESPROC                              ,glTexCoord4xvOES                  );
    GL_GetFuncEXT(PFNGLTEXGENXOESPROC                                  ,glTexGenxOES                      );
    GL_GetFuncEXT(PFNGLTEXGENXVOESPROC                                 ,glTexGenxvOES                     );
    GL_GetFuncEXT(PFNGLVERTEX2XOESPROC                                 ,glVertex2xOES                     );
    GL_GetFuncEXT(PFNGLVERTEX2XVOESPROC                                ,glVertex2xvOES                    );
    GL_GetFuncEXT(PFNGLVERTEX3XOESPROC                                 ,glVertex3xOES                     );
    GL_GetFuncEXT(PFNGLVERTEX3XVOESPROC                                ,glVertex3xvOES                    );
    GL_GetFuncEXT(PFNGLVERTEX4XOESPROC                                 ,glVertex4xOES                     );
    GL_GetFuncEXT(PFNGLVERTEX4XVOESPROC                                ,glVertex4xvOES                    );
    #endif /* GL_OES_fixed_point */

    #ifdef GL_OES_query_matrix
	fprintf(LogGlGetFunctions_py, "\nGL_OES_query_matrix\n");
    GL_GetFuncEXT(PFNGLQUERYMATRIXXOESPROC                     ,glQueryMatrixxOES );
    #endif /* GL_OES_query_matrix */

    #ifdef GL_OES_single_precision
	fprintf(LogGlGetFunctions_py, "\nGL_OES_single_precision\n");
    GL_GetFuncEXT(PFNGLCLEARDEPTHFOESPROC                      ,glClearDepthfOES           );
    GL_GetFuncEXT(PFNGLCLIPPLANEFOESPROC                       ,glClipPlanefOES            );
    GL_GetFuncEXT(PFNGLDEPTHRANGEFOESPROC                      ,glDepthRangefOES           );
    GL_GetFuncEXT(PFNGLFRUSTUMFOESPROC                         ,glFrustumfOES              );
    GL_GetFuncEXT(PFNGLGETCLIPPLANEFOESPROC                    ,glGetClipPlanefOES         );
    GL_GetFuncEXT(PFNGLORTHOFOESPROC                           ,glOrthofOES                );
    #endif /* GL_OES_single_precision */


	
    #ifdef GL_3DFX_tbuffer
	fprintf(LogGlGetFunctions_py, "\nGL_3DFX_tbuffer\n");
    GL_GetFuncEXT(PFNGLTBUFFERMASK3DFXPROC                     ,glTbufferMask3DFX );
    #endif /* GL_3DFX_tbuffer */

	
	
    #ifdef GL_AMD_debug_output
	fprintf(LogGlGetFunctions_py, "\nGL_AMD_debug_output\n");
    GL_GetFuncEXT(PFNGLDEBUGMESSAGEENABLEAMDPROC                       ,glDebugMessageEnableAMD          );
    GL_GetFuncEXT(PFNGLDEBUGMESSAGEINSERTAMDPROC                       ,glDebugMessageInsertAMD          );
    GL_GetFuncEXT(PFNGLDEBUGMESSAGECALLBACKAMDPROC                     ,glDebugMessageCallbackAMD        );
    GL_GetFuncEXT(PFNGLGETDEBUGMESSAGELOGAMDPROC                       ,glGetDebugMessageLogAMD          );
    #endif /* GL_AMD_debug_output */

    #ifdef GL_AMD_draw_buffers_blend
	fprintf(LogGlGetFunctions_py, "\nGL_AMD_draw_buffers_blend\n");
    GL_GetFuncEXT(PFNGLBLENDFUNCINDEXEDAMDPROC                              ,glBlendFuncIndexedAMD                 );
    GL_GetFuncEXT(PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC                      ,glBlendFuncSeparateIndexedAMD         );
    GL_GetFuncEXT(PFNGLBLENDEQUATIONINDEXEDAMDPROC                          ,glBlendEquationIndexedAMD             );
    GL_GetFuncEXT(PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC                  ,glBlendEquationSeparateIndexedAMD     );
    #endif /* GL_AMD_draw_buffers_blend */

    #ifdef GL_AMD_framebuffer_sample_positions
	fprintf(LogGlGetFunctions_py, "\nGL_AMD_framebuffer_sample_positions\n");
    GL_GetFuncEXT(PFNGLFRAMEBUFFERSAMPLEPOSITIONSFVAMDPROC                      ,glFramebufferSamplePositionsfvAMD           );
    GL_GetFuncEXT(PFNGLNAMEDFRAMEBUFFERSAMPLEPOSITIONSFVAMDPROC                 ,glNamedFramebufferSamplePositionsfvAMD      );
    GL_GetFuncEXT(PFNGLGETFRAMEBUFFERPARAMETERFVAMDPROC                         ,glGetFramebufferParameterfvAMD              );
    GL_GetFuncEXT(PFNGLGETNAMEDFRAMEBUFFERPARAMETERFVAMDPROC                    ,glGetNamedFramebufferParameterfvAMD         );
    #endif /* GL_AMD_framebuffer_sample_positions */

    #ifdef GL_AMD_gpu_shader_int64
	fprintf(LogGlGetFunctions_py, "\nGL_AMD_gpu_shader_int64\n");
    GL_GetFuncEXT(PFNGLUNIFORM1I64NVPROC                              ,glUniform1i64NV                );
    GL_GetFuncEXT(PFNGLUNIFORM2I64NVPROC                              ,glUniform2i64NV                );
    GL_GetFuncEXT(PFNGLUNIFORM3I64NVPROC                              ,glUniform3i64NV                );
    GL_GetFuncEXT(PFNGLUNIFORM4I64NVPROC                              ,glUniform4i64NV                );
    GL_GetFuncEXT(PFNGLUNIFORM1I64VNVPROC                             ,glUniform1i64vNV               );
    GL_GetFuncEXT(PFNGLUNIFORM2I64VNVPROC                             ,glUniform2i64vNV               );
    GL_GetFuncEXT(PFNGLUNIFORM3I64VNVPROC                             ,glUniform3i64vNV               );
    GL_GetFuncEXT(PFNGLUNIFORM4I64VNVPROC                             ,glUniform4i64vNV               );
    GL_GetFuncEXT(PFNGLUNIFORM1UI64NVPROC                             ,glUniform1ui64NV               );
    GL_GetFuncEXT(PFNGLUNIFORM2UI64NVPROC                             ,glUniform2ui64NV               );
    GL_GetFuncEXT(PFNGLUNIFORM3UI64NVPROC                             ,glUniform3ui64NV               );
    GL_GetFuncEXT(PFNGLUNIFORM4UI64NVPROC                             ,glUniform4ui64NV               );
    GL_GetFuncEXT(PFNGLUNIFORM1UI64VNVPROC                            ,glUniform1ui64vNV              );
    GL_GetFuncEXT(PFNGLUNIFORM2UI64VNVPROC                            ,glUniform2ui64vNV              );
    GL_GetFuncEXT(PFNGLUNIFORM3UI64VNVPROC                            ,glUniform3ui64vNV              );
    GL_GetFuncEXT(PFNGLUNIFORM4UI64VNVPROC                            ,glUniform4ui64vNV              );
    GL_GetFuncEXT(PFNGLGETUNIFORMI64VNVPROC                           ,glGetUniformi64vNV             );
    GL_GetFuncEXT(PFNGLGETUNIFORMUI64VNVPROC                          ,glGetUniformui64vNV            );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM1I64NVPROC                       ,glProgramUniform1i64NV         );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM2I64NVPROC                       ,glProgramUniform2i64NV         );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM3I64NVPROC                       ,glProgramUniform3i64NV         );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM4I64NVPROC                       ,glProgramUniform4i64NV         );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM1I64VNVPROC                      ,glProgramUniform1i64vNV        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM2I64VNVPROC                      ,glProgramUniform2i64vNV        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM3I64VNVPROC                      ,glProgramUniform3i64vNV        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM4I64VNVPROC                      ,glProgramUniform4i64vNV        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM1UI64NVPROC                      ,glProgramUniform1ui64NV        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM2UI64NVPROC                      ,glProgramUniform2ui64NV        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM3UI64NVPROC                      ,glProgramUniform3ui64NV        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM4UI64NVPROC                      ,glProgramUniform4ui64NV        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM1UI64VNVPROC                     ,glProgramUniform1ui64vNV       );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM2UI64VNVPROC                     ,glProgramUniform2ui64vNV       );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM3UI64VNVPROC                     ,glProgramUniform3ui64vNV       );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM4UI64VNVPROC                     ,glProgramUniform4ui64vNV       );
    #endif /* GL_AMD_gpu_shader_int64 */

    #ifdef GL_AMD_interleaved_elements
	fprintf(LogGlGetFunctions_py, "\nGL_AMD_interleaved_elements\n");
    GL_GetFuncEXT(PFNGLVERTEXATTRIBPARAMETERIAMDPROC                   ,glVertexAttribParameteriAMD );
    #endif /* GL_AMD_interleaved_elements */

    #ifdef GL_AMD_multi_draw_indirect
	fprintf(LogGlGetFunctions_py, "\nGL_AMD_multi_draw_indirect\n");
    GL_GetFuncEXT(PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC                  ,glMultiDrawArraysIndirectAMD    );
    GL_GetFuncEXT(PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC                ,glMultiDrawElementsIndirectAMD  );
    #endif /* GL_AMD_multi_draw_indirect */

    #ifdef GL_AMD_name_gen_delete
	fprintf(LogGlGetFunctions_py, "\nGL_AMD_name_gen_delete\n");
    GL_GetFuncEXT(PFNGLGENNAMESAMDPROC                  ,glGenNamesAMD       );
    GL_GetFuncEXT(PFNGLDELETENAMESAMDPROC               ,glDeleteNamesAMD    );
    GL_GetFuncEXT(PFNGLISNAMEAMDPROC                    ,glIsNameAMD         );
        #endif /* GL_AMD_name_gen_delete */

    #ifdef GL_AMD_occlusion_query_event
	fprintf(LogGlGetFunctions_py, "\nGL_AMD_occlusion_query_event\n");
    GL_GetFuncEXT(PFNGLQUERYOBJECTPARAMETERUIAMDPROC                ,glQueryObjectParameteruiAMD );
    #endif /* GL_AMD_occlusion_query_event */

    #ifdef GL_AMD_performance_monitor
	fprintf(LogGlGetFunctions_py, "\nGL_AMD_performance_monitor\n");
    GL_GetFuncEXT(PFNGLGETPERFMONITORGROUPSAMDPROC                           ,glGetPerfMonitorGroupsAMD             );
    GL_GetFuncEXT(PFNGLGETPERFMONITORCOUNTERSAMDPROC                         ,glGetPerfMonitorCountersAMD           );
    GL_GetFuncEXT(PFNGLGETPERFMONITORGROUPSTRINGAMDPROC                      ,glGetPerfMonitorGroupStringAMD        );
    GL_GetFuncEXT(PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC                    ,glGetPerfMonitorCounterStringAMD      );
    GL_GetFuncEXT(PFNGLGETPERFMONITORCOUNTERINFOAMDPROC                      ,glGetPerfMonitorCounterInfoAMD        );
    GL_GetFuncEXT(PFNGLGENPERFMONITORSAMDPROC                                ,glGenPerfMonitorsAMD                  );
    GL_GetFuncEXT(PFNGLDELETEPERFMONITORSAMDPROC                             ,glDeletePerfMonitorsAMD               );
    GL_GetFuncEXT(PFNGLSELECTPERFMONITORCOUNTERSAMDPROC                      ,glSelectPerfMonitorCountersAMD        );
    GL_GetFuncEXT(PFNGLBEGINPERFMONITORAMDPROC                               ,glBeginPerfMonitorAMD                 );
    GL_GetFuncEXT(PFNGLENDPERFMONITORAMDPROC                                 ,glEndPerfMonitorAMD                   );
    GL_GetFuncEXT(PFNGLGETPERFMONITORCOUNTERDATAAMDPROC                      ,glGetPerfMonitorCounterDataAMD        );
    #endif /* GL_AMD_performance_monitor */

    #ifdef GL_AMD_sample_positions
	fprintf(LogGlGetFunctions_py, "\nGL_AMD_sample_positions\n");
    GL_GetFuncEXT(PFNGLSETMULTISAMPLEFVAMDPROC                     ,glSetMultisamplefvAMD );
    #endif /* GL_AMD_sample_positions */

    #ifdef GL_AMD_sparse_texture
	fprintf(LogGlGetFunctions_py, "\nGL_AMD_sparse_texture\n");
    GL_GetFuncEXT(PFNGLTEXSTORAGESPARSEAMDPROC                     ,glTexStorageSparseAMD      );
    GL_GetFuncEXT(PFNGLTEXTURESTORAGESPARSEAMDPROC                 ,glTextureStorageSparseAMD  );
    #endif /* GL_AMD_sparse_texture */

    #ifdef GL_AMD_stencil_operation_extended
	fprintf(LogGlGetFunctions_py, "\nGL_AMD_stencil_operation_extended\n");
    GL_GetFuncEXT(PFNGLSTENCILOPVALUEAMDPROC                  ,glStencilOpValueAMD );
    #endif /* GL_AMD_stencil_operation_extended */

    #ifdef GL_AMD_vertex_shader_tessellator
	fprintf(LogGlGetFunctions_py, "\nGL_AMD_vertex_shader_tessellator\n");
    GL_GetFuncEXT(PFNGLTESSELLATIONFACTORAMDPROC               ,glTessellationFactorAMD );
    GL_GetFuncEXT(PFNGLTESSELLATIONMODEAMDPROC                 ,glTessellationModeAMD   );
    #endif /* GL_AMD_vertex_shader_tessellator */

	

    #ifdef GL_APPLE_element_array
	fprintf(LogGlGetFunctions_py, "\nGL_APPLE_element_array\n");
    GL_GetFuncEXT(PFNGLELEMENTPOINTERAPPLEPROC                              ,glElementPointerAPPLE                  );
    GL_GetFuncEXT(PFNGLDRAWELEMENTARRAYAPPLEPROC                            ,glDrawElementArrayAPPLE                );
    GL_GetFuncEXT(PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC                       ,glDrawRangeElementArrayAPPLE           );
    GL_GetFuncEXT(PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC                       ,glMultiDrawElementArrayAPPLE           );
    GL_GetFuncEXT(PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC                  ,glMultiDrawRangeElementArrayAPPLE      );
    #endif /* GL_APPLE_element_array */

    #ifdef GL_APPLE_fence
	fprintf(LogGlGetFunctions_py, "\nGL_APPLE_fence\n");
    GL_GetFuncEXT(PFNGLGENFENCESAPPLEPROC                      ,glGenFencesAPPLE          );
    GL_GetFuncEXT(PFNGLDELETEFENCESAPPLEPROC                   ,glDeleteFencesAPPLE       );
    GL_GetFuncEXT(PFNGLSETFENCEAPPLEPROC                       ,glSetFenceAPPLE           );
    GL_GetFuncEXT(PFNGLISFENCEAPPLEPROC                        ,glIsFenceAPPLE            );
    GL_GetFuncEXT(PFNGLTESTFENCEAPPLEPROC                      ,glTestFenceAPPLE          );
    GL_GetFuncEXT(PFNGLFINISHFENCEAPPLEPROC                    ,glFinishFenceAPPLE        );
    GL_GetFuncEXT(PFNGLTESTOBJECTAPPLEPROC                     ,glTestObjectAPPLE         );
    GL_GetFuncEXT(PFNGLFINISHOBJECTAPPLEPROC                   ,glFinishObjectAPPLE       );
    #endif /* GL_APPLE_fence */
	
    #ifdef GL_APPLE_flush_buffer_range
	fprintf(LogGlGetFunctions_py, "\nGL_APPLE_flush_buffer_range\n");
    GL_GetFuncEXT(PFNGLBUFFERPARAMETERIAPPLEPROC                     ,glBufferParameteriAPPLE         );
    GL_GetFuncEXT(PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC               ,glFlushMappedBufferRangeAPPLE   );
    #endif /* GL_APPLE_flush_buffer_range */

    #ifdef GL_APPLE_object_purgeable
	fprintf(LogGlGetFunctions_py, "\nGL_APPLE_object_purgeable\n");
    GL_GetFuncEXT(PFNGLOBJECTPURGEABLEAPPLEPROC                     ,glObjectPurgeableAPPLE       );
    GL_GetFuncEXT(PFNGLOBJECTUNPURGEABLEAPPLEPROC                   ,glObjectUnpurgeableAPPLE     );
    GL_GetFuncEXT(PFNGLGETOBJECTPARAMETERIVAPPLEPROC                ,glGetObjectParameterivAPPLE  );
    #endif /* GL_APPLE_object_purgeable */

    #ifdef GL_APPLE_texture_range
	fprintf(LogGlGetFunctions_py, "\nGL_APPLE_texture_range\n");
    GL_GetFuncEXT(PFNGLTEXTURERANGEAPPLEPROC                            ,glTextureRangeAPPLE             );
    GL_GetFuncEXT(PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC                 ,glGetTexParameterPointervAPPLE  );
        #endif /* GL_APPLE_texture_range */

    #ifdef GL_APPLE_vertex_array_object
	fprintf(LogGlGetFunctions_py, "\nGL_APPLE_vertex_array_object\n");
    GL_GetFuncEXT(PFNGLBINDVERTEXARRAYAPPLEPROC                     ,glBindVertexArrayAPPLE        );
    GL_GetFuncEXT(PFNGLDELETEVERTEXARRAYSAPPLEPROC                  ,glDeleteVertexArraysAPPLE     );
    GL_GetFuncEXT(PFNGLGENVERTEXARRAYSAPPLEPROC                     ,glGenVertexArraysAPPLE        );
    GL_GetFuncEXT(PFNGLISVERTEXARRAYAPPLEPROC                       ,glIsVertexArrayAPPLE          );
    #endif /* GL_APPLE_vertex_array_object */

    #ifdef GL_APPLE_vertex_array_range
	fprintf(LogGlGetFunctions_py, "\nGL_APPLE_vertex_array_range\n");
    GL_GetFuncEXT(PFNGLVERTEXARRAYRANGEAPPLEPROC                       ,glVertexArrayRangeAPPLE          );
    GL_GetFuncEXT(PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC                  ,glFlushVertexArrayRangeAPPLE     );
    GL_GetFuncEXT(PFNGLVERTEXARRAYPARAMETERIAPPLEPROC                  ,glVertexArrayParameteriAPPLE     );
    #endif /* GL_APPLE_vertex_array_range */

    #ifdef GL_APPLE_vertex_program_evaluators
	fprintf(LogGlGetFunctions_py, "\nGL_APPLE_vertex_program_evaluators\n");
    GL_GetFuncEXT(PFNGLENABLEVERTEXATTRIBAPPLEPROC                     ,glEnableVertexAttribAPPLE       );
    GL_GetFuncEXT(PFNGLDISABLEVERTEXATTRIBAPPLEPROC                    ,glDisableVertexAttribAPPLE      );
    GL_GetFuncEXT(PFNGLISVERTEXATTRIBENABLEDAPPLEPROC                  ,glIsVertexAttribEnabledAPPLE    );
    GL_GetFuncEXT(PFNGLMAPVERTEXATTRIB1DAPPLEPROC                      ,glMapVertexAttrib1dAPPLE        );
    GL_GetFuncEXT(PFNGLMAPVERTEXATTRIB1FAPPLEPROC                      ,glMapVertexAttrib1fAPPLE        );
    GL_GetFuncEXT(PFNGLMAPVERTEXATTRIB2DAPPLEPROC                      ,glMapVertexAttrib2dAPPLE        );
    GL_GetFuncEXT(PFNGLMAPVERTEXATTRIB2FAPPLEPROC                      ,glMapVertexAttrib2fAPPLE        );
    #endif /* GL_APPLE_vertex_program_evaluators */


	
    #ifdef GL_ATI_draw_buffers
	fprintf(LogGlGetFunctions_py, "\nGL_ATI_draw_buffers\n");
    GL_GetFuncEXT(PFNGLDRAWBUFFERSATIPROC                         ,glDrawBuffersATI );
    #endif /* GL_ATI_draw_buffers */

    #ifdef GL_ATI_element_array
	fprintf(LogGlGetFunctions_py, "\nGL_ATI_element_array\n");
	GL_GetFuncEXT(PFNGLELEMENTPOINTERATIPROC                      ,glElementPointerATI          );
	GL_GetFuncEXT(PFNGLDRAWELEMENTARRAYATIPROC                    ,glDrawElementArrayATI        );
	GL_GetFuncEXT(PFNGLDRAWRANGEELEMENTARRAYATIPROC               ,glDrawRangeElementArrayATI   );
    #endif /* GL_ATI_element_array */

    #ifdef GL_ATI_envmap_bumpmap
	fprintf(LogGlGetFunctions_py, "\nGL_ATI_envmap_bumpmap\n");
	GL_GetFuncEXT(PFNGLTEXBUMPPARAMETERIVATIPROC                  ,glTexBumpParameterivATI          );
	GL_GetFuncEXT(PFNGLTEXBUMPPARAMETERFVATIPROC                  ,glTexBumpParameterfvATI          );
	GL_GetFuncEXT(PFNGLGETTEXBUMPPARAMETERIVATIPROC               ,glGetTexBumpParameterivATI       );
	GL_GetFuncEXT(PFNGLGETTEXBUMPPARAMETERFVATIPROC               ,glGetTexBumpParameterfvATI       );
    #endif /* GL_ATI_envmap_bumpmap */

    #ifdef GL_ATI_fragment_shader
	fprintf(LogGlGetFunctions_py, "\nGL_ATI_fragment_shader\n");
    GL_GetFuncEXT(PFNGLGENFRAGMENTSHADERSATIPROC                           ,glGenFragmentShadersATI                );
    GL_GetFuncEXT(PFNGLBINDFRAGMENTSHADERATIPROC                           ,glBindFragmentShaderATI                );
    GL_GetFuncEXT(PFNGLDELETEFRAGMENTSHADERATIPROC                         ,glDeleteFragmentShaderATI              );
    GL_GetFuncEXT(PFNGLBEGINFRAGMENTSHADERATIPROC                          ,glBeginFragmentShaderATI               );
    GL_GetFuncEXT(PFNGLENDFRAGMENTSHADERATIPROC                            ,glEndFragmentShaderATI                 );
    GL_GetFuncEXT(PFNGLPASSTEXCOORDATIPROC                                 ,glPassTexCoordATI                      );
    GL_GetFuncEXT(PFNGLSAMPLEMAPATIPROC                                    ,glSampleMapATI                         );
    GL_GetFuncEXT(PFNGLCOLORFRAGMENTOP1ATIPROC                             ,glColorFragmentOp1ATI                  );
    GL_GetFuncEXT(PFNGLCOLORFRAGMENTOP2ATIPROC                             ,glColorFragmentOp2ATI                  );
    GL_GetFuncEXT(PFNGLCOLORFRAGMENTOP3ATIPROC                             ,glColorFragmentOp3ATI                  );
    GL_GetFuncEXT(PFNGLALPHAFRAGMENTOP1ATIPROC                             ,glAlphaFragmentOp1ATI                  );
    GL_GetFuncEXT(PFNGLALPHAFRAGMENTOP2ATIPROC                             ,glAlphaFragmentOp2ATI                  );
    GL_GetFuncEXT(PFNGLALPHAFRAGMENTOP3ATIPROC                             ,glAlphaFragmentOp3ATI                  );
    GL_GetFuncEXT(PFNGLSETFRAGMENTSHADERCONSTANTATIPROC                    ,glSetFragmentShaderConstantATI         );
    #endif /* GL_ATI_fragment_shader */

    #ifdef GL_ATI_map_object_buffer
	fprintf(LogGlGetFunctions_py, "\nGL_ATI_map_object_buffer\n");
    GL_GetFuncEXT(PFNGLMAPOBJECTBUFFERATIPROC                     ,glMapObjectBufferATI     );
    GL_GetFuncEXT(PFNGLUNMAPOBJECTBUFFERATIPROC                   ,glUnmapObjectBufferATI   );
    #endif /* GL_ATI_map_object_buffer */

    #ifdef GL_ATI_pn_triangles
	fprintf(LogGlGetFunctions_py, "\nGL_ATI_pn_triangles\n");
    GL_GetFuncEXT(PFNGLPNTRIANGLESIATIPROC                        ,glPNTrianglesiATI   );
    GL_GetFuncEXT(PFNGLPNTRIANGLESFATIPROC                        ,glPNTrianglesfATI   );
    #endif /* GL_ATI_pn_triangles */

    #ifdef GL_ATI_separate_stencil
	fprintf(LogGlGetFunctions_py, "\nGL_ATI_separate_stencil\n");
    GL_GetFuncEXT(PFNGLSTENCILOPSEPARATEATIPROC                   ,glStencilOpSeparateATI   );
    GL_GetFuncEXT(PFNGLSTENCILFUNCSEPARATEATIPROC                 ,glStencilFuncSeparateATI );
    #endif /* GL_ATI_separate_stencil */

    #ifdef GL_ATI_vertex_array_object
	fprintf(LogGlGetFunctions_py, "\nGL_ATI_vertex_array_object\n");
    GL_GetFuncEXT(PFNGLNEWOBJECTBUFFERATIPROC                           ,glNewObjectBufferATI               );
    GL_GetFuncEXT(PFNGLISOBJECTBUFFERATIPROC                            ,glIsObjectBufferATI                );
    GL_GetFuncEXT(PFNGLUPDATEOBJECTBUFFERATIPROC                        ,glUpdateObjectBufferATI            );
    GL_GetFuncEXT(PFNGLGETOBJECTBUFFERFVATIPROC                         ,glGetObjectBufferfvATI             );
    GL_GetFuncEXT(PFNGLGETOBJECTBUFFERIVATIPROC                         ,glGetObjectBufferivATI             );
    GL_GetFuncEXT(PFNGLFREEOBJECTBUFFERATIPROC                          ,glFreeObjectBufferATI              );
    GL_GetFuncEXT(PFNGLARRAYOBJECTATIPROC                               ,glArrayObjectATI                   );
    GL_GetFuncEXT(PFNGLGETARRAYOBJECTFVATIPROC                          ,glGetArrayObjectfvATI              );
    GL_GetFuncEXT(PFNGLGETARRAYOBJECTIVATIPROC                          ,glGetArrayObjectivATI              );
    GL_GetFuncEXT(PFNGLVARIANTARRAYOBJECTATIPROC                        ,glVariantArrayObjectATI            );
    GL_GetFuncEXT(PFNGLGETVARIANTARRAYOBJECTFVATIPROC                   ,glGetVariantArrayObjectfvATI       );
    GL_GetFuncEXT(PFNGLGETVARIANTARRAYOBJECTIVATIPROC                   ,glGetVariantArrayObjectivATI       );
    #endif /* GL_ATI_vertex_array_object */

    #ifdef GL_ATI_vertex_attrib_array_object
	fprintf(LogGlGetFunctions_py, "\nGL_ATI_vertex_attrib_array_object\n");
    GL_GetFuncEXT(PFNGLVERTEXATTRIBARRAYOBJECTATIPROC                           ,glVertexAttribArrayObjectATI        );
    GL_GetFuncEXT(PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC                      ,glGetVertexAttribArrayObjectfvATI   );
    GL_GetFuncEXT(PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC                      ,glGetVertexAttribArrayObjectivATI   );
    #endif /* GL_ATI_vertex_attrib_array_object */

    #ifdef GL_ATI_vertex_streams
	fprintf(LogGlGetFunctions_py, "\nGL_ATI_vertex_streams\n");
    GL_GetFuncEXT(PFNGLVERTEXSTREAM1SATIPROC                                  ,glVertexStream1sATI                     );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM1SVATIPROC                                 ,glVertexStream1svATI                    );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM1IATIPROC                                  ,glVertexStream1iATI                     );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM1IVATIPROC                                 ,glVertexStream1ivATI                    );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM1FATIPROC                                  ,glVertexStream1fATI                     );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM1FVATIPROC                                 ,glVertexStream1fvATI                    );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM1DATIPROC                                  ,glVertexStream1dATI                     );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM1DVATIPROC                                 ,glVertexStream1dvATI                    );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM2SATIPROC                                  ,glVertexStream2sATI                     );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM2SVATIPROC                                 ,glVertexStream2svATI                    );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM2IATIPROC                                  ,glVertexStream2iATI                     );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM2IVATIPROC                                 ,glVertexStream2ivATI                    );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM2FATIPROC                                  ,glVertexStream2fATI                     );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM2FVATIPROC                                 ,glVertexStream2fvATI                    );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM2DATIPROC                                  ,glVertexStream2dATI                     );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM2DVATIPROC                                 ,glVertexStream2dvATI                    );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM3SATIPROC                                  ,glVertexStream3sATI                     );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM3SVATIPROC                                 ,glVertexStream3svATI                    );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM3IATIPROC                                  ,glVertexStream3iATI                     );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM3IVATIPROC                                 ,glVertexStream3ivATI                    );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM3FATIPROC                                  ,glVertexStream3fATI                     );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM3FVATIPROC                                 ,glVertexStream3fvATI                    );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM3DATIPROC                                  ,glVertexStream3dATI                     );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM3DVATIPROC                                 ,glVertexStream3dvATI                    );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM4SATIPROC                                  ,glVertexStream4sATI                     );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM4SVATIPROC                                 ,glVertexStream4svATI                    );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM4IATIPROC                                  ,glVertexStream4iATI                     );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM4IVATIPROC                                 ,glVertexStream4ivATI                    );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM4FATIPROC                                  ,glVertexStream4fATI                     );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM4FVATIPROC                                 ,glVertexStream4fvATI                    );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM4DATIPROC                                  ,glVertexStream4dATI                     );
    GL_GetFuncEXT(PFNGLVERTEXSTREAM4DVATIPROC                                 ,glVertexStream4dvATI                    );
    GL_GetFuncEXT(PFNGLNORMALSTREAM3BATIPROC                                  ,glNormalStream3bATI                     );
    GL_GetFuncEXT(PFNGLNORMALSTREAM3BVATIPROC                                 ,glNormalStream3bvATI                    );
    GL_GetFuncEXT(PFNGLNORMALSTREAM3SATIPROC                                  ,glNormalStream3sATI                     );
    GL_GetFuncEXT(PFNGLNORMALSTREAM3SVATIPROC                                 ,glNormalStream3svATI                    );
    GL_GetFuncEXT(PFNGLNORMALSTREAM3IATIPROC                                  ,glNormalStream3iATI                     );
    GL_GetFuncEXT(PFNGLNORMALSTREAM3IVATIPROC                                 ,glNormalStream3ivATI                    );
    GL_GetFuncEXT(PFNGLNORMALSTREAM3FATIPROC                                  ,glNormalStream3fATI                     );
    GL_GetFuncEXT(PFNGLNORMALSTREAM3FVATIPROC                                 ,glNormalStream3fvATI                    );
    GL_GetFuncEXT(PFNGLNORMALSTREAM3DATIPROC                                  ,glNormalStream3dATI                     );
    GL_GetFuncEXT(PFNGLNORMALSTREAM3DVATIPROC                                 ,glNormalStream3dvATI                    );
    GL_GetFuncEXT(PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC                        ,glClientActiveVertexStreamATI           );
    GL_GetFuncEXT(PFNGLVERTEXBLENDENVIATIPROC                                 ,glVertexBlendEnviATI                    );
    GL_GetFuncEXT(PFNGLVERTEXBLENDENVFATIPROC                                 ,glVertexBlendEnvfATI                    );
    #endif /* GL_ATI_vertex_streams */

	

    #ifdef GL_EXT_bindable_uniform
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_bindable_uniform\n");
    GL_GetFuncEXT(PFNGLUNIFORMBUFFEREXTPROC                          ,glUniformBufferEXT            );
    GL_GetFuncEXT(PFNGLGETUNIFORMBUFFERSIZEEXTPROC                   ,glGetUniformBufferSizeEXT     );
    GL_GetFuncEXT(PFNGLGETUNIFORMOFFSETEXTPROC                       ,glGetUniformOffsetEXT         );
    #endif /* GL_EXT_bindable_uniform */

    #ifdef GL_EXT_blend_color
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_blend_color\n");
    GL_GetFuncEXT(PFNGLBLENDCOLOREXTPROC                  ,glBlendColorEXT );
    #endif /* GL_EXT_blend_color */

    #ifdef GL_EXT_blend_equation_separate
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_blend_equation_separate\n");
    GL_GetFuncEXT(PFNGLBLENDEQUATIONSEPARATEEXTPROC              ,glBlendEquationSeparateEXT );
    #endif /* GL_EXT_blend_equation_separate */

    #ifdef GL_EXT_blend_func_separate
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_blend_func_separate\n");
    GL_GetFuncEXT(PFNGLBLENDFUNCSEPARATEEXTPROC              ,glBlendFuncSeparateEXT );
    #endif /* GL_EXT_blend_func_separate */

    #ifdef GL_EXT_blend_minmax
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_blend_minmax\n");
    GL_GetFuncEXT(PFNGLBLENDEQUATIONEXTPROC              ,glBlendEquationEXT  );
    #endif /* GL_EXT_blend_minmax */

    #ifdef GL_EXT_color_subtable
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_color_subtable\n");
    GL_GetFuncEXT(PFNGLCOLORSUBTABLEEXTPROC                   ,glColorSubTableEXT       );
    GL_GetFuncEXT(PFNGLCOPYCOLORSUBTABLEEXTPROC               ,glCopyColorSubTableEXT   );
    #endif /* GL_EXT_color_subtable */

    #ifdef GL_EXT_compiled_vertex_array
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_compiled_vertex_array\n");
    GL_GetFuncEXT(PFNGLLOCKARRAYSEXTPROC                 ,glLockArraysEXT     );
    GL_GetFuncEXT(PFNGLUNLOCKARRAYSEXTPROC               ,glUnlockArraysEXT   );
    #endif /* GL_EXT_compiled_vertex_array */

    #ifdef GL_EXT_convolution
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_convolution\n");
    GL_GetFuncEXT(PFNGLCONVOLUTIONFILTER1DEXTPROC                        ,glConvolutionFilter1DEXT             );
    GL_GetFuncEXT(PFNGLCONVOLUTIONFILTER2DEXTPROC                        ,glConvolutionFilter2DEXT             );
    GL_GetFuncEXT(PFNGLCONVOLUTIONPARAMETERFEXTPROC                      ,glConvolutionParameterfEXT           );
    GL_GetFuncEXT(PFNGLCONVOLUTIONPARAMETERFVEXTPROC                     ,glConvolutionParameterfvEXT          );
    GL_GetFuncEXT(PFNGLCONVOLUTIONPARAMETERIEXTPROC                      ,glConvolutionParameteriEXT           );
    GL_GetFuncEXT(PFNGLCONVOLUTIONPARAMETERIVEXTPROC                     ,glConvolutionParameterivEXT          );
    GL_GetFuncEXT(PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC                    ,glCopyConvolutionFilter1DEXT         );
    GL_GetFuncEXT(PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC                    ,glCopyConvolutionFilter2DEXT         );
    GL_GetFuncEXT(PFNGLGETCONVOLUTIONFILTEREXTPROC                       ,glGetConvolutionFilterEXT            );
    GL_GetFuncEXT(PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC                  ,glGetConvolutionParameterfvEXT       );
    GL_GetFuncEXT(PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC                  ,glGetConvolutionParameterivEXT       );
    GL_GetFuncEXT(PFNGLGETSEPARABLEFILTEREXTPROC                         ,glGetSeparableFilterEXT              );
    GL_GetFuncEXT(PFNGLSEPARABLEFILTER2DEXTPROC                          ,glSeparableFilter2DEXT               );
    #endif /* GL_EXT_convolution */

    #ifdef GL_EXT_coordinate_frame
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_coordinate_frame\n");
    GL_GetFuncEXT(PFNGLTANGENT3BEXTPROC                         ,glTangent3bEXT              );
    GL_GetFuncEXT(PFNGLTANGENT3BVEXTPROC                        ,glTangent3bvEXT             );
    GL_GetFuncEXT(PFNGLTANGENT3DEXTPROC                         ,glTangent3dEXT              );
    GL_GetFuncEXT(PFNGLTANGENT3DVEXTPROC                        ,glTangent3dvEXT             );
    GL_GetFuncEXT(PFNGLTANGENT3FEXTPROC                         ,glTangent3fEXT              );
    GL_GetFuncEXT(PFNGLTANGENT3FVEXTPROC                        ,glTangent3fvEXT             );
    GL_GetFuncEXT(PFNGLTANGENT3IEXTPROC                         ,glTangent3iEXT              );
    GL_GetFuncEXT(PFNGLTANGENT3IVEXTPROC                        ,glTangent3ivEXT             );
    GL_GetFuncEXT(PFNGLTANGENT3SEXTPROC                         ,glTangent3sEXT              );
    GL_GetFuncEXT(PFNGLTANGENT3SVEXTPROC                        ,glTangent3svEXT             );
    GL_GetFuncEXT(PFNGLBINORMAL3BEXTPROC                        ,glBinormal3bEXT             );
    GL_GetFuncEXT(PFNGLBINORMAL3BVEXTPROC                       ,glBinormal3bvEXT            );
    GL_GetFuncEXT(PFNGLBINORMAL3DEXTPROC                        ,glBinormal3dEXT             );
    GL_GetFuncEXT(PFNGLBINORMAL3DVEXTPROC                       ,glBinormal3dvEXT            );
    GL_GetFuncEXT(PFNGLBINORMAL3FEXTPROC                        ,glBinormal3fEXT             );
    GL_GetFuncEXT(PFNGLBINORMAL3FVEXTPROC                       ,glBinormal3fvEXT            );
    GL_GetFuncEXT(PFNGLBINORMAL3IEXTPROC                        ,glBinormal3iEXT             );
    GL_GetFuncEXT(PFNGLBINORMAL3IVEXTPROC                       ,glBinormal3ivEXT            );
    GL_GetFuncEXT(PFNGLBINORMAL3SEXTPROC                        ,glBinormal3sEXT             );
    GL_GetFuncEXT(PFNGLBINORMAL3SVEXTPROC                       ,glBinormal3svEXT            );
    GL_GetFuncEXT(PFNGLTANGENTPOINTEREXTPROC                    ,glTangentPointerEXT         );
    GL_GetFuncEXT(PFNGLBINORMALPOINTEREXTPROC                   ,glBinormalPointerEXT        );
    #endif /* GL_EXT_coordinate_frame */

    #ifdef GL_EXT_copy_texture
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_copy_texture\n");
    GL_GetFuncEXT(PFNGLCOPYTEXIMAGE1DEXTPROC                  ,glCopyTexImage1DEXT          );
    GL_GetFuncEXT(PFNGLCOPYTEXIMAGE2DEXTPROC                  ,glCopyTexImage2DEXT          );
	GL_GetFuncEXT(PFNGLCOPYTEXSUBIMAGE1DEXTPROC               ,glCopyTexSubImage1DEXT       );
	GL_GetFuncEXT(PFNGLCOPYTEXSUBIMAGE2DEXTPROC               ,glCopyTexSubImage2DEXT       );
	GL_GetFuncEXT(PFNGLCOPYTEXSUBIMAGE3DEXTPROC               ,glCopyTexSubImage3DEXT       );
    #endif /* GL_EXT_copy_texture */

    #ifdef GL_EXT_cull_vertex
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_cull_vertex\n");
    GL_GetFuncEXT(PFNGLCULLPARAMETERDVEXTPROC                ,glCullParameterdvEXT  );
    GL_GetFuncEXT(PFNGLCULLPARAMETERFVEXTPROC                ,glCullParameterfvEXT  );
    #endif /* GL_EXT_cull_vertex */

    #ifdef GL_EXT_debug_label
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_debug_label\n");
    GL_GetFuncEXT(PFNGLLABELOBJECTEXTPROC                 ,glLabelObjectEXT    );
    GL_GetFuncEXT(PFNGLGETOBJECTLABELEXTPROC              ,glGetObjectLabelEXT );
    #endif /* GL_EXT_debug_label */

    #ifdef GL_EXT_debug_marker
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_debug_marker\n");
    GL_GetFuncEXT(PFNGLINSERTEVENTMARKEREXTPROC                  ,glInsertEventMarkerEXT   );
    GL_GetFuncEXT(PFNGLPUSHGROUPMARKEREXTPROC                    ,glPushGroupMarkerEXT     );
    GL_GetFuncEXT(PFNGLPOPGROUPMARKEREXTPROC                     ,glPopGroupMarkerEXT      );
    #endif /* GL_EXT_debug_marker */

    #ifdef GL_EXT_depth_bounds_test
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_depth_bounds_test\n");
    GL_GetFuncEXT(PFNGLDEPTHBOUNDSEXTPROC              ,glDepthBoundsEXT );
    #endif /* GL_EXT_depth_bounds_test */

    #ifdef GL_EXT_direct_state_access
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_direct_state_access\n");
    GL_GetFuncEXT(PFNGLMATRIXLOADFEXTPROC                                                 ,glMatrixLoadfEXT                                      );
    GL_GetFuncEXT(PFNGLMATRIXLOADDEXTPROC                                                 ,glMatrixLoaddEXT                                      );
    GL_GetFuncEXT(PFNGLMATRIXMULTFEXTPROC                                                 ,glMatrixMultfEXT                                      );
    GL_GetFuncEXT(PFNGLMATRIXMULTDEXTPROC                                                 ,glMatrixMultdEXT                                      );
    GL_GetFuncEXT(PFNGLMATRIXLOADIDENTITYEXTPROC                                          ,glMatrixLoadIdentityEXT                               );
    GL_GetFuncEXT(PFNGLMATRIXROTATEFEXTPROC                                               ,glMatrixRotatefEXT                                    );
    GL_GetFuncEXT(PFNGLMATRIXROTATEDEXTPROC                                               ,glMatrixRotatedEXT                                    );
    GL_GetFuncEXT(PFNGLMATRIXSCALEFEXTPROC                                                ,glMatrixScalefEXT                                     );
    GL_GetFuncEXT(PFNGLMATRIXSCALEDEXTPROC                                                ,glMatrixScaledEXT                                     );
    GL_GetFuncEXT(PFNGLMATRIXTRANSLATEFEXTPROC                                            ,glMatrixTranslatefEXT                                 );
    GL_GetFuncEXT(PFNGLMATRIXTRANSLATEDEXTPROC                                            ,glMatrixTranslatedEXT                                 );
    GL_GetFuncEXT(PFNGLMATRIXFRUSTUMEXTPROC                                               ,glMatrixFrustumEXT                                    );
    GL_GetFuncEXT(PFNGLMATRIXORTHOEXTPROC                                                 ,glMatrixOrthoEXT                                      );
    GL_GetFuncEXT(PFNGLMATRIXPOPEXTPROC                                                   ,glMatrixPopEXT                                        );
    GL_GetFuncEXT(PFNGLMATRIXPUSHEXTPROC                                                  ,glMatrixPushEXT                                       );
    GL_GetFuncEXT(PFNGLCLIENTATTRIBDEFAULTEXTPROC                                         ,glClientAttribDefaultEXT                              );
    GL_GetFuncEXT(PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC                                     ,glPushClientAttribDefaultEXT                          );
    GL_GetFuncEXT(PFNGLTEXTUREPARAMETERFEXTPROC                                           ,glTextureParameterfEXT                                );
    GL_GetFuncEXT(PFNGLTEXTUREPARAMETERFVEXTPROC                                          ,glTextureParameterfvEXT                               );
    GL_GetFuncEXT(PFNGLTEXTUREPARAMETERIEXTPROC                                           ,glTextureParameteriEXT                                );
    GL_GetFuncEXT(PFNGLTEXTUREPARAMETERIVEXTPROC                                          ,glTextureParameterivEXT                               );
    GL_GetFuncEXT(PFNGLTEXTUREIMAGE1DEXTPROC                                              ,glTextureImage1DEXT                                   );
    GL_GetFuncEXT(PFNGLTEXTUREIMAGE2DEXTPROC                                              ,glTextureImage2DEXT                                   );
    GL_GetFuncEXT(PFNGLTEXTURESUBIMAGE1DEXTPROC                                           ,glTextureSubImage1DEXT                                );
    GL_GetFuncEXT(PFNGLTEXTURESUBIMAGE2DEXTPROC                                           ,glTextureSubImage2DEXT                                );
    GL_GetFuncEXT(PFNGLCOPYTEXTUREIMAGE1DEXTPROC                                          ,glCopyTextureImage1DEXT                               );
    GL_GetFuncEXT(PFNGLCOPYTEXTUREIMAGE2DEXTPROC                                          ,glCopyTextureImage2DEXT                               );
    GL_GetFuncEXT(PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC                                       ,glCopyTextureSubImage1DEXT                            );
    GL_GetFuncEXT(PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC                                       ,glCopyTextureSubImage2DEXT                            );
    GL_GetFuncEXT(PFNGLGETTEXTUREIMAGEEXTPROC                                             ,glGetTextureImageEXT                                  );
    GL_GetFuncEXT(PFNGLGETTEXTUREPARAMETERFVEXTPROC                                       ,glGetTextureParameterfvEXT                            );
    GL_GetFuncEXT(PFNGLGETTEXTUREPARAMETERIVEXTPROC                                       ,glGetTextureParameterivEXT                            );
    GL_GetFuncEXT(PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC                                  ,glGetTextureLevelParameterfvEXT                       );
    GL_GetFuncEXT(PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC                                  ,glGetTextureLevelParameterivEXT                       );
    GL_GetFuncEXT(PFNGLTEXTUREIMAGE3DEXTPROC                                              ,glTextureImage3DEXT                                   );
    GL_GetFuncEXT(PFNGLTEXTURESUBIMAGE3DEXTPROC                                           ,glTextureSubImage3DEXT                                );
    GL_GetFuncEXT(PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC                                       ,glCopyTextureSubImage3DEXT                            );
    GL_GetFuncEXT(PFNGLBINDMULTITEXTUREEXTPROC                                            ,glBindMultiTextureEXT                                 );
    GL_GetFuncEXT(PFNGLMULTITEXCOORDPOINTEREXTPROC                                        ,glMultiTexCoordPointerEXT                             );
    GL_GetFuncEXT(PFNGLMULTITEXENVFEXTPROC                                                ,glMultiTexEnvfEXT                                     );
    GL_GetFuncEXT(PFNGLMULTITEXENVFVEXTPROC                                               ,glMultiTexEnvfvEXT                                    );
    GL_GetFuncEXT(PFNGLMULTITEXENVIEXTPROC                                                ,glMultiTexEnviEXT                                     );
    GL_GetFuncEXT(PFNGLMULTITEXENVIVEXTPROC                                               ,glMultiTexEnvivEXT                                    );
    GL_GetFuncEXT(PFNGLMULTITEXGENDEXTPROC                                                ,glMultiTexGendEXT                                     );
    GL_GetFuncEXT(PFNGLMULTITEXGENDVEXTPROC                                               ,glMultiTexGendvEXT                                    );
    GL_GetFuncEXT(PFNGLMULTITEXGENFEXTPROC                                                ,glMultiTexGenfEXT                                     );
    GL_GetFuncEXT(PFNGLMULTITEXGENFVEXTPROC                                               ,glMultiTexGenfvEXT                                    );
    GL_GetFuncEXT(PFNGLMULTITEXGENIEXTPROC                                                ,glMultiTexGeniEXT                                     );
    GL_GetFuncEXT(PFNGLMULTITEXGENIVEXTPROC                                               ,glMultiTexGenivEXT                                    );
    GL_GetFuncEXT(PFNGLGETMULTITEXENVFVEXTPROC                                            ,glGetMultiTexEnvfvEXT                                 );
    GL_GetFuncEXT(PFNGLGETMULTITEXENVIVEXTPROC                                            ,glGetMultiTexEnvivEXT                                 );
    GL_GetFuncEXT(PFNGLGETMULTITEXGENDVEXTPROC                                            ,glGetMultiTexGendvEXT                                 );
    GL_GetFuncEXT(PFNGLGETMULTITEXGENFVEXTPROC                                            ,glGetMultiTexGenfvEXT                                 );
    GL_GetFuncEXT(PFNGLGETMULTITEXGENIVEXTPROC                                            ,glGetMultiTexGenivEXT                                 );
    GL_GetFuncEXT(PFNGLMULTITEXPARAMETERIEXTPROC                                          ,glMultiTexParameteriEXT                               );
    GL_GetFuncEXT(PFNGLMULTITEXPARAMETERIVEXTPROC                                         ,glMultiTexParameterivEXT                              );
    GL_GetFuncEXT(PFNGLMULTITEXPARAMETERFEXTPROC                                          ,glMultiTexParameterfEXT                               );
    GL_GetFuncEXT(PFNGLMULTITEXPARAMETERFVEXTPROC                                         ,glMultiTexParameterfvEXT                              );
    GL_GetFuncEXT(PFNGLMULTITEXIMAGE1DEXTPROC                                             ,glMultiTexImage1DEXT                                  );
    GL_GetFuncEXT(PFNGLMULTITEXIMAGE2DEXTPROC                                             ,glMultiTexImage2DEXT                                  );
    GL_GetFuncEXT(PFNGLMULTITEXSUBIMAGE1DEXTPROC                                          ,glMultiTexSubImage1DEXT                               );
    GL_GetFuncEXT(PFNGLMULTITEXSUBIMAGE2DEXTPROC                                          ,glMultiTexSubImage2DEXT                               );
    GL_GetFuncEXT(PFNGLCOPYMULTITEXIMAGE1DEXTPROC                                         ,glCopyMultiTexImage1DEXT                              );
    GL_GetFuncEXT(PFNGLCOPYMULTITEXIMAGE2DEXTPROC                                         ,glCopyMultiTexImage2DEXT                              );
    GL_GetFuncEXT(PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC                                      ,glCopyMultiTexSubImage1DEXT                           );
    GL_GetFuncEXT(PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC                                      ,glCopyMultiTexSubImage2DEXT                           );
    GL_GetFuncEXT(PFNGLGETMULTITEXIMAGEEXTPROC                                            ,glGetMultiTexImageEXT                                 );
    GL_GetFuncEXT(PFNGLGETMULTITEXPARAMETERFVEXTPROC                                      ,glGetMultiTexParameterfvEXT                           );
    GL_GetFuncEXT(PFNGLGETMULTITEXPARAMETERIVEXTPROC                                      ,glGetMultiTexParameterivEXT                           );
    GL_GetFuncEXT(PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC                                 ,glGetMultiTexLevelParameterfvEXT                      );
    GL_GetFuncEXT(PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC                                 ,glGetMultiTexLevelParameterivEXT                      );
    GL_GetFuncEXT(PFNGLMULTITEXIMAGE3DEXTPROC                                             ,glMultiTexImage3DEXT                                  );
    GL_GetFuncEXT(PFNGLMULTITEXSUBIMAGE3DEXTPROC                                          ,glMultiTexSubImage3DEXT                               );
    GL_GetFuncEXT(PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC                                      ,glCopyMultiTexSubImage3DEXT                           );
    GL_GetFuncEXT(PFNGLENABLECLIENTSTATEINDEXEDEXTPROC                                    ,glEnableClientStateIndexedEXT                         );
    GL_GetFuncEXT(PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC                                   ,glDisableClientStateIndexedEXT                        );
    GL_GetFuncEXT(PFNGLGETFLOATINDEXEDVEXTPROC                                            ,glGetFloatIndexedvEXT                                 );
    GL_GetFuncEXT(PFNGLGETDOUBLEINDEXEDVEXTPROC                                           ,glGetDoubleIndexedvEXT                                );
    GL_GetFuncEXT(PFNGLGETPOINTERINDEXEDVEXTPROC                                          ,glGetPointerIndexedvEXT                               );
    GL_GetFuncEXT(PFNGLENABLEINDEXEDEXTPROC                                               ,glEnableIndexedEXT                                    );
    GL_GetFuncEXT(PFNGLDISABLEINDEXEDEXTPROC                                              ,glDisableIndexedEXT                                   );
    GL_GetFuncEXT(PFNGLISENABLEDINDEXEDEXTPROC                                            ,glIsEnabledIndexedEXT                                 );
    GL_GetFuncEXT(PFNGLGETINTEGERINDEXEDVEXTPROC                                          ,glGetIntegerIndexedvEXT                               );
    GL_GetFuncEXT(PFNGLGETBOOLEANINDEXEDVEXTPROC                                          ,glGetBooleanIndexedvEXT                               );
    GL_GetFuncEXT(PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC                                    ,glCompressedTextureImage3DEXT                         );
    GL_GetFuncEXT(PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC                                    ,glCompressedTextureImage2DEXT                         );
    GL_GetFuncEXT(PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC                                    ,glCompressedTextureImage1DEXT                         );
    GL_GetFuncEXT(PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC                                 ,glCompressedTextureSubImage3DEXT                      );
    GL_GetFuncEXT(PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC                                 ,glCompressedTextureSubImage2DEXT                      );
    GL_GetFuncEXT(PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC                                 ,glCompressedTextureSubImage1DEXT                      );
    GL_GetFuncEXT(PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC                                   ,glGetCompressedTextureImageEXT                        );
    GL_GetFuncEXT(PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC                                   ,glCompressedMultiTexImage3DEXT                        );
    GL_GetFuncEXT(PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC                                   ,glCompressedMultiTexImage2DEXT                        );
    GL_GetFuncEXT(PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC                                   ,glCompressedMultiTexImage1DEXT                        );
    GL_GetFuncEXT(PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC                                ,glCompressedMultiTexSubImage3DEXT                     );
    GL_GetFuncEXT(PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC                                ,glCompressedMultiTexSubImage2DEXT                     );
    GL_GetFuncEXT(PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC                                ,glCompressedMultiTexSubImage1DEXT                     );
    GL_GetFuncEXT(PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC                                  ,glGetCompressedMultiTexImageEXT                       );
    GL_GetFuncEXT(PFNGLMATRIXLOADTRANSPOSEFEXTPROC                                        ,glMatrixLoadTransposefEXT                             );
    GL_GetFuncEXT(PFNGLMATRIXLOADTRANSPOSEDEXTPROC                                        ,glMatrixLoadTransposedEXT                             );
    GL_GetFuncEXT(PFNGLMATRIXMULTTRANSPOSEFEXTPROC                                        ,glMatrixMultTransposefEXT                             );
    GL_GetFuncEXT(PFNGLMATRIXMULTTRANSPOSEDEXTPROC                                        ,glMatrixMultTransposedEXT                             );
    GL_GetFuncEXT(PFNGLNAMEDBUFFERDATAEXTPROC                                             ,glNamedBufferDataEXT                                  );
    GL_GetFuncEXT(PFNGLNAMEDBUFFERSUBDATAEXTPROC                                          ,glNamedBufferSubDataEXT                               );
    GL_GetFuncEXT(PFNGLMAPNAMEDBUFFEREXTPROC                                              ,glMapNamedBufferEXT                                   );
    GL_GetFuncEXT(PFNGLUNMAPNAMEDBUFFEREXTPROC                                            ,glUnmapNamedBufferEXT                                 );
    GL_GetFuncEXT(PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC                                   ,glGetNamedBufferParameterivEXT                        );
    GL_GetFuncEXT(PFNGLGETNAMEDBUFFERPOINTERVEXTPROC                                      ,glGetNamedBufferPointervEXT                           );
    GL_GetFuncEXT(PFNGLGETNAMEDBUFFERSUBDATAEXTPROC                                       ,glGetNamedBufferSubDataEXT                            );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM1FEXTPROC                                            ,glProgramUniform1fEXT                                 );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM2FEXTPROC                                            ,glProgramUniform2fEXT                                 );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM3FEXTPROC                                            ,glProgramUniform3fEXT                                 );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM4FEXTPROC                                            ,glProgramUniform4fEXT                                 );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM1IEXTPROC                                            ,glProgramUniform1iEXT                                 );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM2IEXTPROC                                            ,glProgramUniform2iEXT                                 );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM3IEXTPROC                                            ,glProgramUniform3iEXT                                 );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM4IEXTPROC                                            ,glProgramUniform4iEXT                                 );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM1FVEXTPROC                                           ,glProgramUniform1fvEXT                                );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM2FVEXTPROC                                           ,glProgramUniform2fvEXT                                );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM3FVEXTPROC                                           ,glProgramUniform3fvEXT                                );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM4FVEXTPROC                                           ,glProgramUniform4fvEXT                                );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM1IVEXTPROC                                           ,glProgramUniform1ivEXT                                );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM2IVEXTPROC                                           ,glProgramUniform2ivEXT                                );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM3IVEXTPROC                                           ,glProgramUniform3ivEXT                                );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM4IVEXTPROC                                           ,glProgramUniform4ivEXT                                );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC                                     ,glProgramUniformMatrix2fvEXT                          );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC                                     ,glProgramUniformMatrix3fvEXT                          );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC                                     ,glProgramUniformMatrix4fvEXT                          );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC                                   ,glProgramUniformMatrix2x3fvEXT                        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC                                   ,glProgramUniformMatrix3x2fvEXT                        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC                                   ,glProgramUniformMatrix2x4fvEXT                        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC                                   ,glProgramUniformMatrix4x2fvEXT                        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC                                   ,glProgramUniformMatrix3x4fvEXT                        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC                                   ,glProgramUniformMatrix4x3fvEXT                        );
    GL_GetFuncEXT(PFNGLTEXTUREBUFFEREXTPROC                                               ,glTextureBufferEXT                                    );
    GL_GetFuncEXT(PFNGLMULTITEXBUFFEREXTPROC                                              ,glMultiTexBufferEXT                                   );
    GL_GetFuncEXT(PFNGLTEXTUREPARAMETERIIVEXTPROC                                         ,glTextureParameterIivEXT                              );
    GL_GetFuncEXT(PFNGLTEXTUREPARAMETERIUIVEXTPROC                                        ,glTextureParameterIuivEXT                             );
    GL_GetFuncEXT(PFNGLGETTEXTUREPARAMETERIIVEXTPROC                                      ,glGetTextureParameterIivEXT                           );
    GL_GetFuncEXT(PFNGLGETTEXTUREPARAMETERIUIVEXTPROC                                     ,glGetTextureParameterIuivEXT                          );
    GL_GetFuncEXT(PFNGLMULTITEXPARAMETERIIVEXTPROC                                        ,glMultiTexParameterIivEXT                             );
    GL_GetFuncEXT(PFNGLMULTITEXPARAMETERIUIVEXTPROC                                       ,glMultiTexParameterIuivEXT                            );
    GL_GetFuncEXT(PFNGLGETMULTITEXPARAMETERIIVEXTPROC                                     ,glGetMultiTexParameterIivEXT                          );
    GL_GetFuncEXT(PFNGLGETMULTITEXPARAMETERIUIVEXTPROC                                    ,glGetMultiTexParameterIuivEXT                         );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM1UIEXTPROC                                           ,glProgramUniform1uiEXT                                );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM2UIEXTPROC                                           ,glProgramUniform2uiEXT                                );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM3UIEXTPROC                                           ,glProgramUniform3uiEXT                                );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM4UIEXTPROC                                           ,glProgramUniform4uiEXT                                );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM1UIVEXTPROC                                          ,glProgramUniform1uivEXT                               );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM2UIVEXTPROC                                          ,glProgramUniform2uivEXT                               );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM3UIVEXTPROC                                          ,glProgramUniform3uivEXT                               );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM4UIVEXTPROC                                          ,glProgramUniform4uivEXT                               );
    GL_GetFuncEXT(PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC                              ,glNamedProgramLocalParameters4fvEXT                   );
    GL_GetFuncEXT(PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC                               ,glNamedProgramLocalParameterI4iEXT                    );
    GL_GetFuncEXT(PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC                              ,glNamedProgramLocalParameterI4ivEXT                   );
    GL_GetFuncEXT(PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC                             ,glNamedProgramLocalParametersI4ivEXT                  );
    GL_GetFuncEXT(PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC                              ,glNamedProgramLocalParameterI4uiEXT                   );
    GL_GetFuncEXT(PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC                             ,glNamedProgramLocalParameterI4uivEXT                  );
    GL_GetFuncEXT(PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC                            ,glNamedProgramLocalParametersI4uivEXT                 );
    GL_GetFuncEXT(PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC                            ,glGetNamedProgramLocalParameterIivEXT                 );
    GL_GetFuncEXT(PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC                           ,glGetNamedProgramLocalParameterIuivEXT                );
    GL_GetFuncEXT(PFNGLENABLECLIENTSTATEIEXTPROC                                          ,glEnableClientStateiEXT                               );
    GL_GetFuncEXT(PFNGLDISABLECLIENTSTATEIEXTPROC                                         ,glDisableClientStateiEXT                              );
    GL_GetFuncEXT(PFNGLGETFLOATI_VEXTPROC                                                 ,glGetFloati_vEXT                                      );
    GL_GetFuncEXT(PFNGLGETDOUBLEI_VEXTPROC                                                ,glGetDoublei_vEXT                                     );
    GL_GetFuncEXT(PFNGLGETPOINTERI_VEXTPROC                                               ,glGetPointeri_vEXT                                    );
    GL_GetFuncEXT(PFNGLNAMEDPROGRAMSTRINGEXTPROC                                          ,glNamedProgramStringEXT                               );
    GL_GetFuncEXT(PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC                                ,glNamedProgramLocalParameter4dEXT                     );
    GL_GetFuncEXT(PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC                               ,glNamedProgramLocalParameter4dvEXT                    );
    GL_GetFuncEXT(PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC                                ,glNamedProgramLocalParameter4fEXT                     );
    GL_GetFuncEXT(PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC                               ,glNamedProgramLocalParameter4fvEXT                    );
    GL_GetFuncEXT(PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC                             ,glGetNamedProgramLocalParameterdvEXT                  );
    GL_GetFuncEXT(PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC                             ,glGetNamedProgramLocalParameterfvEXT                  );
    GL_GetFuncEXT(PFNGLGETNAMEDPROGRAMIVEXTPROC                                           ,glGetNamedProgramivEXT                                );
    GL_GetFuncEXT(PFNGLGETNAMEDPROGRAMSTRINGEXTPROC                                       ,glGetNamedProgramStringEXT                            );
    GL_GetFuncEXT(PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC                                    ,glNamedRenderbufferStorageEXT                         );
    GL_GetFuncEXT(PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC                             ,glGetNamedRenderbufferParameterivEXT                  );
    GL_GetFuncEXT(PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC                         ,glNamedRenderbufferStorageMultisampleEXT              );
    GL_GetFuncEXT(PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC                 ,glNamedRenderbufferStorageMultisampleCoverageEXT      );
    GL_GetFuncEXT(PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC                                 ,glCheckNamedFramebufferStatusEXT                      );
    GL_GetFuncEXT(PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC                                   ,glNamedFramebufferTexture1DEXT                        );
    GL_GetFuncEXT(PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC                                   ,glNamedFramebufferTexture2DEXT                        );
    GL_GetFuncEXT(PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC                                   ,glNamedFramebufferTexture3DEXT                        );
    GL_GetFuncEXT(PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC                                ,glNamedFramebufferRenderbufferEXT                     );
    GL_GetFuncEXT(PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC                    ,glGetNamedFramebufferAttachmentParameterivEXT         );
    GL_GetFuncEXT(PFNGLGENERATETEXTUREMIPMAPEXTPROC                                       ,glGenerateTextureMipmapEXT                            );
    GL_GetFuncEXT(PFNGLGENERATEMULTITEXMIPMAPEXTPROC                                      ,glGenerateMultiTexMipmapEXT                           );
    GL_GetFuncEXT(PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC                                       ,glFramebufferDrawBufferEXT                            );
    GL_GetFuncEXT(PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC                                      ,glFramebufferDrawBuffersEXT                           );
    GL_GetFuncEXT(PFNGLFRAMEBUFFERREADBUFFEREXTPROC                                       ,glFramebufferReadBufferEXT                            );
    GL_GetFuncEXT(PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC                                   ,glGetFramebufferParameterivEXT                        );
    GL_GetFuncEXT(PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC                                      ,glNamedCopyBufferSubDataEXT                           );
    GL_GetFuncEXT(PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC                                     ,glNamedFramebufferTextureEXT                          );
    GL_GetFuncEXT(PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC                                ,glNamedFramebufferTextureLayerEXT                     );
    GL_GetFuncEXT(PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC                                 ,glNamedFramebufferTextureFaceEXT                      );
    GL_GetFuncEXT(PFNGLTEXTURERENDERBUFFEREXTPROC                                         ,glTextureRenderbufferEXT                              );
    GL_GetFuncEXT(PFNGLMULTITEXRENDERBUFFEREXTPROC                                        ,glMultiTexRenderbufferEXT                             );
    GL_GetFuncEXT(PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC                                     ,glVertexArrayVertexOffsetEXT                          );
    GL_GetFuncEXT(PFNGLVERTEXARRAYCOLOROFFSETEXTPROC                                      ,glVertexArrayColorOffsetEXT                           );
    GL_GetFuncEXT(PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC                                   ,glVertexArrayEdgeFlagOffsetEXT                        );
    GL_GetFuncEXT(PFNGLVERTEXARRAYINDEXOFFSETEXTPROC                                      ,glVertexArrayIndexOffsetEXT                           );
    GL_GetFuncEXT(PFNGLVERTEXARRAYNORMALOFFSETEXTPROC                                     ,glVertexArrayNormalOffsetEXT                          );
    GL_GetFuncEXT(PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC                                   ,glVertexArrayTexCoordOffsetEXT                        );
    GL_GetFuncEXT(PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC                              ,glVertexArrayMultiTexCoordOffsetEXT                   );
    GL_GetFuncEXT(PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC                                   ,glVertexArrayFogCoordOffsetEXT                        );
    GL_GetFuncEXT(PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC                             ,glVertexArraySecondaryColorOffsetEXT                  );
    GL_GetFuncEXT(PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC                               ,glVertexArrayVertexAttribOffsetEXT                    );
    GL_GetFuncEXT(PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC                              ,glVertexArrayVertexAttribIOffsetEXT                   );
    GL_GetFuncEXT(PFNGLENABLEVERTEXARRAYEXTPROC                                           ,glEnableVertexArrayEXT                                );
    GL_GetFuncEXT(PFNGLDISABLEVERTEXARRAYEXTPROC                                          ,glDisableVertexArrayEXT                               );
    GL_GetFuncEXT(PFNGLENABLEVERTEXARRAYATTRIBEXTPROC                                     ,glEnableVertexArrayAttribEXT                          );
    GL_GetFuncEXT(PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC                                    ,glDisableVertexArrayAttribEXT                         );
    GL_GetFuncEXT(PFNGLGETVERTEXARRAYINTEGERVEXTPROC                                      ,glGetVertexArrayIntegervEXT                           );
    GL_GetFuncEXT(PFNGLGETVERTEXARRAYPOINTERVEXTPROC                                      ,glGetVertexArrayPointervEXT                           );
    GL_GetFuncEXT(PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC                                    ,glGetVertexArrayIntegeri_vEXT                         );
    GL_GetFuncEXT(PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC                                    ,glGetVertexArrayPointeri_vEXT                         );
    GL_GetFuncEXT(PFNGLMAPNAMEDBUFFERRANGEEXTPROC                                         ,glMapNamedBufferRangeEXT                              );
    GL_GetFuncEXT(PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC                                 ,glFlushMappedNamedBufferRangeEXT                      );
    GL_GetFuncEXT(PFNGLNAMEDBUFFERSTORAGEEXTPROC                                          ,glNamedBufferStorageEXT                               );
    GL_GetFuncEXT(PFNGLCLEARNAMEDBUFFERDATAEXTPROC                                        ,glClearNamedBufferDataEXT                             );
    GL_GetFuncEXT(PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC                                     ,glClearNamedBufferSubDataEXT                          );
    GL_GetFuncEXT(PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC                                  ,glNamedFramebufferParameteriEXT                       );
    GL_GetFuncEXT(PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC                              ,glGetNamedFramebufferParameterivEXT                   );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM1DEXTPROC                                            ,glProgramUniform1dEXT                                 );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM2DEXTPROC                                            ,glProgramUniform2dEXT                                 );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM3DEXTPROC                                            ,glProgramUniform3dEXT                                 );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM4DEXTPROC                                            ,glProgramUniform4dEXT                                 );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM1DVEXTPROC                                           ,glProgramUniform1dvEXT                                );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM2DVEXTPROC                                           ,glProgramUniform2dvEXT                                );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM3DVEXTPROC                                           ,glProgramUniform3dvEXT                                );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORM4DVEXTPROC                                           ,glProgramUniform4dvEXT                                );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC                                     ,glProgramUniformMatrix2dvEXT                          );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC                                     ,glProgramUniformMatrix3dvEXT                          );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC                                     ,glProgramUniformMatrix4dvEXT                          );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC                                   ,glProgramUniformMatrix2x3dvEXT                        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC                                   ,glProgramUniformMatrix2x4dvEXT                        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC                                   ,glProgramUniformMatrix3x2dvEXT                        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC                                   ,glProgramUniformMatrix3x4dvEXT                        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC                                   ,glProgramUniformMatrix4x2dvEXT                        );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC                                   ,glProgramUniformMatrix4x3dvEXT                        );
    GL_GetFuncEXT(PFNGLTEXTUREBUFFERRANGEEXTPROC                                          ,glTextureBufferRangeEXT                               );
    GL_GetFuncEXT(PFNGLTEXTURESTORAGE1DEXTPROC                                            ,glTextureStorage1DEXT                                 );
    GL_GetFuncEXT(PFNGLTEXTURESTORAGE2DEXTPROC                                            ,glTextureStorage2DEXT                                 );
    GL_GetFuncEXT(PFNGLTEXTURESTORAGE3DEXTPROC                                            ,glTextureStorage3DEXT                                 );
    GL_GetFuncEXT(PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC                                 ,glTextureStorage2DMultisampleEXT                      );
    GL_GetFuncEXT(PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC                                 ,glTextureStorage3DMultisampleEXT                      );
    GL_GetFuncEXT(PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC                                 ,glVertexArrayBindVertexBufferEXT                      );
    GL_GetFuncEXT(PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC                               ,glVertexArrayVertexAttribFormatEXT                    );
    GL_GetFuncEXT(PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC                              ,glVertexArrayVertexAttribIFormatEXT                   );
    GL_GetFuncEXT(PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC                              ,glVertexArrayVertexAttribLFormatEXT                   );
    GL_GetFuncEXT(PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC                              ,glVertexArrayVertexAttribBindingEXT                   );
    GL_GetFuncEXT(PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC                             ,glVertexArrayVertexBindingDivisorEXT                  );
    GL_GetFuncEXT(PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC                              ,glVertexArrayVertexAttribLOffsetEXT                   );
    GL_GetFuncEXT(PFNGLTEXTUREPAGECOMMITMENTEXTPROC                                       ,glTexturePageCommitmentEXT                            );
    GL_GetFuncEXT(PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC                              ,glVertexArrayVertexAttribDivisorEXT                   );
    #endif /* GL_EXT_direct_state_access */

    #ifdef GL_EXT_draw_buffers2
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_draw_buffers2\n");
    GL_GetFuncEXT(PFNGLCOLORMASKINDEXEDEXTPROC              ,glColorMaskIndexedEXT );
    #endif /* GL_EXT_draw_buffers2 */

    #ifdef GL_EXT_draw_instanced
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_draw_instanced\n");
    GL_GetFuncEXT(PFNGLDRAWARRAYSINSTANCEDEXTPROC                 ,glDrawArraysInstancedEXT     );
    GL_GetFuncEXT(PFNGLDRAWELEMENTSINSTANCEDEXTPROC               ,glDrawElementsInstancedEXT   );
    #endif /* GL_EXT_draw_instanced */

    #ifdef GL_EXT_draw_range_elements
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_draw_range_elements\n");
    GL_GetFuncEXT(PFNGLDRAWRANGEELEMENTSEXTPROC              ,glDrawRangeElementsEXT );
    #endif /* GL_EXT_draw_range_elements */

    #ifdef GL_EXT_external_buffer
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_external_buffer\n");
    GL_GetFuncEXT(PFNGLBUFFERSTORAGEEXTERNALEXTPROC                      ,glBufferStorageExternalEXT          );
    GL_GetFuncEXT(PFNGLNAMEDBUFFERSTORAGEEXTERNALEXTPROC                 ,glNamedBufferStorageExternalEXT     );
    #endif /* GL_EXT_external_buffer */

    #ifdef GL_EXT_fog_coord
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_fog_coord\n");
    GL_GetFuncEXT(PFNGLFOGCOORDFEXTPROC                       ,glFogCoordfEXT           );
    GL_GetFuncEXT(PFNGLFOGCOORDFVEXTPROC                      ,glFogCoordfvEXT          );
    GL_GetFuncEXT(PFNGLFOGCOORDDEXTPROC                       ,glFogCoorddEXT           );
    GL_GetFuncEXT(PFNGLFOGCOORDDVEXTPROC                      ,glFogCoorddvEXT          );
    GL_GetFuncEXT(PFNGLFOGCOORDPOINTEREXTPROC                 ,glFogCoordPointerEXT     );
    #endif /* GL_EXT_fog_coord */

    #ifdef GL_EXT_framebuffer_blit
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_framebuffer_blit\n");
    GL_GetFuncEXT(PFNGLBLITFRAMEBUFFEREXTPROC              ,glBlitFramebufferEXT );
    #endif /* GL_EXT_framebuffer_blit */

    #ifdef GL_EXT_framebuffer_multisample
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_framebuffer_multisample\n");
    GL_GetFuncEXT(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC              ,glRenderbufferStorageMultisampleEXT );
    #endif /* GL_EXT_framebuffer_multisample */

    #ifdef GL_EXT_framebuffer_object
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_framebuffer_object\n");
    GL_GetFuncEXT(PFNGLISRENDERBUFFEREXTPROC                                         ,glIsRenderbufferEXT                            );
    GL_GetFuncEXT(PFNGLBINDRENDERBUFFEREXTPROC                                       ,glBindRenderbufferEXT                          );
    GL_GetFuncEXT(PFNGLDELETERENDERBUFFERSEXTPROC                                    ,glDeleteRenderbuffersEXT                       );
    GL_GetFuncEXT(PFNGLGENRENDERBUFFERSEXTPROC                                       ,glGenRenderbuffersEXT                          );
    GL_GetFuncEXT(PFNGLRENDERBUFFERSTORAGEEXTPROC                                    ,glRenderbufferStorageEXT                       );
    GL_GetFuncEXT(PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC                             ,glGetRenderbufferParameterivEXT                );
    GL_GetFuncEXT(PFNGLISFRAMEBUFFEREXTPROC                                          ,glIsFramebufferEXT                             );
    GL_GetFuncEXT(PFNGLBINDFRAMEBUFFEREXTPROC                                        ,glBindFramebufferEXT                           );
    GL_GetFuncEXT(PFNGLDELETEFRAMEBUFFERSEXTPROC                                     ,glDeleteFramebuffersEXT                        );
    GL_GetFuncEXT(PFNGLGENFRAMEBUFFERSEXTPROC                                        ,glGenFramebuffersEXT                           );
    GL_GetFuncEXT(PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC                                 ,glCheckFramebufferStatusEXT                    );
    GL_GetFuncEXT(PFNGLFRAMEBUFFERTEXTURE1DEXTPROC                                   ,glFramebufferTexture1DEXT                      );
    GL_GetFuncEXT(PFNGLFRAMEBUFFERTEXTURE2DEXTPROC                                   ,glFramebufferTexture2DEXT                      );
    GL_GetFuncEXT(PFNGLFRAMEBUFFERTEXTURE3DEXTPROC                                   ,glFramebufferTexture3DEXT                      );
    GL_GetFuncEXT(PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC                                ,glFramebufferRenderbufferEXT                   );
    GL_GetFuncEXT(PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC                    ,glGetFramebufferAttachmentParameterivEXT       );
    GL_GetFuncEXT(PFNGLGENERATEMIPMAPEXTPROC                                         ,glGenerateMipmapEXT                            );
    #endif /* GL_EXT_framebuffer_object */

    #ifdef GL_EXT_geometry_shader4
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_geometry_shader4\n");
    GL_GetFuncEXT(PFNGLPROGRAMPARAMETERIEXTPROC              ,glProgramParameteriEXT );
    #endif /* GL_EXT_geometry_shader4 */

    #ifdef GL_EXT_gpu_program_parameters
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_gpu_program_parameters\n");
    GL_GetFuncEXT(PFNGLPROGRAMENVPARAMETERS4FVEXTPROC                ,glProgramEnvParameters4fvEXT    );
    GL_GetFuncEXT(PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC              ,glProgramLocalParameters4fvEXT  );
    #endif /* GL_EXT_gpu_program_parameters */

    #ifdef GL_EXT_gpu_shader4
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_gpu_shader4\n");
    GL_GetFuncEXT(PFNGLGETUNIFORMUIVEXTPROC                          ,glGetUniformuivEXT            );
    GL_GetFuncEXT(PFNGLBINDFRAGDATALOCATIONEXTPROC                   ,glBindFragDataLocationEXT     );
    GL_GetFuncEXT(PFNGLGETFRAGDATALOCATIONEXTPROC                    ,glGetFragDataLocationEXT      );
    GL_GetFuncEXT(PFNGLUNIFORM1UIEXTPROC                             ,glUniform1uiEXT               );
    GL_GetFuncEXT(PFNGLUNIFORM2UIEXTPROC                             ,glUniform2uiEXT               );
    GL_GetFuncEXT(PFNGLUNIFORM3UIEXTPROC                             ,glUniform3uiEXT               );
    GL_GetFuncEXT(PFNGLUNIFORM4UIEXTPROC                             ,glUniform4uiEXT               );
    GL_GetFuncEXT(PFNGLUNIFORM1UIVEXTPROC                            ,glUniform1uivEXT              );
    GL_GetFuncEXT(PFNGLUNIFORM2UIVEXTPROC                            ,glUniform2uivEXT              );
    GL_GetFuncEXT(PFNGLUNIFORM3UIVEXTPROC                            ,glUniform3uivEXT              );
    GL_GetFuncEXT(PFNGLUNIFORM4UIVEXTPROC                            ,glUniform4uivEXT              );
    #endif /* GL_EXT_gpu_shader4 */

    #ifdef GL_EXT_histogram
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_histogram\n");
    GL_GetFuncEXT(PFNGLGETHISTOGRAMEXTPROC                              ,glGetHistogramEXT               );
    GL_GetFuncEXT(PFNGLGETHISTOGRAMPARAMETERFVEXTPROC                   ,glGetHistogramParameterfvEXT    );
    GL_GetFuncEXT(PFNGLGETHISTOGRAMPARAMETERIVEXTPROC                   ,glGetHistogramParameterivEXT    );
    GL_GetFuncEXT(PFNGLGETMINMAXEXTPROC                                 ,glGetMinmaxEXT                  );
    GL_GetFuncEXT(PFNGLGETMINMAXPARAMETERFVEXTPROC                      ,glGetMinmaxParameterfvEXT       );
    GL_GetFuncEXT(PFNGLGETMINMAXPARAMETERIVEXTPROC                      ,glGetMinmaxParameterivEXT       );
    GL_GetFuncEXT(PFNGLHISTOGRAMEXTPROC                                 ,glHistogramEXT                  );
    GL_GetFuncEXT(PFNGLMINMAXEXTPROC                                    ,glMinmaxEXT                     );
    GL_GetFuncEXT(PFNGLRESETHISTOGRAMEXTPROC                            ,glResetHistogramEXT             );
    GL_GetFuncEXT(PFNGLRESETMINMAXEXTPROC                               ,glResetMinmaxEXT                );
    #endif /* GL_EXT_histogram */

    #ifdef GL_EXT_index_func
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_index_func\n");
    GL_GetFuncEXT(PFNGLINDEXFUNCEXTPROC              ,glIndexFuncEXT );
    #endif /* GL_EXT_index_func */

    #ifdef GL_EXT_index_material
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_index_material\n");
    GL_GetFuncEXT(PFNGLINDEXMATERIALEXTPROC              ,glIndexMaterialEXT );
    #endif /* GL_EXT_index_material */

    #ifdef GL_EXT_light_texture
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_light_texture\n");
    GL_GetFuncEXT(PFNGLAPPLYTEXTUREEXTPROC                      ,glApplyTextureEXT          );
    GL_GetFuncEXT(PFNGLTEXTURELIGHTEXTPROC                      ,glTextureLightEXT          );
    GL_GetFuncEXT(PFNGLTEXTUREMATERIALEXTPROC                   ,glTextureMaterialEXT       );
    #endif /* GL_EXT_light_texture */

    #ifdef GL_EXT_memory_object
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_memory_object\n");
    GL_GetFuncEXT(PFNGLGETUNSIGNEDBYTEVEXTPROC                                  ,glGetUnsignedBytevEXT                  );
    GL_GetFuncEXT(PFNGLGETUNSIGNEDBYTEI_VEXTPROC                                ,glGetUnsignedBytei_vEXT                );
    GL_GetFuncEXT(PFNGLDELETEMEMORYOBJECTSEXTPROC                               ,glDeleteMemoryObjectsEXT               );
    GL_GetFuncEXT(PFNGLISMEMORYOBJECTEXTPROC                                    ,glIsMemoryObjectEXT                    );
    GL_GetFuncEXT(PFNGLCREATEMEMORYOBJECTSEXTPROC                               ,glCreateMemoryObjectsEXT               );
    GL_GetFuncEXT(PFNGLMEMORYOBJECTPARAMETERIVEXTPROC                           ,glMemoryObjectParameterivEXT           );
    GL_GetFuncEXT(PFNGLGETMEMORYOBJECTPARAMETERIVEXTPROC                        ,glGetMemoryObjectParameterivEXT        );
    GL_GetFuncEXT(PFNGLTEXSTORAGEMEM2DEXTPROC                                   ,glTexStorageMem2DEXT                   );
    GL_GetFuncEXT(PFNGLTEXSTORAGEMEM2DMULTISAMPLEEXTPROC                        ,glTexStorageMem2DMultisampleEXT        );
    GL_GetFuncEXT(PFNGLTEXSTORAGEMEM3DEXTPROC                                   ,glTexStorageMem3DEXT                   );
    GL_GetFuncEXT(PFNGLTEXSTORAGEMEM3DMULTISAMPLEEXTPROC                        ,glTexStorageMem3DMultisampleEXT        );
    GL_GetFuncEXT(PFNGLBUFFERSTORAGEMEMEXTPROC                                  ,glBufferStorageMemEXT                  );
    GL_GetFuncEXT(PFNGLTEXTURESTORAGEMEM2DEXTPROC                               ,glTextureStorageMem2DEXT               );
    GL_GetFuncEXT(PFNGLTEXTURESTORAGEMEM2DMULTISAMPLEEXTPROC                    ,glTextureStorageMem2DMultisampleEXT    );
    GL_GetFuncEXT(PFNGLTEXTURESTORAGEMEM3DEXTPROC                               ,glTextureStorageMem3DEXT               );
    GL_GetFuncEXT(PFNGLTEXTURESTORAGEMEM3DMULTISAMPLEEXTPROC                    ,glTextureStorageMem3DMultisampleEXT    );
    GL_GetFuncEXT(PFNGLNAMEDBUFFERSTORAGEMEMEXTPROC                             ,glNamedBufferStorageMemEXT             );
    GL_GetFuncEXT(PFNGLTEXSTORAGEMEM1DEXTPROC                                   ,glTexStorageMem1DEXT                   );
    GL_GetFuncEXT(PFNGLTEXTURESTORAGEMEM1DEXTPROC                               ,glTextureStorageMem1DEXT               );
    #endif /* GL_EXT_memory_object */

    #ifdef GL_EXT_memory_object_fd
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_memory_object_fd\n");
    GL_GetFuncEXT(PFNGLIMPORTMEMORYFDEXTPROC              ,glImportMemoryFdEXT );
    #endif /* GL_EXT_memory_object_fd */

    #ifdef GL_EXT_memory_object_win32
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_memory_object_win32\n");
    GL_GetFuncEXT(PFNGLIMPORTMEMORYWIN32HANDLEEXTPROC              ,glImportMemoryWin32HandleEXT   );
    GL_GetFuncEXT(PFNGLIMPORTMEMORYWIN32NAMEEXTPROC                ,glImportMemoryWin32NameEXT     );
    #endif /* GL_EXT_memory_object_win32 */

    #ifdef GL_EXT_multi_draw_arrays
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_multi_draw_arrays\n");
    GL_GetFuncEXT(PFNGLMULTIDRAWARRAYSEXTPROC                ,glMultiDrawArraysEXT    );
    GL_GetFuncEXT(PFNGLMULTIDRAWELEMENTSEXTPROC              ,glMultiDrawElementsEXT  );
    #endif /* GL_EXT_multi_draw_arrays */

    #ifdef GL_EXT_multisample
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_multisample\n");
    GL_GetFuncEXT(PFNGLSAMPLEMASKEXTPROC                  ,glSampleMaskEXT     );
    GL_GetFuncEXT(PFNGLSAMPLEPATTERNEXTPROC               ,glSamplePatternEXT  );
    #endif /* GL_EXT_multisample */

    #ifdef GL_EXT_paletted_texture
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_paletted_texture\n");
    GL_GetFuncEXT(PFNGLCOLORTABLEEXTPROC                                ,glColorTableEXT                   );
    GL_GetFuncEXT(PFNGLGETCOLORTABLEEXTPROC                             ,glGetColorTableEXT                );
    GL_GetFuncEXT(PFNGLGETCOLORTABLEPARAMETERIVEXTPROC                  ,glGetColorTableParameterivEXT     );
    GL_GetFuncEXT(PFNGLGETCOLORTABLEPARAMETERFVEXTPROC                  ,glGetColorTableParameterfvEXT     );
    #endif /* GL_EXT_paletted_texture */

    #ifdef GL_EXT_pixel_transform
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_pixel_transform\n");
    GL_GetFuncEXT(PFNGLPIXELTRANSFORMPARAMETERIEXTPROC                       ,glPixelTransformParameteriEXT          );
    GL_GetFuncEXT(PFNGLPIXELTRANSFORMPARAMETERFEXTPROC                       ,glPixelTransformParameterfEXT          );
    GL_GetFuncEXT(PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC                      ,glPixelTransformParameterivEXT         );
    GL_GetFuncEXT(PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC                      ,glPixelTransformParameterfvEXT         );
    GL_GetFuncEXT(PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC                   ,glGetPixelTransformParameterivEXT      );
    GL_GetFuncEXT(PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC                   ,glGetPixelTransformParameterfvEXT      );
    #endif /* GL_EXT_pixel_transform */

    #ifdef GL_EXT_point_parameters
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_point_parameters\n");
    GL_GetFuncEXT(PFNGLPOINTPARAMETERFEXTPROC               ,glPointParameterfEXT   );
    GL_GetFuncEXT(PFNGLPOINTPARAMETERFVEXTPROC              ,glPointParameterfvEXT  );
    #endif /* GL_EXT_point_parameters */

    #ifdef GL_EXT_polygon_offset
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_polygon_offset\n");
    GL_GetFuncEXT(PFNGLPOLYGONOFFSETEXTPROC              ,glPolygonOffsetEXT );
    #endif /* GL_EXT_polygon_offset */

    #ifdef GL_EXT_polygon_offset_clamp
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_polygon_offset_clamp\n");
    GL_GetFuncEXT(PFNGLPOLYGONOFFSETCLAMPEXTPROC              ,glPolygonOffsetClampEXT );
    #endif /* GL_EXT_polygon_offset_clamp */

    #ifdef GL_EXT_provoking_vertex
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_provoking_vertex\n");
    GL_GetFuncEXT(PFNGLPROVOKINGVERTEXEXTPROC              ,glProvokingVertexEXT );
    #endif /* GL_EXT_provoking_vertex */

    #ifdef GL_EXT_raster_multisample
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_raster_multisample\n");
    GL_GetFuncEXT(PFNGLRASTERSAMPLESEXTPROC              ,glRasterSamplesEXT );
    #endif /* GL_EXT_raster_multisample */

    #ifdef GL_EXT_secondary_color
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_secondary_color\n");
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3BEXTPROC                           ,glSecondaryColor3bEXT             );
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3BVEXTPROC                          ,glSecondaryColor3bvEXT            );
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3DEXTPROC                           ,glSecondaryColor3dEXT             );
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3DVEXTPROC                          ,glSecondaryColor3dvEXT            );
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3FEXTPROC                           ,glSecondaryColor3fEXT             );
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3FVEXTPROC                          ,glSecondaryColor3fvEXT            );
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3IEXTPROC                           ,glSecondaryColor3iEXT             );
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3IVEXTPROC                          ,glSecondaryColor3ivEXT            );
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3SEXTPROC                           ,glSecondaryColor3sEXT             );
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3SVEXTPROC                          ,glSecondaryColor3svEXT            );
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3UBEXTPROC                          ,glSecondaryColor3ubEXT            );
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3UBVEXTPROC                         ,glSecondaryColor3ubvEXT           );
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3UIEXTPROC                          ,glSecondaryColor3uiEXT            );
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3UIVEXTPROC                         ,glSecondaryColor3uivEXT           );
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3USEXTPROC                          ,glSecondaryColor3usEXT            );
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3USVEXTPROC                         ,glSecondaryColor3usvEXT           );
    GL_GetFuncEXT(PFNGLSECONDARYCOLORPOINTEREXTPROC                      ,glSecondaryColorPointerEXT        );
    #endif /* GL_EXT_secondary_color */

    #ifdef GL_EXT_semaphore
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_semaphore\n");
    GL_GetFuncEXT(PFNGLGENSEMAPHORESEXTPROC                                 ,glGenSemaphoresEXT                   );
    GL_GetFuncEXT(PFNGLDELETESEMAPHORESEXTPROC                              ,glDeleteSemaphoresEXT                );
    GL_GetFuncEXT(PFNGLISSEMAPHOREEXTPROC                                   ,glIsSemaphoreEXT                     );
    GL_GetFuncEXT(PFNGLSEMAPHOREPARAMETERUI64VEXTPROC                       ,glSemaphoreParameterui64vEXT         );
    GL_GetFuncEXT(PFNGLGETSEMAPHOREPARAMETERUI64VEXTPROC                    ,glGetSemaphoreParameterui64vEXT      );
    GL_GetFuncEXT(PFNGLWAITSEMAPHOREEXTPROC                                 ,glWaitSemaphoreEXT                   );
    GL_GetFuncEXT(PFNGLSIGNALSEMAPHOREEXTPROC                               ,glSignalSemaphoreEXT                 );
    #endif /* GL_EXT_semaphore */

    #ifdef GL_EXT_semaphore_fd
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_semaphore_fd\n");
    GL_GetFuncEXT(PFNGLIMPORTSEMAPHOREFDEXTPROC              ,glImportSemaphoreFdEXT );
    #endif /* GL_EXT_semaphore_fd */

    #ifdef GL_EXT_semaphore_win32
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_semaphore_win32\n");
    GL_GetFuncEXT(PFNGLIMPORTSEMAPHOREWIN32HANDLEEXTPROC              ,glImportSemaphoreWin32HandleEXT   );
    GL_GetFuncEXT(PFNGLIMPORTSEMAPHOREWIN32NAMEEXTPROC                ,glImportSemaphoreWin32NameEXT     );
    #endif /* GL_EXT_semaphore_win32 */

    #ifdef GL_EXT_separate_shader_objects
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_separate_shader_objects\n");
    GL_GetFuncEXT(PFNGLUSESHADERPROGRAMEXTPROC                      ,glUseShaderProgramEXT        );
    GL_GetFuncEXT(PFNGLACTIVEPROGRAMEXTPROC                         ,glActiveProgramEXT           );
    GL_GetFuncEXT(PFNGLCREATESHADERPROGRAMEXTPROC                   ,glCreateShaderProgramEXT     );
    #endif /* GL_EXT_separate_shader_objects */

    #ifdef GL_EXT_shader_framebuffer_fetch_non_coherent
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_shader_framebuffer_fetch_non_coherent\n");
    GL_GetFuncEXT(PFNGLFRAMEBUFFERFETCHBARRIEREXTPROC              ,glFramebufferFetchBarrierEXT );
    #endif /* GL_EXT_shader_framebuffer_fetch_non_coherent */

    #ifdef GL_EXT_shader_image_load_store
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_shader_image_load_store\n");
    GL_GetFuncEXT(PFNGLBINDIMAGETEXTUREEXTPROC               ,glBindImageTextureEXT   );
    GL_GetFuncEXT(PFNGLMEMORYBARRIEREXTPROC                  ,glMemoryBarrierEXT      );
    #endif /* GL_EXT_shader_image_load_store */

    #ifdef GL_EXT_stencil_clear_tag
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_stencil_clear_tag\n");
    GL_GetFuncEXT(PFNGLSTENCILCLEARTAGEXTPROC              ,glStencilClearTagEXT );
    #endif /* GL_EXT_stencil_clear_tag */

    #ifdef GL_EXT_stencil_two_side
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_stencil_two_side\n");
    GL_GetFuncEXT(PFNGLACTIVESTENCILFACEEXTPROC              ,glActiveStencilFaceEXT );
    #endif /* GL_EXT_stencil_two_side */

    #ifdef GL_EXT_subtexture
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_subtexture\n");
    GL_GetFuncEXT(PFNGLTEXSUBIMAGE1DEXTPROC               ,glTexSubImage1DEXT );
    GL_GetFuncEXT(PFNGLTEXSUBIMAGE2DEXTPROC               ,glTexSubImage2DEXT );
    #endif /* GL_EXT_subtexture */

    #ifdef GL_EXT_texture3D
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_texture3D\n");
    GL_GetFuncEXT(PFNGLTEXIMAGE3DEXTPROC                  ,glTexImage3DEXT       );
    GL_GetFuncEXT(PFNGLTEXSUBIMAGE3DEXTPROC               ,glTexSubImage3DEXT    );
    #endif /* GL_EXT_texture3D */

    #ifdef GL_EXT_texture_array
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_texture_array\n");
    GL_GetFuncEXT(PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC              ,glFramebufferTextureLayerEXT );
    #endif /* GL_EXT_texture_array */

    #ifdef GL_EXT_texture_buffer_object
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_texture_buffer_object\n");
    GL_GetFuncEXT(PFNGLTEXBUFFEREXTPROC              ,glTexBufferEXT );
    #endif /* GL_EXT_texture_buffer_object */

    #ifdef GL_EXT_texture_integer
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_texture_integer\n");
    GL_GetFuncEXT(PFNGLTEXPARAMETERIIVEXTPROC                     ,glTexParameterIivEXT         );
    GL_GetFuncEXT(PFNGLTEXPARAMETERIUIVEXTPROC                    ,glTexParameterIuivEXT        );
    GL_GetFuncEXT(PFNGLGETTEXPARAMETERIIVEXTPROC                  ,glGetTexParameterIivEXT      );
    GL_GetFuncEXT(PFNGLGETTEXPARAMETERIUIVEXTPROC                 ,glGetTexParameterIuivEXT     );
    GL_GetFuncEXT(PFNGLCLEARCOLORIIEXTPROC                        ,glClearColorIiEXT            );
    GL_GetFuncEXT(PFNGLCLEARCOLORIUIEXTPROC                       ,glClearColorIuiEXT           );
    #endif /* GL_EXT_texture_integer */

    #ifdef GL_EXT_texture_object
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_texture_object\n");
    GL_GetFuncEXT(PFNGLARETEXTURESRESIDENTEXTPROC                   ,glAreTexturesResidentEXT  );
    GL_GetFuncEXT(PFNGLBINDTEXTUREEXTPROC                           ,glBindTextureEXT          );
    GL_GetFuncEXT(PFNGLDELETETEXTURESEXTPROC                        ,glDeleteTexturesEXT       );
    GL_GetFuncEXT(PFNGLGENTEXTURESEXTPROC                           ,glGenTexturesEXT          );
    GL_GetFuncEXT(PFNGLISTEXTUREEXTPROC                             ,glIsTextureEXT            );
    GL_GetFuncEXT(PFNGLPRIORITIZETEXTURESEXTPROC                    ,glPrioritizeTexturesEXT   );
    #endif /* GL_EXT_texture_object */

    #ifdef GL_EXT_texture_perturb_normal
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_texture_perturb_normal\n");
    GL_GetFuncEXT(PFNGLTEXTURENORMALEXTPROC              ,glTextureNormalEXT );
    #endif /* GL_EXT_texture_perturb_normal */

    #ifdef GL_EXT_timer_query
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_timer_query\n");
    GL_GetFuncEXT(PFNGLGETQUERYOBJECTI64VEXTPROC                ,glGetQueryObjecti64vEXT    );
    GL_GetFuncEXT(PFNGLGETQUERYOBJECTUI64VEXTPROC               ,glGetQueryObjectui64vEXT   );
    #endif /* GL_EXT_timer_query */

    #ifdef GL_EXT_transform_feedback
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_transform_feedback\n");
    GL_GetFuncEXT(PFNGLBEGINTRANSFORMFEEDBACKEXTPROC                       ,glBeginTransformFeedbackEXT           );
    GL_GetFuncEXT(PFNGLENDTRANSFORMFEEDBACKEXTPROC                         ,glEndTransformFeedbackEXT             );
    GL_GetFuncEXT(PFNGLBINDBUFFERRANGEEXTPROC                              ,glBindBufferRangeEXT                  );
    GL_GetFuncEXT(PFNGLBINDBUFFEROFFSETEXTPROC                             ,glBindBufferOffsetEXT                 );
    GL_GetFuncEXT(PFNGLBINDBUFFERBASEEXTPROC                               ,glBindBufferBaseEXT                   );
    GL_GetFuncEXT(PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC                    ,glTransformFeedbackVaryingsEXT        );
    GL_GetFuncEXT(PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC                  ,glGetTransformFeedbackVaryingEXT      );
    #endif /* GL_EXT_transform_feedback */

    #ifdef GL_EXT_vertex_array
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_vertex_array\n");
    GL_GetFuncEXT(PFNGLARRAYELEMENTEXTPROC                        ,glArrayElementEXT                   );
    GL_GetFuncEXT(PFNGLCOLORPOINTEREXTPROC                        ,glColorPointerEXT                   );
    GL_GetFuncEXT(PFNGLDRAWARRAYSEXTPROC                          ,glDrawArraysEXT                     );
    GL_GetFuncEXT(PFNGLEDGEFLAGPOINTEREXTPROC                     ,glEdgeFlagPointerEXT                );
    GL_GetFuncEXT(PFNGLGETPOINTERVEXTPROC                         ,glGetPointervEXT                    );
    GL_GetFuncEXT(PFNGLINDEXPOINTEREXTPROC                        ,glIndexPointerEXT                   );
    GL_GetFuncEXT(PFNGLNORMALPOINTEREXTPROC                       ,glNormalPointerEXT                  );
    GL_GetFuncEXT(PFNGLTEXCOORDPOINTEREXTPROC                     ,glTexCoordPointerEXT                );
    GL_GetFuncEXT(PFNGLVERTEXPOINTEREXTPROC                       ,glVertexPointerEXT                  );
	#ifdef __gl_h_
	#ifdef __GL_H__
	/* EXT_vertex_array */             /* EXT_vertex_array */
	GL_GetFuncEXT(PFNGLARRAYELEMENTARRAYEXTPROC                   ,glArrayElementArrayEXT              );
	/* WIN_draw_range_elements */      /* WIN_draw_range_elements */
	GL_GetFuncEXT(PFNGLDRAWRANGEELEMENTSWINPROC                   ,glDrawRangeElementsWIN              );
	/* WIN_swap_hint */                /* WIN_swap_hint */
	GL_GetFuncEXT(PFNGLADDSWAPHINTRECTWINPROC                     ,glAddSwapHintRectWIN                );
    #endif /* __GL_H__ */
    #endif /* __gl_h_ */
    #endif /* GL_EXT_vertex_array */

    #ifdef GL_EXT_vertex_attrib_64bit
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_vertex_attrib_64bit\n");
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL1DEXTPROC                         ,glVertexAttribL1dEXT              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL2DEXTPROC                         ,glVertexAttribL2dEXT              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL3DEXTPROC                         ,glVertexAttribL3dEXT              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL4DEXTPROC                         ,glVertexAttribL4dEXT              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL1DVEXTPROC                        ,glVertexAttribL1dvEXT             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL2DVEXTPROC                        ,glVertexAttribL2dvEXT             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL3DVEXTPROC                        ,glVertexAttribL3dvEXT             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL4DVEXTPROC                        ,glVertexAttribL4dvEXT             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBLPOINTEREXTPROC                    ,glVertexAttribLPointerEXT         );
    GL_GetFuncEXT(PFNGLGETVERTEXATTRIBLDVEXTPROC                      ,glGetVertexAttribLdvEXT           );
    #endif /* GL_EXT_vertex_attrib_64bit */

    #ifdef GL_EXT_vertex_shader
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_vertex_shader\n");
    GL_GetFuncEXT(PFNGLBEGINVERTEXSHADEREXTPROC                               ,glBeginVertexShaderEXT                    );
    GL_GetFuncEXT(PFNGLENDVERTEXSHADEREXTPROC                                 ,glEndVertexShaderEXT                      );
    GL_GetFuncEXT(PFNGLBINDVERTEXSHADEREXTPROC                                ,glBindVertexShaderEXT                     );
    GL_GetFuncEXT(PFNGLGENVERTEXSHADERSEXTPROC                                ,glGenVertexShadersEXT                     );
    GL_GetFuncEXT(PFNGLDELETEVERTEXSHADEREXTPROC                              ,glDeleteVertexShaderEXT                   );
    GL_GetFuncEXT(PFNGLSHADEROP1EXTPROC                                       ,glShaderOp1EXT                            );
    GL_GetFuncEXT(PFNGLSHADEROP2EXTPROC                                       ,glShaderOp2EXT                            );
    GL_GetFuncEXT(PFNGLSHADEROP3EXTPROC                                       ,glShaderOp3EXT                            );
    GL_GetFuncEXT(PFNGLSWIZZLEEXTPROC                                         ,glSwizzleEXT                              );
    GL_GetFuncEXT(PFNGLWRITEMASKEXTPROC                                       ,glWriteMaskEXT                            );
    GL_GetFuncEXT(PFNGLINSERTCOMPONENTEXTPROC                                 ,glInsertComponentEXT                      );
    GL_GetFuncEXT(PFNGLEXTRACTCOMPONENTEXTPROC                                ,glExtractComponentEXT                     );
    GL_GetFuncEXT(PFNGLGENSYMBOLSEXTPROC                                      ,glGenSymbolsEXT                           );
    GL_GetFuncEXT(PFNGLSETINVARIANTEXTPROC                                    ,glSetInvariantEXT                         );
    GL_GetFuncEXT(PFNGLSETLOCALCONSTANTEXTPROC                                ,glSetLocalConstantEXT                     );
    GL_GetFuncEXT(PFNGLVARIANTBVEXTPROC                                       ,glVariantbvEXT                            );
    GL_GetFuncEXT(PFNGLVARIANTSVEXTPROC                                       ,glVariantsvEXT                            );
    GL_GetFuncEXT(PFNGLVARIANTIVEXTPROC                                       ,glVariantivEXT                            );
    GL_GetFuncEXT(PFNGLVARIANTFVEXTPROC                                       ,glVariantfvEXT                            );
    GL_GetFuncEXT(PFNGLVARIANTDVEXTPROC                                       ,glVariantdvEXT                            );
    GL_GetFuncEXT(PFNGLVARIANTUBVEXTPROC                                      ,glVariantubvEXT                           );
    GL_GetFuncEXT(PFNGLVARIANTUSVEXTPROC                                      ,glVariantusvEXT                           );
    GL_GetFuncEXT(PFNGLVARIANTUIVEXTPROC                                      ,glVariantuivEXT                           );
    GL_GetFuncEXT(PFNGLVARIANTPOINTEREXTPROC                                  ,glVariantPointerEXT                       );
    GL_GetFuncEXT(PFNGLENABLEVARIANTCLIENTSTATEEXTPROC                        ,glEnableVariantClientStateEXT             );
    GL_GetFuncEXT(PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC                       ,glDisableVariantClientStateEXT            );
    GL_GetFuncEXT(PFNGLBINDLIGHTPARAMETEREXTPROC                              ,glBindLightParameterEXT                   );
    GL_GetFuncEXT(PFNGLBINDMATERIALPARAMETEREXTPROC                           ,glBindMaterialParameterEXT                );
    GL_GetFuncEXT(PFNGLBINDTEXGENPARAMETEREXTPROC                             ,glBindTexGenParameterEXT                  );
    GL_GetFuncEXT(PFNGLBINDTEXTUREUNITPARAMETEREXTPROC                        ,glBindTextureUnitParameterEXT             );
    GL_GetFuncEXT(PFNGLBINDPARAMETEREXTPROC                                   ,glBindParameterEXT                        );
    GL_GetFuncEXT(PFNGLISVARIANTENABLEDEXTPROC                                ,glIsVariantEnabledEXT                     );
    GL_GetFuncEXT(PFNGLGETVARIANTBOOLEANVEXTPROC                              ,glGetVariantBooleanvEXT                   );
    GL_GetFuncEXT(PFNGLGETVARIANTINTEGERVEXTPROC                              ,glGetVariantIntegervEXT                   );
    GL_GetFuncEXT(PFNGLGETVARIANTFLOATVEXTPROC                                ,glGetVariantFloatvEXT                     );
    GL_GetFuncEXT(PFNGLGETVARIANTPOINTERVEXTPROC                              ,glGetVariantPointervEXT                   );
    GL_GetFuncEXT(PFNGLGETINVARIANTBOOLEANVEXTPROC                            ,glGetInvariantBooleanvEXT                 );
    GL_GetFuncEXT(PFNGLGETINVARIANTINTEGERVEXTPROC                            ,glGetInvariantIntegervEXT                 );
    GL_GetFuncEXT(PFNGLGETINVARIANTFLOATVEXTPROC                              ,glGetInvariantFloatvEXT                   );
    GL_GetFuncEXT(PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC                        ,glGetLocalConstantBooleanvEXT             );
    GL_GetFuncEXT(PFNGLGETLOCALCONSTANTINTEGERVEXTPROC                        ,glGetLocalConstantIntegervEXT             );
    GL_GetFuncEXT(PFNGLGETLOCALCONSTANTFLOATVEXTPROC                          ,glGetLocalConstantFloatvEXT               );
    #endif /* GL_EXT_vertex_shader */

    #ifdef GL_EXT_vertex_weighting
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_vertex_weighting\n");
    GL_GetFuncEXT(PFNGLVERTEXWEIGHTFEXTPROC                         ,glVertexWeightfEXT          );
    GL_GetFuncEXT(PFNGLVERTEXWEIGHTFVEXTPROC                        ,glVertexWeightfvEXT         );
    GL_GetFuncEXT(PFNGLVERTEXWEIGHTPOINTEREXTPROC                   ,glVertexWeightPointerEXT    );
    #endif /* GL_EXT_vertex_weighting */

    #ifdef GL_EXT_win32_keyed_mutex
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_win32_keyed_mutex\n");
    GL_GetFuncEXT(PFNGLACQUIREKEYEDMUTEXWIN32EXTPROC                ,glAcquireKeyedMutexWin32EXT );
    GL_GetFuncEXT(PFNGLRELEASEKEYEDMUTEXWIN32EXTPROC                ,glReleaseKeyedMutexWin32EXT );
    #endif /* GL_EXT_win32_keyed_mutex */

    #ifdef GL_EXT_window_rectangles
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_window_rectangles\n");
    GL_GetFuncEXT(PFNGLWINDOWRECTANGLESEXTPROC              ,glWindowRectanglesEXT );
    #endif /* GL_EXT_window_rectangles */

    #ifdef GL_EXT_x11_sync_object
	fprintf(LogGlGetFunctions_py, "\nGL_EXT_x11_sync_object\n");
    GL_GetFuncEXT(PFNGLIMPORTSYNCEXTPROC              ,glImportSyncEXT );
    #endif /* GL_EXT_x11_sync_object */

	
	
    #ifdef GL_GREMEDY_frame_terminator
	fprintf(LogGlGetFunctions_py, "\nGL_GREMEDY_frame_terminator\n");
    GL_GetFuncEXT(PFNGLFRAMETERMINATORGREMEDYPROC              ,glFrameTerminatorGREMEDY );
    #endif /* GL_GREMEDY_frame_terminator */

    #ifdef GL_GREMEDY_string_marker
	fprintf(LogGlGetFunctions_py, "\nGL_GREMEDY_string_marker\n");
    GL_GetFuncEXT(PFNGLSTRINGMARKERGREMEDYPROC              ,glStringMarkerGREMEDY );
    #endif /* GL_GREMEDY_string_marker */


	
    #ifdef GL_HP_image_transform
	fprintf(LogGlGetFunctions_py, "\nGL_HP_image_transform\n");
    GL_GetFuncEXT(PFNGLIMAGETRANSFORMPARAMETERIHPPROC                      ,glImageTransformParameteriHP          );
    GL_GetFuncEXT(PFNGLIMAGETRANSFORMPARAMETERFHPPROC                      ,glImageTransformParameterfHP          );
    GL_GetFuncEXT(PFNGLIMAGETRANSFORMPARAMETERIVHPPROC                     ,glImageTransformParameterivHP         );
    GL_GetFuncEXT(PFNGLIMAGETRANSFORMPARAMETERFVHPPROC                     ,glImageTransformParameterfvHP         );
    GL_GetFuncEXT(PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC                  ,glGetImageTransformParameterivHP      );
    GL_GetFuncEXT(PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC                  ,glGetImageTransformParameterfvHP      );
    #endif /* GL_HP_image_transform */

	

    #ifdef GL_IBM_multimode_draw_arrays
	fprintf(LogGlGetFunctions_py, "\nGL_IBM_multimode_draw_arrays\n");
    GL_GetFuncEXT(PFNGLMULTIMODEDRAWARRAYSIBMPROC                 ,glMultiModeDrawArraysIBM   );
    GL_GetFuncEXT(PFNGLMULTIMODEDRAWELEMENTSIBMPROC               ,glMultiModeDrawElementsIBM );
    #endif /* GL_IBM_multimode_draw_arrays */

    #ifdef GL_IBM_static_data
	fprintf(LogGlGetFunctions_py, "\nGL_IBM_static_data\n");
    GL_GetFuncEXT(PFNGLFLUSHSTATICDATAIBMPROC              ,glFlushStaticDataIBM );
    #endif /* GL_IBM_static_data */

    #ifdef GL_IBM_vertex_array_lists
	fprintf(LogGlGetFunctions_py, "\nGL_IBM_vertex_array_lists\n");
    GL_GetFuncEXT(PFNGLCOLORPOINTERLISTIBMPROC                            ,glColorPointerListIBM            );
    GL_GetFuncEXT(PFNGLSECONDARYCOLORPOINTERLISTIBMPROC                   ,glSecondaryColorPointerListIBM   );
    GL_GetFuncEXT(PFNGLEDGEFLAGPOINTERLISTIBMPROC                         ,glEdgeFlagPointerListIBM         );
    GL_GetFuncEXT(PFNGLFOGCOORDPOINTERLISTIBMPROC                         ,glFogCoordPointerListIBM         );
    GL_GetFuncEXT(PFNGLINDEXPOINTERLISTIBMPROC                            ,glIndexPointerListIBM            );
    GL_GetFuncEXT(PFNGLNORMALPOINTERLISTIBMPROC                           ,glNormalPointerListIBM           );
    GL_GetFuncEXT(PFNGLTEXCOORDPOINTERLISTIBMPROC                         ,glTexCoordPointerListIBM         );
    GL_GetFuncEXT(PFNGLVERTEXPOINTERLISTIBMPROC                           ,glVertexPointerListIBM           );
    #endif /* GL_IBM_vertex_array_lists */

	
	
    #ifdef GL_INGR_blend_func_separate
	fprintf(LogGlGetFunctions_py, "\nGL_INGR_blend_func_separate\n");
    GL_GetFuncEXT(PFNGLBLENDFUNCSEPARATEINGRPROC              ,glBlendFuncSeparateINGR );
    #endif /* GL_INGR_blend_func_separate */


	
    #ifdef GL_INTEL_framebuffer_CMAA
	fprintf(LogGlGetFunctions_py, "\nGL_INTEL_framebuffer_CMAA\n");
    GL_GetFuncEXT(PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC              ,glApplyFramebufferAttachmentCMAAINTEL );
    #endif /* GL_INTEL_framebuffer_CMAA */

    #ifdef GL_INTEL_map_texture
	fprintf(LogGlGetFunctions_py, "\nGL_INTEL_map_texture\n");
    GL_GetFuncEXT(PFNGLSYNCTEXTUREINTELPROC                 ,glSyncTextureINTEL     );
    GL_GetFuncEXT(PFNGLUNMAPTEXTURE2DINTELPROC               ,glUnmapTexture2DINTEL  );
	GL_GetFuncEXT(PFNGLMAPTEXTURE2DINTELPROC                ,glMapTexture2DINTEL    );
    #endif /* GL_INTEL_map_texture */

    #ifdef GL_INTEL_parallel_arrays
	fprintf(LogGlGetFunctions_py, "\nGL_INTEL_parallel_arrays\n");
    GL_GetFuncEXT(PFNGLVERTEXPOINTERVINTELPROC                    ,glVertexPointervINTEL      );
    GL_GetFuncEXT(PFNGLNORMALPOINTERVINTELPROC                    ,glNormalPointervINTEL      );
    GL_GetFuncEXT(PFNGLCOLORPOINTERVINTELPROC                     ,glColorPointervINTEL       );
    GL_GetFuncEXT(PFNGLTEXCOORDPOINTERVINTELPROC                  ,glTexCoordPointervINTEL    );
    #endif /* GL_INTEL_parallel_arrays */

    #ifdef GL_INTEL_performance_query
	fprintf(LogGlGetFunctions_py, "\nGL_INTEL_performance_query\n");
    GL_GetFuncEXT(PFNGLBEGINPERFQUERYINTELPROC                          ,glBeginPerfQueryINTEL         );
    GL_GetFuncEXT(PFNGLCREATEPERFQUERYINTELPROC                         ,glCreatePerfQueryINTEL        );
    GL_GetFuncEXT(PFNGLDELETEPERFQUERYINTELPROC                         ,glDeletePerfQueryINTEL        );
    GL_GetFuncEXT(PFNGLENDPERFQUERYINTELPROC                            ,glEndPerfQueryINTEL           );
    GL_GetFuncEXT(PFNGLGETFIRSTPERFQUERYIDINTELPROC                     ,glGetFirstPerfQueryIdINTEL    );
    GL_GetFuncEXT(PFNGLGETNEXTPERFQUERYIDINTELPROC                      ,glGetNextPerfQueryIdINTEL     );
    GL_GetFuncEXT(PFNGLGETPERFCOUNTERINFOINTELPROC                      ,glGetPerfCounterInfoINTEL     );
    GL_GetFuncEXT(PFNGLGETPERFQUERYDATAINTELPROC                        ,glGetPerfQueryDataINTEL       );
    GL_GetFuncEXT(PFNGLGETPERFQUERYIDBYNAMEINTELPROC                    ,glGetPerfQueryIdByNameINTEL   );
    GL_GetFuncEXT(PFNGLGETPERFQUERYINFOINTELPROC                        ,glGetPerfQueryInfoINTEL       );
    #endif /* GL_INTEL_performance_query */

	

    #ifdef GL_MESA_resize_buffers
	fprintf(LogGlGetFunctions_py, "\nGL_MESA_resize_buffers\n");
    GL_GetFuncEXT(PFNGLRESIZEBUFFERSMESAPROC              ,glResizeBuffersMESA );
    #endif /* GL_MESA_resize_buffers */

    #ifdef GL_MESA_window_pos
	fprintf(LogGlGetFunctions_py, "\nGL_MESA_window_pos\n");
    GL_GetFuncEXT(PFNGLWINDOWPOS2DMESAPROC                      ,glWindowPos2dMESA       );
    GL_GetFuncEXT(PFNGLWINDOWPOS2DVMESAPROC                     ,glWindowPos2dvMESA      );
    GL_GetFuncEXT(PFNGLWINDOWPOS2FMESAPROC                      ,glWindowPos2fMESA       );
    GL_GetFuncEXT(PFNGLWINDOWPOS2FVMESAPROC                     ,glWindowPos2fvMESA      );
    GL_GetFuncEXT(PFNGLWINDOWPOS2IMESAPROC                      ,glWindowPos2iMESA       );
    GL_GetFuncEXT(PFNGLWINDOWPOS2IVMESAPROC                     ,glWindowPos2ivMESA      );
    GL_GetFuncEXT(PFNGLWINDOWPOS2SMESAPROC                      ,glWindowPos2sMESA       );
    GL_GetFuncEXT(PFNGLWINDOWPOS2SVMESAPROC                     ,glWindowPos2svMESA      );
    GL_GetFuncEXT(PFNGLWINDOWPOS3DMESAPROC                      ,glWindowPos3dMESA       );
    GL_GetFuncEXT(PFNGLWINDOWPOS3DVMESAPROC                     ,glWindowPos3dvMESA      );
    GL_GetFuncEXT(PFNGLWINDOWPOS3FMESAPROC                      ,glWindowPos3fMESA       );
    GL_GetFuncEXT(PFNGLWINDOWPOS3FVMESAPROC                     ,glWindowPos3fvMESA      );
    GL_GetFuncEXT(PFNGLWINDOWPOS3IMESAPROC                      ,glWindowPos3iMESA       );
    GL_GetFuncEXT(PFNGLWINDOWPOS3IVMESAPROC                     ,glWindowPos3ivMESA      );
    GL_GetFuncEXT(PFNGLWINDOWPOS3SMESAPROC                      ,glWindowPos3sMESA       );
    GL_GetFuncEXT(PFNGLWINDOWPOS3SVMESAPROC                     ,glWindowPos3svMESA      );
    GL_GetFuncEXT(PFNGLWINDOWPOS4DMESAPROC                      ,glWindowPos4dMESA       );
    GL_GetFuncEXT(PFNGLWINDOWPOS4DVMESAPROC                     ,glWindowPos4dvMESA      );
    GL_GetFuncEXT(PFNGLWINDOWPOS4FMESAPROC                      ,glWindowPos4fMESA       );
    GL_GetFuncEXT(PFNGLWINDOWPOS4FVMESAPROC                     ,glWindowPos4fvMESA      );
    GL_GetFuncEXT(PFNGLWINDOWPOS4IMESAPROC                      ,glWindowPos4iMESA       );
    GL_GetFuncEXT(PFNGLWINDOWPOS4IVMESAPROC                     ,glWindowPos4ivMESA      );
    GL_GetFuncEXT(PFNGLWINDOWPOS4SMESAPROC                      ,glWindowPos4sMESA       );
    GL_GetFuncEXT(PFNGLWINDOWPOS4SVMESAPROC                     ,glWindowPos4svMESA      );
    #endif /* GL_MESA_window_pos */



    #ifdef GL_NVX_conditional_render
	fprintf(LogGlGetFunctions_py, "\nGL_NVX_conditional_render\n");
    GL_GetFuncEXT(PFNGLBEGINCONDITIONALRENDERNVXPROC                ,glBeginConditionalRenderNVX    );
    GL_GetFuncEXT(PFNGLENDCONDITIONALRENDERNVXPROC                  ,glEndConditionalRenderNVX      );
    #endif /* GL_NVX_conditional_render */

    #ifdef GL_NVX_linked_gpu_multicast
	fprintf(LogGlGetFunctions_py, "\nGL_NVX_linked_gpu_multicast\n");
    GL_GetFuncEXT(PFNGLLGPUNAMEDBUFFERSUBDATANVXPROC                 ,glLGPUNamedBufferSubDataNVX    );
    GL_GetFuncEXT(PFNGLLGPUCOPYIMAGESUBDATANVXPROC                   ,glLGPUCopyImageSubDataNVX      );
    GL_GetFuncEXT(PFNGLLGPUINTERLOCKNVXPROC                          ,glLGPUInterlockNVX             );
    #endif /* GL_NVX_linked_gpu_multicast */

		
    #ifdef GL_NV_alpha_to_coverage_dither_control
	fprintf(LogGlGetFunctions_py, "\nGL_NV_alpha_to_coverage_dither_control\n");
    GL_GetFuncEXT(PFNGLALPHATOCOVERAGEDITHERCONTROLNVPROC              ,glAlphaToCoverageDitherControlNV );
    #endif /* GL_NV_alpha_to_coverage_dither_control */

    #ifdef GL_NV_bindless_multi_draw_indirect
	fprintf(LogGlGetFunctions_py, "\nGL_NV_bindless_multi_draw_indirect\n");
    GL_GetFuncEXT(PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC                 ,glMultiDrawArraysIndirectBindlessNV    );
    GL_GetFuncEXT(PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC               ,glMultiDrawElementsIndirectBindlessNV  );
    #endif /* GL_NV_bindless_multi_draw_indirect */

    #ifdef GL_NV_bindless_multi_draw_indirect_count
	fprintf(LogGlGetFunctions_py, "\nGL_NV_bindless_multi_draw_indirect_count\n");
    GL_GetFuncEXT(PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC                 ,glMultiDrawArraysIndirectBindlessCountNV    );
    GL_GetFuncEXT(PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC               ,glMultiDrawElementsIndirectBindlessCountNV  );
    #endif /* GL_NV_bindless_multi_draw_indirect_count */

    #ifdef GL_NV_bindless_texture
	fprintf(LogGlGetFunctions_py, "\nGL_NV_bindless_texture\n");
    GL_GetFuncEXT(PFNGLGETTEXTUREHANDLENVPROC                             ,glGetTextureHandleNV                 );
    GL_GetFuncEXT(PFNGLGETTEXTURESAMPLERHANDLENVPROC                      ,glGetTextureSamplerHandleNV          );
    GL_GetFuncEXT(PFNGLMAKETEXTUREHANDLERESIDENTNVPROC                    ,glMakeTextureHandleResidentNV        );
    GL_GetFuncEXT(PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC                 ,glMakeTextureHandleNonResidentNV     );
    GL_GetFuncEXT(PFNGLGETIMAGEHANDLENVPROC                               ,glGetImageHandleNV                   );
    GL_GetFuncEXT(PFNGLMAKEIMAGEHANDLERESIDENTNVPROC                      ,glMakeImageHandleResidentNV          );
    GL_GetFuncEXT(PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC                   ,glMakeImageHandleNonResidentNV       );
    GL_GetFuncEXT(PFNGLUNIFORMHANDLEUI64NVPROC                            ,glUniformHandleui64NV                );
    GL_GetFuncEXT(PFNGLUNIFORMHANDLEUI64VNVPROC                           ,glUniformHandleui64vNV               );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC                     ,glProgramUniformHandleui64NV         );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC                    ,glProgramUniformHandleui64vNV        );
    GL_GetFuncEXT(PFNGLISTEXTUREHANDLERESIDENTNVPROC                      ,glIsTextureHandleResidentNV          );
    GL_GetFuncEXT(PFNGLISIMAGEHANDLERESIDENTNVPROC                        ,glIsImageHandleResidentNV            );
    #endif /* GL_NV_bindless_texture */

    #ifdef GL_NV_blend_equation_advanced
	fprintf(LogGlGetFunctions_py, "\nGL_NV_blend_equation_advanced\n");
    GL_GetFuncEXT(PFNGLBLENDPARAMETERINVPROC                ,glBlendParameteriNV   );
    GL_GetFuncEXT(PFNGLBLENDBARRIERNVPROC                   ,glBlendBarrierNV      );
    #endif /* GL_NV_blend_equation_advanced */

    #ifdef GL_NV_clip_space_w_scaling
	fprintf(LogGlGetFunctions_py, "\nGL_NV_clip_space_w_scaling\n");
    GL_GetFuncEXT(PFNGLVIEWPORTPOSITIONWSCALENVPROC              ,glViewportPositionWScaleNV );
    #endif /* GL_NV_clip_space_w_scaling */

    #ifdef GL_NV_command_list
	fprintf(LogGlGetFunctions_py, "\nGL_NV_command_list\n");
    GL_GetFuncEXT(PFNGLCREATESTATESNVPROC                                   ,glCreateStatesNV                    );
    GL_GetFuncEXT(PFNGLDELETESTATESNVPROC                                   ,glDeleteStatesNV                    );
    GL_GetFuncEXT(PFNGLISSTATENVPROC                                        ,glIsStateNV                         );
    GL_GetFuncEXT(PFNGLSTATECAPTURENVPROC                                   ,glStateCaptureNV                    );
    GL_GetFuncEXT(PFNGLGETCOMMANDHEADERNVPROC                               ,glGetCommandHeaderNV                );
    GL_GetFuncEXT(PFNGLGETSTAGEINDEXNVPROC                                  ,glGetStageIndexNV                   );
    GL_GetFuncEXT(PFNGLDRAWCOMMANDSNVPROC                                   ,glDrawCommandsNV                    );
    GL_GetFuncEXT(PFNGLDRAWCOMMANDSADDRESSNVPROC                            ,glDrawCommandsAddressNV             );
    GL_GetFuncEXT(PFNGLDRAWCOMMANDSSTATESNVPROC                             ,glDrawCommandsStatesNV              );
    GL_GetFuncEXT(PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC                      ,glDrawCommandsStatesAddressNV       );
    GL_GetFuncEXT(PFNGLCREATECOMMANDLISTSNVPROC                             ,glCreateCommandListsNV              );
    GL_GetFuncEXT(PFNGLDELETECOMMANDLISTSNVPROC                             ,glDeleteCommandListsNV              );
    GL_GetFuncEXT(PFNGLISCOMMANDLISTNVPROC                                  ,glIsCommandListNV                   );
    GL_GetFuncEXT(PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC                   ,glListDrawCommandsStatesClientNV    );
    GL_GetFuncEXT(PFNGLCOMMANDLISTSEGMENTSNVPROC                            ,glCommandListSegmentsNV             );
    GL_GetFuncEXT(PFNGLCOMPILECOMMANDLISTNVPROC                             ,glCompileCommandListNV              );
    GL_GetFuncEXT(PFNGLCALLCOMMANDLISTNVPROC                                ,glCallCommandListNV                 );
    #endif /* GL_NV_command_list */

    #ifdef GL_NV_conditional_render
	fprintf(LogGlGetFunctions_py, "\nGL_NV_conditional_render\n");
    GL_GetFuncEXT(PFNGLBEGINCONDITIONALRENDERNVPROC              ,glBeginConditionalRenderNV   );
    GL_GetFuncEXT(PFNGLENDCONDITIONALRENDERNVPROC                ,glEndConditionalRenderNV     );
    #endif /* GL_NV_conditional_render */

    #ifdef GL_NV_conservative_raster
	fprintf(LogGlGetFunctions_py, "\nGL_NV_conservative_raster\n");
    GL_GetFuncEXT(PFNGLSUBPIXELPRECISIONBIASNVPROC              ,glSubpixelPrecisionBiasNV );
    #endif /* GL_NV_conservative_raster */

    #ifdef GL_NV_conservative_raster_dilate
	fprintf(LogGlGetFunctions_py, "\nGL_NV_conservative_raster_dilate\n");
    GL_GetFuncEXT(PFNGLCONSERVATIVERASTERPARAMETERFNVPROC              ,glConservativeRasterParameterfNV );
    #endif /* GL_NV_conservative_raster_dilate */

    #ifdef GL_NV_conservative_raster_pre_snap_triangles
	fprintf(LogGlGetFunctions_py, "\nGL_NV_conservative_raster_pre_snap_triangles\n");
    GL_GetFuncEXT(PFNGLCONSERVATIVERASTERPARAMETERINVPROC              ,glConservativeRasterParameteriNV );
    #endif /* GL_NV_conservative_raster_pre_snap_triangles */

    #ifdef GL_NV_copy_image
	fprintf(LogGlGetFunctions_py, "\nGL_NV_copy_image\n");
    GL_GetFuncEXT(PFNGLCOPYIMAGESUBDATANVPROC              ,glCopyImageSubDataNV );
    #endif /* GL_NV_copy_image */

    #ifdef GL_NV_depth_buffer_float
	fprintf(LogGlGetFunctions_py, "\nGL_NV_depth_buffer_float\n");
    GL_GetFuncEXT(PFNGLDEPTHRANGEDNVPROC                     ,glDepthRangedNV     );
    GL_GetFuncEXT(PFNGLCLEARDEPTHDNVPROC                     ,glClearDepthdNV     );
    GL_GetFuncEXT(PFNGLDEPTHBOUNDSDNVPROC                    ,glDepthBoundsdNV    );
    #endif /* GL_NV_depth_buffer_float */

    #ifdef GL_NV_draw_texture
	fprintf(LogGlGetFunctions_py, "\nGL_NV_draw_texture\n");
    GL_GetFuncEXT(PFNGLDRAWTEXTURENVPROC              ,glDrawTextureNV );
    #endif /* GL_NV_draw_texture */

    #ifdef GL_NV_draw_vulkan_image
	fprintf(LogGlGetFunctions_py, "\nGL_NV_draw_vulkan_image\n");
    GL_GetFuncEXT(PFNGLDRAWVKIMAGENVPROC                        ,glDrawVkImageNV         );
    GL_GetFuncEXT(PFNGLGETVKPROCADDRNVPROC                      ,glGetVkProcAddrNV       );
    GL_GetFuncEXT(PFNGLWAITVKSEMAPHORENVPROC                    ,glWaitVkSemaphoreNV     );
    GL_GetFuncEXT(PFNGLSIGNALVKSEMAPHORENVPROC                  ,glSignalVkSemaphoreNV   );
    GL_GetFuncEXT(PFNGLSIGNALVKFENCENVPROC                      ,glSignalVkFenceNV       );
    #endif /* GL_NV_draw_vulkan_image */

    #ifdef GL_NV_evaluators
	fprintf(LogGlGetFunctions_py, "\nGL_NV_evaluators\n");
    GL_GetFuncEXT(PFNGLMAPCONTROLPOINTSNVPROC                       ,glMapControlPointsNV          );
    GL_GetFuncEXT(PFNGLMAPPARAMETERIVNVPROC                         ,glMapParameterivNV            );
    GL_GetFuncEXT(PFNGLMAPPARAMETERFVNVPROC                         ,glMapParameterfvNV            );
    GL_GetFuncEXT(PFNGLGETMAPCONTROLPOINTSNVPROC                    ,glGetMapControlPointsNV       );
    GL_GetFuncEXT(PFNGLGETMAPPARAMETERIVNVPROC                      ,glGetMapParameterivNV         );
    GL_GetFuncEXT(PFNGLGETMAPPARAMETERFVNVPROC                      ,glGetMapParameterfvNV         );
    GL_GetFuncEXT(PFNGLGETMAPATTRIBPARAMETERIVNVPROC                ,glGetMapAttribParameterivNV   );
    GL_GetFuncEXT(PFNGLGETMAPATTRIBPARAMETERFVNVPROC                ,glGetMapAttribParameterfvNV   );
    GL_GetFuncEXT(PFNGLEVALMAPSNVPROC                               ,glEvalMapsNV                  );
    #endif /* GL_NV_evaluators */

    #ifdef GL_NV_explicit_multisample
	fprintf(LogGlGetFunctions_py, "\nGL_NV_explicit_multisample\n");
    GL_GetFuncEXT(PFNGLGETMULTISAMPLEFVNVPROC                   ,glGetMultisamplefvNV     );
    GL_GetFuncEXT(PFNGLSAMPLEMASKINDEXEDNVPROC                  ,glSampleMaskIndexedNV    );
    GL_GetFuncEXT(PFNGLTEXRENDERBUFFERNVPROC                    ,glTexRenderbufferNV      );
    #endif /* GL_NV_explicit_multisample */

    #ifdef GL_NV_fence
	fprintf(LogGlGetFunctions_py, "\nGL_NV_fence\n");
    GL_GetFuncEXT(PFNGLDELETEFENCESNVPROC                     ,glDeleteFencesNV    );
    GL_GetFuncEXT(PFNGLGENFENCESNVPROC                        ,glGenFencesNV       );
    GL_GetFuncEXT(PFNGLISFENCENVPROC                          ,glIsFenceNV         );
    GL_GetFuncEXT(PFNGLTESTFENCENVPROC                        ,glTestFenceNV       );
    GL_GetFuncEXT(PFNGLGETFENCEIVNVPROC                       ,glGetFenceivNV      );
    GL_GetFuncEXT(PFNGLFINISHFENCENVPROC                      ,glFinishFenceNV     );
    GL_GetFuncEXT(PFNGLSETFENCENVPROC                         ,glSetFenceNV        );
    #endif /* GL_NV_fence */

    #ifdef GL_NV_fragment_coverage_to_color
	fprintf(LogGlGetFunctions_py, "\nGL_NV_fragment_coverage_to_color\n");
    GL_GetFuncEXT(PFNGLFRAGMENTCOVERAGECOLORNVPROC                      ,glFragmentCoverageColorNV                    );
    #endif /* GL_NV_fragment_coverage_to_color */

    #ifdef GL_NV_fragment_program
	fprintf(LogGlGetFunctions_py, "\nGL_NV_fragment_program\n");
    GL_GetFuncEXT(PFNGLPROGRAMNAMEDPARAMETER4FNVPROC                       ,glProgramNamedParameter4fNV                 );
    GL_GetFuncEXT(PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC                      ,glProgramNamedParameter4fvNV                );
    GL_GetFuncEXT(PFNGLPROGRAMNAMEDPARAMETER4DNVPROC                       ,glProgramNamedParameter4dNV                 );
    GL_GetFuncEXT(PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC                      ,glProgramNamedParameter4dvNV                );
    GL_GetFuncEXT(PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC                    ,glGetProgramNamedParameterfvNV              );
    GL_GetFuncEXT(PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC                    ,glGetProgramNamedParameterdvNV              );
    #endif /* GL_NV_fragment_program */

    #ifdef GL_NV_framebuffer_mixed_samples
	fprintf(LogGlGetFunctions_py, "\nGL_NV_framebuffer_mixed_samples\n");
    GL_GetFuncEXT(PFNGLCOVERAGEMODULATIONTABLENVPROC                       ,glCoverageModulationTableNV             );
    GL_GetFuncEXT(PFNGLGETCOVERAGEMODULATIONTABLENVPROC                    ,glGetCoverageModulationTableNV          );
    GL_GetFuncEXT(PFNGLCOVERAGEMODULATIONNVPROC                            ,glCoverageModulationNV                  );
    #endif /* GL_NV_framebuffer_mixed_samples */

    #ifdef GL_NV_framebuffer_multisample_coverage
	fprintf(LogGlGetFunctions_py, "\nGL_NV_framebuffer_multisample_coverage\n");
    GL_GetFuncEXT(PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC                  ,glRenderbufferStorageMultisampleCoverageNV     );
    #endif /* GL_NV_framebuffer_multisample_coverage */

    #ifdef GL_NV_geometry_program4
	fprintf(LogGlGetFunctions_py, "\nGL_NV_geometry_program4\n");
    GL_GetFuncEXT(PFNGLPROGRAMVERTEXLIMITNVPROC                            ,glProgramVertexLimitNV             );
    GL_GetFuncEXT(PFNGLFRAMEBUFFERTEXTUREEXTPROC                           ,glFramebufferTextureEXT            );
    GL_GetFuncEXT(PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC                       ,glFramebufferTextureFaceEXT        );
    #endif /* GL_NV_geometry_program4 */

    #ifdef GL_NV_gpu_multicast
	fprintf(LogGlGetFunctions_py, "\nGL_NV_gpu_multicast\n");
    GL_GetFuncEXT(PFNGLRENDERGPUMASKNVPROC                                            ,glRenderGpuMaskNV                              );
    GL_GetFuncEXT(PFNGLMULTICASTBUFFERSUBDATANVPROC                                   ,glMulticastBufferSubDataNV                     );
    GL_GetFuncEXT(PFNGLMULTICASTCOPYBUFFERSUBDATANVPROC                               ,glMulticastCopyBufferSubDataNV                 );
    GL_GetFuncEXT(PFNGLMULTICASTCOPYIMAGESUBDATANVPROC                                ,glMulticastCopyImageSubDataNV                  );
    GL_GetFuncEXT(PFNGLMULTICASTBLITFRAMEBUFFERNVPROC                                 ,glMulticastBlitFramebufferNV                   );
    GL_GetFuncEXT(PFNGLMULTICASTFRAMEBUFFERSAMPLELOCATIONSFVNVPROC                    ,glMulticastFramebufferSampleLocationsfvNV      );
    GL_GetFuncEXT(PFNGLMULTICASTBARRIERNVPROC                                         ,glMulticastBarrierNV                           );
    GL_GetFuncEXT(PFNGLMULTICASTWAITSYNCNVPROC                                        ,glMulticastWaitSyncNV                          );
    GL_GetFuncEXT(PFNGLMULTICASTGETQUERYOBJECTIVNVPROC                                ,glMulticastGetQueryObjectivNV                  );
    GL_GetFuncEXT(PFNGLMULTICASTGETQUERYOBJECTUIVNVPROC                               ,glMulticastGetQueryObjectuivNV                 );
    GL_GetFuncEXT(PFNGLMULTICASTGETQUERYOBJECTI64VNVPROC                              ,glMulticastGetQueryObjecti64vNV                );
    GL_GetFuncEXT(PFNGLMULTICASTGETQUERYOBJECTUI64VNVPROC                             ,glMulticastGetQueryObjectui64vNV               );
    #endif /* GL_NV_gpu_multicast */

    #ifdef GL_NV_gpu_program4
	fprintf(LogGlGetFunctions_py, "\nGL_NV_gpu_program4\n");
    GL_GetFuncEXT(PFNGLPROGRAMLOCALPARAMETERI4INVPROC                         ,glProgramLocalParameterI4iNV         );
    GL_GetFuncEXT(PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC                        ,glProgramLocalParameterI4ivNV        );
    GL_GetFuncEXT(PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC                       ,glProgramLocalParametersI4ivNV       );
    GL_GetFuncEXT(PFNGLPROGRAMLOCALPARAMETERI4UINVPROC                        ,glProgramLocalParameterI4uiNV        );
    GL_GetFuncEXT(PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC                       ,glProgramLocalParameterI4uivNV       );
    GL_GetFuncEXT(PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC                      ,glProgramLocalParametersI4uivNV      );
    GL_GetFuncEXT(PFNGLPROGRAMENVPARAMETERI4INVPROC                           ,glProgramEnvParameterI4iNV           );
    GL_GetFuncEXT(PFNGLPROGRAMENVPARAMETERI4IVNVPROC                          ,glProgramEnvParameterI4ivNV          );
    GL_GetFuncEXT(PFNGLPROGRAMENVPARAMETERSI4IVNVPROC                         ,glProgramEnvParametersI4ivNV         );
    GL_GetFuncEXT(PFNGLPROGRAMENVPARAMETERI4UINVPROC                          ,glProgramEnvParameterI4uiNV          );
    GL_GetFuncEXT(PFNGLPROGRAMENVPARAMETERI4UIVNVPROC                         ,glProgramEnvParameterI4uivNV         );
    GL_GetFuncEXT(PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC                        ,glProgramEnvParametersI4uivNV        );
    GL_GetFuncEXT(PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC                      ,glGetProgramLocalParameterIivNV      );
    GL_GetFuncEXT(PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC                     ,glGetProgramLocalParameterIuivNV     );
    GL_GetFuncEXT(PFNGLGETPROGRAMENVPARAMETERIIVNVPROC                        ,glGetProgramEnvParameterIivNV        );
    GL_GetFuncEXT(PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC                       ,glGetProgramEnvParameterIuivNV       );
    #endif /* GL_NV_gpu_program4 */

    #ifdef GL_NV_gpu_program5
	fprintf(LogGlGetFunctions_py, "\nGL_NV_gpu_program5\n");
    GL_GetFuncEXT(PFNGLPROGRAMSUBROUTINEPARAMETERSUIVNVPROC                     ,glProgramSubroutineParametersuivNV       );
    GL_GetFuncEXT(PFNGLGETPROGRAMSUBROUTINEPARAMETERUIVNVPROC                   ,glGetProgramSubroutineParameteruivNV     );
    #endif /* GL_NV_gpu_program5 */

    #ifdef GL_NV_half_float
	fprintf(LogGlGetFunctions_py, "\nGL_NV_half_float\n");
    GL_GetFuncEXT(PFNGLVERTEX2HNVPROC                                  ,glVertex2hNV                      );
    GL_GetFuncEXT(PFNGLVERTEX2HVNVPROC                                 ,glVertex2hvNV                     );
    GL_GetFuncEXT(PFNGLVERTEX3HNVPROC                                  ,glVertex3hNV                      );
    GL_GetFuncEXT(PFNGLVERTEX3HVNVPROC                                 ,glVertex3hvNV                     );
    GL_GetFuncEXT(PFNGLVERTEX4HNVPROC                                  ,glVertex4hNV                      );
    GL_GetFuncEXT(PFNGLVERTEX4HVNVPROC                                 ,glVertex4hvNV                     );
    GL_GetFuncEXT(PFNGLNORMAL3HNVPROC                                  ,glNormal3hNV                      );
    GL_GetFuncEXT(PFNGLNORMAL3HVNVPROC                                 ,glNormal3hvNV                     );
    GL_GetFuncEXT(PFNGLCOLOR3HNVPROC                                   ,glColor3hNV                       );
    GL_GetFuncEXT(PFNGLCOLOR3HVNVPROC                                  ,glColor3hvNV                      );
    GL_GetFuncEXT(PFNGLCOLOR4HNVPROC                                   ,glColor4hNV                       );
    GL_GetFuncEXT(PFNGLCOLOR4HVNVPROC                                  ,glColor4hvNV                      );
    GL_GetFuncEXT(PFNGLTEXCOORD1HNVPROC                                ,glTexCoord1hNV                    );
    GL_GetFuncEXT(PFNGLTEXCOORD1HVNVPROC                               ,glTexCoord1hvNV                   );
    GL_GetFuncEXT(PFNGLTEXCOORD2HNVPROC                                ,glTexCoord2hNV                    );
    GL_GetFuncEXT(PFNGLTEXCOORD2HVNVPROC                               ,glTexCoord2hvNV                   );
    GL_GetFuncEXT(PFNGLTEXCOORD3HNVPROC                                ,glTexCoord3hNV                    );
    GL_GetFuncEXT(PFNGLTEXCOORD3HVNVPROC                               ,glTexCoord3hvNV                   );
    GL_GetFuncEXT(PFNGLTEXCOORD4HNVPROC                                ,glTexCoord4hNV                    );
    GL_GetFuncEXT(PFNGLTEXCOORD4HVNVPROC                               ,glTexCoord4hvNV                   );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD1HNVPROC                           ,glMultiTexCoord1hNV               );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD1HVNVPROC                          ,glMultiTexCoord1hvNV              );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD2HNVPROC                           ,glMultiTexCoord2hNV               );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD2HVNVPROC                          ,glMultiTexCoord2hvNV              );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD3HNVPROC                           ,glMultiTexCoord3hNV               );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD3HVNVPROC                          ,glMultiTexCoord3hvNV              );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD4HNVPROC                           ,glMultiTexCoord4hNV               );
    GL_GetFuncEXT(PFNGLMULTITEXCOORD4HVNVPROC                          ,glMultiTexCoord4hvNV              );
    GL_GetFuncEXT(PFNGLFOGCOORDHNVPROC                                 ,glFogCoordhNV                     );
    GL_GetFuncEXT(PFNGLFOGCOORDHVNVPROC                                ,glFogCoordhvNV                    );
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3HNVPROC                          ,glSecondaryColor3hNV              );
    GL_GetFuncEXT(PFNGLSECONDARYCOLOR3HVNVPROC                         ,glSecondaryColor3hvNV             );
    GL_GetFuncEXT(PFNGLVERTEXWEIGHTHNVPROC                             ,glVertexWeighthNV                 );
    GL_GetFuncEXT(PFNGLVERTEXWEIGHTHVNVPROC                            ,glVertexWeighthvNV                );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB1HNVPROC                            ,glVertexAttrib1hNV                );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB1HVNVPROC                           ,glVertexAttrib1hvNV               );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB2HNVPROC                            ,glVertexAttrib2hNV                );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB2HVNVPROC                           ,glVertexAttrib2hvNV               );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB3HNVPROC                            ,glVertexAttrib3hNV                );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB3HVNVPROC                           ,glVertexAttrib3hvNV               );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4HNVPROC                            ,glVertexAttrib4hNV                );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4HVNVPROC                           ,glVertexAttrib4hvNV               );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBS1HVNVPROC                          ,glVertexAttribs1hvNV              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBS2HVNVPROC                          ,glVertexAttribs2hvNV              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBS3HVNVPROC                          ,glVertexAttribs3hvNV              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBS4HVNVPROC                          ,glVertexAttribs4hvNV              );
    #endif /* GL_NV_half_float */

    #ifdef GL_NV_internalformat_sample_query
	fprintf(LogGlGetFunctions_py, "\nGL_NV_internalformat_sample_query\n");
    GL_GetFuncEXT(PFNGLGETINTERNALFORMATSAMPLEIVNVPROC                    ,glGetInternalformatSampleivNV          );
    #endif /* GL_NV_internalformat_sample_query */

    #ifdef GL_NV_occlusion_query
	fprintf(LogGlGetFunctions_py, "\nGL_NV_occlusion_query\n");
    GL_GetFuncEXT(PFNGLGENOCCLUSIONQUERIESNVPROC                         ,glGenOcclusionQueriesNV           );
    GL_GetFuncEXT(PFNGLDELETEOCCLUSIONQUERIESNVPROC                      ,glDeleteOcclusionQueriesNV        );
    GL_GetFuncEXT(PFNGLISOCCLUSIONQUERYNVPROC                            ,glIsOcclusionQueryNV              );
    GL_GetFuncEXT(PFNGLBEGINOCCLUSIONQUERYNVPROC                         ,glBeginOcclusionQueryNV           );
    GL_GetFuncEXT(PFNGLENDOCCLUSIONQUERYNVPROC                           ,glEndOcclusionQueryNV             );
    GL_GetFuncEXT(PFNGLGETOCCLUSIONQUERYIVNVPROC                         ,glGetOcclusionQueryivNV           );
    GL_GetFuncEXT(PFNGLGETOCCLUSIONQUERYUIVNVPROC                        ,glGetOcclusionQueryuivNV          );
    #endif /* GL_NV_occlusion_query */

    #ifdef GL_NV_parameter_buffer_object
	fprintf(LogGlGetFunctions_py, "\nGL_NV_parameter_buffer_object\n");
    GL_GetFuncEXT(PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC                     ,glProgramBufferParametersfvNV       );
    GL_GetFuncEXT(PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC                    ,glProgramBufferParametersIivNV      );
    GL_GetFuncEXT(PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC                   ,glProgramBufferParametersIuivNV     );
    #endif /* GL_NV_parameter_buffer_object */

    #ifdef GL_NV_path_rendering
	fprintf(LogGlGetFunctions_py, "\nGL_NV_path_rendering\n");
    GL_GetFuncEXT(PFNGLGENPATHSNVPROC                                             ,glGenPathsNV                                    );
    GL_GetFuncEXT(PFNGLDELETEPATHSNVPROC                                          ,glDeletePathsNV                                 );
    GL_GetFuncEXT(PFNGLISPATHNVPROC                                               ,glIsPathNV                                      );
    GL_GetFuncEXT(PFNGLPATHCOMMANDSNVPROC                                         ,glPathCommandsNV                                );
    GL_GetFuncEXT(PFNGLPATHCOORDSNVPROC                                           ,glPathCoordsNV                                  );
    GL_GetFuncEXT(PFNGLPATHSUBCOMMANDSNVPROC                                      ,glPathSubCommandsNV                             );
    GL_GetFuncEXT(PFNGLPATHSUBCOORDSNVPROC                                        ,glPathSubCoordsNV                               );
    GL_GetFuncEXT(PFNGLPATHSTRINGNVPROC                                           ,glPathStringNV                                  );
    GL_GetFuncEXT(PFNGLPATHGLYPHSNVPROC                                           ,glPathGlyphsNV                                  );
    GL_GetFuncEXT(PFNGLPATHGLYPHRANGENVPROC                                       ,glPathGlyphRangeNV                              );
    GL_GetFuncEXT(PFNGLWEIGHTPATHSNVPROC                                          ,glWeightPathsNV                                 );
    GL_GetFuncEXT(PFNGLCOPYPATHNVPROC                                             ,glCopyPathNV                                    );
    GL_GetFuncEXT(PFNGLINTERPOLATEPATHSNVPROC                                     ,glInterpolatePathsNV                            );
    GL_GetFuncEXT(PFNGLTRANSFORMPATHNVPROC                                        ,glTransformPathNV                               );
    GL_GetFuncEXT(PFNGLPATHPARAMETERIVNVPROC                                      ,glPathParameterivNV                             );
    GL_GetFuncEXT(PFNGLPATHPARAMETERINVPROC                                       ,glPathParameteriNV                              );
    GL_GetFuncEXT(PFNGLPATHPARAMETERFVNVPROC                                      ,glPathParameterfvNV                             );
    GL_GetFuncEXT(PFNGLPATHPARAMETERFNVPROC                                       ,glPathParameterfNV                              );
    GL_GetFuncEXT(PFNGLPATHDASHARRAYNVPROC                                        ,glPathDashArrayNV                               );
    GL_GetFuncEXT(PFNGLPATHSTENCILFUNCNVPROC                                      ,glPathStencilFuncNV                             );
    GL_GetFuncEXT(PFNGLPATHSTENCILDEPTHOFFSETNVPROC                               ,glPathStencilDepthOffsetNV                      );
    GL_GetFuncEXT(PFNGLSTENCILFILLPATHNVPROC                                      ,glStencilFillPathNV                             );
    GL_GetFuncEXT(PFNGLSTENCILSTROKEPATHNVPROC                                    ,glStencilStrokePathNV                           );
    GL_GetFuncEXT(PFNGLSTENCILFILLPATHINSTANCEDNVPROC                             ,glStencilFillPathInstancedNV                    );
    GL_GetFuncEXT(PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC                           ,glStencilStrokePathInstancedNV                  );
    GL_GetFuncEXT(PFNGLPATHCOVERDEPTHFUNCNVPROC                                   ,glPathCoverDepthFuncNV                          );
    GL_GetFuncEXT(PFNGLCOVERFILLPATHNVPROC                                        ,glCoverFillPathNV                               );
    GL_GetFuncEXT(PFNGLCOVERSTROKEPATHNVPROC                                      ,glCoverStrokePathNV                             );
    GL_GetFuncEXT(PFNGLCOVERFILLPATHINSTANCEDNVPROC                               ,glCoverFillPathInstancedNV                      );
    GL_GetFuncEXT(PFNGLCOVERSTROKEPATHINSTANCEDNVPROC                             ,glCoverStrokePathInstancedNV                    );
    GL_GetFuncEXT(PFNGLGETPATHPARAMETERIVNVPROC                                   ,glGetPathParameterivNV                          );
    GL_GetFuncEXT(PFNGLGETPATHPARAMETERFVNVPROC                                   ,glGetPathParameterfvNV                          );
    GL_GetFuncEXT(PFNGLGETPATHCOMMANDSNVPROC                                      ,glGetPathCommandsNV                             );
    GL_GetFuncEXT(PFNGLGETPATHCOORDSNVPROC                                        ,glGetPathCoordsNV                               );
    GL_GetFuncEXT(PFNGLGETPATHDASHARRAYNVPROC                                     ,glGetPathDashArrayNV                            );
    GL_GetFuncEXT(PFNGLGETPATHMETRICSNVPROC                                       ,glGetPathMetricsNV                              );
    GL_GetFuncEXT(PFNGLGETPATHMETRICRANGENVPROC                                   ,glGetPathMetricRangeNV                          );
    GL_GetFuncEXT(PFNGLGETPATHSPACINGNVPROC                                       ,glGetPathSpacingNV                              );
    GL_GetFuncEXT(PFNGLISPOINTINFILLPATHNVPROC                                    ,glIsPointInFillPathNV                           );
    GL_GetFuncEXT(PFNGLISPOINTINSTROKEPATHNVPROC                                  ,glIsPointInStrokePathNV                         );
    GL_GetFuncEXT(PFNGLGETPATHLENGTHNVPROC                                        ,glGetPathLengthNV                               );
    GL_GetFuncEXT(PFNGLPOINTALONGPATHNVPROC                                       ,glPointAlongPathNV                              );
    GL_GetFuncEXT(PFNGLMATRIXLOAD3X2FNVPROC                                       ,glMatrixLoad3x2fNV                              );
    GL_GetFuncEXT(PFNGLMATRIXLOAD3X3FNVPROC                                       ,glMatrixLoad3x3fNV                              );
    GL_GetFuncEXT(PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC                              ,glMatrixLoadTranspose3x3fNV                     );
    GL_GetFuncEXT(PFNGLMATRIXMULT3X2FNVPROC                                       ,glMatrixMult3x2fNV                              );
    GL_GetFuncEXT(PFNGLMATRIXMULT3X3FNVPROC                                       ,glMatrixMult3x3fNV                              );
    GL_GetFuncEXT(PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC                              ,glMatrixMultTranspose3x3fNV                     );
    GL_GetFuncEXT(PFNGLSTENCILTHENCOVERFILLPATHNVPROC                             ,glStencilThenCoverFillPathNV                    );
    GL_GetFuncEXT(PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC                           ,glStencilThenCoverStrokePathNV                  );
    GL_GetFuncEXT(PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC                    ,glStencilThenCoverFillPathInstancedNV           );
    GL_GetFuncEXT(PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC                  ,glStencilThenCoverStrokePathInstancedNV         );
    GL_GetFuncEXT(PFNGLPATHGLYPHINDEXRANGENVPROC                                  ,glPathGlyphIndexRangeNV                         );
    GL_GetFuncEXT(PFNGLPATHGLYPHINDEXARRAYNVPROC                                  ,glPathGlyphIndexArrayNV                         );
    GL_GetFuncEXT(PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC                            ,glPathMemoryGlyphIndexArrayNV                   );
    GL_GetFuncEXT(PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC                          ,glProgramPathFragmentInputGenNV                 );
    GL_GetFuncEXT(PFNGLGETPROGRAMRESOURCEFVNVPROC                                 ,glGetProgramResourcefvNV                        );
    GL_GetFuncEXT(PFNGLPATHCOLORGENNVPROC                                         ,glPathColorGenNV                                );
    GL_GetFuncEXT(PFNGLPATHTEXGENNVPROC                                           ,glPathTexGenNV                                  );
    GL_GetFuncEXT(PFNGLPATHFOGGENNVPROC                                           ,glPathFogGenNV                                  );
    GL_GetFuncEXT(PFNGLGETPATHCOLORGENIVNVPROC                                    ,glGetPathColorGenivNV                           );
    GL_GetFuncEXT(PFNGLGETPATHCOLORGENFVNVPROC                                    ,glGetPathColorGenfvNV                           );
    GL_GetFuncEXT(PFNGLGETPATHTEXGENIVNVPROC                                      ,glGetPathTexGenivNV                             );
    GL_GetFuncEXT(PFNGLGETPATHTEXGENFVNVPROC                                      ,glGetPathTexGenfvNV                             );
    #endif /* GL_NV_path_rendering */

    #ifdef GL_NV_pixel_data_range
	fprintf(LogGlGetFunctions_py, "\nGL_NV_pixel_data_range\n");
    GL_GetFuncEXT(PFNGLPIXELDATARANGENVPROC                           ,glPixelDataRangeNV                    );
    GL_GetFuncEXT(PFNGLFLUSHPIXELDATARANGENVPROC                      ,glFlushPixelDataRangeNV               );
    #endif /* GL_NV_pixel_data_range */

    #ifdef GL_NV_point_sprite
	fprintf(LogGlGetFunctions_py, "\nGL_NV_point_sprite\n");
    GL_GetFuncEXT(PFNGLPOINTPARAMETERINVPROC                         ,glPointParameteriNV                );
    GL_GetFuncEXT(PFNGLPOINTPARAMETERIVNVPROC                        ,glPointParameterivNV               );
    #endif /* GL_NV_point_sprite */

    #ifdef GL_NV_present_video
	fprintf(LogGlGetFunctions_py, "\nGL_NV_present_video\n");
    GL_GetFuncEXT(PFNGLPRESENTFRAMEKEYEDNVPROC                         ,glPresentFrameKeyedNV       );
    GL_GetFuncEXT(PFNGLPRESENTFRAMEDUALFILLNVPROC                      ,glPresentFrameDualFillNV    );
    GL_GetFuncEXT(PFNGLGETVIDEOIVNVPROC                                ,glGetVideoivNV              );
    GL_GetFuncEXT(PFNGLGETVIDEOUIVNVPROC                               ,glGetVideouivNV             );
    GL_GetFuncEXT(PFNGLGETVIDEOI64VNVPROC                              ,glGetVideoi64vNV            );
    GL_GetFuncEXT(PFNGLGETVIDEOUI64VNVPROC                             ,glGetVideoui64vNV           );
    #endif /* GL_NV_present_video */

    #ifdef GL_NV_primitive_restart
	fprintf(LogGlGetFunctions_py, "\nGL_NV_primitive_restart\n");
    GL_GetFuncEXT(PFNGLPRIMITIVERESTARTNVPROC                          ,glPrimitiveRestartNV          );
    GL_GetFuncEXT(PFNGLPRIMITIVERESTARTINDEXNVPROC                     ,glPrimitiveRestartIndexNV     );
    #endif /* GL_NV_primitive_restart */

    #ifdef GL_NV_query_resource
	fprintf(LogGlGetFunctions_py, "\nGL_NV_query_resource\n");
    GL_GetFuncEXT(PFNGLQUERYRESOURCENVPROC                          ,glQueryResourceNV             );
    #endif /* GL_NV_query_resource */

    #ifdef GL_NV_query_resource_tag
	fprintf(LogGlGetFunctions_py, "\nGL_NV_query_resource_tag\n");
    GL_GetFuncEXT(PFNGLGENQUERYRESOURCETAGNVPROC                         ,glGenQueryResourceTagNV        );
    GL_GetFuncEXT(PFNGLDELETEQUERYRESOURCETAGNVPROC                      ,glDeleteQueryResourceTagNV     );
    GL_GetFuncEXT(PFNGLQUERYRESOURCETAGNVPROC                            ,glQueryResourceTagNV           );
    #endif /* GL_NV_query_resource_tag */

    #ifdef GL_NV_register_combiners
	fprintf(LogGlGetFunctions_py, "\nGL_NV_register_combiners\n");
    GL_GetFuncEXT(PFNGLCOMBINERPARAMETERFVNVPROC                                ,glCombinerParameterfvNV               );
    GL_GetFuncEXT(PFNGLCOMBINERPARAMETERFNVPROC                                 ,glCombinerParameterfNV                );
    GL_GetFuncEXT(PFNGLCOMBINERPARAMETERIVNVPROC                                ,glCombinerParameterivNV               );
    GL_GetFuncEXT(PFNGLCOMBINERPARAMETERINVPROC                                 ,glCombinerParameteriNV                );
    GL_GetFuncEXT(PFNGLCOMBINERINPUTNVPROC                                      ,glCombinerInputNV                     );
    GL_GetFuncEXT(PFNGLCOMBINEROUTPUTNVPROC                                     ,glCombinerOutputNV                    );
    GL_GetFuncEXT(PFNGLFINALCOMBINERINPUTNVPROC                                 ,glFinalCombinerInputNV                );
    GL_GetFuncEXT(PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC                        ,glGetCombinerInputParameterfvNV       );
    GL_GetFuncEXT(PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC                        ,glGetCombinerInputParameterivNV       );
    GL_GetFuncEXT(PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC                       ,glGetCombinerOutputParameterfvNV      );
    GL_GetFuncEXT(PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC                       ,glGetCombinerOutputParameterivNV      );
    GL_GetFuncEXT(PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC                   ,glGetFinalCombinerInputParameterfvNV  );
    GL_GetFuncEXT(PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC                   ,glGetFinalCombinerInputParameterivNV  );
    #endif /* GL_NV_register_combiners */

    #ifdef GL_NV_register_combiners2
	fprintf(LogGlGetFunctions_py, "\nGL_NV_register_combiners2\n");
    GL_GetFuncEXT(PFNGLCOMBINERSTAGEPARAMETERFVNVPROC                       ,glCombinerStageParameterfvNV        );
    GL_GetFuncEXT(PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC                    ,glGetCombinerStageParameterfvNV     );
    #endif /* GL_NV_register_combiners2 */

    #ifdef GL_NV_sample_locations
	fprintf(LogGlGetFunctions_py, "\nGL_NV_sample_locations\n");
    GL_GetFuncEXT(PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC                        ,glFramebufferSampleLocationsfvNV         );
    GL_GetFuncEXT(PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC                   ,glNamedFramebufferSampleLocationsfvNV    );
    GL_GetFuncEXT(PFNGLRESOLVEDEPTHVALUESNVPROC                                  ,glResolveDepthValuesNV                   );
    #endif /* GL_NV_sample_locations */

    #ifdef GL_NV_shader_buffer_load
	fprintf(LogGlGetFunctions_py, "\nGL_NV_shader_buffer_load\n");
    GL_GetFuncEXT(PFNGLMAKEBUFFERRESIDENTNVPROC                              ,glMakeBufferResidentNV               );
    GL_GetFuncEXT(PFNGLMAKEBUFFERNONRESIDENTNVPROC                           ,glMakeBufferNonResidentNV            );
    GL_GetFuncEXT(PFNGLISBUFFERRESIDENTNVPROC                                ,glIsBufferResidentNV                 );
    GL_GetFuncEXT(PFNGLMAKENAMEDBUFFERRESIDENTNVPROC                         ,glMakeNamedBufferResidentNV          );
    GL_GetFuncEXT(PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC                      ,glMakeNamedBufferNonResidentNV       );
    GL_GetFuncEXT(PFNGLISNAMEDBUFFERRESIDENTNVPROC                           ,glIsNamedBufferResidentNV            );
    GL_GetFuncEXT(PFNGLGETBUFFERPARAMETERUI64VNVPROC                         ,glGetBufferParameterui64vNV          );
    GL_GetFuncEXT(PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC                    ,glGetNamedBufferParameterui64vNV     );
    GL_GetFuncEXT(PFNGLGETINTEGERUI64VNVPROC                                 ,glGetIntegerui64vNV                  );
    GL_GetFuncEXT(PFNGLUNIFORMUI64NVPROC                                     ,glUniformui64NV                      );
    GL_GetFuncEXT(PFNGLUNIFORMUI64VNVPROC                                    ,glUniformui64vNV                     );
    GL_GetFuncEXT(PFNGLGETUNIFORMUI64VNVPROC                                 ,glGetUniformui64vNV                  );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMUI64NVPROC                              ,glProgramUniformui64NV               );
    GL_GetFuncEXT(PFNGLPROGRAMUNIFORMUI64VNVPROC                             ,glProgramUniformui64vNV              );
    #endif /* GL_NV_shader_buffer_load */

    #ifdef GL_NV_texture_barrier
	fprintf(LogGlGetFunctions_py, "\nGL_NV_texture_barrier\n");
    GL_GetFuncEXT(PFNGLTEXTUREBARRIERNVPROC                       ,glTextureBarrierNV         );
    #endif /* GL_NV_texture_barrier */

    #ifdef GL_NV_texture_multisample
	fprintf(LogGlGetFunctions_py, "\nGL_NV_texture_multisample\n");
    GL_GetFuncEXT(PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC                       ,glTexImage2DMultisampleCoverageNV         );
    GL_GetFuncEXT(PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC                       ,glTexImage3DMultisampleCoverageNV         );
    GL_GetFuncEXT(PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC                           ,glTextureImage2DMultisampleNV             );
    GL_GetFuncEXT(PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC                           ,glTextureImage3DMultisampleNV             );
    GL_GetFuncEXT(PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC                   ,glTextureImage2DMultisampleCoverageNV     );
    GL_GetFuncEXT(PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC                   ,glTextureImage3DMultisampleCoverageNV     );
    #endif /* GL_NV_texture_multisample */

    #ifdef GL_NV_transform_feedback
	fprintf(LogGlGetFunctions_py, "\nGL_NV_transform_feedback\n");
    GL_GetFuncEXT(PFNGLBEGINTRANSFORMFEEDBACKNVPROC                           ,glBeginTransformFeedbackNV                );
    GL_GetFuncEXT(PFNGLENDTRANSFORMFEEDBACKNVPROC                             ,glEndTransformFeedbackNV                  );
    GL_GetFuncEXT(PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC                         ,glTransformFeedbackAttribsNV              );
    GL_GetFuncEXT(PFNGLBINDBUFFERRANGENVPROC                                  ,glBindBufferRangeNV                       );
    GL_GetFuncEXT(PFNGLBINDBUFFEROFFSETNVPROC                                 ,glBindBufferOffsetNV                      );
    GL_GetFuncEXT(PFNGLBINDBUFFERBASENVPROC                                   ,glBindBufferBaseNV                        );
    GL_GetFuncEXT(PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC                        ,glTransformFeedbackVaryingsNV             );
    GL_GetFuncEXT(PFNGLACTIVEVARYINGNVPROC                                    ,glActiveVaryingNV                         );
    GL_GetFuncEXT(PFNGLGETVARYINGLOCATIONNVPROC                               ,glGetVaryingLocationNV                    );
    GL_GetFuncEXT(PFNGLGETACTIVEVARYINGNVPROC                                 ,glGetActiveVaryingNV                      );
    GL_GetFuncEXT(PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC                      ,glGetTransformFeedbackVaryingNV           );
    GL_GetFuncEXT(PFNGLTRANSFORMFEEDBACKSTREAMATTRIBSNVPROC                   ,glTransformFeedbackStreamAttribsNV        );
    #endif /* GL_NV_transform_feedback */

    #ifdef GL_NV_transform_feedback2
	fprintf(LogGlGetFunctions_py, "\nGL_NV_transform_feedback2\n");
    GL_GetFuncEXT(PFNGLBINDTRANSFORMFEEDBACKNVPROC                           ,glBindTransformFeedbackNV             );
    GL_GetFuncEXT(PFNGLDELETETRANSFORMFEEDBACKSNVPROC                        ,glDeleteTransformFeedbacksNV          );
    GL_GetFuncEXT(PFNGLGENTRANSFORMFEEDBACKSNVPROC                           ,glGenTransformFeedbacksNV             );
    GL_GetFuncEXT(PFNGLISTRANSFORMFEEDBACKNVPROC                             ,glIsTransformFeedbackNV               );
    GL_GetFuncEXT(PFNGLPAUSETRANSFORMFEEDBACKNVPROC                          ,glPauseTransformFeedbackNV            );
    GL_GetFuncEXT(PFNGLRESUMETRANSFORMFEEDBACKNVPROC                         ,glResumeTransformFeedbackNV           );
    GL_GetFuncEXT(PFNGLDRAWTRANSFORMFEEDBACKNVPROC                           ,glDrawTransformFeedbackNV             );
    #endif /* GL_NV_transform_feedback2 */

    #ifdef GL_NV_vdpau_interop
	fprintf(LogGlGetFunctions_py, "\nGL_NV_vdpau_interop\n");
    GL_GetFuncEXT(PFNGLVDPAUINITNVPROC                                      ,glVDPAUInitNV                       );
    GL_GetFuncEXT(PFNGLVDPAUFININVPROC                                      ,glVDPAUFiniNV                       );
    GL_GetFuncEXT(PFNGLVDPAUREGISTERVIDEOSURFACENVPROC                      ,glVDPAURegisterVideoSurfaceNV       );
    GL_GetFuncEXT(PFNGLVDPAUREGISTEROUTPUTSURFACENVPROC                     ,glVDPAURegisterOutputSurfaceNV      );
    GL_GetFuncEXT(PFNGLVDPAUISSURFACENVPROC                                 ,glVDPAUIsSurfaceNV                  );
    GL_GetFuncEXT(PFNGLVDPAUUNREGISTERSURFACENVPROC                         ,glVDPAUUnregisterSurfaceNV          );
    GL_GetFuncEXT(PFNGLVDPAUGETSURFACEIVNVPROC                              ,glVDPAUGetSurfaceivNV               );
    GL_GetFuncEXT(PFNGLVDPAUSURFACEACCESSNVPROC                             ,glVDPAUSurfaceAccessNV              );
    GL_GetFuncEXT(PFNGLVDPAUMAPSURFACESNVPROC                               ,glVDPAUMapSurfacesNV                );
    GL_GetFuncEXT(PFNGLVDPAUUNMAPSURFACESNVPROC                             ,glVDPAUUnmapSurfacesNV              );
    #endif /* GL_NV_vdpau_interop */

    #ifdef GL_NV_vertex_array_range
	fprintf(LogGlGetFunctions_py, "\nGL_NV_vertex_array_range\n");
    GL_GetFuncEXT(PFNGLFLUSHVERTEXARRAYRANGENVPROC                      ,glFlushVertexArrayRangeNV    );
    GL_GetFuncEXT(PFNGLVERTEXARRAYRANGENVPROC                           ,glVertexArrayRangeNV         );
    #endif /* GL_NV_vertex_array_range */

    #ifdef GL_NV_vertex_attrib_integer_64bit
	fprintf(LogGlGetFunctions_py, "\nGL_NV_vertex_attrib_integer_64bit\n");
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL1I64NVPROC                        ,glVertexAttribL1i64NV      );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL2I64NVPROC                        ,glVertexAttribL2i64NV      );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL3I64NVPROC                        ,glVertexAttribL3i64NV      );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL4I64NVPROC                        ,glVertexAttribL4i64NV      );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL1I64VNVPROC                       ,glVertexAttribL1i64vNV     );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL2I64VNVPROC                       ,glVertexAttribL2i64vNV     );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL3I64VNVPROC                       ,glVertexAttribL3i64vNV     );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL4I64VNVPROC                       ,glVertexAttribL4i64vNV     );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL1UI64NVPROC                       ,glVertexAttribL1ui64NV     );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL2UI64NVPROC                       ,glVertexAttribL2ui64NV     );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL3UI64NVPROC                       ,glVertexAttribL3ui64NV     );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL4UI64NVPROC                       ,glVertexAttribL4ui64NV     );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL1UI64VNVPROC                      ,glVertexAttribL1ui64vNV    );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL2UI64VNVPROC                      ,glVertexAttribL2ui64vNV    );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL3UI64VNVPROC                      ,glVertexAttribL3ui64vNV    );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBL4UI64VNVPROC                      ,glVertexAttribL4ui64vNV    );
    GL_GetFuncEXT(PFNGLGETVERTEXATTRIBLI64VNVPROC                     ,glGetVertexAttribLi64vNV   );
    GL_GetFuncEXT(PFNGLGETVERTEXATTRIBLUI64VNVPROC                    ,glGetVertexAttribLui64vNV  );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBLFORMATNVPROC                      ,glVertexAttribLFormatNV    );
    #endif /* GL_NV_vertex_attrib_integer_64bit */

    #ifdef GL_NV_vertex_buffer_unified_memory
	fprintf(LogGlGetFunctions_py, "\nGL_NV_vertex_buffer_unified_memory\n");
    GL_GetFuncEXT(PFNGLBUFFERADDRESSRANGENVPROC                          ,glBufferAddressRangeNV       );
    GL_GetFuncEXT(PFNGLVERTEXFORMATNVPROC                                ,glVertexFormatNV             );
    GL_GetFuncEXT(PFNGLNORMALFORMATNVPROC                                ,glNormalFormatNV             );
    GL_GetFuncEXT(PFNGLCOLORFORMATNVPROC                                 ,glColorFormatNV              );
    GL_GetFuncEXT(PFNGLINDEXFORMATNVPROC                                 ,glIndexFormatNV              );
    GL_GetFuncEXT(PFNGLTEXCOORDFORMATNVPROC                              ,glTexCoordFormatNV           );
    GL_GetFuncEXT(PFNGLEDGEFLAGFORMATNVPROC                              ,glEdgeFlagFormatNV           );
    GL_GetFuncEXT(PFNGLSECONDARYCOLORFORMATNVPROC                        ,glSecondaryColorFormatNV     );
    GL_GetFuncEXT(PFNGLFOGCOORDFORMATNVPROC                              ,glFogCoordFormatNV           );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBFORMATNVPROC                          ,glVertexAttribFormatNV       );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBIFORMATNVPROC                         ,glVertexAttribIFormatNV      );
    GL_GetFuncEXT(PFNGLGETINTEGERUI64I_VNVPROC                           ,glGetIntegerui64i_vNV        );
    #endif /* GL_NV_vertex_buffer_unified_memory */

    #ifdef GL_NV_vertex_program
	fprintf(LogGlGetFunctions_py, "\nGL_NV_vertex_program\n");
    GL_GetFuncEXT(PFNGLAREPROGRAMSRESIDENTNVPROC                             ,glAreProgramsResidentNV          );
    GL_GetFuncEXT(PFNGLBINDPROGRAMNVPROC                                     ,glBindProgramNV                  );
    GL_GetFuncEXT(PFNGLDELETEPROGRAMSNVPROC                                  ,glDeleteProgramsNV               );
    GL_GetFuncEXT(PFNGLEXECUTEPROGRAMNVPROC                                  ,glExecuteProgramNV               );
    GL_GetFuncEXT(PFNGLGENPROGRAMSNVPROC                                     ,glGenProgramsNV                  );
    GL_GetFuncEXT(PFNGLGETPROGRAMPARAMETERDVNVPROC                           ,glGetProgramParameterdvNV        );
    GL_GetFuncEXT(PFNGLGETPROGRAMPARAMETERFVNVPROC                           ,glGetProgramParameterfvNV        );
    GL_GetFuncEXT(PFNGLGETPROGRAMIVNVPROC                                    ,glGetProgramivNV                 );
    GL_GetFuncEXT(PFNGLGETPROGRAMSTRINGNVPROC                                ,glGetProgramStringNV             );
    GL_GetFuncEXT(PFNGLGETTRACKMATRIXIVNVPROC                                ,glGetTrackMatrixivNV             );
    GL_GetFuncEXT(PFNGLGETVERTEXATTRIBDVNVPROC                               ,glGetVertexAttribdvNV            );
    GL_GetFuncEXT(PFNGLGETVERTEXATTRIBFVNVPROC                               ,glGetVertexAttribfvNV            );
    GL_GetFuncEXT(PFNGLGETVERTEXATTRIBIVNVPROC                               ,glGetVertexAttribivNV            );
    GL_GetFuncEXT(PFNGLGETVERTEXATTRIBPOINTERVNVPROC                         ,glGetVertexAttribPointervNV      );
    GL_GetFuncEXT(PFNGLISPROGRAMNVPROC                                       ,glIsProgramNV                    );
    GL_GetFuncEXT(PFNGLLOADPROGRAMNVPROC                                     ,glLoadProgramNV                  );
    GL_GetFuncEXT(PFNGLPROGRAMPARAMETER4DNVPROC                              ,glProgramParameter4dNV           );
    GL_GetFuncEXT(PFNGLPROGRAMPARAMETER4DVNVPROC                             ,glProgramParameter4dvNV          );
    GL_GetFuncEXT(PFNGLPROGRAMPARAMETER4FNVPROC                              ,glProgramParameter4fNV           );
    GL_GetFuncEXT(PFNGLPROGRAMPARAMETER4FVNVPROC                             ,glProgramParameter4fvNV          );
    GL_GetFuncEXT(PFNGLPROGRAMPARAMETERS4DVNVPROC                            ,glProgramParameters4dvNV         );
    GL_GetFuncEXT(PFNGLPROGRAMPARAMETERS4FVNVPROC                            ,glProgramParameters4fvNV         );
    GL_GetFuncEXT(PFNGLREQUESTRESIDENTPROGRAMSNVPROC                         ,glRequestResidentProgramsNV      );
    GL_GetFuncEXT(PFNGLTRACKMATRIXNVPROC                                     ,glTrackMatrixNV                  );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBPOINTERNVPROC                             ,glVertexAttribPointerNV          );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB1DNVPROC                                  ,glVertexAttrib1dNV               );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB1DVNVPROC                                 ,glVertexAttrib1dvNV              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB1FNVPROC                                  ,glVertexAttrib1fNV               );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB1FVNVPROC                                 ,glVertexAttrib1fvNV              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB1SNVPROC                                  ,glVertexAttrib1sNV               );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB1SVNVPROC                                 ,glVertexAttrib1svNV              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB2DNVPROC                                  ,glVertexAttrib2dNV               );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB2DVNVPROC                                 ,glVertexAttrib2dvNV              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB2FNVPROC                                  ,glVertexAttrib2fNV               );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB2FVNVPROC                                 ,glVertexAttrib2fvNV              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB2SNVPROC                                  ,glVertexAttrib2sNV               );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB2SVNVPROC                                 ,glVertexAttrib2svNV              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB3DNVPROC                                  ,glVertexAttrib3dNV               );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB3DVNVPROC                                 ,glVertexAttrib3dvNV              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB3FNVPROC                                  ,glVertexAttrib3fNV               );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB3FVNVPROC                                 ,glVertexAttrib3fvNV              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB3SNVPROC                                  ,glVertexAttrib3sNV               );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB3SVNVPROC                                 ,glVertexAttrib3svNV              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4DNVPROC                                  ,glVertexAttrib4dNV               );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4DVNVPROC                                 ,glVertexAttrib4dvNV              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4FNVPROC                                  ,glVertexAttrib4fNV               );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4FVNVPROC                                 ,glVertexAttrib4fvNV              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4SNVPROC                                  ,glVertexAttrib4sNV               );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4SVNVPROC                                 ,glVertexAttrib4svNV              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4UBNVPROC                                 ,glVertexAttrib4ubNV              );
    GL_GetFuncEXT(PFNGLVERTEXATTRIB4UBVNVPROC                                ,glVertexAttrib4ubvNV             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBS1DVNVPROC                                ,glVertexAttribs1dvNV             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBS1FVNVPROC                                ,glVertexAttribs1fvNV             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBS1SVNVPROC                                ,glVertexAttribs1svNV             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBS2DVNVPROC                                ,glVertexAttribs2dvNV             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBS2FVNVPROC                                ,glVertexAttribs2fvNV             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBS2SVNVPROC                                ,glVertexAttribs2svNV             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBS3DVNVPROC                                ,glVertexAttribs3dvNV             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBS3FVNVPROC                                ,glVertexAttribs3fvNV             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBS3SVNVPROC                                ,glVertexAttribs3svNV             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBS4DVNVPROC                                ,glVertexAttribs4dvNV             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBS4FVNVPROC                                ,glVertexAttribs4fvNV             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBS4SVNVPROC                                ,glVertexAttribs4svNV             );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBS4UBVNVPROC                               ,glVertexAttribs4ubvNV            );
    #endif /* GL_NV_vertex_program */

    #ifdef GL_NV_vertex_program4
	fprintf(LogGlGetFunctions_py, "\nGL_NV_vertex_program4\n");
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI1IEXTPROC                           ,glVertexAttribI1iEXT           );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI2IEXTPROC                           ,glVertexAttribI2iEXT           );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI3IEXTPROC                           ,glVertexAttribI3iEXT           );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI4IEXTPROC                           ,glVertexAttribI4iEXT           );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI1UIEXTPROC                          ,glVertexAttribI1uiEXT          );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI2UIEXTPROC                          ,glVertexAttribI2uiEXT          );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI3UIEXTPROC                          ,glVertexAttribI3uiEXT          );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI4UIEXTPROC                          ,glVertexAttribI4uiEXT          );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI1IVEXTPROC                          ,glVertexAttribI1ivEXT          );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI2IVEXTPROC                          ,glVertexAttribI2ivEXT          );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI3IVEXTPROC                          ,glVertexAttribI3ivEXT          );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI4IVEXTPROC                          ,glVertexAttribI4ivEXT          );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI1UIVEXTPROC                         ,glVertexAttribI1uivEXT         );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI2UIVEXTPROC                         ,glVertexAttribI2uivEXT         );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI3UIVEXTPROC                         ,glVertexAttribI3uivEXT         );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI4UIVEXTPROC                         ,glVertexAttribI4uivEXT         );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI4BVEXTPROC                          ,glVertexAttribI4bvEXT          );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI4SVEXTPROC                          ,glVertexAttribI4svEXT          );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI4UBVEXTPROC                         ,glVertexAttribI4ubvEXT         );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBI4USVEXTPROC                         ,glVertexAttribI4usvEXT         );
    GL_GetFuncEXT(PFNGLVERTEXATTRIBIPOINTEREXTPROC                      ,glVertexAttribIPointerEXT      );
    GL_GetFuncEXT(PFNGLGETVERTEXATTRIBIIVEXTPROC                        ,glGetVertexAttribIivEXT        );
    GL_GetFuncEXT(PFNGLGETVERTEXATTRIBIUIVEXTPROC                       ,glGetVertexAttribIuivEXT       );
    #endif /* GL_NV_vertex_program4 */

    #ifdef GL_NV_video_capture
	fprintf(LogGlGetFunctions_py, "\nGL_NV_video_capture\n");
    GL_GetFuncEXT(PFNGLBEGINVIDEOCAPTURENVPROC                                  ,glBeginVideoCaptureNV                 );
    GL_GetFuncEXT(PFNGLBINDVIDEOCAPTURESTREAMBUFFERNVPROC                       ,glBindVideoCaptureStreamBufferNV      );
    GL_GetFuncEXT(PFNGLBINDVIDEOCAPTURESTREAMTEXTURENVPROC                      ,glBindVideoCaptureStreamTextureNV     );
    GL_GetFuncEXT(PFNGLENDVIDEOCAPTURENVPROC                                    ,glEndVideoCaptureNV                   );
    GL_GetFuncEXT(PFNGLGETVIDEOCAPTUREIVNVPROC                                  ,glGetVideoCaptureivNV                 );
    GL_GetFuncEXT(PFNGLGETVIDEOCAPTURESTREAMIVNVPROC                            ,glGetVideoCaptureStreamivNV           );
    GL_GetFuncEXT(PFNGLGETVIDEOCAPTURESTREAMFVNVPROC                            ,glGetVideoCaptureStreamfvNV           );
    GL_GetFuncEXT(PFNGLGETVIDEOCAPTURESTREAMDVNVPROC                            ,glGetVideoCaptureStreamdvNV           );
    GL_GetFuncEXT(PFNGLVIDEOCAPTURENVPROC                                       ,glVideoCaptureNV                      );
    GL_GetFuncEXT(PFNGLVIDEOCAPTURESTREAMPARAMETERIVNVPROC                      ,glVideoCaptureStreamParameterivNV     );
    GL_GetFuncEXT(PFNGLVIDEOCAPTURESTREAMPARAMETERFVNVPROC                      ,glVideoCaptureStreamParameterfvNV     );
    GL_GetFuncEXT(PFNGLVIDEOCAPTURESTREAMPARAMETERDVNVPROC                      ,glVideoCaptureStreamParameterdvNV     );
    #endif /* GL_NV_video_capture */

    #ifdef GL_NV_viewport_swizzle
	fprintf(LogGlGetFunctions_py, "\nGL_NV_viewport_swizzle\n");
    GL_GetFuncEXT(PFNGLVIEWPORTSWIZZLENVPROC                           ,glViewportSwizzleNV             );
    #endif /* GL_NV_viewport_swizzle */


	
    #ifdef GL_OVR_multiview
	fprintf(LogGlGetFunctions_py, "\nGL_OVR_multiview\n");
    GL_GetFuncEXT(PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC                      ,glFramebufferTextureMultiviewOVR   );
    #endif /* GL_OVR_multiview */


	
    #ifdef GL_PGI_misc_hints
	fprintf(LogGlGetFunctions_py, "\nGL_PGI_misc_hints\n");
    GL_GetFuncEXT(PFNGLHINTPGIPROC                           ,glHintPGI              );
    #endif /* GL_PGI_misc_hints */



    #ifdef GL_SGIS_detail_texture
	fprintf(LogGlGetFunctions_py, "\nGL_SGIS_detail_texture\n");
    GL_GetFuncEXT(PFNGLDETAILTEXFUNCSGISPROC                       ,glDetailTexFuncSGIS       );
    GL_GetFuncEXT(PFNGLGETDETAILTEXFUNCSGISPROC                    ,glGetDetailTexFuncSGIS    );
    #endif /* GL_SGIS_detail_texture */

    #ifdef GL_SGIS_fog_function
	fprintf(LogGlGetFunctions_py, "\nGL_SGIS_fog_function\n");
    GL_GetFuncEXT(PFNGLFOGFUNCSGISPROC                              ,glFogFuncSGIS             );
    GL_GetFuncEXT(PFNGLGETFOGFUNCSGISPROC                           ,glGetFogFuncSGIS          );
    #endif /* GL_SGIS_fog_function */

    #ifdef GL_SGIS_multisample
	fprintf(LogGlGetFunctions_py, "\nGL_SGIS_multisample\n");
    GL_GetFuncEXT(PFNGLSAMPLEMASKSGISPROC                         ,glSampleMaskSGIS           );
    GL_GetFuncEXT(PFNGLSAMPLEPATTERNSGISPROC                      ,glSamplePatternSGIS        );
    #endif /* GL_SGIS_multisample */

    #ifdef GL_SGIS_pixel_texture
	fprintf(LogGlGetFunctions_py, "\nGL_SGIS_pixel_texture\n");
    GL_GetFuncEXT(PFNGLPIXELTEXGENPARAMETERISGISPROC                         ,glPixelTexGenParameteriSGIS        );
    GL_GetFuncEXT(PFNGLPIXELTEXGENPARAMETERIVSGISPROC                        ,glPixelTexGenParameterivSGIS       );
    GL_GetFuncEXT(PFNGLPIXELTEXGENPARAMETERFSGISPROC                         ,glPixelTexGenParameterfSGIS        );
    GL_GetFuncEXT(PFNGLPIXELTEXGENPARAMETERFVSGISPROC                        ,glPixelTexGenParameterfvSGIS       );
    GL_GetFuncEXT(PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC                     ,glGetPixelTexGenParameterivSGIS    );
    GL_GetFuncEXT(PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC                     ,glGetPixelTexGenParameterfvSGIS    );
    #endif /* GL_SGIS_pixel_texture */
	
    #ifdef GL_SGIS_point_parameters
	fprintf(LogGlGetFunctions_py, "\nGL_SGIS_point_parameters\n");
    GL_GetFuncEXT(PFNGLPOINTPARAMETERFSGISPROC                          ,glPointParameterfSGIS         );
    GL_GetFuncEXT(PFNGLPOINTPARAMETERFVSGISPROC                         ,glPointParameterfvSGIS        );
    #endif /* GL_SGIS_point_parameters */

    #ifdef GL_SGIS_sharpen_texture
	fprintf(LogGlGetFunctions_py, "\nGL_SGIS_sharpen_texture\n");
    GL_GetFuncEXT(PFNGLSHARPENTEXFUNCSGISPROC                         ,glSharpenTexFuncSGIS         );
    GL_GetFuncEXT(PFNGLGETSHARPENTEXFUNCSGISPROC                      ,glGetSharpenTexFuncSGIS      );
    #endif /* GL_SGIS_sharpen_texture */

    #ifdef GL_SGIS_texture4D
	fprintf(LogGlGetFunctions_py, "\nGL_SGIS_texture4D\n");
    GL_GetFuncEXT(PFNGLTEXIMAGE4DSGISPROC                          ,glTexImage4DSGIS            );
    GL_GetFuncEXT(PFNGLTEXSUBIMAGE4DSGISPROC                       ,glTexSubImage4DSGIS         );
    #endif /* GL_SGIS_texture4D */

    #ifdef GL_SGIS_texture_color_mask
	fprintf(LogGlGetFunctions_py, "\nGL_SGIS_texture_color_mask\n");
    GL_GetFuncEXT(PFNGLTEXTURECOLORMASKSGISPROC                     ,glTextureColorMaskSGIS       );
    #endif /* GL_SGIS_texture_color_mask */

    #ifdef GL_SGIS_texture_filter4
	fprintf(LogGlGetFunctions_py, "\nGL_SGIS_texture_filter4\n");
    GL_GetFuncEXT(PFNGLGETTEXFILTERFUNCSGISPROC                       ,glGetTexFilterFuncSGIS        );
    GL_GetFuncEXT(PFNGLTEXFILTERFUNCSGISPROC                          ,glTexFilterFuncSGIS           );
    #endif /* GL_SGIS_texture_filter4 */

	
	
    #ifdef GL_SGIX_async
	fprintf(LogGlGetFunctions_py, "\nGL_SGIX_async\n");
    GL_GetFuncEXT(PFNGLASYNCMARKERSGIXPROC                                ,glAsyncMarkerSGIX            );
    GL_GetFuncEXT(PFNGLFINISHASYNCSGIXPROC                                ,glFinishAsyncSGIX            );
    GL_GetFuncEXT(PFNGLPOLLASYNCSGIXPROC                                  ,glPollAsyncSGIX              );
    GL_GetFuncEXT(PFNGLGENASYNCMARKERSSGIXPROC                            ,glGenAsyncMarkersSGIX        );
    GL_GetFuncEXT(PFNGLDELETEASYNCMARKERSSGIXPROC                         ,glDeleteAsyncMarkersSGIX     );
    GL_GetFuncEXT(PFNGLISASYNCMARKERSGIXPROC                              ,glIsAsyncMarkerSGIX          );
    #endif /* GL_SGIX_async */

    #ifdef GL_SGIX_flush_raster
	fprintf(LogGlGetFunctions_py, "\nGL_SGIX_flush_raster\n");
    GL_GetFuncEXT(PFNGLFLUSHRASTERSGIXPROC                          ,glFlushRasterSGIX            );
    #endif /* GL_SGIX_flush_raster */

    #ifdef GL_SGIX_fragment_lighting
	fprintf(LogGlGetFunctions_py, "\nGL_SGIX_fragment_lighting\n");
    GL_GetFuncEXT(PFNGLFRAGMENTCOLORMATERIALSGIXPROC                         ,glFragmentColorMaterialSGIX    );
    GL_GetFuncEXT(PFNGLFRAGMENTLIGHTFSGIXPROC                                ,glFragmentLightfSGIX           );
    GL_GetFuncEXT(PFNGLFRAGMENTLIGHTFVSGIXPROC                               ,glFragmentLightfvSGIX          );
    GL_GetFuncEXT(PFNGLFRAGMENTLIGHTISGIXPROC                                ,glFragmentLightiSGIX           );
    GL_GetFuncEXT(PFNGLFRAGMENTLIGHTIVSGIXPROC                               ,glFragmentLightivSGIX          );
    GL_GetFuncEXT(PFNGLFRAGMENTLIGHTMODELFSGIXPROC                           ,glFragmentLightModelfSGIX      );
    GL_GetFuncEXT(PFNGLFRAGMENTLIGHTMODELFVSGIXPROC                          ,glFragmentLightModelfvSGIX     );
    GL_GetFuncEXT(PFNGLFRAGMENTLIGHTMODELISGIXPROC                           ,glFragmentLightModeliSGIX      );
    GL_GetFuncEXT(PFNGLFRAGMENTLIGHTMODELIVSGIXPROC                          ,glFragmentLightModelivSGIX     );
    GL_GetFuncEXT(PFNGLFRAGMENTMATERIALFSGIXPROC                             ,glFragmentMaterialfSGIX        );
    GL_GetFuncEXT(PFNGLFRAGMENTMATERIALFVSGIXPROC                            ,glFragmentMaterialfvSGIX       );
    GL_GetFuncEXT(PFNGLFRAGMENTMATERIALISGIXPROC                             ,glFragmentMaterialiSGIX        );
    GL_GetFuncEXT(PFNGLFRAGMENTMATERIALIVSGIXPROC                            ,glFragmentMaterialivSGIX       );
    GL_GetFuncEXT(PFNGLGETFRAGMENTLIGHTFVSGIXPROC                            ,glGetFragmentLightfvSGIX       );
    GL_GetFuncEXT(PFNGLGETFRAGMENTLIGHTIVSGIXPROC                            ,glGetFragmentLightivSGIX       );
    GL_GetFuncEXT(PFNGLGETFRAGMENTMATERIALFVSGIXPROC                         ,glGetFragmentMaterialfvSGIX    );
    GL_GetFuncEXT(PFNGLGETFRAGMENTMATERIALIVSGIXPROC                         ,glGetFragmentMaterialivSGIX    );
    GL_GetFuncEXT(PFNGLLIGHTENVISGIXPROC                                     ,glLightEnviSGIX                );
    #endif /* GL_SGIX_fragment_lighting */

    #ifdef GL_SGIX_framezoom
	fprintf(LogGlGetFunctions_py, "\nGL_SGIX_framezoom\n");
    GL_GetFuncEXT(PFNGLFRAMEZOOMSGIXPROC                            ,glFrameZoomSGIX             );
    #endif /* GL_SGIX_framezoom */

    #ifdef GL_SGIX_igloo_interface
	fprintf(LogGlGetFunctions_py, "\nGL_SGIX_igloo_interface\n");
    GL_GetFuncEXT(PFNGLIGLOOINTERFACESGIXPROC                        ,glIglooInterfaceSGIX         );
    #endif /* GL_SGIX_igloo_interface */

    #ifdef GL_SGIX_instruments
	fprintf(LogGlGetFunctions_py, "\nGL_SGIX_instruments\n");
    GL_GetFuncEXT(PFNGLGETINSTRUMENTSSGIXPROC                        ,glGetInstrumentsSGIX        );
    GL_GetFuncEXT(PFNGLINSTRUMENTSBUFFERSGIXPROC                     ,glInstrumentsBufferSGIX     );
    GL_GetFuncEXT(PFNGLPOLLINSTRUMENTSSGIXPROC                       ,glPollInstrumentsSGIX       );
    GL_GetFuncEXT(PFNGLREADINSTRUMENTSSGIXPROC                       ,glReadInstrumentsSGIX       );
    GL_GetFuncEXT(PFNGLSTARTINSTRUMENTSSGIXPROC                      ,glStartInstrumentsSGIX      );
    GL_GetFuncEXT(PFNGLSTOPINSTRUMENTSSGIXPROC                       ,glStopInstrumentsSGIX       );
    #endif /* GL_SGIX_instruments */

    #ifdef GL_SGIX_list_priority
	fprintf(LogGlGetFunctions_py, "\nGL_SGIX_list_priority\n");
    GL_GetFuncEXT(PFNGLGETLISTPARAMETERFVSGIXPROC                ,glGetListParameterfvSGIX   );
    GL_GetFuncEXT(PFNGLGETLISTPARAMETERIVSGIXPROC                ,glGetListParameterivSGIX   );
    GL_GetFuncEXT(PFNGLLISTPARAMETERFSGIXPROC                    ,glListParameterfSGIX       );
    GL_GetFuncEXT(PFNGLLISTPARAMETERFVSGIXPROC                   ,glListParameterfvSGIX      );
    GL_GetFuncEXT(PFNGLLISTPARAMETERISGIXPROC                    ,glListParameteriSGIX       );
    GL_GetFuncEXT(PFNGLLISTPARAMETERIVSGIXPROC                   ,glListParameterivSGIX      );
    #endif /* GL_SGIX_list_priority */

    #ifdef GL_SGIX_pixel_texture
	fprintf(LogGlGetFunctions_py, "\nGL_SGIX_pixel_texture\n");
    GL_GetFuncEXT(PFNGLPIXELTEXGENSGIXPROC              ,glPixelTexGenSGIX  );
    #endif /* GL_SGIX_pixel_texture */

    #ifdef GL_SGIX_polynomial_ffd
	fprintf(LogGlGetFunctions_py, "\nGL_SGIX_polynomial_ffd\n");
    GL_GetFuncEXT(PFNGLDEFORMATIONMAP3DSGIXPROC                            ,glDeformationMap3dSGIX              );
    GL_GetFuncEXT(PFNGLDEFORMATIONMAP3FSGIXPROC                            ,glDeformationMap3fSGIX              );
    GL_GetFuncEXT(PFNGLDEFORMSGIXPROC                                      ,glDeformSGIX                        );
    GL_GetFuncEXT(PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC                  ,glLoadIdentityDeformationMapSGIX    );
    #endif /* GL_SGIX_polynomial_ffd */

    #ifdef GL_SGIX_reference_plane
	fprintf(LogGlGetFunctions_py, "\nGL_SGIX_reference_plane\n");
    GL_GetFuncEXT(PFNGLREFERENCEPLANESGIXPROC              ,glReferencePlaneSGIX );
    #endif /* GL_SGIX_reference_plane */

    #ifdef GL_SGIX_sprite
	fprintf(LogGlGetFunctions_py, "\nGL_SGIX_sprite\n");
    GL_GetFuncEXT(PFNGLSPRITEPARAMETERFSGIXPROC                 ,glSpriteParameterfSGIX     );
	GL_GetFuncEXT(PFNGLSPRITEPARAMETERFVSGIXPROC                ,glSpriteParameterfvSGIX    );
	GL_GetFuncEXT(PFNGLSPRITEPARAMETERISGIXPROC                 ,glSpriteParameteriSGIX     );
	GL_GetFuncEXT(PFNGLSPRITEPARAMETERIVSGIXPROC                ,glSpriteParameterivSGIX    );
    #endif /* GL_SGIX_sprite */

    #ifdef GL_SGIX_subsample
	fprintf(LogGlGetFunctions_py, "\nGL_SGIX_subsample\n");
    GL_GetFuncEXT(PFNGLTAGSAMPLEBUFFERSGIXPROC              ,glTagSampleBufferSGIX );
    #endif /* GL_SGIX_tag_sample_buffer */

	

    #ifdef GL_SGI_color_table
	fprintf(LogGlGetFunctions_py, "\nGL_SGI_color_table\n");
    GL_GetFuncEXT(PFNGLCOLORTABLESGIPROC                                 ,glColorTableSGI                 );
    GL_GetFuncEXT(PFNGLCOLORTABLEPARAMETERFVSGIPROC                      ,glColorTableParameterfvSGI      );
    GL_GetFuncEXT(PFNGLCOLORTABLEPARAMETERIVSGIPROC                      ,glColorTableParameterivSGI      );
    GL_GetFuncEXT(PFNGLCOPYCOLORTABLESGIPROC                             ,glCopyColorTableSGI             );
    GL_GetFuncEXT(PFNGLGETCOLORTABLESGIPROC                              ,glGetColorTableSGI              );
    GL_GetFuncEXT(PFNGLGETCOLORTABLEPARAMETERFVSGIPROC                   ,glGetColorTableParameterfvSGI   );
    GL_GetFuncEXT(PFNGLGETCOLORTABLEPARAMETERIVSGIPROC                   ,glGetColorTableParameterivSGI   );
    #endif /* GL_SGI_color_table */


	
    #ifdef GL_SUNX_constant_data
	fprintf(LogGlGetFunctions_py, "\nGL_SUNX_constant_data\n");
    GL_GetFuncEXT(PFNGLFINISHTEXTURESUNXPROC              ,glFinishTextureSUNX );
    #endif /* GL_SUNX_constant_data */

	

    #ifdef GL_SUN_global_alpha
	fprintf(LogGlGetFunctions_py, "\nGL_SUN_global_alpha\n");
    GL_GetFuncEXT(PFNGLGLOBALALPHAFACTORBSUNPROC                 ,glGlobalAlphaFactorbSUN      );
	GL_GetFuncEXT(PFNGLGLOBALALPHAFACTORSSUNPROC                 ,glGlobalAlphaFactorsSUN      );
	GL_GetFuncEXT(PFNGLGLOBALALPHAFACTORISUNPROC                 ,glGlobalAlphaFactoriSUN      );
	GL_GetFuncEXT(PFNGLGLOBALALPHAFACTORFSUNPROC                 ,glGlobalAlphaFactorfSUN      );
	GL_GetFuncEXT(PFNGLGLOBALALPHAFACTORDSUNPROC                 ,glGlobalAlphaFactordSUN      );
	GL_GetFuncEXT(PFNGLGLOBALALPHAFACTORUBSUNPROC                ,glGlobalAlphaFactorubSUN     );
	GL_GetFuncEXT(PFNGLGLOBALALPHAFACTORUSSUNPROC                ,glGlobalAlphaFactorusSUN     );
	GL_GetFuncEXT(PFNGLGLOBALALPHAFACTORUISUNPROC                ,glGlobalAlphaFactoruiSUN     );
    #endif /* GL_SUN_global_alpha */

    #ifdef GL_SUN_mesh_array
	fprintf(LogGlGetFunctions_py, "\nGL_SUN_mesh_array\n");
    GL_GetFuncEXT(PFNGLDRAWMESHARRAYSSUNPROC              ,glDrawMeshArraysSUN );
    #endif /* GL_SUN_mesh_array */

    #ifdef GL_SUN_triangle_list
	fprintf(LogGlGetFunctions_py, "\nGL_SUN_triangle_list\n");
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUISUNPROC                       ,glReplacementCodeuiSUN          );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUSSUNPROC                       ,glReplacementCodeusSUN          );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUBSUNPROC                       ,glReplacementCodeubSUN          );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUIVSUNPROC                      ,glReplacementCodeuivSUN         );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUSVSUNPROC                      ,glReplacementCodeusvSUN         );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUBVSUNPROC                      ,glReplacementCodeubvSUN         );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEPOINTERSUNPROC                  ,glReplacementCodePointerSUN     );
    #endif /* GL_SUN_triangle_list */

    #ifdef GL_SUN_vertex
	fprintf(LogGlGetFunctions_py, "\nGL_SUN_vertex\n");
    GL_GetFuncEXT(PFNGLCOLOR4UBVERTEX2FSUNPROC                                                       ,glColor4ubVertex2fSUN                                       );
    GL_GetFuncEXT(PFNGLCOLOR4UBVERTEX2FVSUNPROC                                                      ,glColor4ubVertex2fvSUN                                      );
    GL_GetFuncEXT(PFNGLCOLOR4UBVERTEX3FSUNPROC                                                       ,glColor4ubVertex3fSUN                                       );
    GL_GetFuncEXT(PFNGLCOLOR4UBVERTEX3FVSUNPROC                                                      ,glColor4ubVertex3fvSUN                                      );
    GL_GetFuncEXT(PFNGLCOLOR3FVERTEX3FSUNPROC                                                        ,glColor3fVertex3fSUN                                        );
    GL_GetFuncEXT(PFNGLCOLOR3FVERTEX3FVSUNPROC                                                       ,glColor3fVertex3fvSUN                                       );
    GL_GetFuncEXT(PFNGLNORMAL3FVERTEX3FSUNPROC                                                       ,glNormal3fVertex3fSUN                                       );
    GL_GetFuncEXT(PFNGLNORMAL3FVERTEX3FVSUNPROC                                                      ,glNormal3fVertex3fvSUN                                      );
    GL_GetFuncEXT(PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC                                                ,glColor4fNormal3fVertex3fSUN                                );
    GL_GetFuncEXT(PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC                                               ,glColor4fNormal3fVertex3fvSUN                               );
    GL_GetFuncEXT(PFNGLTEXCOORD2FVERTEX3FSUNPROC                                                     ,glTexCoord2fVertex3fSUN                                     );
    GL_GetFuncEXT(PFNGLTEXCOORD2FVERTEX3FVSUNPROC                                                    ,glTexCoord2fVertex3fvSUN                                    );
    GL_GetFuncEXT(PFNGLTEXCOORD4FVERTEX4FSUNPROC                                                     ,glTexCoord4fVertex4fSUN                                     );
    GL_GetFuncEXT(PFNGLTEXCOORD4FVERTEX4FVSUNPROC                                                    ,glTexCoord4fVertex4fvSUN                                    );
    GL_GetFuncEXT(PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC                                             ,glTexCoord2fColor4ubVertex3fSUN                             );
    GL_GetFuncEXT(PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC                                            ,glTexCoord2fColor4ubVertex3fvSUN                            );
    GL_GetFuncEXT(PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC                                              ,glTexCoord2fColor3fVertex3fSUN                              );
    GL_GetFuncEXT(PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC                                             ,glTexCoord2fColor3fVertex3fvSUN                             );
    GL_GetFuncEXT(PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC                                             ,glTexCoord2fNormal3fVertex3fSUN                             );
    GL_GetFuncEXT(PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC                                            ,glTexCoord2fNormal3fVertex3fvSUN                            );
    GL_GetFuncEXT(PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC                                      ,glTexCoord2fColor4fNormal3fVertex3fSUN                      );
    GL_GetFuncEXT(PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC                                     ,glTexCoord2fColor4fNormal3fVertex3fvSUN                     );
    GL_GetFuncEXT(PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC                                      ,glTexCoord4fColor4fNormal3fVertex4fSUN                      );
    GL_GetFuncEXT(PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC                                     ,glTexCoord4fColor4fNormal3fVertex4fvSUN                     );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC                                              ,glReplacementCodeuiVertex3fSUN                              );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC                                             ,glReplacementCodeuiVertex3fvSUN                             );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC                                      ,glReplacementCodeuiColor4ubVertex3fSUN                      );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC                                     ,glReplacementCodeuiColor4ubVertex3fvSUN                     );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC                                       ,glReplacementCodeuiColor3fVertex3fSUN                       );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC                                      ,glReplacementCodeuiColor3fVertex3fvSUN                      );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC                                      ,glReplacementCodeuiNormal3fVertex3fSUN                      );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC                                     ,glReplacementCodeuiNormal3fVertex3fvSUN                     );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC                               ,glReplacementCodeuiColor4fNormal3fVertex3fSUN               );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC                              ,glReplacementCodeuiColor4fNormal3fVertex3fvSUN              );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC                                    ,glReplacementCodeuiTexCoord2fVertex3fSUN                    );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC                                   ,glReplacementCodeuiTexCoord2fVertex3fvSUN                   );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC                            ,glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN            );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC                           ,glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN           );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC                     ,glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN     );
    GL_GetFuncEXT(PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC                    ,glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN    );
    #endif /* GL_SUN_vertex */
	
	
	
	fclose(LogGlGetFunctions_py);
	return 0;
}



