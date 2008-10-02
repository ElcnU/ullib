///\file ULThread.h
///\brief ������������ ���� ������ ������ (03.10.2007)
//�����������, ���������� ������������ ������� ������������
#pragma once
#ifndef __ULTHREAD__H_
#define __ULTHREAD__H_
#include <windows.h>
namespace ULThreads
{
	///\class CULThread
	///\brief ����� ������(27.08.2007)
	class CULThread
	{
	private:
		///\brief ����, ��������� ������
		///	���� FALSE, �� ����������� ��������� ������ ������
		///	���������� ��������� ���� ������
		volatile BOOL m_fRunThread;
	protected:
		///\brief ������� ������
		static unsigned WINAPI ThreadProc(LPVOID param);
		///\brief ������� �������
		///\return FALSE, ���� ������� ��������� ������ ������
		virtual BOOL Run();
	public:
		///\brief ����� ������
		HANDLE m_hThread;
		///\brief ID ������
		DWORD m_dwThreadId;
	public:
		///\brief �����������
		CULThread(void);
		///\brief ����������
		virtual ~CULThread(void);
		///\brief ������ �����
		///\param lpThreadAttributes �������� �������
		///\param dwStackSize ������ �����
		///\param dwCreationFlags ����
		///\return TRUE � ������ ������
		BOOL Create(LPSECURITY_ATTRIBUTES lpThreadAttributes=NULL,
			unsigned int uiStackSize=0,
			DWORD dwCreationFlags=CREATE_SUSPENDED);
		///\brief ��������� ���������� ������
		///\param dwMilliseconds - ����� � ������������� �������� ���������� ������
		///\return TRUE, ���� ����� ���������� ��������
		virtual BOOL Quit(DWORD dwMilliseconds);
		///\brief ���������� ��������� ������
		///\param Msg ���������
		///\param wParam �������� 1
		///\param lParam �������� 2
		///\return TRUE � ������ ������
		inline BOOL PostThreadMessage(UINT Msg,WPARAM wParam=0,LPARAM lParam=0)
			{return ::PostThreadMessage(m_dwThreadId,Msg,wParam,lParam);};
		///\brief ���������������� �����
		///\return TRUE � ������ ������
		inline BOOL SuspendThread()
			{return (::SuspendThread(m_hThread)!=-1); };
		///\brief ���������������� �����
		///\return TRUE � ������ ������
		inline BOOL ResumeThread()
			{return (::ResumeThread(m_hThread)!=-1);};
		///\brief ������������� ���������
		///\param nPiority ���������
		///\return TRUE � ������ ������
		inline BOOL SetThreadPriority(int nPiority)
			{return ::SetThreadPriority(m_hThread,nPiority);};
		///\brief ���������� ����� ������
		inline operator HANDLE() const{return m_hThread;};
		inline BOOL IsRun()
			{return m_fRunThread;}
	};
}
#endif//__ULTHREAD__H_