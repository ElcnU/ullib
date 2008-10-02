///\file ULMenu.h
///\brief ������������ ���� ������ ������ ��� ����(24.10.2007)
#pragma once
#ifndef __MENU__H_
#define __MENU__H_
#include <windows.h>
namespace ULWnds
{
	namespace ULControls
	{
		///\class CULMenu
		///\brief ����� ������ ��� ����(24.10.2007)
		class CULMenu
		{
		public:
			HMENU m_hMenu;
		public:
			///\brief �����������
			CULMenu():m_hMenu(NULL){};
			///\brief �����������
			CULMenu(HMENU hMenu):m_hMenu(hMenu){};
			///\brief ����������
			virtual ~CULMenu(){};
			///\brief ��� ����������� ������� ������ ��� ��� ��������� 
			///������ ����� ����
			inline operator HMENU() const{return m_hMenu;};
		//==================inline functions============================
			///\brief ������ ����
			///\return TRUE � ������ ������
			inline BOOL CreateMenu()
				{return ((m_hMenu=::CreateMenu())!=NULL);}
			///\brief ������ ���������� ����
			///\return TRUE � ������ ������
			inline BOOL CreatePopupMenu()
				{return ((m_hMenu=::CreatePopupMenu())!=NULL);}
			///\brief  ��������� ����� ����
			///\param uFlags - ���� ��� �������� ����(��� ������ MF_STRING)
			///\param uIDNewItem - ID ������ ����
			///\param lpNewItem - ��� MF_STRING ������
			///	��� MF_BITMAP ������ �������
			///\return TRUE � ������ ������
			inline BOOL AppendMenu(UINT uFlags,UINT_PTR uIDNewItem,LPCTSTR lpNewItem)
				{return ::AppendMenu(*this,uFlags,uIDNewItem,lpNewItem);}
			///\brief  ��������� ����� ����(��������!!!)
			///\param uFlags - ���� ��� �������� ����
			///\param uIDNewItem - ID ������ ����
			///\return TRUE � ������ ������
			inline BOOL AppendOwnerDrawMenu(UINT uFlags,UINT_PTR uIDNewItem)
				{return ::AppendMenu(*this,uFlags|MF_OWNERDRAW,uIDNewItem,(LPTSTR)this);}
			///\brief  ��������� ����� ����
			///\param uPosition - ������� ��� �������
			///\param uFlags - ���� ��� �������� ����(��� ������ MF_STRING)
			///\param uIDNewItem - ID ������ ����
			///\param lpNewItem - ��� MF_STRING ������
			///	��� MF_BITMAP ������ �������
			///\return TRUE � ������ ������
			inline BOOL InsertMenu(UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCTSTR lpNewItem)
				{return ::InsertMenu(*this,uPosition,uFlags,uIDNewItem,lpNewItem);}				
			///\brief ���������� ����������� ����
			///\param uFlags - ��� ��� ����� ������ ������������ ������������ ������� �����
			///\param pt - ������� �����
			///\param hWnd - ���� �������� ����
			///\return TRUE � ������ ������
			inline BOOL TrackPopupMenu(UINT uFlags,POINT pt,HWND hWnd)
				{return ::TrackPopupMenu(*this,uFlags,pt.x,pt.y,0,hWnd,NULL);}
			///\brief ���������� ����������� ����
			///\param uFlags - ��� ��� ����� ������ ������������ ������������ ������� �����
			///\param pt - ������� �����
			///\param hWnd - ���� �������� ����
			///\param lptpm - ��������� �� ���������, ���������� �������, ������� ����������� ����
			///\return TRUE � ������ ������		
			inline BOOL TrackPopupMenuEx(UINT uFlags,POINT pt,HWND hWnd,LPTPMPARAMS lptpm)
				{return ::TrackPopupMenuEx(*this,uFlags,pt.x,pt.y,hWnd,lptpm);}
			///\brief ���������� ����
			///\return TRUE � ������ ������
			inline BOOL DestroyMenu()
				{return ((m_hMenu)?::DestroyMenu(m_hMenu):FALSE);};
			///\brief ���������� �������, ������� ������ � ������ �������� ����
			///\return ����� ������� � ������ ������ ����� NULL
			inline HMENU GetSubMenu(int nPos)
				{return ::GetSubMenu(*this,nPos);}
			///\brief ��������� ���� �� ��������
			///\param hInstance - ����� ������, � ������� �������� ������
			///\param lpMenuName - ��� ����
			///\return TRUE � ������ ������
			inline BOOL LoadMenu(HINSTANCE hInstance,LPCTSTR lpMenuName)
				{return ((m_hMenu=::LoadMenu(hInstance,lpMenuName))!=NULL);}
			///\brief ����������� ����� ���� �� ������
			///\return ����� ����
			inline HMENU Detach()
				{HMENU hTmp=m_hMenu;m_hMenu=NULL;return hTmp;}
			///\brief ��������� �������� ����
			///\param uIDItem - ID ��� ������� ����� ������������ �� ����� flags
			///\param lpString - ��������� �� ����� � ������������ �������
			///\param cchMax - ����� ������
			///\param flags - ��������� ��������� �������� MF_BYCOMMAND ��� MF_BYPOSITION
			///\return ����������� ��������
			inline int GetMenuString(UINT uIDItem,LPTSTR lpString,int cchMax,UINT flags)
				{return ::GetMenuString(*this,uIDItem,lpString,cchMax,flags);}
			///\brief ��������� ����� ������ � ����
			///\return ����� ������
			inline int GetMenuItemCount()
				{return ::GetMenuItemCount(*this);}
			///\brief �������� ID ����� ����
			///\param nPos - ������� ����
			///\return �������������
			UINT GetMenuItemID(int nPos)
				{return ::GetMenuItemID(*this,nPos);}
		};
	}
}
#endif //__MENU__H_