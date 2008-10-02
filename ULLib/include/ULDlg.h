///\file ULDlg.h
///\brief ������������ ���� ������ ��������� ����(2006)
#pragma once
#ifndef __UL_DLG_H__
#define __UL_DLG_H__

#include "ULSubClass.h"
namespace ULWnds
{
	namespace ULDlgs
	{
		///\class CULDlg
		///\brief ����� ��������� ����(2006)
		class CULDlg:public CULWnd
		{
		protected:
			///\brief ������� ����
			static LRESULT WndProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);
			///\brief ������������� ������� �������,
			///��������� ��� �������� ���� 
			short m_idTempl;
			///\brief ������������� ������,
			///��������� ��� �������� ���� 
			short m_idIcon;
			///\brief ���������� ��� ����������� ��������� ��� 
			///����������� ������
			BOOL m_fModal;
		public:
			///\brief ����������� �����������
			CULDlg(short idIcon=0);
			///\brief ����������
			virtual ~CULDlg(void);
			///\brief ������ ����������� ������
			///\param idTempl - ������������� ������� �������
			///\param hParentWnd - ����� ������������� ����
			HWND Create(short idTempl,	
				HWND hParentWnd=NULL);	
			///\brief ������ ��������� ������
			///\param idTempl - ������������� ������� �������
			///\param hParentWnd - ����� ������������� ����
			///\return IDOK ��� IDCANCEL
			int CreateModal(short idTempl,
				HWND hParentWnd=NULL);	  
			///\brief ������ ��� ����������� ����������� �������
			///\return TRUE ���� ��������
			inline BOOL IsModal()
				{return m_fModal;}
		//==================inline functions============================
			///\brief �������� ��������� ����� �������� �� �������
			///\param nIDDlgItem - ID ����� 
			///\param Msg - ���������
			///\param wParam - �������� 1
			///\param lParam - �������� 2
			///\return ����� ����������� ���������
			inline LRESULT SendDlgItemMessage(int nIDDlgItem,UINT Msg,
				WPARAM wParam,LPARAM lParam)
				{return ::SendDlgItemMessage(*this,nIDDlgItem,Msg,wParam,lParam);};
			///\brief �������� ����� �� �������� �� �������
			///\param nIDDlgItem - ID �������
			///\param lpString - ������
			///\param nMaxCount - ����� ������
			///\return ����������� �������� TCHAR � ������ ������, ����� NULL
			inline UINT GetDlgItemText(int nIDDlgItem,LPTSTR lpString,int nMaxCount)
				{return ::GetDlgItemText(*this,nIDDlgItem,lpString,nMaxCount);}
			///\brief ������������� ����� � ������� �� �������
			///\param nIDDlgItem - ID �������
			///\param lpString - ������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL SetDlgItemText(int nIDDlgItem,LPTSTR lpString)
				{return ::SetDlgItemText(*this,nIDDlgItem,lpString);}
			///\brief ������������� ����� �� ������� ������� ������������� ��� �� �����
			///\param nIDDlgItem - ID �������
			///\param uValue - �����
			///\param fSigned - ����������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL SetDlgItemInt(int nIDDlgItem,UINT uValue,BOOL fSigned)
				{return ::SetDlgItemInt(*this,nIDDlgItem,uValue,fSigned);}
			///\brief ���������� ����� ������������ �� �������� �������
			///\param nIDDlgItem - ID �������
			///\param lpTranslated - ����������� ��������� ��������(TRUE � ������ ������, ����� FALSE)
			///\param fSigned - ����������
			///\return ����� � ��������
			inline UINT GetDlgItemInt(int nIDDlgItem,BOOL *lpTranslated,BOOL fSigned)
				{return ::GetDlgItemInt(*this,nIDDlgItem,lpTranslated,fSigned);}
			///\brief ������� ����� ��������� �������� �������
			///\param hWndCtrl - ����� ��������
			inline void GotoDlgCtrl(HWND hWndCtrl)
				{SendMessage(WM_NEXTDLGCTL, (WPARAM)hWndCtrl, TRUE);}
			///\brief ������� ����� ���������� ��������� 
			///	�������� ������� �������� WS_TABSTOP
			inline void NextDlgCtrl()
				{SendMessage(WM_NEXTDLGCTL);}
			///\brief ������� ����� ����������� ��������� 
			///	�������� ������� �������� WS_TABSTOP
			inline void PrevDlgCtrl()
				{SendMessage(WM_NEXTDLGCTL, 1);}
		protected:
			///\brief ���������� WM_INITDIALOG 
			virtual LRESULT OnInitDialog(WPARAM,LPARAM /*lParam*/);
			///\brief ���������� WM_DESTROY
			virtual LRESULT OnDestroy(WPARAM /*wParam*/,LPARAM /*lParam*/);
			///\brief ���������� BN_CLICKED ������ IDOK 
			virtual void OnOK(WORD id,HWND hControl);
			///\brief ���������� BN_CLICKED ������ IDCANCEL 
			virtual void OnCancel(WORD id,HWND hControl);
		};
	}
}
#endif//__UL_DLG_H__