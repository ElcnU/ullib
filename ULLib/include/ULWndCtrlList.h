///\file ULWndCtrlList.h
///\brief ������������ ���� ������ ���������� ��� ��������� �������(03.08.2007)
#pragma once
#ifndef __UL_ULCTRLWNDLIST_H__
#define __UL_ULCTRLWNDLIST_H__
#include "ULWndCtrl.h"
#include "ULOther.h"
namespace ULWnds
{
	namespace ULWndCtrls
	{
		///\class CULWndCtrlList
		///\brief ����� - ��������� ��� ��������� �������(03.08.2007)
		class CULWndCtrlList
		{
		private:
			///\brief ������� ����������� ��� ���������������� ������� ����
			static LRESULT SubClassParentProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);
			///\brief ������ ������� ������� �������� ����
			static WNDPROC lpOldParentProc;
			///\brief ���� ����������� ��� ���� ���� ������� ������� ���������
			static BOOL m_fActive;
			///\brief ������ ���������� ��� ��������� �������
			static ULOther::CULArr<CULWndCtrl*> m_arWndCtrl;
		public:
			///\brief ���������, ���������� MDI ������, ��� �������� MDI �����
			enum enToMDIFrameMessage{MDIM_GETCLIENT=WM_APP+1001};
			///\brief ���������� ��������� ��������� �������
			static RECT m_rcParentClientFreeRect;
		public:
			///\brief ����������� 
			CULWndCtrlList();
			///\brief ����������� �����������
			CULWndCtrlList(CULWndCtrlList& WndCtrlList);
			///\brief ���������� 
			~CULWndCtrlList();
			///\brief �������� �����������
			void operator=(CULWndCtrlList& WndCtrlList);
			///\brief ������� �������� ���������� �������
			///\param hOwnerWnd - ����� ���� ��������(�������)
			///\return TRUE � ������ ������
			BOOL Create(HWND hOwnerWnd);
			///\brief ������� ���������� � ��������� ����� ��������
			///\param pULWndCtrl - ��������� �� ����� ��������� ��������
			///\return TRUE � ������ ������
			BOOL AddWndCtrl(CULWndCtrl* pULWndCtrl);
		};
	}
}
#endif //__UL_ULCTRLWNDLIST_H__