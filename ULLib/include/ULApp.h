///\file ULApp.h
///\brief ������������ ���� ������ ����������(01.05.2007)
#pragma once
#ifndef __ULAPP__H_
#define __ULAPP__H_
#include <windows.h>
#include "ULWnd.h"
namespace ULApps
{
	///\class CULApp
	///\brief ����������� ����� ����������(01.05.2007)
	class CULApp
	{
		///\brief ��� ������� �� WinMain
		static CULApp* m_pULApp;
	public:
		///\brief �����������
		CULApp(void);
		///\brief ����������
		virtual ~CULApp(void);
		///\brief HINSTANCE ����������, ������������ � WinMain
		HINSTANCE m_hInstance;
		///\brief ��������� ������ �������, ������������ � WinMain
		LPSTR m_lpCmdLine;
		///\brief ��� GUI, ������������ � WinMain
		int m_nCmdShow;
		///\brief ��������� �� ������� ����, ��� ����� ���������
		ULWnds::CULWnd* m_pMainWnd;
		///\brief ������ ����� ��������� ������ PreTranslateMessage
		CULMessageMap<ULWnds::CULWnd> MessageMap;
		///\brief ����� ���� WH_GETMESSAGE
		HHOOK m_hGetMessageHook;
		///\brief ������� WinMain ������� ������� CULApp, ���� 
		///��� ����������� ������������� ����� � ������ 
		///������� �� ���� ���������� �����������
		friend int APIENTRY WinMain(HINSTANCE hInstance,
						 HINSTANCE /*hPrevInstance*/,
						 LPSTR lpCmdLine,
						 int nCmdShow);
		///\brief ������ ��� ������������� ����������
		virtual BOOL InitInstance()=0;
		///\brief ������� ���������� ����� TranslateMessage
		///\param pMsg - ��������� ���������
		///\return TRUE ���� ��������� ������ ���� ���������� ������������ ���������
		virtual BOOL Run(MSG* pMsg);
		///\brief ��������� ���� ���������
		virtual void MessageLoop();
		///\brief ����������� ������� ���������
		void ProcessMessages();
		///brief ������� ��������� ������� ��������� (��� ���� WH_GETMESSAGE)
		static LRESULT CALLBACK GetMsgProc(int /*code*/, WPARAM /*wParam*/, LPARAM /*lParam*/);
		///\brief ������ ��� ��������� ��������� �� ����� ����������
		///�� ������ ������
		static CULApp* GetULApp(void);
	};
}
#endif//__ULAPP__H_