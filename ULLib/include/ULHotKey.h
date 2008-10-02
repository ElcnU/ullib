///\file ULHotKey.h
///\brief ������������ ���� ������ ������ ��� HOTKEY ��������(09.09.2007)
#pragma once
#ifndef __HOTKEY__H_
#define __HOTKEY__H_
#include "ULSubClass.h"
#include <commctrl.h>
namespace ULWnds
{
	namespace ULControls
	{
		///\class CULHotKey
		///\brief ����� ������ ��� EDIT ��������(16.07.2007)
		class CULHotKey:public CULSubClass
		{
		public:
			///\brief �������� ��������
			enum enCombInv
			{
				ciA=	HKCOMB_A,
				ciC=	HKCOMB_C,
				ciCA=	HKCOMB_CA,
				ciNone=	HKCOMB_NONE,
				ciS=	HKCOMB_S,
				ciSA=	HKCOMB_SA,
				ciSC=	HKCOMB_SC,
				ciSCA=	HKCOMB_SCA
			};
			///\brief �������� �������������� ������� ������
			enum enModifierKey
			{
				mfAlt		=HOTKEYF_ALT,
				mfControl	=HOTKEYF_CONTROL,
				mfExt		=HOTKEYF_EXT,
				mfShift		=HOTKEYF_SHIFT
			};
			///\brief ��������� ������� ������
			///\param wHotkey - ������� ������� ����������� � �����
			///\param hkStruct - ����������� ������� �������
			union unHotKey
			{
				WORD wHotkey;
				///\brief ��������� ����������� ������� ������
				///\param bVirtualKey - ������� �������
				///\param bModifierKey - �������������� ������� �������
				struct tagHotKey
				{
					BYTE bVirtualKey;
					BYTE bModifierKey;
				}hkStruct;
			};
		public:
			///\brief �����������
			CULHotKey();
			///\brief ����������
			virtual ~CULHotKey();
			///\brief ������� ��� �������� ������
			///\param hParentWnd - ����� ������������� ����
			///\param uID - ID ������
			///\param x,y - ���������� ������
			///\param cx,cy - ������ ������
			///\param dwStyle - ����� �����
			///\param dwStyleEx - ����������� ����� �����
			///\return TRUE � ������ ������
			BOOL Create(HWND hParentWnd,UINT uID,int x,int y,
				int cx,int cy,DWORD dwStyle=WS_CHILD|WS_VISIBLE|WS_TABSTOP,
				DWORD dwStyleEx=WS_EX_CLIENTEDGE);
		//==================inline functions============================
			///\brief ���������� ������� ������� �������
			///\return CULHotKey::unHotKey
			inline unHotKey GetHotKey()
			{	
				unHotKey HotKey;
				HotKey.wHotkey=(WORD)SendMessage(HKM_GETHOTKEY);
				return HotKey;
			}
			///\brief ������������� ������� �������
			///\param HotKey - ������� �������
			inline void SetHotKey(unHotKey HotKey)
				{SendMessage(HKM_SETHOTKEY,(WPARAM)HotKey.wHotkey);}
			///\brief ������������� ������� �������
			///\param bVirtualKey - ������� �������
			///\param bModifierKey - �������������� �������
			inline void SetHotKey(BYTE bVirtualKey,BYTE bModifierKey)
				{SendMessage(HKM_SETHOTKEY,MAKELPARAM(bVirtualKey,bModifierKey));}
			///\brief ������������� ������� �� ����� ������� �������
			///\param bCombInv - �������� ��������
			///\param bModifierKey - �������������� �������, ������� ���������� � ����������� 
			inline void SetRules(BYTE bCombInv,BYTE bModifierKey)
				{SendMessage(HKM_SETHOTKEY,(WPARAM)bCombInv,(LPARAM)bModifierKey);}
		};
	}
}
#endif //__HOTKEY__H_