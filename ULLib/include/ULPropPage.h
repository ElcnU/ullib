///\file ULPropPage.h
///\brief ������������ ���� ������ root ����(21.07.2007)
#pragma once
#ifndef __UL_PROPPAGE_H__
#define __UL_PROPPAGE_H__
#include "ULDlg.h"
namespace ULWnds
{
	namespace ULDlgs
	{
		///\class CULPropPage
		///\brief ����� �������� ��� ���� �������(2006)
		class CULPropPage:public CULDlg
		{
		protected:
			///\brief ������� ���� ��� ��������� ��������
			static LRESULT WndProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);
		public:
			///\brief �����������
			CULPropPage();
			///\brief ����������
			virtual ~CULPropPage();
			///\brief ������� ������ �������� �������
			///\param TemplID - ID ������� �������
			///\param szTitle - ��������
			///\param szSubTitle - ����������� ��� ������ �������
			///\param hIcon - ����� ������
			///\param fHelp - ���� ������� ������ "������"
			///\return ����� �� ��������� �������� �������
			HPROPSHEETPAGE Create(short TemplID, 
				TCHAR* szTitle=NULL,
				TCHAR* szSubTitle=NULL, 
				HICON hIcon=NULL,
				BOOL fHelp=FALSE);
			///\brief ������ �������� Apply
			void DoChange();
			///\brief ������ ���������� Apply
			void DoUnChange();
		protected:
			///\brief ���������� ��������� �� WM_ONINITDIALOGz
			virtual LRESULT OnInitDialog(WPARAM,LPARAM);
			///\brief ���������� ��������� �� WM_NOTIFY
			virtual LRESULT OnNotify(WPARAM,LPARAM);
			///\brief ���������� ��������� �� PSN_SETACTIVE
			///	��������� ����� �������� ������ ������� � ���� 
			///	������� �������
			///\param dwFlags - ���� ��� ���� ����� ��������� 
			///	������ ��� ���� �������� �������
			///	PSWIZB_NEXT,PSWIZB_BACK,PSWIZB_FINISH
			virtual LRESULT OnSetActive(DWORD dwFlags);
			///\brief ���������� ��������� �� PSN_WIZNEXT,�.�. �� ������ Next
			///\param nResult - ��������� ���������� ��������, ���� -1,
			///	�� �������� �� ������������ ����� ���� ID ������� ��������� ��������
			virtual LRESULT OnWizNext(short nResult);
			///\brief ���������� ��������� �� PSN_WIZFINISH,�.�.�� ������ Finish
			///\param fFinish - ��������� ���������� ��������
			///	0/!0 - �������/�� ���������
			virtual LRESULT OnWizFinish(BOOL fFinish);
			///\brief ���������� ��������� �� PSN_RESET,�.�.�� ������
			///	Cancel ��� "X"
			///\param fXorCancel - �� ���� 1 = "X", 0=Cancel , �� � ���� 
			///	������ 0
			virtual LRESULT OnReset(BOOL fXorCancel);
			///\brief���������� ��� ������� OK ��� Apply
			///\param nReturn - ������������ ��������, ��������� �� 
			///	���������� ������ �� ��������
			virtual LRESULT OnApply(BYTE nReturn);
			///\brief ���������� ��� ������� �� ������ "�������"
			///\param hPropSheet - ����� �� ���
			virtual LRESULT OnHelp(HWND hPropSheet);
			///\brief ����������,����� ������� �������� ������������� 
			///	��������� ��������� ��� ���������� OK ��� Apply,
			///	���� � DWL_MSGRESULT ����� �� 0
			///\param fProblem - TRUE ��������� ������� �� ��������� �������� ��� ���������
			virtual LRESULT OnKillActivate(BOOL fProblem);
		};
	}
}
#endif //__UL_PROPPAGE_H__