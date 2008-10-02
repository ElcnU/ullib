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
		///\brief ����� ���� ��������
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
		};
	}
}

#endif //_ULCOMBOBOX_H__