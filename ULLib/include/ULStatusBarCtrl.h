///\file ULStatusBarCtrl.h
///\brief ������������ ���� ������ ���������� ������������ �� ��������� ��������(12.10.2007)
#pragma once
#ifndef __UL_ULSTATUSBARCTRL_H__
#define __UL_ULSTATUSBARCTRL_H__
#include "ULWndCtrl.h" 
#include "ULStatusBar.h" 
namespace ULWnds
{
	namespace ULWndCtrls
	{
		///\class CULStatusBarCtrl
		///\brief ����� ���������� ������������ �� ��������� ��������(12.10.2007)
		class CULStatusBarCtrl:
			public CULWndCtrl
		{
		protected:
			///\brief ��������������� ��� ��������
			ULBars::CULStatusBar m_StatusBar;
		public:
			///\brief �����������
			CULStatusBarCtrl(void);
			///\brief ����������� �����������
			CULStatusBarCtrl(CULStatusBarCtrl&);
			///\brief ����������
			virtual ~CULStatusBarCtrl(void);
			///\brief �������� �����������
			void operator=(CULStatusBarCtrl&);
			///\brief ������� ���������� ������ �� ��������
			inline ULBars::CULStatusBar& GetStatusBar(){return m_StatusBar;};
			///\brief ������� �������� �����������������
			///\param hParentWnd - ����� ��������(��������)
			///\param nStatusID - ID ����������
			///\param fGrip - �������� �� ���������� ��� ��������� ��������
			BOOL CreateStatusBar(HWND hParentWnd,short nStatusID,BOOL fGrip=TRUE);
		protected:
			///\brief ���������� WM_SIZE
			virtual LRESULT OnSize(WPARAM nType,LPARAM size);
		};
	}
}
#endif //__UL_ULSTATUSBARCTRL_H__