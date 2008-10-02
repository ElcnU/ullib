///\file ULListBox.h
///\brief ������������ ���� ������ ������ ��� LISTBOX ��������(08.09.2007)
#pragma once
#ifndef __LISTBOX__H_
#define __LISTBOX__H_
#include "ULSubClass.h"
namespace ULWnds
{
	namespace ULControls
	{
		///\class CULListBox
		///\brief ����� ������ ��� LISTBOX ��������(08.09.2007)
		class CULListBox:public CULSubClass
		{
		public:
			///\brief �����������
			CULListBox();
			///\brief ����������
			virtual ~CULListBox();
			///\brief ������� ��� �������� ���������
			///\param hParentWnd - ����� ������������� ����
			///\param uID - ID ������
			///\param x,y - ���������� ������
			///\param cx,cy - ������ ������
			///\param dwStyle - ����� �����
			///\param dwStyleEx - ����������� ����� �����
			///\return TRUE � ������ ������
			BOOL Create(HWND hParentWnd,UINT uID,int x,int y,
				int cx,int cy,DWORD dwStyle=WS_CHILD|WS_VISIBLE|WS_TABSTOP|LBS_HASSTRINGS,
				DWORD dwStyleEx=WS_EX_CLIENTEDGE);
		//==================inline functions============================

			///\brief ��������� ������ � ��������
			///\param pcszStr - ������
			///\return ����� ����������� ������
			inline int AddString(LPCTSTR pcszStr)
				{return (int)SendMessage(LB_ADDSTRING,0,(LPARAM)pcszStr);}
			///\brief �������  ������ �� ���������
			///\param nItem - ����� ������
			///\return ����������� ���������� �����
			inline int DeleteString(int nItem)
				{return (int)SendMessage(LB_DELETESTRING,(WPARAM)nItem);}
			///\brief ���������  ������ � ����������� �������
			///\param nItem - ����� ������
			///\param pcszStr - ������
			///\return ����� ����������� ������
			inline int InsertString(int nItem,LPCTSTR pcszStr)
				{return (int)SendMessage(LB_INSERTSTRING,(WPARAM)nItem,(LPARAM)pcszStr);}
			///\brief ���������� ����������� ��������� 
			///\return ����������� ��������� 
			inline int GetCount()
				{return (int)SendMessage(LB_GETCOUNT);}
			///\brief ���������� ��������� ������� ��� ������ ���������� ���������
			///\return ���������� �������, ���� ����� ����. ���� ��� �� ����� LB_ERR(-1)
			inline int GetCurSel()
				{return (int)SendMessage(LB_GETCURSEL);}
			///\brief ������������� ��������� ������� ��� ������ ���������� ���������
			///\param nItem - ����� ������
			///\return � ������ ������ ����� LB_ERR(-1)
			inline int SetCurSel(int nItem)
				{return (int)SendMessage(LB_SETCURSEL,(WPARAM)nItem);}
			///\brief ���������� �� �������� ���� �����, ���� ���� ����� ��������� ����
			///\param nItem - ����� ������
			///\return � ������ ������ ����� LB_ERR(-1)
			inline int SetTopIndex(int nItem)
				{return (int)SendMessage(LB_SETTOPINDEX,(WPARAM)nItem);}
			///\brief ���������� ������������ ���������� ������
			///\param nItem - ����� ������
			///\param lpRect - ������������
			///\return � ������ ������ ����� LB_ERR(-1)
			inline int GetItemRect(int nItem,LPRECT lpRect)
				{return (int)SendMessage(LB_GETITEMRECT,(WPARAM)nItem,(LPARAM)lpRect);}
			///\brief ���������� ������ ������
			///\return ������ ������
			inline int GetItemHeight()
				{return (int)SendMessage(LB_GETITEMHEIGHT);}		
			///\brief ������� ��� �����
			inline void ResetContent()
				{SendMessage(LB_RESETCONTENT);}
			///\brief ���������� ������ �� ����������� �������
			///\param nItem - ����� ������
			///\param pcszStr - ������
			///\return ����� ������������� �������� � �����,� ������ ������ ����� LB_ERR(-1)
			inline int GetText(int nItem,LPCTSTR pcszStr)
				{return (int)SendMessage(LB_GETTEXT,(WPARAM)nItem,(LPARAM)pcszStr);}
			///\brief ���������� ����� ������ �� ��������� �������
			///\param nItem - ����� ������
			///\return ����� ��������,� ������ ������ ����� LB_ERR(-1)
			inline int GetTextLen(int nItem)
				{return (int)SendMessage(LB_GETTEXTLEN,(WPARAM)nItem);}
			///\brief ���������� ����� ����� �� ��������� ���������� ����������
			///\param pt - ���������� ����������
			///\return ����� �����,� ������ ������ ����� � ������� ����� 1
			inline int ItemFromPoint(POINT pt)
				{return (int)SendMessage(LB_ITEMFROMPOINT,0,MAKELPARAM(pt.x,pt.y));}
			///\brief ������������� �������� ��� ������
			///\param nItem - ����� ������
			///\param pData - ��������
			///\return TRUE � ������ ������
			inline BOOL SetItemData(int nItem,LPVOID pData)
				{return ((SendMessage(LB_SETITEMDATA,WPARAM(nItem),LPARAM(pData)))!=LB_ERR);}
		};
	}
}
#endif //__LISTBOX__H_