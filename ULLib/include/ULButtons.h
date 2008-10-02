///\file ULButtons.h
///\brief ������������ ���� ������������ ���� ������� ������(15.10.2007)
#pragma once
#ifndef __BUTTONS__H_
#define __BUTTONS__H_
#include "ULSubClass.h"
#include "ULGDI.h"
#pragma comment(lib,"Msimg32.lib")
namespace ULWnds
{
	namespace ULControls
	{
		///\namespace ULControls::ULButtons
		///\brief ������������ ���� ������� ������(15.10.2007)
		namespace ULButtons
		{
			///\class CULButton
			///\brief ����� ������(08.09.2007)
			class CULButton:public CULSubClass
			{
			public:
				///\brief ��������� ������
				enum enCheckState
				{
					//��� GetCheck � GetState
					csChecked		=BST_CHECKED,
					csIndeterminate	=BST_INDETERMINATE,
					csUnchecked		=BST_UNCHECKED,
					//��� GetState
					csFocus			=BST_FOCUS,
					csPushed		=BST_PUSHED,
					csXBZ			=0x0003
				};
				enum enImageType
				{
					itBitmap	=IMAGE_BITMAP,
					itIcon		=IMAGE_ICON
				};
			public:
				CULButton();
				virtual ~CULButton();
				///\brief ������� ��� �������� ������
				///\param szCaption - ������� �� ������
				///\param x,y - ���������� ������
				///\param cx,cy - ������ ������
				///\param hParentWnd - ����� ������������� ����
				///\param uID - ID ������
				///\param dwStyle- �����
				///\return TRUE � ������ ������
				BOOL Create(HWND hParentWnd,LPCTSTR szCaption,int x,int y,int cx,int cy,
					UINT uID,DWORD dwStyle=WS_CHILD|WS_CLIPCHILDREN|WS_VISIBLE|
					BS_PUSHBUTTON|WS_TABSTOP);
			//==================inline function============================
				///\brief ������� ������
				inline void Click()
					{SendMessage(BM_CLICK);}
				///\brief ���������� ��������� ������
				///\return ��������� ���� enCheckState
				inline enCheckState GetCheck()
					{return (enCheckState)SendMessage(BM_GETCHECK);}
				///\brief ������������� ��������� ������
				///\param cs - ��������� ���� enCheckState
				inline void SetCheck(enCheckState cs)
					{SendMessage(BM_SETCHECK,(WPARAM)cs);}
				///\brief ���������� �������� ������
				///\return ��������� ���� enCheckState
				inline enCheckState GetState()
					{return (enCheckState)SendMessage(BM_GETSTATE);}
				///\brief ������������� ��������� ��������� ������
				///\param fHighLite - ��������� ���������
				inline void SetState(BOOL fHighLite)
					{SendMessage(BM_SETSTATE,(WPARAM)fHighLite);}
				///\brief ���������� �������� � ������
				///\param it - ��� �������� enImageType
				///\return ����� �� ��������, ���� ���, �� NULL
				inline HANDLE GetImage(enImageType it)
					{return (HANDLE)SendMessage(BM_GETIMAGE,(WPARAM)it);}
				///\brief ������������� �������� �� ������
				///\param it - ��� �������� enImageType
				///\param hImage - ����� ��������
				///\return ����� �� ���������� ��������, ���� ���, �� NULL
				inline HANDLE SetImage(enImageType it,HANDLE hImage)
					{return (HANDLE)SendMessage(BM_GETIMAGE,(WPARAM)it,(LPARAM)hImage);}
				///\brief ������������� ����� ������
				///\param dwStyle - �����
				///\param fRedraw - ���� �����������
				inline void SetStyle(DWORD dwStyle,BOOL fRedraw)
					{SendMessage(BM_SETSTYLE,(WPARAM)dwStyle,(LPARAM)fRedraw);}
			};
			///\class CULCustomButton
			///\brief ����� �������� ��� CULStyleButton � CULBitmapButton
			///(�� ������������ ��� �������� � �����������)(15.10.2007)
			class CULCustomButton:public CULButton
			{
			protected:
				///\brief ���������, ���������� ��������� ��� ������� �����������
				///\param Up - ��� �������� ��������� ������
				///\param Down - ��� ������� ������
				///\param param Focused - ��� �������������� ������
				///\param Disable - ��� ����������� ������
				struct tagMemDC
				{
					ULGDI::ULDC::CULDC Up;
					ULGDI::ULDC::CULDC Down;
					ULGDI::ULDC::CULDC Focused;
					ULGDI::ULDC::CULDC HiLite;
					ULGDI::ULDC::CULDC Disable;
				}m_MemDC;
				///\brief ������������ ��� ��������� ������
				///\param ctUp - ��� �������� ��������� ������
				///\param ctDown - ��� ������� ������
				///\param ctFocused - ��� �������������� ������
				///\param ctDisable - ��� ����������� ������
				///\param ctHiLite - ��� ������������ ������ ��� ��������� ����
				enum enCurrentState
				{
					ctUp			=ODS_DEFAULT,
					ctDown			=ODS_SELECTED,
					ctFocused		=ODS_FOCUS,
					ctDisable		=ODS_DISABLED,
					ctHiLite		=ODS_HOTLIGHT
				};
				///\brief ���������� �������� � ���� ������� ��������� ������
				WORD m_wCurState;
			public:
				///\brief �����������
				CULCustomButton();
				///\brief ����������
				virtual ~CULCustomButton();
			protected:
				///\brief ������� ��� ������������� ������
				virtual void Init()=0;
				///\brief ���������� WM_DRAWITEM(��� ��������� ������)
				virtual LRESULT OnDrawItem(WPARAM wParam,LPARAM);
				///\brief ���������� WM_MOUSEMOVE(��������� ��������� �� ����������)
				virtual LRESULT OnMouseMove(WPARAM Type,LPARAM CurPos);
				///\brief ���������� WM_MOUSELEAVE(��������� ��������� �� ������������)
				virtual LRESULT OnMouseLeave(WPARAM,LPARAM);
				///\brief ���������� WM_SETTEXT(��� ���������� ������)
				virtual LRESULT OnSetText(WPARAM,LPARAM);		
			};
			///\class CULStyleButton
			///\brief ����� �������� ������(15.10.2007)
			///(�� ������������ ��� �������� � �����������)
			class CULStyleButton:public CULCustomButton
			{
			public:
				///\brief ��������� ������ ������
				///\param bcDefault - ���� ����� � ���������� ������
				///\param bcHiLiteText - ���� ������ � ��������������, ����������� � ������� ������
				///\param bcDefaultText - ���� ������ � ���������� ������
				///\param bcFocused - ���� ������ � ����� �������������� ������
				///\param bcDisable - ���� ����������� ������ 
				///\param bcGradientColors - ������ ���������
				///\param bcGradientDest - ����������� ���������
				struct tagButtonColors
				{
					COLORREF bcDefault;
					COLORREF bcFocused;
					COLORREF bcHiLiteText;
					COLORREF bcDefaultText;
					COLORREF bcDisable;
					///\brief ��������� ������ ��� ��������� ������
					///\param gcUpFirst,gcUpSecond - ���������,�������� ���� ������	� ������� ���������
					///\param gcDownFirst,gcDownSecond - ���������,�������� ���� ������� ������
					struct tagGradientColors
					{
						COLORREF gcUpFirst;
						COLORREF gcUpSecond;
						COLORREF gcDownFirst;
						COLORREF gcDownSecond;
					}bcGradientColors;
					///\brief ������������ ����������� ���������
					///\param gdUpDown - ������ ����
					///\param gdLeftRight - ����� �������
					enum enGradients
					{
						gdUpDown		=GRADIENT_FILL_RECT_V,
						gdLeftRight		=GRADIENT_FILL_RECT_H
					};
					enGradients bcGradientDest;
				};
			protected:
				///\brief ����� ������
				tagButtonColors m_ButtonColors;
				///\brief ����� ������� �� ������
				ULGDI::ULGObjs::CULFont m_Font;
				///\brief ������ ���������� ����� ������
				int m_nRadius;
			public:
				///\brief �����������
				CULStyleButton();
				///\brief ����������
				virtual ~CULStyleButton();
				///\brief ������� ��� �������� ������
				///\param hParentWnd - ����� ������������� ����
				///\param szCaption - ������� �� ������
				///\param uID - ID ������
				///\param x,y - ���������� ������
				///\param cx,cy - ������ ������
				///\param hFont - ����� ������� �� ������
				///\return TRUE � ������ ������
				BOOL CreateStyleButton(HWND hParentWnd,TCHAR* szCaption,UINT uID,int x,int y,
					int cx,int cy,HFONT hFont=NULL);
				///\brief ������� ��� �������� ������ �� ��� ���������
				///\param hWnd - ��������� ������
				///\param hFont - ����� ������� �� ������
				///\return TRUE � ������ ������
				virtual BOOL Attach(HWND hWnd,HFONT hFont=NULL);
				///\brief ������� ��������� ������ �������� ������ 
				void SetButtonColors(tagButtonColors ButtonColors);
				///\brief ������� ��� ��������� ������ �������� ������ 
				void GetButtonColors(tagButtonColors* ButtonColors);
				///\brief ������� ���������� ������ ������ ���� �������� ������ 
				///\return ������ ������ ���� �������� ������ 
				int GetRadius();
				///\brief ������� ��� ��������� ������� ������ ���� �������� ������ 
				void SetRadius(int nRadius);
			protected:
				///\brief ������� ���������� ������������� �������� ������ 
				virtual void Init();
			};
			///\class CULBitmapButton
			///\brief ����� bitmap ������(15.10.2007)
			///(�� ������������ ��� �������� � �����������)
			class CULBitmapButton:public CULCustomButton
			{
			protected:
				///\brief ������� ��� ������������� ���������� � �������
				virtual void Init();
			protected:
				///\brief ��������� ��� �������� ������� �������� ������
				struct tagButtonBitmaps
				{
					HBITMAP bbUp;
					HBITMAP bbDown;
					HBITMAP bbFocused;
					HBITMAP bbHiLite;
					HBITMAP bbDisable;
					HBITMAP bbMask;
				}m_ButtonBitmaps;
			public:
				///\brief �����������
				CULBitmapButton();
				///\brief ����������
				virtual ~CULBitmapButton();
				///\brief ������� ��� �������� ������
				///\param hParentWnd - ����� ������������� ����
				///\param uID - ID ������
				///\param x,y - ���������� ������
				///\param wUpID - ID �������� ������ � ������� ���������
				///\param wDownID - ID �������� ������� ������ 
				///\param wFocusedID - ID �������� �������������� ������ 
				///\param wHiLiteID - ID �������� ����������� ������ 
				///\param wDisableID - ID �������� ����������� ������ 
				///\param wMaskID - ID �������� ����� ��� ������� ������ 
				///\return TRUE � ������ ������
				BOOL CreateBitmapButton(HWND hParentWnd,int x,int y,UINT uID,
					WORD wUpID,WORD wDownID,WORD wFocusedID,WORD wHiLiteID,WORD wDisableID,WORD wMaskID);
				///\brief ������� ��� �������� ������
				///\param hParentWnd - ����� ������������� ����
				///\param uID - ID ������
				///\param x,y - ���������� ������
				///\param hUp - ����� �������� ������ � ������� ���������
				///\param hDown - ����� �������� ������� ������ 
				///\param hFocused - ����� �������� �������������� ������ 
				///\param hHiLite - ����� �������� ����������� ������ 
				///\param hDisable - ����� �������� ����������� ������ 
				///\param hMask - ����� �������� ����� ��� ������� ������ 
				///\return TRUE � ������ ������
				BOOL CreateBitmapButton(HWND hParentWnd,int x,int y,UINT uID,
					HBITMAP hUp,HBITMAP hDown,HBITMAP hFocused,HBITMAP hHiLite,HBITMAP hDisable,HBITMAP hMask);
				///\brief ������� ��� �������� bitmap ������ �� ������ ��� ���������
				///\param hWnd - ����� ������
				///\param wUpID - ID �������� ������ � ������� ���������
				///\param wDownID - ID �������� ������� ������ 
				///\param wFocusedID - ID �������� �������������� ������ 
				///\param wHiLiteID - ID �������� ����������� ������ 
				///\param wDisableID - ID �������� ����������� ������ 
				///\param wMaskID - ID �������� ����� ��� ������� ������ 
				///\return TRUE � ������ ������
				virtual BOOL Attach(HWND hWnd,
					WORD wUpID,WORD wDownID,WORD wFocusedID,WORD wHiLiteID,WORD wDisableID,WORD wMaskID);
				///\brief ������� ��� �������� bitmap ������ �� ������ ��� ���������
				///\param hWnd - ����� ������
				///\param hUp - ����� �������� ������ � ������� ���������
				///\param hDown - ����� �������� ������� ������ 
				///\param hFocused - ����� �������� �������������� ������ 
				///\param hHiLite - ����� �������� ����������� ������ 
				///\param hDisable - ����� �������� ����������� ������ 
				///\param hMask - ����� �������� ����� ��� ������� ������ 
				///\return TRUE � ������ ������
				virtual BOOL Attach(HWND hWnd,
					HBITMAP hUp,HBITMAP hDown,HBITMAP hFocused,HBITMAP hHiLite,HBITMAP hDisable,HBITMAP hMask);
			protected:
				///\brief ����������, ���� �������� �� ������� Init()
				virtual LRESULT OnSetText(WPARAM,LPARAM);		
			};
			///\class CULHyperLink
			///\brief ����� ����������(17.07.2007)
			class CULHyperLink:public CULSubClass
			{
			public:
				///\brief ���� ��������� ������
				///\param tDefault �� ���������
				///\param tHiLite ��� ��������� ������
				///\param tVisited ����������
				///\param tDown ��� ������� ������
				enum enType
				{
					tDefault	=0,
					tHiLite		=1,
					tVisited	=2,
					tDown		=3
				};
				///\brief ����������� �����
				static const int constTypeNum=4;
				///\brief ����� ������
				///\param sNone - �������
				///\param sItalic - ���������
				///\param sUnderLine - ������������
				///\param sBold - ������
				enum enStyles
				{
					sNone		=0,
					sItalic		=0x01000000,
					sUnderLine	=0x02000000,
					sBold		=0x04000000
				};
				///\brief ������� �����
				ULGDI::ULGObjs::CULFont m_Font;
			protected:
				///\brief ���� ���������� �� ������� ������
				bool m_fClicking;
				///\brief ���� ���������� �� ��������� ������
				bool m_fVisited;
				///\brief ����� �������� ����
				BYTE m_nCurType;
				///\brief ������ �����
				DWORD m_pdwTypes[constTypeNum];
				///\brief ������ ������
				TCHAR* m_szURL;
			protected:
				///\brief ������� ��������� ������������ ������
				///\return TRUE � ������ ������
				BOOL Init();
				///\brief ������� �������� ������ ������� ��� ������ �������
				///\param hDC ����� ���������
				void AutoSize(HDC hDC);
			public:
				///\brief �����������
				CULHyperLink();
				///\brief ����������
				virtual ~CULHyperLink();
				///\brief ������� ��� �������� �����������.
				///	���� szURL ����� NULL, �� ��� ������� �� ������ 
				///	����� ���������� �������� WM_COMMAND � ���������
				///	BM_CLICKED,ID � HWND ��������.
				///\param hParentWnd - ����� ������������� ����
				///\param x,y - ���������� ������
				///\param szName - ������������ ���
				///\param szURL - URL ������
				///\param uID - ID ������
				///\return TRUE � ������ ������
				BOOL CreateHyperLink(HWND hParentWnd,int x,int y,TCHAR* szName,TCHAR* szURL,UINT uID);
				///\brief ������� ��� �������� ����������� �� ������ ��� ���������� �������
				///	���� szURL ����� NULL, �� ��� ������� �� ������ 
				///	����� ���������� �������� WM_COMMAND � ���������
				///	BM_CLICKED,ID � HWND ��������.
				///\param hWnd - ����� �������
				///\param szURL - URL ������
				///\return TRUE � ������ ������
				BOOL Attach(HWND hWnd,TCHAR* szURL);
				///\brief ������� ��� ����������� ����� ������ � ������
				BOOL SetStyles(enType Type,enStyles Styles,COLORREF Color);
				///\brief ������� ��� ��������� ������ ������
				void SetFont(HFONT hFont);
			protected:
				///\brief ���������� WM_DRAWITEM
				virtual LRESULT OnDrawItem(WPARAM,LPARAM);
				///\brief ���������� WM_LBUTTONDOWN
				virtual LRESULT OnLButtonDown(WPARAM,LPARAM);
				///\brief ���������� WM_LBUTTONUP
				virtual LRESULT OnLButtonUp(WPARAM,LPARAM);
				///\brief ���������� WM_MOUSEMOVE
				virtual LRESULT OnMouseMove(WPARAM,LPARAM);
				///\brief ���������� WM_MOUSELEAVE
				virtual LRESULT OnMouseLeave(WPARAM,LPARAM);
			};
		}
	}
}
#endif //__BUTTONS__H_
