
#include "pch.h"
#include "function.h"

SOCKET s;


int InitSocket()
{
	//windows 初始化网络
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	//初始化操作
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		return 0;
	}

	//  socket 创建一个套接字

	s = socket(
		AF_INET,       //INET协议簇
		SOCK_STREAM,   //表示使用TCP协议
		0);

	if (s == INVALID_SOCKET)
	{
		return 0;
	}

	return 1;
}