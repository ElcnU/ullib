///\file ULToolTip.h
///\brief ������������ ���� ������ �������� ���������(06.09.2007)
#pragma once
#ifndef __ULTOOLTIP_H__
#define __ULTOOLTIP_H__
#include <windows.h>
#include <commctrl.h>
#include "ULSubClass.h"
#pragma comment(lib,"comctl32.lib")
namespace ULWnds
{
	namespace ULControls
	{
		///\class CULToolTip
		///\brief ����� �������� ���������(06.09.2007)
		class CULToolTip: public CULSubClass
		{
		public:
			TOOLINFO m_ToolInfo;
			///brief ���� ������ � ���������
			///\param itNon - ��� ������
			///\param itInfo - ������ "����"
			///\param itWarning - ������ "��������"
			///\param itError - ������ "������"
			enum enIconType
			{
				itNon		=0,
				itInfo		=1,
				itWarning	=2,
				itError		=3
			};
			///\brief ���� ��������������� ��������
			///\param dtAutomatic - ������������ ������� �� ������������ 
			///	����������
			///\param dtAutoPop - ������������� ����� ��������� ��� 
			///	�������� ���������
			///\param dtInitial - ����� ������������� ������� ����� 
			///	���������� ������� � ��� �������� � ������������ 
			///	���������
			///\param dtReshow - ������������� ������� ����� �������������
			///	����� � ���������� ������ ���������
			enum enDelayTime
			{
				dtAutomatic	=TTDT_AUTOMATIC,
				dtAutoPop	=TTDT_AUTOPOP,
				dtInitial	=TTDT_INITIAL,
				dtReshow	=TTDT_RESHOW
			};
			///�����������
			CULToolTip();
			///����������
			virtual ~CULToolTip();
			///\brief ������� �������� ����
			///\param hParentWnd - ������������ ����
			///\param fBalloon - ��� ����������� ����
			///\return TRUE � ������ ������
			BOOL Create(HWND hParentWnd, BOOL fBalloon=TRUE);	
			///\brief ������� ���������� ���������
			///	���� uID==0,�� ��������������� ���� TTF_SUBCLASS
			///	���� uID!=0,�� ��������������� ���� TTF_TRACK
			///	��� ��������� ������������ TrackPosition � TrackActivate
			///\param hTargetWnd - ����, ��� �������� ���������
			///\param szMessage - ����� ���������
			///\param uID - ������������� ���������
			///\return TRUE � ������ ������
			BOOL AddTool(HWND hTargetWnd, LPCTSTR szMessage,UINT uID=0);	
			///\brief ������� ���������� ���������
			///\param hTargetWnd - ����, ��� �������� ���������
			///\param szMessage - ����� ���������
			///\return TRUE � ������ ������
			BOOL UpdateTipText(HWND hTargetWnd,	LPCTSTR szMessage);				
		//==================inline functions============================
			///\brief ������� ����� ���� ����
			///\param clrBK - ���� ����
			inline void SetTipBkColor(COLORREF clrBK)
				{SendMessage(TTM_SETTIPBKCOLOR,clrBK,0);};
			///\brief ������� ����� ���� ������
			///\param clrText - ���� ������	
			inline void SetTipTextColor(COLORREF clrText)
				{SendMessage(TTM_SETTIPTEXTCOLOR,clrText,0);};
			///\brief ������� ����� ��������� ��� ��������� � ��� ������������ ������
			///\param it- ��� ������������ ������
			///\param szTitle - ����� ���������
			inline BOOL SetTitle(enIconType it, TCHAR* szTitle)
				{return(BOOL)SendMessage(TTM_SETTITLE,WPARAM(it),(LPARAM)szTitle);};
			///\brief ������� ������������� ������� ���������...���������
			///\param nmsTime - �������� � ��
			///\param dt - ��� ��������
			inline int SetDelayTime(int nmsTime,enDelayTime dt=dtAutomatic)
				{return (int)SendMessage(TTM_SETDELAYTIME,WPARAM(dt),(LPARAM)nmsTime);};
			///\brief ������� ������������� ������� ���������
			///\param x,y - ���������� ����������
			inline void TrackPosition(int x,int y)
				{SendMessage(TTM_TRACKPOSITION,0,(LPARAM)(DWORD) MAKELONG(x,y));};
			///\brief ������� ��/������������ �������� ���������
			///\param hWnd - ����� ����, �������� ����������� ���������
			///\param uID - ID ��������� 
			///\param fActivate - TRUE/FALSE - ��������������/����������������
			inline void TrackActivate(HWND hWnd,UINT uID,BOOL fActivate)
				{m_ToolInfo.hwnd=hWnd;m_ToolInfo.uId=uID;
						SendMessage(TTM_TRACKACTIVATE,(WPARAM)fActivate,(LPARAM)&m_ToolInfo);};
		};
	}
}
#endif //__ULTOOLTIP_H__