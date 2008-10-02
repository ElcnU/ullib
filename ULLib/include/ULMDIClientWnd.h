///\file ULMDIClientWnd.h
///\brief ������������ ���� ������ ����������� ���� ����������� MDI(26.07.2007)
#pragma once
#ifndef __UL_ULMDICLIENTWND_H__
#define __UL_ULMDICLIENTWND_H__

#include "ULSubClass.h"
#include "ULOther.h"
#include "ULMDIChildWnd.h"
namespace ULWnds
{
	namespace ULFrames
	{
		///\class CULMDIClientWnd
		///\brief ����� ����������� ���� ����������� MDI(26.07.2007)
		class CULMDIClientWnd:
			public CULSubClass
		{
		private:
			///\brief ������ �������� ����
			ULOther::CULArr<CULMDIChildWnd*> m_pMDIChilds;
		public:
			///\brief �����������
			CULMDIClientWnd(void);
			///\brief ����������� �����������
			CULMDIClientWnd(CULMDIClientWnd& MDIClientWnd);
			///\brief ����������
			virtual ~CULMDIClientWnd(void);
			///\brief �������� �����������
			virtual void operator = (CULMDIClientWnd&);
			///\brief ������� �������� ����������� ����
			///\param hParentWnd - ����� ��������
			///\param idSubMenu - ����� ������� �������� ���� ����,� ������� ����� ������������ �������� ����
			///\param idFirstChild - ���� ������� ��������� ����
			///\param dwClientStyle - ����� ���������� ���� 
			///\param dwClientStyleEx - ����������� ����� ���������� ����
			///\return ����� ���������� ����
			HWND Create(HWND hParentWnd,
				UINT idSubMenu,
				UINT idFirstChild,
				DWORD dwClientStyle,
				DWORD dwClientStyleEx);
			///\brief ������� ��������� ����� � ������ ���������� MDI-�������
			///\param pULMDIChildWnd - ��������� �� MDI-����
			///\return ����������� �������
			int AddChild(CULMDIChildWnd* pULMDIChildWnd);
			///\brief ���������� ����������� �������� ����
			///\return ����� �������� ����
			inline int GetChildCount()
				{return (int)m_pMDIChilds.GetSize();}
		protected:
			///\���������� ���������(CLM_DESTROYCHILD), ������� ����� �������� ��� �������� ��� �������� �� m_pMDIChilds
			///\param wParam - HWND ������
			///\return TRUE � ������ ������
			virtual LRESULT OnDestroyChild(WPARAM wParam,LPARAM);
		};
	}
}
#endif//__UL_ULMDICLIENTWND_H__
