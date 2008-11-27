///\file ULWaitCursor.h 
///\brief ���� ���������� ������ ������� ��������
#include <windows.h>
namespace ULOther
{
	///\class CULWaitCursor
	///\brief ������ ������� ��������
	class CULWaitCursor
	{
		///\brief ����� ������� ��������
		HCURSOR m_hWaitCursor;
		///\brief ����� ����������� �������
		HCURSOR m_hCursor;
	public:
		///\brief �����������
		CULWaitCursor();
		///\brief ����������
		~CULWaitCursor();
		///\brief ������� ��� ������������� ���������� �������
		void Restore();
	};
}