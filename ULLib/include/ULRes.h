///\file ULRes.h
///\brief ���� ���������� ������� ������������ ������� ������ ��������
#pragma once
#ifndef _ULRES_H__
#define _ULRES_H__
#include <windows.h>
namespace ULOther
{
	///\brief ������������� ����� ������ ����������� �������
	///\return ���������� �����. 0 �� ���������������
	HINSTANCE ULSetResourceHandle(HINSTANCE hNewRes);
	///\brief ���������� ����� ������ ����������� �������
	///\return ����� ������ ����������� �������
	HINSTANCE ULGetResourceHandle();
}
#endif //_ULRES_H__