///\file ULGObjs.h
///\brief ������������ ���� ������� ����������� ��������(15.10.2007)
#include <windows.h>
#pragma once
#ifndef __ULGOBJS__H_
#define __ULGOBJS__H_
namespace ULGDI
{
	///\namespace ULGDI::ULGObjs
	///\brief ������������ ��� ������� ����������� ��������(15.10.2007)
	namespace ULGObjs
	{
		///\class CULBitmap
		///\brief ����� �������� �����������(15.10.2007)
		class CULBitmap
		{
		public:
			///\brief ����� �������� �����������
			HBITMAP m_hBitmap;
		public:
			///\brief �����������
			CULBitmap():m_hBitmap(NULL){}
			///\brief ����������� �����������
			CULBitmap(HBITMAP hBitmap):m_hBitmap(hBitmap){}
			///\brief ����������
			virtual ~CULBitmap(){DeleteBitmap();}
			///\brief ��� ����������� ������� ������ ��� ��� ��������� 
			///������ HBITMAP
			inline operator HBITMAP() const{return m_hBitmap;}
			///\brief ������ ������� �����������
			///\param nWidth, nHeight - ������ �����������
			///\param cPlanes - ����� �������� �������
			///\param cBitsPerPel - ����� ��� �� �����
			///\param lpvBits - ������� ������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL CreateBitmap(int nWidth,int nHeight,UINT cPlanes,UINT cBitsPerPel,CONST VOID *lpvBits)
				{return ((m_hBitmap=::CreateBitmap(nWidth,nHeight,cPlanes,cBitsPerPel,lpvBits))!=NULL);}
			///\brief ������ ����������� � ���������� ������� �������
			///\param hDC - ��������
			///\param nWidth,nHeight - ������ ������������ �������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL CreateCompatibleBitmap(HDC hDC,int nWidth,int nHeight)
				{return ((m_hBitmap=::CreateCompatibleBitmap(hDC,nWidth,nHeight))!=NULL);}
			///brief ��������� ������� ������� �� ������� ��� �� �����
			///\param hInstance - ����� ������, �� �������� ����������� ������� ������� 
			///\param lpBitmapName - ��� ����� ��� �������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL LoadBitmap(HINSTANCE hInstance,LPCTSTR lpBitmapName)
				{return ((m_hBitmap=::LoadBitmap(hInstance,lpBitmapName))!=NULL);};
			///brief ��������� ������� ������� �� �������
			///\param hInstance - ����� ������, �� �������� ����������� ������� ������� 
			///\param nIDRes - ID �������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL LoadBitmap(HINSTANCE hInstance,int nIDRes)
				{return ((m_hBitmap=::LoadBitmap(hInstance,MAKEINTRESOURCE(nIDRes)))!=NULL);};
			///\brief ���������� ��������� �������� ����������
			///\param pBmp - ��������� �� ��������� �������� ����������
			///\return ����������� ���� ������������� � �����
			///	���� pBmp NULL �� ������ ��������� ���������� ����
			inline int GetBitmap(BITMAP* pBmp)
				{return ::GetObject((HBITMAP)*this,sizeof(BITMAP),(LPSTR)pBmp);}
			///\brief ��. GetBitmap
			inline int GetBitmap(DIBSECTION* pDib)
				{return ::GetObject((HBITMAP)*this,sizeof(DIBSECTION),(LPSTR)pDib);}
			///\brief ���������� ������� ������ �����������
			///\param cbBuffer - ����� ������
			///\param lpvBits - ������� ������
			///\return � ������ ������ ����� ������������� ����, ����� 0
			inline LONG GetBitmapBits(LONG cbBuffer,LPVOID lpvBits)
				{return ::GetBitmapBits(*this,cbBuffer,lpvBits);}
			///\brief ������� ������� �����������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL DeleteBitmap()
				{if(m_hBitmap!=NULL)return ::DeleteObject(m_hBitmap);else return FALSE;}
			///\brief ����������� ������� ����������� �� ������
			///\return ����� �� ������� ����������� 
			inline HBITMAP Detach()
				{HBITMAP hRetBmp=m_hBitmap;m_hBitmap=NULL;return hRetBmp;}
		};
		///\class CULRgn
		///\brief ����� �������(15.10.2007)
		class CULRgn
		{
		public:
			///\brief ����� �������
			HRGN m_hRgn;
		public:
			///\brief �����������
			CULRgn():m_hRgn(NULL){};
			///\brief ����������� �����������
			CULRgn(HRGN& hRgn):m_hRgn(hRgn){};
			///\brief ����������
			virtual ~CULRgn(){DeleteRgn();}
			///\brief ��� ����������� ������� ������ ��� ��� ��������� 
			///������ HRGN
			inline operator HRGN() const{return m_hRgn;}
			///\brief ������ ������ �� �������� �����������,
			///	������� ������� ������������ ������ ������� �� ���������� 0,0
			///\param RgnBitmap - ����� �������� �����������
			///\return TRUE � ������ ������, ����� FALSE
			BOOL CreateBitmapRgn(CULBitmap RgnBitmap);
			///\brief ������ ������ � ���� ��������������
			///\param nLeftRect,nTopRect,nRightRect,nBottomRect - ���������� ����� ��������������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL CreateRectRgn(int nLeftRect,int nTopRect,int nRightRect,int nBottomRect)
				{return ((m_hRgn=::CreateRectRgn(nLeftRect,nTopRect,nRightRect,nBottomRect))!=NULL);};
			///\brief ������ ������ � ���� �������������� �� ����������� ������
			///\param nLeftRect,nTopRect,nRightRect,nBottomRect - ���������� ����� ��������������
			///\param nWidthEllipse,nHeightEllipse - ������� ������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL CreateRoundRectRgn(int nLeftRect,int nTopRect,int nRightRect,int nBottomRect,
				int nWidthEllipse,int nHeightEllipse)
				{return ((m_hRgn=::CreateRoundRectRgn(nLeftRect,nTopRect,nRightRect,nBottomRect,
					nWidthEllipse,nHeightEllipse))!=NULL);}
			///\brief ����������� ��� �������� ������� � �������� � �������
			///\param hrgnSrc1,hrgnSrc2 - ������ �������� ��������
			///\param fnCombineMode - ����� ��������������
			///	RGN_AND		Creates the intersection of the two combined regions. 
			///	RGN_COPY	Creates a copy of the region identified by hrgnSrc1. 
			///	RGN_DIFF	Combines the parts of hrgnSrc1 that are not part of hrgnSrc2. 
			///	RGN_OR		Creates the union of two combined regions. 
			///	RGN_XOR		Creates the union of two combined regions except for any overlapping areas. 
			///\return 
			///	NULLREGION The region is empty. 
			///	SIMPLEREGION The region is a single rectangle. 
			///	COMPLEXREGION The region is more than a single rectangle. 
			///	ERROR No region is created. 
			inline int CombineRgn(HRGN hrgnSrc1,HRGN hrgnSrc2,int fnCombineMode)
				{return ::CombineRgn(*this,hrgnSrc1,hrgnSrc2,fnCombineMode);}
			///\brief ����������� ������� ������ � hrgnSrc2 (��. CombineRgn)
			///\param hrgnSrc2 - ������ ������
			///\param fnCombineMode - ����� �������������� ��. CombineRgn
			///\return ��. CombineRgn			
			inline int CombineRgn(HRGN hrgnSrc2,int fnCombineMode)
				{return ::CombineRgn(*this,*this,hrgnSrc2,fnCombineMode);}
			///\brief ������� ������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL DeleteRgn()
				{if(m_hRgn!=NULL)return ::DeleteObject(m_hRgn);else return FALSE;}
			///\brief ����������� ������ �� ������
			///\return ����� �� ������
			inline HRGN Detach()
				{HRGN hRetRgn=m_hRgn;m_hRgn=NULL;return hRetRgn;}
		};
		///\class CULPen
		///\brief ����� ����(15.10.2007) 
		class CULPen
		{
		public:
			///\brief ����� ����
			HPEN m_hPen;
		public:
			///\brief �����������
			CULPen():m_hPen(NULL){};
			///\brief ����������� �����������
			CULPen(HPEN& hPen):m_hPen(hPen){};
			///\brief ����������� � ��������� ���������
			CULPen(int fnPenStyle,int nWidth,COLORREF crColor);
			///\brief ����������
			virtual ~CULPen(){DeletePen();}
			///\brief ��� ����������� ������� ������ ��� ��� ��������� 
			///������ HPEN
			inline operator HPEN() const{return m_hPen;}
			///\brief ������ ����
			///\param fnPenStyle - ����� ����
			///	PS_SOLID		The pen is solid. 
			///	PS_DASH			The pen is dashed. This style is valid only when the pen width is one or less in device units. 
			///	PS_DOT			The pen is dotted. This style is valid only when the pen width is one or less in device units. 
			///	PS_DASHDOT		The pen has alternating dashes and dots. This style is valid only when the pen width is one or less in device units. 
			///	PS_DASHDOTDOT	The pen has alternating dashes and double dots. This style is valid only when the pen width is one or less in device units. 
			///	PS_NULL			The pen is invisible. 
			///	PS_INSIDEFRAME	The pen is solid. When this pen is used in any GDI drawing function that takes a bounding rectangle, the dimensions of the figure are shrunk so that it fits entirely in the bounding rectangle, taking into account the width of the pen. This applies only to geometric pens. 			
			///\param nWidth - ������� ����
			///\param crColor - ���� ����
			///\return 	TRUE � ������ ������, ����� FALSE
			BOOL CreatePen(int fnPenStyle,int nWidth,COLORREF crColor)
				{return ((m_hPen=::CreatePen(fnPenStyle,nWidth,crColor))!=NULL);}
			///\brief ������ ���� �� ��������� LOGPEN
			///\param lplgpn - ��������� �� ���������� ��������� LOGPEN
			///\return 	TRUE � ������ ������, ����� FALSE
			BOOL CreatePenIndirect(CONST LOGPEN *lplgpn)
				{return ((m_hPen=::CreatePenIndirect(lplgpn))!=NULL);}
			///\brief ������ ���� ���������� ����
			///\param nIndex - ������ ���������� ����
			///	BLACK_PEN Black pen. 
			///	DC_PEN Windows 2000/XP: Solid pen color. The default color is white. The color can be changed by using the SetDCPenColor function. For more information, see the Remarks section. 
			///	WHITE_PEN White pen. 
			///\return TRUE � ������ ������, ����� FALSE	
			inline BOOL CreateSysPen(int nIndex)
				{return ((m_hPen=(HPEN)::GetStockObject(nIndex))!=NULL);}
			///\brief ���������� ��������� ����
			///\param pLogPen - ��������� �� ��������� ����(LOGPEN)
			///\return ����������� ���� ������������� � �����
			///	���� pLogPen NULL �� ������ ��������� ���������� ����
			inline int GetLogPen(LOGPEN* pLogPen)
				{return ::GetObject((HPEN)*this,sizeof(LOGPEN),(LPSTR)pLogPen);}
			///\brief ���������� ��������� ����
			///\param pExtLogPen - ��������� �� ��������� ����(EXTLOGPEN)
			///\return ����������� ���� ������������� � �����
			///	���� pExtLogPen NULL �� ������ ��������� ���������� ����
			inline int GetExtLogPen(EXTLOGPEN* pExtLogPen)
				{return ::GetObject((HPEN)*this,sizeof(EXTLOGPEN),(LPSTR)pExtLogPen);}
			///\brief ������� ����
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL DeletePen()
				{if(m_hPen!=NULL)return ::DeleteObject(m_hPen);else return FALSE;}
			///\brief ����������� ���� �� ������
			///\return ����� �� ����
			inline HPEN Detach()
				{HPEN hRetPen=m_hPen;m_hPen=NULL;return hRetPen;}
		};
		///\class CULBrush
		///\brief ����� �����(15.10.2007) 
		class CULBrush
		{
		public:
			///\brief ����� ����
			HBRUSH m_hBrush;
		public:
			///\brief �����������
			CULBrush():m_hBrush(NULL){};
			///\brief ����������� �����������
			CULBrush(HBRUSH& hBrush):m_hBrush(hBrush){};
			///\brief ����������
			virtual ~CULBrush(){DeleteBrush();}
			///\brief ��� ����������� ������� ������ ��� ��� ��������� 
			///������ HBRUSH
			inline operator HBRUSH() const{return m_hBrush;}
			///\brief ������ �����
			///\param lplb - �������� ���������� � �����
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL CreateBrushIndirect(CONST LOGBRUSH *lplb)
				{return ((m_hBrush=::CreateBrushIndirect(lplb))!=NULL);}
			///\brief ������ ����� �� DIB
			///\param hglbDIBPacked - Handle to a global memory object containing a packed DIB,
			///	which consists of a BITMAPINFO structure immediately followed by an array of bytes defining the pixels of the bitmap. 
			///\param fuColorSpec - ����� ����� � hglbDIBPacked
			///	DIB_PAL_COLORS A color table is provided and consists of an array of 16-bit 
			///	indexes into the logical palette of the device context into which the brush is to be selected. 
			///	DIB_RGB_COLORS A color table is provided and contains literal RGB values. 
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL CreateDIBPatternBrush(HGLOBAL hglbDIBPacked,UINT fuColorSpec)
				{return ((m_hBrush=::CreateDIBPatternBrush(hglbDIBPacked,fuColorSpec))!=NULL);}
			///\brief ������ ������������ �����
			///\param fnStyle - �����
			///	HS_BDIAGONAL 45-degree upward left-to-right hatch 
			///	HS_CROSS Horizontal and vertical crosshatch 
			///	HS_DIAGCROSS 45-degree crosshatch 
			///	HS_FDIAGONAL 45-degree downward left-to-right hatch 
			///	HS_HORIZONTAL Horizontal hatch 
			///	HS_VERTICAL Vertical hatch 
			///\param clrref - ����
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL CreateHatchBrush(int fnStyle,COLORREF clrref)
				{return ((m_hBrush=::CreateHatchBrush(fnStyle,clrref))!=NULL);}
			///\brief ������ ����� �� �������� �����������
			///\param hbmp - ����� �������� �����������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL CreatePatternBrush(HBITMAP hbmp)
				{return ((m_hBrush=::CreatePatternBrush(hbmp))!=NULL);}
			///\brief ������ �������� ����� 
			///\param crColor - ����
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL CreateSolidBrush(COLORREF crColor)
				{return ((m_hBrush=::CreateSolidBrush(crColor))!=NULL);}
			///\brief ������ ����� ���������� �����
			///\param nIndex - ������ ���������� �����
			///	BLACK_BRUSH Black brush. 
			///	DKGRAY_BRUSH Dark gray brush. 
			///	DC_BRUSH Windows 2000/XP: Solid color brush. The default color is white. The color can be changed by using the SetDCBrushColor function. For more information, see the Remarks section. 
			///	GRAY_BRUSH Gray brush. 
			///	HOLLOW_BRUSH Hollow brush (equivalent to NULL_BRUSH). 
			///	LTGRAY_BRUSH Light gray brush. 
			///	NULL_BRUSH Null brush (equivalent to HOLLOW_BRUSH). 
			///	WHITE_BRUSH White brush. 
			///\return TRUE � ������ ������, ����� FALSE	
			inline BOOL CreateSysColorBrush(int nIndex)
				{return ((m_hBrush=::GetSysColorBrush(nIndex))!=NULL);}
			///\brief ���������� ��������� �����
			///\param pLogBrush - ��������� �� ��������� ����(LOGBRUSH)
			///\return ����������� ���� ������������� � �����
			///	���� pLogBrush NULL �� ������ ��������� ���������� ����
			inline int GetLogBrush(LOGBRUSH* pLogBrush)
				{return ::GetObject((HBRUSH)*this,sizeof(LOGBRUSH),(LPSTR)pLogBrush);}
			///\brief ������� �����
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL DeleteBrush()
				{if(m_hBrush!=NULL)return ::DeleteObject(m_hBrush);else return FALSE;}
			///\brief ����������� ����� �� ������
			///\return ����� �� �����
			inline HBRUSH Detach()
				{HBRUSH hRetBrush=m_hBrush;m_hBrush=NULL;return hRetBrush;}
		};
		///\class CULFont
		///\brief ����� ������(15.10.2007) 
		class CULFont
		{
		public:
			///\brief ����� ������
			HFONT m_hFont;
		public:
			///\brief �����������
			CULFont():m_hFont(NULL){};
			///\brief ����������� �����������
			CULFont(HFONT hFont):m_hFont(hFont){};
			///\brief ����������
			virtual ~CULFont(){DeleteFont();}
			///\brief ��� ����������� ������� ������ ��� ��� ��������� 
			///������ HFONT
			inline operator HFONT() const{return m_hFont;}
			///\brief ������ �����
			///\param nHeight - ������ ������(���������� nHeight = -MulDiv(PointSize, GetDeviceCaps(hDC, LOGPIXELSY), 96);)
			///\param nWidth - ������� ������ �������
			///\param nEscapement - angle of escapement
			///\param nOrientation - base-line orientation angle
			///\param fnWeight - ��� ������(���� ������(FW_THIN),�������(FW_BOLD))
			///\param fdwItalic - ���� �����������
			///\param fdwUnderline - ���� �������������
			///\param fdwStrikeOut - ���� ������������ 
			///\param fdwCharSet - ����������
			///\param fdwOutputPrecision - output precision
			///\param fdwClipPrecision - clipping precision
			///\param fdwQuality - ���� ��������
			///\param fdwPitchAndFamily - pitch and family
			///\param lpszFace - �������� ������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL CreateFont(int nHeight,int nWidth,int nEscapement,int nOrientation,
				int fnWeight,DWORD fdwItalic,DWORD fdwUnderline,DWORD fdwStrikeOut,
				DWORD fdwCharSet,DWORD fdwOutputPrecision,DWORD fdwClipPrecision,
				DWORD fdwQuality,DWORD fdwPitchAndFamily,LPCTSTR lpszFace)
				{return ((m_hFont=::CreateFont(nHeight,nWidth,nEscapement,nOrientation,
					fnWeight,fdwItalic,fdwUnderline,fdwStrikeOut,fdwCharSet,
					fdwOutputPrecision,fdwClipPrecision,fdwQuality,fdwPitchAndFamily,
					lpszFace))!=NULL);};
			///\brief ������ �����
			///\param lpLogFont - ���������� � ������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL CreateFontIndirect(const LOGFONT* lpLogFont)
				{return ((m_hFont=::CreateFontIndirect(lpLogFont))!=NULL);}
			///\brief ������ ����� ���������� ����
			///\param nIndex - ������ ���������� ����
			///	ANSI_FIXED_FONT Windows fixed-pitch (monospace) system font. 
			///	ANSI_VAR_FONT Windows variable-pitch (proportional space) system font. 
			///	DEVICE_DEFAULT_FONT Windows NT/2000/XP: Device-dependent font. 
			///	DEFAULT_GUI_FONT Default font for user interface objects such as menus and dialog boxes. This is MS Sans Serif. Compare this with SYSTEM_FONT. 
			///	OEM_FIXED_FONT Original equipment manufacturer (OEM) dependent fixed-pitch (monospace) font. 
			///	SYSTEM_FONT System font. By default, the system uses the system font to draw menus, dialog box controls, and text. 
			///	SYSTEM_FIXED_FONT Fixed-pitch (monospace) system font. This stock object is provided only for compatibility with 16-bit Windows versions earlier than 3.0.  
			///\return TRUE � ������ ������, ����� FALSE	
			inline BOOL CreateSysFont(int nIndex)
				{return ((m_hFont=(HFONT)::GetStockObject(nIndex))!=NULL);}
			///\brief ���������� ��������� ������
			///\param pLogFont - ��������� �� ��������� ������(LOGFONT)
			///\return ����������� ���� ������������� � �����
			///	���� pLogFont NULL �� ������ ��������� ���������� ����
			inline int GetLogFont(LOGFONT* pLogFont)
				{return ::GetObject((HFONT)*this,sizeof(LOGFONT),(LPSTR)pLogFont);}
			///\brief ������� �����
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL DeleteFont()
				{if(m_hFont!=NULL)return ::DeleteObject(m_hFont);else return FALSE;}
			///\brief ����������� ����� �� ������
			///\return ����� �� �����
			inline HFONT Detach()
				{HFONT hRetFont=m_hFont;m_hFont=NULL;return hRetFont;}
		};
		///\class CULPalette
		///\brief ����� �������(15.10.2007) 
		class CULPalette
		{
		public:
			///\brief ����� �������
			HPALETTE m_hPalette;
		public:
			///\brief �����������
			CULPalette():m_hPalette(NULL){};
			///\brief ����������� �����������
			CULPalette(HPALETTE& hPalette):m_hPalette(hPalette){};
			///\brief ����������
			virtual ~CULPalette(){DeletePalette();}
			///\brief ��� ����������� ������� ������ ��� ��� ��������� 
			///������ HPALETTE
			inline operator HPALETTE() const{return m_hPalette;}
			///\brief ������ ����������� ������� �� ������ ���������
			///\param hDC - ��������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL CreateHalftonePalette(HDC hDC)
				{return ((m_hPalette=::CreateHalftonePalette(hDC))!=NULL);}
			///\brief ������ ������� 
			///\param lpLogPalette - �������� ���������� ���������� � �������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL CreatePalette(LPLOGPALETTE lpLogPalette)
				{return ((m_hPalette=::CreatePalette(lpLogPalette))!=NULL);}
			///\brief �������� ����� � �������
			///\param iStartIndex - ��������� ������
			///\param cEntries - ����������� ������
			///\param ppe - ������ �������� PALETTEENTRY
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL AnimatePalette(UINT iStartIndex,UINT cEntries,CONST PALETTEENTRY *ppe)
				{return ::AnimatePalette(*this,iStartIndex,cEntries,ppe);}
			///\brief ���������� ��������� �� ����� ������ �������
			///\param crColor - ���� 
			///\return ������ �������
			inline UINT GetNearestPaletteIndex(COLORREF crColor)
				{return ::GetNearestPaletteIndex(*this,crColor);}
			///\brief �������� ������ �������
			///\param nEntries - ����� ����������� ������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL ResizePalette(UINT nEntries)
				{return ::ResizePalette(*this,nEntries);}
			///\brief ���������� ������ ������ �� �������
			///\param iStartIndex - ��������� ������
			///\param nEntries - ����������� ������
			///\param lppe - ������������ ������ �������� PALETTEENTRY
			///\return ����� ������������� ������
			inline UINT GetPaletteEntries(UINT iStartIndex,UINT nEntries,LPPALETTEENTRY lppe)
				{return ::GetPaletteEntries(*this,iStartIndex,nEntries,lppe);}
			///\brief ������������� ������ ����� ������ � �������
			///\param iStartIndex - ��������� ������
			///\param nEntries - ����������� ������
			///\param lppe - ������ �������� PALETTEENTRY
			///\return ����� ������������� ������
			inline UINT SetPaletteEntries(UINT iStartIndex,UINT nEntries,LPPALETTEENTRY lppe)
				{return ::SetPaletteEntries(*this,iStartIndex,nEntries,lppe);}
			///\brief ���������� ����� ��������� � �������
			///\return ����� ������ � �������
			inline int GetEntryCount()
			{	
				WORD nEntries;
				::GetObject(m_hPalette, sizeof(WORD), &nEntries); 
				return (int)nEntries; 
			}
			///\brief ������� �������
			///\return TRUE � ������ ������, ����� FALSE
			inline BOOL DeletePalette()
				{if(m_hPalette!=NULL)return ::DeleteObject(m_hPalette);else return FALSE;}
			///\brief ����������� ������� �� ������
			///\return ����� �� �������
			inline HPALETTE Detach()
				{HPALETTE hRetPalette=m_hPalette;m_hPalette=NULL;return hRetPalette;}

		};
	}
	///\brief ��������� �������� ���� BMP, GIF, JPEG, ICO, WMF, � EMF:
	///\param szResource - ��� ������� ��� �����
	///\param szResourceType - ��� �������
	///\param hMod - ����� ������, � ������� ����� ������
	///\return ����� �������, � ������ ������ NULL
	HBITMAP ULLoadImage(LPCTSTR szResource,LPCTSTR szResourceType=NULL,HINSTANCE hMod=NULL);
}
#endif//__ULGOBJS__H_