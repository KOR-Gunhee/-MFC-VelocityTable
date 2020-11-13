
// S-CurveVelocityTableDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

// CSCurveVelocityTableDlg 대화 상자
class CSCurveVelocityTableDlg : public CDialogEx
{
// 생성입니다.
public:
	CSCurveVelocityTableDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCURVEVELOCITYTABLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
