///\file ULToolBar.h
///\brief ������������ ���� ������ �������(12.10.2007)
#pragma once
#ifndef __UL_ULTOOLBAR_H__
#define __UL_ULTOOLBAR_H__

#include <windows.h>
#include <commctrl.h>
#pragma comment(lib,"comctl32.lib")
#include "ULOther.h"
#include "ULSubClass.h"
#include "ULControls.h"
namespace ULWnds
{
	namespace ULBars
	{
		///\class CULToolBar
		///\brief ����� �������(12.10.2007)
		class CULToolBar: public CULSubClass
		{
		private:
			///\class CTBToolTip
			///\brief  ����� ��� ���������, ���� ��������� ��������� TTN_GETDISPINFO
			class CTBToolTip:public ULControls::CULToolTip
			{			
			public:
				///\brief �����������
				CTBToolTip();
				///\brief ����������
				virtual ~CTBToolTip();
				///\brief ��������� �� ������� ����� �������
				CULToolBar* m_pULToolBar;
			protected:
				///\brief ���������� TTN_GETDISPINFO
				virtual LONG OnGetDispInfo(LPARAM);
			};
			///\brief ������ ������ ����������
			CTBToolTip m_TBToolTip;
		protected:
			///\brief C�������� ������, ������� ����� ����������� ���������� � �������
			///\param szToolTip - ���� ���������
			///\param idCommand - ID �������
			///\param hMenu - ����� ������������ ���� ��� 
			///	������(���� btnStyle==BTNS_DROPDOWN)
			struct tagInfoButtons
			{
				ULOther::CULStr szToolTip;
				UINT idCommand;	
				HMENU hMenu;
				tagInfoButtons& operator=(tagInfoButtons& InfoButtons)
				{
					szToolTip=InfoButtons.szToolTip;
					idCommand=InfoButtons.idCommand;
					hMenu=InfoButtons.hMenu;
					return *this;
				}
			};
			///\brief ������, ������� ����� ����������� ���������� � �������
			ULOther::CULArr<tagInfoButtons> m_pInfoButtons;
			///\brief ����,����������� ��� �������� ������ �� ����� ��������
			UINT m_afFlag;
			///\brief ������ ������� ��� ������
			int m_dxBitmap;
			///\brief ������ ������� ��� ������
			int m_dyBitmap;
			///\brief m_tbStyle - �����
			DWORD m_tbStyle;
		public:
			///\brief �����������
			CULToolBar(void);
			///\brief ����������� �����������
			CULToolBar(CULToolBar& toolBar);
			///\brief ����������
			virtual ~CULToolBar(void);
			///\brief �������� �����������
			void operator=(CULToolBar&);
			///\brief ����� ������ ��� ���������� ������� �� ����� ��������
			///\param afTop - �� �������� ����
			///\param afBottom - �� ������� ����
			///\param afLeft - �� ������ ����
			///\param afRight - �� ������� ����
			///\param afNon - ������������ ������������
			enum enAlignFlags
			{
				afTop=CCS_TOP,				
				afBottom=CCS_BOTTOM,		
				afLeft=CCS_LEFT,			
				afRight=CCS_RIGHT,			
				afNon=CCS_NOPARENTALIGN		
			};
			///\brief ������� �������� �������
			///\param hParentWnd����� - ������������� ����
			///\param tbID -ID �������
			///\param dxButton - ������ ������
			///\param dyButton - ������ ������
			///\param dxBitmap - ������ �������� ��� ������
			///\param dyBitmap - ������ �������� ��� ������
			///\param afFlag - ��������� ������������ ��������
			///\param tbStyle - �����
			///\param tbExStyle - ����������� �����
			HWND Create(HWND hParentWnd,		
						UINT tbID,				
						int dxButton,			
						int dyButton,			
						int dxBitmap,			
						int dyBitmap,			
						UINT afFlag=afTop,	
						DWORD tbStyle=WS_CHILD|WS_VISIBLE|TBSTYLE_TOOLTIPS|
						TBSTYLE_AUTOSIZE|CCS_NODIVIDER,
						DWORD tbExStyle=TBSTYLE_EX_DRAWDDARROWS);
			///\brief ������� ��������� ������ �� ������
			///\param idCommand - ID ��������(������)
			///\param btnState - ��������� ������
			///\param btnStyle - ����� ������
			///\param szTTip - ��������� ��� ������
			///\param pszStr - ������� ��� ������(� TBSTYLE_LIST)
			///\param nBitmap - ����� �������� ��� ������ ������� � ���� ������� � ������� nID
			///\param nID - ID ������� ��� ��������
			///\param hInst - HINSTANCE ������ �������
			///\param hMenu - ID ������������ ���� ��� ������, ���� (btnStyle&BTNS_DROPDOWN)==BTNS_DROPDOWN)
			int AddButton(int idCommand,					
						BYTE btnState,						
						BYTE btnStyle,						
						TCHAR* szTTip,						
						TCHAR* pszStr,					
						int nBitmap,						
						UINT_PTR nID=IDB_STD_SMALL_COLOR,	
						HINSTANCE hInst=HINST_COMMCTRL,		
						HMENU hMenu=NULL);						
			///\brief ������� ��������� ������ �� ������
			///\param idCommand - ID ��������(������)
			///\param btnState - ��������� ������
			///\param btnStyle - ����� ������
			///\param szTTip - ��������� ��� ������
			///\param pszStr - ������� ��� ������(� TBSTYLE_LIST)
			///\param nBitmap - ����� �������� ��� ������ ������� � ���� ������� � ������� nID
			///\param hBitmap - ����� ��������
			///\param hMenu - ID ������������ ���� ��� ������, ���� (btnStyle&BTNS_DROPDOWN)==BTNS_DROPDOWN)
			int AddButton(int idCommand,	
						BYTE btnState,		
						BYTE btnStyle,		
						TCHAR* szTTip,		
						TCHAR* pszStr,
						int nBitmap,		
						HBITMAP hBitmap,	
						HMENU hMenu=NULL);	  	
			///\brief ������� ��������� ������ � ������
			///\param nInto - ������� �������
			///\param idCommand - ID ��������(������)
			///\param btnState - ��������� ������
			///\param btnStyle - ����� ������
			///\param szTTip - ��������� ��� ������
			///\param pszStr - ������� ��� ������(� TBSTYLE_LIST)
			///\param nBitmap - ����� �������� ��� ������ ������� � ���� ������� � ������� nID
			///\param nID - ID ������� ��� ��������
			///\param hInst - HINSTANCE ������ �������
			///\param hMenu - ID ������������ ���� ��� ������, ���� (btnStyle&BTNS_DROPDOWN)==BTNS_DROPDOWN)
			int InsertButton(int nInto,		
						int idCommand,		
						BYTE btnState,		
						BYTE btnStyle,		
						TCHAR* szTTip,		
						TCHAR* pszStr,
						int nBitmap,  		
						UINT_PTR nID=IDB_STD_SMALL_COLOR,
						HINSTANCE hInst=HINST_COMMCTRL,	 
						HMENU hMenu=NULL);					 
			///\brief ������� ��������� ������ � ������
			///\param nInto - ������� �������
			///\param idCommand - ID ��������(������)
			///\param btnState - ��������� ������
			///\param btnStyle - ����� ������
			///\param szTTip - ��������� ��� ������
			///\param pszStr - ������� ��� ������(� TBSTYLE_LIST)
			///\param nBitmap - ����� �������� ��� ������ ������� � ���� ������� � ������� nID
			///\param hBitmap - ����� ��������
			///\param hMenu - ID ������������ ���� ��� ������, ���� (btnStyle&BTNS_DROPDOWN)==BTNS_DROPDOWN)
			int InsertButton(int nInto,
						int idCommand,
						BYTE btnState,
						BYTE btnStyle,
						TCHAR* szTTip,
						TCHAR* pszStr,
						int nBitmap,
						HBITMAP hBitmap,
						HMENU hMenu=NULL);
			///\brief ������� ������� ��������� ������
			int DeleteButton(int nButton/*!<����� ������*/);
			/*!\brief �������� ������ ������� �� ������ ��� ������ ��������
			� ����������� �� ��������������
			� ��������� ������ ������� ������.
			�������� � ���������� WM_SIZE ���� �������� */
			void AutoSize();
			///\brief ������� ���������� ����������� ������ �� �������
			inline unsigned int GetButtonCount()
				{return (unsigned int)m_pInfoButtons.GetSize();}
			///\brief ��������� ������� ������
			///\param nItem - ����� �����
			///\param lpRect - ��������� �� ��������� � ��������
			///\return TRUE  � ������ ������
      BOOL GetItemRect(int nItem,RECT* lpRect)
			  {return (BOOL)SendMessage(TB_GETITEMRECT,(WPARAM)nItem,(LPARAM)lpRect);}
			///\brief �������� ���������� � ������
			///\param nButton - ����� ������
			///\param lpButton - ��������� �� ��������� � ����������� � ������
			///\return TRUE  � ������ ������
			BOOL GetButton(int nButton,LPTBBUTTON lpButton)
				{return (BOOL)SendMessage(TB_GETBUTTON,(WPARAM)nButton,(LPARAM)lpButton);}
			///\brief ����������/������������ ������
			///\param idButton - ��������� ������������� ������
			///\param fEnable - ���� 
			///\return TRUE  � ������ ������
			BOOL EnableButton(int idButton,BOOL fEnable);
			///\brief ��������/�������� ������
			///\param idButton - ��������� ������������� ������
			///\param fCheck - ���� 
			///\return TRUE  � ������ ������
			BOOL CheckButton(int idButton,BOOL fCheck);
			///\brief ������������� ����������� �����
			///\param dwExStyle - ��� �����
			///\return ���������� �����
			DWORD SetExtendedStyle(DWORD dwExStyle);
			///\brief ���������� ����������� �����
			///\return �����
			DWORD GetExtendedStyle();
			///\brief ���������� ������ � ������ ������ � ��������
			///\return ��������� � ��������
			SIZE GetButtonSize();
			///\brief ���������� ������ � ������ ������� � ��������
			///\return ��������� � ��������
			SIZE GetBitmapSize();
			///\brief ���������� imagelist �������
			///\return imagelist. NULL � ������ ������
			HIMAGELIST GetImageList();
			///\brief �������� imagelist �������
			///\param iImageID - ������ imagelist
			///\param himlNew - ����� imagelist
			///\return ���������� imagelist
			HIMAGELIST SetImageList(int iImageID,HIMAGELIST himlNew);
		protected:
			///\brief ������� ���������� WM_WINDOWPOSCHANGING
			virtual LRESULT OnWindowPosChanging(WPARAM,LPARAM);
			///\brief ���������� TBN_DROPDOWN
      ///\bug ���������� ��� ���� ���� ����� ���� ��������������
			virtual LRESULT OnDropDown(LPARAM);			
		};
	}
}
#endif //__UL_ULTOOLBAR_H__
