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
			///\brief �������� ����� �� ������ �������
			///\param nItem - � ����� 
			///\param nSubItem - � �������� 
			///\param lpszText - ����� ��� ��������� ������
			///\param nLen - ����� ������
			///\return TRUE � ������ ������
			BOOL GetItemText(int nItem,int nSubItem,LPTSTR lpszText,int nLen);
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
			///\brief ����������� ������� ����� � ������������ �� ����������
			///\param pInfo - ��������� �� ��������� � �����
			///\return ������ ����� �� ��������, �� ������� ����������, ����� -1
			int HitTest(LPLVHITTESTINFO pInfo);
			///\brief ����������� ������� �������� � ������������ �� ����������
			///\param pInfo - ��������� �� ��������� � �����
			///\return ������ ����� �� ��������, �� ������� ����������, ����� -1
			int SubItemHitTest(LPLVHITTESTINFO pInfo);
			///\brief ����������� � ����� ������
			///\param nItem - ����� �����
			///\param dwData - ������
			///\return TRUE � ������ ������
			BOOL SetItemData(int nItem,DWORD_PTR dwData);
			///\brief ���������� ����������� ������������ 
			///\param nItem - ����� �����
			///\return ������
			DWORD_PTR GetItemData(int nItem);
			///\brief ��������� ������ ������� ���������� ��������
			///\return ����� ���������� ��������
			int GetFirstSelectedItemPosition();
			///\brief ��������� ������ ���������� ���������� ��������
			///\param pos - ����� �������
			///\return ����� ���������� ��������
			int GetNextSelectedItemPosition(int pos);
			///\brief ������� ��������� �������
			///\param nItem - ������� ��� ��������
			///\return TRUE � ������ ������
			BOOL DeleteItem(int nItem);
			///\brief ���������� ���������� � ������ ������� �����
			///\param nItem - ����� �����
			///\param lpRect - ��������� �� ������ RECT ��� ���������
			///\param nCode - �������� �������
			///\return TRUE � ������ ������
			BOOL GetItemRect(int nItem,LPRECT lpRect,UINT nCode);
			///\brief ���������� ���������� � ������ ������� ��������
			///\param iItem - ����� �����
			///\param iSubItem - ����� ��������
			///\param nArea - �������� �������
			///\param lpRect - ��������� �� ������ RECT ��� ���������
			///\return TRUE � ������ ������
			BOOL GetSubItemRect(int iItem, int iSubItem, int nArea, RECT* lpRect);
			///\brief ���������� ����� ��������� � �����
			///\return ����� ��������� � �����
			int GetSubItemCount();
		};
	}
}

#endif //_ULLISTCTRL_H__