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
				CTBToolTip();
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
			///\param idMenu - ID ������������ ���� ��� 
			///	������(���� btnStyle==BTNS_DROPDOWN)
			struct tagInfoButtons
			{
				TCHAR* szToolTip;
				UINT idCommand;	
				UINT idMenu;	
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
			///\brief ����������
			virtual ~CULToolBar(void);
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
			///\param nBitmap - ����� �������� ��� ������ ������� � ���� ������� � ������� nID
			///\param nID - ID ������� ��� ��������
			///\param hInst - HINSTANCE ������ �������
			///\param iString - ������� ��� ������
			///\param idMenu - ID ������������ ���� ��� ������, ���� (btnStyle&BTNS_DROPDOWN)==BTNS_DROPDOWN)
			int AddButton(int idCommand,					
						BYTE btnState,						
						BYTE btnStyle,						
						TCHAR* szTTip,						
						int nBitmap,						
						UINT_PTR nID=IDB_STD_SMALL_COLOR,	
						HINSTANCE hInst=HINST_COMMCTRL,		
						INT_PTR iString=0,					
						int idMenu=0);						
			///\brief ������� ��������� ������ �� ������
			///\param idCommand - ID ��������(������)
			///\param btnState - ��������� ������
			///\param btnStyle - ����� ������
			///\param szTTip - ��������� ��� ������
			///\param nBitmap - ����� �������� ��� ������ ������� � ���� ������� � ������� nID
			///\param hBitmap - ����� ��������
			///\param iString - ������� ��� ������
			///\param idMenu - ID ������������ ���� ��� ������, ���� (btnStyle&BTNS_DROPDOWN)==BTNS_DROPDOWN)
			int AddButton(int idCommand,	
						BYTE btnState,		
						BYTE btnStyle,		
						TCHAR* szTTip,		
						int nBitmap,		
						HBITMAP hBitmap,	
						INT_PTR iString=0,	
						int idMenu=0);	  	
			///\brief ������� ��������� ������ � ������
			///\param nInto - ������� �������
			///\param idCommand - ID ��������(������)
			///\param btnState - ��������� ������
			///\param btnStyle - ����� ������
			///\param szTTip - ��������� ��� ������
			///\param nBitmap - ����� �������� ��� ������ ������� � ���� ������� � ������� nID
			///\param nID - ID ������� ��� ��������
			///\param hInst - HINSTANCE ������ �������
			///\param iString - ������� ��� ������
			///\param idMenu - ID ������������ ���� ��� ������, ���� (btnStyle&BTNS_DROPDOWN)==BTNS_DROPDOWN)
			int InsertButton(int nInto,		
						int idCommand,		
						BYTE btnState,		
						BYTE btnStyle,		
						TCHAR* szTTip,		
						int nBitmap,  		
						UINT_PTR nID=IDB_STD_SMALL_COLOR,
						HINSTANCE hInst=HINST_COMMCTRL,	 
						INT_PTR iString=0,				 
						int idMenu=0);					 
			///\brief ������� ��������� ������ � ������
			///\param nInto - ������� �������
			///\param idCommand - ID ��������(������)
			///\param btnState - ��������� ������
			///\param btnStyle - ����� ������
			///\param szTTip - ��������� ��� ������
			///\param nBitmap - ����� �������� ��� ������ ������� � ���� ������� � ������� nID
			///\param hBitmap - ����� ��������
			///\param iString - ������� ��� ������
			///\param idMenu - ID ������������ ���� ��� ������, ���� (btnStyle&BTNS_DROPDOWN)==BTNS_DROPDOWN)
			int InsertButton(int nInto,
						int idCommand,
						BYTE btnState,
						BYTE btnStyle,
						TCHAR* szTTip,
						int nBitmap,
						HBITMAP hBitmap,
						INT_PTR iString=0,
						int idMenu=0);
			///\brief ������� ������� ��������� ������
			int DeleteButton(int nButton/*!<����� ������*/);
			/*!\brief �������� ������ ������� �� ������ ��� ������ ��������
			� ����������� �� ��������������
			� ��������� ������ ������� ������.
			�������� � ���������� WM_SIZE ���� �������� */
			void AutoSize();
			///\brief ������� ���������� ����������� ������ �� �������
			inline unsigned int GetButtonCount()
			{
				return (unsigned int)m_pInfoButtons.GetSize();
			};
      BOOL GetItemRect(int nItem,RECT* lpRect)
      {return (BOOL)SendMessage(TB_GETITEMRECT,(WPARAM)nItem,(LPARAM)lpRect);}
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
