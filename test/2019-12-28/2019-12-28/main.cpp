#include <iostream>
#include <string.h>
#include <winsock2.h>
#include <ws2ipdef.h>
#include <mstcpip.h>
#include <process.h>
#include "packdef.h"

#pragma comment (lib,"ws2_32.lib")

using namespace std;

int main()
{
	//1.���ؿ�
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {

		printf("WSAStartup failed with error: %d\n", err);
		return 1;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {

		printf("Could not find a usable version of Winsock.dll\n");
		WSACleanup();
		return 1;
	}
	else
		printf("The Winsock 2.2 dll was found okay\n");

	//����ԭʼ�׽���
	SOCKET sniffersock;
	sniffersock = socket(AF_INET, SOCK_RAW/*ԭʼ�׽���*/, IPPROTO_IP);
	if (INVALID_SOCKET == sniffersock)
	{
		closesocket(sniffersock);
		WSACleanup();
	}

	//��ȡ��������
	char hostname[DEFAULT_NAMELEN];
	if (SOCKET_ERROR == gethostname(hostname, DEFAULT_NAMELEN))
	{
		cout << "��ȡ������ʧ��" << endl;
		WSACleanup();
		return 1;
	}

	//��ȡ��������IP��ַ
	HOSTENT* local;
	local = gethostbyname(hostname);
	if (NULL == local)
	{
		cout << "��ȡ����IP��ַʧ��" << endl;
		WSACleanup();
		return 1;
	}
	//�������IP
	cout << "��������IP��ַ��" << endl;
	int i = 0;
	int num;
	IN_ADDR myAddr;
	while (local->h_addr_list[i] != 0)
	{
		myAddr.s_addr = *(u_long*)local->h_addr_list[i++];
		cout << i << ":  " << inet_ntoa(myAddr) << endl;
	}
	//����sock����ѡIP��
	cout << "ѡ��ʹ�õĽӿں�" << endl;
	cin >> num;
	SOCKADDR_IN localAddr;
	localAddr.sin_family = AF_INET;
	localAddr.sin_port = 0;
	memset(&localAddr.sin_addr.S_un.S_addr, 0, sizeof(localAddr.sin_addr.S_un.S_addr));
	memcpy(&localAddr.sin_addr.S_un.S_addr, local->h_addr_list[num - 1],
		sizeof(localAddr.sin_addr.S_un.S_addr));

	if (SOCKET_ERROR == bind(sniffersock, (const sockaddr*)&localAddr, sizeof(localAddr)))
	{
		closesocket(sniffersock);
		WSACleanup();
		return 1;
	}

	//���������ڻ���ģʽ��������������
	u_long sioarg = 1;
	DWORD dwValue = 0;
	if (SOCKET_ERROR == WSAIoctl(sniffersock, SIO_RCVALL, &sioarg, sizeof(sioarg), NULL, 0, &dwValue, NULL, NULL))
	{
		closesocket(sniffersock);
		return 1;
	}

	//��ʼ��������  
	cout << "��ʼ��������" << endl << endl;
	//�������� ��ȡ���ݰ���Ϣ
	sockaddr_in clientAddr;
	int nsize = sizeof(clientAddr);
	int len = 0;
	char buf[DEF_PACKDEFSIZE] = { 0 };
	while (1)
	{
		len = recv(sniffersock, buf, DEF_PACKDEFSIZE, 0);
		if (len > 0)
		{
			IPHEAD iphead = *(IPHEAD*)buf;
			cout << "�汾��:" << (iphead.version_hl >> 4) << endl;
			cout << "�ײ�����:" << (iphead.version_hl & 15) << endl;
			cout << "����:" << iphead.tot_len << endl;
			cout << "Э��:" << (int)iphead.protocol << endl;
			cout << "Դ��ַ:" << inet_ntoa(*(in_addr *)&iphead.saddr) << endl;
			cout << "Ŀ�ĵ�ַ:" << inet_ntoa(*(in_addr *)&iphead.daddr) << endl;
			cout << endl;
		}
		else
			cout << "����ʧ��" << endl;
	}

	return 0;
}