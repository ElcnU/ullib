///\file ULMDIChildWnd.h
///\brief ������������ ���� ������ ��������� ���� ����������� MDI(03.08.2007)
#pragma once
#ifndef __UL_ULMDICHILDWND_H__
#define __UL_ULMDICHILDWND_H__
#include "ULWnd.h"
namespace ULWnds
{
	namespace ULFrames
	{
		///\class CULMDIChildWnd
		///\brief ����� ��������� ���� ����������� MDI(03.08.2007)
		class CULMDIChildWnd:
			public CULWnd
		{
		protected:
			///\brief ������� ��������� ����
			static LRESULT WndProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);
		public:
			///\brief ���������, ������� ����� �������� ������� ��� ��������
			///\param WPARAM - HWND ������
			///\param LPARAM - �� �������������
			enum{CLM_DESTROYCHILD=WM_APP+1};
			///\brief �����������
			CULMDIChildWnd(void);
			///\brief ����������� �����������
			CULMDIChildWnd(CULMDIChildWnd& MDIChildWnd);
			///\brief ����������
			virtual ~CULMDIChildWnd(void);
			///\brief �������� �����������
			virtual void operator = (CULMDIChildWnd&);
			///\brief ������� �������� ��������� ����
			///\param szWindowName - ��������� ����
			///\param x,y - ���������� ����
			///\param cx,cy - ������� ����
			///\param IconID - ID ������ �� ��������
			///\param hClientWnd - ���������� ����
			///\param BGColor - ���� ���������� �������
			///\param dwChildStyle - ����� ���������  ����
			///\return ����� ���������� ����
			HWND Create(TCHAR* szWindowName,
						int x,
						int y,
						int cx,
						int cy,
						short IconID,
						HWND hClientWnd,
						short BGColor=COLOR_WINDOW,
						DWORD dwChildStyle=MDIS_ALLCHILDSTYLES|
						WS_CLIPSIBLINGS|WS_CLIPCHILDREN);
		protected:
			///\brief ���������� WM_CREATE
			virtual LRESULT OnCreate(WPARAM /*wParam*/,LPARAM);
			///\brief ���������� WM_NCDESTROY
			virtual LRESULT OnNcDestroy(WPARAM ,LPARAM);	
			///\brief ���������� WM_SHOWWINDOW
			virtual LRESULT OnShowWindow(WPARAM ,LPARAM);
		};
	}
}
#endif//__UL_ULMDICHILDWND_H__
