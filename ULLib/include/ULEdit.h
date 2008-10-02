///\file ULEdit.h
///\brief ������������ ���� ������ ������ ��� EDIT ��������(16.08.2007)
#pragma once
#ifndef __EDIT__H_
#define __EDIT__H_
#include "ULSubClass.h"
namespace ULWnds
{
	namespace ULControls
	{
		///\class CULEdit
		///\brief ����� ������ ��� EDIT ��������(16.07.2007)
		class CULEdit:public CULSubClass
		{
		public:
			///\brief �����������
			CULEdit();
			///\brief ����������
			virtual ~CULEdit();
			///\brief ������� ��� �������� �����
			///\param hParentWnd - ����� ������������� ����
			///\param pszText - �����
			///\param uID - ID ������
			///\param x,y - ���������� ������
			///\param cx,cy - ������ ������
			///\param dwStyle - ����� �����
			///\param dwStyleEx - ����������� ����� �����
			///\return TRUE � ������ ������
			BOOL Create(HWND hParentWnd,TCHAR* pszText,UINT uID,int x,int y,
				int cx,int cy,DWORD dwStyle=WS_CHILD|WS_VISIBLE|ES_LEFT|WS_TABSTOP|ES_AUTOHSCROLL,
				DWORD dwStyleEx=WS_EX_CLIENTEDGE|WS_EX_ACCEPTFILES);
		//==================inline functions============================
			///\brief �������� ������
			///\param nStartChar - ��������� ������ ���������
			///\param nEndChar - �������� ������ ���������
			inline void SetSel(int nStartChar,int nEndChar)
				{SendMessage(EM_SETSEL,(WPARAM)nStartChar,(LPARAM)nEndChar);}
			///\brief ���������� ������� ��������� ������
			///\param nStartChar - ��������� ������ ���������
			///\param nEndChar - �������� ������ ���������
			inline void GetSel(int* nStartChar,int* nEndChar)
				{SendMessage(EM_GETSEL,(WPARAM)nStartChar,(LPARAM)nEndChar);}
			///\brief ������������� ������ ����������� ��������
			///\param nLimit - ������ ����������� ��������
			inline void SetLimitText(int nLimit)
				{SendMessage(EM_LIMITTEXT,(WPARAM)nLimit,0);}
			///\brief ���������� ������ ����������� ��������
			///\return ������ ����������� ��������
			inline int GetLimitText()
				{return (int)SendMessage(EM_GETLIMITTEXT,0,0);}
			///\brief ���������� ����� ������� � ������
			///\param xPos,yPos - ����������
			///\param pnChar - ������������ ����� �������
			///\param pnLine - ������������ ����� ������
			inline void CharFromPos(int xPos,int yPos,WORD* pnChar,WORD* pnLine)
			{
				int ret=(int)SendMessage(EM_CHARFROMPOS,0,MAKELPARAM(xPos,yPos));
				if(pnChar!=NULL)
					*pnChar=LOWORD(ret);
				if(pnLine!=NULL)
					*pnLine=HIWORD(ret);
			}		
			///\brief ���������� ���������� �������
			///\param nChar - ����� �������
			///\param pXPos,pYPos - ������������ ����������
			inline void PosFromChar(int nChar,int* pXPos,int* pYPos)
			{
				int ret=(int)SendMessage(EM_POSFROMCHAR,WPARAM(nChar));
				if(pXPos!=NULL)
					*pXPos=LOWORD(ret);
				if(pYPos!=NULL)
					*pYPos=HIWORD(ret);
			}		
			///\brief ������������� ������������� �������
			///\param rc - ������������� �������
			inline void SetRect(RECT rc)
				{SendMessage(EM_SETRECT,(WPARAM)0,(LPARAM)&rc);}
			///\brief �������� ������������� �������
			///\param lpRect - ������������� �������
			inline void GetRect(LPRECT lpRect)
				{SendMessage(EM_GETRECT,(WPARAM)0,(LPARAM)lpRect);}
		protected:
			///\brief ���������� ��������� WM_DROPFILES
			virtual LRESULT OnDropFiles(WPARAM,LPARAM);
		};
	}
}
#endif //__EDIT__H_