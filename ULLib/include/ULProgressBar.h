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
			UINT GetPos();
			///\brief ������������� ����� ���������� �������
			///\param nPos - �������� �������
			///\return ���������� �������
			UINT SetPos(UINT nPos);
			///\brief ���������� �������� ������������
			///\param pnLower,pnUpper - ��������� �� ������ � ������� ��������
			void GetRange(int* pnLower,int* pnUpper);
			///\brief ���������� �������� ������������
			///\param fWhichLimit - ���� TRUE, �� ������� ������ �������, ����� FALSE
			///\return ��������� �������
			int GetRange(BOOL fWhichLimit);
			///\brief ��������� ���������
			///\param nLower,nUpper - ������ � ������� ������ ���������
			void SetRange(short nLower,short nUpper);
			///\brief ��������� ��������� 32� ������� ����������
			///\param nLower,nUpper - ������ � ������� ������ ���������
			void SetRange32(int nLower,int nUpper);
			///\brief ������������� �������� �� ������� �������
			///\param nIncrement - ��������
			///\return ���������� �������� ���������
			int DeltaPos(int nIncrement);
			///\brief ������������� ���� ���� ������������
			///\param clrNew - ����� ����
			///\return ������ ����
			COLORREF SetBkColor(COLORREF clrNew);
			///\brief ����������� ����� �����������
			///\param fEnable - ���� ������������
			///return ���������� ��������
#if _WIN32_WINNT >= 0x0501
			BOOL SetMarquee(BOOL fEnable);
#endif
			///\brief ��������� ����� �������
			///\param nStep - �������� ����� �������
			///\return ���������� �������
			int SetStep(int nStep);
			///\brief �������� ������� �� ���� �������
			///\return ���������� �������
			int StepIt();
		};
	}
}
#endif //__PROGRESSBAR_H__
