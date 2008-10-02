///\file ULGObjs.cpp
///\brief cpp ���� ����������� ��������(08.10.2007)
#include "..\..\ULLib\Include\ULGObjs.h"
#include "..\..\ULLib\Include\ULOther.h"
#include <olectl.h>
#include <shlwapi.h>
#pragma comment(lib,"shlwapi.lib")
#include <tchar.h>

namespace ULGDI
{
	namespace ULGObjs
	{
		BOOL CULRgn::CreateBitmapRgn(CULBitmap RgnBitmap)
		{
			//�������� ������� �� �����
			if(RgnBitmap.m_hBitmap==NULL)
				return FALSE;	
			BITMAP bmp; 
			RgnBitmap.GetBitmap(&bmp);
			int bpp = bmp.bmBitsPixel >> 3;
			ULOther::CULArr<BYTE> pBits(bmp.bmWidth*bmp.bmHeight*bpp);
			RgnBitmap.GetBitmapBits(bmp.bmWidth*bmp.bmHeight*bpp,(BYTE*)pBits);
			DWORD dwTransPixel=*(DWORD*)(BYTE*)pBits;
			//������ ���� ������������
			dwTransPixel <<= 32 - bmp.bmBitsPixel;
			CreateRectRgn(0,0,0,0);
			//����������� ������������ �����
			for (int i = 0; i < bmp.bmHeight; i++)
			{
				int nStartX=-1;
				for (int j = 0; j < bmp.bmWidth; j++)
				{
					DWORD dwPixel = *(DWORD*)(pBits + (i * bmp.bmWidth + j) * bpp) << (32 - bmp.bmBitsPixel);
					if (dwPixel!=dwTransPixel)
					{
						if (nStartX<0)
						{
							nStartX = j;
						} 
						else 
							if (j == (bmp.bmWidth - 1))
							{
								CULRgn Rgn;
								Rgn.CreateRectRgn( nStartX, i, j, i + 1 );
								CombineRgn(Rgn, RGN_OR);
								nStartX=-1;
							}
					}
					else 
						if (nStartX>=0)
						{
							CULRgn Rgn;
							Rgn.CreateRectRgn( nStartX, i, j, i + 1 );
							CombineRgn(Rgn, RGN_OR);
							nStartX=-1;
						}
				}
			}
			return TRUE;
		};
	}
}



HBITMAP ULGDI::ULLoadImage(LPCTSTR szResource,LPCTSTR szResourceType,HINSTANCE hMod)
{
	class CULLoadImageErr
	{
	public:
		enum enErr
		{
			eFindResource			=-1,
			eLoadResource			=-2,
			eLockResource			=-3,
			eCreateStreamOnHGlobal	=-4,
			eOleLoadPicture			=-5,
			eGetObject				=-6
		};
	protected:
		enErr m_nErr;
	public:	
		CULLoadImageErr(enErr nErr):m_nErr(nErr){};
		enErr GetError()
			{return m_nErr;}
	};
	HRESULT hr;
	IStream* pStream=NULL;
	IPicture* m_pPicture=NULL;
	HRSRC rc=NULL;			
	LPVOID lpImage=NULL;
	HGLOBAL hgl=NULL;
	DWORD dwSize=0;
	LPVOID pNewMem=NULL;
	HBITMAP hBitmapRet=NULL;
	try
	{
		if(IS_INTRESOURCE(szResource))
		{//������� �������� �� ��������
			//���� ������
			rc=::FindResource(hMod,szResource,szResourceType);
			if(rc==NULL)
				throw CULLoadImageErr(CULLoadImageErr::eFindResource);
			//���������� ������ �������
			dwSize = ::SizeofResource(hMod, rc);	
			// ������ ������
			hgl=::LoadResource(hMod,rc);	
			if(hgl==NULL)
				throw CULLoadImageErr(CULLoadImageErr::eLoadResource);
			lpImage=LockResource(hgl);
			if(lpImage==NULL)
				throw CULLoadImageErr(CULLoadImageErr::eLockResource);
			//�������� ������ � ��������� ���� ������ ��� �������� ������
			pNewMem = (LPVOID)::GlobalAlloc(GMEM_FIXED,dwSize);
			if(pNewMem==NULL)
				throw CULLoadImageErr(CULLoadImageErr::eLockResource);
			::CopyMemory(pNewMem,lpImage,dwSize);
			//������ �����
			hr=::CreateStreamOnHGlobal((HGLOBAL)pNewMem,TRUE,&pStream);
			if(hr!=S_OK)
				throw CULLoadImageErr(CULLoadImageErr::eLockResource);
		}
		else
		{
			//������ ����� �� �����
			hr=::SHCreateStreamOnFile(szResource,STGM_SHARE_EXCLUSIVE,&pStream);
			if(hr!=S_OK)
				throw CULLoadImageErr(CULLoadImageErr::eCreateStreamOnHGlobal);
		}
		//��������� �������� �� ������
		hr = ::OleLoadPicture(pStream,0,true,IID_IPicture,(void**)&m_pPicture);
		if((hr!=S_OK)||(m_pPicture==NULL))
			throw CULLoadImageErr(CULLoadImageErr::eOleLoadPicture);
		HBITMAP hBitmap=NULL;
		//�������� ����� �������
		m_pPicture->get_Handle((OLE_HANDLE*)(UINT*)&hBitmap);
		//�������� ������ �������
		BITMAP bmp;
		if(GetObject(hBitmap,sizeof(BITMAP),&bmp)==0)
			throw CULLoadImageErr(CULLoadImageErr::eGetObject);
		//�������� ������
		HDC hDTDC=::GetDC(NULL);
		HDC hSrcDC=::CreateCompatibleDC(hDTDC);
		hBitmap=(HBITMAP)::SelectObject(hSrcDC,hBitmap);
		HDC hDestDC=::CreateCompatibleDC(hDTDC);
		hBitmapRet=::CreateCompatibleBitmap(hDTDC,bmp.bmWidth,bmp.bmHeight);
		hBitmapRet=(HBITMAP)::SelectObject(hDestDC,hBitmapRet);
		::BitBlt(hDestDC,0,0,bmp.bmWidth,bmp.bmHeight,hSrcDC,0,0,SRCCOPY);
		::SelectObject(hSrcDC,hBitmap);
		hBitmapRet=(HBITMAP)::SelectObject(hDestDC,hBitmapRet);
		//����������� GDI �������
		::DeleteDC(hSrcDC);
		::DeleteDC(hDestDC);	
		::ReleaseDC(NULL,hDTDC);
	}
	catch(CULLoadImageErr& /*e*/)
	{
		/*��� �� ������� :-) */
	}
	//����������� �������
	if(hgl!=NULL)
	{
		UnlockResource(hgl);
		::FreeResource(hgl);
	}
	if(pNewMem!=NULL)
		::GlobalFree(pNewMem);
	if(m_pPicture)
		m_pPicture->Release();
	return hBitmapRet;
}