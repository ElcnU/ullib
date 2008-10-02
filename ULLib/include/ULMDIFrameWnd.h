///\file ULMDIFrameWnd.h
///\brief ������������ ���� ������ �������� ���� ����������� MDI(2006)
#pragma once
#ifndef __UL_ULMDIFRAMEWND_H__
#define __UL_ULMDIFRAMEWND_H__

#include "ULFrameWnd.h"
#include "UlWndCtrlList.h"
#include "ULMDIClientWnd.h"
namespace ULWnds
{
	namespace ULFrames
	{
		///\class CULMDIFrameWnd 
		///\brief ����� �������� ���� ����������� MDI(2006)
		class CULMDIFrameWnd :
			public CULFrameWnd
		{
		protected:
			///\brief����� ����-�������
			DWORD m_dwClientStyle;
			///brief ���������� ����� ����-�������
			DWORD m_dwClientStyleEx;
			///\brief ID ������� ��������� ����
			UINT m_idFirstChild;
			///\brief ID �������, � ������� ����� ���������� �������� �������� ����
			UINT m_idSubMenu;
			///\brief ��������� ��� ��������� �������. 
			///	��� ��������������� ��������, ����� ��� ������, ���������...
			///	����������� � MDI ������ ���� ������������ �� CULWndCtrl 
			///	� ��������� � m_WndCtrlList.
			///	��� ���������� ��������� ���������� ������� �������� ���� 
			///	��� ���������������� MDICLIENT ����.
			ULWndCtrls::CULWndCtrlList m_WndCtrlList;
			///\brief ������ MDI-����������� ����
			CULMDIClientWnd* m_pMDIClientWnd;
		public:
			///\brief �����������
			CULMDIFrameWnd(void);
			///\brief ����������� �����������
			CULMDIFrameWnd(CULMDIFrameWnd&);
			///\brief ����������
			virtual ~CULMDIFrameWnd(void);
			///\brief �������� �����������
			virtual void operator = (CULMDIFrameWnd&);
			///\brief ������� �������� �������� ����
			///\param szWindowName - ��������� ����
			///\param MenuID - ID ���� �� ��������
			///\param IconID - ID ������ �� ��������
			///\param IconSmID - ID ��������� ������ �� ��������
			///\param BGColor - ���� ���������� �������
			///\param idSubMenu - ����� ������� �������� ���� ����,
			///	� ������� ����� ������������ �������� ����
			///\param dwStyle - ����� ����
			///\param dwStyleEx - ����������� ����� ����
			///\param idFirstChild - ���� ������� ��������� ����
			///\param dwClientStyle - ����� ���������� ���� 
			///\param dwClientStyleEx - ����������� ����� ���������� ����
			HWND Create(TCHAR* szWindowName,
						short MenuID, 
						short IconID, 
						short IconSmID, 
						short BGColor,
						UINT idSubMenu,
						DWORD dwStyle=WS_OVERLAPPEDWINDOW |	WS_CLIPCHILDREN,
						DWORD dwStyleEx=WS_EX_APPWINDOW,
						UINT idFirstChild=1000,
						DWORD dwClientStyle=WS_CHILD | WS_CLIPCHILDREN | WS_VSCROLL | WS_HSCROLL,
						DWORD dwClientStyleEx=0);
			///\brief ���������� ������� ����
			inline virtual LRESULT DefWindowProc(UINT uMsg , WPARAM wParam , LPARAM lParam)
			{
				return ::DefFrameProc(*this,
					((m_pMDIClientWnd!=NULL)?m_pMDIClientWnd->m_hWnd:NULL),uMsg,wParam,lParam);
			};
			///\brief ������� ��� ������� ������ ����������� ����
			///\param pMDIClientWnd ��������� �� ����� ������ ����������� ����
			///\return TRUE � ������ ������
			CULMDIClientWnd* ReplaceMDIClient(CULMDIClientWnd* pMDIClientWnd);
			///\brief ���������� WM_CREATE
		protected:
			virtual LRESULT OnCreate(WPARAM /*wParam*/,LPARAM);
			///\brief ���������� WM_SIZE
			virtual LRESULT OnSize(WPARAM,LPARAM lParam);
			///\brief ���������� CULWndCtrlList::MDIM_GETCLIENT
			virtual LRESULT OnGetMDIClient(WPARAM,LPARAM)
				{return (BOOL)(LONG_PTR)m_pMDIClientWnd->m_hWnd;};	
			///\brief ���������� ������������ �������� � ID=ID_WINDOW_CASCADE
			///	��������� ���� ��������
			virtual void OnWindowCascade(WORD ID,HWND hControl);
			///\brief ���������� ������������ �������� � ID=ID_WINDOW_ARRANGE
			///	������������� ����
			virtual void OnWindowArrange(WORD ID,HWND hControl);
			///\brief ���������� ������������ �������� � ID=ID_WINDOW_TILE_HORZ
			///	��������� ���� ������������
			virtual void OnWindowTileHorz(WORD ID,HWND hControl);
			///\brief ���������� ������������ �������� � ID=ID_WINDOW_TILE_VERT
			///	��������� ���� �����������
			virtual void OnWindowTileVert(WORD ID,HWND hControl);
		};
	}
}
#endif//__UL_ULMDIFRAMEWND_H__