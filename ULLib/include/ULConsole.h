///\file ULConsole.h
///\brief ������������ ���� �������
#pragma once
#include <windows.h>
#include <tchar.h>
///\brief ����� � �������
enum enConsoleColor
{
	clBlack		= 0,
	clNavy		= 1,
	clGreen		= 2,
	clTeal		= 3,
	clBrown		= 4,
	clPurple	= 5,
	clOlive		= 6,
	clGray		= 7,
	clSilver	= 8,
	clBlue		= 9,
	clLime		= 10,
	clCyan		= 11,
	clRed		= 12,
	clMagneta	= 13,
	clYellow	= 14,
	clWhite		= 15,
};
///\class CULConsole 
///\brief ����� ��� ������ � ��������
class CULConsole
{
private:
	///\brief ��������� �� ����������� �����
	HANDLE m_hStdout;
	///\brief ��������� �� ����������� ����
	HANDLE m_hStdin;
public:
	///\brief �����������
	CULConsole();
	///\brief ����������� �����������
	CULConsole(CULConsole&);
	///\brief ����������
	virtual ~CULConsole();
	///\brief �������� �����������
	void operator=(CULConsole&);
	///\brief ������� ������
	void Clear();
	///\brief ��������
	void Pause();
	///\brief ��������� ��������� ����
	///\param pszTitle - ����� ��� ���������
	///\param wSizeOfBuf - ������ ������ ��� ���������
	///\return ��������� �� ���� ��������� (pszTitle)
	TCHAR* GetTitle(LPTSTR pszTitle,WORD wSizeOfBuf);
	///\brief ��������� ��������� ����
	///\param pszTitle - �����
	void SetTitle(LPTSTR pszTitle);
	///\brief ��������� ����� ������
	///\return ���� ������
	enConsoleColor GetColor();
	///\brief ��������� ����� ������
	///\param Color - ���� �����
	void SetColor(enConsoleColor Color);
	///\brief ��������� ����� ����
	///\param ���� ����
	enConsoleColor GetBgColor();
	///\brief ��������� ����� ����
	///\param  Color ���� ����
	void SetBgColor(enConsoleColor Color);
	///\brief ��������� ������� �������
	///\return ������� �������
	COORD GetCursorPos();
	///\brief ��������� ������� �������
	///\param X,Y - ������� �������
	void SetCursorPos(short X, short Y);
	///\brief ��������� �������� ���� (� ��������)
	///\return ��������� �������	
	SIZE GetWindowSize();
	///\brief ����� �������
	///\param c - ������
	void Write(TCHAR c);
	///\brief ����� ������ (� ��������������� ���������)
	///\param pszStr - �����
	void Write(LPTSTR pszStr);
	///\brief ������� �� ����� ������
	void WriteLine();
	///\brief ����� ������ (� ��������������� ��������� � ��������� �� ����� ������)
	///\param pszStr - �����
	void WriteLine(LPTSTR pszStr);
	///\brief ������ ������ (�� ������)
	///\param pszBuf - �����,� ������� ����� ����������� ������
	///\param wSizeOfBuf - ������ ������ (pszBuf)
	///\return ��������� �� ����������� ������ (pszBuf)
	LPTSTR ReadLine(LPTSTR pszBuf,WORD wSizeOfBuf);
	///\brief ������ ������ ����� (�� ������)
	///\return ����� ����� (�� ������)
	long ReadLong();
	///\brief ������ ������ ����� (��� �����)
	///\return ����� ����� (��� �����)
	unsigned long ReadULong();
	///\breif ������ ��������������� �����
	///\return �������������� �����
	double ReadDouble();
	///\breif ������ ���� ������� ������� (� ���������)
	///\return ��� ������� �������
	TCHAR ReadKey();
	///\brief ������� ��������������� �����
	///\param szFormat - ������ ������
	///\param ... - ����� ����������
	///\return ����� ���������� ��������
	int Format(LPTSTR szFormat,...);
};
