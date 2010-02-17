///\file ULCOMDllApp.h
///\brief ������������ ���� ������ ������������ ���������� COM-�������(05.01.2007)
#pragma once
#ifndef _ULCOMDLLAPP_H__
#define _ULCOMDLLAPP_H__
#include "ULDllApp.h"
#include <objbase.h>
#include "ULRegServ.h"

namespace ULApps
{
	///\class CULCOMDllApp
	///\brief ����� ������������ ���������� COM-�������
	class CULCOMDllApp:public ULApps::CULDllApp
	{
	private:
		volatile LONG m_nComponentsLocks;
		volatile LONG m_nServerLocks;
	protected:
		///\brief ����� ������ ULCOMs::CULRegServ, ����������� ��� ����������� �����������
		ULCOMs::CULRegServ m_RegServ;
	public:
		///\brief �����������
		CULCOMDllApp();
		///\brief ����������
		virtual ~CULCOMDllApp();
		///\brief ���������� ��� ���������� ����������� �������� �����������
		void ComponentLock();
		///\brief 
		///\brief ���������� ��� ���������� ����������� �������� �����������
		void ComponentUnlock();
		///\brief ���������� ��� ���������� ����������� �������� ������ �������
		///\��� ��� ����� ���� �������� ��������
		void ServerLock();
		///\brief ���������� ��� ���������� ����������� �������� ������ �������
		///\��� ��� ����� ���� �������� ��������
		void ServerUnlock();
		///\brief ������ ��������� ����������� ������� �������, ��� ������� ����������� � ClassFactory_t
		///\param clsidComponent - ������������� ���������� ������ ����������
		///\param clsidRequest - ������������� ������ ���������
		///\param iid - ������������� ���������� ������� �������
		///\param ppvObject - ������������ ��������� �� ��������� ������� �������
		///\return ��� �������� COM
		template<class ClassFactory_t>HRESULT GetClassObjectFromClassFactory(const CLSID& clsidComponent,
			const CLSID& clsidRequest,
			const IID& iid,
			void** ppvObject)
		{
			// ��������� ����������� �������� ����������?
			if (clsidRequest != clsidComponent)
				return CLASS_E_CLASSNOTAVAILABLE;
			// ������ ������� �������
			ClassFactory_t* pFactory = new ClassFactory_t ;  // No AddRef in constructor
			if (pFactory == NULL)
				return E_OUTOFMEMORY;
			// �������� ����������� ���������
			HRESULT hr = pFactory->QueryInterface(iid, ppvObject) ;
			pFactory->Release();
			return hr;
		};
		///\brief ����� ����������� ������� ����������� ��� 
		///\������� �����������. ���������� �� DllRegisterServer
		///\return ���������� ��� �������� ����������� �������
		virtual HRESULT OnRegisterServer()=0;
		///\brief ����� ����������� ������� ����������� ��� 
		///\������� �����������. ���������� �� DllUnregisterServer
		///\return ���������� ��� �������� ������ ����������� �������
		virtual HRESULT OnUnregisterServer()=0;
		///\brief ����� ����������� ������� ����������� ��� 
		///\������� �����������. ���������� �� DllGetClassObject
		///\param clsid - ������������� ������ ���������
		///\param iid - ������������� ���������� ������� �������
		///\param ppvObject - ������������ ��������� �� ��������� ������� �������
		///\return ��� �������� COM
		virtual HRESULT OnGetClassObject(const CLSID& clsid,const IID& iid,void** ppvObject)=0;
		///\brief ���������� ����������� �������, ��  CoCreateUnusedLibraries
		///\��� ������ DLL ������������ ��� ����� ���� �������
		///\return S_OK - ����� ��������� DLL,S_FALSE - ������ ��������� DLL
		virtual HRESULT OnCanUnloadNow();
		///\brief ������ ��� ����������� ����������(��).
		///\���������� ����� regsvr32.exe my.dll
		///\return ���������� ��� �������� ����������� �������
		HRESULT DllRegisterServer();
		///\brief ������ ��� ������ ����������� ����������(��).
		///\���������� ����� regsvr32.exe -u my.dll
		///\return ���������� ��� �������� ������ ����������� �������
		HRESULT DllUnregisterServer();
		///\brief ����� ����� DLL ��� �������� ������� ������ ���������� (��. CoGetClassObject)
		///\param clsid - ������������� ������ ���������
		///\param iid - ������������� ���������� ������� �������
		///\param ppvObject - ������������ ��������� �� ��������� ������� �������
		///\return ��� �������� COM
		HRESULT DllGetClassObject(const CLSID& clsid,
			const IID& iid,
			void** ppvObject);
		///\brief ���������� ����������� �������, ��  CoCreateUnusedLibraries
		///\��� ������ DLL ������������ ��� ����� ���� �������
		///\return S_OK - ����� ��������� DLL,S_FALSE - ������ ��������� DLL
		HRESULT DllCanUnloadNow();
	};
}
#endif//_ULCOMDLLAPP_H__
