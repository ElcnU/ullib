///\file ULStatusBar.h
///\brief ������������ ���� ������ ����������(12.10.2007)
#pragma once
#ifndef __UL_ULSTATUSBAR_H__
#define __UL_ULSTATUSBAR_H__

#include <windows.h>
#include <commctrl.h>
#pragma comment(lib,"comctl32.lib")
#include "ULSubClass.h"
#include "ULControls.h"
namespace ULWnds
{
	namespace ULBars
	{
		///\class CULStatusBar
		///\brief ����� ����������(12.10.2007)
		class CULStatusBar: public CULSubClass
		{
			///\brief ����������� ������ �� ����������
			UINT m_nParts;
		public:
			///\brief �����������
			CULStatusBar();
			///\brief ����������
			virtual ~CULStatusBar();
			///\brief ������� �������� ����������
			///\param hParentWnd-����� �������� ��� ����������
			///\param nStatusID - ID ����������
			///\param fGrip-�������� �� ���������� ��� ��������� ��������
			HWND Create(HWND hParentWnd,short nStatusID,BOOL fGrip=TRUE);
			///\brief ���������� �������������� ������ �� ���������
			///\param Width - ������ ������
			///\param szToolTip - ��� ��������� ����� ���������, ���� 
			///	����� ���� �� ��������� � ������
			BOOL AddPart(int Width,TCHAR* szToolTip);
			//������� ��� �������������� ������ �� ����������
			BOOL DeleteAll();
			///\brief ������������� ������ � �������������� ������
			///\param nPart - ����� ������
			///\param hIcon - ����� ������
			BOOL SetIcon(int nPart, HICON hIcon);
			///\brief ������������� ������ � �������������� ������
			///\param nPart - ����� ������
			///\param uiID - ID ������ �� ��������
			BOOL SetIcon(int nPart, short uiID);
			///\brief ������������� ����� � �������������� ������
			///\param nPart - ����� ������
			///\param szText - ��� ����� :)
			BOOL SetText(int nPart, TCHAR* szText);
			///\brief ������������� ����� ��������� � �������������� ������
			///\param nPart - ����� ������
			///\param szText - ��� ����� :)
			BOOL SetToolTipText(int nPart, TCHAR* szText);
			///\brief �������� ������ ��������� �� ������ ��������
			///	� ��������� ������ ������� ������.
			///	�������� � ���������� WM_SIZE ���� �������� 
			void AutoSize();
		};
	}
}
#endif //__UL_ULSTATUSBAR_H__
