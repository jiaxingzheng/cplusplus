#include "stdafx.h"
#include "Setting.h"

#define HOST1PORT 8081
#define HOST2PORT 8083
#define HOST3PORT 8085
#define ROUTER1PORT 8082
#define ROUTER2PORT 8084
#define ROUTER3PORT 8086

#define HOST1 "Host1";
#define HOST2 "Host2"
#define HOST3 "Host3"
#define ROUTER1 "Router1"
#define ROUTER2 "Router2"
#define ROUTER3 "Router3"
Setting::Setting()
{
	CFile file;
	file.Open("setting.txt", CFile::modeRead, NULL);
	char buf[200];
	UINT length = file.Read(buf, 200);
	file.Close();
	buf[length] = '\0';
	CString temp;
	temp += buf;
	AfxExtractSubString(host1IP, temp, 0);
	AfxExtractSubString(host2IP, temp, 1);
	AfxExtractSubString(host3IP, temp, 2);
	AfxExtractSubString(router1IP, temp, 3);
	AfxExtractSubString(router2IP, temp, 4);
	AfxExtractSubString(router3IP, temp, 5);
	CString id;
	AfxExtractSubString(id, temp, 6);
	m_idOfRouter = _ttoi(id);
	switch (m_idOfRouter){
	case IDOFROUTER1:
		m_host = HOST1;
		m_hostPort = HOST1PORT;
		m_hostIP = host1IP;
		m_routerPort = ROUTER1PORT;
		m_routerIP = router1IP;
		aimHost1 = HOST2;
		aimHost2 = HOST3;
		routing1.nextHop = ROUTER2;
		routing1.nextHopPort = ROUTER2PORT;
		routing2.nextHop = ROUTER2;
		routing2.nextHopPort = ROUTER2PORT;
		break;
	case IDOFROUTER2:
		m_host = HOST2;
		m_hostPort = HOST2PORT;
		m_hostIP = host2IP;
		m_routerPort = ROUTER2PORT;
		m_routerIP = router2IP;
		aimHost1 = HOST1;
		aimHost2 = HOST3;
		routing1.nextHop = ROUTER1;
		routing1.nextHopPort = ROUTER1PORT;
		routing2.nextHop = ROUTER3;
		routing2.nextHopPort = ROUTER3PORT;
		break;
	case IDOFROUTER3:
		m_host = HOST3;
		m_hostPort = HOST3PORT;
		m_hostIP = host3IP;
		m_routerPort = ROUTER3PORT;
		m_routerIP = router3IP;
		aimHost1 = HOST1;
		aimHost2 = HOST2;
		routing1.nextHop = ROUTER2;
		routing1.nextHopPort = ROUTER2PORT;
		routing2.nextHop = ROUTER2;
		routing2.nextHopPort = ROUTER2PORT;
		break;
	}
	routing1.aimHost = aimHost1;
	routing2.aimHost = aimHost2;
}


Setting::~Setting()
{
}


Setting::Setting(int idOfRouter)
{
}
