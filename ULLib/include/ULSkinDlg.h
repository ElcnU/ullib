///\file ULSkinDlg.h
///\brief ������������ ���� ������ ����-��������� ����(17.10.2007)
#pragma once
#ifndef __UL_SKIN_DLG_H__
#define __UL_SKIN_DLG_H__


#include "ULDlg.h"
#include "ULGDI.h"
namespace ULWnds
{
	namespace ULDlgs
	{
		///\class CULSkinDlg
		///\brief ����� ����-��������� ����(17.10.2007)
		class CULSkinDlg:
			public CULDlg
		{
		private:
			///\brief ����� ������� ��� ������� ����������� ����
			HBITMAP m_hRgnBitmap;
			///\brief ����� ������� ��� ������� ���� ����������� ����
			HBITMAP m_hBGBitmap;
			///\brief �������� ������
			ULGDI::ULDC::CULDC m_MemDC;
			///\brief ������ ������� ����� ��������� ��������
			SIZE m_SizeDlg;
		public:
			///\brief �����������
			CULSkinDlg();
			///\brief ����������
			virtual ~CULSkinDlg();
			///\brief �������� ������ �� �������
			///\param hRgnBitmap - ������ ��� �������
			///\return TRUE ���� ������ ������
			BOOL SetBitmapRgn(HBITMAP hRgnBitmap);
			///\brief ������������� ������ ���
			///\param hBGBitmap - ������ ����
			void SetBitmapBG(HBITMAP hBGBitmap);
		protected:
			///\brief ���������� ��������� WM_INITDIALOG
			virtual LRESULT OnInitDialog(WPARAM wParam,LPARAM lParam);
			///\brief ���������� ��������� WM_ERASEBKGND
			virtual LRESULT OnEraseBkGnd(WPARAM,LPARAM);	
		};
	}
}
#endif//__UL_SKIN_DLG_H__