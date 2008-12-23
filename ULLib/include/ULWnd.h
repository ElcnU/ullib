///\file ULWnd.h
///\brief ������������ ���� ������ root ����(24.10.2007)
#pragma once
#ifndef __ULWND_H__
#define __ULWND_H__

#include <windows.h>
#include "ULMessageMap.inl"

namespace ULWnds
{
	///\class CULWnd
	///\brief ����� root ��� ���� �������� ����(24.10.2007)
	class CULWnd
	{
	protected:
		LPCTSTR m_szDefClassName;
	protected:
		///\brief ������� ����
		static LRESULT WndProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);
	public:
		///\brief �����������
		CULWnd(void);
		///\brief ����������� �����������
		CULWnd(CULWnd& Wnd);
		///\brief ����������� 
		CULWnd(HWND hwnd);
		///\brief ���������
		virtual ~CULWnd(void);
		///\brief ������ ������ ���������� � ��������� ���������
		///��������� ����������� � ������������ ������
		CULMessageMap<CULWnd> MessageMap;
		///\brief ������� ��� ��������� ������ ���� �� ��� ������,
		///���� ���� ����������� ��� ������ ����� ������,
		///�.�.� ����������� WM_CREATE ��� WM_INITDIALOG � GWL_USERDATA ���������� this
		///\param hWnd ����� ����
		///\return ��������� �� ����� ����
		static CULWnd* FromHandle(HWND hWnd)
			{return (CULWnd *)(LONG_PTR)::GetWindowLong(hWnd, GWL_USERDATA);}
		///\brief ������� ���� ����������� ��� ���������������� ��������� ����������
		WNDPROC m_lpSubClassWndProc;
		///\brief ������� ���������� ����� ���������� ���������
		///\���������� ������������� GetApp()->MessageMap.InitializePreTranslateMessage (������������� �������� � ������������)
		///\����� ���� ��� ������� ����� �� �����, � ���������� ����������
		///\ GetApp()->MessageMap.UnInitializePreTranslateMessage (������������� �������� � �����������)
		///\param pMsg - ��������� �� ��������� ������� ���������� � ���������
		///\return TRUE ��� ����������� ���������� ���������, FALSE ��� ����������� ��������� ���������
		virtual BOOL PreTranslateMessage(MSG* pMsg);
		///\brief ����� �������� ���� 
		HWND m_hWnd;
		///\brief ����� ������������� ����
		HWND m_hParentWnd;
		///\brief ��� ����������� ������� ������ ��� ��� ��������� 
		///������ ����� ����
		inline operator HWND() const{return m_hWnd;}
		///\brief �������� �����������
		virtual void operator = (CULWnd&);
	//==============================================================
		///\brief ������� ����
		///\param lpClassName - ����� ����.���� lpClassName ����� NULL\n
		///\ �� ��������������� ����� ����������� ULWNDCLASS
		///\param lpWindowName - ��� ����
		///\param dwStyle - ����� ����
		///\param x,y,nWidth,nHeight - ���������� � ������� ����
		///\param hWndParent - ����� �������������� ����
		///\param hMenu - ����� ����. ��� ��������� ��� �������������
		///\return TRUE � ������ ������
		BOOL Create(LPCTSTR lpClassName,LPCTSTR lpWindowName,DWORD dwStyle,
			int x,int y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu);
		///\brief ������� ����
		///\param dwExStyle - ����������� ����� ����
		///\param lpClassName - ����� ����.���� lpClassName ����� NULL\n
		///\ �� ��������������� ����� ����������� ULWNDCLASS
		///\param lpWindowName - ��� ����
		///\param dwStyle - ����� ����
		///\param x,y,nWidth,nHeight - ���������� � ������� ����
		///\param hWndParent - ����� �������������� ����
		///\param hMenu - ����� ����. ��� ��������� ��� �������������
		///\return TRUE � ������ ������
		BOOL Create(DWORD dwExStyle,LPCTSTR lpClassName,LPCTSTR lpWindowName,DWORD dwStyle,
			int x,int y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu);
		///\brief ������������ ����� ���� �����������
		///\return TRUE � ������ ������
		BOOL RegisterDefClass();
		///\brief ���������� ������� ����
		virtual LRESULT DefWindowProc(UINT uMsg,WPARAM wParam,LPARAM lParam);
		///\brief ����� ������� ����
		virtual LRESULT CallWindowProc(UINT uMsg,WPARAM wParam,LPARAM lParam);
		///\brief ������� ������������ �� WndProc �� ������� ���������
		///\return ���� ���������� �� ����, �� ������������ ��������� ����� ��������� ������� �������������
		virtual LRESULT OnMessage(UINT uMsg,WPARAM wParam,LPARAM lParam);
		///\brief ��������� ������ ����
		///\param lpString - ������
		///\param nMaxCount - ������������ ����� ������
		///\return ����������� ���������� �������� � lpString
		int GetWindowText(LPTSTR lpString,int nMaxCount);
		///\brief ��������� ����� ������ ����
		///\return ����������� �������� � ����
		int GetWindowTextLength();
		///\brief ��������� ������ � ����
		///\param lpString - �����
		///\return TRUE � ������ ������
		BOOL SetWindowText(LPTSTR lpString);
		///\brief �������� ��������� � ����
		///\param Msg - ���������
		///\param wParam - �������� 1
		///\param lParam - �������� 2
		///\return ����� ����������� ���������
		LRESULT SendMessage(UINT Msg,WPARAM wParam=0,LPARAM lParam=0);
		///\brief ���������� ��������� � ���� � ����� ������� ����� ���������
		///\param Msg - ���������
		///\param wParam - �������� 1
		///\param lParam - �������� 2
		///\return TRUE � ������ ������
		BOOL PostMessage(UINT Msg,WPARAM wParam=0,LPARAM lParam=0);
		///\brief ��������� ������
		///\return ���������� ����� ����������� ����
		HWND SetFocus();
		///\brief ���������� ����
		///\return TRUE � ������ ������
		BOOL DestroyWindow();
		///\brief ������ ���� ��������
		///\return ���������� �������� ����
		HWND SetActiveWindow();
		///\brief �������� ���� �� �������� ���� � ������ ��� ��������
		///\return TRUE � ������ ������
		BOOL SetForegroundWindow();
		///\brief ���������� ��������
		///\return ����� ��������
		HWND GetParent();
		///\brief ������������� ������ ��������
		///\return ����� ����������� ��������
		HWND SetParent(HWND hWndNewParent);
		///\brief �������� ��������� ��������� ����
		///\param nCmdShow - ���������
		///\return TRUE � ������ ���������� ���������, ����� FALSE
		BOOL ShowWindow(int nCmdShow);
		///\brief ��������� ����
		///\return TRUE � ������ ���������� ���������, ����� FALSE
		BOOL UpdateWindow();
		///\brief �������� ������� ����
		///\param hWndInsertAfter - ��������� ���� �� Z ����������
		///�������� HWND_BOTTOM,HWND_NOTOPMOST,HWND_TOP,HWND_TOPMOST
		///\param X,Y - ����������
		///\param cx,cy - �������
		///\param uFlags - ���� �����������
		///\return TRUE � ������ ������
		BOOL SetWindowPos(HWND hWndInsertAfter,int X,int Y,int cx,int cy,UINT uFlags);
		///\brief "�������� multiple-window � position structure"
		///\param hWinPosInfo - "Handle to a multiple-window � position structure"
		///	���������� ���������� �� ����� ��� ����� ��������
		///\param hWndInsertAfter - ��������� ���� �� Z ����������
		///�������� HWND_BOTTOM,HWND_NOTOPMOST,HWND_TOP,HWND_TOPMOST
		///\param x,y - ����������
		///\param cx,cy - �������
		///\param uFlags - ���� �����������
		///\return "�������� multiple-window � position structure"
		HDWP DeferWindowPos(HDWP hWinPosInfo,HWND hWndInsertAfter,
			int x,int y,int cx,int cy,UINT uFlags);
		///\brief ���������� ����
		///\param X,Y - ����������
		///\param nWidth,nHeight - �������
		///\param fRepaint - ���� ������� ����������� ����� �����������
		///\return TRUE � ������ ������
		BOOL MoveWindow(int X,int Y,int nWidth,int nHeight,BOOL fRepaint);
		///\brief ���������� ��������� �� ����
		///\param nIndex - ID ���� ������������ ����������
		///\param ������������� ����������
		LONG GetWindowLong(int nIndex);
		///\brief ������������� ����� �������� � ���� ����
		///\param nIndex- ID ���� 
		///\param dwNewLong - ����� ��������
		///\return ���������� ��������
		LONG SetWindowLong(int nIndex,LONG dwNewLong);
		///\brief ������������ ����� ����
		///\param dwRemStyle - ��������� �����
		///\param dwAddStyle - ��������������� �����
		///\param uFlags - ���� ���������� ����
		///\return TRUE � ������ ������
		BOOL ModifyStyle(DWORD dwRemStyle,DWORD dwAddStyle,UINT uFlags=SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
		///\brief ������������ ����������� ����� ����
		///\param dwRemStyleEx - ��������� �����
		///\param dwAddStyleEx - ��������������� �����
		///\param uFlags - ���� ���������� ����
		///\return TRUE � ������ ������
		BOOL ModifyStyleEx(DWORD dwRemStyleEx,DWORD dwAddStyleEx,UINT uFlags=SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
		///\brief ������� ��� ��������� ������� ���������� �������
		///\param lpRect - ��������� �� ���������� ������
		///\return TRUE � ������ ������
		BOOL GetClientRect(LPRECT lpRect);
		///\brief ������� ��� ��������� ������������ ����
		///\param lpRect - ��������� �� ���������� ������������
		///\return TRUE � ������ ������
		BOOL GetWindowRect(LPRECT lpRect);
		///\brief ������������� ����� ����
		///\param hFont - ����� ������
		///\param fRedraw - ���������� ���� ���� TRUE
		void SetFont(HFONT hFont,BOOL fRedraw);
		///\brief ���������� ����� ����
		HFONT GetFont();		
		///\brief ��������� ��������� ������������� �� ����
		///\param lpRect - ������������� ��� ����������, ���� NULL, �� ���������� �� ����
		///\param fErase - ��� TRUE ������� ����������
		///\return TRUE � ������ ������
		BOOL InvalidateRect(CONST RECT *lpRect=NULL,BOOL fErase=FALSE);
		///\brief ������� ���������� ����
		///\param lpText - ����
		///\param lpCaption - ���������
		///\param uType - ��� ����
		///\return  
		///	IDABORT Abort button was selected. 
		///	IDCANCEL Cancel button was selected. 
		///	IDCONTINUE Continue button was selected. 
		///	IDIGNORE Ignore button was selected. 
		///	IDNO No button was selected. 
		///	IDOK OK button was selected. 
		///	IDRETRY Retry button was selected. 
		///	IDTRYAGAIN Try Again button was selected. 
		///	IDYES Yes button was selected. 
		int MessageBox(LPCTSTR lpText,LPCTSTR lpCaption,UINT uType);
		///\brief ���������� �������� ����
		///\return �������� ����
		HDC GetDC();
		///\brief ����� ������ ��� ����
		///\param hRgn - ����� �������
		///\param fRedraw - ���� ����������� ����� ��������� �������
		///\return TRUE � ������ ������
		BOOL SetWindowRgn(HRGN hRgn,BOOL fRedraw);
		///\brief ���������� ������ ��� ����
		///\param hRgn - ����� ������������� �������
		///\return 
		///	NULLREGION The region is empty. 
		///	SIMPLEREGION The region is a single rectangle. 
		///	COMPLEXREGION The region is more than one rectangle. 
		///	ERROR The specified window does not have a region, 
		///	or an error occurred while attempting to return the region.  
		int GetWindowRgn(HRGN hRgn);
		///\brief ��������� ���� �� ����� �� Z ����������
		///\return TRUE � ������ ������
		BOOL BringWindowToTop();
		///\brief ��������� ���������� ������������ �������� ���� � ���������� ���������� ������
		///\param lpPoint - ��������� �� ����������
		///\return TRUE � ������ ������
		BOOL ScreenToClient(LPPOINT lpPoint);
		///\brief ������������ ����������� ����
		///\param lprcUpdate - ���������������� �������������. ���� NULL, �� ���������������� ���� �������������.
		///\param hrgnUpdate - ���������������� ������. ���� NULL, �� ���������������� ���� ������.
		///\param flags - ���� �����������
		///\return TRUE � ������ ������
		BOOL RedrawWindow(CONST RECT *lprcUpdate,HRGN hrgnUpdate,UINT flags);
		///brief ����������/������������� ����������� ����
		///\param fRedraw - ���� ���������
		///\return TRUE � ������ ������
		BOOL SetRedraw(BOOL fRedraw);
		///\brief "��������/���������" ����
		///\param fEnable - ���� ���������/����������
		///\return TRUE � ������ ������
		BOOL EnableWindow(BOOL fEnable);
		///\brief ��������� ������� ��� ����
		///\param nIDEvent - ID �������, ������������ ��� ��������� ������� ������������
		///\param uElapse - ����� ������������ � ��
		///\return ID �������
		UINT_PTR SetTimer(UINT_PTR nIDEvent,UINT uElapse);
		///\brief ���������� ��������� ������
		///\param uIDEvent - ID �������, ������� ������ SetTimer
		///\return TRUE � ������ ������
		BOOL KillTimer(UINT_PTR uIDEvent);
		///\brief ������������� ���� ��� ����
		///\param hMenu - ����� ����
		///\return TRUE � ������ ������
		BOOL SetMenu(HMENU hMenu);
		///\brief �������� ����� �� �������� �������
		///\param nIDDlgItem - ID ��������
		///\return ����� �������
		HWND GetDlgItem(int nIDDlgItem);
		///\brief ��������� ��������� ����
		///\return TRUE ���� ������
		BOOL IsWindowVisible();
		///\brief ��������� ����������� ����
		///\return TRUE ���� ������
		BOOL IsWindowEnabled();
		///\brief ���������� ���������� �� ����
		///\return TRUE ���� ����������
		BOOL IsWindow();
		///\brief ��������� ���������� ������� � ��������
		///\param lpPoint - ��������� � �����������
		///\return FALSE � ������ �������
		BOOL ClientToScreen(LPPOINT lpPoint);
		///\brief ������������� ������ �� ����
		///\param hIcon - ����� ������
		///\param fBig - ���� TRUE, �� ����� ����������� ������� ������, ����� ���������
		///\return ����� ���������� ������������� ������ � ������ ������, ����� NULL
		HICON SetIcon(HICON hIcon,BOOL fBig);
		///\brief ������������ ������������ ���� �� �-������ �/��� �� ��������� �����
		///\param crKey - �������� ����, �� �� �������� ���� ����� ���������
		///\param bAlpha - �����-�����
		///\param  dwFlags - �������� ������ ������� �� �����(LWA_COLORKEY)
		///	�/��� �� �����������(LWA_ALPHA)
		///\return FALSE � ������ �������
	#if(_WIN32_WINNT >= 0x0500)
		BOOL SetLayeredWindowAttributes(COLORREF crKey,BYTE bAlpha,DWORD dwFlags);
	#endif
		///\brief ����������� ����� ���� �� ������
		///\return ����� ����
		HWND Detach();
		///\brief ������� �������/�������� �������� � ������ ������� ����
		///\param lpString - ��� ��������
		///\param hData - ������
		///\return TRUE � ������ ������
		BOOL SetProp(LPTSTR lpString,HANDLE hData);
		///\brief ������� �������� �������� �� ������ ������� ����
		///\param lpString - ��� ��������
		///\return ������
		HANDLE GetProp(LPTSTR lpString);
		///\brief ����������� ����
		///\return TRUE � ������ ������
		BOOL CloseWindow();
		///\brief ���������� ���� ����
		///\return ���� ����
		HMENU GetMenu();
		///\brief ���������� ������������� ����
		///\param uCmd - �������� �������
		///\return ����� �������������� ����
		HWND GetWindow(UINT uCmd);
		///\brief ������� ��� ��������� ����� ������ ����
		///\param nIndex - ������ ����
		///\param dwNewLong - �������� ����
		///\return ���������� ��������
		DWORD SetClassLong(int nIndex,LONG dwNewLong);
	};
}
#endif //__ULWND_H__