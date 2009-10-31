///\file FolderDlg.h
///\brief ������������ ���� ��� ������ ������ ����������
#ifndef _ULFOLDERDLG_H__
#define _ULFOLDERDLG_H__
#include <shlobj.h>
#include "ULDlg.h"
namespace ULWnds
{
	namespace ULDlgs
	{
		///\class CULFolderDlg
		///\brief ����� ������ ����������
		class CULFolderDlg:
			public CULDlg
		{
		protected:
			BROWSEINFO m_bi;
			///\brief �������� ��� ULWnds::ULDlgs::CULDlg::Create
			HWND Create(short /*idTempl*/,	
				HWND /*hParentHWND=NULL*/)
			{return NULL;}
		public:
			///\brief �����������
			CULFolderDlg(HWND hParentWnd=NULL,UINT ulFlags=/*BIF_NEWDIALOGSTYLE|*/BIF_DONTGOBELOWDOMAIN/*|BIF_USENEWUI*/);
			///\brief ����������
			~CULFolderDlg();
			///\brief ���������� ������ ������ ����������
			///\returun IDOK/IDCANCEL
			int CreateModal();
			///\brief ���������� ��������� ����
			///\return ��������� ����
			LPCTSTR GetPath();
			///\brief ���������� ��������� ����
			///\param lpszPath - ��������� �� �����, � ������� ����� ���������� ����
			///\param nLen - ������ ������
			///\return TRUE � ������ ������
			BOOL GetPath(LPTSTR lpszPath,WORD nLen);
		protected:
			///\brief ������� ����
			static LRESULT WndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
			///\brief callback ��� ������������
			static int CALLBACK BrowseCallbackProc(HWND hDlg,UINT uMsg,LPARAM lParam,LPARAM lpData);
		protected:
			///\brief ������� ���������� ������������� �������
			virtual void OnInitialized();
			///\brief ��� ����������� ��������� WM_COMMAND
			virtual LRESULT OnMessage(UINT uMsg,WPARAM wParam,LPARAM lParam);
			///\brief �������� ��� IDOK
			virtual void OnOK(WORD,HWND);
			///\brief �������� ��� IDCANCEL
			virtual void OnCancel(WORD,HWND);
		};
	}
}

#endif //_ULFOLDERDLG_H__
