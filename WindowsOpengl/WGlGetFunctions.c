#include <Windows.h>
#include <stdio.h>
#include "gl\gl.h"
#include "wgl+wglext.h"
#include "WGLfunctions.h"
#define  WGL_WIN_MAIN 1
#undef   WGLFunctions_h
#include "WGLFunctions.h"

#ifndef _opengl32_dll_
#define _opengl32_dll_ 1
HMODULE wopengl32_dll = NULL;
#endif

#ifndef invalidPointer
#define	invalidPointer (p == (void*)0x0 || (p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) || (p == (void*)-1) )
#endif

FILE *LogWGlGetFunctions_py = NULL;
char WglBuffer256[256];

// char * WGL_GetFunc1(char * type, char * ext){
	// sprintf(WglBuffer256, "%s%s", type, ext);
	// return WglBuffer256;
// };

void *WGL_GetF(const char *name)
{
    void *p = (void *)wglGetProcAddress(name);
    // opengl32.dll
    if  (p == (void*)0x0  ||
        (p == (void*)0x1) ||
        (p == (void*)0x2) ||
        (p == (void*)0x3) ||
        (p == (void*)-1) )
    {
        p = (void *)GetProcAddress(wopengl32_dll, name);
    }
    if  (p == (void*)0x0  ||
        (p == (void*)0x1) ||
        (p == (void*)0x2) ||
        (p == (void*)0x3) ||
        (p == (void*)-1) )
    {
        p = NULL;
    }
    fprintf(LogWGlGetFunctions_py, "    %x : %s\n", p, name);
    return p;
}
void *WGL_GetF2(const char *name)
{
	void * p;
		p = (void *)wglGetProcAddress(name);
	// opengl32.dll
	if	(invalidPointer)
	{
		p = (void *)GetProcAddress(wopengl32_dll, name);
	}
	fprintf(LogWGlGetFunctions_py, "	%x : %s\n", p, name);
	
    if  (invalidPointer)
    {
		// ARB
		sprintf(WglBuffer256, "%s%s\0\0", name, "ARB");
		p = (void *)wglGetProcAddress(WglBuffer256);
		if	(invalidPointer)
		{
			p = (void *)GetProcAddress(wopengl32_dll, WglBuffer256);
		}
		
		// EXT
		if  (invalidPointer)
		{
			sprintf(WglBuffer256, "%s%s\0\0", name, "EXT");
			p = (void *)wglGetProcAddress(WglBuffer256);
			if	(invalidPointer)
			{
				p = (void *)GetProcAddress(wopengl32_dll, WglBuffer256);
			}
		}
		
		// NV
		if  (invalidPointer)
		{
			sprintf(WglBuffer256, "%s%s\0\0", name, "NV");
			p = (void *)wglGetProcAddress(WglBuffer256);
			if	(invalidPointer)
			{
				p = (void *)GetProcAddress(wopengl32_dll, WglBuffer256);
			}
		}
		
		// AMD
		if  (invalidPointer)
		{
			sprintf(WglBuffer256, "%s%s\0\0", name, "AMD");
			p = (void *)wglGetProcAddress(WglBuffer256);
			if	(invalidPointer)
			{
				p = (void *)GetProcAddress(wopengl32_dll, WglBuffer256);
			}
		}
		
		// ATI
		if  (invalidPointer)
		{
			sprintf(WglBuffer256, "%s%s\0\0", name, "ATI");
			p = (void *)wglGetProcAddress(WglBuffer256);
			if	(invalidPointer)
			{
				p = (void *)GetProcAddress(wopengl32_dll, WglBuffer256);
			}
		}
		
		// NVX
		if  (invalidPointer)
		{
			sprintf(WglBuffer256, "%s%s\0\0", name, "NVX");
			p = (void *)wglGetProcAddress(WglBuffer256);
			if	(invalidPointer)
			{
				p = (void *)GetProcAddress(wopengl32_dll, WglBuffer256);
			}
		}
		if	(invalidPointer)
			p = NULL;
		if	(!invalidPointer)
			fprintf(LogWGlGetFunctions_py, "	  %x : %s\n", p, WglBuffer256);
	}
	return p;
}

#define WGL_GetFuncEXT(type,name) name=(type)WGL_GetF(#name);

#define WGL_GetFunc(type,name) name=(type)WGL_GetF2(#name); 

/*#define WGL_GetFunc(type,name) name=(type)WGL_GetF(#name);          	\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "ARB"));         	\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "EXT"));         	\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "AMD"));         	\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "ATI"));         	\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "NV"));          	\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "NVX"));         	\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "3DFX"));      		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "AMDX"));      		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "APPLE"));     		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "GREMEDY"));    		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "HP"));        		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "I3D"));       		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "IBM"));       		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "INGR"));      		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "INTEL"));     		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "KHR"));       		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "KTX"));       		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "MESA"));      		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "OES"));       		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "OVR"));       		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "PGI"));       		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "SGI"));       		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "SGIS"));      		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "SGIX"));      		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "SUN"));       		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "SUNX"));      		\
if(!name) name=(type)WGL_GetF(WGL_GetFunc1(#name , "WIN"));       	*/



 int LoadWGL(){
 LogWGlGetFunctions_py = fopen("LogWGlGetFunctions.py", "wb");
 if (!wopengl32_dll)
  wopengl32_dll = LoadLibraryA("opengl32.dll");
#ifdef WGL_VERSION_1_0
#ifndef _WINGDI_
 fprintf(LogWGlGetFunctions_py, "\nWGL_VERSION_1_0\n");
 WGL_GetFunc(PFNCHOOSEPIXELFORMATPROC                     ,ChoosePixelFormat                    );              
 WGL_GetFunc(PFNDESCRIBEPIXELFORMATPROC                   ,DescribePixelFormat                  );              
 WGL_GetFunc(PFNGETENHMETAFILEPIXELFORMATPROC             ,GetEnhMetaFilePixelFormat            );              
 WGL_GetFunc(PFNGETPIXELFORMATPROC                        ,GetPixelFormat                       );              
 WGL_GetFunc(PFNSETPIXELFORMATPROC                        ,SetPixelFormat                       );              
 WGL_GetFunc(PFNSWAPBUFFERSPROC                           ,SwapBuffers                          );              
 WGL_GetFunc(PFNWGLCOPYCONTEXTPROC                        ,wglCopyContext                       );              
 WGL_GetFunc(PFNWGLCREATECONTEXTPROC                      ,wglCreateContext                     );              
 WGL_GetFunc(PFNWGLCREATELAYERCONTEXTPROC                 ,wglCreateLayerContext                );              
 WGL_GetFunc(PFNWGLDELETECONTEXTPROC                      ,wglDeleteContext                     );              
 WGL_GetFunc(PFNWGLDESCRIBELAYERPLANEPROC                 ,wglDescribeLayerPlane                );              
 WGL_GetFunc(PFNWGLGETCURRENTCONTEXTPROC                  ,wglGetCurrentContext                 );              
 WGL_GetFunc(PFNWGLGETCURRENTDCPROC                       ,wglGetCurrentDC                      );              
 WGL_GetFunc(PFNWGLGETLAYERPALETTEENTRIESPROC             ,wglGetLayerPaletteEntries            );              
 WGL_GetFunc(PFNWGLGETPROCADDRESSPROC                     ,wglGetProcAddress                    );              
 WGL_GetFunc(PFNWGLMAKECURRENTPROC                        ,wglMakeCurrent                       );              
 WGL_GetFunc(PFNWGLREALIZELAYERPALETTEPROC                ,wglRealizeLayerPalette               );              
 WGL_GetFunc(PFNWGLSETLAYERPALETTEENTRIESPROC             ,wglSetLayerPaletteEntries            );              
 WGL_GetFunc(PFNWGLSHARELISTSPROC                         ,wglShareLists                        );              
 WGL_GetFunc(PFNWGLSWAPLAYERBUFFERSPROC                   ,wglSwapLayerBuffers                  );              
 WGL_GetFunc(PFNWGLUSEFONTBITMAPSPROC                     ,wglUseFontBitmaps                    );              
 WGL_GetFunc(PFNWGLUSEFONTBITMAPSAPROC                    ,wglUseFontBitmapsA                   );              
 WGL_GetFunc(PFNWGLUSEFONTBITMAPSWPROC                    ,wglUseFontBitmapsW                   );              
 WGL_GetFunc(PFNWGLUSEFONTOUTLINESPROC                    ,wglUseFontOutlines                   );              
 WGL_GetFunc(PFNWGLUSEFONTOUTLINESAPROC                   ,wglUseFontOutlinesA                  );              
 WGL_GetFunc(PFNWGLUSEFONTOUTLINESWPROC                   ,wglUseFontOutlinesW                  );              
#endif /* _WINGDI_ */     
#endif /* WGL_VERSION_1_0 */                                        
                                                                   
#ifdef WGL_ARB_buffer_region                                       
 fprintf(LogWGlGetFunctions_py, "\nWGL_ARB_buffer_region\n");
 WGL_GetFuncEXT(PFNWGLCREATEBUFFERREGIONARBPROC              ,wglCreateBufferRegionARB             );              
 WGL_GetFuncEXT(PFNWGLDELETEBUFFERREGIONARBPROC              ,wglDeleteBufferRegionARB             );              
 WGL_GetFuncEXT(PFNWGLSAVEBUFFERREGIONARBPROC                ,wglSaveBufferRegionARB               );              
 WGL_GetFuncEXT(PFNWGLRESTOREBUFFERREGIONARBPROC             ,wglRestoreBufferRegionARB            );              
#endif /* WGL_ARB_buffer_region */                                  
                                                                    
                                                                    
#ifdef WGL_ARB_create_context                                      
 fprintf(LogWGlGetFunctions_py, "\nWGL_ARB_create_context\n");
 WGL_GetFuncEXT(PFNWGLCREATECONTEXTATTRIBSARBPROC            ,wglCreateContextAttribsARB           );              
#endif /* WGL_ARB_create_context */                                 
                                                                    
                                                                    
#ifdef WGL_ARB_extensions_string                                   
 fprintf(LogWGlGetFunctions_py, "\nWGL_ARB_extensions_string\n");
 WGL_GetFuncEXT(PFNWGLGETEXTENSIONSSTRINGARBPROC             ,wglGetExtensionsStringARB            );              
#endif /* WGL_ARB_extensions_string */                              
                                                                    
                                                                    
#ifdef WGL_ARB_make_current_read                                   
 fprintf(LogWGlGetFunctions_py, "\nWGL_ARB_make_current_read\n");
 WGL_GetFuncEXT(PFNWGLMAKECONTEXTCURRENTARBPROC              ,wglMakeContextCurrentARB             );              
 WGL_GetFuncEXT(PFNWGLGETCURRENTREADDCARBPROC                ,wglGetCurrentReadDCARB               );              
#endif /* WGL_ARB_make_current_read */                              
                                                                    
                                                                    
#ifdef WGL_ARB_pbuffer                                             
 fprintf(LogWGlGetFunctions_py, "\nWGL_ARB_pbuffer\n");
 WGL_GetFuncEXT(PFNWGLCREATEPBUFFERARBPROC                   ,wglCreatePbufferARB                  );              
 WGL_GetFuncEXT(PFNWGLGETPBUFFERDCARBPROC                    ,wglGetPbufferDCARB                   );              
 WGL_GetFuncEXT(PFNWGLRELEASEPBUFFERDCARBPROC                ,wglReleasePbufferDCARB               );              
 WGL_GetFuncEXT(PFNWGLDESTROYPBUFFERARBPROC                  ,wglDestroyPbufferARB                 );              
 WGL_GetFuncEXT(PFNWGLQUERYPBUFFERARBPROC                    ,wglQueryPbufferARB                   );              
#endif /* WGL_ARB_pbuffer */                                        
                                                                    
#ifdef WGL_ARB_pixel_format                                        
 fprintf(LogWGlGetFunctions_py, "\nWGL_ARB_pixel_format\n");
 WGL_GetFuncEXT(PFNWGLGETPIXELFORMATATTRIBIVARBPROC          ,wglGetPixelFormatAttribivARB         );              
 WGL_GetFuncEXT(PFNWGLGETPIXELFORMATATTRIBFVARBPROC          ,wglGetPixelFormatAttribfvARB         );              
 WGL_GetFuncEXT(PFNWGLCHOOSEPIXELFORMATARBPROC               ,wglChoosePixelFormatARB              );              
#endif /* WGL_ARB_pixel_format */                                   
                                                                    
                                                                    
#ifdef WGL_ARB_render_texture
 fprintf(LogWGlGetFunctions_py, "\nWGL_ARB_render_texture\n");
 WGL_GetFuncEXT(PFNWGLBINDTEXIMAGEARBPROC                    ,wglBindTexImageARB                   );              
 WGL_GetFuncEXT(PFNWGLRELEASETEXIMAGEARBPROC                 ,wglReleaseTexImageARB                );              
 WGL_GetFuncEXT(PFNWGLSETPBUFFERATTRIBARBPROC                ,wglSetPbufferAttribARB               );              
#endif /* WGL_ARB_render_texture */                                 
                                                                    
                                                                    
#ifdef WGL_3DL_stereo_control 
 fprintf(LogWGlGetFunctions_py, "\nWGL_3DL_stereo_control\n");                                     
 WGL_GetFuncEXT(PFNWGLSETSTEREOEMITTERSTATE3DLPROC           ,wglSetStereoEmitterState3DL          );              
#endif /* WGL_3DL_stereo_control */                                 
                                                                    
#ifdef WGL_AMD_gpu_association 
 fprintf(LogWGlGetFunctions_py, "\nWGL_AMD_gpu_association\n");                                    
 WGL_GetFuncEXT(PFNWGLGETGPUIDSAMDPROC                       ,wglGetGPUIDsAMD                      );              
 WGL_GetFuncEXT(PFNWGLGETGPUINFOAMDPROC                      ,wglGetGPUInfoAMD                     );              
 WGL_GetFuncEXT(PFNWGLGETCONTEXTGPUIDAMDPROC                 ,wglGetContextGPUIDAMD                );              
 WGL_GetFuncEXT(PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC         ,wglCreateAssociatedContextAMD        );              
 WGL_GetFuncEXT(PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC  ,wglCreateAssociatedContextAttribsAMD );              
 WGL_GetFuncEXT(PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC         ,wglDeleteAssociatedContextAMD        );              
 WGL_GetFuncEXT(PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC    ,wglMakeAssociatedContextCurrentAMD   );              
 WGL_GetFuncEXT(PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC     ,wglGetCurrentAssociatedContextAMD    );              
 WGL_GetFuncEXT(PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC          ,wglBlitContextFramebufferAMD         );              
#endif /* WGL_AMD_gpu_association */                                
                                                                    
                                                                    
#ifdef WGL_EXT_display_color_table
 fprintf(LogWGlGetFunctions_py, "\nWGL_EXT_display_color_table\n");                                 
 WGL_GetFuncEXT(PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC         ,wglCreateDisplayColorTableEXT        );              
 WGL_GetFuncEXT(PFNWGLLOADDISPLAYCOLORTABLEEXTPROC           ,wglLoadDisplayColorTableEXT          );              
 WGL_GetFuncEXT(PFNWGLBINDDISPLAYCOLORTABLEEXTPROC           ,wglBindDisplayColorTableEXT          );              
 WGL_GetFuncEXT(PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC        ,wglDestroyDisplayColorTableEXT       );              
#endif /* WGL_EXT_display_color_table */                            
                                                                    
#ifdef WGL_EXT_extensions_string      
 fprintf(LogWGlGetFunctions_py, "\nWGL_EXT_extensions_string\n");                             
 WGL_GetFuncEXT(PFNWGLGETEXTENSIONSSTRINGEXTPROC             ,wglGetExtensionsStringEXT            );              
#endif /* WGL_EXT_extensions_string */                              
                                                                    
                                                                    
#ifdef WGL_EXT_make_current_read  
 fprintf(LogWGlGetFunctions_py, "\nWGL_EXT_make_current_read\n");                                 
 WGL_GetFuncEXT(PFNWGLMAKECONTEXTCURRENTEXTPROC              ,wglMakeContextCurrentEXT             );              
 WGL_GetFuncEXT(PFNWGLGETCURRENTREADDCEXTPROC                ,wglGetCurrentReadDCEXT               );              
#endif /* WGL_EXT_make_current_read */                              
                                                                    
                                                                    
#ifdef WGL_EXT_pbuffer          
 fprintf(LogWGlGetFunctions_py, "\nWGL_EXT_pbuffer\n");                                   
 WGL_GetFuncEXT(PFNWGLCREATEPBUFFEREXTPROC                   ,wglCreatePbufferEXT                  );              
 WGL_GetFuncEXT(PFNWGLGETPBUFFERDCEXTPROC                    ,wglGetPbufferDCEXT                   );              
 WGL_GetFuncEXT(PFNWGLRELEASEPBUFFERDCEXTPROC                ,wglReleasePbufferDCEXT               );              
 WGL_GetFuncEXT(PFNWGLDESTROYPBUFFEREXTPROC                  ,wglDestroyPbufferEXT                 );              
 WGL_GetFuncEXT(PFNWGLQUERYPBUFFEREXTPROC                    ,wglQueryPbufferEXT                   );              
#endif /* WGL_EXT_pbuffer */                                        
                                                                    
#ifdef WGL_EXT_pixel_format    
 fprintf(LogWGlGetFunctions_py, "\nWGL_EXT_pixel_format\n");                                    
 WGL_GetFuncEXT(PFNWGLGETPIXELFORMATATTRIBIVEXTPROC          ,wglGetPixelFormatAttribivEXT         );              
 WGL_GetFuncEXT(PFNWGLGETPIXELFORMATATTRIBFVEXTPROC          ,wglGetPixelFormatAttribfvEXT         );              
 WGL_GetFuncEXT(PFNWGLCHOOSEPIXELFORMATEXTPROC               ,wglChoosePixelFormatEXT              );              
#endif /* WGL_EXT_pixel_format */                                   
                                                                    
                                                                    
#ifdef WGL_EXT_swap_control    
 fprintf(LogWGlGetFunctions_py, "\nWGL_EXT_swap_control\n");                                    
 WGL_GetFuncEXT(PFNWGLSWAPINTERVALEXTPROC                    ,wglSwapIntervalEXT                   );              
 WGL_GetFuncEXT(PFNWGLGETSWAPINTERVALEXTPROC                 ,wglGetSwapIntervalEXT                );              
#endif /* WGL_EXT_swap_control */                                   
                                                                    
                                                                    
#ifdef WGL_I3D_digital_video_control  
 fprintf(LogWGlGetFunctions_py, "\nWGL_I3D_digital_video_control\n");                             
 WGL_GetFuncEXT(PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC       ,wglGetDigitalVideoParametersI3D      );              
 WGL_GetFuncEXT(PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC       ,wglSetDigitalVideoParametersI3D      );              
#endif /* WGL_I3D_digital_video_control */                          
                                                                    
#ifdef WGL_I3D_gamma                                               
 fprintf(LogWGlGetFunctions_py, "\nWGL_I3D_gamma\n");                                 
 WGL_GetFuncEXT(PFNWGLGETGAMMATABLEPARAMETERSI3DPROC         ,wglGetGammaTableParametersI3D        );              
 WGL_GetFuncEXT(PFNWGLSETGAMMATABLEPARAMETERSI3DPROC         ,wglSetGammaTableParametersI3D        );              
 WGL_GetFuncEXT(PFNWGLGETGAMMATABLEI3DPROC                   ,wglGetGammaTableI3D                  );              
 WGL_GetFuncEXT(PFNWGLSETGAMMATABLEI3DPROC                   ,wglSetGammaTableI3D                  );              
#endif /* WGL_I3D_gamma */                                          
                                                                    
#ifdef WGL_I3D_genlock            
 fprintf(LogWGlGetFunctions_py, "\nWGL_I3D_genlock\n");                                 
 WGL_GetFuncEXT(PFNWGLENABLEGENLOCKI3DPROC                   ,wglEnableGenlockI3D                  );              
 WGL_GetFuncEXT(PFNWGLDISABLEGENLOCKI3DPROC                  ,wglDisableGenlockI3D                 );              
 WGL_GetFuncEXT(PFNWGLISENABLEDGENLOCKI3DPROC                ,wglIsEnabledGenlockI3D               );              
 WGL_GetFuncEXT(PFNWGLGENLOCKSOURCEI3DPROC                   ,wglGenlockSourceI3D                  );              
 WGL_GetFuncEXT(PFNWGLGETGENLOCKSOURCEI3DPROC                ,wglGetGenlockSourceI3D               );              
 WGL_GetFuncEXT(PFNWGLGENLOCKSOURCEEDGEI3DPROC               ,wglGenlockSourceEdgeI3D              );              
 WGL_GetFuncEXT(PFNWGLGETGENLOCKSOURCEEDGEI3DPROC            ,wglGetGenlockSourceEdgeI3D           );              
 WGL_GetFuncEXT(PFNWGLGENLOCKSAMPLERATEI3DPROC               ,wglGenlockSampleRateI3D              );              
 WGL_GetFuncEXT(PFNWGLGETGENLOCKSAMPLERATEI3DPROC            ,wglGetGenlockSampleRateI3D           );              
 WGL_GetFuncEXT(PFNWGLGENLOCKSOURCEDELAYI3DPROC              ,wglGenlockSourceDelayI3D             );              
 WGL_GetFuncEXT(PFNWGLGETGENLOCKSOURCEDELAYI3DPROC           ,wglGetGenlockSourceDelayI3D          );              
 WGL_GetFuncEXT(PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC      ,wglQueryGenlockMaxSourceDelayI3D     );              
#endif /* WGL_I3D_genlock */                                        
                                                                    
#ifdef WGL_I3D_image_buffer     
 fprintf(LogWGlGetFunctions_py, "\nWGL_I3D_image_buffer\n");                                   
 WGL_GetFuncEXT(PFNWGLCREATEIMAGEBUFFERI3DPROC               ,wglCreateImageBufferI3D              );              
 WGL_GetFuncEXT(PFNWGLDESTROYIMAGEBUFFERI3DPROC              ,wglDestroyImageBufferI3D             );              
 WGL_GetFuncEXT(PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC      ,wglAssociateImageBufferEventsI3D     );              
 WGL_GetFuncEXT(PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC        ,wglReleaseImageBufferEventsI3D       );              
#endif /* WGL_I3D_image_buffer */                                   
                                                                    
#ifdef WGL_I3D_swap_frame_lock    
 fprintf(LogWGlGetFunctions_py, "\nWGL_I3D_swap_frame_lock\n");                                 
 WGL_GetFuncEXT(PFNWGLENABLEFRAMELOCKI3DPROC                 ,wglEnableFrameLockI3D                );              
 WGL_GetFuncEXT(PFNWGLDISABLEFRAMELOCKI3DPROC                ,wglDisableFrameLockI3D               );              
 WGL_GetFuncEXT(PFNWGLISENABLEDFRAMELOCKI3DPROC              ,wglIsEnabledFrameLockI3D             );              
 WGL_GetFuncEXT(PFNWGLQUERYFRAMELOCKMASTERI3DPROC            ,wglQueryFrameLockMasterI3D           );              
#endif /* WGL_I3D_swap_frame_lock */                                
                                                                    
#ifdef WGL_I3D_swap_frame_usage   
 fprintf(LogWGlGetFunctions_py, "\nWGL_I3D_swap_frame_usage\n");                                 
 WGL_GetFuncEXT(PFNWGLGETFRAMEUSAGEI3DPROC                   ,wglGetFrameUsageI3D                  );              
 WGL_GetFuncEXT(PFNWGLBEGINFRAMETRACKINGI3DPROC              ,wglBeginFrameTrackingI3D             );              
 WGL_GetFuncEXT(PFNWGLENDFRAMETRACKINGI3DPROC                ,wglEndFrameTrackingI3D               );              
 WGL_GetFuncEXT(PFNWGLQUERYFRAMETRACKINGI3DPROC              ,wglQueryFrameTrackingI3D             );              
#endif /* WGL_I3D_swap_frame_usage */                               
                                                                    
#ifdef WGL_NV_DX_interop       
 fprintf(LogWGlGetFunctions_py, "\nWGL_NV_DX_interop\n");                                    
 WGL_GetFuncEXT(PFNWGLDXSETRESOURCESHAREHANDLENVPROC         ,wglDXSetResourceShareHandleNV        );              
 WGL_GetFuncEXT(PFNWGLDXOPENDEVICENVPROC                     ,wglDXOpenDeviceNV                    );              
 WGL_GetFuncEXT(PFNWGLDXCLOSEDEVICENVPROC                    ,wglDXCloseDeviceNV                   );              
 WGL_GetFuncEXT(PFNWGLDXREGISTEROBJECTNVPROC                 ,wglDXRegisterObjectNV                );              
 WGL_GetFuncEXT(PFNWGLDXUNREGISTEROBJECTNVPROC               ,wglDXUnregisterObjectNV              );              
 WGL_GetFuncEXT(PFNWGLDXOBJECTACCESSNVPROC                   ,wglDXObjectAccessNV                  );              
 WGL_GetFuncEXT(PFNWGLDXLOCKOBJECTSNVPROC                    ,wglDXLockObjectsNV                   );              
 WGL_GetFuncEXT(PFNWGLDXUNLOCKOBJECTSNVPROC                  ,wglDXUnlockObjectsNV                 );              
#endif /* WGL_NV_DX_interop */                                      
                                                                    
                                                                    
#ifdef WGL_NV_copy_image       
 fprintf(LogWGlGetFunctions_py, "\nWGL_NV_copy_image\n");                                    
 WGL_GetFuncEXT(PFNWGLCOPYIMAGESUBDATANVPROC                 ,wglCopyImageSubDataNV                );              
#endif /* WGL_NV_copy_image */                                      
                                                                    
#ifdef WGL_NV_delay_before_swap  
 fprintf(LogWGlGetFunctions_py, "\nWGL_NV_delay_before_swap\n");                                  
 WGL_GetFuncEXT(PFNWGLDELAYBEFORESWAPNVPROC                  ,wglDelayBeforeSwapNV                 );              
#endif /* WGL_NV_delay_before_swap */                               
                                                                    
                                                                    
#ifdef WGL_NV_gpu_affinity      
 fprintf(LogWGlGetFunctions_py, "\nWGL_NV_gpu_affinity\n");                                   
 WGL_GetFuncEXT(PFNWGLENUMGPUSNVPROC                         ,wglEnumGpusNV                        );              
 WGL_GetFuncEXT(PFNWGLENUMGPUDEVICESNVPROC                   ,wglEnumGpuDevicesNV                  );              
 WGL_GetFuncEXT(PFNWGLCREATEAFFINITYDCNVPROC                 ,wglCreateAffinityDCNV                );              
 WGL_GetFuncEXT(PFNWGLENUMGPUSFROMAFFINITYDCNVPROC           ,wglEnumGpusFromAffinityDCNV          );              
 WGL_GetFuncEXT(PFNWGLDELETEDCNVPROC                         ,wglDeleteDCNV                        );              
#endif /* WGL_NV_gpu_affinity */                                    
                                                                    
                                                                    
#ifdef WGL_NV_present_video       
 fprintf(LogWGlGetFunctions_py, "\nWGL_NV_present_video\n");                                 
 WGL_GetFuncEXT(PFNWGLENUMERATEVIDEODEVICESNVPROC            ,wglEnumerateVideoDevicesNV           );              
 WGL_GetFuncEXT(PFNWGLBINDVIDEODEVICENVPROC                  ,wglBindVideoDeviceNV                 );              
 WGL_GetFuncEXT(PFNWGLQUERYCURRENTCONTEXTNVPROC              ,wglQueryCurrentContextNV             );              
#endif /* WGL_NV_present_video */                                   
                                                                    
                                                                    
#ifdef WGL_NV_swap_group       
 fprintf(LogWGlGetFunctions_py, "\nWGL_NV_swap_group\n");                                    
 WGL_GetFuncEXT(PFNWGLJOINSWAPGROUPNVPROC                    ,wglJoinSwapGroupNV                   );              
 WGL_GetFuncEXT(PFNWGLBINDSWAPBARRIERNVPROC                  ,wglBindSwapBarrierNV                 );              
 WGL_GetFuncEXT(PFNWGLQUERYSWAPGROUPNVPROC                   ,wglQuerySwapGroupNV                  );              
 WGL_GetFuncEXT(PFNWGLQUERYMAXSWAPGROUPSNVPROC               ,wglQueryMaxSwapGroupsNV              );              
 WGL_GetFuncEXT(PFNWGLQUERYFRAMECOUNTNVPROC                  ,wglQueryFrameCountNV                 );              
 WGL_GetFuncEXT(PFNWGLRESETFRAMECOUNTNVPROC                  ,wglResetFrameCountNV                 );              
#endif /* WGL_NV_swap_group */                                      
                                                                    
#ifdef WGL_NV_vertex_array_range   
 fprintf(LogWGlGetFunctions_py, "\nWGL_NV_vertex_array_range\n");                                
 WGL_GetFuncEXT(PFNWGLALLOCATEMEMORYNVPROC                   ,wglAllocateMemoryNV                  );              
 WGL_GetFuncEXT(PFNWGLFREEMEMORYNVPROC                       ,wglFreeMemoryNV                      );              
#endif /* WGL_NV_vertex_array_range */                              
                                                                    
#ifdef WGL_NV_video_capture     
 fprintf(LogWGlGetFunctions_py, "\nWGL_NV_video_capture\n");                                   
 WGL_GetFuncEXT(PFNWGLBINDVIDEOCAPTUREDEVICENVPROC           ,wglBindVideoCaptureDeviceNV          );              
 WGL_GetFuncEXT(PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC     ,wglEnumerateVideoCaptureDevicesNV    );              
 WGL_GetFuncEXT(PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC           ,wglLockVideoCaptureDeviceNV          );              
 WGL_GetFuncEXT(PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC          ,wglQueryVideoCaptureDeviceNV         );              
 WGL_GetFuncEXT(PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC        ,wglReleaseVideoCaptureDeviceNV       );              
#endif /* WGL_NV_video_capture */                                   
                                                                    
#ifdef WGL_NV_video_output       
 fprintf(LogWGlGetFunctions_py, "\nWGL_NV_video_output\n");                                  
 WGL_GetFuncEXT(PFNWGLGETVIDEODEVICENVPROC                   ,wglGetVideoDeviceNV                  );              
 WGL_GetFuncEXT(PFNWGLRELEASEVIDEODEVICENVPROC               ,wglReleaseVideoDeviceNV              );              
 WGL_GetFuncEXT(PFNWGLBINDVIDEOIMAGENVPROC                   ,wglBindVideoImageNV                  );              
 WGL_GetFuncEXT(PFNWGLRELEASEVIDEOIMAGENVPROC                ,wglReleaseVideoImageNV               );              
 WGL_GetFuncEXT(PFNWGLSENDPBUFFERTOVIDEONVPROC               ,wglSendPbufferToVideoNV              );              
 WGL_GetFuncEXT(PFNWGLGETVIDEOINFONVPROC                     ,wglGetVideoInfoNV                    );              
#endif /* WGL_NV_video_output */                                    
                                                                    
#ifdef WGL_OML_sync_control    
 fprintf(LogWGlGetFunctions_py, "\nWGL_OML_sync_control\n");                                    
 WGL_GetFuncEXT(PFNWGLGETSYNCVALUESOMLPROC                   ,wglGetSyncValuesOML                  );              
 WGL_GetFuncEXT(PFNWGLGETMSCRATEOMLPROC                      ,wglGetMscRateOML                     );              
 WGL_GetFuncEXT(PFNWGLSWAPBUFFERSMSCOMLPROC                  ,wglSwapBuffersMscOML                 );              
 WGL_GetFuncEXT(PFNWGLSWAPLAYERBUFFERSMSCOMLPROC             ,wglSwapLayerBuffersMscOML            );              
 WGL_GetFuncEXT(PFNWGLWAITFORMSCOMLPROC                      ,wglWaitForMscOML                     );              
 WGL_GetFuncEXT(PFNWGLWAITFORSBCOMLPROC                      ,wglWaitForSbcOML                     );              
#endif /* WGL_OML_sync_control */                                       
 fclose(LogWGlGetFunctions_py);
 return 0;
}

