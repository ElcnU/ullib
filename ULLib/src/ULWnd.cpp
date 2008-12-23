///\file ULWnd.cpp
///\brief cpp ���� ������ root ����(07.10.2007)
#include "..\..\ULLib\Include\UlWnd.h"
namespace ULWnds
{

	CULWnd::CULWnd(void):
		m_hParentWnd(NULL),
		m_hWnd(NULL),
		m_lpSubClassWndProc(NULL),
		m_szDefClassName(_T("ULWNDCLASS"))
	{
	}
	CULWnd::CULWnd(CULWnd& Wnd):
		m_hParentWnd(Wnd.m_hParentWnd),
		m_hWnd(Wnd.m_hWnd),
		m_lpSubClassWndProc(Wnd.m_lpSubClassWndProc),
		MessageMap(Wnd.MessageMap),
		m_szDefClassName(_T("ULWNDCLASS"))
	{
	}

	CULWnd::CULWnd(HWND hwnd):m_hWnd(hwnd)
	{
		m_hParentWnd=GetParent();
		CULWnd* pWnd=FromHandle(hwnd);
		if(pWnd)
			*this=*pWnd;
	}

	CULWnd::~CULWnd(void)
	{
		DestroyWindow();//���������� ���� ��� ����������� ������
	}

	void CULWnd::operator = (CULWnd& Wnd)
	{
		m_hParentWnd=Wnd.m_hParentWnd;
		m_hWnd=Wnd.m_hWnd;
		m_lpSubClassWndProc=Wnd.m_lpSubClassWndProc;
		MessageMap=Wnd.MessageMap;
	}

	BOOL CULWnd::PreTranslateMessage(MSG* /*pMsg*/)
	{
		return TRUE;
	};
	//================================================
	//������� ����
	//����� ��� �������� ���� (WM_INITDIALOG,WM_NCCREATE)
	//����������� this � GWL_USERDATA ��� ������������ �������������
	//� WndProc ������������� ������ ������ 
	//� WM_INITDIALOG this ��������� ����� CreateDialogParam
	//� WM_NCCREATE this ��������� ����� CreateWindow
	//================================================
	LRESULT CULWnd::WndProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam)
	{
		LONG dwNewLong;
		CULWnd *pULWnd=NULL;
		switch(uMsg)
		{
		case WM_CREATE:
			{
				dwNewLong=(LONG)(LONG_PTR) ((LPCREATESTRUCT) lParam)->lpCreateParams;
				::SetWindowLong (hWnd, GWL_USERDATA,dwNewLong);
				// ������� ��������� �� �����
				pULWnd = (CULWnd*)(((LPCREATESTRUCT) lParam)->lpCreateParams); 
				pULWnd->m_hWnd=hWnd;
				break;
			}
		default:
			{
			   pULWnd = FromHandle(hWnd);
			}
		}

		if(pULWnd!=NULL)
		{
			LRESULT lRes=pULWnd->OnMessage(uMsg,wParam,lParam);
			if(lRes)
				return lRes;
			if(uMsg==WM_COMMAND)
			{
					BOOL fRet=pULWnd->MessageMap.ProcessCommand(pULWnd,wParam,lParam);
					if(fRet)
						return fRet;
			}
			else 
				if(uMsg==WM_NOTIFY)
				{
					BOOL fRet=pULWnd->MessageMap.ProcessNotify(pULWnd,(NMHDR*)lParam);
					if(fRet)
						return fRet;
				}
			BOOL fRet=pULWnd->MessageMap.ProcessMessage(pULWnd,uMsg,wParam,lParam);
			if(fRet)
				return fRet;
			else
				return pULWnd->DefWindowProc(uMsg, wParam, lParam);
		}
		else
			return ::DefWindowProc(hWnd,uMsg, wParam, lParam);
	}
	LRESULT CULWnd::OnMessage(UINT /*uMsg*/,WPARAM /*wParam*/,LPARAM /*lParam*/)
	{
		return 0;
	}

	BOOL CULWnd::RegisterDefClass()
	{
		WNDCLASSEX wcex;	    
		wcex.cbSize = sizeof(WNDCLASSEX); 		
		wcex.style			= CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc	= (WNDPROC)WndProc;
		wcex.cbClsExtra		= 0;
		wcex.cbWndExtra		= 0;
		wcex.hInstance		= ULOther::ULGetResourceHandle();
		wcex.hIcon			= NULL;
		wcex.hCursor		= NULL;
		wcex.hbrBackground	= NULL;
		wcex.lpszMenuName	= NULL;	
		wcex.lpszClassName	= m_szDefClassName;
		wcex.hIconSm		= NULL;
		return (RegisterClassEx(&wcex)!=NULL);
	}

	BOOL CULWnd::Create(LPCTSTR lpClassName,LPCTSTR lpWindowName,DWORD dwStyle,
			int x,int y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu)
	{
		if(!lpClassName)
			RegisterDefClass();
		m_hParentWnd=hWndParent;
		m_hWnd=::CreateWindow((lpClassName)?lpClassName:m_szDefClassName,lpWindowName,dwStyle,
			x,y,nWidth,nHeight,hWndParent,hMenu,ULOther::ULGetResourceHandle(),this);
		return (m_hWnd!=NULL);
	}

	BOOL CULWnd::CreateEx(DWORD dwExStyle,LPCTSTR lpClassName,LPCTSTR lpWindowName,DWORD dwStyle,
		int x,int y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu)
	{
		if(!lpClassName)
			RegisterDefClass();
		m_hParentWnd=hWndParent;
		m_hWnd=::CreateWindowEx(dwExStyle,(lpClassName)?lpClassName:m_szDefClassName,lpWindowName,dwStyle,
			x,y,nWidth,nHeight,hWndParent,hMenu,ULOther::ULGetResourceHandle(),this);
		return (m_hWnd!=NULL);
	}

	LRESULT CULWnd::DefWindowProc(UINT uMsg,WPARAM wParam,LPARAM lParam)
	{
		return ::DefWindowProc(*this, uMsg, wParam, lParam);
	}
	
	LRESULT CULWnd::CallWindowProc(UINT uMsg,WPARAM wParam,LPARAM lParam)
	{
		return ::CallWindowProc(m_lpSubClassWndProc,*this, uMsg, wParam, lParam);
	}	

	int CULWnd::GetWindowText(LPTSTR lpString,int nMaxCount)
	{
		return ::GetWindowText(*this,lpString,nMaxCount);
	}

	int CULWnd::GetWindowTextLength()
	{
		return ::GetWindowTextLength(*this);
	}

	BOOL CULWnd::SetWindowText(LPTSTR lpString)
	{
		return ::SetWindowText(*this,lpString);
	}

	LRESULT CULWnd::SendMessage(UINT Msg,WPARAM wParam,LPARAM lParam)
	{
		return ::SendMessage(*this,Msg,wParam,lParam);
	}

	BOOL CULWnd::PostMessage(UINT Msg,WPARAM wParam,LPARAM lParam)
	{
		return ::PostMessage(*this,Msg,wParam,lParam);
	}

	HWND CULWnd::SetFocus()
	{
		return ::SetFocus(*this);
	}

	BOOL CULWnd::DestroyWindow()
	{
		return ((m_hWnd!=NULL)?::DestroyWindow(*this):FALSE);
	}
	HWND CULWnd::SetActiveWindow()
	{
		return ::SetActiveWindow(*this);
	}
	BOOL CULWnd::SetForegroundWindow()
	{
		return ::SetForegroundWindow(*this);
	}
	HWND CULWnd::GetParent()
	{
		return ::GetParent(*this);
	}
	HWND CULWnd::SetParent(HWND hWndNewParent)
	{
		m_hParentWnd=hWndNewParent;return ::SetParent(*this,hWndNewParent);
	}
	BOOL CULWnd::ShowWindow(int nCmdShow)
	{
		return ::ShowWindow(*this,nCmdShow);
	}
	BOOL CULWnd::UpdateWindow()
	{
		return ::UpdateWindow(*this);}
	BOOL CULWnd::SetWindowPos(HWND hWndInsertAfter,int X,int Y,int cx,int cy,UINT uFlags)
	{
		return ::SetWindowPos(*this,hWndInsertAfter,X,Y,cx,cy,uFlags);
	}
	HDWP CULWnd::DeferWindowPos(HDWP hWinPosInfo,HWND hWndInsertAfter,
		int x,int y,int cx,int cy,UINT uFlags)
	{
		return ::DeferWindowPos(hWinPosInfo,*this,hWndInsertAfter,x,y,cx,cy,uFlags);
	}
	BOOL CULWnd::MoveWindow(int X,int Y,int nWidth,int nHeight,BOOL fRepaint)
	{
		return ::MoveWindow(*this,X,Y,nWidth,nHeight,fRepaint);
	}
	LONG CULWnd::GetWindowLong(int nIndex)
	{
		return ::GetWindowLong(*this,nIndex);
	}
	LONG CULWnd::SetWindowLong(int nIndex,LONG dwNewLong)
	{
		return ::SetWindowLong(*this,nIndex,dwNewLong);
	}
	BOOL CULWnd::ModifyStyle(DWORD dwRemStyle,DWORD dwAddStyle,UINT uFlags)
	{	
		SetWindowLong(GWL_STYLE,
			(GetWindowLong(GWL_STYLE)&~dwRemStyle)|dwAddStyle);
		return SetWindowPos(NULL,0,0,0,0,uFlags);
	}
	BOOL CULWnd::ModifyStyleEx(DWORD dwRemStyleEx,DWORD dwAddStyleEx,UINT uFlags)
	{	
		SetWindowLong(GWL_EXSTYLE,
			(GetWindowLong(GWL_EXSTYLE)&(~dwRemStyleEx))|dwAddStyleEx);
		return SetWindowPos(NULL,0,0,0,0,uFlags);
	}
	BOOL CULWnd::GetClientRect(LPRECT lpRect)
	{
		return ::GetClientRect(*this,lpRect);
	}
	BOOL CULWnd::GetWindowRect(LPRECT lpRect)
	{
		return ::GetWindowRect(*this,lpRect);
	}
	void CULWnd::SetFont(HFONT hFont,BOOL fRedraw)
	{
		SendMessage(WM_SETFONT,(WPARAM)hFont,(LPARAM)fRedraw);
	}
	HFONT CULWnd::GetFont()
	{
		return (HFONT)SendMessage(WM_GETFONT);
	}
	BOOL CULWnd::InvalidateRect(CONST RECT *lpRect,BOOL fErase)
	{
		return ::InvalidateRect(*this,lpRect,fErase);
	}
	int CULWnd::MessageBox(LPCTSTR lpText,LPCTSTR lpCaption,UINT uType)
	{
		return ::MessageBox(*this,lpText,lpCaption,uType);
	}
	HDC CULWnd::GetDC()
	{
		return ::GetDC(*this);
	}
	BOOL CULWnd::SetWindowRgn(HRGN hRgn,BOOL fRedraw)
	{
		return ::SetWindowRgn(*this,hRgn,fRedraw);
	}
	int CULWnd::GetWindowRgn(HRGN hRgn)
	{
		return ::GetWindowRgn(*this,hRgn);
	}
	BOOL CULWnd::BringWindowToTop()
	{
		return ::BringWindowToTop(*this);
	}
	BOOL CULWnd::ScreenToClient(LPPOINT lpPoint)
	{
		return ::ScreenToClient(*this,lpPoint);
	}

	BOOL CULWnd::RedrawWindow(CONST RECT *lprcUpdate,HRGN hrgnUpdate,UINT flags)
	{
		return ::RedrawWindow(*this,lprcUpdate,hrgnUpdate,flags);
	}
	BOOL CULWnd::SetRedraw(BOOL fRedraw)
	{
		return (SendMessage(WM_SETREDRAW,WPARAM(fRedraw))!=0);
	}
	BOOL CULWnd::EnableWindow(BOOL fEnable)
	{
		return ::EnableWindow(*this,fEnable);
	}
	UINT_PTR CULWnd::SetTimer(UINT_PTR nIDEvent,UINT uElapse)
	{
		return ::SetTimer(*this,nIDEvent,uElapse,NULL);
	}
	BOOL CULWnd::KillTimer(UINT_PTR uIDEvent)
	{
		return ::KillTimer(*this,uIDEvent);
	}
	BOOL CULWnd::SetMenu(HMENU hMenu)
	{
		return ::SetMenu(*this,hMenu);
	}
	HWND CULWnd::GetDlgItem(int nIDDlgItem)
	{
		return ::GetDlgItem(*this,nIDDlgItem);
	}
	BOOL CULWnd::IsWindowVisible()
	{
		return ::IsWindowVisible(*this);
	}
	BOOL CULWnd::IsWindow()
	{
		return ::IsWindow(*this);
	}
	BOOL CULWnd::ClientToScreen(LPPOINT lpPoint)
	{
		return ::ClientToScreen(*this,lpPoint);
	}
	HICON CULWnd::SetIcon(HICON hIcon,BOOL fBig)
	{
		return (HICON)SendMessage(WM_SETICON,(WPARAM)((fBig)?ICON_BIG:ICON_SMALL),(LPARAM)hIcon);
	}
#if(_WIN32_WINNT >= 0x0500)
	BOOL CULWnd::SetLayeredWindowAttributes(COLORREF crKey,BYTE bAlpha,DWORD dwFlags)
	{
		return ::SetLayeredWindowAttributes(*this,crKey,bAlpha,dwFlags);
	}
#endif
	HWND CULWnd::Detach()
	{
		HWND hTmp=m_hWnd;m_hWnd=NULL;return hTmp;
	}
	BOOL CULWnd::SetProp(LPTSTR lpString,HANDLE hData)
	{
		return ::SetProp(*this,lpString,hData);
	}
	HANDLE CULWnd::GetProp(LPTSTR lpString)
	{
		return ::GetProp(*this,lpString);
	}
	BOOL CULWnd::CloseWindow()
	{
		return ::CloseWindow(*this);
	}
	HMENU CULWnd::GetMenu()
	{
		return ::GetMenu(*this);
	}
	HWND CULWnd::GetWindow(UINT uCmd)
	{
		return ::GetWindow(*this,uCmd);
	}
	/*
	DWORD CULWnd::SetClassLong(int nIndex,LONG dwNewLong)
	{
		return ::SetClassLong(*this,nIndex,dwNewLong);
	}
	*/
	BOOL CULWnd::IsWindowEnabled()
	{
		return ::IsWindowEnabled(*this);
	}
	DWORD CULWnd::SetClassLongPtr(int nIndex,LONG dwNewLong)
	{
		return ::SetClassLongPtr(*this,nIndex,dwNewLong);
	}
}

