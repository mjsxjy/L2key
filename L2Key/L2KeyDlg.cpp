
// L2KeyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "L2Key.h"
#include "L2KeyDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

bool isFinding=false;//�Ƿ���ʹ�������Ҵ�����.
bool isRunning=false;//�ͷ��Ѿ���ʼ���ƴ��ڣ�����Ϣ��

int config_num; //����Timer�� ��
int configID; //OnTimer�¼���ʹ��

//CArray<float,CString> config; //����Ҫ

struct config
{
	CString time;
	CString button;
};

config config_array[100];

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CL2KeyDlg �Ի���




CL2KeyDlg::CL2KeyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CL2KeyDlg::IDD, pParent)
	, edit_1(_T(""))
	, strTargetName(_T(""))
	, m_poswindowname(_T(""))
	, about(_T(""))
//	, cb_button(_T(""))
//	, cb_time(_T(""))
, str_cb1(_T(""))
, str_cb2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CL2KeyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, edit_1);
	DDX_Text(pDX, IDC_EDIT2, strTargetName);
	//	DDX_Text(pDX, IDC_EDIT3, m_poswindowname);
	DDX_Control(pDX, IDC_EDIT2, edit_2);
	//	DDX_Control(pDX, IDC_EDIT3, edit_3);
	//  DDX_Control(pDX, IDCANCEL, m_check1);
	DDX_Control(pDX, IDC_RADIO1, m_radio1);
	DDX_Control(pDX, IDC_BUTTON3, m_button3);
	DDX_Text(pDX, IDC_EDIT3, about);
	//	DDX_CBString(pDX, IDC_COMBO1, cb_button);
	//	DDX_CBString(pDX, IDC_COMBO2, cb_time);
	//	DDX_Control(pDX, IDC_COMBO1, cbbutton);
	//	DDX_Control(pDX, IDC_COMBO2, cbtime);
	DDX_Control(pDX, IDC_COMBO3, cbbuton);
	DDX_Control(pDX, IDC_COMBO4, cbtime);
	DDX_CBString(pDX, IDC_COMBO3, str_cb1);
	DDX_CBString(pDX, IDC_COMBO4, str_cb2);
	DDX_Control(pDX, IDC_LIST1, list1);
}

BEGIN_MESSAGE_MAP(CL2KeyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CL2KeyDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CL2KeyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CL2KeyDlg::OnBnClickedButton2)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RADIO1, &CL2KeyDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CL2KeyDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON3, &CL2KeyDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDCANCEL, &CL2KeyDlg::OnBnClickedCancel)
//	ON_CBN_SELCHANGE(IDC_COMBO2, &CL2KeyDlg::OnCbnSelchangeCombo2)
ON_LBN_SELCHANGE(IDC_LIST1, &CL2KeyDlg::OnLbnSelchangeList1)
ON_BN_CLICKED(IDC_BUTTON4, &CL2KeyDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CL2KeyDlg ��Ϣ�������

BOOL CL2KeyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_radio1.SetCheck(true);
	strTargetName="Lineage II";
	about="by:�Ȼ���� QQ:471439016";
	cbbuton.ResetContent();
	cbtime.ResetContent();
	int i = 0;
	do //���combo����ѡ��
	{
		CString str;
		CString str2;
		str2.Format(L"%d",i+1);
		str=L"F"+ str2;
		cbbuton.InsertString(i,str);
		i++;
	}
	while(i<=11);
	int j=0;
	do //���combo����ѡ��
	{
		CString str;
		CString str2;
		str2.Format(L"%d",j+1);
		if (j<=8)
		{
			str=L"0."+ str2;
		}
		else
		{
			str2.Format(L"%d",j-8);
			str=str2;
		}
		cbtime.InsertString(j,str);
		j++;
	}
	while(j<=18);
	str_cb1="F1";
	str_cb2="0.1";
	UpdateData(0); //��ֵ

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CL2KeyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CL2KeyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CL2KeyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CL2KeyDlg::OnBnClickedOk() //ȡ�þ����ť
{
	//CString str;
	//UpdateData(1); //�ӿؼ��ж�ȡֵ������
	//long hwnd;
	//hwnd=GetWindowHwnd(strTargetName);
	//if (hwnd != 0)
	//{
	//	str.Format(_T("%p"),hwnd);
	//	edit_1 = str;
	//}
	//else
	//{
	//	edit_1="";
	//}
	//UpdateData(0); //��ֵ���͵��ؼ���...�ӵ��ĺ����綼����
}


void CL2KeyDlg::OnBnClickedButton1() //���
{
	//int index1,index2;
	//index1=cbbuton.GetCurSel();
	//CString button;
	//cbbuton.GetLBText(index1,button);
	CString button, time;
	UpdateData(1);
	button=str_cb1;
	time=str_cb2;
	CString str;
	str = L"ÿ���� " + time + L" ���뷢�͡� " + button + L" ����";
	list1.AddString(str);
	float f;
	UINT fi;
	f =  _tstof(time);
	fi = f * 1000;
	if (config_num <100) 
	{
		//������趨��ʱ��Ͱ�����Ϣ����������
		config_array[config_num].button = button;
		config_array[config_num].time = time;
		config_num ++;
		SetTimer(config_num+1,fi,NULL);
	}
	else
	{
		MessageBox(L"���ֻ�ܴ洢100���趨��",L"��ʾ",0);
	}
}


long CL2KeyDlg::GetWindowHwnd(CString WindowName)
{
	HWND hWindowHwnd;
	CString str;
	hWindowHwnd = ::FindWindow(NULL,WindowName);
	if (hWindowHwnd != 0)
	{
		str.Format(_T("%p"),hWindowHwnd);
		return long(hWindowHwnd);
	}
	else
	{
		return 0;
	}
	return 0;
}


void CL2KeyDlg::OnBnClickedButton2() //���list
{
	
}


void CL2KeyDlg::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case 1://��������´��ڵ�timer
		{
			isFinding=true;//���ڲ���
			CString str;
			long hwnd;
			hwnd=GetCurWindow();
			if (hwnd != 0)
			{
				str.Format(_T("%p"),hwnd);
				
				char szWindowTitle[500];
				::GetWindowTextA((HWND)hwnd, szWindowTitle, sizeof(szWindowTitle));  // ��ȡ���ڱ���
				CString str2(szWindowTitle);
				edit_1 =L"���ڱ���:��" + str2 + L"��, �������" + str + L"��";
				if (str2 == "L2Key" || str2=="��ʼ����" || str2== "ֹͣ����")
				{
					edit_1="";
					//m_poswindowname=""; //�˱�����ʹ��
				}
				else
				{
					strTargetName=szWindowTitle;
				}
			}
			else
			{
				edit_1="";
				strTargetName="";
			}
			UpdateData(0); //��ֵ���͵��ؼ�
			break;
		}
	default:
		{
		/*
		config_array[config_num].button = button;
		config_array[config_num].time = time;
		*/
			for (int i = config_num; i>0; i--)
			{
				//::PostMessage((HWND)GetWindowHwnd(strTargetName),WM_KEYDOWN,config_array[config_num-2].button,0);
				::PostMessage((HWND)GetWindowHwnd(strTargetName),WM_KEYDOWN,0,0);
			}
			edit_1=L"���ڡ� " + strTargetName + L" �����ڽ��ܰ�����Ϣ��";
		}
	}//switch end
	UpdateData(0); //��ֵ���͵��ؼ���
	CDialogEx::OnTimer(nIDEvent);
}


long CL2KeyDlg::GetCurWindow(void)
{
HWND hwndPointNow = NULL;
  POINT pNow = {0,0};
  if (GetCursorPos(&pNow))  // ��ȡ��굱ǰλ��
  {
   hwndPointNow = ::WindowFromPoint(pNow);  // ��ȡ������ڴ��ڵľ��
  }
  Sleep(10);
  return long(hwndPointNow);
}


void CL2KeyDlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	KillTimer(1);
	isFinding=false;
	edit_2.EnableWindow(true);
///	edit_3.EnableWindow(false);
//	edit_2.ShowWindow(1);
//	edit_3.ShowWindow(0);
	edit_1="";
	UpdateData(0); //��ֵ���͵��ؼ���...�ӵ��ĺ����綼����
}


void CL2KeyDlg::OnBnClickedRadio2() //���ѡ�Ҵ���radio
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	edit_2.EnableWindow(false);
//	edit_3.EnableWindow(true);
	//edit_3.ShowWindow(1);
	if (isRunning == false) //�����ʱû�п����еĴ���
		SetTimer(1,1000,NULL);//������Ϊ��ʼ����
	else
		KillTimer(1);//ֹͣ���ҹ���
	edit_1="";
	UpdateData(0); //��ֵ���͵��ؼ���...�ӵ��ĺ����綼����
}


void CL2KeyDlg::OnBnClickedButton3() //��ʼ����.ֹͣ���� ��ť
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	UpdateData(1); //�ӿؼ��ж�ȡֵ������
	long hwnd;
	Sleep(200);
	if (config_num == 0) 
	{
		m_button3.SetWindowTextW(L"��ʼ����");
		isRunning=false;
		KillTimer(1);
		edit_1=L"û�д��ڽ��ܰ�����Ϣ��";
		MessageBox((CString)"���������һ���������ã�",L"��ʾ",0);
	}else
	{
		if (isRunning==false) //�������û�п��ƴ���
		{
			{
				hwnd=GetWindowHwnd(strTargetName);
			}
			if (hwnd != 0)
			{
				str.Format(_T("%p"),hwnd);
				//edit_1 = L"���ڿ��ƣ�" + str;
				KillTimer(1);
				isFinding=false;//����Ϊֹͣ���ұ�־
				m_button3.SetWindowTextW(L"ֹͣ����");
				isRunning=true;//����Ϊ���ڿ��Ʊ�־

				//for (int i=0;i<config_num; i++) //������Ӱ�ť����ӵĴ������ڴ�����timer������
				//{
				//	float ftime;
				//	ftime=_wtof(config_array[i].time);//��CString���͵�ʱ��ת��Ϊfloat����
				//	SetTimer(i+2,ftime*1000,NULL);/////----------------------------------------------------------now
				//}
			
			}
			else
			{
				edit_1="";
				MessageBox((CString)"û���ҵ���Ϊ�� " +strTargetName+ (CString)" ���Ĵ��ڣ�",L"��ʾ",0);
			}
		}
		else //����������ڿ���ĳ���ڣ�����󽫳�Ϊֹͣ���Ƶ�״̬
		{
			//KillTimer(2);
			for (int i=1; i<=config_num+1; i++)
			{
				KillTimer(i);
			}
			m_button3.SetWindowTextW(L"��ʼ����");
			isRunning=false;
			edit_1=L"û�д��ڽ��ܰ�����Ϣ��";
		}
	}
	UpdateData(0);
}


void CL2KeyDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CL2KeyDlg::OnCbnSelchangeCombo2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CL2KeyDlg::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

}


void CL2KeyDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
