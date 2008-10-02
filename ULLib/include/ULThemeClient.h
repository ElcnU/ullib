///\file ULThemeClient.h
///\brief ������������ ���� ������ ������� ����(06.08.2008)
#pragma once 
#ifndef _ULTHEMECLIENT_H__
#define _ULTHEMECLIENT_H__
#include "ULWnd.h"
#include "ULGDI.h"
#include "ULButtons.h"
namespace ULWnds
{
	///\class CULThemeClient
	///\brief ����� ������� ����
	class CULThemeClient
	{
	private:
		///\brief ������� ����
		static LRESULT ClientWndProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);
		///\brief ������� ���� ����������� ��� ���������������� ��������� ����������
		WNDPROC m_lpSubClassWndProc;
	protected:
		///\brief ��������� �� ������ ������ ���� ���������
		CULWnd* m_pClientWnd;
		///\brief  �������� � ������ ��� ������� �����������
		ULGDI::ULDC::CULDC m_MemDC;
		///\brief ���������� ����
		COLORREF m_clrInner;
		///\brief ������� ����
		COLORREF m_clrOuter;
		///\brief ������ ����������
		int m_nRadius;
		///\brief ����������� ��� ������ ������� (�)
		ULWnds::ULControls::ULButtons::CULHyperLink m_hlX;
		///\brief ����������� ��� ������ �������� (_)
		ULWnds::ULControls::ULButtons::CULHyperLink m_hl_;
		///\brief ������������� ��� ������ ��������
		enum {CTM_MINIMIZE=IDCANCEL+1};
	protected:		
		///\brief ������������ � �������� � ������ ������� ����� ����
		void CreateLeftUpCorner();
		///\brief ������������ � �������� � ������ ������� ������ ����
		void CreateRightUpCorner();
		///\brief ������������ � �������� � ������ ������ ����� ����
		void CreateLeftDownCorner();
		///\brief ������������ � �������� � ������ ������� ������� ����
		void CreateRightDownCorner();
		///\brief ������������ � �������� � ������ �������
		void CreateBorder();
	public: 
		///\brief �����������
		CULThemeClient();
		///\brief ����������� ����������� 
		CULThemeClient(CULThemeClient& ThemeClient);
		///\brief �����������. ������� ����
		///\param hClientWnd - ���� �������� ����
		CULThemeClient(HWND hClientWnd);
		///\brief �������� �����������
		virtual void operator = (CULThemeClient& ThemeClient);
		///\brief ����������
		virtual ~CULThemeClient();
	//================================================
		///\brief ������� ����
		///\param hClientWnd - ���� �������� ����
		///\return TRUE  � ������ ������
		BOOL Create(HWND hClientWnd);
		///\brief ���������� ������� ������� ����
		///\param dc - ������ ��������� ���������
		///\return TRUE  � ������ ������
		virtual BOOL OnEraseBkGndClient(ULGDI::ULDC::CULDC& dc);
		///\brif ���������� ������� �������� �������
		///\return TRUE  � ������ ������
		virtual BOOL OnCreateRgn();
		///\brif ���������� ������� �������� ����
		///\return TRUE  � ������ ������
		virtual BOOL OnCreateBkGnd();
		///\brief ������������� �������� ������
		///\param clrInner ���������� ����
		///\param clrOuter ������� ����
		void SetColors(COLORREF clrInner,COLORREF clrOuter);
		///\brief ������������� �������� ������
		///\param nRadius ������ 
		///\param ������� ����
		void SetRadius(int nRadius);
	};
}
#endif _ULTHEMECLIENT_H__