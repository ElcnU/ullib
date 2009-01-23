///\file ULPropSheet.h
///\brief ������������ ���� ������ root ����(2006)
#pragma once
#ifndef __UL_PROPSHEET_H__
#define __UL_PROPSHEET_H__

#include "ULSubClass.h"
#include "ULOther.h"
#pragma comment(lib,"comctl32.lib")
namespace ULWnds
{
	namespace ULDlgs
	{
		///\class CULPropSheet
		///\brief ����� ���� �������(2006)
		class CULPropSheet:
			public CULSubClass
		{
		private:
			///\brief ���� ������ �����������
			BOOL m_fWizard;
		protected:
			///\brief ������ ��� �������� ������� ��������� ������ �������
			ULOther::CULArr<HPROPSHEETPAGE> m_phPropSheetPage;
		public:
			///\brief ������������ ����� �������
			enum enWizardFlags
			{
				wfWizard=PSH_WIZARD,
				wfWizard97=PSH_WIZARD97,
			#if _WIN32_IE>0x0400
				wfWizardLite=PSH_WIZARD_LITE,
			#endif
				wfWizardContextHelp=PSH_WIZARDCONTEXTHELP,
				wfWizardHasFinish=PSH_WIZARDHASFINISH,
				wfNonWizard=0
			};
			PROPSHEETHEADER m_psh;
		public:
			///\brief �����������
			CULPropSheet();
			///\brief ����������
			virtual ~CULPropSheet();
			/*!\brief ������� ��������� ������� m_phPropSheetPage
			����� ��������� �������� �������*/
			///\param hPropSheetPage �������� �������
			///\return TRUE � ������ ������
			BOOL AddPage(HPROPSHEETPAGE hPropSheetPage);
			///\brief ������� ������ ���� �������
			///\param hParenWnd - ����� ������������� ����
			///\param szCaption - ��������� ����
			///\param hbmHeader - ����� ��������, ������� ����������� � ���������
			///\param hbmWatermark - ����� ��������, ������� ����������� � ����� ����� ����
			///\param nWizardFlags - ����� �������/TabControla
			///\param fModal - ���������/�����������
			///	���� ����������� �� ������� ������ ����� ����
			///	��:� ������������ �� ����������,�.�.���� �� ����� 
			///	����� ����������� 8-)
			INT_PTR Create(HWND hParenWnd,
				LPCTSTR szCaption,
				HBITMAP hbmHeader=NULL,
				HBITMAP hbmWatermark=NULL,
				UINT nWizardFlags=wfNonWizard,
				BOOL fModal=TRUE);
			///\brief ������� ������ ���� �������
			///\param hParenWnd - ����� ������������� ����
			///\param szCaption - ��������� ����
			///\param rscHeader - ID �������� �� ��������, ������� ����������� � ���������
			///\param rscWatermark - ID �������� �� ��������, 
			///	������� ������������ ����� ����� ����
			///\param nWizardFlags - ����� �������/TabControla
			///\param fModal - ���������/����������� ���� �����������,
			///	�� ������� ������ ����� ����
			INT_PTR Create(HWND hParenWnd,
				LPCTSTR szCaption,
				int rscHeader=0,
				int rscWatermark=0,
				UINT nWizardFlags=wfNonWizard,
				BOOL fModal=TRUE);
			///\brief ���������� ����� �����������
			///\return TRUE, ���� ������
			BOOL IsWizard();
		protected:
			virtual LRESULT OnDestroy(WPARAM,LPARAM);
		};
	}
}
#endif //__UL_PROPSHEET_H__