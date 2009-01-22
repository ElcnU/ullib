///\file ULTrayIcon.h
///\brief ������������ ���� ������ ������ � ����
#pragma once

#ifndef _ULTRAYICON_H__
#define _ULTRAYICON_H__

#include <windows.h>
#include <tchar.h>
namespace ULOther
{
	///\class CULTrayIcon
	///\brief ����� ������ � ����
	class CULTrayIcon
	{
	protected:
		NOTIFYICONDATA m_NotifyIconData;
		UINT m_nIconCount;
	public:
		///\brief �����������
		CULTrayIcon(void);
		///\brief ����������
		~CULTrayIcon(void);
		///\brief �������������� ������
		///\param hWnd - ����� ����, � �������� ����� ��������� ������
		///\param uCallbackMessage - ������������� ��������� ���������� �� ������
		///\return TRUE � ������ ������
		BOOL Create(HWND hWnd,UINT uCallbackMessage);
		///\brief ������� ��������� ������ � ����
		///\param hIcon - ����� ������
		///\return ������������� ������ � ������ ������, ����� 0
		UINT AddIcon(HICON hIcon);
		///\brief ������� �������� ������ � ����
		///\param uID - ������������� ������ 
		///\return TRUE � ������ ������
		BOOL ChangeIcon(UINT uID,HICON hIcon);
		///\brief ������ ����� ������ ��������� ������
		///\param uID - ������������� ������ 
		///\param pszTip - ������ 
		///\return TRUE � ������ ������
		BOOL SetIconTip(UINT uID,TCHAR* pszTip);
		///\brief ������ ���������� ����� � ����������
		///\param uID - ������������� ������ 
		///\param pszInfoTitle - ��������� ���������
		///\param pszInfo - ���������
		///\param infoFlags - ��� ������
		///\return TRUE � ������ ������
		BOOL ShowBalloon(UINT uID,TCHAR* pszInfoTitle,TCHAR* pszInfo,DWORD dwInfoFlags);
		///\brief ������� ������� ������ �� ����
		///\param uID - ������������� ������ 
		///\return TRUE � ������ ������
		BOOL DeleteIcon(UINT uID);
	};
}
#endif //_ULTRAYICON_H__