///\file ULFrameWnd.h
///\brief ������������ ���� ������ �������� ����(2006)
#pragma once

#ifndef __UL_ULFRAMEWND_H__
#define __UL_ULFRAMEWND_H__
#include "ULWnd.h"
namespace ULWnds
{
	namespace ULFrames
	{
		///\class CULFrameWnd
		///\brief ����� �������� ����(2006)
		class CULFrameWnd:
			public CULWnd
		{
		public:
			///\brief �����������
			CULFrameWnd(void);
			///\brief ����������� �����������
			CULFrameWnd(CULFrameWnd& FrameWnd);
			///\brief ����������
			virtual ~CULFrameWnd(void);
			///\brief �������� �����������
			virtual void operator = (CULFrameWnd&);
			///\brief ������� �������� �������� ����
			///\param szWindowName - ��������� ����
			///\param MenuID - ID ���� �� ��������
			///\param IconID - ID ������ �� ��������
			///\param IconSmID - ID ��������� ������ �� ��������
			///\param BGColor - ���� ���������� �������
			///\param dwStyle - ����� ����
			///\param dwStyleEx - ����������� ����� ����		
			///\return TRUE � ������ ������
			BOOL Create(LPCTSTR szWindowName,				
						short MenuID, 						
						short IconID, 						
						short IconSmID,						
						short BGColor,						
						DWORD dwStyle=WS_OVERLAPPEDWINDOW,	
						DWORD dwStyleEx=WS_EX_APPWINDOW);	
		protected:
			///\brief ���������� WM_DESTROY
			virtual LRESULT OnDestroy(WPARAM /*wParam*/,LPARAM /*lParam*/);
			///\brief ���������� WM_CREATE
			virtual LRESULT OnCreate(WPARAM /*wParam*/,LPARAM);
		};
	}
}
#endif//__UL_ULFRAMEWND_H__