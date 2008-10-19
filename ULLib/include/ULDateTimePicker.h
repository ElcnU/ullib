///\file ULDateTimePicker.h 
///\brief ���� ���������� ������ �������� ���������� ���� � �������
#ifndef _ULDATETIMEPICKER_H__
#define _ULDATETIMEPICKER_H__
#include "ULSubClass.h"
#include "commctrl.h"

namespace ULWnds
{
	namespace ULControls
	{
		///\class CULDateTimePicker
		///\brief ����� �������� ���������� ���� � �������
		class CULDateTimePicker:
			public ULWnds::CULSubClass
		{
		public:
			///\brief �����������
			CULDateTimePicker();
			///\brief ����������
			~CULDateTimePicker();
			///\brief ������� ������� ���������� ���� � �������
			///\param hParentWnd - ����� ���� ��������
			///\param wID - ������������� ��������
			///\param x,y - ���������� ��������
			///\param cx,cy - �������
			///\param dwStyle - �����
			///\return TRUE � ������ �������
			BOOL Create(HWND hParentWnd,WORD wID,int x,int y,int cx,int cy,DWORD dwStyle=
				WS_BORDER|WS_CHILD|WS_VISIBLE|DTS_SHOWNONE);
		};
	}
}

#endif //_ULDATETIMEPICKER_H__
