
// L2KeyDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CL2KeyDlg �Ի���
class CL2KeyDlg : public CDialogEx
{
// ����
public:
	CL2KeyDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_L2KEY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString edit_1;
	CString strTargetName; //����Ļ���������õĴ��ڱ����edit2��ر���
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
