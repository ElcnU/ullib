#pragma once
#include "..\..\ULLib\Include\ULDlgs.h"
#include "..\..\ULLib\Include\ULLib.h"
#include "resource.h"
#include <assert.h>

class CPage1:public ULWnds::ULDlgs::CULPropPage
{
public:
	CPage1():ULWnds::ULDlgs::CULPropPage()
	{
		MessageMap.AddCommand<CPage1>(IDC_BUTTON1,&CPage1::OnBtn1);
		MessageMap.AddMessage<CPage1>(WM_INITDIALOG,&CPage1::OnInitDialog);
	};
	virtual ~CPage1(){};
	virtual LRESULT OnInitDialog(WPARAM,LPARAM)
	{
		HWND hBtnOK=::GetDlgItem(GetParent(),IDOK);
		HWND hBtnCancel=::GetDlgItem(GetParent(),IDCANCEL);
		assert(hBtnOK!=NULL);
		assert(hBtnCancel!=NULL);
		ULWnds::ULControls::ULButtons::CULButton btnOk;
		ULWnds::ULControls::ULButtons::CULButton btnCancel;
		btnCancel.Attach(hBtnCancel);
		btnCancel.ModifySyle(BS_DEFPUSHBUTTON,0);
		btnCancel.Detach();

		btnOk.Attach(hBtnOK);
		btnOk.ModifySyle(0,BS_DEFPUSHBUTTON);
		btnOk.SetActiveWindow();
		btnOk.SetFocus();
		btnOk.Detach();

		::SendMessage(GetParent(),WM_NEXTDLGCTL, (WPARAM)hBtnOK, TRUE);
		return 1;
	}
	void OnBtn1(WORD,HWND)
	{
		MessageBox(_T("Page1"),_T("����"),0);
	}
};

class CPage2:public ULWnds::ULDlgs::CULPropPage
{
public:
	CPage2():ULWnds::ULDlgs::CULPropPage()
	{
		MessageMap.AddCommand<CPage2>(IDC_BUTTON1,&CPage2::OnBtn1);
		MessageMap.AddMessage<CPage2>(WM_INITDIALOG,&CPage2::OnInitDialog);
	};
	~CPage2(){};
	virtual LRESULT OnInitDialog(WPARAM,LPARAM)
	{
	/*	HWND hBtnOK=::GetDlgItem(GetParent(),IDOK);
		HWND hBtnCancel=::GetDlgItem(GetParent(),IDCANCEL);
		assert(hBtnOK!=NULL);
		assert(hBtnCancel!=NULL);
		ULWnds::ULControls::ULButtons::CULButton btnOk;
		ULWnds::ULControls::ULButtons::CULButton btnCancel;
		btnCancel.Attach(hBtnCancel);
		btnCancel.ModifySyle(BS_DEFPUSHBUTTON,0);
		btnCancel.Detach();

		btnOk.Attach(hBtnOK);
		btnOk.ModifySyle(0,BS_DEFPUSHBUTTON);
		btnOk.SetActiveWindow();
		btnOk.SetFocus();
		btnOk.Detach();

		::SendMessage(GetParent(),WM_NEXTDLGCTL, (WPARAM)hBtnOK, TRUE);
	*/	return 1;
	}
	void OnBtn1(WORD,HWND)
	{
		MessageBox(_T("Page2"),_T("����"),0);
	}
};



class CWorkPage :
	public ULWnds::ULDlgs::CULPropPage
{
public:
	CPage1 m_Page1;
	CPage2 m_Page2;
	BOOL m_bNext;
	CWorkPage(void);
	~CWorkPage(void);
	void OnBtnPushMe(WORD,HWND);
	virtual LRESULT OnWizNext(short Result);
};
