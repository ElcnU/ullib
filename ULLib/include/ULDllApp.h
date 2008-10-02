///\file ULDllApp.h
///\brief ������������ ���� ������ ������������ ����������(03.01.2007)
#pragma once
#ifndef __ULDLLAPP__H_
#define __ULDLLAPP__H_
#include <windows.h>
#include "ULWnd.h"
namespace ULApps
{
	///\class CULDllApp
	///\brief ����������� ����� ������������ ����������(03.01.2007)
	class CULDllApp
	{
		///\brief ��� ������� �� DllMain
		static CULDllApp* m_pULDllApp;
	public:
		///\brief �����������
		CULDllApp(void);
		///\brief ����������
		virtual ~CULDllApp(void);
		///\brief HINSTANCE ����������, ������������ � WinMain
		static HINSTANCE m_hInstance;
		///\brief ���������� ��� �������� ��� ���������
		virtual BOOL ProcessAttach(HINSTANCE hInstance);
		///\brief ���������� ��� �������� ��� ���������
		virtual BOOL ProcessDetach();
		///\brief ���������� ��� ������������� ��� �������
		virtual BOOL ThreadAttach();
		///\brief ���������� ��� �������� ��� �������
		virtual BOOL ThreadDetach();
		///\brief ������� DllMain ������� ������� CULDllApp, ���� 
		///��� ����������� ������������� ����� � ������ 
		///������� �� ���� ���������� �����������
		BOOL DllMain(HINSTANCE /*hinstDLL*/,
			DWORD /*fdwReason*/);
		///\brief ������ ��� ��������� ��������� �� ����� ����������
		///�� ������ ������
		static CULDllApp* GetULDllApp(void);
	};
}
///\brief ���������� ������� DllMain
#define UL_DECLARE_DLLMAIN \
	BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID /*lpvReserved*/)\
		{return ULApps::CULDllApp::GetULDllApp()->DllMain(hinstDLL,fdwReason);}

	
#endif//__ULDLLAPP__H_