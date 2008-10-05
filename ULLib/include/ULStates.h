///\file ULStates.h
///\brief ������������ ���� ������������ ���� ������� ��������� ������,������� 
///���������� � ���-�����(21.07.2007)
#pragma once
#ifndef __STATES__H_
#define __STATES__H_

#include <windows.h>
#include <stdio.h>
#include <crtdbg.h>
#include <TCHAR.H>
#include "ULOther.h"
#include "ULRes.h"
///\namespace ULStates
/*!\brief ������������ ���� ������� ��������� ������,������� 
���������� � ���-�����(21.07.2007)*/
namespace ULStates
{
	///\class CULMemState
	///\brief ����� ��� ������������ ������ ������(2006)
	class CULMemState
	{
	protected:
		///\brief ��������� �������� ������ ������ ��� ������ MemCkeck
		_CrtMemState m_OldState;
		///\brief ��������� �������� ������ ������ ��� ������ MemVerify
		_CrtMemState m_NewState;
	public:
		///\brief ������� ������ ��������� ������ ������ � ��������� � m_OldState
		void MemCkeck()
		{
			_CrtMemCheckpoint(&m_OldState);
		};
		/*!\brief ������� ������ ��������� ������ ������ � ���������
		� m_NewState, � ����� ���������� � m_OldState*/
		///\return ���������� ��������������� ������
		int MemVerify()
		{
			_CrtMemCheckpoint(&m_NewState);
			if(_CrtMemDifference(&m_NewState, &m_OldState, &m_NewState)!=0)
				return int(m_NewState.lSizes[1]);
			else
				return 0;
		}
		///\brief ������� ���������� ���������� ��������������� ������
		///\return ���������� ��������������� ������
		int GetLeak()
		{
			return (int)m_NewState.lSizes[1];
		}
	};
}
	//=============================================
	//������� ��� ������� ��
	//=============================================
	#ifdef _DEBUG
		#include <stdio.h>
		/*!\brief ������ ������ CULMemState ��� ������ �������� 
		MEM_CHECK � MEM_VERIFY*/
		static ULStates::CULMemState m_MemProtect;
		///\brief ������� ������ ��������� ������ ������
		#define MEM_CHECK	m_MemProtect.MemCkeck();
		/*!\brief ������� ������ �������� ������ ������ � � ������
		������ ������� MessageBox*/
		#define MEM_VERIFY			if(m_MemProtect.MemVerify()!=0){ \
									char buffer[MAX_PATH];			\
									_stprintf_s(buffer,_T("�������������� ������ %d ����(�)"),int(m_MemProtect.GetLeak()));\
									::MessageBox(0,buffer,_T("������ ������!"),MB_ICONHAND);};

	#else
		///\brief ������� ������ ��������� ������ ������
		#define MEM_CHECK 
		/*!\brief ������� ������ �������� ������ ������ � � ������
		������ ������� MessageBox*/
		#define MEM_VERIFY 
	#endif //_DEBUG

namespace ULStates
{
	///\class CULTimeState
	/*!\brief ����� ��� ����������� ������� ���������� ����
	� ������ ����������� ���������������, 
	�.�. ������ ���������� ������ ������� (2006)*/
	class CULTimeState
	{
	protected:
		///\brief ��������� ���������� �������
		FILETIME ftKernelTimeStart, ftKernelTimeEnd; 
		///\brief �������� ���������� �������
		FILETIME ftUserTimeStart, ftUserTimeEnd; 
		FILETIME ftDummy; 
		///\brief ������� ��� �������� �� FILETIME � _int64
		///\param pFT - FILETIME
		///\return ������ � _int64
		_int64 FileTimeToQuadWord(FILETIME* pFT)
		{
			return ((unsigned long long(pFT->dwHighDateTime)<<32)|pFT->dwLowDateTime);
		};
	public:
		///\brief �����������
		///\������������ ��������� ������� �������
		CULTimeState()
		{
			TimeCheck();
		};
		///������� ��� ����������� ���������� ������� �������
		///\return TRUE � ������ ������
		BOOL TimeCheck()
		{
			// �������� ��������� ���������� ������� 
			return ::GetThreadTimes(::GetCurrentThread(), &ftDummy, &ftDummy, 
				&ftKernelTimeStart, &ftUserTimeStart);
		};
		///\brief ������� ��� ��������� ��������� ������� ������� � ��������� � ���������
		///\return ����� � ������������
		double TimeVerify()
		{
			_int64 qwKernelTimeElapsed, qwUserTimeElapsed, qwTotalTimeElapsed; 
			// �������� �������� ���������� ������� 
			::GetThreadTimes(::GetCurrentThread(), &ftDummy, &ftDummy, 
				&ftKernelTimeEnd, &ftUserTimeEnd); 
			// �������� ����� �����, ��������� ����� ���������� ���� � User 
			qwKernelTimeElapsed = FileTimeToQuadWord(&ftKernelTimeEnd) - FileTimeToQuadWord(&ftKernelTimeStart); 
			qwUserTimeElapsed = FileTimeToQuadWord(&ftUserTimeEnd) - FileTimeToQuadWord(&ftUserTimeStart); 
			qwTotalTimeElapsed = qwKernelTimeElapsed + qwUserTimeElapsed; 
			//���������� � ��
			return (double(qwTotalTimeElapsed)/10000);
		};
	};
	///\class CULWatchState
	/*!\brief ����� ��� ����������� ������� ���������� ����
	��� ����� ����������� ��������������� (2006)*/
	class CULWatchState
	{ 
	protected:
		///\brief ���������� �������� � ������� 
		LARGE_INTEGER m_liPerfFreq; 
		///\brief ��������� ������ 
		LARGE_INTEGER m_liPerfStart; 
	public: 
		///\brief �����������
		///������������� ��������� ������� �������
		CULWatchState() 
		{ 
			WatchCheck(); 
		} 
		///\brief ������� ��� ����������� ���������� ������� �������
		///\return TRUE � ������ ������
		BOOL WatchCheck() 
		{
			QueryPerformanceFrequency(&m_liPerfFreq); 
			return QueryPerformanceCounter(&m_liPerfStart); 
		};
		/*!\brief ������� ��� ��������� ��������� ������� �������
			� ��������� � ���������
			���������� ����� ����������� ����� ������ WatchCheck */
		double WatchVerify() const 
		{ 

			LARGE_INTEGER liPerfNow; 
			QueryPerformanceCounter(&liPerfNow); 
			return (double((liPerfNow.QuadPart - m_liPerfStart.QuadPart) * 1000) /m_liPerfFreq.QuadPart); 
		} 
	}; 
	///\class CULLogFile
	/*!\brief ����� ��� ������� ����������� ����:
		������ ������ � ������� ���������� ����(2006)*/
	class CULLogFile
	{
	protected:
		///\brief ��������� ��� �������� ����� ����
		///\param lfdMemState - ������ �� ������� ������
		///\param lfdTimeState - ������ �� �������� ����������
		///\param lfdszName - ��� ���� ����
		struct tagLogFileData
		{
			CULMemState lfdMemState;
			CULTimeState lfdTimeState;
			CULWatchState lfdWatchState;
			TCHAR* lfdszName;
		};
		///\brief ������ �������� ��� �������� ����� ����
		ULOther::CULArr<tagLogFileData> m_pLogFileData;
		///\brief ��������� ������������� ����� ����
		FILE* m_LogFile;
	public:
		///\brief �����������
		CULLogFile():
		m_pLogFileData(NULL)
		{
			//����������� ����������������� �����
			TCHAR szPath[5][MAX_PATH];
			::GetModuleFileName(ULOther::ULGetResourceHandle(),szPath[0],MAX_PATH);
			 _tsplitpath_s(szPath[0],szPath[1],MAX_PATH,szPath[2],MAX_PATH,szPath[3],MAX_PATH,szPath[4],MAX_PATH);
			//��� ����� ���� = ��� ������������ �����.log
			_tcscat_s(szPath[3],MAX_PATH,szPath[4]);
			_tcscat_s(szPath[3],MAX_PATH,_T(".log"));
			_tfopen_s(&m_LogFile,szPath[3],_T("w+"));
#ifdef UNICODE
			unsigned short usLittleEndian=0xfeff;
			fwrite(&usLittleEndian,2,1,m_LogFile);
#endif
		};
		///\brief ����������
		~CULLogFile()
		{
			fclose(m_LogFile);
		}
		///\brief ������� ��������� ���� ����
		///\param szLogName ��� ���� ����
		///\return TRUE � ������ ������
		BOOL AddLog(TCHAR* szLogName)
		{
			if(ResetLog(szLogName))
				return FALSE;
			m_pLogFileData.Resize(m_pLogFileData.GetSize()+1);
			if(m_pLogFileData!=NULL)
			{
				m_pLogFileData[m_pLogFileData.GetSize()-1].lfdMemState.MemCkeck();
				m_pLogFileData[m_pLogFileData.GetSize()-1].lfdTimeState.TimeCheck();
				m_pLogFileData[m_pLogFileData.GetSize()-1].lfdWatchState.WatchCheck();
				m_pLogFileData[m_pLogFileData.GetSize()-1].lfdszName=szLogName;
				return TRUE;
			}
			else
				return FALSE;
		};
		///\brief ������� ���������� ���� ����
		///\param szLogName ��� ���� ����
		///\return TRUE � ������ ������
		BOOL ResetLog(TCHAR* szLogName)
		{
			for(unsigned int i=0;i<m_pLogFileData.GetSize();i++)
				if((_tcsspn(m_pLogFileData[i].lfdszName,szLogName)==0)&&
					(_tcslen(m_pLogFileData[i].lfdszName)==_tcslen(szLogName)))
				{
					m_pLogFileData[i].lfdMemState.MemCkeck();
					m_pLogFileData[i].lfdTimeState.TimeCheck();
					m_pLogFileData[i].lfdWatchState.WatchCheck();
					return TRUE;
				}
			return FALSE;
		};
		///\brief ������� ��������� ���� ����
		///\param szLogName ��� ���� ����
		///\return TRUE � ������ ������
		BOOL SaveLog(TCHAR* szLogName)
		{
			for(unsigned int i=0;i<m_pLogFileData.GetSize();i++)
				if((_tcscmp(m_pLogFileData[i].lfdszName,szLogName)==0))
				{
					TCHAR szSaveLog[MAX_PATH];
					_stprintf_s(szSaveLog,MAX_PATH,_T("%s: ������ ������ %d ����,����� ���������� %.3f ��,������ ����� %.3f ��\r"),
						m_pLogFileData[i].lfdszName,
						//��������� �� ���� �������� LOGFILEDATA
						m_pLogFileData[i].lfdMemState.MemVerify()-(m_pLogFileData.GetSize()-1-i)*sizeof(tagLogFileData),
						m_pLogFileData[i].lfdTimeState.TimeVerify(),
						m_pLogFileData[i].lfdWatchState.WatchVerify());
					fwrite(szSaveLog,_tcslen(szSaveLog)*sizeof(TCHAR),1,m_LogFile);
					return TRUE;
				}
			return FALSE;
		}
	};
}	//=============================================
	//������� ��� ������� ��(2006)
	//=============================================
	#ifdef _DEBUG
		/*!\brief ������ ������ CULLogFile ��� ������ �������� 
		LOGFILE_ADD, LOGFILE_RESET � LOGFILE_SAVE*/
		template <typename T>
		T &GetLogFile()
		{
			static T g_LogFile;
			return g_LogFile;
		}
		///\brief ������ ��������� ���� ����
		#define LOGFILE_ADD(szLogName)		\
			GetLogFile<ULStates::CULLogFile>().AddLog(szLogName);
		///\brief ������ ���������� ���� ����
		#define LOGFILE_RESET(szLogName)	\
			GetLogFile<ULStates::CULLogFile>().ResetLog(szLogName);
		///\brief ������� ��������� ���� ����
		#define LOGFILE_SAVE(szLogName)		\
			GetLogFile<ULStates::CULLogFile>().SaveLog(szLogName);
		///\brief ����������� �������
		#define ASSERT assert
	#else
		///\brief ������ ��������� ���� ����
		#define LOGFILE_ADD(szLogName)
		///\brief ������ ���������� ���� ����
		#define LOGFILE_RESET(szLogName)
		///\brief ������� ��������� ���� ����
		#define LOGFILE_SAVE(szLogName)
		///\brief ����������� �������
		#define ASSERT
	#endif //_DEBUG

#endif //__STATES__H_