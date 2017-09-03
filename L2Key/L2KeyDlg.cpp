
// L2KeyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "L2Key.h"
#include "L2KeyDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

bool isFinding=false;//是否在使用鼠标查找窗口中.
bool isRunning=false;//就否已经开始控制窗口（发消息）

int config_num; //配置Timer编 号
int configID; //OnTimer事件中使用

//CArray<float,CString> config; //不需要

struct config
{
	CString time;
	CString button;
};

config config_array[100];

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CL2KeyDlg 对话框




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


// CL2KeyDlg 消息处理程序

BOOL CL2KeyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_radio1.SetCheck(true);
	strTargetName="Lineage II";
	about="by:踩花大盗 QQ:471439016";
	cbbuton.ResetContent();
	cbtime.ResetContent();
	int i = 0;
	do //添加combo基本选项
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
	do //添加combo基本选项
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
	UpdateData(0); //把值

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CL2KeyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CL2KeyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CL2KeyDlg::OnBnClickedOk() //取得句柄按钮
{
	//CString str;
	//UpdateData(1); //从控件中读取值到变量
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
	//UpdateData(0); //把值传送到控件中...坑爹的函数哥都忘了
}


void CL2KeyDlg::OnBnClickedButton1() //添加
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
	str = L"每隔【 " + time + L" 】秒发送【 " + button + L" 】键";
	list1.AddString(str);
	float f;
	UINT fi;
	f =  _tstof(time);
	fi = f * 1000;
	if (config_num <100) 
	{
		//下面把设定的时间和按键信息存入数组中
		config_array[config_num].button = button;
		config_array[config_num].time = time;
		config_num ++;
		SetTimer(config_num+1,fi,NULL);
	}
	else
	{
		MessageBox(L"最多只能存储100条设定！",L"提示",0);
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


void CL2KeyDlg::OnBnClickedButton2() //清空list
{
	
}


void CL2KeyDlg::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case 1://搜索鼠标下窗口的timer
		{
			isFinding=true;//正在查找
			CString str;
			long hwnd;
			hwnd=GetCurWindow();
			if (hwnd != 0)
			{
				str.Format(_T("%p"),hwnd);
				
				char szWindowTitle[500];
				::GetWindowTextA((HWND)hwnd, szWindowTitle, sizeof(szWindowTitle));  // 获取窗口标题
				CString str2(szWindowTitle);
				edit_1 =L"窗口标题:【" + str2 + L"】, 句柄：【" + str + L"】";
				if (str2 == "L2Key" || str2=="开始发送" || str2== "停止发送")
				{
					edit_1="";
					//m_poswindowname=""; //此变量不使用
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
			UpdateData(0); //把值传送到控件
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
			edit_1=L"窗口【 " + strTargetName + L" 】正在接受按键消息！";
		}
	}//switch end
	UpdateData(0); //把值传送到控件中
	CDialogEx::OnTimer(nIDEvent);
}


long CL2KeyDlg::GetCurWindow(void)
{
HWND hwndPointNow = NULL;
  POINT pNow = {0,0};
  if (GetCursorPos(&pNow))  // 获取鼠标当前位置
  {
   hwndPointNow = ::WindowFromPoint(pNow);  // 获取鼠标所在窗口的句柄
  }
  Sleep(10);
  return long(hwndPointNow);
}


void CL2KeyDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	KillTimer(1);
	isFinding=false;
	edit_2.EnableWindow(true);
///	edit_3.EnableWindow(false);
//	edit_2.ShowWindow(1);
//	edit_3.ShowWindow(0);
	edit_1="";
	UpdateData(0); //把值传送到控件中...坑爹的函数哥都忘了
}


void CL2KeyDlg::OnBnClickedRadio2() //鼠标选找窗口radio
{
	// TODO: 在此添加控件通知处理程序代码
	edit_2.EnableWindow(false);
//	edit_3.EnableWindow(true);
	//edit_3.ShowWindow(1);
	if (isRunning == false) //如果此时没有控制中的窗口
		SetTimer(1,1000,NULL);//就设置为开始查找
	else
		KillTimer(1);//停止查找功能
	edit_1="";
	UpdateData(0); //把值传送到控件中...坑爹的函数哥都忘了
}


void CL2KeyDlg::OnBnClickedButton3() //开始发送.停止发送 按钮
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	UpdateData(1); //从控件中读取值到变量
	long hwnd;
	Sleep(200);
	if (config_num == 0) 
	{
		m_button3.SetWindowTextW(L"开始发送");
		isRunning=false;
		KillTimer(1);
		edit_1=L"没有窗口接受按键消息！";
		MessageBox((CString)"请至少添加一个发送设置！",L"提示",0);
	}else
	{
		if (isRunning==false) //如果现在没有控制窗口
		{
			{
				hwnd=GetWindowHwnd(strTargetName);
			}
			if (hwnd != 0)
			{
				str.Format(_T("%p"),hwnd);
				//edit_1 = L"正在控制：" + str;
				KillTimer(1);
				isFinding=false;//设置为停止查找标志
				m_button3.SetWindowTextW(L"停止发送");
				isRunning=true;//设置为正在控制标志

				//for (int i=0;i<config_num; i++) //根据添加按钮中添加的次数，在此增加timer的数量
				//{
				//	float ftime;
				//	ftime=_wtof(config_array[i].time);//把CString类型的时间转换为float类型
				//	SetTimer(i+2,ftime*1000,NULL);/////----------------------------------------------------------now
				//}
			
			}
			else
			{
				edit_1="";
				MessageBox((CString)"没有找到名为【 " +strTargetName+ (CString)" 】的窗口！",L"提示",0);
			}
		}
		else //如果现在正在控制某窗口，点击后将成为停止控制的状态
		{
			//KillTimer(2);
			for (int i=1; i<=config_num+1; i++)
			{
				KillTimer(i);
			}
			m_button3.SetWindowTextW(L"开始发送");
			isRunning=false;
			edit_1=L"没有窗口接受按键消息！";
		}
	}
	UpdateData(0);
}


void CL2KeyDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CL2KeyDlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CL2KeyDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码

}


void CL2KeyDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
}
