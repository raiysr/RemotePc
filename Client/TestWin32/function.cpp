
#include "pch.h"
#include "function.h"

SOCKET s;


int InitSocket()
{
	//windows ��ʼ������
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	//��ʼ������
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return 0;
	}

	//  socket ����һ���׽���

	s = socket(
		AF_INET,       //INETЭ���
		SOCK_STREAM,   //��ʾʹ��TCPЭ��
		0);

	if (s == INVALID_SOCKET)
	{
		return 0;
	}

	return 1;
}