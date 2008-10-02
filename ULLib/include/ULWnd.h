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
	//==================inline functions============================
		///\brief ���������� ������� ����
		inline virtual LRESULT DefWindowProc(UINT uMsg,WPARAM wParam,LPARAM lParam)
			{return ::DefWindowProc(*this, uMsg, wParam, lParam);};
		///\brief ����� ������� ����
		inline virtual LRESULT CallWindowProc(UINT uMsg,WPARAM wParam,LPARAM lParam)
			{return ::CallWindowProc(m_lpSubClassWndProc,*this, uMsg, wParam, lParam);}	
		///\brief ��������� ������ ����
		///\param lpString - ������
		///\param nMaxCount - ������������ ����� ������
		///\return ����������� ���������� �������� � lpString
		inline int GetWindowText(LPTSTR lpString,int nMaxCount)
			{return ::GetWindowText(*this,lpString,nMaxCount);}
		///\brief ��������� ����� ������ ����
		///\return ����������� �������� � ����
		inline int GetWindowTextLength()
			{return ::GetWindowTextLength(*this);}
		///\brief ��������� ������ � ����
		///\param lpString - �����
		///\return TRUE � ������ ������
		inline BOOL SetWindowText(LPTSTR lpString)
			{return ::SetWindowText(*this,lpString);}
		///\brief �������� ��������� � ����
		///\param Msg - ���������
		///\param wParam - �������� 1
		///\param lParam - �������� 2
		///\return ����� ����������� ���������
		inline LRESULT SendMessage(UINT Msg,WPARAM wParam=0,LPARAM lParam=0)
			{return ::SendMessage(*this,Msg,wParam,lParam);}
		///\brief ���������� ��������� � ���� � ����� ������� ����� ���������
		///\param Msg - ���������
		///\param wParam - �������� 1
		///\param lParam - �������� 2
		///\return TRUE � ������ ������
		inline BOOL PostMessage(UINT Msg,WPARAM wParam=0,LPARAM lParam=0)
			{return ::PostMessage(*this,Msg,wParam,lParam);}
		///\brief ��������� ������
		///\return ���������� ����� ����������� ����
		inline HWND SetFocus()
			{return ::SetFocus(*this);}
		///\brief ���������� ����
		///\return TRUE � ������ ������
		inline BOOL DestroyWindow()
			{return ((m_hWnd!=NULL)?::DestroyWindow(*this):FALSE);}
		///\brief ������ ���� ��������
		///\return ���������� �������� ����
		inline HWND SetActiveWindow()
			{return ::SetActiveWindow(*this);}
		///\brief �������� ���� �� �������� ���� � ������ ��� ��������
		///\return TRUE � ������ ������
		inline BOOL SetForegroundWindow()
			{return ::SetForegroundWindow(*this);}
		///\brief ���������� ��������
		///\return ����� ��������
		inline HWND GetParent()
			{return ::GetParent(*this);};
		///\brief ������������� ������ ��������
		///\return ����� ����������� ��������
		inline HWND SetParent(HWND hWndNewParent)
			{m_hParentWnd=hWndNewParent;return ::SetParent(*this,hWndNewParent);};
		///\brief �������� ��������� ��������� ����
		///\param nCmdShow - ���������
		///\return TRUE � ������ ���������� ���������, ����� FALSE
		inline BOOL ShowWindow(int nCmdShow)
			{return ::ShowWindow(*this,nCmdShow);};
		///\brief ��������� ����
		///\return TRUE � ������ ���������� ���������, ����� FALSE
		inline BOOL UpdateWindow()
			{return ::UpdateWindow(*this);}
		///\brief �������� ������� ����
		///\param hWndInsertAfter - ��������� ���� �� Z ����������
		///�������� HWND_BOTTOM,HWND_NOTOPMOST,HWND_TOP,HWND_TOPMOST
		///\param X,Y - ����������
		///\param cx,cy - �������
		///\param uFlags - ���� �����������
		///\return TRUE � ������ ������
		inline BOOL SetWindowPos(HWND hWndInsertAfter,int X,int Y,int cx,int cy,UINT uFlags)
			{return ::SetWindowPos(*this,hWndInsertAfter,X,Y,cx,cy,uFlags);}
		///\brief "�������� multiple-window � position structure"
		///\param hWinPosInfo - "Handle to a multiple-window � position structure"
		///	���������� ���������� �� ����� ��� ����� ��������
		///\param hWndInsertAfter - ��������� ���� �� Z ����������
		///�������� HWND_BOTTOM,HWND_NOTOPMOST,HWND_TOP,HWND_TOPMOST
		///\param x,y - ����������
		///\param cx,cy - �������
		///\param uFlags - ���� �����������
		///\return "�������� multiple-window � position structure"
		inline HDWP DeferWindowPos(HDWP hWinPosInfo,HWND hWndInsertAfter,
			int x,int y,int cx,int cy,UINT uFlags)
			{return ::DeferWindowPos(hWinPosInfo,*this,hWndInsertAfter,x,y,cx,cy,uFlags);};
		///\brief ���������� ����
		///\param X,Y - ����������
		///\param nWidth,nHeight - �������
		///\param fRepaint - ���� ������� ����������� ����� �����������
		///\return TRUE � ������ ������
		inline BOOL MoveWindow(int X,int Y,int nWidth,int nHeight,BOOL fRepaint)
			{return ::MoveWindow(*this,X,Y,nWidth,nHeight,fRepaint);}
		///\brief ���������� ��������� �� ����
		///\param nIndex - ID ���� ������������ ����������
		///\param ������������� ����������
		inline LONG GetWindowLong(int nIndex)
			{return ::GetWindowLong(*this,nIndex);}
		///\brief ������������� ����� �������� � ���� ����
		///\param nIndex- ID ���� 
		///\param dwNewLong - ����� ��������
		///\return ���������� ��������
		inline LONG SetWindowLong(int nIndex,LONG dwNewLong)
			{return ::SetWindowLong(*this,nIndex,dwNewLong);}
		///\brief ������������ ����� ����
		///\param dwRemStyle - ��������� �����
		///\param dwAddStyle - ��������������� �����
		///\param uFlags - ���� ���������� ����
		///\return TRUE � ������ ������
		inline BOOL ModifySyle(DWORD dwRemStyle,DWORD dwAddStyle,UINT uFlags=SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED)
		{	
			SetWindowLong(GWL_STYLE,
				(GetWindowLong(GWL_STYLE)&~dwRemStyle)|dwAddStyle);
			return SetWindowPos(NULL,0,0,0,0,uFlags);
		}
		///\brief ������������ ����������� ����� ����
		///\param dwRemStyleEx - ��������� �����
		///\param dwAddStyleEx - ��������������� �����
		///\param uFlags - ���� ���������� ����
		///\return TRUE � ������ ������
		inline BOOL ModifySyleEx(DWORD dwRemStyleEx,DWORD dwAddStyleEx,UINT uFlags=SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED)
		{	
			SetWindowLong(GWL_EXSTYLE,
				(GetWindowLong(GWL_EXSTYLE)&(~dwRemStyleEx))|dwAddStyleEx);
			return SetWindowPos(NULL,0,0,0,0,uFlags);
		}
		///\brief ������� ��� ��������� ������� ���������� �������
		///\param lpRect - ��������� �� ���������� ������
		///\return TRUE � ������ ������
		inline BOOL GetClientRect(LPRECT lpRect)
			{return ::GetClientRect(*this,lpRect);}
		///\brief ������� ��� ��������� ������������ ����
		///\param lpRect - ��������� �� ���������� ������������
		///\return TRUE � ������ ������
		inline BOOL GetWindowRect(LPRECT lpRect)
			{return ::GetWindowRect(*this,lpRect);}
		///\brief ������������� ����� ����
		///\param hFont - ����� ������
		///\param fRedraw - ���������� ���� ���� TRUE
		inline void SetFont(HFONT hFont,BOOL fRedraw)
			{SendMessage(WM_SETFONT,(WPARAM)hFont,(LPARAM)fRedraw);}
		///\brief ��������� ��������� ������������� �� ����
		///\param lpRect - ������������� ��� ����������, ���� NULL, �� ���������� �� ����
		///\param fErase - ��� TRUE ������� ����������
		///\return TRUE � ������ ������
		inline BOOL InvalidateRect(CONST RECT *lpRect=NULL,BOOL fErase=FALSE)
			{return ::InvalidateRect(*this,lpRect,fErase);}
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
		inline int MessageBox(LPCTSTR lpText,LPCTSTR lpCaption,UINT uType)
			{return ::MessageBox(*this,lpText,lpCaption,uType);}
		///\brief ���������� �������� ����
		///\return �������� ����
		inline HDC GetDC()
			{return ::GetDC(*this);}
		///\brief ����� ������ ��� ����
		///\param hRgn - ����� �������
		///\param fRedraw - ���� ����������� ����� ��������� �������
		///\return TRUE � ������ ������
		inline BOOL SetWindowRgn(HRGN hRgn,BOOL fRedraw)
			{return ::SetWindowRgn(*this,hRgn,fRedraw);}
		///\brief ���������� ������ ��� ����
		///\param hRgn - ����� ������������� �������
		///\return 
		///	NULLREGION The region is empty. 
		///	SIMPLEREGION The region is a single rectangle. 
		///	COMPLEXREGION The region is more than one rectangle. 
		///	ERROR The specified window does not have a region, 
		///	or an error occurred while attempting to return the region.  
		inline int GetWindowRgn(HRGN hRgn)
			{return ::GetWindowRgn(*this,hRgn);}
		///\brief ��������� ���� �� ����� �� Z ����������
		///\return TRUE � ������ ������
		inline BOOL BringWindowToTop()
			{return ::BringWindowToTop(*this);}
		///\brief ��������� ���������� ������������ �������� ���� � ���������� ���������� ������
		///\param lpPoint - ��������� �� ����������
		///\return TRUE � ������ ������
		inline BOOL ScreenToClient(LPPOINT lpPoint)
			{return ::ScreenToClient(*this,lpPoint);}
		///\brief ������������ ����������� ����
		///\param lprcUpdate - ���������������� �������������. ���� NULL, �� ���������������� ���� �������������.
		///\param hrgnUpdate - ���������������� ������. ���� NULL, �� ���������������� ���� ������.
		///\param flags - ���� �����������
		///\return TRUE � ������ ������
		inline BOOL RedrawWindow(CONST RECT *lprcUpdate,HRGN hrgnUpdate,UINT flags)
			{return ::RedrawWindow(*this,lprcUpdate,hrgnUpdate,flags);}
		///brief ����������/������������� ����������� ����
		///\param fRedraw - ���� ���������
		///\return TRUE � ������ ������
		inline BOOL SetRedraw(BOOL fRedraw)
			{return (SendMessage(WM_SETREDRAW,WPARAM(fRedraw))!=0);}
		///\brief "��������/���������" ����
		///\param fEnable - ���� ���������/����������
		///\return TRUE � ������ ������
		inline BOOL EnableWindow(BOOL fEnable)
			{return ::EnableWindow(*this,fEnable);}
		///\brief ��������� ������� ��� ����
		///\param nIDEvent - ID �������, ������������ ��� ��������� ������� ������������
		///\param uElapse - ����� ������������ � ��
		///\return ID �������
		inline UINT_PTR SetTimer(UINT_PTR nIDEvent,UINT uElapse)
			{return ::SetTimer(*this,nIDEvent,uElapse,NULL);}
		///\brief ���������� ��������� ������
		///\param uIDEvent - ID �������, ������� ������ SetTimer
		///\return TRUE � ������ ������
		BOOL KillTimer(UINT_PTR uIDEvent)
			{return ::KillTimer(*this,uIDEvent);}
		///\brief ������������� ���� ��� ����
		///\param hMenu - ����� ����
		///\return TRUE � ������ ������
		BOOL SetMenu(HMENU hMenu)
			{return ::SetMenu(*this,hMenu);}
		///\brief �������� ����� �� �������� �������
		///\param nIDDlgItem - ID ��������
		///\return ����� �������
		inline HWND GetDlgItem(int nIDDlgItem)
			{return ::GetDlgItem(*this,nIDDlgItem);}
		///\brief ��������� ��������� ����
		///\return TRUE ���� ������
		inline BOOL IsWindowVisible()
			{return ::IsWindowVisible(*this);}
		///\brief ���������� ���������� �� ����
		///\return TRUE ���� ����������
		inline BOOL IsWindow()
			{return ::IsWindow(*this);}
		///\brief ��������� ���������� ������� � ��������
		///\param lpPoint - ��������� � �����������
		///\return FALSE � ������ �������
		BOOL ClientToScreen(LPPOINT lpPoint)
			{return ::ClientToScreen(*this,lpPoint);}
		///\brief ������������� ������ �� ����
		///\param hIcon - ����� ����jyrb
		///\param fBig - ���� TRUE, �� ����� ����������� ������� ������, ����� ���������
		///\return ����� ���������� ������������� ������ � ������ ������, ����� NULL
		HICON SetIcon(HICON hIcon,BOOL fBig)
			{return (HICON)SendMessage(WM_SETICON,(WPARAM)hIcon,(LPARAM)((fBig)?ICON_BIG:ICON_SMALL));}
		///\brief ������������ ������������ ���� �� �-������ �/��� �� ��������� �����
		///\param crKey - �������� ����, �� �� �������� ���� ����� ���������
		///\param bAlpha - �����-�����
		///\param  dwFlags - �������� ������ ������� �� �����(LWA_COLORKEY)
		///	�/��� �� �����������(LWA_ALPHA)
		///\return FALSE � ������ �������
	#if(_WIN32_WINNT >= 0x0500)
		BOOL SetLayeredWindowAttributes(COLORREF crKey,BYTE bAlpha,DWORD dwFlags)
			{return ::SetLayeredWindowAttributes(*this,crKey,bAlpha,dwFlags);}
	#endif
		///\brief ����������� ����� ���� �� ������
		///\return ����� ����
		inline HWND Detach()
			{HWND hTmp=m_hWnd;m_hWnd=NULL;return hTmp;}
		///\brief ������� �������/�������� �������� � ������ ������� ����
		///\param lpString - ��� ��������
		///\param hData - ������
		///\return TRUE � ������ ������
		BOOL SetProp(LPTSTR lpString,HANDLE hData)
			{return ::SetProp(*this,lpString,hData);}
		///\brief ������� �������� �������� �� ������ ������� ����
		///\param lpString - ��� ��������
		///\return ������
		HANDLE GetProp(LPTSTR lpString)
			{return ::GetProp(*this,lpString);}
		///\brief ����������� ����
		///\return TRUE � ������ ������
		BOOL CloseWindow()
			{return ::CloseWindow(*this);};
		///\brief ���������� ���� ����
		///\return ���� ����
		HMENU GetMenu()
			{return ::GetMenu(*this);}
		///\brief ���������� ������������� ����
		///\param uCmd - �������� �������
		///\return ����� �������������� ����
		HWND GetWindow(UINT uCmd)
			{return ::GetWindow(*this,uCmd);}
		///\brief ������� ��� ��������� ����� ������ ����
		///\param nIndex - ������ ����
		///\param dwNewLong - �������� ����
		///\return ���������� ��������
		DWORD SetClassLong(int nIndex,LONG dwNewLong)
			{return ::SetClassLong(*this,nIndex,dwNewLong);}
	};
}
#endif //__ULWND_H__