#pragma once

#define IDOFROUTER1 1
#define IDOFROUTER2 2
#define IDOFROUTER3 3
struct Routing {
	CString aimHost;
	CString nextHop;
	unsigned short nextHopPort;
};
class Setting
{
public:
	Setting();
	~Setting();
	int m_idOfRouter;
	unsigned short m_hostPort;
	unsigned short m_routerPort;
	CString m_hostIP;
	CString m_routerIP;
	CString aimHost1;
	CString aimHost2;
	CString m_host;
	Routing routing1;
	Routing routing2;
	Setting(int idOfRouter);


	CString host1IP;
	CString host2IP;
	CString host3IP;
	CString router1IP;
	CString router2IP;
	CString router3IP;
};

