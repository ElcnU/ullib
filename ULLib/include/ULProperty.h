///\file ULProperty.h
///\brief ���� ���������� ������ �������
#pragma warning(disable:4355)
///\namespace 
///\brief ������������ ��� ���������� ������ �������
namespace ULProperty
{
	///\class CULProperty
	///\brief ����� ��������, ��������� �������� Set/Get
	template<typename Prop_t,class OwnerClass_t,
		void (OwnerClass_t::*SetHandler)(Prop_t*),
		void (OwnerClass_t::*GetHandler)(Prop_t*)>
	class CULProperty
	{
	protected:
		///\brief ���� ���� ��������
		Prop_t m_PropVal;
		///\brief ��������� �� �����, ���������� ��������
		OwnerClass_t* m_pOwnerClass;
	public:
		///\brief �����������
		///\param pOwnerClass - ��������� �� �����, ���������� ��������
		CULProperty(OwnerClass_t* pOwnerClass):
			m_pOwnerClass(pOwnerClass)
		{
		}
		///\brief �������� ������������
		///\param propVal - ����� �������� ��������
		///\return ����� �������� ��������
		Prop_t operator=(const Prop_t propVal)
		{
			m_PropVal=propVal;
			(m_pOwnerClass->*SetHandler)(&m_PropVal);
			return m_PropVal;
		}
		///\brief �������� ���������� ����
		operator Prop_t()
		{
			(m_pOwnerClass->*GetHandler)(&m_PropVal);
			return m_PropVal;
		}
	};
	///\class CULGetProperty
	///\brief ����� ��������, ��������� �������� Get
	template<typename Prop_t,class OwnerClass_t,
		void (OwnerClass_t::*GetHandler)(Prop_t*)>
	class CULGetProperty
	{
	protected:
		Prop_t m_PropVal;
		OwnerClass_t* m_pOwnerClass;
	public:
		CULGetProperty(OwnerClass_t* pOwnerClass):
			m_pOwnerClass(pOwnerClass)
		{
		}
		Prop_t operator=(const Prop_t propVal)
		{
			m_PropVal=propVal;
			return m_PropVal;
		}
		operator Prop_t()
		{
			(m_pOwnerClass->*GetHandler)(&m_PropVal);
			return m_PropVal;
		}
	};
	///\class CULSetProperty
	///\brief ����� ��������, ��������� �������� Set
	template<typename Prop_t,class OwnerClass_t,
		typename void (OwnerClass_t::*SetHandler)(Prop_t*)>
	class CULSetProperty
	{
	protected:
		Prop_t m_PropVal;
		OwnerClass_t* m_pOwnerClass;
	public:
		CULSetProperty(OwnerClass_t* pOwnerClass):
			m_pOwnerClass(pOwnerClass)
		{
		}
		Prop_t operator=(const Prop_t propVal)
		{
			m_PropVal=propVal;
			(m_pOwnerClass->*SetHandler)(&m_PropVal);
			return m_PropVal;
		}
		operator Prop_t()
		{
			return m_PropVal;
		}
	};
}