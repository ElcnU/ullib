///\file ULSplitter.h 
///\brief ���� ���������� ������ �������� �����������
#ifndef _ULSPLITTER_H__
#define _ULSPLITTER_H__
#include "ULWnd.h"

namespace ULWnds
{
	namespace ULControls
	{
		///\class CULSplitter
		///\brief ����� �������� �������� ����������� 
		class CULSplitter:
			public ULWnds::CULWnd
		{
		private:
			///\brief ������� ��������
			int m_nSplitterPos;
			//\brief ������ ��������
			int m_nSplitterBorder;
			///\brief ������ ��� ����, ������� ��������� �������
			ULWnds::CULWnd* m_arPane[2];
			///\brief ���������� ������� ��������
			int  m_oldPos;
			///\brief ����� �������
			BOOL m_fMoved;
			BOOL m_fDragMode;

		public:
			///\brief ������� ���������� ��������� �������
			///\param scPaneSized - ����� ������� ��������
			enum enSplitterCommand
			{
				scPaneSized
			};
			///\brief ������ ��������
			///\param soHorz - ��������������
			///\param soVert - ������������
			enum enSplitterOrientation
			{
				soHorz,
				soVert
			};
			///\brief �������� ������� ����� ��������
			enSplitterOrientation m_SplitterOrientation;
		public:
			///\brief �����������
			CULSplitter();
			///\brief ������� �������
			///\param hParentWnd - ����� ���� ��������
			///\param wID - ������������� ��������
			///\param x,y - ���������� ��������
			///\param cx,cy - �������
			///\param SplitterOrientation - ����������
			///\param nSplitterPos - ������� ������� ��������
			///\return TRUE � ������ ������
			BOOL Create(HWND hParentWnd,WORD wID,int x,int y,int cx,int cy,enSplitterOrientation SplitterOrientation,int nSplitterPos);
			///\brief ������������� ���� � ������
			///\param nPos - ������� ������
			///\param pwndPane - ��������� �� ����
			///\return TRUE � ������ ������
			BOOL SetPane(int nPos,ULWnds::CULWnd* pwndPane);
		protected:
			///\brief �������� ������ 
			///\param nWidth, nHeight - ������ ��������
			void SizeWindowContents(int nWidth, int nHeight);
			///\brief ������ ������ ��� ������� �����
			///\param hDC - �������� ��� ���������
			///\param x1,y1,width, height - ���������� � ������� �������
			void DrawXorBar(HDC hDC, int x1, int y1, int width, int height);
		protected:
			virtual LRESULT OnMessage(UINT uMsg,WPARAM wParam,LPARAM lParam);
			virtual LRESULT OnLButtonDown(WPARAM wParam,LPARAM lParam);
			virtual LRESULT OnLButtonUp(WPARAM wParam,LPARAM lParam);
			virtual LRESULT OnMouseMove(WPARAM wParam,LPARAM lParam);
			virtual LRESULT OnSize(WPARAM wParam,LPARAM lParam);
			virtual LRESULT OnWindowPosChanged(WPARAM wParam,LPARAM lParam);
		};
	}
}

#endif _ULSPLITTER_H__
