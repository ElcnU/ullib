///\file ULClassFactory.h
///\brief ������������ ���� ������ ������� �������
#pragma once
#ifndef _ULCLASSFACTORY_H__
#define _ULCLASSFACTORY_H__
#include <objbase.h>
#include "ULCOMDllApp.h"
namespace ULCOMs
{
	///\namespace ULAgregation
	///\brief ������������ ��� ������� ���������
	namespace ULAgregation
	{
		;
		///\class CAgregateNone
		///\brief ����� �������� ��� ���������� ���������
		///\param CComponent_t - ��� ������ ����������
		template<class CComponent_t>class CULAgregateNone
		{
		public:
			///\brief ����������
			CULAgregateNone(IUnknown* /*pUnknownOuter*/)
			{		
			}
			///\brief ��������� ������� ��������� CULClassFactory::CreateInstance 
			///\ �� ����������� �������������
			///\param pUnknownOuter - ������������� ��������� �� ���������
			///\param iid - ������������� �������������� ����������
			///\return S_OK ���� �� ��������, ����� CLASS_E_NOAGGREGATION
			HRESULT Check(IUnknown* pUnknownOuter,const IID& iid)
			{
				if(pUnknownOuter!=NULL)
					return CLASS_E_NOAGGREGATION;
				else 
					return S_OK;
			}
			///\brief ������ ���������
			///\return ��������� �� ���������
			CComponent_t* GetComponent()
			{
				return new CComponent_t;
			}
		};
		///\class CULAgregate
		///\brief ����� ��� ���������
		///\param CComponent_t - ��� ������ ����������
		template<class CComponent_t>class CULAgregate
		{
		private:
			///\brief ��������� �� ������������� ���������
			IUnknown* m_pUnknownOuter;
		public:
			///\brief ����������
			///\param pUnknownOuter - ������������� ��������� �� ���������
			CULAgregate(IUnknown* pUnknownOuter):
				m_pUnknownOuter(pUnknownOuter)
			{		
			}
			///\brief ��������� ������� ��������� CULClassFactory::CreateInstance 
			///\ �� ����������� �������������
			///\param pUnknownOuter - ������������� ��������� �� ���������
			///\param iid - ������������� �������������� ����������
			///\return S_OK ���� �� ��������, ����� CLASS_E_NOAGGREGATION
			HRESULT Check(IUnknown* pUnknownOuter,const IID& iid)
			{
				if ((pUnknownOuter != NULL) && (iid != IID_IUnknown))
					return CLASS_E_NOAGGREGATION;
				else 
					return S_OK;
			}
			///\brief ������ ���������
			///\return ��������� �� ���������
			CComponent_t* GetComponent()
			{
				return new CComponent_t(pUnknownOuter);
			}
		};
	}
	template<class CComponent_t,class CAgregate_t=ULAgregation::CULAgregateNone<CComponent_t>>class CULClassFactory:
	///\class CULClassFactory
	///\brief ����� ������� �������
	///\param CComponent_t - ��� ��������������� ����������
	public IClassFactory
	{
	private: 
		///brief ������� ������
		long m_nRef; 
	public:
		///\brief �����������
		CULClassFactory():
			m_nRef(1)
		{
		};
		///\brief ����������
		~CULClassFactory()
		{
		};
		
		//=================����������  ���������� IUnknown==========================
		///\brief ���������� ��������� �� IClassFactory
		///\param iid - ������������� ����������
		///\param ppvObject - ��������� �� ��������� �� ���������
		///\return S_OK � ������ �������� ���������, 
		///\ E_NOINTERFACE - � ������ ���������� �������������� ����������
		virtual HRESULT __stdcall CULClassFactory::QueryInterface(const IID& iid, void** ppvObject)
		{    
			if ((iid == IID_IUnknown) || (iid == IID_IClassFactory))
				*ppvObject = static_cast<IClassFactory*>(this); 
			else
			{
				*ppvObject = NULL ;
				return E_NOINTERFACE ;
			}
			reinterpret_cast<IUnknown*>(*ppvObject)->AddRef() ;
			return S_OK ;
		}
		///\brief ����������� ������� ����� ������ �� ���������
		///\return ������� ����� ������
		virtual ULONG __stdcall CULClassFactory::AddRef()
		{
			return InterlockedIncrement(&m_nRef) ;
		}
		///\brief ��������� ������� ����� ������ �� ���������
		///\return ������� ����� ������
		virtual ULONG __stdcall CULClassFactory::Release() 
		{
			if (InterlockedDecrement(&m_nRef) == 0)
			{
				delete this ;
				return 0 ;
			}
			return m_nRef ;
		}

		// ���������� LockServer
		///\brief ��������� ������ ��� �� ��������������� �������� �������������
		///\param fLock - TRUE - �������������, FALSE - ��������������
		///\return S_OK
		virtual HRESULT __stdcall CULClassFactory::LockServer(BOOL fLock) 
		{
			if (fLock)
				static_cast<ULApps::CULCOMDllApp*>(ULApps::CULCOMDllApp::GetULDllApp())->ServerLock();
			else
				static_cast<ULApps::CULCOMDllApp*>(ULApps::CULCOMDllApp::GetULDllApp())->ServerUnlock();
			return S_OK ;
		}

		///\brief ��������� �������� ����������. ���������� �� CoCreateInstance
		///\param pUnknownOuter - ���� �������������� �������������, 
		/// �� � ���� ������������� ��������� �� ���������
		///\param iid - ������������� ����������, ��������������� �����������
		///\param ppvObject - ��������� �� ��������� �� ���������
		///\return COM ��� ��������
		HRESULT __stdcall CreateInstance(IUnknown* pUnknownOuter,
												 const IID& iid,
												 void** ppvObject)
		{
			CAgregate_t Agregation(pUnknownOuter);
			HRESULT hr=Agregation.Check(pUnknownOuter,iid);
			if(FAILED(hr))
				return hr;
			//�������� ����������
			CComponent_t* pComponent = Agregation.GetComponent();
			if (pComponent == NULL)
				return E_OUTOFMEMORY;
			//��������� ������������ ����������
			hr = pComponent->QueryInterface(iid, ppvObject) ;
			//����������� ��������� IUnknown .
			// (���� QueryInterface ����������� �� �����, �� ��������� �������� ����������.)
			pComponent->Release() ;
			return hr ;
		}
	};
}
#endif//_ULCLASSFACTORY_H__
