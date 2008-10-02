///\file ULToolBarCtrl.h
///\brief ������������ ���� ������ ������� ������������ �� ��������� ��������(12.10.2007)
#pragma once
#ifndef __UL_ULTOOLBARCTRL_H__
#define __UL_ULTOOLBARCTRL_H__
#include "ULToolBar.h"
#include "ULWndCtrl.h"
namespace ULWnds
{
	namespace ULWndCtrls
	{
		///\class CULToolBarCtrl
		///\brief ����� ������� ������������ �� ��������� ��������(12.10.2007)
		class CULToolBarCtrl :
			public CULWndCtrl
		{
		protected:
			///\brief ��������� ����������� ��� ���������������� ������� 
			///�� ��������
			enum enConsts
			{
				cNonGripperBorder	=2,
				cGripperBorder		=7,
				cBorderButtonDock	=4,
				cBorderButtonFloat	=7,
				cGripperSize		=16
			};
			///\brief ��������������� ��� ������
			ULBars::CULToolBar m_ToolBar;
		public:
			//================================================
			///\brief �����������
			//================================================
			CULToolBarCtrl(void);
			///\brief ����������
			virtual ~CULToolBarCtrl(void);
			///\brief ������� ���������� ������ �� ������
			inline ULBars::CULToolBar& GetToolBar(){return m_ToolBar;};
			///\brief ������� �������� ��������������
			///\param hParentWnd - ����� ��������(��������)
			///\param tbID - ������������� �������
			///\param nXPos,nYPos - ������� �������������� ��� �������� �
			///	��������� ���������
			///\param dxButton,dyButton - ������ ������ �������
			///\param dxBitmap,dyBitmap - ������ �������� ��� ������ �������
			///\param dwDockedState - ���������� �������� �� ������ ��������
			///\param fDocked - ��������� �������� �� ������ ��������
			///\param tbStyle - ����� �������
			///\param tbExStyle - ����������� ����� �������
			///\param dwDockingStyles - ����� ������
			BOOL CreateToolBarCtrl(HWND hParentWnd,
							short tbID,
							int nXPos,
							int nYPos,
							int dxButton,
							int dyButton,
							int dxBitmap,
							int dyBitmap,
							DWORD dwDockedState,
							BOOL fDocked=TRUE,
							DWORD tbStyle=WS_CHILD|WS_VISIBLE|TBSTYLE_TOOLTIPS|
											TBSTYLE_AUTOSIZE|CCS_NODIVIDER,
							DWORD tbExStyle=TBSTYLE_EX_DRAWDDARROWS,
							DWORD dwDockingStyles=dsDrawGripperDocked|
												dsDrawGripperFloating|
												dsUseBorders|dsBorderTop|dsBorderLeft|
												dsBorderBottom|dsBorderRight|
												dsAllowDockAll);
		protected:
			///\brief ���������� WM_SIZE
			virtual LRESULT OnSize(WPARAM nType,LPARAM point);
		};
	}
}
#endif //__UL_ULTOOLBARCTRL_H__