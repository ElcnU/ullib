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
			///\brief ����������� ������� � ������������ �� ����������
			///\param pInfo - ��������� �� ��������� � �����
			///\return ������ ����� �� ��������, �� ������� ����������, ����� -1
			int HitTest(LPLVHITTESTINFO pInfo)
				{return(int)SendMessage(LVM_HITTEST,0,(LPARAM)pInfo);}
			///\brief ����������� � ����� ������
			///\param nItem - ����� �����
			///\param dwData - ������
			///\return TRUE � ������ ������
			BOOL SetItemData(int nItem,DWORD_PTR dwData)
			{
				LVITEM it={0};
				it.mask=LVIF_PARAM;
				it.iItem=nItem;
				it.lParam=dwData;
				return (BOOL)SendMessage(LVM_SETITEM,0,(LPARAM)&it);
			}
			///\brief ���������� ����������� ������������ 
			///\param nItem - ����� �����
			///\return ������
			DWORD_PTR GetItemData(int nItem)
			{
				LVITEM it={0};
				it.mask=LVIF_PARAM;
				it.iItem=nItem;
				SendMessage(LVM_GETITEM,0,(LPARAM)&it);
				return it.lParam;
			}
			///\brief ��������� ������ ������� ���������� ��������
			///\return ����� ���������� ��������
			int GetFirstSelectedItemPosition()
				{return (int)SendMessage(LVM_GETNEXTITEM,(WPARAM)-1,(LPARAM)LVNI_SELECTED);}
			///\brief ��������� ������ ���������� ���������� ��������
			///\param pos - ����� �������
			///\return ����� ���������� ��������
			int GetNextSelectedItemPosition(int pos)
				{return (int)SendMessage(LVM_GETNEXTITEM,(WPARAM)pos,(LPARAM)LVNI_SELECTED);}
			///\brief ������� ��������� �������
			///\param nItem - ������� ��� ��������
			///\return TRUE � ������ ������
			BOOL DeleteItem(int nItem)
				{return (BOOL)SendMessage(LVM_DELETEITEM,(WPARAM)nItem);}
			///\brief ���������� ���������� � ������ ������� �����
			///\param nItem - ����� �����
			///\param lpRect - ��������� �� ������ RECT ��� ���������
			///\param nCode - �������� �������
			///\return TRUE � ������ ������
			BOOL GetItemRect(int nItem,LPRECT lpRect,UINT nCode);
			///\brief ���������� ���������� � ������ ������� ��������
			///\param nItem - ����� �����
			///\param iSubItem - ����� ��������
			///\param nArea - �������� �������
			///\param lpRect - ��������� �� ������ RECT ��� ���������
			///\return TRUE � ������ ������
			BOOL GetSubItemRect(int iItem, int iSubItem, int nArea, RECT* lpRect);
		};
	}
}

#endif //_ULLISTCTRL_H__