///\file ULQueueThread.h
///\brief ������������ ���� ������ ������ � ��������(27.08.2007)
#pragma once
#ifndef __ULQUEUETHREAD__H_
#define __ULQUEUETHREAD__H_
#include "ULMessageMap.inl"
#include "ULThread.h"
namespace ULThreads
{
	///\class CULQueueThread
	///\brief ����� ������ � ��������(27.08.2007)
	class CULQueueThread:public CULThread
	{
	private:
		///\brief ����� ������� ������� ����� ���������
		HANDLE m_hStartedEvent;
	protected:
		///\brief ������� ������
		static DWORD ThreadProc(LPVOID param);
		///\brief ������ ������ ���������� � ��������� ���������.
		///C�������� ����������� � ������������ ������
		CULMessageMap<CULQueueThread> MessageMap;
	public:
		///\brief �����������
		CULQueueThread(void);
		///\brief ����������
		virtual ~CULQueueThread(void);
		///\brief ������ �����
		///\param lpThreadAttributes �������� �������
		///\param dwStackSize ������ �����
		///\param dwCreationFlags ����
		///\return TRUE � ������ ������
		BOOL Create(LPSECURITY_ATTRIBUTES lpThreadAttributes=NULL,
			SIZE_T dwStackSize=0,
			DWORD dwCreationFlags=CREATE_SUSPENDED);
	};
}
#endif//__ULQUEUETHREAD__H_