///\file ULWndCtrl.h
///\brief ������������ ���� ������ ���� ���� ���������(21.07.2007)
#pragma once
#ifndef __UL_ULWNDCTRL_H__
#define __UL_ULWNDCTRL_H__
#include "ULWnd.h"
namespace ULWnds
{
	namespace ULWndCtrls
	{
		///\class CULWndCtrl
		///\brief ����� ���� ���� ���������, ������� ����� ������������ 
		///	� ����� ���������� ������� ���� ��������(21.07.2007)
		class CULWndCtrl:public CULWnd
		{
		private:
			///\brief ����� ����
			///\param twsPopupStyles,twsPopupExStyles - ��� ���������� ����
			///\param twsChildStyles,twsChildExStyles - ��� ���������� ����
			typedef enum enCtrlWndStyles
			{
				twsPopupStyles	=WS_POPUP | WS_CLIPCHILDREN |
					WS_CLIPSIBLINGS | WS_SYSMENU | WS_CAPTION /*| WS_THICKFRAME*/,
				twsPopupExStyles=WS_EX_TOOLWINDOW | WS_EX_WINDOWEDGE,
				twsChildStyles	=WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
				twsChildExStyles	=0
			};
			///\brief ���� �������������� � ������� ������
			BOOL	m_fDragging;
			///\brief ���� ������� VK_CONTROL � ������� ������
			BOOL	m_fControl;
			BOOL	m_fOldDrawDocked;
			BOOL	m_fOldControl;
			POINT	m_ptPos;
			SIZE	m_FrameSize;
			RECT	m_rcBorderDock;
			///\brief ������� ��������� ��������
			RECT	m_rcBorderFloat;
			RECT	m_rcOldRect;
			///\brief ����� ������
			UINT	m_dwDockingStyle;
		//////////////////////////
			///\brief ���� �������� ���� � ����������� �������
			BOOL	m_fMouseMoved;
			///\brief ������� ������� �������
			POINT	m_ptCursorPos;
			///\brief ��������� ������������ ��������
			RECT	m_rcStart;
			///\brief ��������� ������� �������
			POINT	m_ptOldCursorPos;
		protected:
			///\brief ���� ��������� ������/�������
			BOOL	m_fDocked;
			///\brief ���� ��������� � ����� ���� ������
			UINT	m_dwDockedState;
			///\brief ������ ����������� ��� ���������� � ���� ���� ��������
			int		m_nDockedSize;
			///\brief ������ ������ � ��������� ���������
			SIZE	m_FloatingSize;
		public:
			///\brief ���������, ������� ���������� ���� ��� "��������" ������
			enum enToParentMessage{CWM_CLOSE=WM_APP+1};
			///\brief ����� ������ 
			///\param dsBorderTop �������� ������				
			///\param dsBorderBottom �������� �����
			///\param dsBorderLeft �������� �����
			///\param dsBorderRight �������� ������
			///\param dsDrawGripperDocked ��������� � ����������� ���������
			///\param dsDrawGripperFloating ��������� � ��������� ���������
			///\param dsForceDock ������ �����������
			///\param dsForceFloat ������ �������			
			///\param dsResizeble ���������� ������		
			///\param dsNoResize ������������ ������		
			///\param dsUseBorders	������������ �������		
			///\param dsNoSetFocus	�� ����������� �����
			///\param dsNoDestroy	"�����������"
			///\param dsAllowDockLeft ���������������� �����
			///\param dsAllowDockRight	���������������� � �����
			///\param dsAllowDockTop ���������������� ������
			///\param dsAllowDockBottom ���������������� �����
			///\param dsAllowDockAll ����� ����������������
			typedef enum enDockingStyles
			{
				dsBorderTop				=0x0001,
				dsBorderBottom			=0x0002,
				dsBorderLeft			=0x0004,
				dsBorderRight			=0x0008,
				dsDrawGripperDocked		=0x0010,
				dsDrawGripperFloating	=0x0020,
				dsForceDock				=0x0040,
				dsForceFloat			=0x0080,
				dsResizeble				=0x0100,
				dsNoResize				=0x0200,
				dsUseBorders			=0x1000,
				dsNoSetFocus			=0x2000,
				dsNoDestroy				=0x4000,
				dsAllowDockLeft			=0x10000,
				dsAllowDockRight		=0x20000,
				dsAllowDockTop			=0x40000,
				dsAllowDockBottom		=0x80000,
				dsAllowDockAll			=dsAllowDockLeft|dsAllowDockRight|
										dsAllowDockTop|dsAllowDockBottom
			};
			///\brief ����������� 
			CULWndCtrl();
			///\brief ����������� �����������
			CULWndCtrl(CULWndCtrl&);
			///\brief ���������� 
			virtual ~CULWndCtrl();
			///\brief �������� �����������
			void operator=(CULWndCtrl&);
			///\brief ������ ������
			///\param szWndName - ��������� ����
			///\param x,y - ���������� ����(� ��������� ���������)
			///\param cx,cy - ������ ����(� ��������� ���������)
			///\param hParentWnd - ����� ������������� ����
			///\param dwDockedState - ���������� �������� �� ������ �������� 
			///\param fDocked - ��������� �������� �� ������ ��������
			///\param dwDockingStyles - ����� ������
			///\return ����� ���������� ����
			HWND Create(TCHAR* szWndName,
				int x,int y,int cx,int cy,
				HWND hParentWnd,
				DWORD dwDockedState,
				BOOL fDocked=TRUE,
				DWORD dwDockingStyles=dsUseBorders|
							dsDrawGripperDocked|
							dsDrawGripperFloating|
							dsBorderTop|dsBorderLeft|
							dsBorderBottom|dsBorderRight|
							dsAllowDockAll);
			///\brief ������� ��������� ����� ��������� ������ �� �����
			///	��������� ������ � �������
			void TogglePopupStyle();
			///\brief ������� ��������� �����  ��������� ������ �� �����
			///	��������� ������ � ��������
			void ToggleDockingMode();
			///\brief ������� ��� ��������� ������� ��� �������������� ����
			///\param rect - ���������� �������������� ���������
			///\param fDocked ���� ����������� ��� �������������� �� ��������� ������
			void DrawXorFrame(RECT *rect, BOOL fDocked);
			///\brief ������� ���� ������� �� 0, �� ������ �������������
			///	���� ���������� ������� ��� ����������
			///\param rcDrag ������������� ��� ���������� 
			///\param ptCursorPos ���������� �������, ����������� �� ���������� 
			///\return ���� �� 0, �� ������� �� enDockingStyles
			UINT IsDockable(RECT* rcDrag,POINT ptCursorPos);
			///\brief ������� ���������� ��� ��������� ��������� ��� ��������� ������
			void CalcFloatingRect();
			///\brief ������� �c���������� ��������� �������, �����������
			///	��� ���� ���� ���������� ������ ��� ��������������
			void DrawGripper(HDC hDC,RECT rcClient);
			///\brief �������� ������� ��� �������������������� ���� 
			///	������� �� ������������ ����
			void ResizeAllWndCtrls(void);
			///\brief ���������� �������� ������ (������/�������)
			///\return TRUE/FALSE - ������/�������
			inline BOOL IsDocked()
				{return m_fDocked;}
			///\brief ���������� ������ ����������� ������� ������ 
			///\return ������ ����������� ������� ������ 
			inline int GetDockedSize()
				{return m_nDockedSize;}
			///\brief ���������� ��������� ������ 
			///\return ��������� ������ 
			inline UINT GetDockedState()
				{return m_dwDockedState;}
		protected:
			///\brief ������� ���������� WM_NCLBUTTONDBLCLK
			virtual LRESULT OnNCLButtonDblClick(WPARAM,LPARAM);
			///\brief ������� ���������� WM_WINDOWPOSCHANGED
			virtual LRESULT OnWindowPosChanged(WPARAM,LPARAM);
			///\brief ������� ���������� WM_NCLBUTTONDOWN
			virtual LRESULT OnNCLButtonDown(WPARAM,LPARAM);
			///\brief ������� ���������� WM_MOUSEMOVE
			virtual LRESULT OnMouseMove(WPARAM,LPARAM);
			///\brief ������� ���������� WM_LBUTTONUP
			virtual LRESULT OnLButtonUp(WPARAM,LPARAM);
			///\brief ������� ���������� WM_GETMINMAXINFO
			virtual LRESULT OnGetMinMaxInfo(WPARAM,LPARAM);
			///\brief ������� ���������� WM_SETTINGCHANGE
			virtual LRESULT OnEraseBkGnd(WPARAM,LPARAM);
			///\brief ������� ���������� WM_ERASEBKGND
			virtual LRESULT OnSettingChange(WPARAM,LPARAM);
			///\brief ������� ���������� WM_NCHITTEST
			virtual LRESULT OnNCHitTest(WPARAM Type,LPARAM CurPos);
			///\brief ������� ���������� WM_CLOSE
			virtual LRESULT OnClose(WPARAM,LPARAM);
		};
	}
}
#endif //__UL_ULWNDCTRL_H__
