#ifndef GL_GLEXT_PROTOTYPES
#ifndef GLFunctions_h
#define	GLFunctions_h 1

// #ifdef __cplusplus
// extern "C" {
// #endif

#ifndef GL_WIN_MAIN
 #undef GL_FUNC_DEF
 #undef GL_FUNC_DEF2

 #define GL_FUNC_DEF extern
 #define GL_FUNC_DEF2
#else
 #undef GL_FUNC_DEF
 #undef GL_FUNC_DEF2

 #define GL_FUNC_DEF
 #define GL_FUNC_DEF2 = NULL
#endif



#ifdef GL_VERSION_1_0
#ifndef __gl_h_
#ifndef __GL_H__
GL_FUNC_DEF  PFNGLCULLFACEPROC                                 glCullFace                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRONTFACEPROC                                glFrontFace                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLHINTPROC                                     glHint                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLINEWIDTHPROC                                glLineWidth                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOINTSIZEPROC                                glPointSize                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOLYGONMODEPROC                              glPolygonMode                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSCISSORPROC                                  glScissor                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXPARAMETERFPROC                            glTexParameterf                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXPARAMETERFVPROC                           glTexParameterfv                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXPARAMETERIPROC                            glTexParameteri                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXPARAMETERIVPROC                           glTexParameteriv                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXIMAGE1DPROC                               glTexImage1D                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXIMAGE2DPROC                               glTexImage2D                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWBUFFERPROC                               glDrawBuffer                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARPROC                                    glClear                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARCOLORPROC                               glClearColor                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARSTENCILPROC                             glClearStencil                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARDEPTHPROC                               glClearDepth                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTENCILMASKPROC                              glStencilMask                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLORMASKPROC                                glColorMask                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEPTHMASKPROC                                glDepthMask                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDISABLEPROC                                  glDisable                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENABLEPROC                                   glEnable                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFINISHPROC                                   glFinish                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFLUSHPROC                                    glFlush                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBLENDFUNCPROC                                glBlendFunc                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLOGICOPPROC                                  glLogicOp                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTENCILFUNCPROC                              glStencilFunc                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTENCILOPPROC                                glStencilOp                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEPTHFUNCPROC                                glDepthFunc                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPIXELSTOREFPROC                              glPixelStoref                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPIXELSTOREIPROC                              glPixelStorei                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREADBUFFERPROC                               glReadBuffer                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREADPIXELSPROC                               glReadPixels                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETBOOLEANVPROC                              glGetBooleanv                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETDOUBLEVPROC                               glGetDoublev                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETERRORPROC                                 glGetError                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFLOATVPROC                                glGetFloatv                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETINTEGERVPROC                              glGetIntegerv                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSTRINGPROC                                glGetString                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXIMAGEPROC                              glGetTexImage                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXPARAMETERFVPROC                        glGetTexParameterfv                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXPARAMETERIVPROC                        glGetTexParameteriv                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXLEVELPARAMETERFVPROC                   glGetTexLevelParameterfv                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXLEVELPARAMETERIVPROC                   glGetTexLevelParameteriv                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISENABLEDPROC                                glIsEnabled                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEPTHRANGEPROC                               glDepthRange                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVIEWPORTPROC                                 glViewport                                           GL_FUNC_DEF2     ;
#endif /* __GL_H__ GL_VERSION_1_0 */
#endif /* __gl_h_  GL_VERSION_1_0 */
#endif /* GL_VERSION_1_0 */

#ifdef GL_VERSION_1_1
#ifndef __gl_h_
#ifndef __GL_H__
GL_FUNC_DEF  PFNGLDRAWARRAYSPROC                         glDrawArrays                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWELEMENTSPROC                       glDrawElements                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPOINTERVPROC                        glGetPointerv                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOLYGONOFFSETPROC                      glPolygonOffset                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYTEXIMAGE1DPROC                     glCopyTexImage1D                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYTEXIMAGE2DPROC                     glCopyTexImage2D                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYTEXSUBIMAGE1DPROC                  glCopyTexSubImage1D                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYTEXSUBIMAGE2DPROC                  glCopyTexSubImage2D                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXSUBIMAGE1DPROC                      glTexSubImage1D                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXSUBIMAGE2DPROC                      glTexSubImage2D                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDTEXTUREPROC                        glBindTexture                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETETEXTURESPROC                     glDeleteTextures                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENTEXTURESPROC                        glGenTextures                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISTEXTUREPROC                          glIsTexture                                            GL_FUNC_DEF2     ;
#endif /* __GL_H__ GL_VERSION_1_1 */
#endif /* __gl_h_ GL_VERSION_1_1 */
#endif /* GL_VERSION_1_1 */

#ifdef GL_VERSION_1_2
GL_FUNC_DEF  PFNGLDRAWRANGEELEMENTSPROC                   glDrawRangeElements                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXIMAGE3DPROC                          glTexImage3D                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXSUBIMAGE3DPROC                       glTexSubImage3D                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYTEXSUBIMAGE3DPROC                   glCopyTexSubImage3D                               GL_FUNC_DEF2     ;
#endif /* GL_VERSION_1_2 */

#ifdef GL_VERSION_1_3
GL_FUNC_DEF  PFNGLACTIVETEXTUREPROC                                   glActiveTexture                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSAMPLECOVERAGEPROC                                  glSampleCoverage                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXIMAGE3DPROC                            glCompressedTexImage3D                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXIMAGE2DPROC                            glCompressedTexImage2D                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXIMAGE1DPROC                            glCompressedTexImage1D                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC                         glCompressedTexSubImage3D                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC                         glCompressedTexSubImage2D                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC                         glCompressedTexSubImage1D                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOMPRESSEDTEXIMAGEPROC                           glGetCompressedTexImage                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLIENTACTIVETEXTUREPROC                             glClientActiveTexture                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1DPROC                                 glMultiTexCoord1d                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1DVPROC                                glMultiTexCoord1dv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1FPROC                                 glMultiTexCoord1f                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1FVPROC                                glMultiTexCoord1fv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1IPROC                                 glMultiTexCoord1i                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1IVPROC                                glMultiTexCoord1iv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1SPROC                                 glMultiTexCoord1s                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1SVPROC                                glMultiTexCoord1sv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2DPROC                                 glMultiTexCoord2d                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2DVPROC                                glMultiTexCoord2dv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2FPROC                                 glMultiTexCoord2f                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2FVPROC                                glMultiTexCoord2fv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2IPROC                                 glMultiTexCoord2i                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2IVPROC                                glMultiTexCoord2iv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2SPROC                                 glMultiTexCoord2s                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2SVPROC                                glMultiTexCoord2sv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3DPROC                                 glMultiTexCoord3d                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3DVPROC                                glMultiTexCoord3dv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3FPROC                                 glMultiTexCoord3f                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3FVPROC                                glMultiTexCoord3fv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3IPROC                                 glMultiTexCoord3i                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3IVPROC                                glMultiTexCoord3iv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3SPROC                                 glMultiTexCoord3s                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3SVPROC                                glMultiTexCoord3sv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4DPROC                                 glMultiTexCoord4d                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4DVPROC                                glMultiTexCoord4dv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4FPROC                                 glMultiTexCoord4f                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4FVPROC                                glMultiTexCoord4fv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4IPROC                                 glMultiTexCoord4i                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4IVPROC                                glMultiTexCoord4iv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4SPROC                                 glMultiTexCoord4s                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4SVPROC                                glMultiTexCoord4sv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLOADTRANSPOSEMATRIXFPROC                            glLoadTransposeMatrixf                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLOADTRANSPOSEMATRIXDPROC                            glLoadTransposeMatrixd                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTTRANSPOSEMATRIXFPROC                            glMultTransposeMatrixf                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTTRANSPOSEMATRIXDPROC                            glMultTransposeMatrixd                                           GL_FUNC_DEF2     ;
#endif /* GL_VERSION_1_3 */

#ifdef GL_VERSION_1_4
GL_FUNC_DEF  PFNGLBLENDFUNCSEPARATEPROC                           glBlendFuncSeparate                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTIDRAWARRAYSPROC                             glMultiDrawArrays                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTIDRAWELEMENTSPROC                           glMultiDrawElements                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOINTPARAMETERFPROC                             glPointParameterf                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOINTPARAMETERFVPROC                            glPointParameterfv                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOINTPARAMETERIPROC                             glPointParameteri                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOINTPARAMETERIVPROC                            glPointParameteriv                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFOGCOORDFPROC                                   glFogCoordf                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFOGCOORDFVPROC                                  glFogCoordfv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFOGCOORDDPROC                                   glFogCoordd                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFOGCOORDDVPROC                                  glFogCoorddv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFOGCOORDPOINTERPROC                             glFogCoordPointer                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3BPROC                            glSecondaryColor3b                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3BVPROC                           glSecondaryColor3bv                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3DPROC                            glSecondaryColor3d                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3DVPROC                           glSecondaryColor3dv                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3FPROC                            glSecondaryColor3f                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3FVPROC                           glSecondaryColor3fv                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3IPROC                            glSecondaryColor3i                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3IVPROC                           glSecondaryColor3iv                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3SPROC                            glSecondaryColor3s                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3SVPROC                           glSecondaryColor3sv                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3UBPROC                           glSecondaryColor3ub                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3UBVPROC                          glSecondaryColor3ubv                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3UIPROC                           glSecondaryColor3ui                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3UIVPROC                          glSecondaryColor3uiv                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3USPROC                           glSecondaryColor3us                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3USVPROC                          glSecondaryColor3usv                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLORPOINTERPROC                       glSecondaryColorPointer                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2DPROC                                 glWindowPos2d                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2DVPROC                                glWindowPos2dv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2FPROC                                 glWindowPos2f                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2FVPROC                                glWindowPos2fv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2IPROC                                 glWindowPos2i                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2IVPROC                                glWindowPos2iv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2SPROC                                 glWindowPos2s                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2SVPROC                                glWindowPos2sv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3DPROC                                 glWindowPos3d                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3DVPROC                                glWindowPos3dv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3FPROC                                 glWindowPos3f                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3FVPROC                                glWindowPos3fv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3IPROC                                 glWindowPos3i                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3IVPROC                                glWindowPos3iv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3SPROC                                 glWindowPos3s                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3SVPROC                                glWindowPos3sv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBLENDCOLORPROC                                  glBlendColor                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBLENDEQUATIONPROC                               glBlendEquation                                              GL_FUNC_DEF2     ;
#endif /* GL_VERSION_1_4 */

#ifdef GL_VERSION_1_5
GL_FUNC_DEF  PFNGLGENQUERIESPROC                                glGenQueries                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEQUERIESPROC                             glDeleteQueries                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISQUERYPROC                                   glIsQuery                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBEGINQUERYPROC                                glBeginQuery                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENDQUERYPROC                                  glEndQuery                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETQUERYIVPROC                                glGetQueryiv                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETQUERYOBJECTIVPROC                          glGetQueryObjectiv                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETQUERYOBJECTUIVPROC                         glGetQueryObjectuiv                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDBUFFERPROC                                glBindBuffer                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEBUFFERSPROC                             glDeleteBuffers                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENBUFFERSPROC                                glGenBuffers                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISBUFFERPROC                                  glIsBuffer                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBUFFERDATAPROC                                glBufferData                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBUFFERSUBDATAPROC                             glBufferSubData                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETBUFFERSUBDATAPROC                          glGetBufferSubData                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAPBUFFERPROC                                 glMapBuffer                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNMAPBUFFERPROC                               glUnmapBuffer                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETBUFFERPARAMETERIVPROC                      glGetBufferParameteriv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETBUFFERPOINTERVPROC                         glGetBufferPointerv                                                  GL_FUNC_DEF2     ;
#endif /* GL_VERSION_1_5 */

#ifdef GL_VERSION_2_0
GL_FUNC_DEF  PFNGLBLENDEQUATIONSEPARATEPROC                                   glBlendEquationSeparate                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWBUFFERSPROC                                             glDrawBuffers                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTENCILOPSEPARATEPROC                                       glStencilOpSeparate                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTENCILFUNCSEPARATEPROC                                     glStencilFuncSeparate                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTENCILMASKSEPARATEPROC                                     glStencilMaskSeparate                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLATTACHSHADERPROC                                            glAttachShader                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDATTRIBLOCATIONPROC                                      glBindAttribLocation                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPILESHADERPROC                                           glCompileShader                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATEPROGRAMPROC                                           glCreateProgram                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATESHADERPROC                                            glCreateShader                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEPROGRAMPROC                                           glDeleteProgram                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETESHADERPROC                                            glDeleteShader                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDETACHSHADERPROC                                            glDetachShader                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDISABLEVERTEXATTRIBARRAYPROC                                glDisableVertexAttribArray                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENABLEVERTEXATTRIBARRAYPROC                                 glEnableVertexAttribArray                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETACTIVEATTRIBPROC                                         glGetActiveAttrib                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETACTIVEUNIFORMPROC                                        glGetActiveUniform                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETATTACHEDSHADERSPROC                                      glGetAttachedShaders                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETATTRIBLOCATIONPROC                                       glGetAttribLocation                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMIVPROC                                            glGetProgramiv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMINFOLOGPROC                                       glGetProgramInfoLog                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSHADERIVPROC                                             glGetShaderiv                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSHADERINFOLOGPROC                                        glGetShaderInfoLog                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSHADERSOURCEPROC                                         glGetShaderSource                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNIFORMLOCATIONPROC                                      glGetUniformLocation                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNIFORMFVPROC                                            glGetUniformfv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNIFORMIVPROC                                            glGetUniformiv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBDVPROC                                       glGetVertexAttribdv                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBFVPROC                                       glGetVertexAttribfv                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBIVPROC                                       glGetVertexAttribiv                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBPOINTERVPROC                                 glGetVertexAttribPointerv                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISPROGRAMPROC                                               glIsProgram                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISSHADERPROC                                                glIsShader                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLINKPROGRAMPROC                                             glLinkProgram                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSHADERSOURCEPROC                                            glShaderSource                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUSEPROGRAMPROC                                              glUseProgram                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1FPROC                                               glUniform1f                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2FPROC                                               glUniform2f                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3FPROC                                               glUniform3f                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4FPROC                                               glUniform4f                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1IPROC                                               glUniform1i                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2IPROC                                               glUniform2i                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3IPROC                                               glUniform3i                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4IPROC                                               glUniform4i                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1FVPROC                                              glUniform1fv                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2FVPROC                                              glUniform2fv                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3FVPROC                                              glUniform3fv                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4FVPROC                                              glUniform4fv                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1IVPROC                                              glUniform1iv                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2IVPROC                                              glUniform2iv                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3IVPROC                                              glUniform3iv                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4IVPROC                                              glUniform4iv                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX2FVPROC                                        glUniformMatrix2fv                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX3FVPROC                                        glUniformMatrix3fv                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX4FVPROC                                        glUniformMatrix4fv                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVALIDATEPROGRAMPROC                                         glValidateProgram                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1DPROC                                          glVertexAttrib1d                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1DVPROC                                         glVertexAttrib1dv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1FPROC                                          glVertexAttrib1f                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1FVPROC                                         glVertexAttrib1fv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1SPROC                                          glVertexAttrib1s                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1SVPROC                                         glVertexAttrib1sv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2DPROC                                          glVertexAttrib2d                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2DVPROC                                         glVertexAttrib2dv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2FPROC                                          glVertexAttrib2f                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2FVPROC                                         glVertexAttrib2fv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2SPROC                                          glVertexAttrib2s                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2SVPROC                                         glVertexAttrib2sv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3DPROC                                          glVertexAttrib3d                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3DVPROC                                         glVertexAttrib3dv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3FPROC                                          glVertexAttrib3f                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3FVPROC                                         glVertexAttrib3fv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3SPROC                                          glVertexAttrib3s                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3SVPROC                                         glVertexAttrib3sv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4NBVPROC                                        glVertexAttrib4Nbv                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4NIVPROC                                        glVertexAttrib4Niv                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4NSVPROC                                        glVertexAttrib4Nsv                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4NUBPROC                                        glVertexAttrib4Nub                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4NUBVPROC                                       glVertexAttrib4Nubv                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4NUIVPROC                                       glVertexAttrib4Nuiv                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4NUSVPROC                                       glVertexAttrib4Nusv                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4BVPROC                                         glVertexAttrib4bv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4DPROC                                          glVertexAttrib4d                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4DVPROC                                         glVertexAttrib4dv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4FPROC                                          glVertexAttrib4f                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4FVPROC                                         glVertexAttrib4fv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4IVPROC                                         glVertexAttrib4iv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4SPROC                                          glVertexAttrib4s                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4SVPROC                                         glVertexAttrib4sv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4UBVPROC                                        glVertexAttrib4ubv                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4UIVPROC                                        glVertexAttrib4uiv                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4USVPROC                                        glVertexAttrib4usv                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBPOINTERPROC                                     glVertexAttribPointer                                          GL_FUNC_DEF2     ;
#endif /* GL_VERSION_2_0 */

#ifdef GL_VERSION_2_1
GL_FUNC_DEF  PFNGLUNIFORMMATRIX2X3FVPROC                     glUniformMatrix2x3fv                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX3X2FVPROC                     glUniformMatrix3x2fv                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX2X4FVPROC                     glUniformMatrix2x4fv                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX4X2FVPROC                     glUniformMatrix4x2fv                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX3X4FVPROC                     glUniformMatrix3x4fv                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX4X3FVPROC                     glUniformMatrix4x3fv                                 GL_FUNC_DEF2     ;
#endif /* GL_VERSION_2_1 */

#ifdef GL_VERSION_3_0
GL_FUNC_DEF  PFNGLCOLORMASKIPROC                                             glColorMaski                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETBOOLEANI_VPROC                                          glGetBooleani_v                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETINTEGERI_VPROC                                          glGetIntegeri_v                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENABLEIPROC                                                glEnablei                                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDISABLEIPROC                                               glDisablei                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISENABLEDIPROC                                             glIsEnabledi                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBEGINTRANSFORMFEEDBACKPROC                                 glBeginTransformFeedback                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENDTRANSFORMFEEDBACKPROC                                   glEndTransformFeedback                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDBUFFERRANGEPROC                                        glBindBufferRange                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDBUFFERBASEPROC                                         glBindBufferBase                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTRANSFORMFEEDBACKVARYINGSPROC                              glTransformFeedbackVaryings                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTRANSFORMFEEDBACKVARYINGPROC                            glGetTransformFeedbackVarying                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLAMPCOLORPROC                                             glClampColor                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBEGINCONDITIONALRENDERPROC                                 glBeginConditionalRender                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENDCONDITIONALRENDERPROC                                   glEndConditionalRender                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBIPOINTERPROC                                   glVertexAttribIPointer                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBIIVPROC                                     glGetVertexAttribIiv                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBIUIVPROC                                    glGetVertexAttribIuiv                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI1IPROC                                        glVertexAttribI1i                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI2IPROC                                        glVertexAttribI2i                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI3IPROC                                        glVertexAttribI3i                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI4IPROC                                        glVertexAttribI4i                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI1UIPROC                                       glVertexAttribI1ui                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI2UIPROC                                       glVertexAttribI2ui                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI3UIPROC                                       glVertexAttribI3ui                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI4UIPROC                                       glVertexAttribI4ui                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI1IVPROC                                       glVertexAttribI1iv                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI2IVPROC                                       glVertexAttribI2iv                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI3IVPROC                                       glVertexAttribI3iv                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI4IVPROC                                       glVertexAttribI4iv                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI1UIVPROC                                      glVertexAttribI1uiv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI2UIVPROC                                      glVertexAttribI2uiv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI3UIVPROC                                      glVertexAttribI3uiv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI4UIVPROC                                      glVertexAttribI4uiv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI4BVPROC                                       glVertexAttribI4bv                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI4SVPROC                                       glVertexAttribI4sv                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI4UBVPROC                                      glVertexAttribI4ubv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI4USVPROC                                      glVertexAttribI4usv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNIFORMUIVPROC                                          glGetUniformuiv                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDFRAGDATALOCATIONPROC                                   glBindFragDataLocation                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFRAGDATALOCATIONPROC                                    glGetFragDataLocation                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1UIPROC                                             glUniform1ui                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2UIPROC                                             glUniform2ui                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3UIPROC                                             glUniform3ui                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4UIPROC                                             glUniform4ui                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1UIVPROC                                            glUniform1uiv                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2UIVPROC                                            glUniform2uiv                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3UIVPROC                                            glUniform3uiv                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4UIVPROC                                            glUniform4uiv                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXPARAMETERIIVPROC                                        glTexParameterIiv                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXPARAMETERIUIVPROC                                       glTexParameterIuiv                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXPARAMETERIIVPROC                                     glGetTexParameterIiv                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXPARAMETERIUIVPROC                                    glGetTexParameterIuiv                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARBUFFERIVPROC                                          glClearBufferiv                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARBUFFERUIVPROC                                         glClearBufferuiv                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARBUFFERFVPROC                                          glClearBufferfv                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARBUFFERFIPROC                                          glClearBufferfi                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSTRINGIPROC                                             glGetStringi                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISRENDERBUFFERPROC                                         glIsRenderbuffer                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDRENDERBUFFERPROC                                       glBindRenderbuffer                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETERENDERBUFFERSPROC                                    glDeleteRenderbuffers                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENRENDERBUFFERSPROC                                       glGenRenderbuffers                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRENDERBUFFERSTORAGEPROC                                    glRenderbufferStorage                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETRENDERBUFFERPARAMETERIVPROC                             glGetRenderbufferParameteriv                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISFRAMEBUFFERPROC                                          glIsFramebuffer                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDFRAMEBUFFERPROC                                        glBindFramebuffer                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEFRAMEBUFFERSPROC                                     glDeleteFramebuffers                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENFRAMEBUFFERSPROC                                        glGenFramebuffers                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCHECKFRAMEBUFFERSTATUSPROC                                 glCheckFramebufferStatus                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERTEXTURE1DPROC                                   glFramebufferTexture1D                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERTEXTURE2DPROC                                   glFramebufferTexture2D                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERTEXTURE3DPROC                                   glFramebufferTexture3D                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERRENDERBUFFERPROC                                glFramebufferRenderbuffer                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC                    glGetFramebufferAttachmentParameteriv                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENERATEMIPMAPPROC                                         glGenerateMipmap                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBLITFRAMEBUFFERPROC                                        glBlitFramebuffer                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC                         glRenderbufferStorageMultisample                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERTEXTURELAYERPROC                                glFramebufferTextureLayer                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAPBUFFERRANGEPROC                                         glMapBufferRange                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFLUSHMAPPEDBUFFERRANGEPROC                                 glFlushMappedBufferRange                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDVERTEXARRAYPROC                                        glBindVertexArray                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEVERTEXARRAYSPROC                                     glDeleteVertexArrays                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENVERTEXARRAYSPROC                                        glGenVertexArrays                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISVERTEXARRAYPROC                                          glIsVertexArray                                                         GL_FUNC_DEF2     ;
#endif /* GL_VERSION_3_0 */

#ifdef GL_VERSION_3_1
GL_FUNC_DEF  PFNGLDRAWARRAYSINSTANCEDPROC                               glDrawArraysInstanced                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWELEMENTSINSTANCEDPROC                             glDrawElementsInstanced                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXBUFFERPROC                                         glTexBuffer                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPRIMITIVERESTARTINDEXPROC                             glPrimitiveRestartIndex                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYBUFFERSUBDATAPROC                                 glCopyBufferSubData                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNIFORMINDICESPROC                                 glGetUniformIndices                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETACTIVEUNIFORMSIVPROC                               glGetActiveUniformsiv                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETACTIVEUNIFORMNAMEPROC                              glGetActiveUniformName                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNIFORMBLOCKINDEXPROC                              glGetUniformBlockIndex                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETACTIVEUNIFORMBLOCKIVPROC                           glGetActiveUniformBlockiv                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC                         glGetActiveUniformBlockName                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMBLOCKBINDINGPROC                               glUniformBlockBinding                                            GL_FUNC_DEF2     ;
#endif /* GL_VERSION_3_1 */

#ifdef GL_VERSION_3_2
GL_FUNC_DEF  PFNGLDRAWELEMENTSBASEVERTEXPROC                                   glDrawElementsBaseVertex                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC                              glDrawRangeElementsBaseVertex                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC                          glDrawElementsInstancedBaseVertex                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC                              glMultiDrawElementsBaseVertex                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROVOKINGVERTEXPROC                                          glProvokingVertex                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFENCESYNCPROC                                                glFenceSync                                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISSYNCPROC                                                   glIsSync                                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETESYNCPROC                                               glDeleteSync                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLIENTWAITSYNCPROC                                           glClientWaitSync                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWAITSYNCPROC                                                 glWaitSync                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETINTEGER64VPROC                                            glGetInteger64v                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSYNCIVPROC                                                glGetSynciv                                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETINTEGER64I_VPROC                                          glGetInteger64i_v                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETBUFFERPARAMETERI64VPROC                                   glGetBufferParameteri64v                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERTEXTUREPROC                                       glFramebufferTexture                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXIMAGE2DMULTISAMPLEPROC                                    glTexImage2DMultisample                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXIMAGE3DMULTISAMPLEPROC                                    glTexImage3DMultisample                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMULTISAMPLEFVPROC                                         glGetMultisamplefv                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSAMPLEMASKIPROC                                              glSampleMaski                                                           GL_FUNC_DEF2     ;
#endif /* GL_VERSION_3_2 */

#ifdef GL_VERSION_3_3
GL_FUNC_DEF  PFNGLBINDFRAGDATALOCATIONINDEXEDPROC                           glBindFragDataLocationIndexed                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFRAGDATAINDEXPROC                                      glGetFragDataIndex                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENSAMPLERSPROC                                           glGenSamplers                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETESAMPLERSPROC                                        glDeleteSamplers                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISSAMPLERPROC                                             glIsSampler                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDSAMPLERPROC                                           glBindSampler                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSAMPLERPARAMETERIPROC                                     glSamplerParameteri                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSAMPLERPARAMETERIVPROC                                    glSamplerParameteriv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSAMPLERPARAMETERFPROC                                     glSamplerParameterf                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSAMPLERPARAMETERFVPROC                                    glSamplerParameterfv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSAMPLERPARAMETERIIVPROC                                   glSamplerParameterIiv                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSAMPLERPARAMETERIUIVPROC                                  glSamplerParameterIuiv                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSAMPLERPARAMETERIVPROC                                 glGetSamplerParameteriv                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSAMPLERPARAMETERIIVPROC                                glGetSamplerParameterIiv                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSAMPLERPARAMETERFVPROC                                 glGetSamplerParameterfv                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSAMPLERPARAMETERIUIVPROC                               glGetSamplerParameterIuiv                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLQUERYCOUNTERPROC                                          glQueryCounter                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETQUERYOBJECTI64VPROC                                    glGetQueryObjecti64v                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETQUERYOBJECTUI64VPROC                                   glGetQueryObjectui64v                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBDIVISORPROC                                   glVertexAttribDivisor                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBP1UIPROC                                      glVertexAttribP1ui                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBP1UIVPROC                                     glVertexAttribP1uiv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBP2UIPROC                                      glVertexAttribP2ui                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBP2UIVPROC                                     glVertexAttribP2uiv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBP3UIPROC                                      glVertexAttribP3ui                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBP3UIVPROC                                     glVertexAttribP3uiv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBP4UIPROC                                      glVertexAttribP4ui                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBP4UIVPROC                                     glVertexAttribP4uiv                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXP2UIPROC                                            glVertexP2ui                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXP2UIVPROC                                           glVertexP2uiv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXP3UIPROC                                            glVertexP3ui                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXP3UIVPROC                                           glVertexP3uiv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXP4UIPROC                                            glVertexP4ui                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXP4UIVPROC                                           glVertexP4uiv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORDP1UIPROC                                          glTexCoordP1ui                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORDP1UIVPROC                                         glTexCoordP1uiv                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORDP2UIPROC                                          glTexCoordP2ui                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORDP2UIVPROC                                         glTexCoordP2uiv                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORDP3UIPROC                                          glTexCoordP3ui                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORDP3UIVPROC                                         glTexCoordP3uiv                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORDP4UIPROC                                          glTexCoordP4ui                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORDP4UIVPROC                                         glTexCoordP4uiv                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORDP1UIPROC                                     glMultiTexCoordP1ui                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORDP1UIVPROC                                    glMultiTexCoordP1uiv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORDP2UIPROC                                     glMultiTexCoordP2ui                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORDP2UIVPROC                                    glMultiTexCoordP2uiv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORDP3UIPROC                                     glMultiTexCoordP3ui                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORDP3UIVPROC                                    glMultiTexCoordP3uiv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORDP4UIPROC                                     glMultiTexCoordP4ui                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORDP4UIVPROC                                    glMultiTexCoordP4uiv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMALP3UIPROC                                            glNormalP3ui                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMALP3UIVPROC                                           glNormalP3uiv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLORP3UIPROC                                             glColorP3ui                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLORP3UIVPROC                                            glColorP3uiv                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLORP4UIPROC                                             glColorP4ui                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLORP4UIVPROC                                            glColorP4uiv                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLORP3UIPROC                                    glSecondaryColorP3ui                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLORP3UIVPROC                                   glSecondaryColorP3uiv                                             GL_FUNC_DEF2     ;
#endif /* GL_VERSION_3_3 */

#ifdef GL_VERSION_4_0
GL_FUNC_DEF  PFNGLMINSAMPLESHADINGPROC                                    glMinSampleShading                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBLENDEQUATIONIPROC                                      glBlendEquationi                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBLENDEQUATIONSEPARATEIPROC                              glBlendEquationSeparatei                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBLENDFUNCIPROC                                          glBlendFunci                                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBLENDFUNCSEPARATEIPROC                                  glBlendFuncSeparatei                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWARRAYSINDIRECTPROC                                  glDrawArraysIndirect                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWELEMENTSINDIRECTPROC                                glDrawElementsIndirect                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1DPROC                                           glUniform1d                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2DPROC                                           glUniform2d                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3DPROC                                           glUniform3d                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4DPROC                                           glUniform4d                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1DVPROC                                          glUniform1dv                                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2DVPROC                                          glUniform2dv                                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3DVPROC                                          glUniform3dv                                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4DVPROC                                          glUniform4dv                                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX2DVPROC                                    glUniformMatrix2dv                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX3DVPROC                                    glUniformMatrix3dv                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX4DVPROC                                    glUniformMatrix4dv                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX2X3DVPROC                                  glUniformMatrix2x3dv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX2X4DVPROC                                  glUniformMatrix2x4dv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX3X2DVPROC                                  glUniformMatrix3x2dv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX3X4DVPROC                                  glUniformMatrix3x4dv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX4X2DVPROC                                  glUniformMatrix4x2dv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX4X3DVPROC                                  glUniformMatrix4x3dv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNIFORMDVPROC                                        glGetUniformdv                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC                        glGetSubroutineUniformLocation                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSUBROUTINEINDEXPROC                                  glGetSubroutineIndex                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC                        glGetActiveSubroutineUniformiv                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC                      glGetActiveSubroutineUniformName                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETACTIVESUBROUTINENAMEPROC                             glGetActiveSubroutineName                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMSUBROUTINESUIVPROC                               glUniformSubroutinesuiv                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNIFORMSUBROUTINEUIVPROC                             glGetUniformSubroutineuiv                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMSTAGEIVPROC                                   glGetProgramStageiv                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATCHPARAMETERIPROC                                     glPatchParameteri                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATCHPARAMETERFVPROC                                    glPatchParameterfv                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDTRANSFORMFEEDBACKPROC                               glBindTransformFeedback                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETETRANSFORMFEEDBACKSPROC                            glDeleteTransformFeedbacks                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENTRANSFORMFEEDBACKSPROC                               glGenTransformFeedbacks                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISTRANSFORMFEEDBACKPROC                                 glIsTransformFeedback                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPAUSETRANSFORMFEEDBACKPROC                              glPauseTransformFeedback                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRESUMETRANSFORMFEEDBACKPROC                             glResumeTransformFeedback                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWTRANSFORMFEEDBACKPROC                               glDrawTransformFeedback                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC                         glDrawTransformFeedbackStream                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBEGINQUERYINDEXEDPROC                                   glBeginQueryIndexed                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENDQUERYINDEXEDPROC                                     glEndQueryIndexed                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETQUERYINDEXEDIVPROC                                   glGetQueryIndexediv                                                      GL_FUNC_DEF2     ;
#endif /* GL_VERSION_4_0 */

#ifdef GL_VERSION_4_1
GL_FUNC_DEF  PFNGLRELEASESHADERCOMPILERPROC                                    glReleaseShaderCompiler                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSHADERBINARYPROC                                             glShaderBinary                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSHADERPRECISIONFORMATPROC                                 glGetShaderPrecisionFormat                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEPTHRANGEFPROC                                              glDepthRangef                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARDEPTHFPROC                                              glClearDepthf                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMBINARYPROC                                         glGetProgramBinary                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMBINARYPROC                                            glProgramBinary                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMPARAMETERIPROC                                        glProgramParameteri                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUSEPROGRAMSTAGESPROC                                         glUseProgramStages                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLACTIVESHADERPROGRAMPROC                                      glActiveShaderProgram                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATESHADERPROGRAMVPROC                                     glCreateShaderProgramv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDPROGRAMPIPELINEPROC                                      glBindProgramPipeline                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEPROGRAMPIPELINESPROC                                   glDeleteProgramPipelines                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENPROGRAMPIPELINESPROC                                      glGenProgramPipelines                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISPROGRAMPIPELINEPROC                                        glIsProgramPipeline                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMPIPELINEIVPROC                                     glGetProgramPipelineiv                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1IPROC                                         glProgramUniform1i                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1IVPROC                                        glProgramUniform1iv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1FPROC                                         glProgramUniform1f                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1FVPROC                                        glProgramUniform1fv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1DPROC                                         glProgramUniform1d                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1DVPROC                                        glProgramUniform1dv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1UIPROC                                        glProgramUniform1ui                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1UIVPROC                                       glProgramUniform1uiv                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2IPROC                                         glProgramUniform2i                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2IVPROC                                        glProgramUniform2iv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2FPROC                                         glProgramUniform2f                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2FVPROC                                        glProgramUniform2fv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2DPROC                                         glProgramUniform2d                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2DVPROC                                        glProgramUniform2dv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2UIPROC                                        glProgramUniform2ui                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2UIVPROC                                       glProgramUniform2uiv                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3IPROC                                         glProgramUniform3i                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3IVPROC                                        glProgramUniform3iv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3FPROC                                         glProgramUniform3f                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3FVPROC                                        glProgramUniform3fv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3DPROC                                         glProgramUniform3d                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3DVPROC                                        glProgramUniform3dv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3UIPROC                                        glProgramUniform3ui                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3UIVPROC                                       glProgramUniform3uiv                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4IPROC                                         glProgramUniform4i                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4IVPROC                                        glProgramUniform4iv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4FPROC                                         glProgramUniform4f                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4FVPROC                                        glProgramUniform4fv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4DPROC                                         glProgramUniform4d                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4DVPROC                                        glProgramUniform4dv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4UIPROC                                        glProgramUniform4ui                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4UIVPROC                                       glProgramUniform4uiv                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX2FVPROC                                  glProgramUniformMatrix2fv                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX3FVPROC                                  glProgramUniformMatrix3fv                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX4FVPROC                                  glProgramUniformMatrix4fv                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX2DVPROC                                  glProgramUniformMatrix2dv                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX3DVPROC                                  glProgramUniformMatrix3dv                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX4DVPROC                                  glProgramUniformMatrix4dv                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC                                glProgramUniformMatrix2x3fv                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC                                glProgramUniformMatrix3x2fv                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC                                glProgramUniformMatrix2x4fv                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC                                glProgramUniformMatrix4x2fv                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC                                glProgramUniformMatrix3x4fv                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC                                glProgramUniformMatrix4x3fv                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC                                glProgramUniformMatrix2x3dv                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC                                glProgramUniformMatrix3x2dv                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC                                glProgramUniformMatrix2x4dv                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC                                glProgramUniformMatrix4x2dv                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC                                glProgramUniformMatrix3x4dv                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC                                glProgramUniformMatrix4x3dv                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVALIDATEPROGRAMPIPELINEPROC                                  glValidateProgramPipeline                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMPIPELINEINFOLOGPROC                                glGetProgramPipelineInfoLog                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL1DPROC                                          glVertexAttribL1d                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL2DPROC                                          glVertexAttribL2d                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL3DPROC                                          glVertexAttribL3d                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL4DPROC                                          glVertexAttribL4d                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL1DVPROC                                         glVertexAttribL1dv                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL2DVPROC                                         glVertexAttribL2dv                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL3DVPROC                                         glVertexAttribL3dv                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL4DVPROC                                         glVertexAttribL4dv                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBLPOINTERPROC                                     glVertexAttribLPointer                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBLDVPROC                                       glGetVertexAttribLdv                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVIEWPORTARRAYVPROC                                           glViewportArrayv                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVIEWPORTINDEXEDFPROC                                         glViewportIndexedf                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVIEWPORTINDEXEDFVPROC                                        glViewportIndexedfv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSCISSORARRAYVPROC                                            glScissorArrayv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSCISSORINDEXEDPROC                                           glScissorIndexed                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSCISSORINDEXEDVPROC                                          glScissorIndexedv                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEPTHRANGEARRAYVPROC                                         glDepthRangeArrayv                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEPTHRANGEINDEXEDPROC                                        glDepthRangeIndexed                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFLOATI_VPROC                                              glGetFloati_v                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETDOUBLEI_VPROC                                             glGetDoublei_v                                                      GL_FUNC_DEF2     ;
#endif /* GL_VERSION_4_1 */

#ifdef GL_VERSION_4_2
GL_FUNC_DEF  PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC                              glDrawArraysInstancedBaseInstance                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC                            glDrawElementsInstancedBaseInstance                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC                  glDrawElementsInstancedBaseVertexBaseInstance                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETINTERNALFORMATIVPROC                                          glGetInternalformativ                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC                               glGetActiveAtomicCounterBufferiv                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDIMAGETEXTUREPROC                                             glBindImageTexture                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMEMORYBARRIERPROC                                                glMemoryBarrier                                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXSTORAGE1DPROC                                                 glTexStorage1D                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXSTORAGE2DPROC                                                 glTexStorage2D                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXSTORAGE3DPROC                                                 glTexStorage3D                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC                               glDrawTransformFeedbackInstanced                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC                         glDrawTransformFeedbackStreamInstanced                                      GL_FUNC_DEF2     ;
#endif /* GL_VERSION_4_2 */

#ifdef GL_VERSION_4_3
GL_FUNC_DEF  PFNGLCLEARBUFFERDATAPROC                                         glClearBufferData                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARBUFFERSUBDATAPROC                                      glClearBufferSubData                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDISPATCHCOMPUTEPROC                                         glDispatchCompute                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDISPATCHCOMPUTEINDIRECTPROC                                 glDispatchComputeIndirect                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYIMAGESUBDATAPROC                                        glCopyImageSubData                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERPARAMETERIPROC                                   glFramebufferParameteri                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFRAMEBUFFERPARAMETERIVPROC                               glGetFramebufferParameteriv                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETINTERNALFORMATI64VPROC                                   glGetInternalformati64v                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLINVALIDATETEXSUBIMAGEPROC                                   glInvalidateTexSubImage                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLINVALIDATETEXIMAGEPROC                                      glInvalidateTexImage                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLINVALIDATEBUFFERSUBDATAPROC                                 glInvalidateBufferSubData                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLINVALIDATEBUFFERDATAPROC                                    glInvalidateBufferData                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLINVALIDATEFRAMEBUFFERPROC                                   glInvalidateFramebuffer                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLINVALIDATESUBFRAMEBUFFERPROC                                glInvalidateSubFramebuffer                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTIDRAWARRAYSINDIRECTPROC                                 glMultiDrawArraysIndirect                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTIDRAWELEMENTSINDIRECTPROC                               glMultiDrawElementsIndirect                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMINTERFACEIVPROC                                   glGetProgramInterfaceiv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMRESOURCEINDEXPROC                                 glGetProgramResourceIndex                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMRESOURCENAMEPROC                                  glGetProgramResourceName                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMRESOURCEIVPROC                                    glGetProgramResourceiv                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMRESOURCELOCATIONPROC                              glGetProgramResourceLocation                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC                         glGetProgramResourceLocationIndex                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSHADERSTORAGEBLOCKBINDINGPROC                               glShaderStorageBlockBinding                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXBUFFERRANGEPROC                                          glTexBufferRange                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXSTORAGE2DMULTISAMPLEPROC                                 glTexStorage2DMultisample                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXSTORAGE3DMULTISAMPLEPROC                                 glTexStorage3DMultisample                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREVIEWPROC                                             glTextureView                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDVERTEXBUFFERPROC                                        glBindVertexBuffer                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBFORMATPROC                                      glVertexAttribFormat                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBIFORMATPROC                                     glVertexAttribIFormat                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBLFORMATPROC                                     glVertexAttribLFormat                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBBINDINGPROC                                     glVertexAttribBinding                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXBINDINGDIVISORPROC                                    glVertexBindingDivisor                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEBUGMESSAGECONTROLPROC                                     glDebugMessageControl                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEBUGMESSAGEINSERTPROC                                      glDebugMessageInsert                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEBUGMESSAGECALLBACKPROC                                    glDebugMessageCallback                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETDEBUGMESSAGELOGPROC                                      glGetDebugMessageLog                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPUSHDEBUGGROUPPROC                                          glPushDebugGroup                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOPDEBUGGROUPPROC                                           glPopDebugGroup                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLOBJECTLABELPROC                                             glObjectLabel                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETOBJECTLABELPROC                                          glGetObjectLabel                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLOBJECTPTRLABELPROC                                          glObjectPtrLabel                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETOBJECTPTRLABELPROC                                       glGetObjectPtrLabel                                                     GL_FUNC_DEF2     ;
#endif /* GL_VERSION_4_3 */

#ifdef GL_VERSION_4_4
GL_FUNC_DEF  PFNGLBUFFERSTORAGEPROC                           glBufferStorage                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARTEXIMAGEPROC                           glClearTexImage                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARTEXSUBIMAGEPROC                        glClearTexSubImage                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDBUFFERSBASEPROC                         glBindBuffersBase                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDBUFFERSRANGEPROC                        glBindBuffersRange                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDTEXTURESPROC                            glBindTextures                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDSAMPLERSPROC                            glBindSamplers                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDIMAGETEXTURESPROC                       glBindImageTextures                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDVERTEXBUFFERSPROC                       glBindVertexBuffers                                    GL_FUNC_DEF2     ;
#endif /* GL_VERSION_4_4 */

#ifdef GL_VERSION_4_5
  GL_FUNC_DEF  PFNGLCLIPCONTROLPROC                                               glClipControl                                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATETRANSFORMFEEDBACKSPROC                                  glCreateTransformFeedbacks                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC                               glTransformFeedbackBufferBase                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC                              glTransformFeedbackBufferRange                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTRANSFORMFEEDBACKIVPROC                                    glGetTransformFeedbackiv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTRANSFORMFEEDBACKI_VPROC                                   glGetTransformFeedbacki_v                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTRANSFORMFEEDBACKI64_VPROC                                 glGetTransformFeedbacki64_v                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATEBUFFERSPROC                                             glCreateBuffers                                                              GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLNAMEDBUFFERSTORAGEPROC                                        glNamedBufferStorage                                                         GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLNAMEDBUFFERDATAPROC                                           glNamedBufferData                                                            GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLNAMEDBUFFERSUBDATAPROC                                        glNamedBufferSubData                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYNAMEDBUFFERSUBDATAPROC                                    glCopyNamedBufferSubData                                                     GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLCLEARNAMEDBUFFERDATAPROC                                      glClearNamedBufferData                                                       GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLCLEARNAMEDBUFFERSUBDATAPROC                                   glClearNamedBufferSubData                                                    GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLMAPNAMEDBUFFERPROC                                            glMapNamedBuffer                                                             GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLMAPNAMEDBUFFERRANGEPROC                                       glMapNamedBufferRange                                                        GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLUNMAPNAMEDBUFFERPROC                                          glUnmapNamedBuffer                                                           GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC                               glFlushMappedNamedBufferRange                                                GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNAMEDBUFFERPARAMETERIVPROC                                 glGetNamedBufferParameteriv                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNAMEDBUFFERPARAMETERI64VPROC                               glGetNamedBufferParameteri64v                                                GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNAMEDBUFFERPOINTERVPROC                                    glGetNamedBufferPointerv                                                     GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNAMEDBUFFERSUBDATAPROC                                     glGetNamedBufferSubData                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATEFRAMEBUFFERSPROC                                        glCreateFramebuffers                                                         GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC                              glNamedFramebufferRenderbuffer                                               GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC                                glNamedFramebufferParameteri                                                 GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERTEXTUREPROC                                   glNamedFramebufferTexture                                                    GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC                              glNamedFramebufferTextureLayer                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC                                glNamedFramebufferDrawBuffer                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC                               glNamedFramebufferDrawBuffers                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC                                glNamedFramebufferReadBuffer                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC                            glInvalidateNamedFramebufferData                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC                         glInvalidateNamedFramebufferSubData                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARNAMEDFRAMEBUFFERIVPROC                                   glClearNamedFramebufferiv                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC                                  glClearNamedFramebufferuiv                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARNAMEDFRAMEBUFFERFVPROC                                   glClearNamedFramebufferfv                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARNAMEDFRAMEBUFFERFIPROC                                   glClearNamedFramebufferfi                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBLITNAMEDFRAMEBUFFERPROC                                      glBlitNamedFramebuffer                                                       GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC                               glCheckNamedFramebufferStatus                                                GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC                            glGetNamedFramebufferParameteriv                                             GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC                  glGetNamedFramebufferAttachmentParameteriv                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATERENDERBUFFERSPROC                                       glCreateRenderbuffers                                                        GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLNAMEDRENDERBUFFERSTORAGEPROC                                  glNamedRenderbufferStorage                                                   GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC                       glNamedRenderbufferStorageMultisample                                        GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC                           glGetNamedRenderbufferParameteriv                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATETEXTURESPROC                                            glCreateTextures                                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREBUFFERPROC                                             glTextureBuffer                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREBUFFERRANGEPROC                                        glTextureBufferRange                                                         GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLTEXTURESTORAGE1DPROC                                          glTextureStorage1D                                                           GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLTEXTURESTORAGE2DPROC                                          glTextureStorage2D                                                           GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLTEXTURESTORAGE3DPROC                                          glTextureStorage3D                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC                               glTextureStorage2DMultisample                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC                               glTextureStorage3DMultisample                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESUBIMAGE1DPROC                                         glTextureSubImage1D                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESUBIMAGE2DPROC                                         glTextureSubImage2D                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESUBIMAGE3DPROC                                         glTextureSubImage3D                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC                               glCompressedTextureSubImage1D                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC                               glCompressedTextureSubImage2D                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC                               glCompressedTextureSubImage3D                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYTEXTURESUBIMAGE1DPROC                                     glCopyTextureSubImage1D                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYTEXTURESUBIMAGE2DPROC                                     glCopyTextureSubImage2D                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYTEXTURESUBIMAGE3DPROC                                     glCopyTextureSubImage3D                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREPARAMETERFPROC                                         glTextureParameterf                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREPARAMETERFVPROC                                        glTextureParameterfv                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREPARAMETERIPROC                                         glTextureParameteri                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREPARAMETERIIVPROC                                       glTextureParameterIiv                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREPARAMETERIUIVPROC                                      glTextureParameterIuiv                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREPARAMETERIVPROC                                        glTextureParameteriv                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENERATETEXTUREMIPMAPPROC                                     glGenerateTextureMipmap                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDTEXTUREUNITPROC                                           glBindTextureUnit                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXTUREIMAGEPROC                                           glGetTextureImage                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC                                 glGetCompressedTextureImage                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXTURELEVELPARAMETERFVPROC                                glGetTextureLevelParameterfv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXTURELEVELPARAMETERIVPROC                                glGetTextureLevelParameteriv                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXTUREPARAMETERFVPROC                                     glGetTextureParameterfv                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXTUREPARAMETERIIVPROC                                    glGetTextureParameterIiv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXTUREPARAMETERIUIVPROC                                   glGetTextureParameterIuiv                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXTUREPARAMETERIVPROC                                     glGetTextureParameteriv                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATEVERTEXARRAYSPROC                                        glCreateVertexArrays                                                         GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLDISABLEVERTEXARRAYATTRIBPROC                                  glDisableVertexArrayAttrib                                                   GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLENABLEVERTEXARRAYATTRIBPROC                                   glEnableVertexArrayAttrib                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYELEMENTBUFFERPROC                                  glVertexArrayElementBuffer                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYVERTEXBUFFERPROC                                   glVertexArrayVertexBuffer                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYVERTEXBUFFERSPROC                                  glVertexArrayVertexBuffers                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYATTRIBBINDINGPROC                                  glVertexArrayAttribBinding                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYATTRIBFORMATPROC                                   glVertexArrayAttribFormat                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYATTRIBIFORMATPROC                                  glVertexArrayAttribIFormat                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYATTRIBLFORMATPROC                                  glVertexArrayAttribLFormat                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYBINDINGDIVISORPROC                                 glVertexArrayBindingDivisor                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXARRAYIVPROC                                          glGetVertexArrayiv                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXARRAYINDEXEDIVPROC                                   glGetVertexArrayIndexediv                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXARRAYINDEXED64IVPROC                                 glGetVertexArrayIndexed64iv                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATESAMPLERSPROC                                            glCreateSamplers                                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATEPROGRAMPIPELINESPROC                                    glCreateProgramPipelines                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATEQUERIESPROC                                             glCreateQueries                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETQUERYBUFFEROBJECTI64VPROC                                  glGetQueryBufferObjecti64v                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETQUERYBUFFEROBJECTIVPROC                                    glGetQueryBufferObjectiv                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETQUERYBUFFEROBJECTUI64VPROC                                 glGetQueryBufferObjectui64v                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETQUERYBUFFEROBJECTUIVPROC                                   glGetQueryBufferObjectuiv                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMEMORYBARRIERBYREGIONPROC                                     glMemoryBarrierByRegion                                                      GL_FUNC_DEF2     ;
  GL_FUNC_DEF  PFNGLGETTEXTURESUBIMAGEPROC                                        glGetTextureSubImage                                                         GL_FUNC_DEF2     ;
  GL_FUNC_DEF  PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC                              glGetCompressedTextureSubImage                                               GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETGRAPHICSRESETSTATUSPROC                                    glGetGraphicsResetStatus                                                     GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNCOMPRESSEDTEXIMAGEPROC                                    glGetnCompressedTexImage                                                     GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNTEXIMAGEPROC                                              glGetnTexImage                                                               GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNUNIFORMDVPROC                                             glGetnUniformdv                                                              GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNUNIFORMFVPROC                                             glGetnUniformfv                                                              GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNUNIFORMIVPROC                                             glGetnUniformiv                                                              GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNUNIFORMUIVPROC                                            glGetnUniformuiv                                                             GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLREADNPIXELSPROC                                               glReadnPixels                                                                GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNMAPDVPROC                                                 glGetnMapdv                                                                  GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNMAPFVPROC                                                 glGetnMapfv                                                                  GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNMAPIVPROC                                                 glGetnMapiv                                                                  GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNPIXELMAPFVPROC                                            glGetnPixelMapfv                                                             GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNPIXELMAPUIVPROC                                           glGetnPixelMapuiv                                                            GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNPIXELMAPUSVPROC                                           glGetnPixelMapusv                                                            GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNPOLYGONSTIPPLEPROC                                        glGetnPolygonStipple                                                         GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNCOLORTABLEPROC                                            glGetnColorTable                                                             GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNCONVOLUTIONFILTERPROC                                     glGetnConvolutionFilter                                                      GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNSEPARABLEFILTERPROC                                       glGetnSeparableFilter                                                        GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNHISTOGRAMPROC                                             glGetnHistogram                                                              GL_FUNC_DEF2     ;
 GL_FUNC_DEF  PFNGLGETNMINMAXPROC                                                glGetnMinmax                                                                 GL_FUNC_DEF2     ;
  GL_FUNC_DEF  PFNGLTEXTUREBARRIERPROC                                            glTextureBarrier                                                             GL_FUNC_DEF2     ;
#endif /* GL_VERSION_4_5 */

#ifdef GL_VERSION_4_6
GL_FUNC_DEF  PFNGLSPECIALIZESHADERPROC                                 glSpecializeShader                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC                     glMultiDrawArraysIndirectCount                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC                   glMultiDrawElementsIndirectCount                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOLYGONOFFSETCLAMPPROC                               glPolygonOffsetClamp                                              GL_FUNC_DEF2     ;
#endif /* GL_VERSION_4_6 */


#ifdef GL_ARB_imaging
GL_FUNC_DEF  PFNGLCOLORTABLEPROC                                     glColorTable                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLORTABLEPARAMETERFVPROC                          glColorTableParameterfv                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLORTABLEPARAMETERIVPROC                          glColorTableParameteriv                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYCOLORTABLEPROC                                 glCopyColorTable                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOLORTABLEPROC                                  glGetColorTable                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOLORTABLEPARAMETERFVPROC                       glGetColorTableParameterfv                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOLORTABLEPARAMETERIVPROC                       glGetColorTableParameteriv                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLORSUBTABLEPROC                                  glColorSubTable                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYCOLORSUBTABLEPROC                              glCopyColorSubTable                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCONVOLUTIONFILTER1DPROC                            glConvolutionFilter1D                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCONVOLUTIONFILTER2DPROC                            glConvolutionFilter2D                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCONVOLUTIONPARAMETERFPROC                          glConvolutionParameterf                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCONVOLUTIONPARAMETERFVPROC                         glConvolutionParameterfv                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCONVOLUTIONPARAMETERIPROC                          glConvolutionParameteri                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCONVOLUTIONPARAMETERIVPROC                         glConvolutionParameteriv                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYCONVOLUTIONFILTER1DPROC                        glCopyConvolutionFilter1D                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYCONVOLUTIONFILTER2DPROC                        glCopyConvolutionFilter2D                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCONVOLUTIONFILTERPROC                           glGetConvolutionFilter                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCONVOLUTIONPARAMETERFVPROC                      glGetConvolutionParameterfv                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCONVOLUTIONPARAMETERIVPROC                      glGetConvolutionParameteriv                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSEPARABLEFILTERPROC                             glGetSeparableFilter                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSEPARABLEFILTER2DPROC                              glSeparableFilter2D                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETHISTOGRAMPROC                                   glGetHistogram                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETHISTOGRAMPARAMETERFVPROC                        glGetHistogramParameterfv                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETHISTOGRAMPARAMETERIVPROC                        glGetHistogramParameteriv                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMINMAXPROC                                      glGetMinmax                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMINMAXPARAMETERFVPROC                           glGetMinmaxParameterfv                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMINMAXPARAMETERIVPROC                           glGetMinmaxParameteriv                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLHISTOGRAMPROC                                      glHistogram                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMINMAXPROC                                         glMinmax                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRESETHISTOGRAMPROC                                 glResetHistogram                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRESETMINMAXPROC                                    glResetMinmax                                            GL_FUNC_DEF2     ;
#endif /* GL_ARB_imaging */

#ifdef GL_ARB_ES3_2_compatibility
GL_FUNC_DEF  PFNGLPRIMITIVEBOUNDINGBOXARBPROC               glPrimitiveBoundingBoxARB                           GL_FUNC_DEF2     ;
#endif /* GL_ARB_ES3_2_compatibility */

#ifdef GL_ARB_bindless_texture
GL_FUNC_DEF  PFNGLGETTEXTUREHANDLEARBPROC                                 glGetTextureHandleARB                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXTURESAMPLERHANDLEARBPROC                          glGetTextureSamplerHandleARB                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAKETEXTUREHANDLERESIDENTARBPROC                        glMakeTextureHandleResidentARB                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC                     glMakeTextureHandleNonResidentARB                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETIMAGEHANDLEARBPROC                                   glGetImageHandleARB                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAKEIMAGEHANDLERESIDENTARBPROC                          glMakeImageHandleResidentARB                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC                       glMakeImageHandleNonResidentARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMHANDLEUI64ARBPROC                                glUniformHandleui64ARB                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMHANDLEUI64VARBPROC                               glUniformHandleui64vARB                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC                         glProgramUniformHandleui64ARB                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC                        glProgramUniformHandleui64vARB                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISTEXTUREHANDLERESIDENTARBPROC                          glIsTextureHandleResidentARB                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISIMAGEHANDLERESIDENTARBPROC                            glIsImageHandleResidentARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL1UI64ARBPROC                               glVertexAttribL1ui64ARB                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL1UI64VARBPROC                              glVertexAttribL1ui64vARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBLUI64VARBPROC                            glGetVertexAttribLui64vARB                                     GL_FUNC_DEF2     ;
#endif /* GL_ARB_bindless_texture */

#ifdef GL_ARB_cl_event
GL_FUNC_DEF  PFNGLCREATESYNCFROMCLEVENTARBPROC                glCreateSyncFromCLeventARB                           GL_FUNC_DEF2     ;
#endif /* GL_ARB_cl_event */

#ifdef GL_ARB_color_buffer_float
GL_FUNC_DEF  PFNGLCLAMPCOLORARBPROC                glClampColorARB                           GL_FUNC_DEF2     ;
#endif /* GL_ARB_color_buffer_float */

#ifdef GL_ARB_compute_variable_group_size
GL_FUNC_DEF  PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC                glDispatchComputeGroupSizeARB                           GL_FUNC_DEF2     ;
#endif /* GL_ARB_compute_variable_group_size */

#ifdef GL_ARB_debug_output
GL_FUNC_DEF  PFNGLDEBUGMESSAGECONTROLARBPROC                   glDebugMessageControlARB                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEBUGMESSAGEINSERTARBPROC                    glDebugMessageInsertARB                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEBUGMESSAGECALLBACKARBPROC                  glDebugMessageCallbackARB                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETDEBUGMESSAGELOGARBPROC                    glGetDebugMessageLogARB                              GL_FUNC_DEF2     ;
#endif /* GL_ARB_debug_output */

#ifdef GL_ARB_draw_buffers
GL_FUNC_DEF  PFNGLDRAWBUFFERSARBPROC                glDrawBuffersARB                           GL_FUNC_DEF2     ;
#endif /* GL_ARB_draw_buffers */

#ifdef GL_ARB_draw_buffers_blend
GL_FUNC_DEF  PFNGLBLENDEQUATIONIARBPROC	                         glBlendEquationiARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBLENDEQUATIONSEPARATEIARBPROC                   glBlendEquationSeparateiARB                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBLENDFUNCIARBPROC                               glBlendFunciARB                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBLENDFUNCSEPARATEIARBPROC                       glBlendFuncSeparateiARB                                   GL_FUNC_DEF2     ;
#endif /* GL_ARB_draw_buffers_blend */

#ifdef GL_ARB_draw_instanced
GL_FUNC_DEF  PFNGLDRAWARRAYSINSTANCEDARBPROC                     glDrawArraysInstancedARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWELEMENTSINSTANCEDARBPROC                   glDrawElementsInstancedARB                              GL_FUNC_DEF2     ;
#endif /* GL_ARB_draw_instanced */

#ifdef GL_ARB_fragment_program
GL_FUNC_DEF  PFNGLPROGRAMSTRINGARBPROC                                 glProgramStringARB                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDPROGRAMARBPROC                                   glBindProgramARB                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEPROGRAMSARBPROC                                glDeleteProgramsARB                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENPROGRAMSARBPROC                                   glGenProgramsARB                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMENVPARAMETER4DARBPROC                         glProgramEnvParameter4dARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMENVPARAMETER4DVARBPROC                        glProgramEnvParameter4dvARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMENVPARAMETER4FARBPROC                         glProgramEnvParameter4fARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMENVPARAMETER4FVARBPROC                        glProgramEnvParameter4fvARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMLOCALPARAMETER4DARBPROC                       glProgramLocalParameter4dARB                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMLOCALPARAMETER4DVARBPROC                      glProgramLocalParameter4dvARB                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMLOCALPARAMETER4FARBPROC                       glProgramLocalParameter4fARB                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMLOCALPARAMETER4FVARBPROC                      glProgramLocalParameter4fvARB                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMENVPARAMETERDVARBPROC                      glGetProgramEnvParameterdvARB                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMENVPARAMETERFVARBPROC                      glGetProgramEnvParameterfvARB                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC                    glGetProgramLocalParameterdvARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC                    glGetProgramLocalParameterfvARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMIVARBPROC                                  glGetProgramivARB                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMSTRINGARBPROC                              glGetProgramStringARB                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISPROGRAMARBPROC                                     glIsProgramARB                                                 GL_FUNC_DEF2     ;
#endif /* GL_ARB_fragment_program */

#ifdef GL_ARB_geometry_shader4
GL_FUNC_DEF  PFNGLPROGRAMPARAMETERIARBPROC                            glProgramParameteriARB 		                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERTEXTUREARBPROC                           glFramebufferTextureARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERTEXTURELAYERARBPROC	                  glFramebufferTextureLayerARB                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERTEXTUREFACEARBPROC 	                  glFramebufferTextureFaceARB                                GL_FUNC_DEF2     ;
#endif /* GL_ARB_geometry_shader4 */

#ifdef GL_ARB_gl_spirv
GL_FUNC_DEF  PFNGLSPECIALIZESHADERARBPROC               glSpecializeShaderARB                            GL_FUNC_DEF2     ;
#endif /* GL_ARB_gl_spirv */

#ifdef GL_ARB_gpu_shader_int64
GL_FUNC_DEF  PFNGLUNIFORM1I64ARBPROC                                    glUniform1i64ARB                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2I64ARBPROC                                    glUniform2i64ARB                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3I64ARBPROC                                    glUniform3i64ARB                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4I64ARBPROC                                    glUniform4i64ARB                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1I64VARBPROC                                   glUniform1i64vARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2I64VARBPROC                                   glUniform2i64vARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3I64VARBPROC                                   glUniform3i64vARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4I64VARBPROC                                   glUniform4i64vARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1UI64ARBPROC                                   glUniform1ui64ARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2UI64ARBPROC                                   glUniform2ui64ARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3UI64ARBPROC                                   glUniform3ui64ARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4UI64ARBPROC                                   glUniform4ui64ARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1UI64VARBPROC                                  glUniform1ui64vARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2UI64VARBPROC                                  glUniform2ui64vARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3UI64VARBPROC                                  glUniform3ui64vARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4UI64VARBPROC                                  glUniform4ui64vARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNIFORMI64VARBPROC                                 glGetUniformi64vARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNIFORMUI64VARBPROC                                glGetUniformui64vARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNUNIFORMI64VARBPROC                                glGetnUniformi64vARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNUNIFORMUI64VARBPROC                               glGetnUniformui64vARB                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1I64ARBPROC                             glProgramUniform1i64ARB                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2I64ARBPROC                             glProgramUniform2i64ARB                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3I64ARBPROC                             glProgramUniform3i64ARB                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4I64ARBPROC                             glProgramUniform4i64ARB                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1I64VARBPROC                            glProgramUniform1i64vARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2I64VARBPROC                            glProgramUniform2i64vARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3I64VARBPROC                            glProgramUniform3i64vARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4I64VARBPROC                            glProgramUniform4i64vARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1UI64ARBPROC                            glProgramUniform1ui64ARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2UI64ARBPROC                            glProgramUniform2ui64ARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3UI64ARBPROC                            glProgramUniform3ui64ARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4UI64ARBPROC                            glProgramUniform4ui64ARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1UI64VARBPROC                           glProgramUniform1ui64vARB                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2UI64VARBPROC                           glProgramUniform2ui64vARB                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3UI64VARBPROC                           glProgramUniform3ui64vARB                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4UI64VARBPROC                           glProgramUniform4ui64vARB                               GL_FUNC_DEF2     ;
#endif /* GL_ARB_gpu_shader_int64 */

#ifdef GL_ARB_indirect_parameters
GL_FUNC_DEF  PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC                    glMultiDrawArraysIndirectCountARB                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC                  glMultiDrawElementsIndirectCountARB                             GL_FUNC_DEF2     ;
#endif /* GL_ARB_indirect_parameters */

#ifdef GL_ARB_instanced_arrays
GL_FUNC_DEF  PFNGLVERTEXATTRIBDIVISORARBPROC               glVertexAttribDivisorARB                                      GL_FUNC_DEF2     ;
#endif /* GL_ARB_instanced_arrays */

#ifdef GL_ARB_matrix_palette
GL_FUNC_DEF  PFNGLCURRENTPALETTEMATRIXARBPROC                  glCurrentPaletteMatrixARB                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXINDEXUBVARBPROC                        glMatrixIndexubvARB                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXINDEXUSVARBPROC                        glMatrixIndexusvARB                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXINDEXUIVARBPROC                        glMatrixIndexuivARB                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXINDEXPOINTERARBPROC                    glMatrixIndexPointerARB                                    GL_FUNC_DEF2     ;
#endif /* GL_ARB_matrix_palette */

#ifdef GL_ARB_multisample
GL_FUNC_DEF  PFNGLSAMPLECOVERAGEARBPROC              		   glSampleCoverageARB                                        GL_FUNC_DEF2     ;
#endif /* GL_ARB_multisample */

#ifdef GL_ARB_multitexture
GL_FUNC_DEF  PFNGLACTIVETEXTUREARBPROC                          glActiveTextureARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLIENTACTIVETEXTUREARBPROC                    glClientActiveTextureARB                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1DARBPROC                        glMultiTexCoord1dARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1DVARBPROC                       glMultiTexCoord1dvARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1FARBPROC                        glMultiTexCoord1fARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1FVARBPROC                       glMultiTexCoord1fvARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1IARBPROC                        glMultiTexCoord1iARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1IVARBPROC                       glMultiTexCoord1ivARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1SARBPROC                        glMultiTexCoord1sARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1SVARBPROC                       glMultiTexCoord1svARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2DARBPROC                        glMultiTexCoord2dARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2DVARBPROC                       glMultiTexCoord2dvARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2FARBPROC                        glMultiTexCoord2fARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2FVARBPROC                       glMultiTexCoord2fvARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2IARBPROC                        glMultiTexCoord2iARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2IVARBPROC                       glMultiTexCoord2ivARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2SARBPROC                        glMultiTexCoord2sARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2SVARBPROC                       glMultiTexCoord2svARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3DARBPROC                        glMultiTexCoord3dARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3DVARBPROC                       glMultiTexCoord3dvARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3FARBPROC                        glMultiTexCoord3fARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3FVARBPROC                       glMultiTexCoord3fvARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3IARBPROC                        glMultiTexCoord3iARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3IVARBPROC                       glMultiTexCoord3ivARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3SARBPROC                        glMultiTexCoord3sARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3SVARBPROC                       glMultiTexCoord3svARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4DARBPROC                        glMultiTexCoord4dARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4DVARBPROC                       glMultiTexCoord4dvARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4FARBPROC                        glMultiTexCoord4fARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4FVARBPROC                       glMultiTexCoord4fvARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4IARBPROC                        glMultiTexCoord4iARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4IVARBPROC                       glMultiTexCoord4ivARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4SARBPROC                        glMultiTexCoord4sARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4SVARBPROC                       glMultiTexCoord4svARB                                    GL_FUNC_DEF2     ;
#endif /* GL_ARB_multitexture */

#ifdef GL_ARB_occlusion_query
GL_FUNC_DEF  PFNGLGENQUERIESARBPROC                             glGenQueriesARB                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEQUERIESARBPROC                          glDeleteQueriesARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISQUERYARBPROC                                glIsQueryARB                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBEGINQUERYARBPROC                             glBeginQueryARB                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENDQUERYARBPROC                               glEndQueryARB                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETQUERYIVARBPROC                             glGetQueryivARB                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETQUERYOBJECTIVARBPROC                       glGetQueryObjectivARB                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETQUERYOBJECTUIVARBPROC                      glGetQueryObjectuivARB                                 GL_FUNC_DEF2     ;
#endif /* GL_ARB_occlusion_query */

#ifdef GL_ARB_parallel_shader_compile
GL_FUNC_DEF  PFNGLMAXSHADERCOMPILERTHREADSARBPROC               glMaxShaderCompilerThreadsARB                           GL_FUNC_DEF2     ;
#endif /* GL_ARB_parallel_shader_compile */

#ifdef GL_ARB_point_parameters
GL_FUNC_DEF  PFNGLPOINTPARAMETERFARBPROC                 		glPointParameterfARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOINTPARAMETERFVARBPROC                		glPointParameterfvARB                                      GL_FUNC_DEF2     ;
#endif /* GL_ARB_point_parameters */

#ifdef GL_ARB_robustness
GL_FUNC_DEF  PFNGLGETGRAPHICSRESETSTATUSARBPROC                    glGetGraphicsResetStatusARB                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNTEXIMAGEARBPROC                              glGetnTexImageARB                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREADNPIXELSARBPROC                               glReadnPixelsARB                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC                    glGetnCompressedTexImageARB                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNUNIFORMFVARBPROC                             glGetnUniformfvARB                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNUNIFORMIVARBPROC                             glGetnUniformivARB                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNUNIFORMUIVARBPROC                            glGetnUniformuivARB                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNUNIFORMDVARBPROC                             glGetnUniformdvARB                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNMAPDVARBPROC                                 glGetnMapdvARB                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNMAPFVARBPROC                                 glGetnMapfvARB                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNMAPIVARBPROC                                 glGetnMapivARB                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNPIXELMAPFVARBPROC                            glGetnPixelMapfvARB                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNPIXELMAPUIVARBPROC                           glGetnPixelMapuivARB                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNPIXELMAPUSVARBPROC                           glGetnPixelMapusvARB                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNPOLYGONSTIPPLEARBPROC                        glGetnPolygonStippleARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNCOLORTABLEARBPROC                            glGetnColorTableARB                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNCONVOLUTIONFILTERARBPROC                     glGetnConvolutionFilterARB                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNSEPARABLEFILTERARBPROC                       glGetnSeparableFilterARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNHISTOGRAMARBPROC                             glGetnHistogramARB                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNMINMAXARBPROC                                glGetnMinmaxARB                                              GL_FUNC_DEF2     ;
#endif /* GL_ARB_robustness */

#ifdef GL_ARB_sample_locations
GL_FUNC_DEF  PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC                        glFramebufferSampleLocationsfvARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC                   glNamedFramebufferSampleLocationsfvARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLEVALUATEDEPTHVALUESARBPROC                                 glEvaluateDepthValuesARB                                              GL_FUNC_DEF2     ;
#endif /* GL_ARB_sample_locations */

#ifdef GL_ARB_sample_shading
GL_FUNC_DEF  PFNGLMINSAMPLESHADINGARBPROC               glMinSampleShadingARB                           GL_FUNC_DEF2     ;
#endif /* GL_ARB_sample_shading */

#ifdef GL_ARB_shader_objects
GL_FUNC_DEF  PFNGLDELETEOBJECTARBPROC                              glDeleteObjectARB                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETHANDLEARBPROC                                 glGetHandleARB                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDETACHOBJECTARBPROC                              glDetachObjectARB                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATESHADEROBJECTARBPROC                        glCreateShaderObjectARB                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSHADERSOURCEARBPROC                              glShaderSourceARB                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPILESHADERARBPROC                             glCompileShaderARB                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATEPROGRAMOBJECTARBPROC                       glCreateProgramObjectARB                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLATTACHOBJECTARBPROC                              glAttachObjectARB                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLINKPROGRAMARBPROC                               glLinkProgramARB                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUSEPROGRAMOBJECTARBPROC                          glUseProgramObjectARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVALIDATEPROGRAMARBPROC                           glValidateProgramARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1FARBPROC                                 glUniform1fARB                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2FARBPROC                                 glUniform2fARB                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3FARBPROC                                 glUniform3fARB                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4FARBPROC                                 glUniform4fARB                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1IARBPROC                                 glUniform1iARB                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2IARBPROC                                 glUniform2iARB                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3IARBPROC                                 glUniform3iARB                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4IARBPROC                                 glUniform4iARB                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1FVARBPROC                                glUniform1fvARB                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2FVARBPROC                                glUniform2fvARB                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3FVARBPROC                                glUniform3fvARB                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4FVARBPROC                                glUniform4fvARB                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1IVARBPROC                                glUniform1ivARB                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2IVARBPROC                                glUniform2ivARB                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3IVARBPROC                                glUniform3ivARB                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4IVARBPROC                                glUniform4ivARB                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX2FVARBPROC                          glUniformMatrix2fvARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX3FVARBPROC                          glUniformMatrix3fvARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMMATRIX4FVARBPROC                          glUniformMatrix4fvARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETOBJECTPARAMETERFVARBPROC                      glGetObjectParameterfvARB                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETOBJECTPARAMETERIVARBPROC                      glGetObjectParameterivARB                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETINFOLOGARBPROC                                glGetInfoLogARB                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETATTACHEDOBJECTSARBPROC                        glGetAttachedObjectsARB                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNIFORMLOCATIONARBPROC                        glGetUniformLocationARB                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETACTIVEUNIFORMARBPROC                          glGetActiveUniformARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNIFORMFVARBPROC                              glGetUniformfvARB                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNIFORMIVARBPROC                              glGetUniformivARB                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSHADERSOURCEARBPROC                           glGetShaderSourceARB                                      GL_FUNC_DEF2     ;
#endif /* GL_ARB_shader_objects */

#ifdef GL_ARB_shading_language_include
GL_FUNC_DEF  PFNGLNAMEDSTRINGARBPROC                              glNamedStringARB                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETENAMEDSTRINGARBPROC                        glDeleteNamedStringARB                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPILESHADERINCLUDEARBPROC                     glCompileShaderIncludeARB                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISNAMEDSTRINGARBPROC                            glIsNamedStringARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNAMEDSTRINGARBPROC                           glGetNamedStringARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNAMEDSTRINGIVARBPROC                         glGetNamedStringivARB                                   GL_FUNC_DEF2     ;
#endif /* GL_ARB_shading_language_include */

#ifdef GL_ARB_sparse_buffer
GL_FUNC_DEF  PFNGLBUFFERPAGECOMMITMENTARBPROC                      glBufferPageCommitmentARB                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC                 glNamedBufferPageCommitmentEXT                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC                 glNamedBufferPageCommitmentARB                             GL_FUNC_DEF2     ;
#endif /* GL_ARB_sparse_buffer */

#ifdef GL_ARB_sparse_texture
GL_FUNC_DEF  PFNGLTEXPAGECOMMITMENTARBPROC               glTexPageCommitmentARB                           GL_FUNC_DEF2     ;
#endif /* GL_ARB_sparse_texture */

#ifdef GL_ARB_texture_buffer_object
GL_FUNC_DEF  PFNGLTEXBUFFERARBPROC               glTexBufferARB                           GL_FUNC_DEF2     ;
#endif /* GL_ARB_texture_buffer_object */

#ifdef GL_ARB_texture_compression
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXIMAGE3DARBPROC                      glCompressedTexImage3DARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXIMAGE2DARBPROC                      glCompressedTexImage2DARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXIMAGE1DARBPROC 	                  glCompressedTexImage1DARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC	                  glCompressedTexSubImage3DARB                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC	                  glCompressedTexSubImage2DARB                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC	                  glCompressedTexSubImage1DARB                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOMPRESSEDTEXIMAGEARBPROC  	                  glGetCompressedTexImageARB                               GL_FUNC_DEF2     ;
#endif /* GL_ARB_texture_compression */

#ifdef GL_ARB_transpose_matrix
GL_FUNC_DEF  PFNGLLOADTRANSPOSEMATRIXFARBPROC                 glLoadTransposeMatrixfARB                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLOADTRANSPOSEMATRIXDARBPROC                 glLoadTransposeMatrixdARB                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTTRANSPOSEMATRIXFARBPROC                 glMultTransposeMatrixfARB                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTTRANSPOSEMATRIXDARBPROC                 glMultTransposeMatrixdARB                               GL_FUNC_DEF2     ;
#endif /* GL_ARB_transpose_matrix */

#ifdef GL_ARB_vertex_blend
GL_FUNC_DEF  PFNGLWEIGHTBVARBPROC                         glWeightbvARB                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWEIGHTSVARBPROC                         glWeightsvARB                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWEIGHTIVARBPROC                         glWeightivARB                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWEIGHTFVARBPROC                         glWeightfvARB                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWEIGHTDVARBPROC                         glWeightdvARB                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWEIGHTUBVARBPROC                        glWeightubvARB                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWEIGHTUSVARBPROC                        glWeightusvARB                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWEIGHTUIVARBPROC                        glWeightuivARB                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWEIGHTPOINTERARBPROC                    glWeightPointerARB                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXBLENDARBPROC                      glVertexBlendARB                                GL_FUNC_DEF2     ;
#endif /* GL_ARB_vertex_blend */

#ifdef GL_ARB_vertex_buffer_object
GL_FUNC_DEF  PFNGLBINDBUFFERARBPROC                            glBindBufferARB                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEBUFFERSARBPROC                         glDeleteBuffersARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENBUFFERSARBPROC                            glGenBuffersARB                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISBUFFERARBPROC                              glIsBufferARB                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBUFFERDATAARBPROC                            glBufferDataARB                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBUFFERSUBDATAARBPROC                         glBufferSubDataARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETBUFFERSUBDATAARBPROC                      glGetBufferSubDataARB                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAPBUFFERARBPROC                             glMapBufferARB                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNMAPBUFFERARBPROC                           glUnmapBufferARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETBUFFERPARAMETERIVARBPROC                  glGetBufferParameterivARB                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETBUFFERPOINTERVARBPROC                     glGetBufferPointervARB                                 GL_FUNC_DEF2     ;
#endif /* GL_ARB_vertex_buffer_object */

#ifdef GL_ARB_vertex_program
GL_FUNC_DEF  PFNGLVERTEXATTRIB1DARBPROC                           glVertexAttrib1dARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1DVARBPROC                          glVertexAttrib1dvARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1FARBPROC                           glVertexAttrib1fARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1FVARBPROC                          glVertexAttrib1fvARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1SARBPROC                           glVertexAttrib1sARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1SVARBPROC                          glVertexAttrib1svARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2DARBPROC                           glVertexAttrib2dARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2DVARBPROC                          glVertexAttrib2dvARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2FARBPROC                           glVertexAttrib2fARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2FVARBPROC                          glVertexAttrib2fvARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2SARBPROC                           glVertexAttrib2sARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2SVARBPROC                          glVertexAttrib2svARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3DARBPROC                           glVertexAttrib3dARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3DVARBPROC                          glVertexAttrib3dvARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3FARBPROC                           glVertexAttrib3fARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3FVARBPROC                          glVertexAttrib3fvARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3SARBPROC                           glVertexAttrib3sARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3SVARBPROC                          glVertexAttrib3svARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4NBVARBPROC                         glVertexAttrib4NbvARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4NIVARBPROC                         glVertexAttrib4NivARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4NSVARBPROC                         glVertexAttrib4NsvARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4NUBARBPROC                         glVertexAttrib4NubARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4NUBVARBPROC                        glVertexAttrib4NubvARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4NUIVARBPROC                        glVertexAttrib4NuivARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4NUSVARBPROC                        glVertexAttrib4NusvARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4BVARBPROC                          glVertexAttrib4bvARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4DARBPROC                           glVertexAttrib4dARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4DVARBPROC                          glVertexAttrib4dvARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4FARBPROC                           glVertexAttrib4fARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4FVARBPROC                          glVertexAttrib4fvARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4IVARBPROC                          glVertexAttrib4ivARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4SARBPROC                           glVertexAttrib4sARB                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4SVARBPROC                          glVertexAttrib4svARB                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4UBVARBPROC                         glVertexAttrib4ubvARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4UIVARBPROC                         glVertexAttrib4uivARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4USVARBPROC                         glVertexAttrib4usvARB                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBPOINTERARBPROC                      glVertexAttribPointerARB                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENABLEVERTEXATTRIBARRAYARBPROC                  glEnableVertexAttribArrayARB                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDISABLEVERTEXATTRIBARRAYARBPROC                 glDisableVertexAttribArrayARB                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBDVARBPROC                        glGetVertexAttribdvARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBFVARBPROC                        glGetVertexAttribfvARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBIVARBPROC                        glGetVertexAttribivARB                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBPOINTERVARBPROC                  glGetVertexAttribPointervARB                              GL_FUNC_DEF2     ;
#endif /* GL_ARB_vertex_program */

#ifdef GL_ARB_vertex_shader
GL_FUNC_DEF  PFNGLBINDATTRIBLOCATIONARBPROC                    glBindAttribLocationARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETACTIVEATTRIBARBPROC                       glGetActiveAttribARB                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETATTRIBLOCATIONARBPROC                     glGetAttribLocationARB                                 GL_FUNC_DEF2     ;
#endif /* GL_ARB_vertex_shader */

#ifdef GL_ARB_window_pos
GL_FUNC_DEF  PFNGLWINDOWPOS2DARBPROC                    glWindowPos2dARB                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2DVARBPROC                   glWindowPos2dvARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2FARBPROC                    glWindowPos2fARB                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2FVARBPROC                   glWindowPos2fvARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2IARBPROC                    glWindowPos2iARB                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2IVARBPROC                   glWindowPos2ivARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2SARBPROC                    glWindowPos2sARB                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2SVARBPROC                   glWindowPos2svARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3DARBPROC                    glWindowPos3dARB                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3DVARBPROC                   glWindowPos3dvARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3FARBPROC                    glWindowPos3fARB                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3FVARBPROC                   glWindowPos3fvARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3IARBPROC                    glWindowPos3iARB                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3IVARBPROC                   glWindowPos3ivARB                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3SARBPROC                    glWindowPos3sARB                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3SVARBPROC                   glWindowPos3svARB                                GL_FUNC_DEF2     ;
#endif /* GL_ARB_window_pos */



#ifdef GL_KHR_blend_equation_advanced
GL_FUNC_DEF  PFNGLBLENDBARRIERKHRPROC                             glBlendBarrierKHR                            GL_FUNC_DEF2     ;
#endif /* GL_KHR_blend_equation_advanced */

#ifdef GL_KHR_parallel_shader_compile
GL_FUNC_DEF  PFNGLMAXSHADERCOMPILERTHREADSKHRPROC                      glMaxShaderCompilerThreadsKHR                           GL_FUNC_DEF2     ;
#endif /* GL_KHR_parallel_shader_compile */



#ifdef GL_OES_byte_coordinates
GL_FUNC_DEF  PFNGLMULTITEXCOORD1BOESPROC                     glMultiTexCoord1bOES                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1BVOESPROC                    glMultiTexCoord1bvOES                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2BOESPROC                     glMultiTexCoord2bOES                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2BVOESPROC                    glMultiTexCoord2bvOES                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3BOESPROC                     glMultiTexCoord3bOES                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3BVOESPROC                    glMultiTexCoord3bvOES                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4BOESPROC                     glMultiTexCoord4bOES                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4BVOESPROC                    glMultiTexCoord4bvOES                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD1BOESPROC                          glTexCoord1bOES                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD1BVOESPROC                         glTexCoord1bvOES                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD2BOESPROC                          glTexCoord2bOES                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD2BVOESPROC                         glTexCoord2bvOES                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD3BOESPROC                          glTexCoord3bOES                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD3BVOESPROC                         glTexCoord3bvOES                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD4BOESPROC                          glTexCoord4bOES                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD4BVOESPROC                         glTexCoord4bvOES                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEX2BOESPROC                            glVertex2bOES                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEX2BVOESPROC                           glVertex2bvOES                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEX3BOESPROC                            glVertex3bOES                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEX3BVOESPROC                           glVertex3bvOES                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEX4BOESPROC                            glVertex4bOES                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEX4BVOESPROC                           glVertex4bvOES                                        GL_FUNC_DEF2     ;
#endif /* GL_OES_byte_coordinates */

#ifdef GL_OES_fixed_point
GL_FUNC_DEF  PFNGLALPHAFUNCXOESPROC                                glAlphaFuncxOES                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARCOLORXOESPROC                               glClearColorxOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARDEPTHXOESPROC                               glClearDepthxOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLIPPLANEXOESPROC                                glClipPlanexOES                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLOR4XOESPROC                                   glColor4xOES                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEPTHRANGEXOESPROC                               glDepthRangexOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFOGXOESPROC                                      glFogxOES                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFOGXVOESPROC                                     glFogxvOES                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRUSTUMXOESPROC                                  glFrustumxOES                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCLIPPLANEXOESPROC                             glGetClipPlanexOES                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFIXEDVOESPROC                                 glGetFixedvOES                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXENVXVOESPROC                               glGetTexEnvxvOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXPARAMETERXVOESPROC                         glGetTexParameterxvOES                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLIGHTMODELXOESPROC                               glLightModelxOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLIGHTMODELXVOESPROC                              glLightModelxvOES                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLIGHTXOESPROC                                    glLightxOES                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLIGHTXVOESPROC                                   glLightxvOES                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLINEWIDTHXOESPROC                                glLineWidthxOES                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLOADMATRIXXOESPROC                               glLoadMatrixxOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATERIALXOESPROC                                 glMaterialxOES                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATERIALXVOESPROC                                glMaterialxvOES                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTMATRIXXOESPROC                               glMultMatrixxOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4XOESPROC                           glMultiTexCoord4xOES                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMAL3XOESPROC                                  glNormal3xOES                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLORTHOXOESPROC                                    glOrthoxOES                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOINTPARAMETERXVOESPROC                          glPointParameterxvOES                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOINTSIZEXOESPROC                                glPointSizexOES                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOLYGONOFFSETXOESPROC                            glPolygonOffsetxOES                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLROTATEXOESPROC                                   glRotatexOES                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSCALEXOESPROC                                    glScalexOES                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXENVXOESPROC                                   glTexEnvxOES                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXENVXVOESPROC                                  glTexEnvxvOES                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXPARAMETERXOESPROC                             glTexParameterxOES                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXPARAMETERXVOESPROC                            glTexParameterxvOES                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTRANSLATEXOESPROC                                glTranslatexOES                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLACCUMXOESPROC                                    glAccumxOES                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBITMAPXOESPROC                                   glBitmapxOES                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBLENDCOLORXOESPROC                               glBlendColorxOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARACCUMXOESPROC                               glClearAccumxOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLOR3XOESPROC                                   glColor3xOES                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLOR3XVOESPROC                                  glColor3xvOES                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLOR4XVOESPROC                                  glColor4xvOES                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCONVOLUTIONPARAMETERXOESPROC                     glConvolutionParameterxOES                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCONVOLUTIONPARAMETERXVOESPROC                    glConvolutionParameterxvOES                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLEVALCOORD1XOESPROC                               glEvalCoord1xOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLEVALCOORD1XVOESPROC                              glEvalCoord1xvOES                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLEVALCOORD2XOESPROC                               glEvalCoord2xOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLEVALCOORD2XVOESPROC                              glEvalCoord2xvOES                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFEEDBACKBUFFERXOESPROC                           glFeedbackBufferxOES                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCONVOLUTIONPARAMETERXVOESPROC                 glGetConvolutionParameterxvOES                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETHISTOGRAMPARAMETERXVOESPROC                   glGetHistogramParameterxvOES                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETLIGHTXOESPROC                                 glGetLightxOES                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMAPXVOESPROC                                  glGetMapxvOES                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMATERIALXOESPROC                              glGetMaterialxOES                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPIXELMAPXVPROC                                glGetPixelMapxv                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXGENXVOESPROC                               glGetTexGenxvOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXLEVELPARAMETERXVOESPROC                    glGetTexLevelParameterxvOES                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLINDEXXOESPROC                                    glIndexxOES                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLINDEXXVOESPROC                                   glIndexxvOES                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLOADTRANSPOSEMATRIXXOESPROC                      glLoadTransposeMatrixxOES                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAP1XOESPROC                                     glMap1xOES                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAP2XOESPROC                                     glMap2xOES                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAPGRID1XOESPROC                                 glMapGrid1xOES                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAPGRID2XOESPROC                                 glMapGrid2xOES                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTTRANSPOSEMATRIXXOESPROC                      glMultTransposeMatrixxOES                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1XOESPROC                           glMultiTexCoord1xOES                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1XVOESPROC                          glMultiTexCoord1xvOES                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2XOESPROC                           glMultiTexCoord2xOES                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2XVOESPROC                          glMultiTexCoord2xvOES                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3XOESPROC                           glMultiTexCoord3xOES                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3XVOESPROC                          glMultiTexCoord3xvOES                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4XVOESPROC                          glMultiTexCoord4xvOES                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMAL3XVOESPROC                                 glNormal3xvOES                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPASSTHROUGHXOESPROC                              glPassThroughxOES                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPIXELMAPXPROC                                    glPixelMapx                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPIXELSTOREXPROC                                  glPixelStorex                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPIXELTRANSFERXOESPROC                            glPixelTransferxOES                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPIXELZOOMXOESPROC                                glPixelZoomxOES                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPRIORITIZETEXTURESXOESPROC                       glPrioritizeTexturesxOES                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRASTERPOS2XOESPROC                               glRasterPos2xOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRASTERPOS2XVOESPROC                              glRasterPos2xvOES                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRASTERPOS3XOESPROC                               glRasterPos3xOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRASTERPOS3XVOESPROC                              glRasterPos3xvOES                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRASTERPOS4XOESPROC                               glRasterPos4xOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRASTERPOS4XVOESPROC                              glRasterPos4xvOES                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRECTXOESPROC                                     glRectxOES                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRECTXVOESPROC                                    glRectxvOES                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD1XOESPROC                                glTexCoord1xOES                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD1XVOESPROC                               glTexCoord1xvOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD2XOESPROC                                glTexCoord2xOES                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD2XVOESPROC                               glTexCoord2xvOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD3XOESPROC                                glTexCoord3xOES                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD3XVOESPROC                               glTexCoord3xvOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD4XOESPROC                                glTexCoord4xOES                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD4XVOESPROC                               glTexCoord4xvOES                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXGENXOESPROC                                   glTexGenxOES                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXGENXVOESPROC                                  glTexGenxvOES                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEX2XOESPROC                                  glVertex2xOES                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEX2XVOESPROC                                 glVertex2xvOES                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEX3XOESPROC                                  glVertex3xOES                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEX3XVOESPROC                                 glVertex3xvOES                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEX4XOESPROC                                  glVertex4xOES                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEX4XVOESPROC                                 glVertex4xvOES                                              GL_FUNC_DEF2     ;
#endif /* GL_OES_fixed_point */

#ifdef GL_OES_query_matrix
GL_FUNC_DEF  PFNGLQUERYMATRIXXOESPROC                      glQueryMatrixxOES                           GL_FUNC_DEF2     ;
#endif /* GL_OES_query_matrix */

#ifdef GL_OES_single_precision
GL_FUNC_DEF  PFNGLCLEARDEPTHFOESPROC                       glClearDepthfOES                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLIPPLANEFOESPROC                        glClipPlanefOES                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEPTHRANGEFOESPROC                       glDepthRangefOES                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRUSTUMFOESPROC                          glFrustumfOES                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCLIPPLANEFOESPROC                     glGetClipPlanefOES                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLORTHOFOESPROC                            glOrthofOES                                          GL_FUNC_DEF2     ;
#endif /* GL_OES_single_precision */



#ifdef GL_3DFX_tbuffer
GL_FUNC_DEF  PFNGLTBUFFERMASK3DFXPROC                      glTbufferMask3DFX                           GL_FUNC_DEF2     ;
#endif /* GL_3DFX_tbuffer */



#ifdef GL_AMD_debug_output
GL_FUNC_DEF  PFNGLDEBUGMESSAGEENABLEAMDPROC                        glDebugMessageEnableAMD                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEBUGMESSAGEINSERTAMDPROC                        glDebugMessageInsertAMD                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEBUGMESSAGECALLBACKAMDPROC                      glDebugMessageCallbackAMD                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETDEBUGMESSAGELOGAMDPROC                        glGetDebugMessageLogAMD                                    GL_FUNC_DEF2     ;
#endif /* GL_AMD_debug_output */

#ifdef GL_AMD_draw_buffers_blend
GL_FUNC_DEF  PFNGLBLENDFUNCINDEXEDAMDPROC                               glBlendFuncIndexedAMD                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC                       glBlendFuncSeparateIndexedAMD                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBLENDEQUATIONINDEXEDAMDPROC                           glBlendEquationIndexedAMD                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC                   glBlendEquationSeparateIndexedAMD                               GL_FUNC_DEF2     ;
#endif /* GL_AMD_draw_buffers_blend */

#ifdef GL_AMD_framebuffer_sample_positions
GL_FUNC_DEF  PFNGLFRAMEBUFFERSAMPLEPOSITIONSFVAMDPROC                       glFramebufferSamplePositionsfvAMD                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERSAMPLEPOSITIONSFVAMDPROC                  glNamedFramebufferSamplePositionsfvAMD                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFRAMEBUFFERPARAMETERFVAMDPROC                          glGetFramebufferParameterfvAMD                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNAMEDFRAMEBUFFERPARAMETERFVAMDPROC                     glGetNamedFramebufferParameterfvAMD                                   GL_FUNC_DEF2     ;
#endif /* GL_AMD_framebuffer_sample_positions */

#ifdef GL_AMD_gpu_shader_int64
GL_FUNC_DEF  PFNGLUNIFORM1I64NVPROC                               glUniform1i64NV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2I64NVPROC                               glUniform2i64NV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3I64NVPROC                               glUniform3i64NV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4I64NVPROC                               glUniform4i64NV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1I64VNVPROC                              glUniform1i64vNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2I64VNVPROC                              glUniform2i64vNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3I64VNVPROC                              glUniform3i64vNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4I64VNVPROC                              glUniform4i64vNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1UI64NVPROC                              glUniform1ui64NV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2UI64NVPROC                              glUniform2ui64NV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3UI64NVPROC                              glUniform3ui64NV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4UI64NVPROC                              glUniform4ui64NV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1UI64VNVPROC                             glUniform1ui64vNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2UI64VNVPROC                             glUniform2ui64vNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3UI64VNVPROC                             glUniform3ui64vNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4UI64VNVPROC                             glUniform4ui64vNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNIFORMI64VNVPROC                            glGetUniformi64vNV                                       GL_FUNC_DEF2     ;
// GL_FUNC_DEF  PFNGLGETUNIFORMUI64VNVPROC                           glGetUniformui64vNV                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1I64NVPROC                        glProgramUniform1i64NV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2I64NVPROC                        glProgramUniform2i64NV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3I64NVPROC                        glProgramUniform3i64NV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4I64NVPROC                        glProgramUniform4i64NV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1I64VNVPROC                       glProgramUniform1i64vNV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2I64VNVPROC                       glProgramUniform2i64vNV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3I64VNVPROC                       glProgramUniform3i64vNV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4I64VNVPROC                       glProgramUniform4i64vNV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1UI64NVPROC                       glProgramUniform1ui64NV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2UI64NVPROC                       glProgramUniform2ui64NV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3UI64NVPROC                       glProgramUniform3ui64NV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4UI64NVPROC                       glProgramUniform4ui64NV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1UI64VNVPROC                      glProgramUniform1ui64vNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2UI64VNVPROC                      glProgramUniform2ui64vNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3UI64VNVPROC                      glProgramUniform3ui64vNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4UI64VNVPROC                      glProgramUniform4ui64vNV                                 GL_FUNC_DEF2     ;
#endif /* GL_AMD_gpu_shader_int64 */

#ifdef GL_AMD_interleaved_elements
GL_FUNC_DEF  PFNGLVERTEXATTRIBPARAMETERIAMDPROC                    glVertexAttribParameteriAMD                           GL_FUNC_DEF2     ;
#endif /* GL_AMD_interleaved_elements */

#ifdef GL_AMD_multi_draw_indirect
GL_FUNC_DEF  PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC                   glMultiDrawArraysIndirectAMD                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC                 glMultiDrawElementsIndirectAMD                            GL_FUNC_DEF2     ;
#endif /* GL_AMD_multi_draw_indirect */

#ifdef GL_AMD_name_gen_delete
GL_FUNC_DEF  PFNGLGENNAMESAMDPROC                   glGenNamesAMD                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETENAMESAMDPROC                glDeleteNamesAMD                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISNAMEAMDPROC                     glIsNameAMD                                   GL_FUNC_DEF2     ;
	#endif /* GL_AMD_name_gen_delete */

#ifdef GL_AMD_occlusion_query_event
GL_FUNC_DEF  PFNGLQUERYOBJECTPARAMETERUIAMDPROC                 glQueryObjectParameteruiAMD                           GL_FUNC_DEF2     ;
#endif /* GL_AMD_occlusion_query_event */

#ifdef GL_AMD_performance_monitor
GL_FUNC_DEF  PFNGLGETPERFMONITORGROUPSAMDPROC                            glGetPerfMonitorGroupsAMD                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPERFMONITORCOUNTERSAMDPROC                          glGetPerfMonitorCountersAMD                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPERFMONITORGROUPSTRINGAMDPROC                       glGetPerfMonitorGroupStringAMD                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC                     glGetPerfMonitorCounterStringAMD                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPERFMONITORCOUNTERINFOAMDPROC                       glGetPerfMonitorCounterInfoAMD                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENPERFMONITORSAMDPROC                                 glGenPerfMonitorsAMD                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEPERFMONITORSAMDPROC                              glDeletePerfMonitorsAMD                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSELECTPERFMONITORCOUNTERSAMDPROC                       glSelectPerfMonitorCountersAMD                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBEGINPERFMONITORAMDPROC                                glBeginPerfMonitorAMD                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENDPERFMONITORAMDPROC                                  glEndPerfMonitorAMD                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPERFMONITORCOUNTERDATAAMDPROC                       glGetPerfMonitorCounterDataAMD                                  GL_FUNC_DEF2     ;
#endif /* GL_AMD_performance_monitor */

#ifdef GL_AMD_sample_positions
GL_FUNC_DEF  PFNGLSETMULTISAMPLEFVAMDPROC                      glSetMultisamplefvAMD                           GL_FUNC_DEF2     ;
#endif /* GL_AMD_sample_positions */

#ifdef GL_AMD_sparse_texture
GL_FUNC_DEF  PFNGLTEXSTORAGESPARSEAMDPROC                      glTexStorageSparseAMD                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESTORAGESPARSEAMDPROC                  glTextureStorageSparseAMD                            GL_FUNC_DEF2     ;
#endif /* GL_AMD_sparse_texture */

#ifdef GL_AMD_stencil_operation_extended
GL_FUNC_DEF  PFNGLSTENCILOPVALUEAMDPROC                   glStencilOpValueAMD                           GL_FUNC_DEF2     ;
#endif /* GL_AMD_stencil_operation_extended */

#ifdef GL_AMD_vertex_shader_tessellator
GL_FUNC_DEF  PFNGLTESSELLATIONFACTORAMDPROC                glTessellationFactorAMD                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTESSELLATIONMODEAMDPROC                  glTessellationModeAMD                             GL_FUNC_DEF2     ;
#endif /* GL_AMD_vertex_shader_tessellator */



#ifdef GL_APPLE_element_array
GL_FUNC_DEF  PFNGLELEMENTPOINTERAPPLEPROC                               glElementPointerAPPLE                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWELEMENTARRAYAPPLEPROC                             glDrawElementArrayAPPLE                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC                        glDrawRangeElementArrayAPPLE                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC                        glMultiDrawElementArrayAPPLE                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC                   glMultiDrawRangeElementArrayAPPLE                                GL_FUNC_DEF2     ;
#endif /* GL_APPLE_element_array */

#ifdef GL_APPLE_fence
GL_FUNC_DEF  PFNGLGENFENCESAPPLEPROC                       glGenFencesAPPLE                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEFENCESAPPLEPROC                    glDeleteFencesAPPLE                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSETFENCEAPPLEPROC                        glSetFenceAPPLE                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISFENCEAPPLEPROC                         glIsFenceAPPLE                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTESTFENCEAPPLEPROC                       glTestFenceAPPLE                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFINISHFENCEAPPLEPROC                     glFinishFenceAPPLE                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTESTOBJECTAPPLEPROC                      glTestObjectAPPLE                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFINISHOBJECTAPPLEPROC                    glFinishObjectAPPLE                                 GL_FUNC_DEF2     ;
#endif /* GL_APPLE_fence */

#ifdef GL_APPLE_flush_buffer_range
GL_FUNC_DEF  PFNGLBUFFERPARAMETERIAPPLEPROC                      glBufferParameteriAPPLE                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC                glFlushMappedBufferRangeAPPLE                             GL_FUNC_DEF2     ;
#endif /* GL_APPLE_flush_buffer_range */

#ifdef GL_APPLE_object_purgeable
GL_FUNC_DEF  PFNGLOBJECTPURGEABLEAPPLEPROC                      glObjectPurgeableAPPLE                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLOBJECTUNPURGEABLEAPPLEPROC                    glObjectUnpurgeableAPPLE                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETOBJECTPARAMETERIVAPPLEPROC                 glGetObjectParameterivAPPLE                            GL_FUNC_DEF2     ;
#endif /* GL_APPLE_object_purgeable */

#ifdef GL_APPLE_texture_range
GL_FUNC_DEF  PFNGLTEXTURERANGEAPPLEPROC                             glTextureRangeAPPLE                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC                  glGetTexParameterPointervAPPLE                            GL_FUNC_DEF2     ;
	#endif /* GL_APPLE_texture_range */

#ifdef GL_APPLE_vertex_array_object
GL_FUNC_DEF  PFNGLBINDVERTEXARRAYAPPLEPROC                      glBindVertexArrayAPPLE                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEVERTEXARRAYSAPPLEPROC                   glDeleteVertexArraysAPPLE                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENVERTEXARRAYSAPPLEPROC                      glGenVertexArraysAPPLE                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISVERTEXARRAYAPPLEPROC                        glIsVertexArrayAPPLE                                    GL_FUNC_DEF2     ;
#endif /* GL_APPLE_vertex_array_object */

#ifdef GL_APPLE_vertex_array_range
GL_FUNC_DEF  PFNGLVERTEXARRAYRANGEAPPLEPROC                        glVertexArrayRangeAPPLE                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC                   glFlushVertexArrayRangeAPPLE                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYPARAMETERIAPPLEPROC                   glVertexArrayParameteriAPPLE                               GL_FUNC_DEF2     ;
#endif /* GL_APPLE_vertex_array_range */

#ifdef GL_APPLE_vertex_program_evaluators
GL_FUNC_DEF  PFNGLENABLEVERTEXATTRIBAPPLEPROC                      glEnableVertexAttribAPPLE                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDISABLEVERTEXATTRIBAPPLEPROC                     glDisableVertexAttribAPPLE                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISVERTEXATTRIBENABLEDAPPLEPROC                   glIsVertexAttribEnabledAPPLE                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAPVERTEXATTRIB1DAPPLEPROC                       glMapVertexAttrib1dAPPLE                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAPVERTEXATTRIB1FAPPLEPROC                       glMapVertexAttrib1fAPPLE                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAPVERTEXATTRIB2DAPPLEPROC                       glMapVertexAttrib2dAPPLE                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAPVERTEXATTRIB2FAPPLEPROC                       glMapVertexAttrib2fAPPLE                                  GL_FUNC_DEF2     ;
#endif /* GL_APPLE_vertex_program_evaluators */



#ifdef GL_ATI_draw_buffers
GL_FUNC_DEF  PFNGLDRAWBUFFERSATIPROC                          glDrawBuffersATI                           GL_FUNC_DEF2     ;
#endif /* GL_ATI_draw_buffers */

#ifdef GL_ATI_element_array
GL_FUNC_DEF  PFNGLELEMENTPOINTERATIPROC                       glElementPointerATI                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWELEMENTARRAYATIPROC                     glDrawElementArrayATI                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWRANGEELEMENTARRAYATIPROC                glDrawRangeElementArrayATI                             GL_FUNC_DEF2     ;
#endif /* GL_ATI_element_array */

#ifdef GL_ATI_envmap_bumpmap
GL_FUNC_DEF  PFNGLTEXBUMPPARAMETERIVATIPROC                   glTexBumpParameterivATI                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXBUMPPARAMETERFVATIPROC                   glTexBumpParameterfvATI                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXBUMPPARAMETERIVATIPROC                glGetTexBumpParameterivATI                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXBUMPPARAMETERFVATIPROC                glGetTexBumpParameterfvATI                                 GL_FUNC_DEF2     ;
#endif /* GL_ATI_envmap_bumpmap */

#ifdef GL_ATI_fragment_shader
GL_FUNC_DEF  PFNGLGENFRAGMENTSHADERSATIPROC                            glGenFragmentShadersATI                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDFRAGMENTSHADERATIPROC                            glBindFragmentShaderATI                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEFRAGMENTSHADERATIPROC                          glDeleteFragmentShaderATI                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBEGINFRAGMENTSHADERATIPROC                           glBeginFragmentShaderATI                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENDFRAGMENTSHADERATIPROC                             glEndFragmentShaderATI                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPASSTEXCOORDATIPROC                                  glPassTexCoordATI                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSAMPLEMAPATIPROC                                     glSampleMapATI                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLORFRAGMENTOP1ATIPROC                              glColorFragmentOp1ATI                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLORFRAGMENTOP2ATIPROC                              glColorFragmentOp2ATI                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLORFRAGMENTOP3ATIPROC                              glColorFragmentOp3ATI                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLALPHAFRAGMENTOP1ATIPROC                              glAlphaFragmentOp1ATI                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLALPHAFRAGMENTOP2ATIPROC                              glAlphaFragmentOp2ATI                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLALPHAFRAGMENTOP3ATIPROC                              glAlphaFragmentOp3ATI                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSETFRAGMENTSHADERCONSTANTATIPROC                     glSetFragmentShaderConstantATI                                   GL_FUNC_DEF2     ;
#endif /* GL_ATI_fragment_shader */

#ifdef GL_ATI_map_object_buffer
GL_FUNC_DEF  PFNGLMAPOBJECTBUFFERATIPROC                      glMapObjectBufferATI                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNMAPOBJECTBUFFERATIPROC                    glUnmapObjectBufferATI                             GL_FUNC_DEF2     ;
#endif /* GL_ATI_map_object_buffer */

#ifdef GL_ATI_pn_triangles
GL_FUNC_DEF  PFNGLPNTRIANGLESIATIPROC                         glPNTrianglesiATI                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPNTRIANGLESFATIPROC                         glPNTrianglesfATI                             GL_FUNC_DEF2     ;
#endif /* GL_ATI_pn_triangles */

#ifdef GL_ATI_separate_stencil
GL_FUNC_DEF  PFNGLSTENCILOPSEPARATEATIPROC                    glStencilOpSeparateATI                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTENCILFUNCSEPARATEATIPROC                  glStencilFuncSeparateATI                           GL_FUNC_DEF2     ;
#endif /* GL_ATI_separate_stencil */

#ifdef GL_ATI_vertex_array_object
GL_FUNC_DEF  PFNGLNEWOBJECTBUFFERATIPROC                            glNewObjectBufferATI                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISOBJECTBUFFERATIPROC                             glIsObjectBufferATI                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUPDATEOBJECTBUFFERATIPROC                         glUpdateObjectBufferATI                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETOBJECTBUFFERFVATIPROC                          glGetObjectBufferfvATI                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETOBJECTBUFFERIVATIPROC                          glGetObjectBufferivATI                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFREEOBJECTBUFFERATIPROC                           glFreeObjectBufferATI                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLARRAYOBJECTATIPROC                                glArrayObjectATI                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETARRAYOBJECTFVATIPROC                           glGetArrayObjectfvATI                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETARRAYOBJECTIVATIPROC                           glGetArrayObjectivATI                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVARIANTARRAYOBJECTATIPROC                         glVariantArrayObjectATI                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVARIANTARRAYOBJECTFVATIPROC                    glGetVariantArrayObjectfvATI                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVARIANTARRAYOBJECTIVATIPROC                    glGetVariantArrayObjectivATI                                 GL_FUNC_DEF2     ;
#endif /* GL_ATI_vertex_array_object */

#ifdef GL_ATI_vertex_attrib_array_object
GL_FUNC_DEF  PFNGLVERTEXATTRIBARRAYOBJECTATIPROC                            glVertexAttribArrayObjectATI                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC                       glGetVertexAttribArrayObjectfvATI                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC                       glGetVertexAttribArrayObjectivATI                             GL_FUNC_DEF2     ;
#endif /* GL_ATI_vertex_attrib_array_object */

#ifdef GL_ATI_vertex_streams
GL_FUNC_DEF  PFNGLVERTEXSTREAM1SATIPROC                                   glVertexStream1sATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM1SVATIPROC                                  glVertexStream1svATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM1IATIPROC                                   glVertexStream1iATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM1IVATIPROC                                  glVertexStream1ivATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM1FATIPROC                                   glVertexStream1fATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM1FVATIPROC                                  glVertexStream1fvATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM1DATIPROC                                   glVertexStream1dATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM1DVATIPROC                                  glVertexStream1dvATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM2SATIPROC                                   glVertexStream2sATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM2SVATIPROC                                  glVertexStream2svATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM2IATIPROC                                   glVertexStream2iATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM2IVATIPROC                                  glVertexStream2ivATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM2FATIPROC                                   glVertexStream2fATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM2FVATIPROC                                  glVertexStream2fvATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM2DATIPROC                                   glVertexStream2dATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM2DVATIPROC                                  glVertexStream2dvATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM3SATIPROC                                   glVertexStream3sATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM3SVATIPROC                                  glVertexStream3svATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM3IATIPROC                                   glVertexStream3iATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM3IVATIPROC                                  glVertexStream3ivATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM3FATIPROC                                   glVertexStream3fATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM3FVATIPROC                                  glVertexStream3fvATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM3DATIPROC                                   glVertexStream3dATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM3DVATIPROC                                  glVertexStream3dvATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM4SATIPROC                                   glVertexStream4sATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM4SVATIPROC                                  glVertexStream4svATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM4IATIPROC                                   glVertexStream4iATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM4IVATIPROC                                  glVertexStream4ivATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM4FATIPROC                                   glVertexStream4fATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM4FVATIPROC                                  glVertexStream4fvATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM4DATIPROC                                   glVertexStream4dATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXSTREAM4DVATIPROC                                  glVertexStream4dvATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMALSTREAM3BATIPROC                                   glNormalStream3bATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMALSTREAM3BVATIPROC                                  glNormalStream3bvATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMALSTREAM3SATIPROC                                   glNormalStream3sATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMALSTREAM3SVATIPROC                                  glNormalStream3svATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMALSTREAM3IATIPROC                                   glNormalStream3iATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMALSTREAM3IVATIPROC                                  glNormalStream3ivATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMALSTREAM3FATIPROC                                   glNormalStream3fATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMALSTREAM3FVATIPROC                                  glNormalStream3fvATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMALSTREAM3DATIPROC                                   glNormalStream3dATI                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMALSTREAM3DVATIPROC                                  glNormalStream3dvATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC                         glClientActiveVertexStreamATI                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXBLENDENVIATIPROC                                  glVertexBlendEnviATI                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXBLENDENVFATIPROC                                  glVertexBlendEnvfATI                                              GL_FUNC_DEF2     ;
#endif /* GL_ATI_vertex_streams */



#ifdef GL_EXT_bindable_uniform
GL_FUNC_DEF  PFNGLUNIFORMBUFFEREXTPROC                           glUniformBufferEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNIFORMBUFFERSIZEEXTPROC                    glGetUniformBufferSizeEXT                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNIFORMOFFSETEXTPROC                        glGetUniformOffsetEXT                                   GL_FUNC_DEF2     ;
#endif /* GL_EXT_bindable_uniform */

#ifdef GL_EXT_blend_color
GL_FUNC_DEF  PFNGLBLENDCOLOREXTPROC                   glBlendColorEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_blend_color */

#ifdef GL_EXT_blend_equation_separate
GL_FUNC_DEF  PFNGLBLENDEQUATIONSEPARATEEXTPROC               glBlendEquationSeparateEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_blend_equation_separate */

#ifdef GL_EXT_blend_func_separate
GL_FUNC_DEF  PFNGLBLENDFUNCSEPARATEEXTPROC               glBlendFuncSeparateEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_blend_func_separate */

#ifdef GL_EXT_blend_minmax
GL_FUNC_DEF  PFNGLBLENDEQUATIONEXTPROC               glBlendEquationEXT                            GL_FUNC_DEF2     ;
#endif /* GL_EXT_blend_minmax */

#ifdef GL_EXT_color_subtable
GL_FUNC_DEF  PFNGLCOLORSUBTABLEEXTPROC                    glColorSubTableEXT                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYCOLORSUBTABLEEXTPROC                glCopyColorSubTableEXT                             GL_FUNC_DEF2     ;
#endif /* GL_EXT_color_subtable */

#ifdef GL_EXT_compiled_vertex_array
GL_FUNC_DEF  PFNGLLOCKARRAYSEXTPROC                  glLockArraysEXT                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNLOCKARRAYSEXTPROC                glUnlockArraysEXT                             GL_FUNC_DEF2     ;
#endif /* GL_EXT_compiled_vertex_array */

#ifdef GL_EXT_convolution
GL_FUNC_DEF  PFNGLCONVOLUTIONFILTER1DEXTPROC                         glConvolutionFilter1DEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCONVOLUTIONFILTER2DEXTPROC                         glConvolutionFilter2DEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCONVOLUTIONPARAMETERFEXTPROC                       glConvolutionParameterfEXT                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCONVOLUTIONPARAMETERFVEXTPROC                      glConvolutionParameterfvEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCONVOLUTIONPARAMETERIEXTPROC                       glConvolutionParameteriEXT                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCONVOLUTIONPARAMETERIVEXTPROC                      glConvolutionParameterivEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC                     glCopyConvolutionFilter1DEXT                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC                     glCopyConvolutionFilter2DEXT                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCONVOLUTIONFILTEREXTPROC                        glGetConvolutionFilterEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC                   glGetConvolutionParameterfvEXT                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC                   glGetConvolutionParameterivEXT                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSEPARABLEFILTEREXTPROC                          glGetSeparableFilterEXT                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSEPARABLEFILTER2DEXTPROC                           glSeparableFilter2DEXT                                         GL_FUNC_DEF2     ;
#endif /* GL_EXT_convolution */

#ifdef GL_EXT_coordinate_frame
GL_FUNC_DEF  PFNGLTANGENT3BEXTPROC                          glTangent3bEXT                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTANGENT3BVEXTPROC                         glTangent3bvEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTANGENT3DEXTPROC                          glTangent3dEXT                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTANGENT3DVEXTPROC                         glTangent3dvEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTANGENT3FEXTPROC                          glTangent3fEXT                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTANGENT3FVEXTPROC                         glTangent3fvEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTANGENT3IEXTPROC                          glTangent3iEXT                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTANGENT3IVEXTPROC                         glTangent3ivEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTANGENT3SEXTPROC                          glTangent3sEXT                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTANGENT3SVEXTPROC                         glTangent3svEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINORMAL3BEXTPROC                         glBinormal3bEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINORMAL3BVEXTPROC                        glBinormal3bvEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINORMAL3DEXTPROC                         glBinormal3dEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINORMAL3DVEXTPROC                        glBinormal3dvEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINORMAL3FEXTPROC                         glBinormal3fEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINORMAL3FVEXTPROC                        glBinormal3fvEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINORMAL3IEXTPROC                         glBinormal3iEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINORMAL3IVEXTPROC                        glBinormal3ivEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINORMAL3SEXTPROC                         glBinormal3sEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINORMAL3SVEXTPROC                        glBinormal3svEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTANGENTPOINTEREXTPROC                     glTangentPointerEXT                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINORMALPOINTEREXTPROC                    glBinormalPointerEXT                                  GL_FUNC_DEF2     ;
#endif /* GL_EXT_coordinate_frame */

#ifdef GL_EXT_copy_texture
GL_FUNC_DEF  PFNGLCOPYTEXIMAGE1DEXTPROC                   glCopyTexImage1DEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYTEXIMAGE2DEXTPROC                   glCopyTexImage2DEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYTEXSUBIMAGE1DEXTPROC                glCopyTexSubImage1DEXT                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYTEXSUBIMAGE2DEXTPROC                glCopyTexSubImage2DEXT                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYTEXSUBIMAGE3DEXTPROC                glCopyTexSubImage3DEXT                                 GL_FUNC_DEF2     ;
#endif /* GL_EXT_copy_texture */

#ifdef GL_EXT_cull_vertex
GL_FUNC_DEF  PFNGLCULLPARAMETERDVEXTPROC                 glCullParameterdvEXT                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCULLPARAMETERFVEXTPROC                 glCullParameterfvEXT                            GL_FUNC_DEF2     ;
#endif /* GL_EXT_cull_vertex */

#ifdef GL_EXT_debug_label
GL_FUNC_DEF  PFNGLLABELOBJECTEXTPROC                  glLabelObjectEXT                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETOBJECTLABELEXTPROC               glGetObjectLabelEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_debug_label */

#ifdef GL_EXT_debug_marker
GL_FUNC_DEF  PFNGLINSERTEVENTMARKEREXTPROC                   glInsertEventMarkerEXT                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPUSHGROUPMARKEREXTPROC                     glPushGroupMarkerEXT                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOPGROUPMARKEREXTPROC                      glPopGroupMarkerEXT                                GL_FUNC_DEF2     ;
#endif /* GL_EXT_debug_marker */

#ifdef GL_EXT_depth_bounds_test
GL_FUNC_DEF  PFNGLDEPTHBOUNDSEXTPROC               glDepthBoundsEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_depth_bounds_test */

#ifdef GL_EXT_direct_state_access
GL_FUNC_DEF  PFNGLMATRIXLOADFEXTPROC                                                  glMatrixLoadfEXT                                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXLOADDEXTPROC                                                  glMatrixLoaddEXT                                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXMULTFEXTPROC                                                  glMatrixMultfEXT                                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXMULTDEXTPROC                                                  glMatrixMultdEXT                                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXLOADIDENTITYEXTPROC                                           glMatrixLoadIdentityEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXROTATEFEXTPROC                                                glMatrixRotatefEXT                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXROTATEDEXTPROC                                                glMatrixRotatedEXT                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXSCALEFEXTPROC                                                 glMatrixScalefEXT                                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXSCALEDEXTPROC                                                 glMatrixScaledEXT                                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXTRANSLATEFEXTPROC                                             glMatrixTranslatefEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXTRANSLATEDEXTPROC                                             glMatrixTranslatedEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXFRUSTUMEXTPROC                                                glMatrixFrustumEXT                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXORTHOEXTPROC                                                  glMatrixOrthoEXT                                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXPOPEXTPROC                                                    glMatrixPopEXT                                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXPUSHEXTPROC                                                   glMatrixPushEXT                                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLIENTATTRIBDEFAULTEXTPROC                                          glClientAttribDefaultEXT                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC                                      glPushClientAttribDefaultEXT                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREPARAMETERFEXTPROC                                            glTextureParameterfEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREPARAMETERFVEXTPROC                                           glTextureParameterfvEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREPARAMETERIEXTPROC                                            glTextureParameteriEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREPARAMETERIVEXTPROC                                           glTextureParameterivEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREIMAGE1DEXTPROC                                               glTextureImage1DEXT                                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREIMAGE2DEXTPROC                                               glTextureImage2DEXT                                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESUBIMAGE1DEXTPROC                                            glTextureSubImage1DEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESUBIMAGE2DEXTPROC                                            glTextureSubImage2DEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYTEXTUREIMAGE1DEXTPROC                                           glCopyTextureImage1DEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYTEXTUREIMAGE2DEXTPROC                                           glCopyTextureImage2DEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC                                        glCopyTextureSubImage1DEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC                                        glCopyTextureSubImage2DEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXTUREIMAGEEXTPROC                                              glGetTextureImageEXT                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXTUREPARAMETERFVEXTPROC                                        glGetTextureParameterfvEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXTUREPARAMETERIVEXTPROC                                        glGetTextureParameterivEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC                                   glGetTextureLevelParameterfvEXT                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC                                   glGetTextureLevelParameterivEXT                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREIMAGE3DEXTPROC                                               glTextureImage3DEXT                                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESUBIMAGE3DEXTPROC                                            glTextureSubImage3DEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC                                        glCopyTextureSubImage3DEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDMULTITEXTUREEXTPROC                                             glBindMultiTextureEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORDPOINTEREXTPROC                                         glMultiTexCoordPointerEXT                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXENVFEXTPROC                                                 glMultiTexEnvfEXT                                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXENVFVEXTPROC                                                glMultiTexEnvfvEXT                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXENVIEXTPROC                                                 glMultiTexEnviEXT                                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXENVIVEXTPROC                                                glMultiTexEnvivEXT                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXGENDEXTPROC                                                 glMultiTexGendEXT                                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXGENDVEXTPROC                                                glMultiTexGendvEXT                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXGENFEXTPROC                                                 glMultiTexGenfEXT                                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXGENFVEXTPROC                                                glMultiTexGenfvEXT                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXGENIEXTPROC                                                 glMultiTexGeniEXT                                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXGENIVEXTPROC                                                glMultiTexGenivEXT                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMULTITEXENVFVEXTPROC                                             glGetMultiTexEnvfvEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMULTITEXENVIVEXTPROC                                             glGetMultiTexEnvivEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMULTITEXGENDVEXTPROC                                             glGetMultiTexGendvEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMULTITEXGENFVEXTPROC                                             glGetMultiTexGenfvEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMULTITEXGENIVEXTPROC                                             glGetMultiTexGenivEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXPARAMETERIEXTPROC                                           glMultiTexParameteriEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXPARAMETERIVEXTPROC                                          glMultiTexParameterivEXT                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXPARAMETERFEXTPROC                                           glMultiTexParameterfEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXPARAMETERFVEXTPROC                                          glMultiTexParameterfvEXT                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXIMAGE1DEXTPROC                                              glMultiTexImage1DEXT                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXIMAGE2DEXTPROC                                              glMultiTexImage2DEXT                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXSUBIMAGE1DEXTPROC                                           glMultiTexSubImage1DEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXSUBIMAGE2DEXTPROC                                           glMultiTexSubImage2DEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYMULTITEXIMAGE1DEXTPROC                                          glCopyMultiTexImage1DEXT                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYMULTITEXIMAGE2DEXTPROC                                          glCopyMultiTexImage2DEXT                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC                                       glCopyMultiTexSubImage1DEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC                                       glCopyMultiTexSubImage2DEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMULTITEXIMAGEEXTPROC                                             glGetMultiTexImageEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMULTITEXPARAMETERFVEXTPROC                                       glGetMultiTexParameterfvEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMULTITEXPARAMETERIVEXTPROC                                       glGetMultiTexParameterivEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC                                  glGetMultiTexLevelParameterfvEXT                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC                                  glGetMultiTexLevelParameterivEXT                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXIMAGE3DEXTPROC                                              glMultiTexImage3DEXT                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXSUBIMAGE3DEXTPROC                                           glMultiTexSubImage3DEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC                                       glCopyMultiTexSubImage3DEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENABLECLIENTSTATEINDEXEDEXTPROC                                     glEnableClientStateIndexedEXT                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC                                    glDisableClientStateIndexedEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFLOATINDEXEDVEXTPROC                                             glGetFloatIndexedvEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETDOUBLEINDEXEDVEXTPROC                                            glGetDoubleIndexedvEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPOINTERINDEXEDVEXTPROC                                           glGetPointerIndexedvEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENABLEINDEXEDEXTPROC                                                glEnableIndexedEXT                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDISABLEINDEXEDEXTPROC                                               glDisableIndexedEXT                                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISENABLEDINDEXEDEXTPROC                                             glIsEnabledIndexedEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETINTEGERINDEXEDVEXTPROC                                           glGetIntegerIndexedvEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETBOOLEANINDEXEDVEXTPROC                                           glGetBooleanIndexedvEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC                                     glCompressedTextureImage3DEXT                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC                                     glCompressedTextureImage2DEXT                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC                                     glCompressedTextureImage1DEXT                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC                                  glCompressedTextureSubImage3DEXT                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC                                  glCompressedTextureSubImage2DEXT                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC                                  glCompressedTextureSubImage1DEXT                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC                                    glGetCompressedTextureImageEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC                                    glCompressedMultiTexImage3DEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC                                    glCompressedMultiTexImage2DEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC                                    glCompressedMultiTexImage1DEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC                                 glCompressedMultiTexSubImage3DEXT                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC                                 glCompressedMultiTexSubImage2DEXT                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC                                 glCompressedMultiTexSubImage1DEXT                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC                                   glGetCompressedMultiTexImageEXT                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXLOADTRANSPOSEFEXTPROC                                         glMatrixLoadTransposefEXT                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXLOADTRANSPOSEDEXTPROC                                         glMatrixLoadTransposedEXT                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXMULTTRANSPOSEFEXTPROC                                         glMatrixMultTransposefEXT                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXMULTTRANSPOSEDEXTPROC                                         glMatrixMultTransposedEXT                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDBUFFERDATAEXTPROC                                              glNamedBufferDataEXT                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDBUFFERSUBDATAEXTPROC                                           glNamedBufferSubDataEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAPNAMEDBUFFEREXTPROC                                               glMapNamedBufferEXT                                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNMAPNAMEDBUFFEREXTPROC                                             glUnmapNamedBufferEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC                                    glGetNamedBufferParameterivEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNAMEDBUFFERPOINTERVEXTPROC                                       glGetNamedBufferPointervEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNAMEDBUFFERSUBDATAEXTPROC                                        glGetNamedBufferSubDataEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1FEXTPROC                                             glProgramUniform1fEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2FEXTPROC                                             glProgramUniform2fEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3FEXTPROC                                             glProgramUniform3fEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4FEXTPROC                                             glProgramUniform4fEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1IEXTPROC                                             glProgramUniform1iEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2IEXTPROC                                             glProgramUniform2iEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3IEXTPROC                                             glProgramUniform3iEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4IEXTPROC                                             glProgramUniform4iEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1FVEXTPROC                                            glProgramUniform1fvEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2FVEXTPROC                                            glProgramUniform2fvEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3FVEXTPROC                                            glProgramUniform3fvEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4FVEXTPROC                                            glProgramUniform4fvEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1IVEXTPROC                                            glProgramUniform1ivEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2IVEXTPROC                                            glProgramUniform2ivEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3IVEXTPROC                                            glProgramUniform3ivEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4IVEXTPROC                                            glProgramUniform4ivEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC                                      glProgramUniformMatrix2fvEXT                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC                                      glProgramUniformMatrix3fvEXT                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC                                      glProgramUniformMatrix4fvEXT                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC                                    glProgramUniformMatrix2x3fvEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC                                    glProgramUniformMatrix3x2fvEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC                                    glProgramUniformMatrix2x4fvEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC                                    glProgramUniformMatrix4x2fvEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC                                    glProgramUniformMatrix3x4fvEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC                                    glProgramUniformMatrix4x3fvEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREBUFFEREXTPROC                                                glTextureBufferEXT                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXBUFFEREXTPROC                                               glMultiTexBufferEXT                                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREPARAMETERIIVEXTPROC                                          glTextureParameterIivEXT                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREPARAMETERIUIVEXTPROC                                         glTextureParameterIuivEXT                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXTUREPARAMETERIIVEXTPROC                                       glGetTextureParameterIivEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXTUREPARAMETERIUIVEXTPROC                                      glGetTextureParameterIuivEXT                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXPARAMETERIIVEXTPROC                                         glMultiTexParameterIivEXT                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXPARAMETERIUIVEXTPROC                                        glMultiTexParameterIuivEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMULTITEXPARAMETERIIVEXTPROC                                      glGetMultiTexParameterIivEXT                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMULTITEXPARAMETERIUIVEXTPROC                                     glGetMultiTexParameterIuivEXT                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1UIEXTPROC                                            glProgramUniform1uiEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2UIEXTPROC                                            glProgramUniform2uiEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3UIEXTPROC                                            glProgramUniform3uiEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4UIEXTPROC                                            glProgramUniform4uiEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1UIVEXTPROC                                           glProgramUniform1uivEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2UIVEXTPROC                                           glProgramUniform2uivEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3UIVEXTPROC                                           glProgramUniform3uivEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4UIVEXTPROC                                           glProgramUniform4uivEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC                               glNamedProgramLocalParameters4fvEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC                                glNamedProgramLocalParameterI4iEXT                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC                               glNamedProgramLocalParameterI4ivEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC                              glNamedProgramLocalParametersI4ivEXT                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC                               glNamedProgramLocalParameterI4uiEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC                              glNamedProgramLocalParameterI4uivEXT                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC                             glNamedProgramLocalParametersI4uivEXT                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC                             glGetNamedProgramLocalParameterIivEXT                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC                            glGetNamedProgramLocalParameterIuivEXT                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENABLECLIENTSTATEIEXTPROC                                           glEnableClientStateiEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDISABLECLIENTSTATEIEXTPROC                                          glDisableClientStateiEXT                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFLOATI_VEXTPROC                                                  glGetFloati_vEXT                                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETDOUBLEI_VEXTPROC                                                 glGetDoublei_vEXT                                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPOINTERI_VEXTPROC                                                glGetPointeri_vEXT                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDPROGRAMSTRINGEXTPROC                                           glNamedProgramStringEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC                                 glNamedProgramLocalParameter4dEXT                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC                                glNamedProgramLocalParameter4dvEXT                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC                                 glNamedProgramLocalParameter4fEXT                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC                                glNamedProgramLocalParameter4fvEXT                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC                              glGetNamedProgramLocalParameterdvEXT                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC                              glGetNamedProgramLocalParameterfvEXT                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNAMEDPROGRAMIVEXTPROC                                            glGetNamedProgramivEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNAMEDPROGRAMSTRINGEXTPROC                                        glGetNamedProgramStringEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC                                     glNamedRenderbufferStorageEXT                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC                              glGetNamedRenderbufferParameterivEXT                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC                          glNamedRenderbufferStorageMultisampleEXT                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC                  glNamedRenderbufferStorageMultisampleCoverageEXT                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC                                  glCheckNamedFramebufferStatusEXT                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC                                    glNamedFramebufferTexture1DEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC                                    glNamedFramebufferTexture2DEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC                                    glNamedFramebufferTexture3DEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC                                 glNamedFramebufferRenderbufferEXT                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC                     glGetNamedFramebufferAttachmentParameterivEXT                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENERATETEXTUREMIPMAPEXTPROC                                        glGenerateTextureMipmapEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENERATEMULTITEXMIPMAPEXTPROC                                       glGenerateMultiTexMipmapEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC                                        glFramebufferDrawBufferEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC                                       glFramebufferDrawBuffersEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERREADBUFFEREXTPROC                                        glFramebufferReadBufferEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC                                    glGetFramebufferParameterivEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC                                       glNamedCopyBufferSubDataEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC                                      glNamedFramebufferTextureEXT                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC                                 glNamedFramebufferTextureLayerEXT                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC                                  glNamedFramebufferTextureFaceEXT                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURERENDERBUFFEREXTPROC                                          glTextureRenderbufferEXT                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXRENDERBUFFEREXTPROC                                         glMultiTexRenderbufferEXT                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC                                      glVertexArrayVertexOffsetEXT                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYCOLOROFFSETEXTPROC                                       glVertexArrayColorOffsetEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC                                    glVertexArrayEdgeFlagOffsetEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYINDEXOFFSETEXTPROC                                       glVertexArrayIndexOffsetEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYNORMALOFFSETEXTPROC                                      glVertexArrayNormalOffsetEXT                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC                                    glVertexArrayTexCoordOffsetEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC                               glVertexArrayMultiTexCoordOffsetEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC                                    glVertexArrayFogCoordOffsetEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC                              glVertexArraySecondaryColorOffsetEXT                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC                                glVertexArrayVertexAttribOffsetEXT                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC                               glVertexArrayVertexAttribIOffsetEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENABLEVERTEXARRAYEXTPROC                                            glEnableVertexArrayEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDISABLEVERTEXARRAYEXTPROC                                           glDisableVertexArrayEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENABLEVERTEXARRAYATTRIBEXTPROC                                      glEnableVertexArrayAttribEXT                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC                                     glDisableVertexArrayAttribEXT                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXARRAYINTEGERVEXTPROC                                       glGetVertexArrayIntegervEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXARRAYPOINTERVEXTPROC                                       glGetVertexArrayPointervEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC                                     glGetVertexArrayIntegeri_vEXT                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC                                     glGetVertexArrayPointeri_vEXT                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAPNAMEDBUFFERRANGEEXTPROC                                          glMapNamedBufferRangeEXT                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC                                  glFlushMappedNamedBufferRangeEXT                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDBUFFERSTORAGEEXTPROC                                           glNamedBufferStorageEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARNAMEDBUFFERDATAEXTPROC                                         glClearNamedBufferDataEXT                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC                                      glClearNamedBufferSubDataEXT                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC                                   glNamedFramebufferParameteriEXT                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC                               glGetNamedFramebufferParameterivEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1DEXTPROC                                             glProgramUniform1dEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2DEXTPROC                                             glProgramUniform2dEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3DEXTPROC                                             glProgramUniform3dEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4DEXTPROC                                             glProgramUniform4dEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM1DVEXTPROC                                            glProgramUniform1dvEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM2DVEXTPROC                                            glProgramUniform2dvEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM3DVEXTPROC                                            glProgramUniform3dvEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORM4DVEXTPROC                                            glProgramUniform4dvEXT                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC                                      glProgramUniformMatrix2dvEXT                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC                                      glProgramUniformMatrix3dvEXT                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC                                      glProgramUniformMatrix4dvEXT                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC                                    glProgramUniformMatrix2x3dvEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC                                    glProgramUniformMatrix2x4dvEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC                                    glProgramUniformMatrix3x2dvEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC                                    glProgramUniformMatrix3x4dvEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC                                    glProgramUniformMatrix4x2dvEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC                                    glProgramUniformMatrix4x3dvEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREBUFFERRANGEEXTPROC                                           glTextureBufferRangeEXT                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESTORAGE1DEXTPROC                                             glTextureStorage1DEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESTORAGE2DEXTPROC                                             glTextureStorage2DEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESTORAGE3DEXTPROC                                             glTextureStorage3DEXT                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC                                  glTextureStorage2DMultisampleEXT                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC                                  glTextureStorage3DMultisampleEXT                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC                                  glVertexArrayBindVertexBufferEXT                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC                                glVertexArrayVertexAttribFormatEXT                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC                               glVertexArrayVertexAttribIFormatEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC                               glVertexArrayVertexAttribLFormatEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC                               glVertexArrayVertexAttribBindingEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC                              glVertexArrayVertexBindingDivisorEXT                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC                               glVertexArrayVertexAttribLOffsetEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREPAGECOMMITMENTEXTPROC                                        glTexturePageCommitmentEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC                               glVertexArrayVertexAttribDivisorEXT                                             GL_FUNC_DEF2     ;
#endif /* GL_EXT_direct_state_access */

#ifdef GL_EXT_draw_buffers2
GL_FUNC_DEF  PFNGLCOLORMASKINDEXEDEXTPROC               glColorMaskIndexedEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_draw_buffers2 */

#ifdef GL_EXT_draw_instanced
GL_FUNC_DEF  PFNGLDRAWARRAYSINSTANCEDEXTPROC                  glDrawArraysInstancedEXT                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWELEMENTSINSTANCEDEXTPROC                glDrawElementsInstancedEXT                             GL_FUNC_DEF2     ;
#endif /* GL_EXT_draw_instanced */

#ifdef GL_EXT_draw_range_elements
GL_FUNC_DEF  PFNGLDRAWRANGEELEMENTSEXTPROC               glDrawRangeElementsEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_draw_range_elements */

#ifdef GL_EXT_external_buffer
GL_FUNC_DEF  PFNGLBUFFERSTORAGEEXTERNALEXTPROC                       glBufferStorageExternalEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDBUFFERSTORAGEEXTERNALEXTPROC                  glNamedBufferStorageExternalEXT                               GL_FUNC_DEF2     ;
#endif /* GL_EXT_external_buffer */

#ifdef GL_EXT_fog_coord
GL_FUNC_DEF  PFNGLFOGCOORDFEXTPROC                        glFogCoordfEXT                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFOGCOORDFVEXTPROC                       glFogCoordfvEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFOGCOORDDEXTPROC                        glFogCoorddEXT                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFOGCOORDDVEXTPROC                       glFogCoorddvEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFOGCOORDPOINTEREXTPROC                  glFogCoordPointerEXT                               GL_FUNC_DEF2     ;
#endif /* GL_EXT_fog_coord */

#ifdef GL_EXT_framebuffer_blit
GL_FUNC_DEF  PFNGLBLITFRAMEBUFFEREXTPROC               glBlitFramebufferEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_framebuffer_blit */

#ifdef GL_EXT_framebuffer_multisample
GL_FUNC_DEF  PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC               glRenderbufferStorageMultisampleEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_framebuffer_multisample */

#ifdef GL_EXT_framebuffer_object
GL_FUNC_DEF  PFNGLISRENDERBUFFEREXTPROC                                          glIsRenderbufferEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDRENDERBUFFEREXTPROC                                        glBindRenderbufferEXT                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETERENDERBUFFERSEXTPROC                                     glDeleteRenderbuffersEXT                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENRENDERBUFFERSEXTPROC                                        glGenRenderbuffersEXT                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRENDERBUFFERSTORAGEEXTPROC                                     glRenderbufferStorageEXT                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC                              glGetRenderbufferParameterivEXT                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISFRAMEBUFFEREXTPROC                                           glIsFramebufferEXT                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDFRAMEBUFFEREXTPROC                                         glBindFramebufferEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEFRAMEBUFFERSEXTPROC                                      glDeleteFramebuffersEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENFRAMEBUFFERSEXTPROC                                         glGenFramebuffersEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC                                  glCheckFramebufferStatusEXT                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERTEXTURE1DEXTPROC                                    glFramebufferTexture1DEXT                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERTEXTURE2DEXTPROC                                    glFramebufferTexture2DEXT                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERTEXTURE3DEXTPROC                                    glFramebufferTexture3DEXT                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC                                 glFramebufferRenderbufferEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC                     glGetFramebufferAttachmentParameterivEXT                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENERATEMIPMAPEXTPROC                                          glGenerateMipmapEXT                                                      GL_FUNC_DEF2     ;
#endif /* GL_EXT_framebuffer_object */

#ifdef GL_EXT_geometry_shader4
GL_FUNC_DEF  PFNGLPROGRAMPARAMETERIEXTPROC               glProgramParameteriEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_geometry_shader4 */

#ifdef GL_EXT_gpu_program_parameters
GL_FUNC_DEF  PFNGLPROGRAMENVPARAMETERS4FVEXTPROC                 glProgramEnvParameters4fvEXT                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC               glProgramLocalParameters4fvEXT                            GL_FUNC_DEF2     ;
#endif /* GL_EXT_gpu_program_parameters */

#ifdef GL_EXT_gpu_shader4
GL_FUNC_DEF  PFNGLGETUNIFORMUIVEXTPROC                           glGetUniformuivEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDFRAGDATALOCATIONEXTPROC                    glBindFragDataLocationEXT                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFRAGDATALOCATIONEXTPROC                     glGetFragDataLocationEXT                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1UIEXTPROC                              glUniform1uiEXT                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2UIEXTPROC                              glUniform2uiEXT                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3UIEXTPROC                              glUniform3uiEXT                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4UIEXTPROC                              glUniform4uiEXT                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM1UIVEXTPROC                             glUniform1uivEXT                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM2UIVEXTPROC                             glUniform2uivEXT                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM3UIVEXTPROC                             glUniform3uivEXT                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORM4UIVEXTPROC                             glUniform4uivEXT                                        GL_FUNC_DEF2     ;
#endif /* GL_EXT_gpu_shader4 */

#ifdef GL_EXT_histogram
GL_FUNC_DEF  PFNGLGETHISTOGRAMEXTPROC                               glGetHistogramEXT                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETHISTOGRAMPARAMETERFVEXTPROC                    glGetHistogramParameterfvEXT                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETHISTOGRAMPARAMETERIVEXTPROC                    glGetHistogramParameterivEXT                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMINMAXEXTPROC                                  glGetMinmaxEXT                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMINMAXPARAMETERFVEXTPROC                       glGetMinmaxParameterfvEXT                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMINMAXPARAMETERIVEXTPROC                       glGetMinmaxParameterivEXT                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLHISTOGRAMEXTPROC                                  glHistogramEXT                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMINMAXEXTPROC                                     glMinmaxEXT                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRESETHISTOGRAMEXTPROC                             glResetHistogramEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRESETMINMAXEXTPROC                                glResetMinmaxEXT                                          GL_FUNC_DEF2     ;
#endif /* GL_EXT_histogram */

#ifdef GL_EXT_index_func
GL_FUNC_DEF  PFNGLINDEXFUNCEXTPROC               glIndexFuncEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_index_func */

#ifdef GL_EXT_index_material
GL_FUNC_DEF  PFNGLINDEXMATERIALEXTPROC               glIndexMaterialEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_index_material */

#ifdef GL_EXT_light_texture
GL_FUNC_DEF  PFNGLAPPLYTEXTUREEXTPROC                       glApplyTextureEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURELIGHTEXTPROC                       glTextureLightEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREMATERIALEXTPROC                    glTextureMaterialEXT                                 GL_FUNC_DEF2     ;
#endif /* GL_EXT_light_texture */

#ifdef GL_EXT_memory_object
GL_FUNC_DEF  PFNGLGETUNSIGNEDBYTEVEXTPROC                                   glGetUnsignedBytevEXT                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNSIGNEDBYTEI_VEXTPROC                                 glGetUnsignedBytei_vEXT                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEMEMORYOBJECTSEXTPROC                                glDeleteMemoryObjectsEXT                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISMEMORYOBJECTEXTPROC                                     glIsMemoryObjectEXT                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATEMEMORYOBJECTSEXTPROC                                glCreateMemoryObjectsEXT                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMEMORYOBJECTPARAMETERIVEXTPROC                            glMemoryObjectParameterivEXT                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMEMORYOBJECTPARAMETERIVEXTPROC                         glGetMemoryObjectParameterivEXT                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXSTORAGEMEM2DEXTPROC                                    glTexStorageMem2DEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXSTORAGEMEM2DMULTISAMPLEEXTPROC                         glTexStorageMem2DMultisampleEXT                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXSTORAGEMEM3DEXTPROC                                    glTexStorageMem3DEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXSTORAGEMEM3DMULTISAMPLEEXTPROC                         glTexStorageMem3DMultisampleEXT                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBUFFERSTORAGEMEMEXTPROC                                   glBufferStorageMemEXT                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESTORAGEMEM2DEXTPROC                                glTextureStorageMem2DEXT                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESTORAGEMEM2DMULTISAMPLEEXTPROC                     glTextureStorageMem2DMultisampleEXT                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESTORAGEMEM3DEXTPROC                                glTextureStorageMem3DEXT                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESTORAGEMEM3DMULTISAMPLEEXTPROC                     glTextureStorageMem3DMultisampleEXT                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDBUFFERSTORAGEMEMEXTPROC                              glNamedBufferStorageMemEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXSTORAGEMEM1DEXTPROC                                    glTexStorageMem1DEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTURESTORAGEMEM1DEXTPROC                                glTextureStorageMem1DEXT                                         GL_FUNC_DEF2     ;
#endif /* GL_EXT_memory_object */

#ifdef GL_EXT_memory_object_fd
GL_FUNC_DEF  PFNGLIMPORTMEMORYFDEXTPROC               glImportMemoryFdEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_memory_object_fd */

#ifdef GL_EXT_memory_object_win32
GL_FUNC_DEF  PFNGLIMPORTMEMORYWIN32HANDLEEXTPROC               glImportMemoryWin32HandleEXT                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLIMPORTMEMORYWIN32NAMEEXTPROC                 glImportMemoryWin32NameEXT                               GL_FUNC_DEF2     ;
#endif /* GL_EXT_memory_object_win32 */

#ifdef GL_EXT_multi_draw_arrays
GL_FUNC_DEF  PFNGLMULTIDRAWARRAYSEXTPROC                 glMultiDrawArraysEXT                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTIDRAWELEMENTSEXTPROC               glMultiDrawElementsEXT                            GL_FUNC_DEF2     ;
#endif /* GL_EXT_multi_draw_arrays */

#ifdef GL_EXT_multisample
GL_FUNC_DEF  PFNGLSAMPLEMASKEXTPROC                   glSampleMaskEXT                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSAMPLEPATTERNEXTPROC                glSamplePatternEXT                            GL_FUNC_DEF2     ;
#endif /* GL_EXT_multisample */

#ifdef GL_EXT_paletted_texture
GL_FUNC_DEF  PFNGLCOLORTABLEEXTPROC                                 glColorTableEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOLORTABLEEXTPROC                              glGetColorTableEXT                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOLORTABLEPARAMETERIVEXTPROC                   glGetColorTableParameterivEXT                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOLORTABLEPARAMETERFVEXTPROC                   glGetColorTableParameterfvEXT                               GL_FUNC_DEF2     ;
#endif /* GL_EXT_paletted_texture */

#ifdef GL_EXT_pixel_transform
GL_FUNC_DEF  PFNGLPIXELTRANSFORMPARAMETERIEXTPROC                        glPixelTransformParameteriEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPIXELTRANSFORMPARAMETERFEXTPROC                        glPixelTransformParameterfEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC                       glPixelTransformParameterivEXT                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC                       glPixelTransformParameterfvEXT                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC                    glGetPixelTransformParameterivEXT                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC                    glGetPixelTransformParameterfvEXT                                GL_FUNC_DEF2     ;
#endif /* GL_EXT_pixel_transform */

#ifdef GL_EXT_point_parameters
GL_FUNC_DEF  PFNGLPOINTPARAMETERFEXTPROC                glPointParameterfEXT                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOINTPARAMETERFVEXTPROC               glPointParameterfvEXT                            GL_FUNC_DEF2     ;
#endif /* GL_EXT_point_parameters */

#ifdef GL_EXT_polygon_offset
GL_FUNC_DEF  PFNGLPOLYGONOFFSETEXTPROC               glPolygonOffsetEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_polygon_offset */

#ifdef GL_EXT_polygon_offset_clamp
GL_FUNC_DEF  PFNGLPOLYGONOFFSETCLAMPEXTPROC               glPolygonOffsetClampEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_polygon_offset_clamp */

#ifdef GL_EXT_provoking_vertex
GL_FUNC_DEF  PFNGLPROVOKINGVERTEXEXTPROC               glProvokingVertexEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_provoking_vertex */

#ifdef GL_EXT_raster_multisample
GL_FUNC_DEF  PFNGLRASTERSAMPLESEXTPROC               glRasterSamplesEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_raster_multisample */

#ifdef GL_EXT_secondary_color
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3BEXTPROC                            glSecondaryColor3bEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3BVEXTPROC                           glSecondaryColor3bvEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3DEXTPROC                            glSecondaryColor3dEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3DVEXTPROC                           glSecondaryColor3dvEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3FEXTPROC                            glSecondaryColor3fEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3FVEXTPROC                           glSecondaryColor3fvEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3IEXTPROC                            glSecondaryColor3iEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3IVEXTPROC                           glSecondaryColor3ivEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3SEXTPROC                            glSecondaryColor3sEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3SVEXTPROC                           glSecondaryColor3svEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3UBEXTPROC                           glSecondaryColor3ubEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3UBVEXTPROC                          glSecondaryColor3ubvEXT                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3UIEXTPROC                           glSecondaryColor3uiEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3UIVEXTPROC                          glSecondaryColor3uivEXT                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3USEXTPROC                           glSecondaryColor3usEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3USVEXTPROC                          glSecondaryColor3usvEXT                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLORPOINTEREXTPROC                       glSecondaryColorPointerEXT                                  GL_FUNC_DEF2     ;
#endif /* GL_EXT_secondary_color */

#ifdef GL_EXT_semaphore
GL_FUNC_DEF  PFNGLGENSEMAPHORESEXTPROC                                  glGenSemaphoresEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETESEMAPHORESEXTPROC                               glDeleteSemaphoresEXT                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISSEMAPHOREEXTPROC                                    glIsSemaphoreEXT                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSEMAPHOREPARAMETERUI64VEXTPROC                        glSemaphoreParameterui64vEXT                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSEMAPHOREPARAMETERUI64VEXTPROC                     glGetSemaphoreParameterui64vEXT                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWAITSEMAPHOREEXTPROC                                  glWaitSemaphoreEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSIGNALSEMAPHOREEXTPROC                                glSignalSemaphoreEXT                                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_semaphore */

#ifdef GL_EXT_semaphore_fd
GL_FUNC_DEF  PFNGLIMPORTSEMAPHOREFDEXTPROC               glImportSemaphoreFdEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_semaphore_fd */

#ifdef GL_EXT_semaphore_win32
GL_FUNC_DEF  PFNGLIMPORTSEMAPHOREWIN32HANDLEEXTPROC               glImportSemaphoreWin32HandleEXT                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLIMPORTSEMAPHOREWIN32NAMEEXTPROC                 glImportSemaphoreWin32NameEXT                               GL_FUNC_DEF2     ;
#endif /* GL_EXT_semaphore_win32 */

#ifdef GL_EXT_separate_shader_objects
GL_FUNC_DEF  PFNGLUSESHADERPROGRAMEXTPROC                       glUseShaderProgramEXT                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLACTIVEPROGRAMEXTPROC                          glActiveProgramEXT                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATESHADERPROGRAMEXTPROC                    glCreateShaderProgramEXT                               GL_FUNC_DEF2     ;
#endif /* GL_EXT_separate_shader_objects */

#ifdef GL_EXT_shader_framebuffer_fetch_non_coherent
GL_FUNC_DEF  PFNGLFRAMEBUFFERFETCHBARRIEREXTPROC               glFramebufferFetchBarrierEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_shader_framebuffer_fetch_non_coherent */

#ifdef GL_EXT_shader_image_load_store
GL_FUNC_DEF  PFNGLBINDIMAGETEXTUREEXTPROC                glBindImageTextureEXT                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMEMORYBARRIEREXTPROC                   glMemoryBarrierEXT                                GL_FUNC_DEF2     ;
#endif /* GL_EXT_shader_image_load_store */

#ifdef GL_EXT_stencil_clear_tag
GL_FUNC_DEF  PFNGLSTENCILCLEARTAGEXTPROC               glStencilClearTagEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_stencil_clear_tag */

#ifdef GL_EXT_stencil_two_side
GL_FUNC_DEF  PFNGLACTIVESTENCILFACEEXTPROC               glActiveStencilFaceEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_stencil_two_side */

#ifdef GL_EXT_subtexture
GL_FUNC_DEF  PFNGLTEXSUBIMAGE1DEXTPROC                glTexSubImage1DEXT                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXSUBIMAGE2DEXTPROC                glTexSubImage2DEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_subtexture */

#ifdef GL_EXT_texture3D
GL_FUNC_DEF  PFNGLTEXIMAGE3DEXTPROC                   glTexImage3DEXT                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXSUBIMAGE3DEXTPROC                glTexSubImage3DEXT                              GL_FUNC_DEF2     ;
#endif /* GL_EXT_texture3D */

#ifdef GL_EXT_texture_array
GL_FUNC_DEF  PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC               glFramebufferTextureLayerEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_texture_array */

#ifdef GL_EXT_texture_buffer_object
GL_FUNC_DEF  PFNGLTEXBUFFEREXTPROC               glTexBufferEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_texture_buffer_object */

#ifdef GL_EXT_texture_integer
GL_FUNC_DEF  PFNGLTEXPARAMETERIIVEXTPROC                      glTexParameterIivEXT                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXPARAMETERIUIVEXTPROC                     glTexParameterIuivEXT                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXPARAMETERIIVEXTPROC                   glGetTexParameterIivEXT                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXPARAMETERIUIVEXTPROC                  glGetTexParameterIuivEXT                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARCOLORIIEXTPROC                         glClearColorIiEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARCOLORIUIEXTPROC                        glClearColorIuiEXT                                     GL_FUNC_DEF2     ;
#endif /* GL_EXT_texture_integer */

#ifdef GL_EXT_texture_object
GL_FUNC_DEF  PFNGLARETEXTURESRESIDENTEXTPROC                    glAreTexturesResidentEXT                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDTEXTUREEXTPROC                            glBindTextureEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETETEXTURESEXTPROC                         glDeleteTexturesEXT                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENTEXTURESEXTPROC                            glGenTexturesEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISTEXTUREEXTPROC                              glIsTextureEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPRIORITIZETEXTURESEXTPROC                     glPrioritizeTexturesEXT                             GL_FUNC_DEF2     ;
#endif /* GL_EXT_texture_object */

#ifdef GL_EXT_texture_perturb_normal
GL_FUNC_DEF  PFNGLTEXTURENORMALEXTPROC               glTextureNormalEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_texture_perturb_normal */

#ifdef GL_EXT_timer_query
GL_FUNC_DEF  PFNGLGETQUERYOBJECTI64VEXTPROC                 glGetQueryObjecti64vEXT                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETQUERYOBJECTUI64VEXTPROC                glGetQueryObjectui64vEXT                             GL_FUNC_DEF2     ;
#endif /* GL_EXT_timer_query */

#ifdef GL_EXT_transform_feedback
GL_FUNC_DEF  PFNGLBEGINTRANSFORMFEEDBACKEXTPROC                        glBeginTransformFeedbackEXT                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENDTRANSFORMFEEDBACKEXTPROC                          glEndTransformFeedbackEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDBUFFERRANGEEXTPROC                               glBindBufferRangeEXT                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDBUFFEROFFSETEXTPROC                              glBindBufferOffsetEXT                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDBUFFERBASEEXTPROC                                glBindBufferBaseEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC                     glTransformFeedbackVaryingsEXT                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC                   glGetTransformFeedbackVaryingEXT                                GL_FUNC_DEF2     ;
#endif /* GL_EXT_transform_feedback */

#ifdef GL_EXT_vertex_array
GL_FUNC_DEF  PFNGLARRAYELEMENTEXTPROC                         glArrayElementEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLORPOINTEREXTPROC                         glColorPointerEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWARRAYSEXTPROC                           glDrawArraysEXT                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLEDGEFLAGPOINTEREXTPROC                      glEdgeFlagPointerEXT                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPOINTERVEXTPROC                          glGetPointervEXT                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLINDEXPOINTEREXTPROC                         glIndexPointerEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMALPOINTEREXTPROC                        glNormalPointerEXT                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORDPOINTEREXTPROC                      glTexCoordPointerEXT                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXPOINTEREXTPROC                        glVertexPointerEXT                                            GL_FUNC_DEF2     ;
#ifdef __gl_h_
#ifdef __GL_H__
/* EXT_vertex_array */             /* EXT_vertex_array */
GL_FUNC_DEF  PFNGLARRAYELEMENTARRAYEXTPROC                    glArrayElementArrayEXT                                        GL_FUNC_DEF2     ;
/* WIN_draw_range_elements */      /* WIN_draw_range_elements */
GL_FUNC_DEF  PFNGLDRAWRANGEELEMENTSWINPROC                    glDrawRangeElementsWIN                                        GL_FUNC_DEF2     ;
/* WIN_swap_hint */                /* WIN_swap_hint */
GL_FUNC_DEF  PFNGLADDSWAPHINTRECTWINPROC                      glAddSwapHintRectWIN                                          GL_FUNC_DEF2     ;
#endif /* __GL_H__ */
#endif /* __gl_h_ */
#endif /* GL_EXT_vertex_array */

#ifdef GL_EXT_vertex_attrib_64bit
GL_FUNC_DEF  PFNGLVERTEXATTRIBL1DEXTPROC                          glVertexAttribL1dEXT                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL2DEXTPROC                          glVertexAttribL2dEXT                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL3DEXTPROC                          glVertexAttribL3dEXT                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL4DEXTPROC                          glVertexAttribL4dEXT                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL1DVEXTPROC                         glVertexAttribL1dvEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL2DVEXTPROC                         glVertexAttribL2dvEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL3DVEXTPROC                         glVertexAttribL3dvEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL4DVEXTPROC                         glVertexAttribL4dvEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBLPOINTEREXTPROC                     glVertexAttribLPointerEXT                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBLDVEXTPROC                       glGetVertexAttribLdvEXT                                     GL_FUNC_DEF2     ;
#endif /* GL_EXT_vertex_attrib_64bit */

#ifdef GL_EXT_vertex_shader
GL_FUNC_DEF  PFNGLBEGINVERTEXSHADEREXTPROC                                glBeginVertexShaderEXT                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENDVERTEXSHADEREXTPROC                                  glEndVertexShaderEXT                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDVERTEXSHADEREXTPROC                                 glBindVertexShaderEXT                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENVERTEXSHADERSEXTPROC                                 glGenVertexShadersEXT                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEVERTEXSHADEREXTPROC                               glDeleteVertexShaderEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSHADEROP1EXTPROC                                        glShaderOp1EXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSHADEROP2EXTPROC                                        glShaderOp2EXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSHADEROP3EXTPROC                                        glShaderOp3EXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSWIZZLEEXTPROC                                          glSwizzleEXT                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWRITEMASKEXTPROC                                        glWriteMaskEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLINSERTCOMPONENTEXTPROC                                  glInsertComponentEXT                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLEXTRACTCOMPONENTEXTPROC                                 glExtractComponentEXT                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENSYMBOLSEXTPROC                                       glGenSymbolsEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSETINVARIANTEXTPROC                                     glSetInvariantEXT                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSETLOCALCONSTANTEXTPROC                                 glSetLocalConstantEXT                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVARIANTBVEXTPROC                                        glVariantbvEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVARIANTSVEXTPROC                                        glVariantsvEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVARIANTIVEXTPROC                                        glVariantivEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVARIANTFVEXTPROC                                        glVariantfvEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVARIANTDVEXTPROC                                        glVariantdvEXT                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVARIANTUBVEXTPROC                                       glVariantubvEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVARIANTUSVEXTPROC                                       glVariantusvEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVARIANTUIVEXTPROC                                       glVariantuivEXT                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVARIANTPOINTEREXTPROC                                   glVariantPointerEXT                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENABLEVARIANTCLIENTSTATEEXTPROC                         glEnableVariantClientStateEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC                        glDisableVariantClientStateEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDLIGHTPARAMETEREXTPROC                               glBindLightParameterEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDMATERIALPARAMETEREXTPROC                            glBindMaterialParameterEXT                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDTEXGENPARAMETEREXTPROC                              glBindTexGenParameterEXT                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDTEXTUREUNITPARAMETEREXTPROC                         glBindTextureUnitParameterEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDPARAMETEREXTPROC                                    glBindParameterEXT                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISVARIANTENABLEDEXTPROC                                 glIsVariantEnabledEXT                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVARIANTBOOLEANVEXTPROC                               glGetVariantBooleanvEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVARIANTINTEGERVEXTPROC                               glGetVariantIntegervEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVARIANTFLOATVEXTPROC                                 glGetVariantFloatvEXT                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVARIANTPOINTERVEXTPROC                               glGetVariantPointervEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETINVARIANTBOOLEANVEXTPROC                             glGetInvariantBooleanvEXT                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETINVARIANTINTEGERVEXTPROC                             glGetInvariantIntegervEXT                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETINVARIANTFLOATVEXTPROC                               glGetInvariantFloatvEXT                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC                         glGetLocalConstantBooleanvEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETLOCALCONSTANTINTEGERVEXTPROC                         glGetLocalConstantIntegervEXT                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETLOCALCONSTANTFLOATVEXTPROC                           glGetLocalConstantFloatvEXT                                         GL_FUNC_DEF2     ;
#endif /* GL_EXT_vertex_shader */

#ifdef GL_EXT_vertex_weighting
GL_FUNC_DEF  PFNGLVERTEXWEIGHTFEXTPROC                          glVertexWeightfEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXWEIGHTFVEXTPROC                         glVertexWeightfvEXT                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXWEIGHTPOINTEREXTPROC                    glVertexWeightPointerEXT                              GL_FUNC_DEF2     ;
#endif /* GL_EXT_vertex_weighting */

#ifdef GL_EXT_win32_keyed_mutex
GL_FUNC_DEF  PFNGLACQUIREKEYEDMUTEXWIN32EXTPROC                 glAcquireKeyedMutexWin32EXT                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRELEASEKEYEDMUTEXWIN32EXTPROC                 glReleaseKeyedMutexWin32EXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_win32_keyed_mutex */

#ifdef GL_EXT_window_rectangles
GL_FUNC_DEF  PFNGLWINDOWRECTANGLESEXTPROC               glWindowRectanglesEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_window_rectangles */

#ifdef GL_EXT_x11_sync_object
GL_FUNC_DEF  PFNGLIMPORTSYNCEXTPROC               glImportSyncEXT                           GL_FUNC_DEF2     ;
#endif /* GL_EXT_x11_sync_object */



#ifdef GL_GREMEDY_frame_terminator
GL_FUNC_DEF  PFNGLFRAMETERMINATORGREMEDYPROC               glFrameTerminatorGREMEDY                           GL_FUNC_DEF2     ;
#endif /* GL_GREMEDY_frame_terminator */

#ifdef GL_GREMEDY_string_marker
GL_FUNC_DEF  PFNGLSTRINGMARKERGREMEDYPROC               glStringMarkerGREMEDY                           GL_FUNC_DEF2     ;
#endif /* GL_GREMEDY_string_marker */



#ifdef GL_HP_image_transform
GL_FUNC_DEF  PFNGLIMAGETRANSFORMPARAMETERIHPPROC                       glImageTransformParameteriHP                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLIMAGETRANSFORMPARAMETERFHPPROC                       glImageTransformParameterfHP                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLIMAGETRANSFORMPARAMETERIVHPPROC                      glImageTransformParameterivHP                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLIMAGETRANSFORMPARAMETERFVHPPROC                      glImageTransformParameterfvHP                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC                   glGetImageTransformParameterivHP                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC                   glGetImageTransformParameterfvHP                                GL_FUNC_DEF2     ;
#endif /* GL_HP_image_transform */



#ifdef GL_IBM_multimode_draw_arrays
GL_FUNC_DEF  PFNGLMULTIMODEDRAWARRAYSIBMPROC                  glMultiModeDrawArraysIBM                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTIMODEDRAWELEMENTSIBMPROC                glMultiModeDrawElementsIBM                           GL_FUNC_DEF2     ;
#endif /* GL_IBM_multimode_draw_arrays */

#ifdef GL_IBM_static_data
GL_FUNC_DEF  PFNGLFLUSHSTATICDATAIBMPROC               glFlushStaticDataIBM                           GL_FUNC_DEF2     ;
#endif /* GL_IBM_static_data */

#ifdef GL_IBM_vertex_array_lists
GL_FUNC_DEF  PFNGLCOLORPOINTERLISTIBMPROC                             glColorPointerListIBM                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLORPOINTERLISTIBMPROC                    glSecondaryColorPointerListIBM                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLEDGEFLAGPOINTERLISTIBMPROC                          glEdgeFlagPointerListIBM                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFOGCOORDPOINTERLISTIBMPROC                          glFogCoordPointerListIBM                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLINDEXPOINTERLISTIBMPROC                             glIndexPointerListIBM                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMALPOINTERLISTIBMPROC                            glNormalPointerListIBM                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORDPOINTERLISTIBMPROC                          glTexCoordPointerListIBM                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXPOINTERLISTIBMPROC                            glVertexPointerListIBM                                     GL_FUNC_DEF2     ;
#endif /* GL_IBM_vertex_array_lists */



#ifdef GL_INGR_blend_func_separate
GL_FUNC_DEF  PFNGLBLENDFUNCSEPARATEINGRPROC               glBlendFuncSeparateINGR                           GL_FUNC_DEF2     ;
#endif /* GL_INGR_blend_func_separate */



#ifdef GL_INTEL_framebuffer_CMAA
GL_FUNC_DEF  PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC               glApplyFramebufferAttachmentCMAAINTEL                           GL_FUNC_DEF2     ;
#endif /* GL_INTEL_framebuffer_CMAA */

#ifdef GL_INTEL_map_texture
GL_FUNC_DEF  PFNGLSYNCTEXTUREINTELPROC                  glSyncTextureINTEL                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNMAPTEXTURE2DINTELPROC                glUnmapTexture2DINTEL                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAPTEXTURE2DINTELPROC                 glMapTexture2DINTEL                              GL_FUNC_DEF2     ;
#endif /* GL_INTEL_map_texture */

#ifdef GL_INTEL_parallel_arrays
GL_FUNC_DEF  PFNGLVERTEXPOINTERVINTELPROC                     glVertexPointervINTEL                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMALPOINTERVINTELPROC                     glNormalPointervINTEL                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLORPOINTERVINTELPROC                      glColorPointervINTEL                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORDPOINTERVINTELPROC                   glTexCoordPointervINTEL                              GL_FUNC_DEF2     ;
#endif /* GL_INTEL_parallel_arrays */

#ifdef GL_INTEL_performance_query
GL_FUNC_DEF  PFNGLBEGINPERFQUERYINTELPROC                           glBeginPerfQueryINTEL                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATEPERFQUERYINTELPROC                          glCreatePerfQueryINTEL                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEPERFQUERYINTELPROC                          glDeletePerfQueryINTEL                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENDPERFQUERYINTELPROC                             glEndPerfQueryINTEL                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFIRSTPERFQUERYIDINTELPROC                      glGetFirstPerfQueryIdINTEL                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNEXTPERFQUERYIDINTELPROC                       glGetNextPerfQueryIdINTEL                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPERFCOUNTERINFOINTELPROC                       glGetPerfCounterInfoINTEL                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPERFQUERYDATAINTELPROC                         glGetPerfQueryDataINTEL                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPERFQUERYIDBYNAMEINTELPROC                     glGetPerfQueryIdByNameINTEL                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPERFQUERYINFOINTELPROC                         glGetPerfQueryInfoINTEL                                 GL_FUNC_DEF2     ;
#endif /* GL_INTEL_performance_query */



#ifdef GL_MESA_resize_buffers
GL_FUNC_DEF  PFNGLRESIZEBUFFERSMESAPROC               glResizeBuffersMESA                           GL_FUNC_DEF2     ;
#endif /* GL_MESA_resize_buffers */

#ifdef GL_MESA_window_pos
GL_FUNC_DEF  PFNGLWINDOWPOS2DMESAPROC                       glWindowPos2dMESA                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2DVMESAPROC                      glWindowPos2dvMESA                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2FMESAPROC                       glWindowPos2fMESA                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2FVMESAPROC                      glWindowPos2fvMESA                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2IMESAPROC                       glWindowPos2iMESA                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2IVMESAPROC                      glWindowPos2ivMESA                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2SMESAPROC                       glWindowPos2sMESA                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS2SVMESAPROC                      glWindowPos2svMESA                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3DMESAPROC                       glWindowPos3dMESA                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3DVMESAPROC                      glWindowPos3dvMESA                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3FMESAPROC                       glWindowPos3fMESA                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3FVMESAPROC                      glWindowPos3fvMESA                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3IMESAPROC                       glWindowPos3iMESA                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3IVMESAPROC                      glWindowPos3ivMESA                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3SMESAPROC                       glWindowPos3sMESA                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS3SVMESAPROC                      glWindowPos3svMESA                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS4DMESAPROC                       glWindowPos4dMESA                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS4DVMESAPROC                      glWindowPos4dvMESA                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS4FMESAPROC                       glWindowPos4fMESA                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS4FVMESAPROC                      glWindowPos4fvMESA                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS4IMESAPROC                       glWindowPos4iMESA                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS4IVMESAPROC                      glWindowPos4ivMESA                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS4SMESAPROC                       glWindowPos4sMESA                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWINDOWPOS4SVMESAPROC                      glWindowPos4svMESA                                GL_FUNC_DEF2     ;
#endif /* GL_MESA_window_pos */



#ifdef GL_NVX_conditional_render
GL_FUNC_DEF  PFNGLBEGINCONDITIONALRENDERNVXPROC                 glBeginConditionalRenderNVX                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENDCONDITIONALRENDERNVXPROC                   glEndConditionalRenderNVX                                GL_FUNC_DEF2     ;
#endif /* GL_NVX_conditional_render */

#ifdef GL_NVX_linked_gpu_multicast
GL_FUNC_DEF  PFNGLLGPUNAMEDBUFFERSUBDATANVXPROC                  glLGPUNamedBufferSubDataNVX                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLGPUCOPYIMAGESUBDATANVXPROC                    glLGPUCopyImageSubDataNVX                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLGPUINTERLOCKNVXPROC                           glLGPUInterlockNVX                                       GL_FUNC_DEF2     ;
#endif /* GL_NVX_linked_gpu_multicast */

	
#ifdef GL_NV_alpha_to_coverage_dither_control
GL_FUNC_DEF  PFNGLALPHATOCOVERAGEDITHERCONTROLNVPROC               glAlphaToCoverageDitherControlNV                           GL_FUNC_DEF2     ;
#endif /* GL_NV_alpha_to_coverage_dither_control */

#ifdef GL_NV_bindless_multi_draw_indirect
GL_FUNC_DEF  PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC                  glMultiDrawArraysIndirectBindlessNV                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC                glMultiDrawElementsIndirectBindlessNV                            GL_FUNC_DEF2     ;
#endif /* GL_NV_bindless_multi_draw_indirect */

#ifdef GL_NV_bindless_multi_draw_indirect_count
GL_FUNC_DEF  PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC                  glMultiDrawArraysIndirectBindlessCountNV                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC                glMultiDrawElementsIndirectBindlessCountNV                            GL_FUNC_DEF2     ;
#endif /* GL_NV_bindless_multi_draw_indirect_count */

#ifdef GL_NV_bindless_texture
GL_FUNC_DEF  PFNGLGETTEXTUREHANDLENVPROC                              glGetTextureHandleNV                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTEXTURESAMPLERHANDLENVPROC                       glGetTextureSamplerHandleNV                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAKETEXTUREHANDLERESIDENTNVPROC                     glMakeTextureHandleResidentNV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC                  glMakeTextureHandleNonResidentNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETIMAGEHANDLENVPROC                                glGetImageHandleNV                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAKEIMAGEHANDLERESIDENTNVPROC                       glMakeImageHandleResidentNV                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC                    glMakeImageHandleNonResidentNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMHANDLEUI64NVPROC                             glUniformHandleui64NV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMHANDLEUI64VNVPROC                            glUniformHandleui64vNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC                      glProgramUniformHandleui64NV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC                     glProgramUniformHandleui64vNV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISTEXTUREHANDLERESIDENTNVPROC                       glIsTextureHandleResidentNV                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISIMAGEHANDLERESIDENTNVPROC                         glIsImageHandleResidentNV                                      GL_FUNC_DEF2     ;
#endif /* GL_NV_bindless_texture */

#ifdef GL_NV_blend_equation_advanced
GL_FUNC_DEF  PFNGLBLENDPARAMETERINVPROC                 glBlendParameteriNV                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBLENDBARRIERNVPROC                    glBlendBarrierNV                                GL_FUNC_DEF2     ;
#endif /* GL_NV_blend_equation_advanced */

#ifdef GL_NV_clip_space_w_scaling
GL_FUNC_DEF  PFNGLVIEWPORTPOSITIONWSCALENVPROC               glViewportPositionWScaleNV                           GL_FUNC_DEF2     ;
#endif /* GL_NV_clip_space_w_scaling */

#ifdef GL_NV_command_list
GL_FUNC_DEF  PFNGLCREATESTATESNVPROC                                    glCreateStatesNV                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETESTATESNVPROC                                    glDeleteStatesNV                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISSTATENVPROC                                         glIsStateNV                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTATECAPTURENVPROC                                    glStateCaptureNV                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOMMANDHEADERNVPROC                                glGetCommandHeaderNV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSTAGEINDEXNVPROC                                   glGetStageIndexNV                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWCOMMANDSNVPROC                                    glDrawCommandsNV                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWCOMMANDSADDRESSNVPROC                             glDrawCommandsAddressNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWCOMMANDSSTATESNVPROC                              glDrawCommandsStatesNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC                       glDrawCommandsStatesAddressNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCREATECOMMANDLISTSNVPROC                              glCreateCommandListsNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETECOMMANDLISTSNVPROC                              glDeleteCommandListsNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISCOMMANDLISTNVPROC                                   glIsCommandListNV                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC                    glListDrawCommandsStatesClientNV                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMMANDLISTSEGMENTSNVPROC                             glCommandListSegmentsNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMPILECOMMANDLISTNVPROC                              glCompileCommandListNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCALLCOMMANDLISTNVPROC                                 glCallCommandListNV                                           GL_FUNC_DEF2     ;
#endif /* GL_NV_command_list */

#ifdef GL_NV_conditional_render
GL_FUNC_DEF  PFNGLBEGINCONDITIONALRENDERNVPROC               glBeginConditionalRenderNV                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENDCONDITIONALRENDERNVPROC                 glEndConditionalRenderNV                               GL_FUNC_DEF2     ;
#endif /* GL_NV_conditional_render */

#ifdef GL_NV_conservative_raster
GL_FUNC_DEF  PFNGLSUBPIXELPRECISIONBIASNVPROC               glSubpixelPrecisionBiasNV                           GL_FUNC_DEF2     ;
#endif /* GL_NV_conservative_raster */

#ifdef GL_NV_conservative_raster_dilate
GL_FUNC_DEF  PFNGLCONSERVATIVERASTERPARAMETERFNVPROC               glConservativeRasterParameterfNV                           GL_FUNC_DEF2     ;
#endif /* GL_NV_conservative_raster_dilate */

#ifdef GL_NV_conservative_raster_pre_snap_triangles
GL_FUNC_DEF  PFNGLCONSERVATIVERASTERPARAMETERINVPROC               glConservativeRasterParameteriNV                           GL_FUNC_DEF2     ;
#endif /* GL_NV_conservative_raster_pre_snap_triangles */

#ifdef GL_NV_copy_image
GL_FUNC_DEF  PFNGLCOPYIMAGESUBDATANVPROC               glCopyImageSubDataNV                           GL_FUNC_DEF2     ;
#endif /* GL_NV_copy_image */

#ifdef GL_NV_depth_buffer_float
GL_FUNC_DEF  PFNGLDEPTHRANGEDNVPROC                      glDepthRangedNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCLEARDEPTHDNVPROC                      glClearDepthdNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEPTHBOUNDSDNVPROC                     glDepthBoundsdNV                              GL_FUNC_DEF2     ;
#endif /* GL_NV_depth_buffer_float */

#ifdef GL_NV_draw_texture
GL_FUNC_DEF  PFNGLDRAWTEXTURENVPROC               glDrawTextureNV                           GL_FUNC_DEF2     ;
#endif /* GL_NV_draw_texture */

#ifdef GL_NV_draw_vulkan_image
GL_FUNC_DEF  PFNGLDRAWVKIMAGENVPROC                         glDrawVkImageNV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVKPROCADDRNVPROC                       glGetVkProcAddrNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWAITVKSEMAPHORENVPROC                     glWaitVkSemaphoreNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSIGNALVKSEMAPHORENVPROC                   glSignalVkSemaphoreNV                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSIGNALVKFENCENVPROC                       glSignalVkFenceNV                                 GL_FUNC_DEF2     ;
#endif /* GL_NV_draw_vulkan_image */

#ifdef GL_NV_evaluators
GL_FUNC_DEF  PFNGLMAPCONTROLPOINTSNVPROC                        glMapControlPointsNV                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAPPARAMETERIVNVPROC                          glMapParameterivNV                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAPPARAMETERFVNVPROC                          glMapParameterfvNV                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMAPCONTROLPOINTSNVPROC                     glGetMapControlPointsNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMAPPARAMETERIVNVPROC                       glGetMapParameterivNV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMAPPARAMETERFVNVPROC                       glGetMapParameterfvNV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMAPATTRIBPARAMETERIVNVPROC                 glGetMapAttribParameterivNV                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETMAPATTRIBPARAMETERFVNVPROC                 glGetMapAttribParameterfvNV                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLEVALMAPSNVPROC                                glEvalMapsNV                                            GL_FUNC_DEF2     ;
#endif /* GL_NV_evaluators */

#ifdef GL_NV_explicit_multisample
GL_FUNC_DEF  PFNGLGETMULTISAMPLEFVNVPROC                    glGetMultisamplefvNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSAMPLEMASKINDEXEDNVPROC                   glSampleMaskIndexedNV                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXRENDERBUFFERNVPROC                     glTexRenderbufferNV                                GL_FUNC_DEF2     ;
#endif /* GL_NV_explicit_multisample */

#ifdef GL_NV_fence
GL_FUNC_DEF  PFNGLDELETEFENCESNVPROC                      glDeleteFencesNV                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENFENCESNVPROC                         glGenFencesNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISFENCENVPROC                           glIsFenceNV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTESTFENCENVPROC                         glTestFenceNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFENCEIVNVPROC                        glGetFenceivNV                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFINISHFENCENVPROC                       glFinishFenceNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSETFENCENVPROC                          glSetFenceNV                                  GL_FUNC_DEF2     ;
#endif /* GL_NV_fence */

#ifdef GL_NV_fragment_coverage_to_color
GL_FUNC_DEF  PFNGLFRAGMENTCOVERAGECOLORNVPROC                       glFragmentCoverageColorNV                                              GL_FUNC_DEF2     ;
#endif /* GL_NV_fragment_coverage_to_color */

#ifdef GL_NV_fragment_program
GL_FUNC_DEF  PFNGLPROGRAMNAMEDPARAMETER4FNVPROC                        glProgramNamedParameter4fNV                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC                       glProgramNamedParameter4fvNV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMNAMEDPARAMETER4DNVPROC                        glProgramNamedParameter4dNV                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC                       glProgramNamedParameter4dvNV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC                     glGetProgramNamedParameterfvNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC                     glGetProgramNamedParameterdvNV                                        GL_FUNC_DEF2     ;
#endif /* GL_NV_fragment_program */

#ifdef GL_NV_framebuffer_mixed_samples
GL_FUNC_DEF  PFNGLCOVERAGEMODULATIONTABLENVPROC                        glCoverageModulationTableNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOVERAGEMODULATIONTABLENVPROC                     glGetCoverageModulationTableNV                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOVERAGEMODULATIONNVPROC                             glCoverageModulationNV                                            GL_FUNC_DEF2     ;
#endif /* GL_NV_framebuffer_mixed_samples */

#ifdef GL_NV_framebuffer_multisample_coverage
GL_FUNC_DEF  PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC                   glRenderbufferStorageMultisampleCoverageNV                               GL_FUNC_DEF2     ;
#endif /* GL_NV_framebuffer_multisample_coverage */

#ifdef GL_NV_geometry_program4
GL_FUNC_DEF  PFNGLPROGRAMVERTEXLIMITNVPROC                             glProgramVertexLimitNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERTEXTUREEXTPROC                            glFramebufferTextureEXT                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC                        glFramebufferTextureFaceEXT                                  GL_FUNC_DEF2     ;
#endif /* GL_NV_geometry_program4 */

#ifdef GL_NV_gpu_multicast
GL_FUNC_DEF  PFNGLRENDERGPUMASKNVPROC                                             glRenderGpuMaskNV                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTICASTBUFFERSUBDATANVPROC                                    glMulticastBufferSubDataNV                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTICASTCOPYBUFFERSUBDATANVPROC                                glMulticastCopyBufferSubDataNV                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTICASTCOPYIMAGESUBDATANVPROC                                 glMulticastCopyImageSubDataNV                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTICASTBLITFRAMEBUFFERNVPROC                                  glMulticastBlitFramebufferNV                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTICASTFRAMEBUFFERSAMPLELOCATIONSFVNVPROC                     glMulticastFramebufferSampleLocationsfvNV                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTICASTBARRIERNVPROC                                          glMulticastBarrierNV                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTICASTWAITSYNCNVPROC                                         glMulticastWaitSyncNV                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTICASTGETQUERYOBJECTIVNVPROC                                 glMulticastGetQueryObjectivNV                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTICASTGETQUERYOBJECTUIVNVPROC                                glMulticastGetQueryObjectuivNV                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTICASTGETQUERYOBJECTI64VNVPROC                               glMulticastGetQueryObjecti64vNV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTICASTGETQUERYOBJECTUI64VNVPROC                              glMulticastGetQueryObjectui64vNV                                         GL_FUNC_DEF2     ;
#endif /* GL_NV_gpu_multicast */

#ifdef GL_NV_gpu_program4
GL_FUNC_DEF  PFNGLPROGRAMLOCALPARAMETERI4INVPROC                          glProgramLocalParameterI4iNV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC                         glProgramLocalParameterI4ivNV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC                        glProgramLocalParametersI4ivNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMLOCALPARAMETERI4UINVPROC                         glProgramLocalParameterI4uiNV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC                        glProgramLocalParameterI4uivNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC                       glProgramLocalParametersI4uivNV                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMENVPARAMETERI4INVPROC                            glProgramEnvParameterI4iNV                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMENVPARAMETERI4IVNVPROC                           glProgramEnvParameterI4ivNV                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMENVPARAMETERSI4IVNVPROC                          glProgramEnvParametersI4ivNV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMENVPARAMETERI4UINVPROC                           glProgramEnvParameterI4uiNV                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMENVPARAMETERI4UIVNVPROC                          glProgramEnvParameterI4uivNV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC                         glProgramEnvParametersI4uivNV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC                       glGetProgramLocalParameterIivNV                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC                      glGetProgramLocalParameterIuivNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMENVPARAMETERIIVNVPROC                         glGetProgramEnvParameterIivNV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC                        glGetProgramEnvParameterIuivNV                                 GL_FUNC_DEF2     ;
#endif /* GL_NV_gpu_program4 */

#ifdef GL_NV_gpu_program5
GL_FUNC_DEF  PFNGLPROGRAMSUBROUTINEPARAMETERSUIVNVPROC                      glProgramSubroutineParametersuivNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMSUBROUTINEPARAMETERUIVNVPROC                    glGetProgramSubroutineParameteruivNV                               GL_FUNC_DEF2     ;
#endif /* GL_NV_gpu_program5 */

#ifdef GL_NV_half_float
GL_FUNC_DEF  PFNGLVERTEX2HNVPROC                                   glVertex2hNV                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEX2HVNVPROC                                  glVertex2hvNV                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEX3HNVPROC                                   glVertex3hNV                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEX3HVNVPROC                                  glVertex3hvNV                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEX4HNVPROC                                   glVertex4hNV                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEX4HVNVPROC                                  glVertex4hvNV                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMAL3HNVPROC                                   glNormal3hNV                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMAL3HVNVPROC                                  glNormal3hvNV                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLOR3HNVPROC                                    glColor3hNV                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLOR3HVNVPROC                                   glColor3hvNV                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLOR4HNVPROC                                    glColor4hNV                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLOR4HVNVPROC                                   glColor4hvNV                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD1HNVPROC                                 glTexCoord1hNV                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD1HVNVPROC                                glTexCoord1hvNV                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD2HNVPROC                                 glTexCoord2hNV                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD2HVNVPROC                                glTexCoord2hvNV                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD3HNVPROC                                 glTexCoord3hNV                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD3HVNVPROC                                glTexCoord3hvNV                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD4HNVPROC                                 glTexCoord4hNV                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD4HVNVPROC                                glTexCoord4hvNV                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1HNVPROC                            glMultiTexCoord1hNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD1HVNVPROC                           glMultiTexCoord1hvNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2HNVPROC                            glMultiTexCoord2hNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD2HVNVPROC                           glMultiTexCoord2hvNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3HNVPROC                            glMultiTexCoord3hNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD3HVNVPROC                           glMultiTexCoord3hvNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4HNVPROC                            glMultiTexCoord4hNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMULTITEXCOORD4HVNVPROC                           glMultiTexCoord4hvNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFOGCOORDHNVPROC                                  glFogCoordhNV                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFOGCOORDHVNVPROC                                 glFogCoordhvNV                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3HNVPROC                           glSecondaryColor3hNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLOR3HVNVPROC                          glSecondaryColor3hvNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXWEIGHTHNVPROC                              glVertexWeighthNV                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXWEIGHTHVNVPROC                             glVertexWeighthvNV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1HNVPROC                             glVertexAttrib1hNV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1HVNVPROC                            glVertexAttrib1hvNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2HNVPROC                             glVertexAttrib2hNV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2HVNVPROC                            glVertexAttrib2hvNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3HNVPROC                             glVertexAttrib3hNV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3HVNVPROC                            glVertexAttrib3hvNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4HNVPROC                             glVertexAttrib4hNV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4HVNVPROC                            glVertexAttrib4hvNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBS1HVNVPROC                           glVertexAttribs1hvNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBS2HVNVPROC                           glVertexAttribs2hvNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBS3HVNVPROC                           glVertexAttribs3hvNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBS4HVNVPROC                           glVertexAttribs4hvNV                                        GL_FUNC_DEF2     ;
#endif /* GL_NV_half_float */

#ifdef GL_NV_internalformat_sample_query
GL_FUNC_DEF  PFNGLGETINTERNALFORMATSAMPLEIVNVPROC                     glGetInternalformatSampleivNV                                    GL_FUNC_DEF2     ;
#endif /* GL_NV_internalformat_sample_query */

#ifdef GL_NV_occlusion_query
GL_FUNC_DEF  PFNGLGENOCCLUSIONQUERIESNVPROC                          glGenOcclusionQueriesNV                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEOCCLUSIONQUERIESNVPROC                       glDeleteOcclusionQueriesNV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISOCCLUSIONQUERYNVPROC                             glIsOcclusionQueryNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBEGINOCCLUSIONQUERYNVPROC                          glBeginOcclusionQueryNV                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENDOCCLUSIONQUERYNVPROC                            glEndOcclusionQueryNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETOCCLUSIONQUERYIVNVPROC                          glGetOcclusionQueryivNV                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETOCCLUSIONQUERYUIVNVPROC                         glGetOcclusionQueryuivNV                                    GL_FUNC_DEF2     ;
#endif /* GL_NV_occlusion_query */

#ifdef GL_NV_parameter_buffer_object
GL_FUNC_DEF  PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC                      glProgramBufferParametersfvNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC                     glProgramBufferParametersIivNV                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC                    glProgramBufferParametersIuivNV                               GL_FUNC_DEF2     ;
#endif /* GL_NV_parameter_buffer_object */

#ifdef GL_NV_path_rendering
GL_FUNC_DEF  PFNGLGENPATHSNVPROC                                              glGenPathsNV                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEPATHSNVPROC                                           glDeletePathsNV                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISPATHNVPROC                                                glIsPathNV                                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHCOMMANDSNVPROC                                          glPathCommandsNV                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHCOORDSNVPROC                                            glPathCoordsNV                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHSUBCOMMANDSNVPROC                                       glPathSubCommandsNV                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHSUBCOORDSNVPROC                                         glPathSubCoordsNV                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHSTRINGNVPROC                                            glPathStringNV                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHGLYPHSNVPROC                                            glPathGlyphsNV                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHGLYPHRANGENVPROC                                        glPathGlyphRangeNV                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLWEIGHTPATHSNVPROC                                           glWeightPathsNV                                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYPATHNVPROC                                              glCopyPathNV                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLINTERPOLATEPATHSNVPROC                                      glInterpolatePathsNV                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTRANSFORMPATHNVPROC                                         glTransformPathNV                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHPARAMETERIVNVPROC                                       glPathParameterivNV                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHPARAMETERINVPROC                                        glPathParameteriNV                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHPARAMETERFVNVPROC                                       glPathParameterfvNV                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHPARAMETERFNVPROC                                        glPathParameterfNV                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHDASHARRAYNVPROC                                         glPathDashArrayNV                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHSTENCILFUNCNVPROC                                       glPathStencilFuncNV                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHSTENCILDEPTHOFFSETNVPROC                                glPathStencilDepthOffsetNV                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTENCILFILLPATHNVPROC                                       glStencilFillPathNV                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTENCILSTROKEPATHNVPROC                                     glStencilStrokePathNV                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTENCILFILLPATHINSTANCEDNVPROC                              glStencilFillPathInstancedNV                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC                            glStencilStrokePathInstancedNV                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHCOVERDEPTHFUNCNVPROC                                    glPathCoverDepthFuncNV                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOVERFILLPATHNVPROC                                         glCoverFillPathNV                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOVERSTROKEPATHNVPROC                                       glCoverStrokePathNV                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOVERFILLPATHINSTANCEDNVPROC                                glCoverFillPathInstancedNV                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOVERSTROKEPATHINSTANCEDNVPROC                              glCoverStrokePathInstancedNV                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPATHPARAMETERIVNVPROC                                    glGetPathParameterivNV                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPATHPARAMETERFVNVPROC                                    glGetPathParameterfvNV                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPATHCOMMANDSNVPROC                                       glGetPathCommandsNV                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPATHCOORDSNVPROC                                         glGetPathCoordsNV                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPATHDASHARRAYNVPROC                                      glGetPathDashArrayNV                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPATHMETRICSNVPROC                                        glGetPathMetricsNV                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPATHMETRICRANGENVPROC                                    glGetPathMetricRangeNV                                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPATHSPACINGNVPROC                                        glGetPathSpacingNV                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISPOINTINFILLPATHNVPROC                                     glIsPointInFillPathNV                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISPOINTINSTROKEPATHNVPROC                                   glIsPointInStrokePathNV                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPATHLENGTHNVPROC                                         glGetPathLengthNV                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOINTALONGPATHNVPROC                                        glPointAlongPathNV                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXLOAD3X2FNVPROC                                        glMatrixLoad3x2fNV                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXLOAD3X3FNVPROC                                        glMatrixLoad3x3fNV                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC                               glMatrixLoadTranspose3x3fNV                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXMULT3X2FNVPROC                                        glMatrixMult3x2fNV                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXMULT3X3FNVPROC                                        glMatrixMult3x3fNV                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC                               glMatrixMultTranspose3x3fNV                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTENCILTHENCOVERFILLPATHNVPROC                              glStencilThenCoverFillPathNV                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC                            glStencilThenCoverStrokePathNV                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC                     glStencilThenCoverFillPathInstancedNV                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC                   glStencilThenCoverStrokePathInstancedNV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHGLYPHINDEXRANGENVPROC                                   glPathGlyphIndexRangeNV                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHGLYPHINDEXARRAYNVPROC                                   glPathGlyphIndexArrayNV                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC                             glPathMemoryGlyphIndexArrayNV                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC                           glProgramPathFragmentInputGenNV                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMRESOURCEFVNVPROC                                  glGetProgramResourcefvNV                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHCOLORGENNVPROC                                          glPathColorGenNV                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHTEXGENNVPROC                                            glPathTexGenNV                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPATHFOGGENNVPROC                                            glPathFogGenNV                                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPATHCOLORGENIVNVPROC                                     glGetPathColorGenivNV                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPATHCOLORGENFVNVPROC                                     glGetPathColorGenfvNV                                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPATHTEXGENIVNVPROC                                       glGetPathTexGenivNV                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPATHTEXGENFVNVPROC                                       glGetPathTexGenfvNV                                                       GL_FUNC_DEF2     ;
#endif /* GL_NV_path_rendering */

#ifdef GL_NV_pixel_data_range
GL_FUNC_DEF  PFNGLPIXELDATARANGENVPROC                            glPixelDataRangeNV                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFLUSHPIXELDATARANGENVPROC                       glFlushPixelDataRangeNV                                         GL_FUNC_DEF2     ;
#endif /* GL_NV_pixel_data_range */

#ifdef GL_NV_point_sprite
GL_FUNC_DEF  PFNGLPOINTPARAMETERINVPROC                          glPointParameteriNV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOINTPARAMETERIVNVPROC                         glPointParameterivNV                                         GL_FUNC_DEF2     ;
#endif /* GL_NV_point_sprite */

#ifdef GL_NV_present_video
GL_FUNC_DEF  PFNGLPRESENTFRAMEKEYEDNVPROC                          glPresentFrameKeyedNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPRESENTFRAMEDUALFILLNVPROC                       glPresentFrameDualFillNV                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVIDEOIVNVPROC                                 glGetVideoivNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVIDEOUIVNVPROC                                glGetVideouivNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVIDEOI64VNVPROC                               glGetVideoi64vNV                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVIDEOUI64VNVPROC                              glGetVideoui64vNV                                     GL_FUNC_DEF2     ;
#endif /* GL_NV_present_video */

#ifdef GL_NV_primitive_restart
GL_FUNC_DEF  PFNGLPRIMITIVERESTARTNVPROC                           glPrimitiveRestartNV                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPRIMITIVERESTARTINDEXNVPROC                      glPrimitiveRestartIndexNV                               GL_FUNC_DEF2     ;
#endif /* GL_NV_primitive_restart */

#ifdef GL_NV_query_resource
GL_FUNC_DEF  PFNGLQUERYRESOURCENVPROC                           glQueryResourceNV                                       GL_FUNC_DEF2     ;
#endif /* GL_NV_query_resource */

#ifdef GL_NV_query_resource_tag
GL_FUNC_DEF  PFNGLGENQUERYRESOURCETAGNVPROC                          glGenQueryResourceTagNV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEQUERYRESOURCETAGNVPROC                       glDeleteQueryResourceTagNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLQUERYRESOURCETAGNVPROC                             glQueryResourceTagNV                                     GL_FUNC_DEF2     ;
#endif /* GL_NV_query_resource_tag */

#ifdef GL_NV_register_combiners
GL_FUNC_DEF  PFNGLCOMBINERPARAMETERFVNVPROC                                 glCombinerParameterfvNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMBINERPARAMETERFNVPROC                                  glCombinerParameterfNV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMBINERPARAMETERIVNVPROC                                 glCombinerParameterivNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMBINERPARAMETERINVPROC                                  glCombinerParameteriNV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMBINERINPUTNVPROC                                       glCombinerInputNV                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOMBINEROUTPUTNVPROC                                      glCombinerOutputNV                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFINALCOMBINERINPUTNVPROC                                  glFinalCombinerInputNV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC                         glGetCombinerInputParameterfvNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC                         glGetCombinerInputParameterivNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC                        glGetCombinerOutputParameterfvNV                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC                        glGetCombinerOutputParameterivNV                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC                    glGetFinalCombinerInputParameterfvNV                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC                    glGetFinalCombinerInputParameterivNV                            GL_FUNC_DEF2     ;
#endif /* GL_NV_register_combiners */

#ifdef GL_NV_register_combiners2
GL_FUNC_DEF  PFNGLCOMBINERSTAGEPARAMETERFVNVPROC                        glCombinerStageParameterfvNV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC                     glGetCombinerStageParameterfvNV                               GL_FUNC_DEF2     ;
#endif /* GL_NV_register_combiners2 */

#ifdef GL_NV_sample_locations
GL_FUNC_DEF  PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC                         glFramebufferSampleLocationsfvNV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC                    glNamedFramebufferSampleLocationsfvNV                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRESOLVEDEPTHVALUESNVPROC                                   glResolveDepthValuesNV                                             GL_FUNC_DEF2     ;
#endif /* GL_NV_sample_locations */

#ifdef GL_NV_shader_buffer_load
GL_FUNC_DEF  PFNGLMAKEBUFFERRESIDENTNVPROC                               glMakeBufferResidentNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAKEBUFFERNONRESIDENTNVPROC                            glMakeBufferNonResidentNV                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISBUFFERRESIDENTNVPROC                                 glIsBufferResidentNV                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAKENAMEDBUFFERRESIDENTNVPROC                          glMakeNamedBufferResidentNV                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC                       glMakeNamedBufferNonResidentNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISNAMEDBUFFERRESIDENTNVPROC                            glIsNamedBufferResidentNV                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETBUFFERPARAMETERUI64VNVPROC                          glGetBufferParameterui64vNV                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC                     glGetNamedBufferParameterui64vNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETINTEGERUI64VNVPROC                                  glGetIntegerui64vNV                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMUI64NVPROC                                      glUniformui64NV                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLUNIFORMUI64VNVPROC                                     glUniformui64vNV                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETUNIFORMUI64VNVPROC                                  glGetUniformui64vNV                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMUI64NVPROC                               glProgramUniformui64NV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMUNIFORMUI64VNVPROC                              glProgramUniformui64vNV                                        GL_FUNC_DEF2     ;
#endif /* GL_NV_shader_buffer_load */

#ifdef GL_NV_texture_barrier
GL_FUNC_DEF  PFNGLTEXTUREBARRIERNVPROC                        glTextureBarrierNV                                   GL_FUNC_DEF2     ;
#endif /* GL_NV_texture_barrier */

#ifdef GL_NV_texture_multisample
GL_FUNC_DEF  PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC                        glTexImage2DMultisampleCoverageNV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC                        glTexImage3DMultisampleCoverageNV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC                            glTextureImage2DMultisampleNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC                            glTextureImage3DMultisampleNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC                    glTextureImage2DMultisampleCoverageNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC                    glTextureImage3DMultisampleCoverageNV                               GL_FUNC_DEF2     ;
#endif /* GL_NV_texture_multisample */

#ifdef GL_NV_transform_feedback
GL_FUNC_DEF  PFNGLBEGINTRANSFORMFEEDBACKNVPROC                            glBeginTransformFeedbackNV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENDTRANSFORMFEEDBACKNVPROC                              glEndTransformFeedbackNV                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC                          glTransformFeedbackAttribsNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDBUFFERRANGENVPROC                                   glBindBufferRangeNV                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDBUFFEROFFSETNVPROC                                  glBindBufferOffsetNV                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDBUFFERBASENVPROC                                    glBindBufferBaseNV                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC                         glTransformFeedbackVaryingsNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLACTIVEVARYINGNVPROC                                     glActiveVaryingNV                                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVARYINGLOCATIONNVPROC                                glGetVaryingLocationNV                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETACTIVEVARYINGNVPROC                                  glGetActiveVaryingNV                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC                       glGetTransformFeedbackVaryingNV                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTRANSFORMFEEDBACKSTREAMATTRIBSNVPROC                    glTransformFeedbackStreamAttribsNV                                  GL_FUNC_DEF2     ;
#endif /* GL_NV_transform_feedback */

#ifdef GL_NV_transform_feedback2
GL_FUNC_DEF  PFNGLBINDTRANSFORMFEEDBACKNVPROC                            glBindTransformFeedbackNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETETRANSFORMFEEDBACKSNVPROC                         glDeleteTransformFeedbacksNV                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENTRANSFORMFEEDBACKSNVPROC                            glGenTransformFeedbacksNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISTRANSFORMFEEDBACKNVPROC                              glIsTransformFeedbackNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPAUSETRANSFORMFEEDBACKNVPROC                           glPauseTransformFeedbackNV                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLRESUMETRANSFORMFEEDBACKNVPROC                          glResumeTransformFeedbackNV                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDRAWTRANSFORMFEEDBACKNVPROC                            glDrawTransformFeedbackNV                                       GL_FUNC_DEF2     ;
#endif /* GL_NV_transform_feedback2 */

#ifdef GL_NV_vdpau_interop
GL_FUNC_DEF  PFNGLVDPAUINITNVPROC                                       glVDPAUInitNV                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVDPAUFININVPROC                                       glVDPAUFiniNV                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVDPAUREGISTERVIDEOSURFACENVPROC                       glVDPAURegisterVideoSurfaceNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVDPAUREGISTEROUTPUTSURFACENVPROC                      glVDPAURegisterOutputSurfaceNV                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVDPAUISSURFACENVPROC                                  glVDPAUIsSurfaceNV                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVDPAUUNREGISTERSURFACENVPROC                          glVDPAUUnregisterSurfaceNV                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVDPAUGETSURFACEIVNVPROC                               glVDPAUGetSurfaceivNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVDPAUSURFACEACCESSNVPROC                              glVDPAUSurfaceAccessNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVDPAUMAPSURFACESNVPROC                                glVDPAUMapSurfacesNV                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVDPAUUNMAPSURFACESNVPROC                              glVDPAUUnmapSurfacesNV                                        GL_FUNC_DEF2     ;
#endif /* GL_NV_vdpau_interop */

#ifdef GL_NV_vertex_array_range
GL_FUNC_DEF  PFNGLFLUSHVERTEXARRAYRANGENVPROC                       glFlushVertexArrayRangeNV                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXARRAYRANGENVPROC                            glVertexArrayRangeNV                                   GL_FUNC_DEF2     ;
#endif /* GL_NV_vertex_array_range */

#ifdef GL_NV_vertex_attrib_integer_64bit
GL_FUNC_DEF  PFNGLVERTEXATTRIBL1I64NVPROC                         glVertexAttribL1i64NV                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL2I64NVPROC                         glVertexAttribL2i64NV                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL3I64NVPROC                         glVertexAttribL3i64NV                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL4I64NVPROC                         glVertexAttribL4i64NV                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL1I64VNVPROC                        glVertexAttribL1i64vNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL2I64VNVPROC                        glVertexAttribL2i64vNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL3I64VNVPROC                        glVertexAttribL3i64vNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL4I64VNVPROC                        glVertexAttribL4i64vNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL1UI64NVPROC                        glVertexAttribL1ui64NV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL2UI64NVPROC                        glVertexAttribL2ui64NV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL3UI64NVPROC                        glVertexAttribL3ui64NV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL4UI64NVPROC                        glVertexAttribL4ui64NV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL1UI64VNVPROC                       glVertexAttribL1ui64vNV                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL2UI64VNVPROC                       glVertexAttribL2ui64vNV                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL3UI64VNVPROC                       glVertexAttribL3ui64vNV                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBL4UI64VNVPROC                       glVertexAttribL4ui64vNV                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBLI64VNVPROC                      glGetVertexAttribLi64vNV                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBLUI64VNVPROC                     glGetVertexAttribLui64vNV                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBLFORMATNVPROC                       glVertexAttribLFormatNV                              GL_FUNC_DEF2     ;
#endif /* GL_NV_vertex_attrib_integer_64bit */

#ifdef GL_NV_vertex_buffer_unified_memory
GL_FUNC_DEF  PFNGLBUFFERADDRESSRANGENVPROC                           glBufferAddressRangeNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXFORMATNVPROC                                 glVertexFormatNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMALFORMATNVPROC                                 glNormalFormatNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLORFORMATNVPROC                                  glColorFormatNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLINDEXFORMATNVPROC                                  glIndexFormatNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORDFORMATNVPROC                               glTexCoordFormatNV                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLEDGEFLAGFORMATNVPROC                               glEdgeFlagFormatNV                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSECONDARYCOLORFORMATNVPROC                         glSecondaryColorFormatNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFOGCOORDFORMATNVPROC                               glFogCoordFormatNV                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBFORMATNVPROC                           glVertexAttribFormatNV                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBIFORMATNVPROC                          glVertexAttribIFormatNV                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETINTEGERUI64I_VNVPROC                            glGetIntegerui64i_vNV                                  GL_FUNC_DEF2     ;
#endif /* GL_NV_vertex_buffer_unified_memory */

#ifdef GL_NV_vertex_program
GL_FUNC_DEF  PFNGLAREPROGRAMSRESIDENTNVPROC                              glAreProgramsResidentNV                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDPROGRAMNVPROC                                      glBindProgramNV                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEPROGRAMSNVPROC                                   glDeleteProgramsNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLEXECUTEPROGRAMNVPROC                                   glExecuteProgramNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENPROGRAMSNVPROC                                      glGenProgramsNV                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMPARAMETERDVNVPROC                            glGetProgramParameterdvNV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMPARAMETERFVNVPROC                            glGetProgramParameterfvNV                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMIVNVPROC                                     glGetProgramivNV                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPROGRAMSTRINGNVPROC                                 glGetProgramStringNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETTRACKMATRIXIVNVPROC                                 glGetTrackMatrixivNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBDVNVPROC                                glGetVertexAttribdvNV                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBFVNVPROC                                glGetVertexAttribfvNV                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBIVNVPROC                                glGetVertexAttribivNV                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBPOINTERVNVPROC                          glGetVertexAttribPointervNV                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISPROGRAMNVPROC                                        glIsProgramNV                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLOADPROGRAMNVPROC                                      glLoadProgramNV                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMPARAMETER4DNVPROC                               glProgramParameter4dNV                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMPARAMETER4DVNVPROC                              glProgramParameter4dvNV                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMPARAMETER4FNVPROC                               glProgramParameter4fNV                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMPARAMETER4FVNVPROC                              glProgramParameter4fvNV                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMPARAMETERS4DVNVPROC                             glProgramParameters4dvNV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPROGRAMPARAMETERS4FVNVPROC                             glProgramParameters4fvNV                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREQUESTRESIDENTPROGRAMSNVPROC                          glRequestResidentProgramsNV                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTRACKMATRIXNVPROC                                      glTrackMatrixNV                                            GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBPOINTERNVPROC                              glVertexAttribPointerNV                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1DNVPROC                                   glVertexAttrib1dNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1DVNVPROC                                  glVertexAttrib1dvNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1FNVPROC                                   glVertexAttrib1fNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1FVNVPROC                                  glVertexAttrib1fvNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1SNVPROC                                   glVertexAttrib1sNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB1SVNVPROC                                  glVertexAttrib1svNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2DNVPROC                                   glVertexAttrib2dNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2DVNVPROC                                  glVertexAttrib2dvNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2FNVPROC                                   glVertexAttrib2fNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2FVNVPROC                                  glVertexAttrib2fvNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2SNVPROC                                   glVertexAttrib2sNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB2SVNVPROC                                  glVertexAttrib2svNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3DNVPROC                                   glVertexAttrib3dNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3DVNVPROC                                  glVertexAttrib3dvNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3FNVPROC                                   glVertexAttrib3fNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3FVNVPROC                                  glVertexAttrib3fvNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3SNVPROC                                   glVertexAttrib3sNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB3SVNVPROC                                  glVertexAttrib3svNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4DNVPROC                                   glVertexAttrib4dNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4DVNVPROC                                  glVertexAttrib4dvNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4FNVPROC                                   glVertexAttrib4fNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4FVNVPROC                                  glVertexAttrib4fvNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4SNVPROC                                   glVertexAttrib4sNV                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4SVNVPROC                                  glVertexAttrib4svNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4UBNVPROC                                  glVertexAttrib4ubNV                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIB4UBVNVPROC                                 glVertexAttrib4ubvNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBS1DVNVPROC                                 glVertexAttribs1dvNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBS1FVNVPROC                                 glVertexAttribs1fvNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBS1SVNVPROC                                 glVertexAttribs1svNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBS2DVNVPROC                                 glVertexAttribs2dvNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBS2FVNVPROC                                 glVertexAttribs2fvNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBS2SVNVPROC                                 glVertexAttribs2svNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBS3DVNVPROC                                 glVertexAttribs3dvNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBS3FVNVPROC                                 glVertexAttribs3fvNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBS3SVNVPROC                                 glVertexAttribs3svNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBS4DVNVPROC                                 glVertexAttribs4dvNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBS4FVNVPROC                                 glVertexAttribs4fvNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBS4SVNVPROC                                 glVertexAttribs4svNV                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBS4UBVNVPROC                                glVertexAttribs4ubvNV                                      GL_FUNC_DEF2     ;
#endif /* GL_NV_vertex_program */

#ifdef GL_NV_vertex_program4
GL_FUNC_DEF  PFNGLVERTEXATTRIBI1IEXTPROC                            glVertexAttribI1iEXT                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI2IEXTPROC                            glVertexAttribI2iEXT                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI3IEXTPROC                            glVertexAttribI3iEXT                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI4IEXTPROC                            glVertexAttribI4iEXT                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI1UIEXTPROC                           glVertexAttribI1uiEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI2UIEXTPROC                           glVertexAttribI2uiEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI3UIEXTPROC                           glVertexAttribI3uiEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI4UIEXTPROC                           glVertexAttribI4uiEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI1IVEXTPROC                           glVertexAttribI1ivEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI2IVEXTPROC                           glVertexAttribI2ivEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI3IVEXTPROC                           glVertexAttribI3ivEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI4IVEXTPROC                           glVertexAttribI4ivEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI1UIVEXTPROC                          glVertexAttribI1uivEXT                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI2UIVEXTPROC                          glVertexAttribI2uivEXT                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI3UIVEXTPROC                          glVertexAttribI3uivEXT                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI4UIVEXTPROC                          glVertexAttribI4uivEXT                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI4BVEXTPROC                           glVertexAttribI4bvEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI4SVEXTPROC                           glVertexAttribI4svEXT                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI4UBVEXTPROC                          glVertexAttribI4ubvEXT                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBI4USVEXTPROC                          glVertexAttribI4usvEXT                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVERTEXATTRIBIPOINTEREXTPROC                       glVertexAttribIPointerEXT                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBIIVEXTPROC                         glGetVertexAttribIivEXT                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVERTEXATTRIBIUIVEXTPROC                        glGetVertexAttribIuivEXT                                 GL_FUNC_DEF2     ;
#endif /* GL_NV_vertex_program4 */

#ifdef GL_NV_video_capture
GL_FUNC_DEF  PFNGLBEGINVIDEOCAPTURENVPROC                                   glBeginVideoCaptureNV                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDVIDEOCAPTURESTREAMBUFFERNVPROC                        glBindVideoCaptureStreamBufferNV                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLBINDVIDEOCAPTURESTREAMTEXTURENVPROC                       glBindVideoCaptureStreamTextureNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLENDVIDEOCAPTURENVPROC                                     glEndVideoCaptureNV                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVIDEOCAPTUREIVNVPROC                                   glGetVideoCaptureivNV                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVIDEOCAPTURESTREAMIVNVPROC                             glGetVideoCaptureStreamivNV                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVIDEOCAPTURESTREAMFVNVPROC                             glGetVideoCaptureStreamfvNV                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETVIDEOCAPTURESTREAMDVNVPROC                             glGetVideoCaptureStreamdvNV                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVIDEOCAPTURENVPROC                                        glVideoCaptureNV                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVIDEOCAPTURESTREAMPARAMETERIVNVPROC                       glVideoCaptureStreamParameterivNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVIDEOCAPTURESTREAMPARAMETERFVNVPROC                       glVideoCaptureStreamParameterfvNV                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLVIDEOCAPTURESTREAMPARAMETERDVNVPROC                       glVideoCaptureStreamParameterdvNV                               GL_FUNC_DEF2     ;
#endif /* GL_NV_video_capture */

#ifdef GL_NV_viewport_swizzle
GL_FUNC_DEF  PFNGLVIEWPORTSWIZZLENVPROC                            glViewportSwizzleNV                                       GL_FUNC_DEF2     ;
#endif /* GL_NV_viewport_swizzle */



#ifdef GL_OVR_multiview
GL_FUNC_DEF  PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC                       glFramebufferTextureMultiviewOVR                             GL_FUNC_DEF2     ;
#endif /* GL_OVR_multiview */



#ifdef GL_PGI_misc_hints
GL_FUNC_DEF  PFNGLHINTPGIPROC                            glHintPGI                                        GL_FUNC_DEF2     ;
#endif /* GL_PGI_misc_hints */



#ifdef GL_SGIS_detail_texture
GL_FUNC_DEF  PFNGLDETAILTEXFUNCSGISPROC                        glDetailTexFuncSGIS                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETDETAILTEXFUNCSGISPROC                     glGetDetailTexFuncSGIS                              GL_FUNC_DEF2     ;
#endif /* GL_SGIS_detail_texture */

#ifdef GL_SGIS_fog_function
GL_FUNC_DEF  PFNGLFOGFUNCSGISPROC                               glFogFuncSGIS                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFOGFUNCSGISPROC                            glGetFogFuncSGIS                                    GL_FUNC_DEF2     ;
#endif /* GL_SGIS_fog_function */

#ifdef GL_SGIS_multisample
GL_FUNC_DEF  PFNGLSAMPLEMASKSGISPROC                          glSampleMaskSGIS                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSAMPLEPATTERNSGISPROC                       glSamplePatternSGIS                                  GL_FUNC_DEF2     ;
#endif /* GL_SGIS_multisample */

#ifdef GL_SGIS_pixel_texture
GL_FUNC_DEF  PFNGLPIXELTEXGENPARAMETERISGISPROC                          glPixelTexGenParameteriSGIS                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPIXELTEXGENPARAMETERIVSGISPROC                         glPixelTexGenParameterivSGIS                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPIXELTEXGENPARAMETERFSGISPROC                          glPixelTexGenParameterfSGIS                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPIXELTEXGENPARAMETERFVSGISPROC                         glPixelTexGenParameterfvSGIS                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC                      glGetPixelTexGenParameterivSGIS                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC                      glGetPixelTexGenParameterfvSGIS                              GL_FUNC_DEF2     ;
#endif /* GL_SGIS_pixel_texture */

#ifdef GL_SGIS_point_parameters
GL_FUNC_DEF  PFNGLPOINTPARAMETERFSGISPROC                           glPointParameterfSGIS                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOINTPARAMETERFVSGISPROC                          glPointParameterfvSGIS                                  GL_FUNC_DEF2     ;
#endif /* GL_SGIS_point_parameters */

#ifdef GL_SGIS_sharpen_texture
GL_FUNC_DEF  PFNGLSHARPENTEXFUNCSGISPROC                          glSharpenTexFuncSGIS                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETSHARPENTEXFUNCSGISPROC                       glGetSharpenTexFuncSGIS                                GL_FUNC_DEF2     ;
#endif /* GL_SGIS_sharpen_texture */

#ifdef GL_SGIS_texture4D
GL_FUNC_DEF  PFNGLTEXIMAGE4DSGISPROC                           glTexImage4DSGIS                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXSUBIMAGE4DSGISPROC                        glTexSubImage4DSGIS                                   GL_FUNC_DEF2     ;
#endif /* GL_SGIS_texture4D */

#ifdef GL_SGIS_texture_color_mask
GL_FUNC_DEF  PFNGLTEXTURECOLORMASKSGISPROC                      glTextureColorMaskSGIS                                 GL_FUNC_DEF2     ;
#endif /* GL_SGIS_texture_color_mask */

#ifdef GL_SGIS_texture_filter4
GL_FUNC_DEF  PFNGLGETTEXFILTERFUNCSGISPROC                        glGetTexFilterFuncSGIS                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXFILTERFUNCSGISPROC                           glTexFilterFuncSGIS                                     GL_FUNC_DEF2     ;
#endif /* GL_SGIS_texture_filter4 */



#ifdef GL_SGIX_async
GL_FUNC_DEF  PFNGLASYNCMARKERSGIXPROC                                 glAsyncMarkerSGIX                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFINISHASYNCSGIXPROC                                 glFinishAsyncSGIX                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOLLASYNCSGIXPROC                                   glPollAsyncSGIX                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGENASYNCMARKERSSGIXPROC                             glGenAsyncMarkersSGIX                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDELETEASYNCMARKERSSGIXPROC                          glDeleteAsyncMarkersSGIX                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLISASYNCMARKERSGIXPROC                               glIsAsyncMarkerSGIX                                    GL_FUNC_DEF2     ;
#endif /* GL_SGIX_async */

#ifdef GL_SGIX_flush_raster
GL_FUNC_DEF  PFNGLFLUSHRASTERSGIXPROC                           glFlushRasterSGIX                                      GL_FUNC_DEF2     ;
#endif /* GL_SGIX_flush_raster */

#ifdef GL_SGIX_fragment_lighting
GL_FUNC_DEF  PFNGLFRAGMENTCOLORMATERIALSGIXPROC                          glFragmentColorMaterialSGIX                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAGMENTLIGHTFSGIXPROC                                 glFragmentLightfSGIX                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAGMENTLIGHTFVSGIXPROC                                glFragmentLightfvSGIX                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAGMENTLIGHTISGIXPROC                                 glFragmentLightiSGIX                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAGMENTLIGHTIVSGIXPROC                                glFragmentLightivSGIX                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAGMENTLIGHTMODELFSGIXPROC                            glFragmentLightModelfSGIX                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAGMENTLIGHTMODELFVSGIXPROC                           glFragmentLightModelfvSGIX                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAGMENTLIGHTMODELISGIXPROC                            glFragmentLightModeliSGIX                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAGMENTLIGHTMODELIVSGIXPROC                           glFragmentLightModelivSGIX                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAGMENTMATERIALFSGIXPROC                              glFragmentMaterialfSGIX                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAGMENTMATERIALFVSGIXPROC                             glFragmentMaterialfvSGIX                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAGMENTMATERIALISGIXPROC                              glFragmentMaterialiSGIX                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLFRAGMENTMATERIALIVSGIXPROC                             glFragmentMaterialivSGIX                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFRAGMENTLIGHTFVSGIXPROC                             glGetFragmentLightfvSGIX                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFRAGMENTLIGHTIVSGIXPROC                             glGetFragmentLightivSGIX                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFRAGMENTMATERIALFVSGIXPROC                          glGetFragmentMaterialfvSGIX                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETFRAGMENTMATERIALIVSGIXPROC                          glGetFragmentMaterialivSGIX                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLIGHTENVISGIXPROC                                      glLightEnviSGIX                                          GL_FUNC_DEF2     ;
#endif /* GL_SGIX_fragment_lighting */

#ifdef GL_SGIX_framezoom
GL_FUNC_DEF  PFNGLFRAMEZOOMSGIXPROC                             glFrameZoomSGIX                                       GL_FUNC_DEF2     ;
#endif /* GL_SGIX_framezoom */

#ifdef GL_SGIX_igloo_interface
GL_FUNC_DEF  PFNGLIGLOOINTERFACESGIXPROC                         glIglooInterfaceSGIX                                   GL_FUNC_DEF2     ;
#endif /* GL_SGIX_igloo_interface */

#ifdef GL_SGIX_instruments
GL_FUNC_DEF  PFNGLGETINSTRUMENTSSGIXPROC                         glGetInstrumentsSGIX                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLINSTRUMENTSBUFFERSGIXPROC                      glInstrumentsBufferSGIX                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLPOLLINSTRUMENTSSGIXPROC                        glPollInstrumentsSGIX                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREADINSTRUMENTSSGIXPROC                        glReadInstrumentsSGIX                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTARTINSTRUMENTSSGIXPROC                       glStartInstrumentsSGIX                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSTOPINSTRUMENTSSGIXPROC                        glStopInstrumentsSGIX                                 GL_FUNC_DEF2     ;
#endif /* GL_SGIX_instruments */

#ifdef GL_SGIX_list_priority
GL_FUNC_DEF  PFNGLGETLISTPARAMETERFVSGIXPROC                 glGetListParameterfvSGIX                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETLISTPARAMETERIVSGIXPROC                 glGetListParameterivSGIX                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLISTPARAMETERFSGIXPROC                     glListParameterfSGIX                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLISTPARAMETERFVSGIXPROC                    glListParameterfvSGIX                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLISTPARAMETERISGIXPROC                     glListParameteriSGIX                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLISTPARAMETERIVSGIXPROC                    glListParameterivSGIX                                GL_FUNC_DEF2     ;
#endif /* GL_SGIX_list_priority */

#ifdef GL_SGIX_pixel_texture
GL_FUNC_DEF  PFNGLPIXELTEXGENSGIXPROC               glPixelTexGenSGIX                            GL_FUNC_DEF2     ;
#endif /* GL_SGIX_pixel_texture */

#ifdef GL_SGIX_polynomial_ffd
GL_FUNC_DEF  PFNGLDEFORMATIONMAP3DSGIXPROC                             glDeformationMap3dSGIX                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEFORMATIONMAP3FSGIXPROC                             glDeformationMap3fSGIX                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLDEFORMSGIXPROC                                       glDeformSGIX                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC                   glLoadIdentityDeformationMapSGIX                              GL_FUNC_DEF2     ;
#endif /* GL_SGIX_polynomial_ffd */

#ifdef GL_SGIX_reference_plane
GL_FUNC_DEF  PFNGLREFERENCEPLANESGIXPROC               glReferencePlaneSGIX                           GL_FUNC_DEF2     ;
#endif /* GL_SGIX_reference_plane */

#ifdef GL_SGIX_sprite
GL_FUNC_DEF  PFNGLSPRITEPARAMETERFSGIXPROC                  glSpriteParameterfSGIX                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSPRITEPARAMETERFVSGIXPROC                 glSpriteParameterfvSGIX                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSPRITEPARAMETERISGIXPROC                  glSpriteParameteriSGIX                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLSPRITEPARAMETERIVSGIXPROC                 glSpriteParameterivSGIX                              GL_FUNC_DEF2     ;
#endif /* GL_SGIX_sprite */

#ifdef GL_SGIX_subsample
GL_FUNC_DEF  PFNGLTAGSAMPLEBUFFERSGIXPROC               glTagSampleBufferSGIX                           GL_FUNC_DEF2     ;
#endif /* GL_SGIX_tag_sample_buffer */



#ifdef GL_SGI_color_table
GL_FUNC_DEF  PFNGLCOLORTABLESGIPROC                                  glColorTableSGI                                           GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLORTABLEPARAMETERFVSGIPROC                       glColorTableParameterfvSGI                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLORTABLEPARAMETERIVSGIPROC                       glColorTableParameterivSGI                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOPYCOLORTABLESGIPROC                              glCopyColorTableSGI                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOLORTABLESGIPROC                               glGetColorTableSGI                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOLORTABLEPARAMETERFVSGIPROC                    glGetColorTableParameterfvSGI                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGETCOLORTABLEPARAMETERIVSGIPROC                    glGetColorTableParameterivSGI                             GL_FUNC_DEF2     ;
#endif /* GL_SGI_color_table */



#ifdef GL_SUNX_constant_data
GL_FUNC_DEF  PFNGLFINISHTEXTURESUNXPROC               glFinishTextureSUNX                           GL_FUNC_DEF2     ;
#endif /* GL_SUNX_constant_data */



#ifdef GL_SUN_global_alpha
GL_FUNC_DEF  PFNGLGLOBALALPHAFACTORBSUNPROC                  glGlobalAlphaFactorbSUN                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGLOBALALPHAFACTORSSUNPROC                  glGlobalAlphaFactorsSUN                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGLOBALALPHAFACTORISUNPROC                  glGlobalAlphaFactoriSUN                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGLOBALALPHAFACTORFSUNPROC                  glGlobalAlphaFactorfSUN                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGLOBALALPHAFACTORDSUNPROC                  glGlobalAlphaFactordSUN                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGLOBALALPHAFACTORUBSUNPROC                 glGlobalAlphaFactorubSUN                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGLOBALALPHAFACTORUSSUNPROC                 glGlobalAlphaFactorusSUN                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLGLOBALALPHAFACTORUISUNPROC                 glGlobalAlphaFactoruiSUN                               GL_FUNC_DEF2     ;
#endif /* GL_SUN_global_alpha */

#ifdef GL_SUN_mesh_array
GL_FUNC_DEF  PFNGLDRAWMESHARRAYSSUNPROC               glDrawMeshArraysSUN                           GL_FUNC_DEF2     ;
#endif /* GL_SUN_mesh_array */

#ifdef GL_SUN_triangle_list
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUISUNPROC                        glReplacementCodeuiSUN                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUSSUNPROC                        glReplacementCodeusSUN                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUBSUNPROC                        glReplacementCodeubSUN                                    GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUIVSUNPROC                       glReplacementCodeuivSUN                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUSVSUNPROC                       glReplacementCodeusvSUN                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUBVSUNPROC                       glReplacementCodeubvSUN                                   GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEPOINTERSUNPROC                   glReplacementCodePointerSUN                               GL_FUNC_DEF2     ;
#endif /* GL_SUN_triangle_list */

#ifdef GL_SUN_vertex
GL_FUNC_DEF  PFNGLCOLOR4UBVERTEX2FSUNPROC                                                        glColor4ubVertex2fSUN                                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLOR4UBVERTEX2FVSUNPROC                                                       glColor4ubVertex2fvSUN                                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLOR4UBVERTEX3FSUNPROC                                                        glColor4ubVertex3fSUN                                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLOR4UBVERTEX3FVSUNPROC                                                       glColor4ubVertex3fvSUN                                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLOR3FVERTEX3FSUNPROC                                                         glColor3fVertex3fSUN                                                                  GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLOR3FVERTEX3FVSUNPROC                                                        glColor3fVertex3fvSUN                                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMAL3FVERTEX3FSUNPROC                                                        glNormal3fVertex3fSUN                                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLNORMAL3FVERTEX3FVSUNPROC                                                       glNormal3fVertex3fvSUN                                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC                                                 glColor4fNormal3fVertex3fSUN                                                          GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC                                                glColor4fNormal3fVertex3fvSUN                                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD2FVERTEX3FSUNPROC                                                      glTexCoord2fVertex3fSUN                                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD2FVERTEX3FVSUNPROC                                                     glTexCoord2fVertex3fvSUN                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD4FVERTEX4FSUNPROC                                                      glTexCoord4fVertex4fSUN                                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD4FVERTEX4FVSUNPROC                                                     glTexCoord4fVertex4fvSUN                                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC                                              glTexCoord2fColor4ubVertex3fSUN                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC                                             glTexCoord2fColor4ubVertex3fvSUN                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC                                               glTexCoord2fColor3fVertex3fSUN                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC                                              glTexCoord2fColor3fVertex3fvSUN                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC                                              glTexCoord2fNormal3fVertex3fSUN                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC                                             glTexCoord2fNormal3fVertex3fvSUN                                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC                                       glTexCoord2fColor4fNormal3fVertex3fSUN                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC                                      glTexCoord2fColor4fNormal3fVertex3fvSUN                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC                                       glTexCoord4fColor4fNormal3fVertex4fSUN                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC                                      glTexCoord4fColor4fNormal3fVertex4fvSUN                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC                                               glReplacementCodeuiVertex3fSUN                                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC                                              glReplacementCodeuiVertex3fvSUN                                                       GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC                                       glReplacementCodeuiColor4ubVertex3fSUN                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC                                      glReplacementCodeuiColor4ubVertex3fvSUN                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC                                        glReplacementCodeuiColor3fVertex3fSUN                                                 GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC                                       glReplacementCodeuiColor3fVertex3fvSUN                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC                                       glReplacementCodeuiNormal3fVertex3fSUN                                                GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC                                      glReplacementCodeuiNormal3fVertex3fvSUN                                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC                                glReplacementCodeuiColor4fNormal3fVertex3fSUN                                         GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC                               glReplacementCodeuiColor4fNormal3fVertex3fvSUN                                        GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC                                     glReplacementCodeuiTexCoord2fVertex3fSUN                                              GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC                                    glReplacementCodeuiTexCoord2fVertex3fvSUN                                             GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC                             glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN                                      GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC                            glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN                                     GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC                      glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN                               GL_FUNC_DEF2     ;
GL_FUNC_DEF  PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC                     glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN                              GL_FUNC_DEF2     ;
#endif /* GL_SUN_vertex */



#ifdef __cplusplus
// }
#endif

#endif  /* GLFunctions_h */
#endif  /* GL_GLEXT_PROTOTYPES */




