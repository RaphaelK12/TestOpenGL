////#define GL_WIN_MAIN 1
#include "stdafx.h"
#include "ogl2.h"
#include "Utils.h"

//using namespace glm;

GLContext ctx;
int bQuit = false;
float theta = 0;
int nvert=0, nindex=0;
vec3 *vert;
vec3 *norm;
usvec3 *index;

int tnvert=0, tnindex=0;
vec3 *tvert;
vec3 *tnorm;
usvec3 *tindex;

class timer{
public:
	LONGLONG fr, // processador frequencia
			 c1, // primeiro tempo
			 c2; // segundo tempo
	timer(){
		//c2=c1=0;
		QueryPerformanceFrequency((LARGE_INTEGER *)&fr);
		QueryPerformanceCounter((LARGE_INTEGER *)&c1);
		c2 = c1;
	}
	~timer(){};
	void reset(){
		QueryPerformanceFrequency((LARGE_INTEGER *)&fr);
		QueryPerformanceCounter((LARGE_INTEGER *)&c1);
		c2 = c1;

	}
	LONGLONG get(){
		set();
		return c2-c1;
	}
	float getns(){
		set();
		return (c2-c1)*(1000000.0f/fr);
	}
	float getms(){
		set();
		return (c2-c1)*(1000000.0f/fr)/1000.0f;
	}
	float gets(){
		set();
		return (c2-c1)*(1000000.0f/fr)/1000000.0f;
	}
	double getdns(){
		return double((c2-c1)*(1000000.0/fr));
	}
	double getdms(){
		return double((c2-c1)*(1000000.0/fr)/1000.0);
	}
	double getds(){
		return double((c2-c1)*(1000000.0/fr)/1000000.0);
	}
	void set(){
		QueryPerformanceFrequency((LARGE_INTEGER *)&fr);
		QueryPerformanceCounter((LARGE_INTEGER *)&c2);

	}
	float getFPS(){
		return 1.0f/(getns()/1000000.0f);
	}
	float FPS(){
		set();
		return 1.0f/(getns()/1000000.0f);
	}


};


LONGLONG freq=0, count1=0, count2=0;
LONGLONG resetTime(){
	LONGLONG tmp = count1 - count2;
	QueryPerformanceCounter((LARGE_INTEGER *)&count1);
	QueryPerformanceCounter((LARGE_INTEGER *)&count2);
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
	return tmp;
}
float getTime(){
	return float((count2-count1)*(1000000.0/freq));
}
float setTime(){
	QueryPerformanceCounter((LARGE_INTEGER *)&count2);
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
	return float((count2-count1)*(1000000.0/freq));
}

LONGLONG resetTime2(){
	LONGLONG tmp = count1 - count2;
	count1 = __rdtsc();
	count2 = count1;
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
	return tmp;
}
float getTime2(){
	return float((count2-count1)*(1000000.0/freq));
}
float setTime2(){
	count2 = __rdtsc();
	return float((count2-count1)*(1000000.0/freq));
}

void printAsciiTable(){
	FILE * ASSItable = fopen("ASSItable.py", "wb");
	char c = 0;
	for(char i=0; i<16; i++){
		for(char j=0; j<16; j++){
			fprintf(ASSItable, "%c	", c);
			c++;
		}
		fprintf(ASSItable, "\r\n");
	}
	fclose(ASSItable);

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	static int cxClient, cyClient, lcxClient, lcyClient, iDeltaPerLine = 120, iAccumDelta;
	//int iVertPos, iHorzPos;
	//SCROLLINFO si;
	ULONG ulScrollLines = 1;
	static int xres, yres;
	PAINTSTRUCT ps;
	//HDC hdcMem, hdc;
	HDC hdc;
	//BITMAP bm;
	//HBITMAP hbmOld;
	RECT rc;

	switch(Message)
	{
		case WM_CREATE:
		{
			printf("WM_CREATE\n");
			//printf(a);
 			break;
		}
		case WM_NULL:
		{
			printf("WM_NULL\n");
 			//break;
		}
		case WM_SIZE:
		{
			GetWindowRect (hwnd, &rc);
			onResize( LOWORD (lParam), HIWORD (lParam),wParam, lParam);
 			break;
		}
		case WM_MOVE:
		{
			onMove(LOWORD (lParam), HIWORD (lParam),wParam, lParam);
 			break;
		}
		//case WM_VSCROLL:
		//{
		//	// Get all the vertical scroll bar information
		//	si.cbSize = sizeof (si);
		//	si.fMask = SIF_ALL | SIF_DISABLENOSCROLL;
		//	GetScrollInfo (hwnd, SB_VERT, &si);
		//	// Save the position for comparison later on
		//	iVertPos = si.nPos;
		//	switch (LOWORD (wParam))
		//	{
		//		case SB_TOP:
		//		{
		//			si.nPos = si.nMin;
		//			printf("WM_VSCROLL\n");
		//			break;
		//		}
		//		case SB_BOTTOM:
		//		{
		//			si.nPos = si.nMax;
		//			printf("WM_VSCROLL\n");
		//			break;
		//		}
		//		case SB_LINEUP:
		//		{
		//			si.nPos -= 15;
		//			printf("WM_VSCROLL\n");
		//			break;
		//		}
		//		case SB_LINEDOWN:
		//		{
		//			si.nPos += 15;
		//			break;
		//		}
		//		case SB_PAGEUP:
		//		{
		//			si.nPos -= si.nPage;
		//			printf("WM_VSCROLL\n");
		//			break;
		//		}
		//		case SB_PAGEDOWN:
		//		{
		//			si.nPos += si.nPage;
		//			printf("WM_VSCROLL\n");
		//			break;
		//		}
		//		case SB_THUMBPOSITION:
		//		{
		//			si.nPos = si.nTrackPos;
		//			//InvalidateRect(hwnd,NULL,true);
		//			//UpdateWindow (hwnd);
		//			printf("WM_VSCROLL\n");
		//			break;
		//		}
		//		case SB_THUMBTRACK:
		//		{
		//			si.nPos = si.nTrackPos;
		//			printf("WM_VSCROLL\n");
		//			break;
		//		}
		//		default:
		//		{
		//			break; 
		//		}
		//	}
		//	// Set the position and then retrieve it. Due to adjustments
		//	// by Windows it may not be the same as the value set.
		//	si.fMask = SIF_POS | SIF_DISABLENOSCROLL;
		//	SetScrollInfo (hwnd, SB_VERT, &si, TRUE);
		//	GetScrollInfo (hwnd, SB_VERT, &si);
		//	// If the position has changed, scroll the window and update it
		//	if (si.nPos != iVertPos)
		//	{ 
		//		ScrollWindow (hwnd, 0, (iVertPos - si.nPos), NULL, NULL);
		//		UpdateWindow (hwnd);
		//	}
		//	return 0;
		//}
		//case WM_HSCROLL:
		//{
		//	// Get all the vertical scroll bar information
		//	si.cbSize = sizeof (si);
		//	si.fMask = SIF_ALL | SIF_DISABLENOSCROLL;
		//	// Save the position for comparison later on
		//	GetScrollInfo (hwnd, SB_HORZ, &si);
		//	iHorzPos = si.nPos;
		//	switch (LOWORD (wParam))
		//	{
		//		case SB_LINELEFT:
		//		{
		//			si.nPos -= 15;
		//			printf("WM_HSCROLL\n");
		//			break;
		//		}
		//		case SB_LINERIGHT:
		//		{
		//			si.nPos += 15;
		//			printf("WM_HSCROLL\n");
		//			break;
		//		}
		//		case SB_PAGELEFT:
		//		{
		//			si.nPos -= si.nPage;
		//			printf("WM_HSCROLL\n");
		//			break;
		//		}
		//		case SB_PAGERIGHT:
		//		{
		//			si.nPos += si.nPage;
		//			printf("WM_HSCROLL\n");
		//			break;
		//		}
		//		case SB_THUMBPOSITION:
		//		{
		//			si.nPos = si.nTrackPos;
		//			//InvalidateRect(hwnd,NULL,true);
		//			//UpdateWindow (hwnd);
		//			printf("WM_HSCROLL\n");
		//			break;
		//		}
		//		case SB_THUMBTRACK:
		//		{
		//			si.nPos = si.nTrackPos;
		//			printf("WM_HSCROLL\n");
		//			break;
		//		}
		//		default:
		//		{
		//			break;
		//		}
		//	}
		//	// Set the position and then retrieve it. Due to adjustments
		//	// by Windows it may not be the same as the value set.
		//	si.fMask = SIF_POS | SIF_DISABLENOSCROLL;
		//	SetScrollInfo (hwnd, SB_HORZ, &si, TRUE);
		//	GetScrollInfo (hwnd, SB_HORZ, &si);
		//	// If the position has changed, scroll the window 
		//	if (si.nPos != iHorzPos)
		//	{
		//		ScrollWindow (hwnd, (iHorzPos - si.nPos), 0, NULL, NULL);
		//		UpdateWindow (hwnd);
		//	}
		//	return 0;
		//}
		case WM_MOUSEMOVE:
		{
			onMouseMove(LOWORD (lParam), HIWORD (lParam), lParam, lParam);
			break;
		}
		case WM_LBUTTONDOWN:
		{
			onMousePress(LOWORD (lParam), HIWORD (lParam), lParam, lParam, false, 1);
			return 0;
		}
		case WM_MBUTTONDOWN:
		{
			onMousePress(LOWORD (lParam), HIWORD (lParam), lParam, lParam, false, 2);
			return 0;
		}
		case WM_RBUTTONDOWN:
		{
			onMousePress(LOWORD (lParam), HIWORD (lParam), lParam, lParam, false, 3);
			return 0;
		}
		case WM_LBUTTONUP:
		{
			onMousePress(LOWORD (lParam), HIWORD (lParam), lParam, lParam, true, 1);
			return 0;
		}
		case WM_MBUTTONUP:
		{
			onMousePress(LOWORD (lParam), HIWORD (lParam), lParam, lParam, true, 2);
			return 0;
		}
		case WM_RBUTTONUP:
		{
			onMousePress(LOWORD (lParam), HIWORD (lParam), lParam, lParam, true, 3);
			return 0;
		}
		case WM_KEYDOWN:
		case WM_KEYUP:
		//case WM_CHAR:
		//case WM_DEADCHAR:
		case WM_SYSKEYDOWN:
		case WM_SYSKEYUP:
		case WM_SYSCHAR:
		case WM_SYSDEADCHAR: 
		{
			pKeyMap keymap = new KeyMap;
			//char a[1000];
			//printf("%i %i %i %i; %i %i %i %i %i; %i %i %i %i %i %i %i; \n", LOWORD (lParam), HIWORD (lParam),LOWORD (wParam), HIWORD (wParam), HIWORD (lParam)&0x01000000, HIWORD (lParam)&0x02000000, HIWORD (lParam)&0x04000000, HIWORD (lParam)&0x08000000, HIWORD (lParam)&0x10000000, GetKeyState (VK_SHIFT), GetKeyState (VK_LSHIFT), GetKeyState (VK_RSHIFT), GetKeyState (VK_LCONTROL), GetKeyState (VK_RCONTROL), GetKeyState (VK_LMENU), GetKeyState (VK_RMENU));
			printf("%i%i%i%i %i%i%i%i:%i%i%i%i %i%i%i%i  %i%i%i%i %i%i%i%i:%i%i%i%i %i%i%i%i  "
						"%i%i%i%i %i%i%i%i:%i%i%i%i %i%i%i%i  %i%i%i%i %i%i%i%i:%i%i%i%i %i%i%i%i\n",
						(lParam&0x00000001)>>0 , (lParam&0x00000002)>>1 , (lParam&0x00000004)>>2 , (lParam&0x00000008)>>3 , 
						(lParam&0x00000010)>>4 , (lParam&0x00000020)>>5 , (lParam&0x00000040)>>6 , (lParam&0x00000080)>>7 , 

						(lParam&0x00000100)>>8 , (lParam&0x00000200)>>9 , (lParam&0x00000400)>>10, (lParam&0x00000800)>>11, 
						(lParam&0x00001000)>>12, (lParam&0x00002000)>>13, (lParam&0x00004000)>>14, (lParam&0x00008000)>>15, 

						(lParam&0x00010000)>>16, (lParam&0x00020000)>>17, (lParam&0x00040000)>>18, (lParam&0x00080000)>>19, 
						(lParam&0x00100000)>>20, (lParam&0x00200000)>>21, (lParam&0x00400000)>>22, (lParam&0x00800000)>>23, 

						(lParam&0x01000000)>>24, (lParam&0x02000000)>>25, (lParam&0x04000000)>>26, (lParam&0x08000000)>>27, 
						(lParam&0x10000000)>>28, (lParam&0x20000000)>>29, (lParam&0x00000000)>>30, (lParam&0x80000000)>>31, // 0x20000000 = alt


						(wParam&0x00000001)>>0 , (wParam&0x00000002)>>1 , (wParam&0x00000004)>>2 , (wParam&0x00000008)>>3 , // 0x00000020 = shift
						(wParam&0x00000010)>>4 , (wParam&0x00000020)>>5 , (wParam&0x00000040)>>6 , (wParam&0x00000080)>>7 , // 0x00000040 = ctrl

						(wParam&0x00000100)>>8 , (wParam&0x00000200)>>9 , (wParam&0x00000400)>>10, (wParam&0x00000800)>>11, 
						(wParam&0x00001000)>>12, (wParam&0x00002000)>>13, (wParam&0x00004000)>>14, (wParam&0x00008000)>>15, 

						(wParam&0x00010000)>>16, (wParam&0x00020000)>>17, (wParam&0x00040000)>>18, (wParam&0x00080000)>>19, 
						(wParam&0x00100000)>>20, (wParam&0x00200000)>>21, (wParam&0x00400000)>>22, (wParam&0x00800000)>>23, 

						(wParam&0x01000000)>>24, (wParam&0x02000000)>>25, (wParam&0x04000000)>>26, (wParam&0x08000000)>>27, 
						(wParam&0x10000000)>>28, (wParam&0x20000000)>>29, (wParam&0x40000000)>>30, (wParam&0x80000000)>>31);

						//HIWORD (lParam)&0x02000000, HIWORD (lParam)&0x04000000, HIWORD (lParam)&0x08000000, HIWORD (lParam)&0x10000000);
			//SetWindowTextA(hwnd, a);
			onKeyPress(wParam, wParam, lParam, keymap);
			delete keymap;
			return 0;
		}
		case WM_MOUSEWHEEL:
		{
			//{
			//	SystemParametersInfo (SPI_GETWHEELSCROLLLINES, 0, &ulScrollLines, 0);
			//	// ulScrollLines usually equals 3 or 0 (for no scrolling)
			//	// WHEEL_DELTA equals 120, so iDeltaPerLine will be 40
			//	if (ulScrollLines)
			//		iDeltaPerLine = WHEEL_DELTA / ulScrollLines;
			//	else
			//		iDeltaPerLine = 0;
			//}
			if (iDeltaPerLine == 0)
				break;
			iAccumDelta += (short) HIWORD (wParam); // 120 or -120
			while (iAccumDelta >= iDeltaPerLine)
			{ 
				//SendMessage (hwnd, WM_VSCROLL, SB_LINEUP, 0);
				onMouseWhell(1,wParam, lParam);
				iAccumDelta -= iDeltaPerLine;
			}
			while (iAccumDelta <= -iDeltaPerLine)
			{
				onMouseWhell(-1,wParam, lParam);
				//SendMessage (hwnd, WM_VSCROLL, SB_LINEDOWN, 0);
				iAccumDelta += iDeltaPerLine;
			}
			break;
		}
		case WM_PAINT:
		{
			hdc = BeginPaint(hwnd, &ps);
			onPaint(&ps,wParam, lParam);
			//hdcMem = CreateCompatibleDC(hdc);
			//si.cbSize = sizeof (si);
			//si.fMask = SIF_POS | SIF_DISABLENOSCROLL;
			//GetScrollInfo (hwnd, SB_VERT, &si);
			//iVertPos = si.nPos;
			//// Get horizontal scroll bar position
			//GetScrollInfo (hwnd, SB_HORZ, &si);
			//iHorzPos = si.nPos;
			//// Find painting limits
			////iPaintBeg = max (0, iVertPos + ps.rcPaint.top );
			////iPaintEnd = min (yres, iVertPos + ps.rcPaint.bottom );

			//BitBlt(hdc, ps.rcPaint.left, ps.rcPaint.top, ps.rcPaint.right - ps.rcPaint.left, ps.rcPaint.bottom - ps.rcPaint.top, hdcMem, iHorzPos+ps.rcPaint.left, iVertPos+ps.rcPaint.top, SRCCOPY);
			//MoveToEx(hdc, 0-iHorzPos-1,0-iVertPos-1, NULL);
			////LineTo(hdc, 0-iHorzPos-1,0-iVertPos-1);
			//LineTo(hdc, 100,100);
			//LineTo(hdc, xres-iHorzPos,yres-iVertPos);
			//LineTo(hdc, 0-iHorzPos-1,yres-iVertPos);
			//LineTo(hdc, 0-iHorzPos-1,0-iVertPos-1);
			////SelectObject(hdcMem, hbmOld);

			//glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
   //         glClear (GL_COLOR_BUFFER_BIT);

   //         glPushMatrix ();
   //         glRotatef (theta, 0.0f, 0.0f, 1.0f);
   //         glBegin (GL_TRIANGLES);
   //         glColor3f (1.0f, 0.0f, 0.0f);   glVertex3f (0.0f, 1.0f, 1.0f);
   //         glColor3f (0.0f, 1.0f, 0.0f);   glVertex3f (0.87f, -0.5f, -0.5f);
   //         glColor3f (0.0f, 0.0f, 1.0f);   glVertex3f (-0.87f, -0.5f, -0.5f);
   //         glEnd ();
   //         glPopMatrix ();

   //         SwapBuffers (ctx.hdc);
   //         theta += 1.0f;
   //         Sleep (1);	




			EndPaint(hwnd, &ps);
			//DeleteDC(hdcMem);
			//DeleteObject(hbmOld);
			return 0;
			//break;
		}
		case WM_SETTINGCHANGE:
		{
			printf("WM_SETTINGCHANGE\n");
			SystemParametersInfo (SPI_GETWHEELSCROLLLINES, 0, &ulScrollLines, 0);
			// ulScrollLines usually equals 3 or 0 (for no scrolling)
			// WHEEL_DELTA equals 120, so iDeltaPerLine will be 40
			if (ulScrollLines)
				iDeltaPerLine = WHEEL_DELTA / ulScrollLines;
			else
				iDeltaPerLine = 0;
			break;
		}
		case WM_CLOSE:
		{
			printf("WM_CLOSE\n");
			DestroyWindow(hwnd);
			break;
		}
		case WM_DESTROY:
		{
			printf("WM_DESTROY\n");
			PostQuitMessage(0);
			break;
		}
		case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
				//case ID_FILE_OPEN:
				case 0:
				{
					PostMessage(hwnd, WM_CLOSE, 0, 0);
					break;
				}
				//case ID_FILE_SAVE:
				//{
				//	break;
				//}
				//case ID_FILE_SAVE_AS:
				//{
				//	break;
				//}
				//case ID_FILE_SAVE_ALL:
				//{
				//	break;
				//}
				//case ID_FILE_CLOSE:
				//{
				//	break;
				//}
				//case ID_FILE_CLOSE_ALL:
				//{
				//	break;
				//}
				//case ID_FILE_EXIT:
				//{
				//	break;
				//}
				//case ID_HELP_ABOUT:
				//{
				//	break;
				//}
			}
			break;
		}
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

int startOpengl(){
	QueryPerformanceCounter((LARGE_INTEGER *)&count1);
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
	QueryPerformanceCounter((LARGE_INTEGER *)&count2);
	printf("Frequência: %I64d ticks/s\n", freq);
	printf("Contagem: 1: %I64d 2: %I64d dif: %I64d\n", count1, count2, count2-count1);
	printf("Tempo: %I64d ns\n", (count2-count1)*1000000/freq);
	//mat4x4f h;
	//h.row0=0.0f;
	//h.aray[7]=8;
	//h.mt[1][1]=5;
	//h.x[1]=5;
	//h.
	vec4 g[10];
	//g[1] = vec4(1.0f,2.0f,3.0f,4.0f);
	//{
	//	text i;


	//}

	ctx.sx = 512;
	ctx.sy = 512;
	ZeroMemory(&ctx.wc, sizeof(WNDCLASS));
	ctx.wc.hInstance = GetModuleHandle(NULL);
	ctx.wc.lpfnWndProc = WndProc;
	ctx.wc.lpszClassName = "TestOpengl_01";
	ctx.wc.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH);
	ctx.wc.hCursor = LoadCursor (NULL, IDC_ARROW);
	//wc.style = CS_HREDRAW | CS_VREDRAW;
	ctx.wc.hIcon = LoadIcon (NULL, IDI_ASTERISK);
	if (0 == RegisterClass(&ctx.wc)) return GL_TRUE;
	/* create window */
	ctx.hwnd = CreateWindow("TestOpengl_01", "Test Opengl 01", 
		WS_OVERLAPPEDWINDOW, 
		111, 202, ctx.sx, ctx.sy,
		NULL, NULL, NULL, NULL);

	/* get the device context */
	ctx.hdc = GetDC(ctx.hwnd);
	// WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL

	/* find pixel format */

	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
	int visual = ChoosePixelFormat(ctx.hdc, &pfd);
	/* set the pixel format for the dc */
	//SetPixelFormat(ctx.hdc, visual, &pfd);
	SetPixelFormat(ctx.hdc, 80, &pfd); // it is a hack, so i know that this number 80 activate the 4x AntiAlias on my computer
	/* create rendering context */
	ctx.hglrc = wglCreateContext(ctx.hdc);
	wglMakeCurrent(ctx.hdc, ctx.hglrc);
	LoadOGL();
	LoadWGL();
	
	printf(wglGetExtensionsStringARB(ctx.hdc));

    int attributes[] = {
      WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
      WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
      WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
      WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
      WGL_COLOR_BITS_ARB, 32,
      WGL_DEPTH_BITS_ARB, 24,
      WGL_STENCIL_BITS_ARB, 8,
      WGL_SAMPLE_BUFFERS_ARB, 1, // Number of buffers (must be 1 at time of writing)
      WGL_SAMPLES_ARB, 4,        // Number of samples
      0
    };

	int attrib[] = { WGL_NUMBER_PIXEL_FORMATS_ARB }; 
	int nResults[1] = {0}; 
	int pixFmt = 1; 
	wglGetPixelFormatAttribivARB (ctx.hdc, pixFmt, 0, 1, attrib, nResults);


	GLint pfAttribCount[]= { WGL_NUMBER_PIXEL_FORMATS_ARB };
	//GLint pfAttribList[] = { 
	//	WGL_DRAW_TO_WINDOW_ARB, 
	//	WGL_ACCELERATION_ARB,
	//	WGL_SUPPORT_OPENGL_ARB, 
	//	WGL_DOUBLE_BUFFER_ARB, 
	//	WGL_DEPTH_BITS_ARB, 
	//	WGL_STENCIL_BITS_ARB, 
	//	WGL_RED_BITS_ARB, 
	//	WGL_GREEN_BITS_ARB, 
	//	WGL_BLUE_BITS_ARB, 
	//	WGL_ALPHA_BITS_ARB 
	//};
	GLint pfAttribList[] = { 
	//WGL_NUMBER_PIXEL_FORMATS_ARB,
	//WGL_SUPPORT_OPENGL_ARB,
	//WGL_DOUBLE_BUFFER_ARB,
	//WGL_DRAW_TO_WINDOW_ARB,
	//WGL_DRAW_TO_BITMAP_ARB,
	//WGL_ACCELERATION_ARB,
	//WGL_NUMBER_OVERLAYS_ARB,
	//WGL_NUMBER_UNDERLAYS_ARB,
	//WGL_TRANSPARENT_ARB,
	//WGL_STEREO_ARB,
	//WGL_COLOR_BITS_ARB,
	//WGL_RED_BITS_ARB,
	//WGL_RED_SHIFT_ARB,
	//WGL_GREEN_BITS_ARB,
	//WGL_GREEN_SHIFT_ARB,
	//WGL_BLUE_BITS_ARB,
	//WGL_BLUE_SHIFT_ARB,
	//WGL_ALPHA_BITS_ARB,
	//WGL_ALPHA_SHIFT_ARB,
	//WGL_ACCUM_BITS_ARB,
	//WGL_ACCUM_RED_BITS_ARB,
	//WGL_ACCUM_GREEN_BITS_ARB,
	//WGL_ACCUM_BLUE_BITS_ARB,
	//WGL_ACCUM_ALPHA_BITS_ARB,
	//WGL_DEPTH_BITS_ARB,
	//WGL_STENCIL_BITS_ARB,
	//WGL_SHARE_DEPTH_ARB,
	//WGL_SHARE_STENCIL_ARB,
	//WGL_SHARE_ACCUM_ARB,
	//WGL_PIXEL_TYPE_ARB,
	//WGL_TRANSPARENT_RED_VALUE_ARB,
	//WGL_TRANSPARENT_GREEN_VALUE_ARB,
	//WGL_TRANSPARENT_BLUE_VALUE_ARB,
	//WGL_TRANSPARENT_ALPHA_VALUE_ARB,
	//WGL_TRANSPARENT_INDEX_VALUE_ARB,
	//WGL_NEED_PALETTE_ARB,
	//WGL_NEED_SYSTEM_PALETTE_ARB,
	//WGL_SWAP_LAYER_BUFFERS_ARB,
	//WGL_SWAP_METHOD_ARB,
	//WGL_SUPPORT_GDI_ARB,
	//WGL_AUX_BUFFERS_ARB,
	//WGL_SAMPLES_ARB

		WGL_SUPPORT_OPENGL_ARB,
		WGL_SUPPORT_GDI_ARB,
		WGL_DOUBLE_BUFFER_ARB,
		WGL_DRAW_TO_WINDOW_ARB,
		WGL_DRAW_TO_BITMAP_ARB,
		WGL_SWAP_METHOD_ARB,
		WGL_PIXEL_TYPE_ARB,
		WGL_AUX_BUFFERS_ARB,
		WGL_COLOR_BITS_ARB,
		WGL_DEPTH_BITS_ARB,
		WGL_STENCIL_BITS_ARB,
		WGL_RED_BITS_ARB,
		WGL_GREEN_BITS_ARB,
		WGL_BLUE_BITS_ARB,
		WGL_ALPHA_BITS_ARB,
		WGL_ACCUM_BITS_ARB,
		WGL_ACCUM_RED_BITS_ARB,
		WGL_ACCUM_GREEN_BITS_ARB,
		WGL_ACCUM_BLUE_BITS_ARB,
		WGL_ACCUM_ALPHA_BITS_ARB,
		WGL_SAMPLES_ARB,
	};

	FILE *LogPixelFormat = fopen("LogPixelFormat.py", "wb");



	int nPixelFormatCount = 0; 
	wglGetPixelFormatAttribivARB(ctx.hdc, 1, 0, 1, pfAttribCount, &nPixelFormatCount); 
	for (int i=1; i<nPixelFormatCount; i++) 
	{
		GLint results[21]; 
		fprintf(LogPixelFormat, "\nPixel format %d details:\n", i); 
		wglGetPixelFormatAttribivARB(ctx.hdc, i, 0, 21, pfAttribList, results); 
		//printf(" Draw to Window = %x:\n", results[0]); 
		//printf(" HW Accelerated = %x:\n", results[1]); 
		//printf(" Supports OpenGL = %x:\n", results[2]); 
		//printf(" Double Buffered = %x:\n", results[3]); 
		//printf(" Depth Bits = %x:\n", results[4]); 
		//printf(" Stencil Bits = %x:\n", results[5]); 
		//printf(" Red Bits = %x:\n", results[6]); 
		//printf(" Green Bits = %x:\n", results[7]); 
		//printf(" Blue Bits = %x:\n", results[8]); 
		//printf(" Alpha Bits = %x:\n", results[9]);

		//fprintf(LogPixelFormat, " WGL_NUMBER_PIXEL_FORMATS_ARB = %x:\n", results[0]);
		fprintf(LogPixelFormat, " WGL_SUPPORT_OPENGL_ARB = %d:\n", results[0]);
		fprintf(LogPixelFormat, " WGL_SUPPORT_GDI_ARB = %d:\n", results[1]);
		fprintf(LogPixelFormat, " WGL_DOUBLE_BUFFER_ARB = %d:\n", results[2]);
		fprintf(LogPixelFormat, " WGL_DRAW_TO_WINDOW_ARB = %d:\n", results[3]);
		fprintf(LogPixelFormat, " WGL_DRAW_TO_BITMAP_ARB = %d:\n", results[4]);
		fprintf(LogPixelFormat, " WGL_SWAP_METHOD_ARB = 0x%x:\n", results[5]);
		fprintf(LogPixelFormat, " WGL_PIXEL_TYPE_ARB = 0x%x:\n", results[6]);
		fprintf(LogPixelFormat, " WGL_SAMPLES_ARB = %d:\n", results[20]);
		fprintf(LogPixelFormat, " WGL_AUX_BUFFERS_ARB = %d:\n", results[7]);
		fprintf(LogPixelFormat, " WGL_COLOR_BITS_ARB = %d:\n", results[8]);
		fprintf(LogPixelFormat, " WGL_DEPTH_BITS_ARB = %d:\n", results[9]);
		fprintf(LogPixelFormat, " WGL_STENCIL_BITS_ARB = %d:\n", results[10]);
		fprintf(LogPixelFormat, " WGL_RED_BITS_ARB = %d:\n", results[11]);
		fprintf(LogPixelFormat, " WGL_GREEN_BITS_ARB = %d:\n", results[12]);
		fprintf(LogPixelFormat, " WGL_BLUE_BITS_ARB = %d:\n", results[13]);
		fprintf(LogPixelFormat, " WGL_ALPHA_BITS_ARB = %d:\n", results[14]);
		fprintf(LogPixelFormat, " WGL_ACCUM_BITS_ARB = %d:\n", results[15]);
		fprintf(LogPixelFormat, " WGL_ACCUM_RED_BITS_ARB = %d:\n", results[16]);
		fprintf(LogPixelFormat, " WGL_ACCUM_GREEN_BITS_ARB = %d:\n", results[17]);
		fprintf(LogPixelFormat, " WGL_ACCUM_BLUE_BITS_ARB = %d:\n", results[18]);
		fprintf(LogPixelFormat, " WGL_ACCUM_ALPHA_BITS_ARB = %d:\n", results[19]);
		//fprintf(LogPixelFormat, " WGL_RED_SHIFT_ARB = %d:\n", results[12]);
		//fprintf(LogPixelFormat, " WGL_GREEN_SHIFT_ARB = %d:\n", results[14]);
		//fprintf(LogPixelFormat, " WGL_BLUE_SHIFT_ARB = %d:\n", results[16]);
		//fprintf(LogPixelFormat, " WGL_ALPHA_SHIFT_ARB = %d:\n", results[18]);
		//fprintf(LogPixelFormat, " WGL_ACCELERATION_ARB = %x:\n", results[5]);
		//fprintf(LogPixelFormat, " WGL_NUMBER_OVERLAYS_ARB = %x:\n", results[6]);
		//fprintf(LogPixelFormat, " WGL_NUMBER_UNDERLAYS_ARB = %x:\n", results[7]);
		//fprintf(LogPixelFormat, " WGL_TRANSPARENT_ARB = %x:\n", results[8]);
		//fprintf(LogPixelFormat, " WGL_STEREO_ARB = %x:\n", results[9]);
		//fprintf(LogPixelFormat, " WGL_SHARE_DEPTH_ARB = %x:\n", results[26]);
		//fprintf(LogPixelFormat, " WGL_SHARE_STENCIL_ARB = %x:\n", results[27]);
		//fprintf(LogPixelFormat, " WGL_SHARE_ACCUM_ARB = %x:\n", results[28]);
		//fprintf(LogPixelFormat, " WGL_TRANSPARENT_RED_VALUE_ARB = %x:\n", results[30]);
		//fprintf(LogPixelFormat, " WGL_TRANSPARENT_GREEN_VALUE_ARB = %x:\n", results[31]);
		//fprintf(LogPixelFormat, " WGL_TRANSPARENT_BLUE_VALUE_ARB = %x:\n", results[32]);
		//fprintf(LogPixelFormat, " WGL_TRANSPARENT_ALPHA_VALUE_ARB = %x:\n", results[33]);
		//fprintf(LogPixelFormat, " WGL_TRANSPARENT_INDEX_VALUE_ARB = %x:\n", results[34]);
		//fprintf(LogPixelFormat, " WGL_NEED_PALETTE_ARB = %x:\n", results[35]);
		//fprintf(LogPixelFormat, " WGL_NEED_SYSTEM_PALETTE_ARB = %x:\n", results[36]);
		//fprintf(LogPixelFormat, " WGL_SWAP_LAYER_BUFFERS_ARB = %x:\n", results[37]);
	}
	fprintf(LogPixelFormat, "\n\n\n\n");


	fclose(LogPixelFormat);
	return 1;
}

void drawRandPoints(int num);
void drawTorus(int xres, int yres, float3 size);
void drawTorus2(int xres, int yres, float3 size);
void makeTorus(int xres, int yres, float3 size);
void drawAxis();
void drawGrid();

int main(int argc, char* argv[])
{
	//printAsciiTable();
	timer t;
	startOpengl();
	GLuint hdrTextures[10];
	glEnable(GL_MULTISAMPLE);
	glGenTextures(1, hdrTextures);

	glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, hdrTextures[0]); 
	glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, 8, GL_RGB16F, ctx.sx, ctx.sy, GL_FALSE);

	GLint buf, sbuf;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glGetIntegerv(GL_SAMPLE_BUFFERS, &buf);
	printf("number of sample buffers is %d\n", buf);
	glGetIntegerv(GL_SAMPLES, &sbuf);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -2.0, 100.0);
	//glRotatef (1.0f, 0.1f, 0.0f, 0.0f);

	//int nvert=0, nindex=0;
	//vec3 *vert;
	//usvec3 *index;

	makeSphere(10,11, vec3(0.5f,0.5,0.5), &nvert, &nindex, &vert, &norm, &index);
	makeTorus(32,21,vec3(0.5f,0.5f,0.5f));
	printf("\n%i, %i\n",nvert,nindex);
	//for(int i=0; i<nvert; i++){
	//	printf("%i   %f %f %f\n", i, vert[i].x,vert[i].y,vert[i].z);
	//}
	for(int i=0; i<nindex; i++){
		//printf("%i %i %i\n", index[i].x,index[i].y,index[i].z);
	}

	t.reset();
	//printf("test\n test");
	ShowWindow(ctx.hwnd, 1);
	//UpdateWindow(ctx.hwnd);
	MSG msg;
	//gl3wInit();
	//printf("fn:%x\n",GetF("glVertexFormatAMD"));
	//printf("fn:%x\n",GetF("glVertexFormatARB"));
	//printf("fn:%x\n",GetF("glVertexFormatATI"));
	//printf("fn:%x\n",GetF("glVertexFormatEXT"));
	//printf("fn:%x\n",GetF("glVertexFormatNV"));
	//printf("fn:%x\n",GetF("glVertexFormat"));
 //	printf("fn:%x\n",GetF("glGenerateTextureMipmapAMD"));
 //	printf("fn:%x\n",GetF("glGenerateTextureMipmapARB"));
 //	printf("fn:%x\n",GetF("glGenerateTextureMipmapATI"));
 //	printf("fn:%x\n",GetF("glGenerateTextureMipmapEXT"));
 //	printf("fn:%x\n",GetF("glGenerateTextureMipmapNV"));
 //  	printf("fn:%x\n",GetF("glGenerateTextureMipmap"));
 //  	printf("fn:%x\n",GetF("glGenerateMipmap"));
 
	shader s2;
	printf("%i\n", s2.use());
	while (!bQuit)
	{
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }
        else
        {   
			//printf("time1: %f ns\n", setTime());
			printf("time1: %f ms\n", setTime()/1000.0f);
			//resetTime();
			onRenderScene();
			//printf("time2: %f ns\n", setTime());
			t.set();
			printf("time2: %f ms\n", setTime()/1000.0f);
			glFinish();
			//resetTime();
			//Sleep (11);	// 1 000ms = 1s; 1 000 000ns = 1s; 1s/60= 0.016666...s;  1 000ms/60 = 16.6666666... ms/f;
			// 1000/60 = 16.6666666... ms
			// 1000ms = 1s; 1000000 ns = 1s
			// 1000000ns / 60fps = 16 666.6666... ns

			// fps = ms/16.666...; fps = gettime/1000/(100/6)
			t.set();
			printf("time3: %f ms\n", t.getms());
			SwapBuffers (ctx.hdc);
			while((setTime()/1000.0f)<=13.0f){
				Sleep (1);
			}
			t.set();
			//printf("time3: %f ns\n", setTime());
			//printf("time3: %f ns\n", t.getns());
			//printf("time4: %f ms\n", setTime()/1000.0f);
			printf("time4: %f ms\n", t.getms());
			//printf("time5: %f s\n", setTime()/1000000.0f);
			//printf("time5: %f s\n", t.gets());
			printf("time4: %f fps\n\n", t.FPS());
			//printf("time6: %f fps\n\n", 1/(setTime()/1000000.0f));
			//printf("time6: %f fps\n\n", t.FPS());
			t.reset();
			resetTime();
			//system("pause");
		}
		//TranslateMessage(&msg);
		//DispatchMessage(&msg);
	}

	delete [] vert;
	delete [] index;
	wglMakeCurrent(ctx.hdc, NULL);
	wglDeleteContext(ctx.hglrc);
	ReleaseDC(ctx.hwnd, ctx.hdc);
	DestroyWindow(ctx.hwnd);


	//GLint nNum; 
	//char * ext;

	//glGetIntegerv(GL_EXTENSIONS, &nNum);

	//for(GLint i = 1; i< 1000; i++){
	//	ext = (char *)glGetString(i);
	//	if(!ext)
	//		continue;
	//	printf(ext);
	//}
	//{ 
	//wglSwapIntervalEXT = 
	//(PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress(“wglSwapIntervalEXT”);
	//if(wglSwapIntervalEXT != NULL) 
	//wglSwapIntervalEXT(1);
	//}

	//auxInitDisplayMode(AUX_INDIRECT | AUX_RGBA);
	//auxInitPosition(100,100,250,250);
	//auxInitWindow("My first OpenGL Program");  
	//// These are the OpenGL functions that do something in the window
	//glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	//glClear(GL_COLOR_BUFFER_BIT);
	//glFlush();
	//// Stop and wait for a keypress
	//printf("Press any key to close the Window \n");
	//getchar();

	system("pause");
	return msg.wParam;
}

void onRenderScene(){
    glEnable(GL_MULTISAMPLE_ARB);
	glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
	glClear (GL_COLOR_BUFFER_BIT);
	glClear (GL_DEPTH_BUFFER_BIT);

	glPushMatrix ();
	glRotatef (theta, 0.5f, -1.5f, 0.0f);
	//glBegin (GL_TRIANGLES);
	//	glColor3f (1.0f, 0.0f, 0.0f);   glVertex3f (0.0f, 1.0f, 1.0f);
	//	glColor3f (0.0f, 1.0f, 0.0f);   glVertex3f (0.87f, -0.5f, -0.5f);
	//	glColor3f (0.0f, 0.0f, 1.0f);   glVertex3f (-0.87f, -0.5f, -0.5f);
	//glEnd ();
	drawSphere(100,100,vec3(0.75f,0.75f,0.75f));
	//drawCube(vec3(1.0f, 0.15f, 1.0f), 0x1|0x2|0x4);
	//drawRandPoints(100000);
	drawGrid();
	drawAxis();
	drawTorus2(20,11,vec3(0.5f,0.5f,0.5f));
	glPopMatrix ();
    glDisable(GL_DEPTH_TEST);
	drawText("abcdefghijklmnopqrstuvwxyz\n", vec2(-1.f,1.f), vec2(1.f,1.f), vec4(1.f,1.f,1.f,1.f), vec2(0.f,0.f));
    glEnable(GL_DEPTH_TEST);

	theta -= 0.1f;

}

void onResize(int x, int y, WPARAM wParam, LPARAM lParam){
	glViewport(0,0,x,y);
	printf("WM_SIZE: %i:%i\n", x,y);
}

void onMove(int x, int y, WPARAM wParam, LPARAM lParam){
	printf("WM_MOVE\n");
}

void onPaint(PAINTSTRUCT *rc, WPARAM wParam, LPARAM lParam){
	printf("WM_PAINT\n");
	onRenderScene();
}

void onMouseWhell(int val, WPARAM wParam, LPARAM lParam){
	printf("WM_MOUSEWHEEL\n");
}

void onMouseMove(int x, int y, WPARAM wParam, LPARAM lParam){

}

void onComand(int cmd, WPARAM wParam, LPARAM lParam){
	printf("WM_COMMAND\n");
}

void onKeyPress(int key, WPARAM wParam, LPARAM lParam, pKeyMap keymap){

}

void onMousePress(int x,	int y, WPARAM wParam, LPARAM lParam,  int up, int n){

}


void drawSphere2(int xres, int yres, float3 size){
	xres = max(xres,3);
	yres = max(yres,2);
	float vx = PI/xres*2.0f, vy = PI/yres;
	float px=0,py=0,pz=0;
	// attributes
	glPointSize(3);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	// big sphere
	glBegin (GL_TRIANGLE_STRIP);
		glVertex3f (0, size.y,0);
		for(int y = 1; y < yres; y++){
			for(int x = 0; x < xres; x++){
				px=x*vx+0.001f; py = y*vy+0.001f; 
				glVertex3f (sin(px)*sin(py)*size.x, cos(py)*size.y, cos(px)*sin(py)*size.z);
			}
		}
		glVertex3f (0.0f, -size.y,0.0f);
	glEnd ();

	glBegin (GL_LINE_STRIP);
	glColor3f (1.0f, 1.0f, 1.0f);
		glVertex3f (0, size.y,0);
		for(int y = 1; y < yres; y++){
			for(int x = 0; x < xres; x++){
				px=x*vx+0.001f; py = y*vy+0.001f; 
				glVertex3f (sin(px)*sin(py)*size.x, cos(py)*size.y, cos(px)*sin(py)*size.z);
			}
		}
		glVertex3f (0.0f, -size.y,0.0f);
	glEnd ();

	glBegin (GL_POINTS);
	glColor3f (1.0f, 0.3f, 0.0f);
		glVertex3f (0.0f, size.y,0.0f);
		for(int y = 1; y < yres; y++){
			for(int x = 0; x < xres; x++){
				px=x*vx+0.001f; py = y*vy+0.001f; 
				glVertex3f (sin(px)*sin(py)*size.x, cos(py)*size.y, cos(px)*sin(py)*size.z);
			}
		}
		glVertex3f (0.0f, -size.y,0.0f);
	glEnd ();

	// small sphere
	glBegin (GL_LINE_STRIP);
	glColor3f (1.0f, 1.0f, 1.0f);
	for(py = -PI; py < PI; py += vy){
		for(px = -PI; px < PI; px += vx){
			glVertex3f (sin(px)/2*sin(py)*size.x, (cos(py)/2)*size.y, cos(px)/2*sin(py)*size.z);
		}
	}
	glEnd ();
	glBegin (GL_POINTS);
	glColor3f (1.0f, 0.3f, 0.0f);
	for(py = -PI; py < PI; py += vy){
		for(px = -PI; px < PI; px += vx){
			glVertex3f (sin(px)/2.0f*sin(py)*size.x, (cos(py)/2.0f)*size.y, cos(px)/2.0f*sin(py)*size.z);
		}
	}
	glEnd ();
}

void drawSphere(int xres, int yres, float3 size){
	//drawSphere2(xres, yres, sizex, sizey, sizez);
	glLineWidth(1.0f);
	//xres = max(xres,3);
	//yres = max(yres,2);
	//float vx = PI/xres*2, vy = PI/yres;
	//float px=0,py=0,pz=0;

	glPointSize(3);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	//glPolygonOffset(0, -10.5);
	glEnable(GL_POLYGON_OFFSET_FILL);
	//glBegin (GL_TRIANGLES);
	//	for(int i=0; i<nindex; i++){
	//		glColor3fv (vert[index[i].x].i);
	//		glVertex3fv (vert[index[i].x].i);
	//		glColor3fv (vert[index[i].y].i);
	//		glVertex3fv (vert[index[i].y].i);
	//		glColor3fv (vert[index[i].z].i);
	//		glVertex3fv (vert[index[i].z].i);
	//	}
	//glEnd ();
	//glDisable(GL_POLYGON_OFFSET_FILL);

	glBegin (GL_LINE_STRIP);
		for(int i=0; i<nindex; i++){
			glColor3f (0.75f,0.75f,0.0f);
			glVertex3fv (vert[index[i].x].i);
			//glColor3fv (vert[index[i].y].i);
			glVertex3fv (vert[index[i].y].i);
			//glColor3fv (vert[index[i].z].i);
			glVertex3fv (vert[index[i].z].i);
		}
	glEnd ();

	glBegin (GL_POINTS);
		for(int i=0; i<nindex; i++){
			glColor3f (1.0f,0.1f,0.0f);
			glVertex3fv (vert[index[i].x].i);
			//glColor3fv (vert[index[i].y].i);
			glVertex3fv (vert[index[i].y].i);
			//glColor3fv (vert[index[i].z].i);
			glVertex3fv (vert[index[i].z].i);
		}
	glEnd ();
}

void drawCube(float3 size, GLint type){

	glPointSize(3);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	//Mesh { // Cube mesh
 //     8;
 //      1.000000; 1.000000;-1.000000;,
 //      1.000000;-1.000000;-1.000000;,
 //     -1.000000;-1.000000;-1.000000;,
 //     -1.000000; 1.000000;-1.000000;,
 //      1.000000; 1.000000; 1.000000;,
 //      1.000000;-1.000000; 1.000000;,
 //     -1.000000;-1.000000; 1.000000;,
 //     -1.000000; 1.000000; 1.000000;;
 //     12;
 //     3;0,3,1;,
 //     3;4,5,7;,
 //     3;0,1,4;,
 //     3;1,2,5;,
 //     3;4,7,0;,
 //     3;3,2,1;,
 //     3;5,6,7;,
 //     3;1,5,4;,
 //     3;2,6,5;,
 //     3;7,3,0;,
 //     3;2,3,6;,
 //     3;3,7,6;;
	//MeshNormals { // Cube normals
 //       12;
 //       -0.000000;-0.000000;-1.000000;,
 //        0.000000; 0.000000; 1.000000;,
 //        1.000000; 0.000000;-0.000000;,
 //        0.000000;-1.000000; 0.000000;,
 //        0.000000; 1.000000; 0.000000;,
 //        0.000000; 0.000000;-1.000000;,
 //        0.000000;-0.000000; 1.000000;,
 //        1.000000; 0.000000; 0.000000;,
 //        0.000000;-1.000000; 0.000000;,
 //       -0.000000; 1.000000; 0.000000;,
 //       -1.000000; 0.000000; 0.000000;,
 //       -1.000000; 0.000000; 0.000000;;
 //       12;
 //       3;0,0,0;,
 //       3;1,1,1;,
 //       3;2,2,2;,
 //       3;3,3,3;,
 //       3;4,4,4;,
 //       3;5,5,5;,
 //       3;6,6,6;,
 //       3;7,7,7;,
 //       3;8,8,8;,
 //       3;9,9,9;,
 //       3;10,10,10;,
 //       3;11,11,11;;
	//} // End of Cube normals

	vec3 v[8] = {
		vec3(  1.0f, -1.0f, -1.0f ),
		vec3(  1.0f, -1.0f,  1.0f ),
		vec3( -1.0f, -1.0f,  1.0f ),
		vec3( -1.0f, -1.0f, -1.0f ),
		vec3(  1.0f,  1.0f, -1.0f ),
		vec3(  1.0f,  1.0f,  1.0f ),
		vec3( -1.0f,  1.0f,  1.0f ),
		vec3( -1.0f,  1.0f, -1.0f )
	};
	vec2 vt[14] = {
		vec2(  1.0f,  0.0f ),
		vec2(  0.5f, -0.5f ),
		vec2(  1.0f, -0.5f ),
		vec2(  0.5f,  1.0f ),
		vec2(  1.0f,  0.5f ),
		vec2(  1.0f,  1.0f ),
		vec2(  1.5f,  0.5f ),
		vec2(  1.5f,  0.0f ),
		vec2(  0.5f,  0.0f ),
		vec2( -0.5f,  0.0f ),
		vec2(  0.0f,  0.5f ),
		vec2( -0.5f,  0.5f ),
		vec2(  0.5f,  0.5f ),
		vec2(  0.0f,  0.0f )
	};
	vec3 vn[6] = {
		vec3(  0.0f, -1.0f,  0.0f  ),
		vec3(  0.0f,  1.0f,  0.0f  ),
		vec3(  1.0f,  0.0f,  0.0f  ),
		vec3(  0.0f,  0.0f,  1.0f  ),
		vec3(  0.0f,  0.0f, -1.0f  ),
		vec3( -1.0f,  0.0f,  0.0f  )
	};

	//v/t/n
	uchar3 fv[12]={
		uchar3( 2, 4, 1 ),
		uchar3( 8, 6, 5 ),
		uchar3( 5, 2, 1 ),
		uchar3( 6, 3, 2 ),
		uchar3( 1, 8, 5 ),
		uchar3( 2, 3, 4 ),
		uchar3( 8, 7, 6 ),
		uchar3( 5, 6, 2 ),
		uchar3( 6, 7, 3 ),
		uchar3( 1, 4, 8 ),
		uchar3( 7, 4, 3 ),
		uchar3( 7, 8, 4 )
	};
	uchar3 ft[12]={
		uchar3( 1 ,  2 ,  3  ),
		uchar3( 4 ,  5 ,  6  ),
		uchar3( 7 ,  1 ,  8  ),
		uchar3( 5 ,  9 ,  1  ),
		uchar3( 10,  11,  12 ),
		uchar3( 1 ,  9 ,  2  ),
		uchar3( 4 ,  13,  5  ),
		uchar3( 7 ,  5 ,  1  ),
		uchar3( 5 ,  13,  9  ),
		uchar3( 10,  14,  11 ),
		uchar3( 13,  14,  9  ),
		uchar3( 13,  11,  14 )
	};
	uchar3 fn[12]={
		uchar3(1, 1, 1 ), 
		uchar3(2, 2, 2 ), 
		uchar3(3, 3, 3 ), 
		uchar3(4, 4, 4 ), 
		uchar3(5, 5, 5 ), 
		uchar3(1, 1, 1 ), 
		uchar3(2, 2, 2 ), 
		uchar3(3, 3, 3 ), 
		uchar3(4, 4, 4 ), 
		uchar3(5, 5, 5 ), 
		uchar3(6, 6, 6 ), 
		uchar3(6, 6, 6 )
	};


	float3 vertex[8]= { 
		float3( 0.5f, 0.5f, 0.5f)*size, 
		float3( 0.5f,-0.5f, 0.5f)*size, 
		float3(-0.5f,-0.5f, 0.5f)*size, 
		float3(-0.5f, 0.5f, 0.5f)*size, 
		float3( 0.5f, 0.5f,-0.5f)*size, 
		float3( 0.5f,-0.5f,-0.5f)*size, 
		float3(-0.5f,-0.5f,-0.5f)*size, 
		float3(-0.5f, 0.5f,-0.5f)*size 
	};

	uchar3 index[12]= { 
		uchar3( 1, 3, 2), //up
		uchar3( 1, 0, 3), 

		uchar3( 0, 4, 3), // left
		uchar3( 3, 4, 7), 

		uchar3( 3, 7, 2), //front
		uchar3( 2, 7, 6), 

		uchar3( 1, 6, 5), //right
		uchar3( 1, 2, 6), 

		uchar3( 1, 5, 0), //back
		uchar3( 0, 5, 4), 

		uchar3( 6, 7, 4), // down
		uchar3( 5, 6, 4) 
	};

	glPolygonOffset(-1.5, -1.5);
	glEnable(GL_POLYGON_OFFSET_FILL);
	if(type & 0x1){
		glBegin (GL_TRIANGLES);
			glColor3f (0.2f,0.00f,0.5f);
			for(int i=0; i< 12; i++){
				glVertex3fv (vertex[index[i].x].i);
				glVertex3fv (vertex[index[i].y].i);
				glVertex3fv (vertex[index[i].z].i);
			}
		glEnd();
	}
	glDisable(GL_POLYGON_OFFSET_FILL);
	if(type & 0x2){
		glBegin (GL_LINE_STRIP);
			glColor3f (0.0f,0.9f,0.0f);
			for(int i=0; i< 12; i++){
				glVertex3fv (vertex[index[i].x].i);
				glVertex3fv (vertex[index[i].y].i);
				glVertex3fv (vertex[index[i].z].i);
			}
		glEnd();
	}
	if(type & 0x4){
		glBegin (GL_POINTS);
			glColor3f (1.0f,0.1f,0.0f);
			for(int i=0; i<12; i++){
				glVertex3fv (vertex[index[i].x].i);
				glVertex3fv (vertex[index[i].y].i);
				glVertex3fv (vertex[index[i].z].i);
			}
		glEnd();
	}
}

GLuint compile_shaders(const GLchar * vertex_shader_source, const GLchar * fragment_shader_source)
{
	GLuint vertex_shader;
	GLuint fragment_shader;
	GLuint program;
	const GLchar ** vs = &vertex_shader_source;
	const GLchar ** fs = &fragment_shader_source;

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, vs, NULL);
	glCompileShader(vertex_shader);

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, fs, NULL);
	glCompileShader(fragment_shader);

	program = glCreateProgram();
	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	return program;
}

void drawRandPoints(int num){
	srand(5);
	glPointSize(1.5);
	vec3 a, b, c;
	glBegin (GL_POINTS);
		glColor3f (1.2f,1.0f,0.0f);
		for(int i=0; i< num; i++){
			float r = rand()/40000.0, g=rand()/40000.0 -rand()/40000.0;

			a.x=pow(r, 0.125f)*sin(i*0.1*g)*0.5;
			a.y=pow(r, 0.125f)*cos(i*0.1*g)*0.5;
			a.z=pow(g, 0.5f)/10.0;
			//b.x=sin(rand()/(long double)40000.0);
			//b.y=sin(rand()/(long double)40000.0);
			//b.z=sin(rand()/(long double)40000.0);
			//c.x=sin(rand()/(long double)40000.0);
			//c.y=sin(rand()/(long double)40000.0);
			//c.z=sin(rand()/(long double)40000.0);
			//pow((long double)rand(), (long double)0.1
			//a.x = pow((long double)a.x, (long double)0.2);
			//a.y = pow((long double)a.y, (long double)0.2);
			//a.z = pow((long double)a.z, (long double)0.2);
			//b.x = pow((long double)b.x, (long double)0.2);
			//b.y = pow((long double)b.y, (long double)0.2);
			//b.z = pow((long double)b.z, (long double)0.2);
			//c.x = pow((long double)c.x, (long double)0.2);
			//c.y = pow((long double)c.y, (long double)0.2);
			//c.z = pow((long double)c.z, (long double)0.2);

			glVertex3fv (a.i);
			//glVertex3fv (b.i);
			//glVertex3fv (c.i);
		}
	glEnd();

}

void drawAxis(){
	glLineWidth(2.0f);
	glBegin (GL_LINES);
		glColor3f (1.0f,0.0f,0.0f);
			glVertex3f (0,0,0);
			glVertex3f (1,0,0);
		glColor3f (0.0f,1.0f,0.0f);
			glVertex3f (0,0,0);
			glVertex3f (0,1,0);
		glColor3f (0.0f,0.0f,1.0f);
			glVertex3f (0,0,0);
			glVertex3f (0,0,1);
	glEnd();

}

void drawGrid(){
	glLineWidth(1.0f);
	for(int i=-10; i<=10; i++){
		glBegin (GL_LINES);
			glColor3f(0.3f, 0.3f, 0.3f);
			glVertex3f(i*0.1f, -1, 0);
			glVertex3f(i*0.1f,  1, 0);
		glEnd();
	}
	for(int i=-10; i<=10; i++){
		glBegin (GL_LINES);
			glColor3f(0.3f, 0.3f, 0.3f);
			glVertex3f(-1, i*0.1f, 0);
			glVertex3f( 1, i*0.1f, 0);
		glEnd();
	}
}

float3 rotate_around_axis(float3 &p, float3 &axis, float angle)
{
	float costheta = cosf(angle);
	float sintheta = sinf(angle);
	float3 r;

	r.x = ((costheta + (1 - costheta) * axis.x * axis.x) * p.x) +
	      (((1 - costheta) * axis.x * axis.y - axis.z * sintheta) * p.y) +
	      (((1 - costheta) * axis.x * axis.z + axis.y * sintheta) * p.z);

	r.y = (((1 - costheta) * axis.x * axis.y + axis.z * sintheta) * p.x) +
	      ((costheta + (1 - costheta) * axis.y * axis.y) * p.y) +
	     (((1 - costheta) * axis.y * axis.z - axis.x * sintheta) * p.z);

	r.z = (((1 - costheta) * axis.x * axis.z - axis.y * sintheta) * p.x) +
	      (((1 - costheta) * axis.y * axis.z + axis.x * sintheta) * p.y) +
	      ((costheta + (1 - costheta) * axis.z * axis.z) * p.z);

	return r;
}

void drawTorus(int xres, int yres, float3 size){
	xres = max(xres,3);
	yres = max(yres,3);
	float vx = PI/xres*2.0f, vy = PI/yres*2.0f;
	float px=0,py=0,pz=0;
	// attributes
	glPointSize(3);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	// big sphere

	//glBegin (GL_POINTS);
	//glColor3f (1.0f, 0.3f, 0.0f);
	//	glVertex3f (0.0f, size.y,0.0f);
	//	for(int x = 0; x < xres; x++){
	//		for(int y = 1; y < yres; y++){
	//			px=x*vx+0.001f; py = y*vy+0.001f; 
	//			glVertex3f (sin(px)*sin(py)*size.x, cos(py)*size.y, cos(px)*sin(py)*size.z);
	//		}
	//	}
	//	glVertex3f (0.0f, -size.y,0.0f);
	//glEnd ();

	//glBegin (GL_POINTS);
	//glColor3f (1.0f, 0.3f, 0.0f);
	//	for(int x = 0; x < xres; x++){
	//		for(int y = 1; y <= yres; y++){
	//			px=x*vx+0.001f; py = y*vy+0.001f;

	//			float X=sin(px)*size.x*5,
	//				  Y=cos(px)*size.y*5,
	//				  Z=cos(py)*size.z;

	//			//glVertex3f(sin(px)*size.x, cos(px)*size.y+sin(py), 0.1*size.z+cos(py));
	//			glVertex3f(X+(sin(py)*size.x), Y+(cos(py)*size.y), Z*1);
	//		}
	//	}
	//glEnd ();
	//glBegin (GL_LINE_STRIP);
	//glColor3f (1.0f, 0.3f, 0.0f);
	//	for(int x = 0; x < xres; x++){
	//		for(int y = 1; y <= yres; y++){
	//			px=x*vx+0.001f; py = y*vy+0.001f;

	//			float x1 = sin(px) * size.x * 5,
	//				  y1 = cos(px) * size.y * 5,
	//				  z  = cos(py) * size.z,

	//				  x2 = sin(py) * size.x,
	//				  y2 = cos(py) * size.y;


	//			//glVertex3f(sin(px)*size.x, cos(px)*size.y+sin(py), 0.1*size.z+cos(py));
	//			glVertex3f(x1+(x2*y1), y1+(y2*x1), z);
	//		}
	//	}
	//glEnd ();

	glBegin (GL_LINE_LOOP);
	glColor3f (1.0f, 1.0f, 1.0f);
	for(int y = 0; y < yres; y++){
		py = y*vy;
	for(int x = 0; x < xres; x++){
		px=x*vx;
			float
				xb = sin(px) * size.x,   // big circle x
				yb = cos(px) * size.y,   // big circle y

				xs = sin(py) * size.x,   // small circle x
				ys = cos(py) * size.y,   // small circle y
				z  = cos(py) * size.z/2; // small circle z: nedded because the size(/2)
			//glColor3f (xb+(xs*xb), yb+(xs*yb), z);
			glVertex3f(xb+(xs*xb), yb+(xs*yb), z);
			//big circle
			//glVertex3f(xb, yb, 0);
			//small circle
			//glVertex3f(xs, ys, 0);
		}
		}
	glEnd ();

	int numc = 5, numt = 20;
	glColor3f (1.0f, 0.3f, 0.0f);
	double TWOPI = 2 * PI;
	for (int i = 0; i < numc; i++) {
		glBegin(GL_LINE_STRIP);
		for (int j = 0; j <= numt; j++) {
				double s = (i ) % numc ;
				double t = j % numt;
				double x = (0.5 + 0.1 * cos(s * TWOPI / numc)) * cos(t * TWOPI / numt);
				double y = (0.5 + 0.1 * cos(s * TWOPI / numc)) * sin(t * TWOPI / numt);
				double z = 0.1 * sin(s * TWOPI / numc);
				//glVertex3d(1 * x, 1 * y, 1 * z);
		}
		glEnd();
	}
}

void makeTorus(int xres, int yres, float3 size){
	xres = max(xres,3);
	yres = max(yres,3);

	tnvert = xres*yres;
	tnindex = xres * yres * 2;

	tvert = new vec3[tnvert];
	tnorm = new vec3[tnvert];
	tindex = new usvec3[tnindex];

	float vx = PI/xres*2.0f, vy = PI/yres*2.0f;
	float px=0,py=0,pz=0;
	// attributes
	int p =0, y = 0, x = 0;
	for(y = 0; y < yres; y++){
		py = y*vy;
	for(x = 0; x < xres; x++){
		px=x*vx;
			float
				xb = sin(px) * size.x,   // big circle x
				yb = cos(px) * size.y,   // big circle y

				xs = sin(py) * size.x,   // small circle x
				ys = cos(py) * size.y,   // small circle y
				z  = cos(py) * size.z/2; // small circle z: nedded because the size(/2)
			tvert[p] = vec3(xb+(xs*xb), yb+(xs*yb), z);
			p++;
			//glVertex3f(xb+(xs*xb), yb+(xs*yb), z);
	}
	}


	//center
	p=0;
	y=0;
	x=y+xres;
	int sx=x, sy=0;
	for(int a=0 ; a < yres-1; a++){
		int sx=x, sy=y;
		for(int b=0 ; b < xres-1; b++, x++, y++){
			tindex[p] = usvec3(y, x, x+1);
			p++;
			tindex[p] = usvec3(y, x+1, y+1);
			p++;
		}
		tindex[p] = usvec3(y, x, sx);
		p++;
		tindex[p] = usvec3(y, y+1, sy);
		//tindex[p] = usvec3(y, sx, x+1);
		//p++;
		//tindex[p] = usvec3(y, sy-1, y+1);
		p++;
		x++;
		y++;
	}

	// booton
	for(x =0, y = tnvert - xres; y < tnvert, p<tnindex;){
		if(x>=xres)
			//tindex[p] = usvec3(y-yres, x, x+1);
			tindex[p] = usvec3(0, 0, 0);
		else
			tindex[p] = usvec3(y, x, x+1);
		//tindex[p] = usvec3(tnvert-1, y, y-1);
		p++;

		if(x>=xres)
			tindex[p] = usvec3(0, 0, 0);
			//tindex[p] = usvec3(y, y+1, x-xres);
		else
			tindex[p] = usvec3(y, x+1, y+1);
		//tindex[p] = usvec3(tnvert-1, y+1, y-1);
		p++;
		y++;
		x++;
	}

	tindex[tnindex-2] = usvec3(xres-1, 0, tnvert-1);
	tindex[tnindex-1] = usvec3(tnvert-xres, tnvert-1, 0);
	//tindex[tnindex-1] = usvec3(0, 0, 0);
	//tindex[tnindex-2] = usvec3(0, 0, 0);
	//tindex[tnindex-1] = usvec3(0, 0, 0);

	vec3 faceNormal;
	for(p = 0; p < tnindex; p++){
		faceNormal = calcNormal(tvert[tindex[p].x], tvert[tindex[p].y], tvert[tindex[p].z]);
		tnorm[tindex[p].x] += faceNormal;
		tnorm[tindex[p].y] += faceNormal;
		tnorm[tindex[p].z] += faceNormal;
	}
	for (p = 0; p < tnvert; p++){
		tnorm[p] = normalize(tnorm[p]);
	}
	p=0;




}

void drawTorus2(int xres, int yres, float3 size){
	//drawSphere2(xres, yres, sizex, sizey, sizez);
	glLineWidth(1.0f);
	//xres = max(xres,3);
	//yres = max(yres,2);
	//float vx = PI/xres*2, vy = PI/yres;
	//float px=0,py=0,pz=0;

	glPointSize(3);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	//glPolygonOffset(0, -10.5);
	glEnable(GL_POLYGON_OFFSET_FILL);
	//glBegin (GL_TRIANGLES);
	//	for(int i=0; i<tnindex; i++){
	//		glColor3fv ((tnorm[tindex[i].y]).i);
	//		glVertex3fv(tvert[tindex[i].y].i);
	//		glColor3fv ((tnorm[tindex[i].x]).i);
	//		glVertex3fv(tvert[tindex[i].x].i);
	//		glColor3fv ((tnorm[tindex[i].z]).i);
	//		glVertex3fv(tvert[tindex[i].z].i);
	//	}
	//glEnd ();
	glDisable(GL_POLYGON_OFFSET_FILL);

	glBegin (GL_LINE_STRIP);
		for(int i=0; i<tnindex; i++){
			glColor3f (0.75f,0.75f,0.0f);
			glVertex3fv (tvert[tindex[i].x].i);
			//glColor3fv(tvert[tindex[i].y].i);
			glVertex3fv (tvert[tindex[i].y].i);
			//glColor3fv(tvert[tindex[i].z].i);
			glVertex3fv (tvert[tindex[i].z].i);
		}
	glEnd ();

	glBegin (GL_POINTS);
		for(int i=0; i<tnindex; i++){
			glColor3f (1.0f,0.1f,0.0f);
			glVertex3fv (tvert[tindex[i].x].i);
			//glColor3fv(tvert[tindex[i].y].i);
			glVertex3fv (tvert[tindex[i].y].i);
			//glColor3fv(tvert[tindex[i].z].i);
			glVertex3fv (tvert[tindex[i].z].i);
		}
	glEnd ();
}























