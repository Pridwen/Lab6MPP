
// Lab6Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Lab6.h"
#include "Lab6Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CLab6Dlg dialog



CLab6Dlg::CLab6Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB6_DIALOG, pParent)
	, Date(_T(""))
	, Desc(_T(""))
	, Obsv(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DATE, Date);
	DDX_Text(pDX, IDC_DESC, Desc);
	DDX_Text(pDX, IDC_OBSV, Obsv);
}

BEGIN_MESSAGE_MAP(CLab6Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INAINTE, &CLab6Dlg::OnBnClickedInainte)
	ON_BN_CLICKED(IDC_INAPOI, &CLab6Dlg::OnBnClickedInapoi)
END_MESSAGE_MAP()


// CLab6Dlg message handlers

BOOL CLab6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_nCrt = 1;
	ActualizareFoto();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLab6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLab6Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLab6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLab6Dlg::ActualizareFoto()
{
	UpdateData();
	if (m_nCrt == 1) {
		Date = "12/02/2000";
		Desc = "Field in mystical blue aura";
		Obsv = "First Image";
	}
	if (m_nCrt == 2) {
		Date = "17/12/2009";
		Desc = "A mythical lion used as a Logo";
		Obsv = "Second Image";
	}
	if (m_nCrt == 3) {
		Date = "21/12/2022";
		Desc = "Picture of a lake";
		Obsv = "Third Image";
	}
	if (m_nCrt == 4) {
		Date = "11/09/2003";
		Desc = "Knitted Touchan napkin";
		Obsv = "Fourth Image";
	}
	if (m_nCrt == 5) {
		Date = "01/08/2159";
		Desc = "3 Penguins next to yellow tulips";
		Obsv = "Fifth Image";
	}
	CString sTitlu;
	sTitlu.Format((LPCWSTR)L"Album de Fotografii - #%d", m_nCrt);
	SetWindowText(sTitlu);
	//incarcare imagine
	static CBitmap bmpFoto;
	if (bmpFoto.m_hObject)bmpFoto.DeleteObject();
	bmpFoto.LoadBitmapW(m_nCrt);
	((CStatic*)GetDlgItem(IDC_FOTO))->SetBitmap(bmpFoto);
	//activari/dezactivari butoane
	GetDlgItem(IDC_INAINTE)->EnableWindow(m_nCrt < N ? TRUE : FALSE);
	GetDlgItem(IDC_INAPOI)->EnableWindow(m_nCrt > 1 ? TRUE : FALSE);
	UpdateData(FALSE);
}


void CLab6Dlg::OnBnClickedInainte()
{
	if (m_nCrt < N)
	{
		m_nCrt++;
		ActualizareFoto();
	}
}
void CLab6Dlg::OnBnClickedInapoi()
{
	if (m_nCrt > 1)
	{
		m_nCrt--;
		ActualizareFoto();
	}
}
