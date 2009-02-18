///\file ULOther.h
///\brief ������������ ���� ������������ ��� ������ ��� �������� �������(25.08.2007)
#pragma once
#ifndef __ULOTHER__H_
#define __ULOTHER__H_
#include <windows.h>
#include "ULProfileReg.h"
#include "ULPtr.inl"
#include "ULFileVersionInfo.h"
#include "ULWaitCursor.h"
#include "ULRes.h"

#include "ULTrayIcon.h"
///\namespace ULOther
///\brief ������������ ��� ������ ��� �������� �������(25.08.2007)
namespace ULOther
{
	///\brief ������� ��� ����������� ��� � �������������� �������(2006)
	///\param hLibrary -����� ������������ ���������� 
	///\param lpszLibrary-��� ����� ������������ ���������� 
	///\param nCount-����������� ������������� ������� 
	///\param ... - ��������� �� �������� �������, ��� �������
	///\return TRUE � ������ ������
	BOOL GetProcAddresses(HINSTANCE *hLibrary, LPCTSTR lpszLibrary, INT nCount, ... );
	///\brief ������� ��� �������� rus ������ � ����������(30.07.2007)
	///\param pszIn - ��������� �� ����� � �������
	///\return ���������� �����
	const char* Rus(const TCHAR* pszIn);
	///\brief ������� ���������� �������� ������(29.12.2007)
	///\param nErr - ����� ������
	///\return �������� ��������� ������
	LPTSTR ParseError(UINT nErr);
	///\brief ��� ��������� ����������, � ������� ���������� ��������� ������
	///\param hModule - ����� ������
	///\param lpszFolderPath - ������������ ������ � ������ ����������
	///\param dwSize - ������ ������
	///\return ����� ������ ���� � ������������ ���������� 
	DWORD GetModuleFolderPath(HMODULE hModule,LPTSTR lpszFolderPath,DWORD dwSize);	
};
#endif//__ULOTHER__H_