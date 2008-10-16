///\file ULComboBox.h 
///\brief ���� ���������� ������ ���� ��������
#ifndef _ULCOMBOBOX_H__
#define _ULCOMBOBOX_H__
#include "ULSubClass.h"
#include "commctrl.h"

namespace ULWnds
{
	namespace ULControls
	{
		///\class CULComboBox
		///\brief ����� ����������
		class CULComboBox:
			public ULWnds::CULSubClass
		{
		public:
			///\brief �����������
			CULComboBox();
			///\brief ������� ��� �������� ������������
			///\param hParentWnd - ����� ������������� ����
			///\param uID - ID ������������
			///\param x,y - ���������� ������������
			///\param cx,cy - ������ ������������
			///\param dwStyle - ����� ������������
			///\param dwStyleEx - ����������� ����� 
			///\return TRUE � ������ ������
			BOOL Create(HWND hParentWnd,UINT uID,int x,int y,int cx,int cy,DWORD dwStyle,DWORD dwStyleEx);
			///\brief ��������� ������ � ���������
			///\param pszStr - ������
			///\return ����� ���������� ������ � ������ ������ ����� CB_ERR ��� CB_ERRSPACE
			int AddString(LPCTSTR pszStr);
			///\brief ��������� ������ � ���������
			///\param pszStr - ������
			///\param pszStr - ������
			///\return ����� ���������� ������ � ������ ������ ����� CB_ERR ��� CB_ERRSPACE
			int InsertString(int nItem,LPCTSTR pszStr);
			///\brief ������ ������ �� ����������
			///\return ����������� ���������� �����. CB_ERR � ������ ������
			int DeleteString(int nItem);
			///\brief ����������� ������ � �����
			///\param nItem - ����� �����
			///\param dwData - ������
			///\return TRUE  � ������ ������
			BOOL SetItemData(int nItem,DWORD dwData);
			///\brief ���������� ������ ������������� � �����
			///\param nItem - ����� �����
			///\return ������, � ������ ������ CB_ERR
			DWORD GetItemData(int nItem);
			///\brief �������� ������ �� ����� � ���������
			///\param nItem - ���������� ����
			///\return ������ ���������� �����. ���� nItem �� �������� � �������� ������, �� CB_ERR 
			int SetCurSel(int nItem);
			///\brief �������� ����� ��������� ������ � �������
			///\return ������ ���������� �����. ���� ������ �� �������, ��  CB_ERR
			int GetCurSel();
			///\brief ������� ��� �����
			void ResetContent();
			///\brief ����������/������ ��������
			///\param fShowIt - ���� (����������/������)
			void ShowDropDown(BOOL fShowIt);
			///\brief ���������� ���������� � ����������
			///\param pcbi - ��������� �� ��������� ��������� � �����������
			///\return TRUE � ������ ������
			BOOL GetComboBoxInfo(PCOMBOBOXINFO pcbi);
			///\brief ���������� ����� ��������� � ����������
			///\return ����� ���������. CB_ERR � ������ ������
			int GetCount();
			///\brief ���������� ����� ���������� ����� ���������
			///\param nItem - ����� ����� 
			///\param pszText - ����� ��� ����������� ������ 
			///\return ����� ������������ ������, � ������ ������ CB_ERR
			int GetLBText(int nItem,LPTSTR pszText);
			///\brief ���������� ����� ������ � ��������� �����
			///\param nItem - ����� ����� 
			///\return ����� ������, � ������ ������ CB_ERR
			int GetLBTextLen(int nItem);			
		};
	}
}

#endif //_ULCOMBOBOX_H__