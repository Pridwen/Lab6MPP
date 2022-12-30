
// Lab6Dlg.h : header file
//

#pragma once

#define N 5

// CLab6Dlg dialog
class CLab6Dlg : public CDialogEx
{
// Construction
public:
	CLab6Dlg(CWnd* pParent = nullptr);	// standard constructor
	void ActualizareFoto();
	UINT m_nCrt;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB6_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedInainte();
	afx_msg void OnBnClickedInapoi();
	CString Date;
	CString Desc;
	CString Obsv;
};
