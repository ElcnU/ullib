///\file ULSubClass.h
///\brief ������������ ���� ������ ��� ���������������� ���������(12.10.2007)
#pragma once
#ifndef __SUBCLASS__H_
#define __SUBCLASS__H_
#include "ULWnd.h"
namespace ULWnds
{
	///\class CULSubClass
	///\brief ����� ��� ���������������� ���������(12.10.2007)
	class CULSubClass:public CULWnd
	{
	private:
		///\brief ������ ������� ����
		WNDPROC m_lpOldWndProc;
	protected:
		///\brief ����� ������� ����
		static LRESULT WndProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);
		///\brief ����� ������� ���� ��������
		static LRESULT ParentWndProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);
		///\brief ������� ���������� ����� �����������������
		virtual void PreSubClass();
	public:
		///\brief �����������
		CULSubClass();
		///\brief ����������� �����������
		CULSubClass(CULSubClass& SubClass);
		///\brief ����������
		virtual ~CULSubClass();
		///\brief �������� �����������
		virtual void operator = (CULSubClass&);
		///\brief ������� �������������� ������� ������� �������
		///\param hWnd - ����� ����, ������� ����� ��������� � ������
		virtual BOOL Attach(HWND hWnd);
		///\brief �������� ID ��������� ��������
		///\return ID ��������
		inline int GetDlgCtrlID()
			{return ::GetDlgCtrlID(*this);}
		///\brief ����� ������� ����
		inline virtual LRESULT CallWindowProc(UINT uMsg,WPARAM wParam,LPARAM lParam)
    {return ((m_lpOldWndProc)?::CallWindowProc(m_lpOldWndProc,*this, uMsg, wParam, lParam):0);}	
	};
}
#endif //__SUBCLASS__H_
