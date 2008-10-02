///\file ULThreads.h
///\brief ������������ ���� ������������ ��� ULThreads � ��������� ����� ����������� ������(27.08.2007)
#pragma once
#ifndef __ULTHREADS__H_
#define __ULTHREADS__H_

#include "ULQueueThread.h"
///\namespace ULThreads
///\brief ������������ ��� ������� ��������� � �������� � 	�� ��������������(27.08.2007)
namespace ULThreads
{
	///\class CULCriticalSection
	///\brief ����� ����������� ������(27.08.2007)
	class CULCriticalSection
	{
	private:
		///\brief ID ����������� ������
		CRITICAL_SECTION m_CS;
	public:
		///\brief �����������
		CULCriticalSection()
		{
			::InitializeCriticalSection(&m_CS);
		}
		///\brief ����������
		virtual ~CULCriticalSection()
		{
			::DeleteCriticalSection(&m_CS);
		}
		///\brief ���� � ����������� ������
		inline void Enter()
		{
			::EnterCriticalSection(&m_CS);
		}
		///\brief ����� �� ����������� ������
		inline void Leave()
		{
			::LeaveCriticalSection(&m_CS);
		}
		///\brief ������� ������������ ����������� ������
		///\param dwSeconds - ����� � ��������
		///\return TRUE, ���� ����� ��������� 
		///	�� ��������� ��������� �������
#if(_WIN32_WINNT >= 0x0400)
		inline BOOL WaitEnter(DWORD dwSeconds)
		{
			while(!TryEnter()&&(dwSeconds--))
				Sleep(1000);
			return (dwSeconds!=0);
		}
#endif
		///\brief �������� ����������� ������
		///\return FALSE, ���� ����������� ������ ��������
		///	TRUE, ���� ���� ����������� ���� � ����������� ������
#if(_WIN32_WINNT >= 0x0400)
		inline BOOL TryEnter()
		{
			return ::TryEnterCriticalSection(&m_CS);
		}
#endif
	};
	///\class CULEvent
	///\brief ����� �������(11.10.2007)
	class CULEvent
	{
	private:
		///\brief ���� ��� ��������� � ��� ��� ������� �������
		BOOL m_fExists;
	protected:
		///\brief ����� �������
		HANDLE m_hEvent;
	public:
		///\brief �����������
		CULEvent():m_hEvent(NULL),m_fExists(FALSE){}
		///\brief ����������� �����������
		CULEvent(HANDLE hEvent):m_hEvent(hEvent),m_fExists(FALSE){}
		///\brief ����������
		inline virtual ~CULEvent(){}
		///\brief ��� ����������� ������� ������ ��� ��� ��������� 
		///������ HANDLE
		inline operator HANDLE() const{return m_hEvent;}
		///\brief ������ �������
		///\param fManualReset - ���� TRUE, �� ���������� �������� ��� ������ ResetEvent
		///\param fInitialState - �������� ��������� ������� ��� �������� 
		///\param lpName - ��� ��� �������, �������������� �������
		///\param lpEventAttributes - ������ � NULL
		///\return TRUE � ������ ������,����� FALSE 
		inline BOOL Create(LPCTSTR lpName=NULL,
			BOOL fManualReset=FALSE,
			BOOL fInitialState=FALSE,
			LPSECURITY_ATTRIBUTES lpEventAttributes=NULL)
		{
			m_hEvent=::CreateEvent(lpEventAttributes,fManualReset,fInitialState,lpName);
			m_fExists=(::GetLastError()==ERROR_ALREADY_EXISTS);
			return(m_hEvent!=NULL);
		}
		///\brief ������� � ��� ��� ������� ��� �������(����� ������ CreateEvent)
		///\return TRUE � ������ ���������� �������
		inline BOOL IsAlraedyExists()
			{return m_fExists;};
		///\brief ��������� ����� ��������� �������
		///\param lpName - ��� �������
		///\param dwDesiredAccess - ����� �������
		///\param bInheritHandle - ���� ������������ ������� �������� ���������
		///\return TRUE � ������ ������, ����� FALSE
		BOOL Open(LPCTSTR lpName,DWORD dwDesiredAccess=EVENT_ALL_ACCESS,BOOL bInheritHandle=FALSE)
			{return ((m_hEvent=::OpenEvent(dwDesiredAccess,bInheritHandle,lpName))!=NULL);};
		///\brief ������� ������������� �������
		///\return TRUE � ������ ������,����� FALSE 
		inline BOOL Set()
			{return ::SetEvent(m_hEvent);}
		///\brief ������� ���������� �������
		///\return TRUE � ������ ������,����� FALSE 
		inline BOOL Reset()
			{return ::ResetEvent(m_hEvent);}
		///\brief ��������� ��������� �������
		///\return TRUE ���� �����������, ����� FALSE
		inline BOOL CheckEvent()
			{return Wait(0);}
		///\brief ������� ������� ������� � ������������� ���������
		///\param dwMillisecond - ����� �������� � ��
		///\return TRUE ���� �� ������������� ����� ������� ������������, ����� FALSE
		inline BOOL Wait(DWORD dwMillisecond=INFINITE)
			{return (::WaitForSingleObject(m_hEvent,dwMillisecond)==WAIT_OBJECT_0);}
		///\brief ��������� �������
		///\return TRUE � ������ ������,����� FALSE 
		inline BOOL Close()
			{return ::CloseHandle(m_hEvent);}
	};
	///\class CULMutex
	///\brief ����� �������(11.10.2007)
	class CULMutex
	{
	private:
		///\brief ���� ��� ��������� � ��� ��� ������ ������
		BOOL m_fExists;
	protected:
		///\brief ����� �������
		HANDLE m_hMutex;
	public:
		///\brief �����������
		CULMutex():m_hMutex(NULL){}
		///\brief ����������� �����������
		CULMutex(HANDLE hMutex):m_hMutex(hMutex){}
		///\brief ����������
		inline virtual ~CULMutex(){}
		///\brief ��� ����������� ������� ������ ��� ��� ��������� 
		///������ HANDLE
		inline operator HANDLE() const{return m_hMutex;}
		///\brief ������ ������
		///\param lpName - ��� ��� �������, �������������� ��������
		///\param fInitialOwner - �������� ��������� ������� ��� �������� 
		///\param lpEventAttributes - ������ NULL
		///\return TRUE � ������ ������,����� FALSE 
		inline BOOL Create(LPCTSTR lpName=NULL,
			BOOL fInitialOwner=FALSE,
			LPSECURITY_ATTRIBUTES lpEventAttributes=NULL)
		{
			m_hMutex=::CreateMutex(lpEventAttributes,fInitialOwner,lpName);
			m_fExists=(::GetLastError()==ERROR_ALREADY_EXISTS);
			return(m_hMutex!=NULL);
		}
		///\brief ������� � ��� ��� ������ ��� ������(����� ������ CreateMutex)
		///\return TRUE � ������ ���������� �������
		inline BOOL IsAlraedyExists()
			{return m_fExists;};
		///\brief ��������� ����� ��������� ������
		///\param lpName - ��� �������
		///\param dwDesiredAccess - ����� �������
		///\param bInheritHandle - ���� ������������ ������� �������� ���������
		///\return TRUE � ������ ������, ����� FALSE
		BOOL Open(LPCTSTR lpName,DWORD dwDesiredAccess=EVENT_ALL_ACCESS,BOOL bInheritHandle=FALSE)
			{return ((m_hMutex=::OpenMutex(dwDesiredAccess,bInheritHandle,lpName))!=NULL);};
		///\brief ������� ����������� ������
		///\return TRUE � ������ ������,����� FALSE 
		inline BOOL Release()
			{return ::ReleaseMutex(m_hMutex);}
		///\brief ��������� ��������� �������
		///\return TRUE ���� �����������, ����� FALSE
		inline BOOL CheckMutex()
		{
			BOOL fRet=Wait(0);
			if(fRet)
				Release();
			return fRet;
		}
		///\brief ������� ������� ������� � ������������� ���������
		///\param dwMillisecond - ����� �������� � ��
		///\return TRUE ���� �� ������������� ����� ������ �����������, ����� FALSE
		inline BOOL Wait(DWORD dwMillisecond=INFINITE)
			{return (::WaitForSingleObject(m_hMutex,dwMillisecond)==WAIT_OBJECT_0);}
		///\brief ��������� ������
		///\return TRUE � ������ ������,����� FALSE 
		inline BOOL Close()
			{return ::CloseHandle(m_hMutex);}
	};
}
#endif //__ULTHREADS__H_
