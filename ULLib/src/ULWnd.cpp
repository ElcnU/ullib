///\file ULWnd.cpp
///\brief cpp ���� ������ root ����(07.10.2007)
#include "..\..\ULLib\Include\UlWnd.h"
namespace ULWnds
{

	CULWnd::CULWnd(void):
		m_hParentWnd(NULL),
		m_hWnd(NULL),
		m_lpSubClassWndProc(NULL)
	{
	}
	CULWnd::CULWnd(CULWnd& Wnd):
		m_hParentWnd(Wnd.m_hParentWnd),
		m_hWnd(Wnd.m_hWnd),
		m_lpSubClassWndProc(Wnd.m_lpSubClassWndProc),
		MessageMap(Wnd.MessageMap)
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
}

