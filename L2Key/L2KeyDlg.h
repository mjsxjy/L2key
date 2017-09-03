
// L2KeyDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CL2KeyDlg 对话框
class CL2KeyDlg : public CDialogEx
{
// 构造
public:
	CL2KeyDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_L2KEY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString edit_1;
	CString strTargetName; //输入的或者是鼠标获得的窗口标题的edit2相关变量
	afx_msg void OnBnClickedButton1();
	long GetWindowHwnd(CString WindowName);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	long GetCurWindow(void);
	CString m_poswindowname;
	afx_msg void OnBnClickedRadio1();
	CEdit edit_2;
//	CEdit edit_3;
	afx_msg void OnBnClickedRadio2();
//	CButton m_check1;
	CButton m_radio1;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedCancel();
	CButton m_button3;
	CString about;
	afx_msg void OnCbnSelchangeCombo2();
//	CString cb_button;
//	CString cb_time;
//	CComboBox cbbutton;
//	CComboBox cbtime;
	CComboBox cbbuton;
	CComboBox cbtime;
	CString str_cb1;
	CString str_cb2;
	CListBox list1;
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton4();
};
