
// S-CurveVelocityTableDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "S-CurveVelocityTable.h"
#include "S-CurveVelocityTableDlg.h"
#include "afxdialogex.h"
#include <stdio.h>
#include <math.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSCurveVelocityTableDlg 대화 상자



CSCurveVelocityTableDlg::CSCurveVelocityTableDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SCURVEVELOCITYTABLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSCurveVelocityTableDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_LOW, m_edit_low);
	DDX_Control(pDX, IDC_EDIT_HIGH, m_edit_high);
	DDX_Control(pDX, IDC_LIST_RESULT, m_list_result);
}

BEGIN_MESSAGE_MAP(CSCurveVelocityTableDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ACCEL, &CSCurveVelocityTableDlg::OnBnClickedBtnAccel)
	ON_BN_CLICKED(IDC_BTN_DECEL, &CSCurveVelocityTableDlg::OnBnClickedBtnDecel)
	ON_BN_CLICKED(IDC_BTN_CONVERT, &CSCurveVelocityTableDlg::OnBnClickedBtnConvert)
END_MESSAGE_MAP()


// CSCurveVelocityTableDlg 메시지 처리기

BOOL CSCurveVelocityTableDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	CRect rect;
	m_list_result.GetClientRect(&rect);

	m_list_result.InsertColumn(0, _T("Accelerate"), LVCFMT_LEFT, 100);
	m_list_result.InsertColumn(1, _T("Decelerate"), LVCFMT_LEFT, 100);
	m_list_result.InsertColumn(2, _T("OK"), LVCFMT_LEFT, 100);
	//m_list_result.InsertColumn(1, )
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CSCurveVelocityTableDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CSCurveVelocityTableDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CSCurveVelocityTableDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CSCurveVelocityTableDlg::Accelerate()
{
	CString str_high, str_low, str_result = _T("");
	double db_high, db_base = 0;
	i_Accel_num = 0;

	m_edit_high.GetWindowTextW(str_high);
	m_edit_low.GetWindowTextW(str_low);

	db_high = _wtof(str_high);
	db_base = _wtof(str_low);

	Accel_buf[i_Accel_num++] = str_low;

	while (db_base <= db_high)
	{
		i_col++;
		db_base *= 1.1f;
		str_result.Format(_T("%7.2f"), db_base);
		Accel_buf[i_Accel_num++] = str_result;
	}
}

void CSCurveVelocityTableDlg::Decelerate()
{
	CString str_high, str_low, str_result = _T("");
	double db_low, db_base = 0;
	i_Decel_num = 0;

	m_edit_high.GetWindowTextW(str_high);
	m_edit_low.GetWindowTextW(str_low);

	db_base = _wtof(str_high);
	db_low = _wtof(str_low);

	Decel_buf[i_Decel_num++] = str_high;

	while (db_base >= db_low)
	{
		i_col++;
		db_base *= 0.9f;
		str_result.Format(_T("%7.2f"), db_base);
		Decel_buf[i_Decel_num++] = str_result;
	}
}

void CSCurveVelocityTableDlg::OnBnClickedBtnAccel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_list_result.DeleteAllItems();
	for (int i = 0; i <= 2; i++)
	{
		m_list_result.DeleteItem(0);
	}

	i_col = 0;

	Accelerate();

	UpdateData(TRUE);

	for (int j = 1; j <= i_Accel_num; j++)
	{
		m_list_result.InsertItem(j, Accel_buf[j - 1]);
	}

	UpdateData(FALSE);
}


void CSCurveVelocityTableDlg::OnBnClickedBtnDecel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_list_result.DeleteAllItems();
	//for (int i = 0; i <= 2; i++)
	//{
	//	m_list_result.DeleteItem(0);
	//}

	i_col = 0;

	Decelerate();

	UpdateData(TRUE);

	for (int j = 1; j <= i_Decel_num; j++)
	{
		m_list_result.InsertItem(j, _T("1"));
		//m_list_result.SetItemText(j, 1, Decel_buf[j - 1]);
		m_list_result.SetItemText(j, 1, _T("2"));
	}

	UpdateData(FALSE);
}


void CSCurveVelocityTableDlg::OnBnClickedBtnConvert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	for (int i = 0; i <= i_col; i++)
	{
		m_list_result.DeleteItem(0);
	}

	i_col = 0;
	Accelerate();
	Decelerate();

	for (int j = 1; j <= i_Decel_num; j++)
	{
		m_list_result.InsertItem(j, Decel_buf[j - 1]);
	}

}
