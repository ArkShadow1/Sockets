#pragma once
#include <iostream>
#include <WinSock2.h>
#pragma comment (lib,"ws2_32.lib")
#if defined(_DEBUG) && !defined(_DLL)
#pragma comment (lib,"SocketLib-mt-sgd.lib")
#endif
class WSAAutoClean
{
	static int count;
public:
	WSAAutoClean(void);
	~WSAAutoClean(void);
};

