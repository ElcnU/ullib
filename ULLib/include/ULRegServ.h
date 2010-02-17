///\file ULRegServ.h
///\brief ������������ ���� ������ ����������� COM - �������
#pragma once
#ifndef _ULREGSERV_H__
#define _ULREGSERV_H__
#include <windows.h>

namespace ULCOMs
{
	///\class CULRegServ
	///\brief ����� ����������� COM - �������
	class CULRegServ
	{
	protected:
		///\brief ������ CLSID 
		enum
		{
			CLSID_STRING_SIZE=39
		};
		///\brief ������������ CLSID � ��������� ����������
		///\param clsid - ������������� ������
		///\param szCLSID - ��������� ����������
		///\param nLen - ����� ��������� ����������
		void CLSIDtoTCHAR(const CLSID& clsid,
			LPTSTR szCLSID,
			int nLen);
		///\brief ������ ���� � �������� ��� ��������
		///\param szKey - ������� ����
		///\param szSubkey - ����������� ����
		///\param szValue - ���������� �������� �����
		///\return TRUE � ������ ������, ����� FALSE
		BOOL SetKeyAndValue(LPCTSTR szKey,
							LPCTSTR szSubkey,
							LPCTSTR szValue);
		///\brief ������� �������� ���� � ��� ��� ��������
		///\param hKeyParent - ������������ ����
		///\param lpszKeyChild - ��������� �������� ���� 
		///\return ��� �������� �� ������� �������
		LONG RecursiveDeleteKey(HKEY hKeyParent,LPCTSTR lpszKeyChild); 
	public:
		///\brief �����������
		CULRegServ(void);
		///\brief ����������
		virtual ~CULRegServ(void);
		///\brief ������� ������������� ��� ����������� ����������. ���������� � DllRegisterServer.
		///\param hModule - ����� ������
		///\param clsid - ������������� ����������
		///\param szFriendlyName - ������������� ��� ����������
		///\param szVerIndProgID - �� ��������� �� ������ ProgID
		///\param szProgID - "�������������" �������������(����� ������ ��������)
		///\return ��� �������� ������� �������
		HRESULT RegisterServer(HMODULE hModule, 
							   const CLSID& clsid, 
							   LPCTSTR szFriendlyName,
							   LPCTSTR szVerIndProgID,
							   LPCTSTR szProgID);
		///\brief ������� ������������� ��� ������������� ����������. ���������� � DllUnregisterServer.
		///\param clsid - ������������� ����������
		///\param szVerIndProgID - �� ��������� �� ������ ProgID
		///\param szProgID - "�������������" �������������(����� ������ ��������)
		///\return ��� �������� ������� �������
		HRESULT UnregisterServer(const CLSID& clsid,
								 LPCTSTR szVerIndProgID,
								 LPCTSTR szProgID) ;
	};
}
#endif//_ULREGSERV_H__