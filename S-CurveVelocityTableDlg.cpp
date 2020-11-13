
// S-CurveVelocityTableDlg.cpp : ���� ����
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


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CSCurveVelocityTableDlg ��ȭ ����



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


// CSCurveVelocityTableDlg �޽��� ó����

BOOL CSCurveVelocityTableDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CRect rect;
	m_list_result.GetClientRect(&rect);

	m_list_result.InsertColumn(0, _T("Accelerate"), LVCFMT_LEFT, 100);
	m_list_result.InsertColumn(1, _T("Decelerate"), LVCFMT_LEFT, 100);
	m_list_result.InsertColumn(2, _T("OK"), LVCFMT_LEFT, 100);
	//m_list_result.InsertColumn(1, )
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CSCurveVelocityTableDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
