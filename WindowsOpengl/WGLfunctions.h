#ifndef WGL_WGLEXT_PROTOTYPES
#ifndef WGLFunctions_h
#define	WGLFunctions_h 1

//#ifdef __cplusplus
//extern "C" {
//#endif

#ifndef WGL_WIN_MAIN
 #undef WGL_FUNC_DEF
 #undef WGL_FUNC_DEF2
 #define WGL_FUNC_DEF extern
 #define WGL_FUNC_DEF2
#else
 #undef WGL_FUNC_DEF
 #undef WGL_FUNC_DEF2
 #define WGL_FUNC_DEF
 #define WGL_FUNC_DEF2 = NULL
#endif



#ifdef WGL_VERSION_1_0
#ifndef _WINGDI_
 WGL_FUNC_DEF  PFNCHOOSEPIXELFORMATPROC                      ChoosePixelFormat                                              WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNDESCRIBEPIXELFORMATPROC                    DescribePixelFormat                                            WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNGETENHMETAFILEPIXELFORMATPROC              GetEnhMetaFilePixelFormat                                      WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNGETPIXELFORMATPROC                         GetPixelFormat                                                 WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNSETPIXELFORMATPROC                         SetPixelFormat                                                 WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNSWAPBUFFERSPROC                            SwapBuffers                                                    WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLCOPYCONTEXTPROC                         wglCopyContext                                                 WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLCREATECONTEXTPROC                       wglCreateContext                                               WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLCREATELAYERCONTEXTPROC                  wglCreateLayerContext                                          WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDELETECONTEXTPROC                       wglDeleteContext                                               WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDESCRIBELAYERPLANEPROC                  wglDescribeLayerPlane                                          WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETCURRENTCONTEXTPROC                   wglGetCurrentContext                                           WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETCURRENTDCPROC                        wglGetCurrentDC                                                WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETLAYERPALETTEENTRIESPROC              wglGetLayerPaletteEntries                                      WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETPROCADDRESSPROC                      wglGetProcAddress                                              WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLMAKECURRENTPROC                         wglMakeCurrent                                                 WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLREALIZELAYERPALETTEPROC                 wglRealizeLayerPalette                                         WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLSETLAYERPALETTEENTRIESPROC              wglSetLayerPaletteEntries                                      WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLSHARELISTSPROC                          wglShareLists                                                  WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLSWAPLAYERBUFFERSPROC                    wglSwapLayerBuffers                                            WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLUSEFONTBITMAPSPROC                      wglUseFontBitmaps                                              WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLUSEFONTBITMAPSAPROC                     wglUseFontBitmapsA                                             WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLUSEFONTBITMAPSWPROC                     wglUseFontBitmapsW                                             WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLUSEFONTOUTLINESPROC                     wglUseFontOutlines                                             WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLUSEFONTOUTLINESAPROC                    wglUseFontOutlinesA                                            WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLUSEFONTOUTLINESWPROC                    wglUseFontOutlinesW                                            WGL_FUNC_DEF2     ;              
#endif /* _WINGDI_ */     
#endif /* WGL_VERSION_1_0 */                                        
                                                                   
#ifdef WGL_ARB_buffer_region                                       
 WGL_FUNC_DEF  PFNWGLCREATEBUFFERREGIONARBPROC               wglCreateBufferRegionARB                                       WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDELETEBUFFERREGIONARBPROC               wglDeleteBufferRegionARB                                       WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLSAVEBUFFERREGIONARBPROC                 wglSaveBufferRegionARB                                         WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLRESTOREBUFFERREGIONARBPROC              wglRestoreBufferRegionARB                                      WGL_FUNC_DEF2     ;              
#endif /* WGL_ARB_buffer_region */                                  
                                                                    
                                                                    
#ifdef WGL_ARB_create_context                                      
 WGL_FUNC_DEF  PFNWGLCREATECONTEXTATTRIBSARBPROC             wglCreateContextAttribsARB                                     WGL_FUNC_DEF2     ;              
#endif /* WGL_ARB_create_context */                                 
                                                                    
                                                                    
#ifdef WGL_ARB_extensions_string                                   
 WGL_FUNC_DEF  PFNWGLGETEXTENSIONSSTRINGARBPROC              wglGetExtensionsStringARB                                      WGL_FUNC_DEF2     ;              
#endif /* WGL_ARB_extensions_string */                              
                                                                    
                                                                    
#ifdef WGL_ARB_make_current_read                                   
 WGL_FUNC_DEF  PFNWGLMAKECONTEXTCURRENTARBPROC               wglMakeContextCurrentARB                                       WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETCURRENTREADDCARBPROC                 wglGetCurrentReadDCARB                                         WGL_FUNC_DEF2     ;              
#endif /* WGL_ARB_make_current_read */                              
                                                                    
                                                                    
#ifdef WGL_ARB_pbuffer                                             
 WGL_FUNC_DEF  PFNWGLCREATEPBUFFERARBPROC                    wglCreatePbufferARB                                            WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETPBUFFERDCARBPROC                     wglGetPbufferDCARB                                             WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLRELEASEPBUFFERDCARBPROC                 wglReleasePbufferDCARB                                         WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDESTROYPBUFFERARBPROC                   wglDestroyPbufferARB                                           WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLQUERYPBUFFERARBPROC                     wglQueryPbufferARB                                             WGL_FUNC_DEF2     ;              
#endif /* WGL_ARB_pbuffer */                                        
                                                                    
#ifdef WGL_ARB_pixel_format                                        
 WGL_FUNC_DEF  PFNWGLGETPIXELFORMATATTRIBIVARBPROC           wglGetPixelFormatAttribivARB                                   WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETPIXELFORMATATTRIBFVARBPROC           wglGetPixelFormatAttribfvARB                                   WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLCHOOSEPIXELFORMATARBPROC                wglChoosePixelFormatARB                                        WGL_FUNC_DEF2     ;              
#endif /* WGL_ARB_pixel_format */                                   
                                                                    
                                                                    
#ifdef WGL_ARB_render_texture
 WGL_FUNC_DEF  PFNWGLBINDTEXIMAGEARBPROC                     wglBindTexImageARB                                             WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLRELEASETEXIMAGEARBPROC                  wglReleaseTexImageARB                                          WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLSETPBUFFERATTRIBARBPROC                 wglSetPbufferAttribARB                                         WGL_FUNC_DEF2     ;              
#endif /* WGL_ARB_render_texture */                                 
                                                                    
                                                                    
#ifdef WGL_3DL_stereo_control 
 WGL_FUNC_DEF  PFNWGLSETSTEREOEMITTERSTATE3DLPROC            wglSetStereoEmitterState3DL                                    WGL_FUNC_DEF2     ;              
#endif /* WGL_3DL_stereo_control */                                 
                                                                    
#ifdef WGL_AMD_gpu_association 
 WGL_FUNC_DEF  PFNWGLGETGPUIDSAMDPROC                        wglGetGPUIDsAMD                                                WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETGPUINFOAMDPROC                       wglGetGPUInfoAMD                                               WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETCONTEXTGPUIDAMDPROC                  wglGetContextGPUIDAMD                                          WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC          wglCreateAssociatedContextAMD                                  WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC   wglCreateAssociatedContextAttribsAMD                           WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC          wglDeleteAssociatedContextAMD                                  WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC     wglMakeAssociatedContextCurrentAMD                             WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC      wglGetCurrentAssociatedContextAMD                              WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC           wglBlitContextFramebufferAMD                                   WGL_FUNC_DEF2     ;              
#endif /* WGL_AMD_gpu_association */                                
                                                                    
                                                                    
#ifdef WGL_EXT_display_color_table
 WGL_FUNC_DEF  PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC          wglCreateDisplayColorTableEXT                                  WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLLOADDISPLAYCOLORTABLEEXTPROC            wglLoadDisplayColorTableEXT                                    WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLBINDDISPLAYCOLORTABLEEXTPROC            wglBindDisplayColorTableEXT                                    WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC         wglDestroyDisplayColorTableEXT                                 WGL_FUNC_DEF2     ;              
#endif /* WGL_EXT_display_color_table */                            
                                                                    
#ifdef WGL_EXT_extensions_string      
 WGL_FUNC_DEF  PFNWGLGETEXTENSIONSSTRINGEXTPROC              wglGetExtensionsStringEXT                                      WGL_FUNC_DEF2     ;              
#endif /* WGL_EXT_extensions_string */                              
                                                                    
                                                                    
#ifdef WGL_EXT_make_current_read  
 WGL_FUNC_DEF  PFNWGLMAKECONTEXTCURRENTEXTPROC               wglMakeContextCurrentEXT                                       WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETCURRENTREADDCEXTPROC                 wglGetCurrentReadDCEXT                                         WGL_FUNC_DEF2     ;              
#endif /* WGL_EXT_make_current_read */                              
                                                                    
                                                                    
#ifdef WGL_EXT_pbuffer          
 WGL_FUNC_DEF  PFNWGLCREATEPBUFFEREXTPROC                    wglCreatePbufferEXT                                            WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETPBUFFERDCEXTPROC                     wglGetPbufferDCEXT                                             WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLRELEASEPBUFFERDCEXTPROC                 wglReleasePbufferDCEXT                                         WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDESTROYPBUFFEREXTPROC                   wglDestroyPbufferEXT                                           WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLQUERYPBUFFEREXTPROC                     wglQueryPbufferEXT                                             WGL_FUNC_DEF2     ;              
#endif /* WGL_EXT_pbuffer */                                        
                                                                    
#ifdef WGL_EXT_pixel_format    
 WGL_FUNC_DEF  PFNWGLGETPIXELFORMATATTRIBIVEXTPROC           wglGetPixelFormatAttribivEXT                                   WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETPIXELFORMATATTRIBFVEXTPROC           wglGetPixelFormatAttribfvEXT                                   WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLCHOOSEPIXELFORMATEXTPROC                wglChoosePixelFormatEXT                                        WGL_FUNC_DEF2     ;              
#endif /* WGL_EXT_pixel_format */                                   
                                                                    
                                                                    
#ifdef WGL_EXT_swap_control    
 WGL_FUNC_DEF  PFNWGLSWAPINTERVALEXTPROC                     wglSwapIntervalEXT                                             WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETSWAPINTERVALEXTPROC                  wglGetSwapIntervalEXT                                          WGL_FUNC_DEF2     ;              
#endif /* WGL_EXT_swap_control */                                   
                                                                    
                                                                    
#ifdef WGL_I3D_digital_video_control  
 WGL_FUNC_DEF  PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC        wglGetDigitalVideoParametersI3D                                WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC        wglSetDigitalVideoParametersI3D                                WGL_FUNC_DEF2     ;              
#endif /* WGL_I3D_digital_video_control */                          
                                                                    
#ifdef WGL_I3D_gamma                                               
 WGL_FUNC_DEF  PFNWGLGETGAMMATABLEPARAMETERSI3DPROC          wglGetGammaTableParametersI3D                                  WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLSETGAMMATABLEPARAMETERSI3DPROC          wglSetGammaTableParametersI3D                                  WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETGAMMATABLEI3DPROC                    wglGetGammaTableI3D                                            WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLSETGAMMATABLEI3DPROC                    wglSetGammaTableI3D                                            WGL_FUNC_DEF2     ;              
#endif /* WGL_I3D_gamma */                                          
                                                                    
#ifdef WGL_I3D_genlock            
 WGL_FUNC_DEF  PFNWGLENABLEGENLOCKI3DPROC                    wglEnableGenlockI3D                                            WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDISABLEGENLOCKI3DPROC                   wglDisableGenlockI3D                                           WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLISENABLEDGENLOCKI3DPROC                 wglIsEnabledGenlockI3D                                         WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGENLOCKSOURCEI3DPROC                    wglGenlockSourceI3D                                            WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETGENLOCKSOURCEI3DPROC                 wglGetGenlockSourceI3D                                         WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGENLOCKSOURCEEDGEI3DPROC                wglGenlockSourceEdgeI3D                                        WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETGENLOCKSOURCEEDGEI3DPROC             wglGetGenlockSourceEdgeI3D                                     WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGENLOCKSAMPLERATEI3DPROC                wglGenlockSampleRateI3D                                        WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETGENLOCKSAMPLERATEI3DPROC             wglGetGenlockSampleRateI3D                                     WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGENLOCKSOURCEDELAYI3DPROC               wglGenlockSourceDelayI3D                                       WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETGENLOCKSOURCEDELAYI3DPROC            wglGetGenlockSourceDelayI3D                                    WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC       wglQueryGenlockMaxSourceDelayI3D                               WGL_FUNC_DEF2     ;              
#endif /* WGL_I3D_genlock */                                        
                                                                    
#ifdef WGL_I3D_image_buffer     
 WGL_FUNC_DEF  PFNWGLCREATEIMAGEBUFFERI3DPROC                wglCreateImageBufferI3D                                        WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDESTROYIMAGEBUFFERI3DPROC               wglDestroyImageBufferI3D                                       WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC       wglAssociateImageBufferEventsI3D                               WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC         wglReleaseImageBufferEventsI3D                                 WGL_FUNC_DEF2     ;              
#endif /* WGL_I3D_image_buffer */                                   
                                                                    
#ifdef WGL_I3D_swap_frame_lock    
 WGL_FUNC_DEF  PFNWGLENABLEFRAMELOCKI3DPROC                  wglEnableFrameLockI3D                                          WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDISABLEFRAMELOCKI3DPROC                 wglDisableFrameLockI3D                                         WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLISENABLEDFRAMELOCKI3DPROC               wglIsEnabledFrameLockI3D                                       WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLQUERYFRAMELOCKMASTERI3DPROC             wglQueryFrameLockMasterI3D                                     WGL_FUNC_DEF2     ;              
#endif /* WGL_I3D_swap_frame_lock */                                
                                                                    
#ifdef WGL_I3D_swap_frame_usage   
 WGL_FUNC_DEF  PFNWGLGETFRAMEUSAGEI3DPROC                    wglGetFrameUsageI3D                                            WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLBEGINFRAMETRACKINGI3DPROC               wglBeginFrameTrackingI3D                                       WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLENDFRAMETRACKINGI3DPROC                 wglEndFrameTrackingI3D                                         WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLQUERYFRAMETRACKINGI3DPROC               wglQueryFrameTrackingI3D                                       WGL_FUNC_DEF2     ;              
#endif /* WGL_I3D_swap_frame_usage */                               
                                                                    
#ifdef WGL_NV_DX_interop       
 WGL_FUNC_DEF  PFNWGLDXSETRESOURCESHAREHANDLENVPROC          wglDXSetResourceShareHandleNV                                  WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDXOPENDEVICENVPROC                      wglDXOpenDeviceNV                                              WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDXCLOSEDEVICENVPROC                     wglDXCloseDeviceNV                                             WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDXREGISTEROBJECTNVPROC                  wglDXRegisterObjectNV                                          WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDXUNREGISTEROBJECTNVPROC                wglDXUnregisterObjectNV                                        WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDXOBJECTACCESSNVPROC                    wglDXObjectAccessNV                                            WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDXLOCKOBJECTSNVPROC                     wglDXLockObjectsNV                                             WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDXUNLOCKOBJECTSNVPROC                   wglDXUnlockObjectsNV                                           WGL_FUNC_DEF2     ;              
#endif /* WGL_NV_DX_interop */                                      
                                                                    
                                                                    
#ifdef WGL_NV_copy_image       
 WGL_FUNC_DEF  PFNWGLCOPYIMAGESUBDATANVPROC                  wglCopyImageSubDataNV                                          WGL_FUNC_DEF2     ;              
#endif /* WGL_NV_copy_image */                                      
                                                                    
#ifdef WGL_NV_delay_before_swap  
 WGL_FUNC_DEF  PFNWGLDELAYBEFORESWAPNVPROC                   wglDelayBeforeSwapNV                                           WGL_FUNC_DEF2     ;              
#endif /* WGL_NV_delay_before_swap */                               
                                                                    
                                                                    
#ifdef WGL_NV_gpu_affinity      
 WGL_FUNC_DEF  PFNWGLENUMGPUSNVPROC                          wglEnumGpusNV                                                  WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLENUMGPUDEVICESNVPROC                    wglEnumGpuDevicesNV                                            WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLCREATEAFFINITYDCNVPROC                  wglCreateAffinityDCNV                                          WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLENUMGPUSFROMAFFINITYDCNVPROC            wglEnumGpusFromAffinityDCNV                                    WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLDELETEDCNVPROC                          wglDeleteDCNV                                                  WGL_FUNC_DEF2     ;              
#endif /* WGL_NV_gpu_affinity */                                    
                                                                    
                                                                    
#ifdef WGL_NV_present_video       
 WGL_FUNC_DEF  PFNWGLENUMERATEVIDEODEVICESNVPROC             wglEnumerateVideoDevicesNV                                     WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLBINDVIDEODEVICENVPROC                   wglBindVideoDeviceNV                                           WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLQUERYCURRENTCONTEXTNVPROC               wglQueryCurrentContextNV                                       WGL_FUNC_DEF2     ;              
#endif /* WGL_NV_present_video */                                   
                                                                    
                                                                    
#ifdef WGL_NV_swap_group       
 WGL_FUNC_DEF  PFNWGLJOINSWAPGROUPNVPROC                     wglJoinSwapGroupNV                                             WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLBINDSWAPBARRIERNVPROC                   wglBindSwapBarrierNV                                           WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLQUERYSWAPGROUPNVPROC                    wglQuerySwapGroupNV                                            WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLQUERYMAXSWAPGROUPSNVPROC                wglQueryMaxSwapGroupsNV                                        WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLQUERYFRAMECOUNTNVPROC                   wglQueryFrameCountNV                                           WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLRESETFRAMECOUNTNVPROC                   wglResetFrameCountNV                                           WGL_FUNC_DEF2     ;              
#endif /* WGL_NV_swap_group */                                      
                                                                    
#ifdef WGL_NV_vertex_array_range   
 WGL_FUNC_DEF  PFNWGLALLOCATEMEMORYNVPROC                    wglAllocateMemoryNV                                            WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLFREEMEMORYNVPROC                        wglFreeMemoryNV                                                WGL_FUNC_DEF2     ;              
#endif /* WGL_NV_vertex_array_range */                              
                                                                    
#ifdef WGL_NV_video_capture     
 WGL_FUNC_DEF  PFNWGLBINDVIDEOCAPTUREDEVICENVPROC            wglBindVideoCaptureDeviceNV                                    WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC      wglEnumerateVideoCaptureDevicesNV                              WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC            wglLockVideoCaptureDeviceNV                                    WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC           wglQueryVideoCaptureDeviceNV                                   WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC         wglReleaseVideoCaptureDeviceNV                                 WGL_FUNC_DEF2     ;              
#endif /* WGL_NV_video_capture */                                   
                                                                    
#ifdef WGL_NV_video_output       
 WGL_FUNC_DEF  PFNWGLGETVIDEODEVICENVPROC                    wglGetVideoDeviceNV                                            WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLRELEASEVIDEODEVICENVPROC                wglReleaseVideoDeviceNV                                        WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLBINDVIDEOIMAGENVPROC                    wglBindVideoImageNV                                            WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLRELEASEVIDEOIMAGENVPROC                 wglReleaseVideoImageNV                                         WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLSENDPBUFFERTOVIDEONVPROC                wglSendPbufferToVideoNV                                        WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETVIDEOINFONVPROC                      wglGetVideoInfoNV                                              WGL_FUNC_DEF2     ;              
#endif /* WGL_NV_video_output */                                    
                                                                    
#ifdef WGL_OML_sync_control    
 WGL_FUNC_DEF  PFNWGLGETSYNCVALUESOMLPROC                    wglGetSyncValuesOML                                            WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLGETMSCRATEOMLPROC                       wglGetMscRateOML                                               WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLSWAPBUFFERSMSCOMLPROC                   wglSwapBuffersMscOML                                           WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLSWAPLAYERBUFFERSMSCOMLPROC              wglSwapLayerBuffersMscOML                                      WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLWAITFORMSCOMLPROC                       wglWaitForMscOML                                               WGL_FUNC_DEF2     ;              
 WGL_FUNC_DEF  PFNWGLWAITFORSBCOMLPROC                       wglWaitForSbcOML                                               WGL_FUNC_DEF2     ;              
#endif /* WGL_OML_sync_control */                                       

#ifdef __cplusplus
//}
#endif

#endif /* WGLFunctions_h */                                       
#endif /* WGL_WGLEXT_PROTOTYPES */       



                                
