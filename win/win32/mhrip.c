/* Copyright (C) 2001 by Alex Kompel <shurikk@pacbell.net> */
/* NetHack may be freely redistributed.  See license for details. */

#include "winMS.h"
#include "resource.h"
#include "mhrip.h"
#include "mhtext.h"

HWND mswin_init_RIP_window () 
{
	return mswin_init_text_window();
}

void mswin_display_RIP_window (HWND hWnd)
{
	MSG msg;
	RECT rt;

	GetNHApp()->hMenuWnd = hWnd;
	GetWindowRect(GetNHApp()->hMainWnd, &rt);
	MoveWindow(hWnd, rt.left, rt.top, rt.right-rt.left, rt.bottom-rt.top, FALSE);
	ShowWindow(hWnd, SW_SHOW);
	SetFocus(hWnd);

	while( IsWindow(hWnd) && 
		   GetMessage(&msg, NULL, 0, 0)!=0 ) {
		if( !IsDialogMessage(hWnd, &msg) ) {
			if (!TranslateAccelerator(msg.hwnd, GetNHApp()->hAccelTable, &msg)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	}

	GetNHApp()->hMenuWnd = NULL;
}