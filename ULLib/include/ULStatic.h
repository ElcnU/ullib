///\file ULStatic.h
///\brief ������������ ���� ������ ������ ��� STATIC ��������(23.12.2008)
#pragma once
#ifndef _STATIC_H__
#define _STATIC_H__
#include "ULSubClass.h"
namespace ULWnds
{
	namespace ULControls
	{
		///\class CULStatic
		///\brief ����� ������ ��� STATIC ��������(23.12.2008)
		class CULStatic:
			public CULSubClass
		{
		public:
			///\brief �����������
			CULStatic();
			///\brief ������� ��� �������� �����
			///\param hParentWnd - ����� ������������� ����
			///\param pszText - �����
			///\param uID - ������������� ��������
			///\param x,y - ���������� ��������
			///\param cx,cy - ������ 
			///\param dwStyle - ����� 
			///\param dwStyleEx - ����������� ����� 
			///\return TRUE � ������ ������
			BOOL Create(HWND hParentWnd,LPCTSTR pszText,UINT uID,int x,int y,
				int cx,int cy,DWORD dwStyle=WS_CHILD|WS_VISIBLE,
				DWORD dwStyleEx=WS_EX_CLIENTEDGE|WS_EX_ACCEPTFILES);
			///\brief ������� �� ������ �� ������ SS_ICON ������
			///\param hIcon - ����� ������
			///\return ���������� ������
			HICON SetIcon(HICON hIcon);

		};
	}
}
#endif //_STATIC_H__