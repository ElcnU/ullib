///\file ULMessageMap.inl
///\brief ������������ ���� ������ ����������� ��������� ����(23.10.2007)
#pragma once
#ifndef __UL_MESSAGEMAP_H__
#define __UL_MESSAGEMAP_H__
#include <windows.h>
#include "ULOther.h"
#include <assert.h>
///\class CULMessageMap
///\brief ����� ����������� ��������� ����
///\param CULClass_t - ����� ��������, ��� ��� �������, \n
///������� ���������� CULMessageMap
///\note ��������� ������ ����������� � ������������ ������ ���� \n
/// ��� ������ ������ Add... . \n
/// ��� ���������� ���������� ��������������� ������ � ������������� \n
/// � ������������ ��������� �������� ������� �������� ��������� \n
/// ���� ������ ��������������� ������� Clear...
template <class CULClass_t>
class CULMessageMap
{
private:
	///\brief ��� ������� ����������� ���������
	typedef LRESULT(CULClass_t::*MSGPROC)(WPARAM,LPARAM);
	///\brief ��� ������� ����������� ������ �� ���������
	typedef void(CULClass_t::*CMDPROC)(WORD,HWND);
	///\brief ��� ������� ����������� ������ �� ������������
	typedef LRESULT(CULClass_t::*NOTIFYPROC)(LPARAM);
	///\brief ��� ������� ����������� ������ �� ���������, � ����� �� ���������
	typedef LRESULT(CULClass_t::*REFLECTCMDPROC)();
	///\brief ��� ������� ���������� ����� ���������� ���������
	typedef BOOL(CULClass_t::*PRETRANSLATEMESSAGEPROC)(MSG* pMsg);

	///\brief ���������, ���������� ���������� �� ����������� ���������
	///\param msMsgID - ID ���������
	///\param msMsgProc - ��������� �� ������� ����������
	struct tagMessageStorage
	{
		DWORD msMsgID;			
		MSGPROC msMsgProc;
	};
	///\brief ������ ��������, ���������� ���������� �� ������������ ���������
	ULOther::CULArr<tagMessageStorage> m_pMessageStorage;
	///\brief ������ ��������, ���������� ���������� �������������� ������������ ���������
	ULOther::CULArr<tagMessageStorage> m_pReflectMessageStorage;
	///\brief C��������, ���������� ���������� �� ����������� ������� �� ��������
	///\param csNotifyCode - ��� ���������
	///\param csCtrlID - ������������� ��������
	///\param csCmdProc - ��������� �� ������� ����������
	struct tagCommandStorage
	{
		WORD csNotifyCode;
		WORD csCtrlID;			
		CMDPROC csCmdProc;		
	};
	///\brief ������ ��������, ���������� ���������� �� ������������ ������ �� ���������
	ULOther::CULArr<tagCommandStorage> m_pCommandStorage;
	///\brief C��������, ���������� ���������� �� ����������� ������� �� ��������
	///\param csNotifyCode - ��� ���������
	///\param csReflectCmdProc - ��������� �� ������� ����������
	struct tagReflectCommandStorage
	{
		WORD csNotifyCode;
		REFLECTCMDPROC csReflectCmdProc;		
	};
	///\brief ������ ��������, ���������� ���������� �� ������������ ������ �� ���������
	ULOther::CULArr<tagReflectCommandStorage> m_pReflectCommandStorage;
	///\brief C��������, ����������� ���������� �� ����������� ��������� �� ��������
	///\param nsNMHDR - �������� ���������� � ���������
	///\param nsNotifyProc - ��������� �� ������� ����������
	struct tagNotifyStorage
	{
		NMHDR nsNMHDR;			
		NOTIFYPROC nsNotifyProc;
	};
	///\brief ������ ��������, ���������� ���������� �� ������������ ��������� �� ���������
	ULOther::CULArr<tagNotifyStorage> m_pNotifyStorage;
	///\brief ������ ��������, ���������� ���������� �� ������������ ������������ ��������� �� ���������
	ULOther::CULArr<tagNotifyStorage> m_pReflectNotifyStorage;
	///\brief C��������, ����������� ���������� ������� ���������� ����� ���������� ���������
	///\param lpObject - ��������� �� ������ ��������� �������
	///\param lpPreTranslateMessageProc - ��������� �� �������
	struct tagPreTranslateMessageStorage
	{
		CULClass_t* lpObject;
		PRETRANSLATEMESSAGEPROC lpPreTranslateMessageProc;
	};
	///\brief ������ ��������, ����������� ���������� ������� ���������� ����� ���������� ���������
	ULOther::CULArr<tagPreTranslateMessageStorage> m_pPreTranslateMessageStorage;
public:
	///brief �����������
	CULMessageMap()
	{
		m_pMessageStorage.Resize(0);
		m_pReflectMessageStorage.Resize(0);
		m_pCommandStorage.Resize(0);
		m_pReflectCommandStorage.Resize(0);
		m_pNotifyStorage.Resize(0);
		m_pReflectNotifyStorage.Resize(0);
		m_pPreTranslateMessageStorage.Resize(0);
	};
	///brief ����������� �����������
	CULMessageMap(CULMessageMap<CULClass_t>& MessageMap):
		m_pMessageStorage(MessageMap.m_pMessageStorage),
		m_pReflectMessageStorage(MessageMap.m_pReflectMessageStorage),
		m_pCommandStorage(MessageMap.m_pCommandStorage),
		m_pReflectCommandStorage(MessageMap.m_pReflectCommandStorage),
		m_pNotifyStorage(MessageMap.m_pNotifyStorage),
		m_pReflectNotifyStorage(MessageMap.m_pReflectNotifyStorage),
		m_pPreTranslateMessageStorage(MessageMap.m_pPreTranslateMessageStorage)
	{
	}
	///\brief ����������
	~CULMessageMap(){};
	///\brief �������� �����������
	void operator=(CULMessageMap<CULClass_t>& MessageMap)
	{
		m_pMessageStorage=MessageMap.m_pMessageStorage;
		m_pReflectMessageStorage=MessageMap.m_pReflectMessageStorage;
		m_pCommandStorage=MessageMap.m_pCommandStorage;
		m_pReflectCommandStorage=MessageMap.m_pReflectCommandStorage;
		m_pNotifyStorage=MessageMap.m_pNotifyStorage;
		m_pReflectNotifyStorage=MessageMap.m_pReflectNotifyStorage;
		m_pPreTranslateMessageStorage=MessageMap.m_pPreTranslateMessageStorage;
	}
	///\brief ������� ������� � ������� ������������
	///\return TRUE, ���� ����������� ����
	BOOL IsAllowMessage()
		{return ((m_pMessageStorage.GetSize())||
			(m_pCommandStorage.GetSize())||(m_pNotifyStorage.GetSize()));}
	///\brief ������� ������� � ������� ������������ ������������ �������
	///\return TRUE, ���� ����������� ����
	BOOL IsAllowReflect()
		{return ((m_pReflectMessageStorage.GetSize())||
			(m_pReflectCommandStorage.GetSize())||(m_pReflectNotifyStorage.GetSize()));}
	///\brief ������� ��� ��������� ������������ ���������
	///	CULCurClass_t - ����� ����, � ������� ���������� ��������� ���������
	///\param MsgID - ID ���������
	///\param MsgProc - ��������� �� ������� ����������
	///\return TRUE � ������ ������
	template<class CULCurClass_t>
	BOOL AddMessage(WORD MsgID,LRESULT(CULCurClass_t::*MsgProc)(WPARAM,LPARAM))	
	{
		if(m_pMessageStorage.Resize(m_pMessageStorage.GetSize()+1)!=NULL)
		{
			m_pMessageStorage[m_pMessageStorage.GetSize()-1].msMsgProc=reinterpret_cast<MSGPROC>(MsgProc);
			m_pMessageStorage[m_pMessageStorage.GetSize()-1].msMsgID=MsgID;
			return TRUE;
		}
		else
			return FALSE;
	};
	///\brief ������� ��� ��������� ������������ ������������ ���������
	///	CULCurClass_t - ����� ����, � ������� ���������� ��������� ���������
	///\param MsgID - ID ���������
	///\param MsgProc - ��������� �� ������� ����������
	///\return TRUE � ������ ������
	template<class CULCurClass_t>
	BOOL AddReflectMessage(WORD MsgID,LRESULT(CULCurClass_t::*MsgProc)(WPARAM,LPARAM))	
	{
		if(m_pReflectMessageStorage.Resize(m_pReflectMessageStorage.GetSize()+1)!=NULL)
		{
			m_pReflectMessageStorage[m_pReflectMessageStorage.GetSize()-1].msMsgProc=reinterpret_cast<MSGPROC>(MsgProc);
			m_pReflectMessageStorage[m_pReflectMessageStorage.GetSize()-1].msMsgID=MsgID;
			return TRUE;
		}
		else
			return FALSE;
	};
	///\brief ������� ��� ��������� ������������ ������ �� ���������
	///	CULCurClass_t - ����� ����, � ������� ����������	��������� ���������
	///\param CtrlID - ������������� ��������
	///\param CmdProc - ��������� �� ������� ����������
	///\param wNotifyCode - ������������� ��������� �� ��������
	///\return TRUE � ������ ������
	template<class CULCurClass_t>
	BOOL AddCommand(WORD CtrlID,void(CULCurClass_t::*CmdProc)(WORD,HWND),WORD wNotifyCode=0)	
	{
		if(m_pCommandStorage.Resize(m_pCommandStorage.GetSize()+1)!=NULL)
		{
			m_pCommandStorage[m_pCommandStorage.GetSize()-1].csCtrlID=CtrlID;
			m_pCommandStorage[m_pCommandStorage.GetSize()-1].csCmdProc=reinterpret_cast<CMDPROC>(CmdProc);
			m_pCommandStorage[m_pCommandStorage.GetSize()-1].csNotifyCode=wNotifyCode;
			return TRUE;
		}
		else
			return FALSE;
	};
	///\brief ������� ��� ��������� ������������ ������������ ������ �� ���������
	///	CULCurClass_t - ����� ����, � ������� ����������	��������� ���������
	///\param ReflectCmdProc - ��������� �� ������� ����������
	///\param wNotifyCode - ������������� ��������� �� ��������
	///\return TRUE � ������ ������
	template<class CULCurClass_t>
	BOOL AddReflectCommand(LRESULT(CULCurClass_t::*ReflectCmdProc)(),WORD wNotifyCode=0)	
	{
		if(m_pReflectCommandStorage.Resize(m_pReflectCommandStorage.GetSize()+1)!=NULL)
		{
			m_pReflectCommandStorage[m_pReflectCommandStorage.GetSize()-1].csReflectCmdProc=reinterpret_cast<REFLECTCMDPROC>(ReflectCmdProc);
			m_pReflectCommandStorage[m_pReflectCommandStorage.GetSize()-1].csNotifyCode=wNotifyCode;
			return TRUE;
		}
		else
			return FALSE;
	};
	///\brief ������� ��� ��������� ������������ ��������� �� ���������
	///	CULCurClass_t - ����� ����, � ������� ����������	��������� ���������
	///\param CtrlID -������������� ��������
	///\param NotifyCode - ID �������
	///\param NotifyProc - ��������� �� ������� ����������
	///\return TRUE � ������ ������
	template<class CULCurClass_t>
	BOOL AddNotify(WORD CtrlID,DWORD NotifyCode, 
		LRESULT(CULCurClass_t::*NotifyProc)(LPARAM))	
	{
		if(m_pNotifyStorage.Resize(m_pNotifyStorage.GetSize()+1)!=NULL)
		{
			m_pNotifyStorage[m_pNotifyStorage.GetSize()-1].nsNMHDR.hwndFrom=NULL;
			m_pNotifyStorage[m_pNotifyStorage.GetSize()-1].nsNMHDR.idFrom=CtrlID;
			m_pNotifyStorage[m_pNotifyStorage.GetSize()-1].nsNMHDR.code=NotifyCode;
			m_pNotifyStorage[m_pNotifyStorage.GetSize()-1].nsNotifyProc=reinterpret_cast<NOTIFYPROC>(NotifyProc);
			return TRUE;
		}
		else
			return FALSE;
	};
	///\brief ������� ��� ��������� ������������ ������������ ��������� �� ���������
	///	CULCurClass_t - ����� ����, � ������� ����������	��������� ���������
	///\param NotifyCode - ID �������
	///\param NotifyProc - ��������� �� ������� ����������
	///\return TRUE � ������ ������
	template<class CULCurClass_t>
	BOOL AddReflectNotify(DWORD NotifyCode, 
		LRESULT(CULCurClass_t::*NotifyProc)(LPARAM))	
	{
		if(m_pReflectNotifyStorage.Resize(m_pReflectNotifyStorage.GetSize()+1)!=NULL)
		{
			m_pReflectNotifyStorage[m_pReflectNotifyStorage.GetSize()-1].nsNMHDR.code=NotifyCode;
			m_pReflectNotifyStorage[m_pReflectNotifyStorage.GetSize()-1].nsNotifyProc=
				reinterpret_cast<NOTIFYPROC>(NotifyProc);
			return TRUE;
		}
		else
			return FALSE;
	};
	///\brief ������� ������� ��������� ������������ ���������
	void ClearMessage()
	{
		m_pMessageStorage.Resize(0);
	}
	///\brief ������� ������� ��������� ������������ ������������ ���������
	void ClearReflectMessage()
	{
		m_pReflectMessageStorage.Resize(0);
	}
	///\brief ������� ������� ��������� ������������ ������ �� ���������
	void ClearCommand()
	{
		m_pCommandStorage.Resize(0);
	}
	///\brief ������� ������� ��������� ������������ ������������ ������ �� ���������
	void ClearReflectCommand()
	{
		m_pReflectCommandStorage.Resize(0);
	}
	///\brief ������� ������� ��������� ������������ ������ �� ���������
	void ClearNotify()
	{
		m_pNotifyStorage.Resize(0);
	}
	///\brief ������� ������� ��������� ������������ ������������ ������ �� ���������
	void ClearReflectNotify()
	{
		m_pReflectNotifyStorage.Resize(0);
	}
	///\brief ������� ������� ���� ��������� ������������
	void ClearAll()
	{
		ClearMessage();
		ClearReflectMessage();
		ClearCommand();
		ClearReflectCommand();
		ClearNotify();
		ClearReflectNotify();
	}
	///\brief ������� ��� ��������� �������, ���������� ����� ���������� ���������
	///	CULCurClass_t - ����� ����, ����������� �������
	///\param lpObject - ��������� �� ������, ���������� �������
	///\param lpPreTranslateMessageProc - �������
	///\return TRUE � ������ ������
	///\note ������� ������ ���������� � ��� �� ������, � \n
	///\ � ������� ������ ������ CULApp 
	template<class CULCurClass_t>
	BOOL InitializePreTranslateMessage(CULCurClass_t* lpObject, BOOL(CULCurClass_t::*lpPreTranslateMessageProc)(MSG*))	
	{
		if(m_pPreTranslateMessageStorage.Resize(m_pPreTranslateMessageStorage.GetSize()+1)!=NULL)
		{
			m_pPreTranslateMessageStorage[m_pPreTranslateMessageStorage.GetSize()-1].lpObject=lpObject;
			m_pPreTranslateMessageStorage[m_pPreTranslateMessageStorage.GetSize()-1].lpPreTranslateMessageProc=
				reinterpret_cast<PRETRANSLATEMESSAGEPROC>(lpPreTranslateMessageProc);
			return TRUE;
		}
		else
			return FALSE;
	};
	///\brief ������� ��� �������� �������, ���������� ����� ���������� ���������
	///	CULCurClass_t - ����� ����, ����������� �������
	///\param lpObject - ��������� �� ������, ���������� �������
	///\param lpPreTranslateMessageProc - �������
	template<class CULCurClass_t>
	void UnInitializePreTranslateMessage(CULCurClass_t* lpObject, BOOL(CULCurClass_t::*lpPreTranslateMessageProc)(MSG*))	
	{
		size_t nFind=0;
		for(nFind=0;nFind<m_pPreTranslateMessageStorage.GetSize();++nFind)
			if((m_pPreTranslateMessageStorage[nFind].lpObject==lpObject)&&
				m_pPreTranslateMessageStorage[nFind].lpPreTranslateMessageProc==lpPreTranslateMessageProc)
				break;
		for(size_t i=nFind;i<(m_pPreTranslateMessageStorage.GetSize()-1);++i)
		{
			m_pPreTranslateMessageStorage[i].lpObject=m_pPreTranslateMessageStorage[i+1].lpObject;
			m_pPreTranslateMessageStorage[i].lpPreTranslateMessageProc=m_pPreTranslateMessageStorage[i+1].lpPreTranslateMessageProc;
		}
		assert(m_pPreTranslateMessageStorage.GetSize());
		m_pPreTranslateMessageStorage.Resize(m_pPreTranslateMessageStorage.GetSize()-1);
	};
	///\brief ������� ������ ������������ ���������
	///\param pWnd - ��������� �� �����, � �������� ����������� WndProc
	///\param uMsg - ������������� ���������
	///\param wParam - �������� 1
	///\param lParam - �������� 2
	///\return ������������ �������� �����������
	BOOL ProcessMessage(CULClass_t* pWnd,UINT uMsg , WPARAM wParam , LPARAM lParam)
	{
		for(unsigned int i=0;i<m_pMessageStorage.GetSize();++i)
			if(m_pMessageStorage[i].msMsgID==uMsg)
				return(pWnd->*m_pMessageStorage[i].msMsgProc)(wParam,lParam);
		return FALSE;
	};
	///\brief ������� ������ ������������ ������������ ���������
	///\param pWnd - ��������� �� �����, � �������� ����������� WndProc
	///\param uMsg - ������������� ���������
	///\param wParam - �������� 1
	///\param lParam - �������� 2
	///\return ������������ �������� �����������
	BOOL ProcessReflectMessage(CULClass_t* pWnd,UINT uMsg , WPARAM wParam , LPARAM lParam)
	{
		for(unsigned int i=0;i<m_pReflectMessageStorage.GetSize();++i)
			if(m_pReflectMessageStorage[i].msMsgID==uMsg)
				return(pWnd->*m_pReflectMessageStorage[i].msMsgProc)(wParam,lParam);
		return FALSE;
	};
	///\brief ������� ������ ������������ ������ �� ���������
	///\param pWnd - ��������� �� �����, � �������� ����������� WndProc
	///\param wParam - �������� 1
	///\param lParam - �������� 2
	///\return TRUE, ���� ���� ����������
	BOOL ProcessCommand(CULClass_t* pWnd,WPARAM wParam , LPARAM lParam)
	{
		WORD wNotifyCode=HIWORD(wParam);
		WORD wID=LOWORD(wParam);
		HWND hControl=HWND(lParam);
		for(unsigned int i=0;i<m_pCommandStorage.GetSize();++i)
			if((m_pCommandStorage[i].csCtrlID==wID)&&
				((m_pCommandStorage[i].csNotifyCode==wNotifyCode)||
				((m_pCommandStorage[i].csNotifyCode==0)&&(wNotifyCode==1))))//��� ������������
			{
				(pWnd->*m_pCommandStorage[i].csCmdProc)(wID,hControl);
				return TRUE;
			}
		return FALSE;
	};
	///\brief ������� ������ ������������ ������������ ������ �� ���������
	///\param pWnd - ��������� �� �����, � �������� ����������� WndProc
	///\param wNotifyCode - ������������� ��������� �� ��������
	///\return TRUE, ���� ���� ����������
	BOOL ProcessReflectCommand(CULClass_t* pWnd,WORD wNotifyCode)
	{
		for(unsigned int i=0;i<m_pReflectCommandStorage.GetSize();++i)
			if(m_pReflectCommandStorage[i].csNotifyCode==wNotifyCode)
				return(pWnd->*m_pReflectCommandStorage[i].csReflectCmdProc)();
		return FALSE;
	};
	///\brief ������� ������ ������������ ������ �� ���������
	///\param pWnd - ��������� �� �����, � �������� ����������� WndProc
	///\param pNMHDR - ��������� �� ��������� NMHDR
	///\return TRUE, ���� ���� ����������
	BOOL ProcessNotify(CULClass_t* pWnd,NMHDR* pNMHDR)
	{
		for(unsigned int i=0;i<m_pNotifyStorage.GetSize();++i)
			if((m_pNotifyStorage[i].nsNMHDR.idFrom==pNMHDR->idFrom)&&
				(m_pNotifyStorage[i].nsNMHDR.code==pNMHDR->code))
			{
				::SetWindowLong(pWnd->m_hWnd,DWL_MSGRESULT,(pWnd->*m_pNotifyStorage[i].nsNotifyProc)(LPARAM(pNMHDR)));
				return TRUE;
			}
		return FALSE;
	};
	///\brief ������� ������ ������������ ������������ ������ �� ���������
	///\param pWnd - ��������� �� �����, � �������� ����������� WndProc
	///\param pNMHDR - ��������� �� ��������� NMHDR
	///\param pfRet - ������������ �������� �� ����������� ���������
	///\return TRUE, ���� ���� ����������
	BOOL ProcessReflectNotify(CULClass_t* pWnd,NMHDR* pNMHDR,BOOL *pfRet)
	{
		for(unsigned int i=0;i<m_pReflectNotifyStorage.GetSize();++i)
			if(m_pReflectNotifyStorage[i].nsNMHDR.code==pNMHDR->code)
			{
				*pfRet=(pWnd->*m_pReflectNotifyStorage[i].nsNotifyProc)(LPARAM(pNMHDR));
				//::SetWindowLong(pWnd->m_hWnd,DWL_MSGRESULT,*pfRet);
				return TRUE;
			}
		return FALSE;
	};

	///\brief ������� ������ �������, ���������� ����� ���������� ���������
	///\param pMsg - ��������� �� ��������� ���������, ������� ���������� � ���������
	///\return FALSE(��� �������� ������� Pre...) ����� � ����������� ��������� �������� ���������
	BOOL ProcessPreTranslateMessage(MSG* pMsg)
	{
		for(unsigned int i=0;i<m_pPreTranslateMessageStorage.GetSize();++i)
			if(!(m_pPreTranslateMessageStorage[i].lpObject->*m_pPreTranslateMessageStorage[i].lpPreTranslateMessageProc)(pMsg))
				return FALSE;
		return TRUE;
	};
};
#endif //__UL_MESSAGEMAP_H__