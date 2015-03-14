#pragma once

#define IDOFHOST1 1
#define IDOFHOST2 2
#define IDOFHOST3 3
class Setting
{
public:
	Setting();
	~Setting();
	int m_idOfHost;
	unsigned short m_hostPort;
	unsigned short m_routerPort;
	CString m_hostIP;
	CString m_routerIP;
	CString aimHost1;
	CString aimHost2;
	CString m_host;


	CString host1IP;
	CString host2IP;
	CString host3IP;
	CString router1IP;
	CString router2IP;
	CString router3IP;
};

