
// S-CurveVelocityTable.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSCurveVelocityTableApp:
// �� Ŭ������ ������ ���ؼ��� S-CurveVelocityTable.cpp�� �����Ͻʽÿ�.
//

class CSCurveVelocityTableApp : public CWinApp
{
public:
	CSCurveVelocityTableApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSCurveVelocityTableApp theApp;