///\file ULDC.h
///\brief ������������ ���� ������� ����������(08.10.2007)
#include <windows.h>
#pragma once
#ifndef __ULDC__H_
#define __ULDC__H_
namespace ULGDI
{
	///\namespace ULGDI::ULDC
	///\brief ������������ ��� ������� ����������(08.10.2007)
	namespace ULDC
	{
		///\class CULDC
		///\brief ����� ���������
		class CULDC
		{
		public:
			///\brief ��������
			HDC m_hDC;
			///\brief ���� ��������
			HWND m_hWndOwner;
			///\brief ����� ����
			///\param bmOPAQUE - ������� ����� ������������� ������� BkColor(SetBkColor)
			///\param bmTRANSPARENT - ���������� ���
			enum enBkMode
			{
				bmOPAQUE		=OPAQUE,
				bmTRANSPARENT	=TRANSPARENT	
			};
		public:
			///\brief �����������
			CULDC():m_hDC(NULL),m_hWndOwner(NULL){};
			///\brief ����������� �����������
			CULDC(HDC& hDC):m_hDC(hDC),m_hWndOwner(NULL){}
			///\brief ����������� �����������
			CULDC(CULDC& DC):m_hDC(DC),m_hWndOwner(NULL){}
			///\brief ����������
			virtual ~CULDC(){DeleteDC();}
			///\brief ������������������ ������� ��������� � ������
			///\param pszFile - ���� � �����
			///\param rcSize - ������� ���������� ����� � ����
			///\param dwComp - ��� ���������� (BI_RGB,BI_RLE8,BI_RLE4,BI_BITFIELDS,BI_JPEG,BI_PNG)
			///\param wBitCount - �������� ������������ �����������
			///\return TRUE � ������ ������, ����� FALSE
			BOOL ULGDI::ULDC::CULDC::CreateBMPFile(LPCTSTR pszFile, RECT rcSize, DWORD dwComp, WORD wBitCount);
		//==================inline functions============================
			///\brief ������� �������� ���������(������� �� ����������� :D)
			inline BOOL CreateDC(LPCTSTR lpszDriver, LPCTSTR lpszDevice,
				LPCTSTR lpszOutput,CONST DEVMODE* lpInitData)
				{return ((m_hDC=::CreateDC(lpszDriver,lpszDevice,lpszOutput,lpInitData))!=NULL);}
			///\brief ������� ����������� �������� �� ������ ���������
			///\param hDC - ������� ��������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL CreateCompatibleDC(HDC hDC)
				{return ((m_hDC=::CreateCompatibleDC(hDC))!=NULL);}
			///\brief ��� ����������� ������� ������ ��� ��� ��������� 
			///	������ ����� DC
			inline operator HDC() const{return m_hDC;};
			inline BOOL BitBlt(int nXDest,int nYDest,int nWidth,int nHeight,
				HDC hdcSrc,int nXSrc,int nYSrc,DWORD dwRop)
			{return ::BitBlt(*this,nXDest,nYDest,nWidth,nHeight,
				hdcSrc,nXSrc,nYSrc,dwRop);};
			///\brief ������������� ���� ������
			///\param crColor - ����
			///\return ���������� ����
			inline COLORREF SetTextColor(COLORREF crColor)
				{return ::SetTextColor(*this,crColor);}
			///\brief ���������� ���� ������
			///\return ����
			inline COLORREF GetTextColor()
				{return ::GetTextColor(*this);}			 
			///\brief ������������� ���� ���� ������
			///\param crColor - ����
			///\return ���������� ����
			inline COLORREF SetBkColor(COLORREF crColor)
				{return ::SetBkColor(*this,crColor);};
			///\brief ������������� ����� ��������� ������
			///\param bm - �����
			///\return ���������� ����
			inline int SetBkMode(enBkMode bm)
				{return ::SetBkMode(*this,bm);};
			///\brief ������������ �����
			///\param lpString - �����
			///\param nCount - ����� ������
			///\param lpRect - ������������� � ������� ������������
			///\param uFormat - ������ ���������(�� ����)
			///\return � ������ ������ ����� ������ ������ � ������������������, ����� 0
			inline int DrawText(LPCTSTR lpString,int nCount,LPRECT lpRect,UINT uFormat)
				{return ::DrawText(*this,lpString,nCount,lpRect,uFormat);};
			///\brief ��� ��������� ������� ������ � ��������� ��� �������� ������
			///\param lpString - ������
			///\param cbString - ����� ������
			///\param lpSize - ������ ������
			///\return TRUE � ������ ������
			inline BOOL GetTextExtentPoint(LPCTSTR lpString,int cbString,LPSIZE lpSize)
				{return ::GetTextExtentPoint(*this,lpString,cbString,lpSize);};
			///\brief �������� ���������� ��������� � ��������
			///\param hgdiobj - ���������� ���������
			///\return ���������� ���������� ���������
			inline HGDIOBJ SelectObject(HGDIOBJ hgdiobj)
				{return ::SelectObject(*this,hgdiobj);};
			///\brief ������� ��������
			///\return TRUE � ������ ������
			inline BOOL DeleteDC()
				{if(m_hDC!=NULL)return ::DeleteDC(*this);else return FALSE;}
			///\brief ����������� �������� �� ������
			///\return ��������
			inline HDC Detach()
				{HDC hRetDC=m_hDC;m_hDC=NULL;return hRetDC;}
			///\brief ������ �������������
			///\param nLeftRect,nTopRect,nRightRect,nBottomRect - ����������
			///\return TRUE � ������ ������
			inline BOOL Rectangle(int nLeftRect,int nTopRect,int nRightRect,int nBottomRect)
				{return ::Rectangle(*this,nLeftRect,nTopRect,nRightRect,nBottomRect);}
			///\brief ������ �����
			///\param nXStart,nYStart - ����������
			///\param nXStart,nYStart - ����������
			///\param lpString - ������
			///\param cbString - ����� ������
			///\return TRUE � ������ ������
			inline BOOL TextOut(int nXStart,int nYStart,LPCTSTR lpString,int cbString)
				{return ::TextOut(*this,nXStart,nYStart,lpString,cbString);}
			///\brief ������ ������ �� ��������� �������
			///\param hrgn - ������
			///\param hbr - �����, ������� ����� ��������� ���������
			///\param nWidth,nHeight - ������� �������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL FrameRgn(HRGN hrgn,HBRUSH hbr,int nWidth,int nHeight)
				{return ::FrameRgn(*this,hrgn,hbr,nWidth,nHeight);};
			///\brief ��������� ����������� �������� �������� �������
			///\param pVertex - ������ TRIVERTEX ��������
			///\param dwNumVertex - ����� TRIVERTEX �������� � ������� pVertex
			///\param pMesh - ������ GRADIENT_TRIANGLE �������� ��� ������ ������������
			///	��� ������ GRADIENT_RECT �������� ��� ������ ��������������
			///\param dwNumMesh - ����� ��������� � pMesh
			///\param dwMode - �����
			///	GRADIENT_FILL_RECT_H �������������� ��������
			///	GRADIENT_FILL_RECT_V ������������ ��������
			///	GRADIENT_FILL_TRIANGLE �������� �� �����������(�� ��������)
			inline BOOL GradientFill(PTRIVERTEX pVertex,ULONG dwNumVertex,PVOID pMesh,ULONG dwNumMesh,ULONG dwMode)
				{return ::GradientFill(*this,pVertex,dwNumVertex,pMesh,dwNumMesh,dwMode);}; 
			///\brief ���������� ���������� � ���������
			///\param index - ID ����
			///\return ��������
			virtual int GetDeviceCaps(int index)
				{return ::GetDeviceCaps(*this,index);}
			///\brief ���������� ��������� ����������� ������
			///\param type - ��� �������
			///\return ����������� ������ � ������ �����, ����� NULL
			inline HGDIOBJ GetCurrentObject(UINT type)
				{return ::GetCurrentObject(*this,type);}
			///\brief ������ ����� ������� � ������� �����
			///\param nXEnd, nYEnd - ���������� �������� �����
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL LineTo(int nXEnd,int nYEnd)
				{return ::LineTo(*this,nXEnd,nYEnd);}
			///\brief ������������� �������� ������� �����
			///\param X, Y - ���������� ����� ��������������� �����
			///\param lpPoint - ���������� ������ �����
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL MoveTo(int X,int Y,LPPOINT lpPoint=NULL)
				{return ::MoveToEx(*this,X,Y,lpPoint);}
			///\brief �������� ���� � ������� �����, ���������� �� ������������ �������
			///\param hbmp - ����� �� ������
			///\param uStartScan - ����� ������ ����� ��� �����������
			///\param cScanLines - ����� ���������� �����
			///\param lpvBits - �������� ����� ��� ������������� ������
			///\param lpbi - ���������� � �������
			///\param uUsage -�������� ������(DIB_PAL_COLORS,DIB_RGB_COLORS)
			///\return ����� ������������� ����� � �����
			inline int GetDIBits(HBITMAP hbmp, UINT uStartScan,UINT cScanLines,LPVOID lpvBits,LPBITMAPINFO lpbi,UINT uUsage)
				{return ::GetDIBits(*this,hbmp, uStartScan,cScanLines,lpvBits,lpbi,uUsage);	}
			///\brief ������ ���������� �������������
			///\param lprc - ��������� �� ��������� ��������������
			///\param hbr - ����� �����, ������� ����� ������������ ������������
			///\return TRUE � ������ ������
			inline int FillRect(CONST RECT *lprc,HBRUSH hbr)
				{return (0!=::FillRect(*this,lprc,hbr));};
			///\brief ������ ���������� �������������
			///\param hrgn - ����� �������������� �������
			///\param hbr - ����� �����, ������� ����� ������������ ������������
			///\return TRUE � ������ ������
			inline int FillRgn(HRGN hrgn,HBRUSH hbr)
				{return (0!=::FillRgn(*this,hrgn,hbr));};
			///\brief ������� ��������� ������� ��������� ���������
			///\return TRUE � ������ ������
			BOOL SaveDC();
			///\brief ������� �������������� ���������� ��������� ���������
			///\param nSavedDC - ��������� ��� �������������
			///\return TRUE � ������ ������
			BOOL RestoreDC(int nSavedDC);
			///\brief ������� ������ �������
			///\param lpPoints - ��������� �� ������ ����� ��������
			///\param nCount - ����� ����� � �������
			///\return TRUE � ������ ������
			BOOL Polygon(CONST POINT *lpPoints,int nCount);
			///\brief ������� ��� ��������� ����� �� ��������� ����������
			///\param nXPos,nYPos - ����������
			///\return ���� � ������ ������, ����� CLR_INVALID
			COLORREF GetPixel(int nXPos,int nYPos);
			///\brief ������� ��� ��������� ����� �� ��������� ����������
			///\param nXPos,nYPos - ����������
			///\param crColor - ��������������� ���� 
			///\return TRUE � ������ ������
			BOOL SetPixel(int nXPos,int nYPos,COLORREF crColor);
			///\brief ������� ������ ������
			///\param X,Y - ���������� �������� ������ ���� ������
			///\param hIcon - ����� ������
			///\return TRUE � ������ ������
			BOOL DrawIcon(int X,int Y,HICON hIcon);
			///\brief ������� ������ ������
			///\param xLeft,yTop - ���������� �������� ������ ���� ������
			///\param hIcon - ����� ������
			///\param cxWidth,cyWidth - ������� ������
			///\param istepIfAniCur - ������ ������, ���� ������ - ������������� ������
			///\param hbrFlickerFreeDraw - ����� �� �����, ����� ���� NULL
			///\param diFlags - ���� ���������
			///\return TRUE � ������ ������
			BOOL DrawIconEx(int xLeft,int yTop,HICON hIcon,int cxWidth,int cyWidth,
				UINT istepIfAniCur,HBRUSH hbrFlickerFreeDraw,UINT diFlags);
	};
		///\class CULWindowDC
		///\brief ����� ��������� ����(10.09.2007)
		class CULWindowDC:public CULDC
		{
		public:
			///\�����������
			inline explicit CULWindowDC(HWND hWndOwner):CULDC()
			{
					m_hWndOwner=hWndOwner;
					m_hDC=::GetWindowDC(hWndOwner);
			};
			///\brief ����������
			~CULWindowDC(){if(m_hDC!=NULL)::ReleaseDC(m_hWndOwner,*this);m_hDC=NULL;};
		};
		///\class CULClientDC
		///\brief ����� ��������� ���������� ������� ����(10.09.2007)
		class CULClientDC:public CULDC
		{
		public:
			///\�����������
			inline explicit CULClientDC(HWND hWndOwner):CULDC()
				{
					m_hWndOwner=hWndOwner;
					m_hDC=::GetDC(hWndOwner);
				};
			///\brief ����������
			~CULClientDC(){if(m_hDC!=NULL)::ReleaseDC(m_hWndOwner,*this);m_hDC=NULL;};
		};
		///\class CULPaintDC
		///\brief ����� ��������� ���������� ������� ����(10.09.2007)
		///����������� ������ � ������������ WM_PAINT
		class CULPaintDC:public CULDC
		{
		public:
			PAINTSTRUCT m_PaintStruct;
		public:
			///\�����������
			inline explicit CULPaintDC(HWND hWndOwner):CULDC()
				{	
					m_hWndOwner=hWndOwner;
					m_hDC=::BeginPaint(hWndOwner,&m_PaintStruct);
				};
			///\brief ����������
			~CULPaintDC(){::EndPaint(m_hWndOwner,&m_PaintStruct);m_hDC=NULL;};
		};
	}
}
#endif//__ULDC__H_