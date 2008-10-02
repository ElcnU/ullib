///\file ULReBar.h
///\brief ������������ ���� ������ ������(11.08.2007)
#pragma once
#ifndef __UL_ULREBAR_H__
#define __UL_ULREBAR_H__

#include <windows.h>
#include <commctrl.h>
#pragma comment(lib,"comctl32.lib")
#include "ULSubClass.h"
namespace ULWnds
{
	namespace ULBars
	{
		///\class CULRebar
		///\brief ����� ������(11.08.2007)
		class CULRebar:public CULSubClass
		{
		public:
			///\brief �����������
			CULRebar();
			///\brief ����������� �����������
			CULRebar(CULRebar	&);
			///\brief ����������
			virtual ~CULRebar();
			///\brief �������� �����������
			void operator=(CULRebar&);
			///\brief ����� ������ ��� ���������� ������ �� ����� ��������
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
			}m_afFlag;
			///\brief ������ �������� ������
			///\param hParentWnd - ����� ��������
			///\param afFlag - ���� ����������
			///\param dwStyle - ��������
			HWND Create(HWND hParentWnd,enAlignFlags afFlag,DWORD dwStyle=
				WS_CHILD|WS_VISIBLE|WS_BORDER|/*WS_CLIPSIBLINGS|*/
				/*WS_CLIPCHILDREN|*/RBS_VARHEIGHT|CCS_NODIVIDER|RBS_AUTOSIZE);
			///\brief ������ ������� ����� ���������� ������ 
			///\param nInto - ������� �������
			///\param hClientWnd-����� �������
			///\param szName-��� ���������� ������
			///\param hBitmap-������� ��������
			///\param wID - ������������� �����
			///\param pszClient - ������ �������
			///\param dwStyle=��������
			BOOL InsertBand(int nInto,HWND hClientWnd,TCHAR* szName,HBITMAP hBitmap,
				WORD wID=0,SIZE* pszClient=NULL,
				DWORD dwStyle=/*RBBS_GRIPPERALWAYS|*/RBBS_FIXEDBMP|/*RBS_BANDBORDERS|/*RBBS_BREAK|*/RBBS_CHILDEDGE);
			///\brief ������ ������� ����� ���������� ������ 
			///\param nInto - ������� �������
			///\param hClientWnd-����� �������
			///\param szName-��� ���������� ������
			///\param clrFore-���� ������� szName
			///\param clrBack-���� ����
			///\param wID - ������������� �����
			///\param pszClient - ������ �������
			///\param dwStyle=��������
			BOOL InsertBand(int nInto,HWND hClientWnd, TCHAR* szName,	COLORREF clrFore, COLORREF clrBack,
				WORD wID=0,SIZE* pszClient=NULL,
				DWORD dwStyle= RBBS_GRIPPERALWAYS|RBBS_BREAK|RBBS_CHILDEDGE);
			///\brief ������� ��� ���������� ������ � ������
			BOOL DeleteBand(int numBand);
			/*!\brief �������� ������ ������ �� ������ ��� ������ ��������
					� ����������� �� ��������������
			�������� � ���������� WM_SIZE ���� �������� */
			void AutoSize();
			///\brief ���������� ����� ���������� ������
			///\return ����� ���������� ������
			int GetBandCount()
				{return (int)SendMessage(RB_GETBANDCOUNT);}
			///\brief ���������� ���������� � �����
			///\param nBand - ����� �����
			///\param lprbbi - ��������� �� ��������� �����
			///\return TRUE  � ������ ������
			BOOL GetBandInfo(int nBand,LPREBARBANDINFO lprbbi)
				{return (SendMessage(RB_GETBANDINFO,(WPARAM)nBand,(LPARAM)lprbbi)!=0);}
			///\brief ������� ���������� � �����
			///\param nBand - ����� �����
			///\param lprbbi - ��������� �� ��������� �����
			///\return TRUE  � ������ ������
			BOOL SetBandInfo(int nBand,LPREBARBANDINFO lprbbi)
				{return (SendMessage(RB_SETBANDINFO,(WPARAM)nBand,(LPARAM)lprbbi)!=0);}
			///\brief �������������� ����
			///\param nBand - ����� �����
			void MinimizeBand(int nBand)
				{SendMessage(RB_MINIMIZEBAND,(WPARAM)nBand);}
			///\brief ��������������� ����
			///\param nBand - ����� �����
			void MaximizeBand(int nBand)
				{SendMessage(RB_MAXIMIZEBAND,(WPARAM)nBand);}
		};
	}
}
#endif //__UL_ULREBAR_H__