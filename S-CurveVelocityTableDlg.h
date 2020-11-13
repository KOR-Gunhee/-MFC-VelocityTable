
// S-CurveVelocityTableDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

// CSCurveVelocityTableDlg ��ȭ ����
class CSCurveVelocityTableDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CSCurveVelocityTableDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCURVEVELOCITYTABLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CEdit m_edit_low;
	CEdit m_edit_high;
	CListCtrl m_list_result;

public:
	int i_col;
	int i_Accel_num;
	int i_Decel_num;
	CString Accel_buf[100];
	CString Decel_buf[100];
public:
	afx_msg void OnBnClickedBtnAccel();
	afx_msg void OnBnClickedBtnDecel();

public:
	void Accelerate();
	void Decelerate();

	afx_msg void OnBnClickedBtnConvert();
};
