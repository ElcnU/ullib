///\file ULPtr.inl
///\brief ������������ ���� ������� ��������� � �����(29.12.2007)
#include <windows.h>
#include <tchar.h>
#include "ULRes.h"
namespace ULOther
{
	///\����� ������������� ������� ��������� (30.07.2007)
	template<typename object_t>
	class CULArr
	{
		///\brief ������� ������ � �������� ����
		size_t m_nObjSize;
	public:
		///\brief ��� ��������� �� �����
		object_t* m_lpObject;
		///\brief �����������,�� ���������� ������
		CULArr():
			m_nObjSize(0),
			m_lpObject(NULL)
		{
		}
		///\brief ����������� ��� ������� ���������
		///\param nObjSize ��������� ������
		CULArr(size_t nObjSize):
			m_nObjSize(nObjSize)
		{
			m_lpObject=new object_t[nObjSize];
		}
		///\brief ����������� �����������
		CULArr(CULArr<object_t>& Arr):
			m_nObjSize(Arr.m_nObjSize)
		{
			m_lpObject=new object_t[m_nObjSize];
			for(size_t i=0;i<m_nObjSize;++i)
				m_lpObject[i]=Arr.m_lpObject[i];
		}
		///\brief �������� ������������
		void operator=(CULArr<object_t>& Arr)
		{
			m_nObjSize=Arr.m_nObjSize;
			m_lpObject=new object_t[m_nObjSize];
			for(size_t i=0;i<m_nObjSize;++i)
				m_lpObject[i]=Arr.m_lpObject[i];
		}
		///\brief ��������� ������� ���������� ������ � ����������� ���������
		///\param nObjSize ����� ������
		///\return �������� �� �����
		object_t* Resize(size_t nObjSize)
		{
			object_t* lpNewObj=NULL;
			if(nObjSize==0)
				Free();
			else
			{
				lpNewObj=new object_t[nObjSize];
				size_t size = (m_nObjSize<nObjSize)?m_nObjSize:nObjSize;
				for(size_t  i = 0; i < size; ++i)
					lpNewObj[i]=m_lpObject[i];
				Free();
			}
			m_lpObject=lpNewObj;
			m_nObjSize=nObjSize;
			return m_lpObject;
		};
		///\brief ���������� ������ ���������
		inline 	size_t GetSize()
		{
			return m_nObjSize;
		}
		///\brief ���������� ���������
		inline operator object_t*()
		{
			return m_lpObject;
		}
		///\brief ����������� ���������� ������
		inline void Free()
		{
			if((m_lpObject!=NULL)&&(m_nObjSize!=0))
			{
				delete[] m_lpObject;
				m_lpObject=NULL;
				m_nObjSize=0;
			}
		}
		///\brief ����������� ���������� ������ �� ������
		///\return ��������� �� ���������� ������
		object_t* Detach()
		{
			object_t* lpRet=m_lpObject;
			m_lpObject=NULL;
			m_nObjSize=0;
			return lpRet;
		}
		///\brief ����������
		virtual ~CULArr()
		{
 			Free();
		}
	};

	template<typename object_t>
	///\class CULStrT
	///\brief ����� ������(29.12.2007)
	class CULStrT:public CULArr<typename object_t> 
	{
	public:
		///\brief �����������
		///\param nObjSize - ������ ���������� ������
		CULStrT(size_t nObjSize=32767):
			CULArr<object_t>(nObjSize)
			{
				(*this)[0]=0;
			};
		///\brief ����������
		virtual ~CULStrT(){};
		///\brief ���������� ����� ������
		///\return ����� ������
		int GetLen()
		{
			return (int)_tcslen(*this);
		}
		/*
		///\brief �������� ����������
		object_t* operator=(const object_t pszRight[])
		{
			if(!pszRight)
				return *this;
			size_t nSize=_tcslen(pszRight);
			if(nSize>GetSize())
				Resize(nSize+1);
			_tcscpy_s(*this,(int)GetSize(),pszRight);
			return *this;
		};
		*/
		///\brief �������� ����������
		object_t* operator=(const object_t* pszRight)
		{
			if(!pszRight)
				return *this;
			size_t nSize=_tcslen(pszRight);
			if(nSize>GetSize())
				Resize(nSize+1);
			_tcscpy_s(*this,(int)GetSize(),pszRight);
			return *this;
		};
		///\brief �������� ����������
		object_t* operator=(CULStrT<object_t> &pszRight)
		{
			if(pszRight.GetSize()>GetSize())
				Resize(pszRight.GetSize()+1);
			_tcscpy_s(*this,(int)GetSize(),pszRight);
			return *this;
		};
		///\brief �������� �������� �����
		///\return ������������ ������
		CULStrT operator+(const object_t* pszRight)
		{
			CULString pszTmp;
			pszTmp=*this;
			size_t nSize=_tcslen(pszRight);
			if(nSize>pszTmp.GetSize())
				pszTmp.Resize(pszTmp.GetSize()+nSize);
			_tcscat_s(pszTmp,pszRight);
			return pszTmp;
		}
		///\brief �������� ����������� � ������
		void operator+=(const object_t* pszRight)
		{
			size_t nSize=GetSize()+_tcslen(pszRight);
			if(nSize>GetSize())
				Resize(nSize);
			_tcscat_s(*this,GetSize(),pszRight);
		}
		///\brief �������� ��������� �����
		///\return 0 ���� �����
		int operator==(const object_t* pszRight)
		{
			return _tcscmp(*this,pszRight);
		}
		///\brief �������� ��������� �����
		///\return 0 ���� �����
		int operator==(const CULStrT<object_t> &pszRight)	
		{
			return _tcscmp(*this,pszRight);
		}
		///\brief ������� ��������������� ����� � ������
		///\param szFormat - ������ ������
		///\param ... - ����� ����������
		///\return ����� ���������� ��������
		int Format(LPTSTR szFormat,...)
		{
			va_list va;
			va_start( va, szFormat );	
			int nRet=_vstprintf(*this,szFormat,va);
			va_end( va );
			return nRet;
		}
	};
	///\brief ���������������� ��� ������ ������
	typedef CULStrT<TCHAR> CULStr;	
	///\class CULStrTable
	///\brief ����� ��� ��������� �������� ����� �� StringTable(05.10.2008)
	class CULStrTable
	{
		///\brief id ������
		UINT m_uID;
		///\brief ������ ������
		TCHAR m_szStr[MAX_PATH];
	public:
		///\brief �����������
		///\param uID - ������������� ������
		CULStrTable(UINT uID):m_uID(uID)
		{}
		///\�������� LPTSTR
		operator LPCTSTR()
		{
			LoadString(ULGetResourceHandle(),m_uID,m_szStr,MAX_PATH);
			return m_szStr;
		}		
	};
}
