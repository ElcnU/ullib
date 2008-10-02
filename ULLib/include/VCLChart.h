///\file VCLChart.h
///\brief ������������ ���� ������ ������ ��� vcl - �����
#pragma once
#ifndef _VCL_CHART_H__
#define _VCL_CHART_H__
#include <windows.h>
#include <tchar.h>
///\class CVCLChart
///\brief ����� VCL �����, ������� �������� � ���(���� �����������)(2006)
class CVCLChart
{
	///\brief ����� ������
	HMODULE m_hLib;
public:
	///\brief ����� ����
	HWND m_hVCLChart;
//==================================================
	///\brief ���� �����	
	enum enPenStyle
	{
		psSolid=1,
		psClear=2,
		psDash=3,
		psDashDot=4,
		psDashDotDot=5,
		psDot=6,
		psInsideFrame=7
	};
//==================================================
	///\brief �����������
	CVCLChart(void)
	{
		m_hLib=LoadLibrary(_T("vclChart/vclChart.dll"));
		if(m_hLib==NULL) 
		{
			::MessageBox(0,_T("Not load library vclChart.dll"),_T("Error"),0);
			return;
		}

	}
	///\brief ����������
	~CVCLChart(void)
	{
		FreeLibrary(m_hLib);
	}
	///\brief ������ ��������� �����
	///\param hParentWnd - ����� ��������
	///\param x,y - ���������� ��� ����������
	///\param cx,cy - �������
	///\return TRUE � ������ ������
	BOOL Create(HWND hParentWnd, int x, int y, int cx, int cy)
	{
		typedef HWND(_cdecl* VCL_CREATE_CHART_WND)(HWND hParentWnd);
		VCL_CREATE_CHART_WND vclCreateChartWnd=(VCL_CREATE_CHART_WND)GetProcAddress(m_hLib,"CreateChartWnd");
		if(vclCreateChartWnd==NULL)
		{
			::MessageBox(0,_T("Not load vclCreateChartWnd"),_T("Error"),0);
			return FALSE;
		}
		m_hVCLChart=vclCreateChartWnd(hParentWnd);
		SetWindowPos(m_hVCLChart,HWND_TOP,x,y,cx,cy,SWP_SHOWWINDOW);
		return TRUE;
	}
	///\brief ��������� ������
	///\param pBufX - ����� ������ �� ��� �
	///\param pBufY - ����� ������ �� ��� Y
	///\param nBufLen - ������ ������
	///\param uiColor - ���� �������
	///\param szName - ������� �������
	///\param nWidth - ������ �����
	///\param PenStyle - ��� �����
	///\return TRUE � ������ ������, ����� FALSE
	BOOL AddSeries(double* pBufX,double* pBufY, int nBufLen, UINT uiColor, LPTSTR szName,int nWidth,enPenStyle PenStyle)
	{
		typedef BOOL(_cdecl* VCL_ADD_SERIES)(double** pBuffer, int nBufLen, UINT uiColor, TCHAR* szName,int nWidth,int iType);
		VCL_ADD_SERIES vclAddSeries=(VCL_ADD_SERIES)GetProcAddress(m_hLib,"AddSeries");
		if(vclAddSeries==NULL)
		{
			::MessageBox(0,_T("Not load AddSeries"),_T("Error"),0);
			return FALSE;
		}
		double **pBuffer;
		pBuffer=new double*[2];
		pBuffer[0]=pBufX;
		pBuffer[1]=pBufY;
		vclAddSeries(pBuffer,nBufLen,uiColor,szName,nWidth,PenStyle);
		return TRUE;
	}
	///\brief ���������� �������
	///\param fVisible - ���� ��������� ������
	///\return TRUE � ������ ������, ����� FALSE
	BOOL SeriesLegend(BOOL fVisible)
	{
		typedef BOOL(_cdecl* VCL_SERIES_LEGEND)(BOOL bVisible);
		VCL_SERIES_LEGEND vclSeriesLegend=(VCL_SERIES_LEGEND)GetProcAddress(m_hLib,"SeriesLegend");
		if(vclSeriesLegend==NULL)
		{
			::MessageBox(0,_T("Not load SeriesLegend"),_T("Error"),0);
			return FALSE;
		}
		vclSeriesLegend(fVisible);
		return TRUE;
	}
	///\brief ������� �� �������
	///\return TRUE � ������ ������, ����� FALSE
	BOOL ClearSeries(void)
	{
		typedef BOOL(_cdecl* VCL_CLEAR_SERIES)();
		VCL_CLEAR_SERIES vclClearSeries=(VCL_CLEAR_SERIES)GetProcAddress(m_hLib,"ClearSeries");
		if(vclClearSeries==NULL)
		{
			::MessageBox(0,_T("Not load ClearSeries"),_T("Error"),0);
			return FALSE;
		}
		vclClearSeries();
		return TRUE;
	}
};
#endif //_VCL_CHART_H__
