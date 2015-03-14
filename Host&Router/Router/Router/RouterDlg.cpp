
// RouterDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Router.h"
#include "RouterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CRouterDlg 对话框



CRouterDlg::CRouterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRouterDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRouterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_table);
	DDX_Control(pDX, IDC_EDIT1, m_message);
}

BEGIN_MESSAGE_MAP(CRouterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CRouterDlg 消息处理程序

BOOL CRouterDlg::OnInitDialog()
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	setting = new Setting();
	InitUI();
	InitEnvironment();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CRouterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRouterDlg::OnPaint()
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
HCURSOR CRouterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRouterDlg::InitUI()
{
	switch (setting->m_idOfRouter){
	case IDOFROUTER1:
		AfxGetMainWnd()->SetWindowText("Router1");
		break;
	case IDOFROUTER2:
		AfxGetMainWnd()->SetWindowText(_T("Router2"));
		break;
	case IDOFROUTER3:
		AfxGetMainWnd()->SetWindowText(_T("Router3"));
		break;

	}
	DWORD dwStyle = m_table.GetExtendedStyle();                    //添加列表框的网格线

	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_table.SetExtendedStyle(dwStyle);

	
	m_table.InsertColumn(0,"目标主机",LVCFMT_LEFT,140);
	m_table.InsertColumn(1, "下一跳", LVCFMT_LEFT,140);
	m_table.InsertItem(0, setting->routing1.aimHost);
	m_table.SetItemText(0, 1, setting->routing1.nextHop);
	m_table.InsertItem(1, setting->routing2.aimHost);
	m_table.SetItemText(1, 1, setting->routing2.nextHop);
	m_table.InsertItem(2, setting->m_host);
	m_table.SetItemText(2, 1, "-");
	//m_table.InsertItem(1, "1.2");
	//m_table.SetItemText(0, 1, setting->routing1.nextHop);

	//m_table.InsertItem(2, "2.1");
	//m_table.SetItemText(2, 1, setting->routing2.aimHost);
	//m_table.InsertItem(3, "2.2");
	//m_table.SetItemText(3, 1, setting->routing2.nextHop);

	//m_table.InsertItem(4, "3.1");
	//m_table.SetItemText(4, 1, setting->m_host);
	//m_table.InsertItem(5, "3.2");
	//m_table.SetItemText(5, 1,"-");


	
}

UINT RecvThread(LPVOID lpParm)
{
	CRouterDlg *dlg = (CRouterDlg*)lpParm;
	char gcInBuffer[1027];
	int length;
	int size = sizeof(sockaddr_in);
	CString strReceive, tempStr;
	while (1)
	{
		if ((length = recvfrom(dlg->m_sock, gcInBuffer, 1024, 0, (struct sockaddr *)&dlg->m_desAddr, &size))>0)
		{
			CString strReceive;
			gcInBuffer[length] = '\0';
			strReceive += gcInBuffer;
			CString temp;
			dlg->m_message.GetWindowTextA(temp);
			CString originalHost;
			CString data;
			CString desHost;
			AfxExtractSubString(originalHost, strReceive, 0, '/');
			AfxExtractSubString(data, strReceive, 1, '/');
			AfxExtractSubString(desHost, strReceive, 2, '/');
			temp += originalHost;
			temp += "->";
			temp += desHost;
			temp += ":";
			temp += data;
			temp += "\r\n";
			dlg->m_message.SetWindowText(temp);
			unsigned short aimPort;
			if (desHost.Compare(dlg->setting->m_host) == 0)
				aimPort = dlg->setting->m_hostPort;
			else if(desHost.Compare(dlg->setting->routing1.aimHost)==0)
				aimPort = dlg->setting->routing1.nextHopPort;
			else
				aimPort = dlg->setting->routing2.nextHopPort;



			struct sockaddr_in addr;
			addr.sin_family = AF_INET;
			addr.sin_port = htons(aimPort);
			addr.sin_addr.s_addr = inet_addr(dlg->setting->m_routerIP);
			sendto(dlg->m_sock, strReceive, strlen(strReceive), 0, (struct sockaddr*)&addr, sizeof(sockaddr));
		}
	}
	return 0;
}
void CRouterDlg::InitEnvironment()
{
	WSADATA	wsaData; //存储被WSAStartup函数调用后返回的Windows sockets数据
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		MessageBox("WSAStartup ERROR!");
	}
	//创建套接字UDP连接，AF_INET表示使用IPV4协议，SOCK_DGRAM是无连接报文类型，默认UDP协议
	if ((m_sock = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
	{
		MessageBox("ERROR: Create Server Socket Error!");
		exit(-1);
	}
	struct sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(setting->m_routerPort);
	serAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	if ((bind(m_sock, (LPSOCKADDR)&serAddr, sizeof(serAddr))) == SOCKET_ERROR)
	{
		MessageBox("ERROR: Bind Socket Error!");
		exit(-1);
	}
	AfxBeginThread(RecvThread, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
}
