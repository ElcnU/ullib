///\file ULListCtrl.h 
///\brief ���� ���������� ������ ���� ��������
#ifndef _ULLISTCTRL_H__
#define _ULLISTCTRL_H__
#include "ULSubClass.h"
#include "commctrl.h"

namespace ULWnds
{
	namespace ULControls
	{
		///\class CULListCtrl
		///\brief ����� ���� ��������
		class CULListCtrl:
			public ULWnds::CULSubClass
		{
		public:
			///\brief �����������
			CULListCtrl();
			///\brief ������� ��� �������� ������������
			///\param hParentWnd - ����� ������������� ����
			///\param uID - ID ������������
			///\param x,y - ���������� ������������
			///\param cx,cy - ������ ������������
			///\param dwStyle - ����� ������������
			///\param dwStyleEx - ����������� ����� 
			///\return TRUE � ������ ������
			BOOL Create(HWND hParentWnd,UINT uID,int x,int y,int cx,int cy,DWORD dwStyle,DWORD dwStyleEx);
			///\brief ��������� ������� � �����������
			///\param nCol - ������� �������
			///\param lpszColumnHeading - �������� �������
			///\param nFormat - ���� ������������
			///\param nWidth - ������ �������
			///\param nSubItem - ������ �������� ���������������� �� ��������
			///\return ������ ������ ������� � ������ ������, ����� -1
			int InsertColumn(int nCol,LPCTSTR lpszColumnHeading,int nFormat = LVCFMT_LEFT,
				int nWidth = -1,int nSubItem = -1);
			///\brief ������ ������ �������
			///\param nCol - ����� ������� 
			///\param cx - ������ �������
			///\	����� ��������� �������� LVSCW_AUTOSIZE � LVSCW_AUTOSIZE_USEHEADER
			///\return TRUE � ������ ������
			BOOL SetColumnWidth(int nCol,int cx);
			///\brief �������� ������ �������
			///\param nCol - ����� ������� 
			///\return ������ �������
			int GetColumnWidth(int nCol);
			///\brief ��������� ���� 
			///\param nItem - ������� �������
			///\param lpszItem - ������
			///\return ����� ������������ �����
			int InsertItem(int nItem,LPCTSTR lpszItem);	
			///\brief ������������� ����� � ������ �������
			///\param nItem - � ����� ��� �������
			///\param nSubItem - � �������� ��� �������
			///\param lpszText - ����� ��� �������
			///\return TRUE � ������ ������
			BOOL SetItemText(int nItem,int nSubItem,LPCTSTR lpszText);
			///\brief ��������� ����������� ������
			///\return ����������j ������
			int GetItemCount();
			///\brief ������������� ���������� ����� ������������
			///\param dwNewStyle - ����� �����
			///\return ���������� ���������� ���������� ����� ������������
			DWORD SetExtendedStyle(DWORD dwNewStyle);
			///\brief ������� ��� ����� � ������������
			///\return TRUE � ������ ������
			BOOL DeleteAllItems();
			///\brief ��������� ���������� � �������
			///\param nCol - ����� �������
			///\param pCol - ��������� �� ��������� � ����������� � �������
			///\return  TRUE � ������ ������
			BOOL GetColumn(int nCol,LPLVCOLUMN pCol);
		};
	}
}

#endif //_ULLISTCTRL_H__