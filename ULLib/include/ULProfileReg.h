///\file ULProfileReg.h
///\brief ������������ ���� ������ ������� ���������� � �������(17.08.2007)
#pragma once
#ifndef __UL_ULPROFILE_REG_H__
#define __UL_ULPROFILE_REG_H__
#include <windows.h>
namespace ULOther
{
	///\class CULProfileReg
	///\brief ����� ������� ���������� � �������(17.08.2007)
	class CULProfileReg
	{
	protected:
		///\brief ����� ����� ������� ����������
		HKEY m_hAppKey;
		///\brief ���� ������, ���� TRUE �� ��������� ��� �������� � HKEY_LOCAL_MACHINE
		BOOL m_fAllUsers;
		///\brief ������� ��� ��������� ����� ������� ������
		///\param pcszSection - ��� ������
		///\param ����������: ����� ������
		HKEY GetSectionKey(LPCTSTR pcszSection);
	public:
		///\brief ����������� 
		CULProfileReg();
		///\brief ����������
		~CULProfileReg();
		///\brief ������� ��� �������� ������ �������� � ��������� ����������
		///\param pcszCompanyName - ��� ��������
		///\param pcszAppName - ��� ����������
		///\param fAllUsers - ������������ ������������ ��� ���� �������������
		///\return ����������: TRUE � ������ ������, ����� FALSE
		BOOL SetRegistryKey(LPCTSTR pcszCompanyName,LPCTSTR pcszAppName,BOOL fAllUsers=FALSE);
		///\brief ������� ��� ������ ���������� ��������� � ��������� ������
		///\param pcszSection - ��� ������
		///\param pcszEntry - ��� ���������(������)
		///\param pcszValue - ��������(������)
		///\return ����������: TRUE � ������ ������, ����� FALSE
		BOOL WriteProfileString(LPCTSTR pcszSection,LPCTSTR pcszEntry,
			LPCTSTR pcszValue);
		///\brief ������� ��� ������ ��������� ��������� � ��������� ������
		///\param pcszSection - ��� ������
		///\param pcszEntry - ��� ���������(�����)
		///\param nValue - ��������(�����)
		///\return ����������: TRUE � ������ ������, ����� FALSE
		BOOL WriteProfileInt(LPCTSTR pcszSection, LPCTSTR pcszEntry,int nValue);
		///\brief ������� ��� ������ ���������� ��������� � ��������� ������
		///\param pcszSection - ��� ������
		///\param pcszEntry - ��� ���������(������)
		///\param pszValue - ��������� �� ������������ ��������(������)
		///\param lpdwValLen - ������ pcszValue
		///\return ����������: TRUE � ������ ������, ����� FALSE
		BOOL GetProfileString(LPCTSTR pcszSection, LPCTSTR pcszEntry,
			LPTSTR pszValue,LPDWORD lpdwValLen);
		///\brief ������� ��� ������ ��������� ��������� � ��������� ������
		///\param pcszSection - ��� ������
		///\param pcszEntry - ��� ���������(�����)
		///\param pdwValue - ��������� �� ������������ ��������(�����)
		///\return ����������: TRUE � ������ ������, ����� FALSE
		BOOL GetProfileInt(LPCTSTR pcszSection, LPCTSTR pcszEntry,DWORD* pdwValue);
		///\brief ������� ��� ���������� ���������� ���� � �������
		///\param pcszName - ��� ���������
		///\param pcszFilePath - ���� � �����(���� NULL,�� ��� pcszName ��������)
		///\return  ����������: TRUE � ������ ������, ����� FALSE
		BOOL AddToAutoRun(LPCTSTR pcszName,LPCTSTR pcszFilePath);
		///\brief ��������� ������ �������
		void Close();
		///\brief ����������� ����� �� ������ 
		///\return �����
		inline HKEY Detach()
			{HKEY hRetKey=m_hAppKey;m_hAppKey=NULL;return hRetKey;}
	};
}
#endif//__UL_ULPROFILE_REG_H__
