
// L2Key.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CL2KeyApp:
// �йش����ʵ�֣������ L2Key.cpp
//

class CL2KeyApp : public CWinApp
{
public:
	CL2KeyApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CL2KeyApp theApp;