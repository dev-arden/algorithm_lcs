
// ����ó��_�ǽ�.h : ����ó��_�ǽ� ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// C����ó��_�ǽ�App:
// �� Ŭ������ ������ ���ؼ��� ����ó��_�ǽ�.cpp�� �����Ͻʽÿ�.
//

class C����ó��_�ǽ�App : public CWinAppEx
{
public:
	C����ó��_�ǽ�App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C����ó��_�ǽ�App theApp;
