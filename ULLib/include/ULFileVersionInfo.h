///\file ULFileVersionInfo.h
///\brief ������������ ���� ������ ������ �����(29.12.2007)
#pragma once
#ifndef __ULFILE_VERSION_INFO__H_
#define __ULFILE_VERSION_INFO__H_
#include <windows.h>
#include <tchar.h>
#pragma comment(lib, "version.lib")

namespace ULOther
{
	///\class CULFileVersionInfo
	///\brief ����� ������ �����
	class CULFileVersionInfo
	{
	protected:
		///\brief ������ ��� � ���� � �����
		LPTSTR m_lpszFileName;
	public:
		///\brief �����������
		///\param lpszFileName ������ ��� � ���� � �����
		CULFileVersionInfo(LPTSTR lpszFileName);
		///\brief �����������
		CULFileVersionInfo();
		///\brief ����������
		~CULFileVersionInfo();
		///\brief �������� ���������� � ����� �� ��������� ����
		///\param szType - ��� ���������� ���
		///\param szBuffer - �����, � ������� ����� ����������� ���������� ����������
		///\param nLength - ����� ������
		///\return �����, � ������� ����� ����������� ���������� ���������� � ������ ������, ����� NULL
		LPTSTR GetVersionString(LPTSTR szType, LPTSTR szBuffer, ULONG nLength);
		///\brief ������������� ������ ��� � ���� � �����
		///\param lpszFileName - ������ ��� � ���� � �����
		///\return ���������� ������ ��� � ���� � �����
		LPTSTR SetFileName(LPTSTR lpszFileName);
		///\brief ���������� ������� ������ ��� � ���� � �����
		///\param lpszFileName - �����, � ������� ����� ����������� ��� � ���� � �����
		///\param nLen - ����� ������
		///\return ������� ������ ��� � ���� � �����, ����� NULL
		LPTSTR GetFileName(LPTSTR lpszFileName,UINT nLen);
		///\brief ���������� �������� �����
		///\param lpszDescription - �����, � ������� ����� ����������� �������� �����
		///\param nLen - ����� ������
		///\return �������� �����, ����� NULL
		LPTSTR GetFileDescription(LPTSTR lpszDescription,UINT nLen);
		///\brief ���������� ������ �����
		///\param lpszVersion - �����, � ������� ����� ����������� ������ �����
		///\param nLen - ����� ������
		///\return ������ �����, ����� NULL
		LPTSTR GetFileVersion(LPTSTR lpszVersion,UINT nLen);
		///\brief ���������� ���������� ��� �����
		///\param lpszInternalName - �����, � ������� ����� ����������� ���������� ��� �����
		///\param nLen - ����� ������
		///\return ���������� ��� �����, ����� NULL
		LPTSTR GetInternalName(LPTSTR lpszInternalName,UINT nLen);
		///\brief ���������� �������� ��������
		///\param lpszProductName - �����, � ������� ����� ����������� �������� ��������
		///\param nLen - ����� ������
		///\return �������� ��������, ����� NULL
		LPTSTR GetProductName(LPTSTR lpszProductName,UINT nLen);
		///\brief ���������� ������ ��������
		///\param lpszProductVersion - �����, � ������� ����� ����������� ������ ��������
		///\param nLen - ����� ������
		///\return ������ ��������, ����� NULL
		LPTSTR GetProductVersion(LPTSTR lpszProductVersion,UINT nLen);
		///\brief ���������� ����������	
		///\param lpszComments - �����, � ������� ����� ����������� ����������
		///\param nLen - ����� ������
		///\return ����������, ����� NULL
		LPTSTR GetComments(LPTSTR lpszComments,UINT nLen);
		///\brief ���������� ��������� ��������� ����	
		///\param lpszLegalCopyright - �����, � ������� ����� ���������� �������� ��������� ����	
		///\param nLen - ����� ������
		///\return �������� ��������� ����, ����� NULL
		LPTSTR GetLegalCopyright(LPTSTR lpszLegalCopyright,UINT nLen);
		///\brief ���������� �������� �������� �������������
		///\param lpszCompanyName - �����, � ������� ����� ���������� �������� �������� �������������
		///\param nLen - ����� ������
		///\return �������� �������� �������������, ����� NULL
		LPTSTR GetCompanyName(LPTSTR lpszCompanyName,UINT nLen);	
	};
};
#endif //__ULFILE_VERSION_INFO__H_
