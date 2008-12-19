///\file ULCommDlgs.h
///\brief ������������ ���� ������� ����������� ���������� ����(02.01.2007)
#pragma once
#ifndef __UL_COMMDLG_H__
#define __UL_COMMDLG_H__
#include "ULDlg.h"
#include "ULOther.h"

namespace ULWnds
{
	namespace ULDlgs
	{
		///\namespace ULCommDlgs
		///\brief ������������ ��� ������� ����������� ��������
		namespace ULCommDlgs
		{
			///\class CULCommDlg
			///\brief ����� �������� - �������� ��� ����������� ��������
			class CULCommDlg:
				public ULWnds::ULDlgs::CULDlg
			{
			private:
				///\brief �������� ��� ULWnds::ULDlgs::CULDlg::Create
				HWND Create(short /*idTempl*/,	
					HWND /*hParentHWND=NULL*/)
				{return NULL;}
			protected:
				///\brief ������� ����
				static LRESULT WndProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);
			public:
				///\brief �����������
				CULCommDlg();
				///\brief ����������
					virtual ~CULCommDlg(){};
			};
			///\class CULColorDlg
			///\brief ����� ������ �����
			class CULColorDlg:
				public CULCommDlg
			{
			public:
				///\brief ������ ���������  ��� ����������� ������� ������ �����
				CHOOSECOLOR m_cc;
				///\brief ������ ����-������
				COLORREF m_acrCustClr[16]; 
			public:
				///\brief �����������
				///\param clrInit - ���� �����������
				///\param dwFlags - ����� ��� ����������� �������
				explicit CULColorDlg(COLORREF clrInit = 0,
					DWORD dwFlags=CC_RGBINIT|CC_ANYCOLOR|CC_ENABLEHOOK);
				///\brief ����������
				virtual ~CULColorDlg();
				///\brief �������� ���������� �������
				///\param idTempl - ������ �������, ���� ��������� ���� CC_ENABLETEMPLATE
				///\param hParentWnd - ����� ��������
				///\return ��� ��������
				int CreateModal(short idTempl,HWND hParentWnd);	
				///\brief ���������� ������ ���� - ������ 
				///\return ������ ���� - ������ 
				COLORREF* GetSavedCustomColors()
					{return &m_acrCustClr[0];}
				///\brief ���������� ��������� ����
				///\return ��������� ����
				COLORREF GetColor()
					{return m_cc.rgbResult;}	
			};
			///\class CULFileDlg
			///\brief ������� ��������/���������� ������(�������������)
			class CULFileDlg:
				public CULCommDlg
			{
			protected:
				///\brief ���� ��������/���������� �����
				BOOL m_fOpenFileDlg;
				///\brief ����� ��� ����� � ���� �����
				ULOther::CULStr m_strFile;
				///\brief ����� ��� ����� �����
				ULOther::CULStr m_strFileTitle;
			public:
				///\brief ��������� �������� ������
				OPENFILENAME m_ofn;
			public:
				///\brief �����������
				///\param fOpenFileDlg - TRUE ������ ������� �����, FALSE ������ ���������� �����
				///\param lpszDefExt - ���������� ����� �����������
				///\param lpszFileName - ��� ����� �����������
				///\param dwFlags - ����� ������� �������� ������
				///\param lpszFilter - ������ �������� ������
				///\param dwFilterIndex - ������ �������� ���������� �������
				explicit CULFileDlg(BOOL fOpenFileDlg,
					LPCTSTR lpszDefExt = NULL,
					LPCTSTR lpszFileName = NULL,
					DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT/*|OFN_ENABLEHOOK*/,
					LPCTSTR lpszFilter = NULL,
					DWORD dwFilterIndex=0);
				///\brief �������� ���������� �������
				///\param idTempl - ������ �������, ���� ��������� ���� CC_ENABLETEMPLATE
				///\param hParentWnd - ����� ��������
				///\return ��� ��������
				int CreateModal(short idTempl, HWND hParentWnd);
				///\brief ������������� ���������� �����������
				///\param lpszDefExt - ����� � ���������� �����������
				///\return ���������� �������� ���������� �����������, ����� NULL
				LPCTSTR SetDefExt(LPCTSTR lpszDefExt);
				///\brief ���������� ��c������� �����������
				///\return ���������� �����������, ����� NULL
				LPCTSTR GetFileExt() 
					{return m_ofn.lpstrDefExt;}
				///\brief ���������� ��������� ����
				///\return ��������� ����, ����� NULL
				LPCTSTR GetFileTitle()
					{return m_ofn.lpstrFileTitle;}
				///\brief ���������� ��������� ���� � ����
				///\return ��������� ���� � ����, ����� NULL
				LPCTSTR GetFileName()
					{return m_ofn.lpstrFile;}
			};
			///\class CULFontDlg
			///\brief ����� ������ ������
			class CULFontDlg:
				public CULCommDlg
			{
			public:
				///\brief ������ ��������� ��� ����������� ������� ������ ������
				CHOOSEFONT m_cf;
			protected:
				///\brief ��������� ������
				LOGFONT m_lf;
			public:
				///\brief �����������
				///\param clrInit - ���� �����������
				///\param dwFlags - ����� ��� ����������� �������
				explicit CULFontDlg();
				///\brief �������� ���������� �������
				///\param idTempl - ������ �������, ���� ��������� ���� CC_ENABLETEMPLATE
				///\param hParentWnd - ����� ��������
				///\return ��� ��������
				int CreateModal(short idTempl,HWND hParentWnd);	
				///\brief ���������� ������ �� ��������� ������
				///\return �������� ����� �� ��������� ������
				LOGFONT& GetLogFont();
				///\brief ������������� ���� ������ � ������� ������
				///\note ������� ����� CF_EFFECTS. \n
				/// ����� ������� ��������� ���� SetFontColor m_cf.Flags
				void SetFontColor(COLORREF clrFont);
				///\brief ���������� ���� ������ � ������� ������
				///\note ������� ����� CF_EFFECTS 
				COLORREF GetFontColor();

			};
		}
	}
}
#endif //__UL_COMMDLG_H__

/* 
CFindReplaceDialog
 Lets user initiate a find or replace operation in a text file.
 
 
CPrintDialog
 Lets user specify information for a print job.
*/