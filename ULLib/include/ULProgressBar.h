///\file ULProgressBar.h
///\brief ������������ ���� ������ ������ ��� ProgressBar
#ifndef __PROGRESSBAR_H__
#define __PROGRESSBAR_H__
#include "ULSubClass.h"
namespace ULWnds
{
	namespace ULControls
	{
		///\class CULProgressBar
		///\brief ����� �������� ������������
		class CULProgressBar:
			public ULWnds::CULSubClass
		{
		public:
			///\brief �����������
			CULProgressBar();
			///\brief ������ �����������
			///\param hParentWnd - ����� ������������� ����
			///\param uID - ID ��������
			///\param x,y - ���������� ��������
			///\param cx,cy - ������ ��������
			///\param dwStyle - ����� ��������
			///\param dwStyleEx - ����������� ����� 
			///\return TRUE � ������ ������
			BOOL Create(HWND hParentWnd,UINT uID,int x,int y,int cx,int cy,
				DWORD dwStyle=WS_CHILD|WS_VISIBLE,DWORD dwStyleEx=NULL);
			///\return ���������� ������� ������� ������������
			int GetPos();
			///\brief ���������� �������� ������������
			///\param pnLower,pnUpper - ��������� �� ������ � ������� ��������
			///\return TRUE � ������ ������
			BOOL GetRange(int* pnLower,int* pnUpper);
			///\brief ������������� �������� �� ������� �������
			///\param nIncrement - ��������
			///\return ���������� �������� ���������
			int DeltaPos(int nIncrement);
			///\brief 
			COLORREF SetBkColor(COLORREF clrNew);
			///\brief ������������� ����� ���������� �������
			///\param nPos - �������� �������
			///\return ���������� �������
			int SetPos(int nPos);
			///\brief ��������� ���������
			void SetRange(short nLower,short nUpper);
			void SetRange32(int nLower,int nUpper);
			int SetStep(int nStep);
			int StepIt();
		};
	}
}
#endif //__PROGRESSBAR_H__
