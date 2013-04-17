#pragma once

#include <iostream>
#include <WinSock2.h>
#pragma comment (lib,"ws2_32.lib")
#include "WSAAutoClean.hpp"
#include <iostream>
#if defined(_DEBUG) && !defined(_DLL)
#pragma comment (lib,"SocketLib-mt-sgd.lib")
#endif

class TCPSocket
{
	WSAAutoClean wsaAutoClean;
public:
	SOCKET _hSocket;
	TCPSocket(void);
	~TCPSocket(void);

	TCPSocket Accept();
	void Send();
	void Recv();
};

class TCPClient //: public Client
{
	static unsigned int const MAX = 256;
	char _buf[MAX];

	sockaddr_in _service;
	TCPSocket _socket;
public:
	TCPClient(const char* inAddr, USHORT inPort);
	~TCPClient();

	//template <typename T>
	int Send(char data[]);

	bool Connect();
};

class TCPServer //: public Server
{
	sockaddr_in _service;
	TCPSocket _listen;
public:
	TCPSocket _accept;
	TCPServer(const char* inAddr, USHORT inPort);
	~TCPServer();

	//void Accept();
	bool ServerListen();
	bool ServerBind();
	//void Send();
};