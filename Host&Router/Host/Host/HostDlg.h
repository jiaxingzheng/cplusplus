
// Host1Dlg.h : 头文件
//

#pragma once
#include "Setting.h"
#include <WinSock2.h>
#include "afxwin.h"

// CHost1Dlg 对话框
class CHostDlg : public CDialogEx
{
// 构造
public:
	CHostDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_HOST1_DIALOG };

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
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	void InitUI();

private:
	Setting* setting;

public:
	SOCKET m_sock;
	struct sockaddr_in m_routerAddr;

public:
	void InitEnvironment();
	CEdit m_message;
	afx_msg void OnBnClickedButton1();

	CString m_dataToSend;
};
