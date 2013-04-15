#pragma once
#include <iostream>
#include <WinSock2.h>
#pragma comment (lib,"ws2_32.lib")

class WSAAutoClean
{
	static int count;
public:
	WSAAutoClean(void);
	~WSAAutoClean(void);
};

