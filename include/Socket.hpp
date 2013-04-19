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
	WSAAutoClean _wsaAutoClean;
	sockaddr_in _service;
	SOCKET _connection;
	SOCKET _message;
	static const int MAX = 256;
	char _buf[MAX];
public:
	TCPSocket(void);
	TCPSocket(LPCSTR inAddr, USHORT inPort);
	~TCPSocket(void);

	void Accept();
	void Connect();
	bool Bind();
	bool Listen();

	void Send(char data[]);
	void Recv();

	SOCKET GetMainHandle();
	SOCKET GetMessageHandle();
};

//class TCPClient //: public Client
//{
//	static unsigned int const MAX = 256;
//	char _buf[MAX];
//
//	sockaddr_in _service;
//	TCPSocket _socket;
//public:
//	TCPClient(const char* inAddr, USHORT inPort);
//	~TCPClient();
//
//	//template <typename T>
//	int Send(char data[]);
//
//	bool Connect();
//};
//
//class TCPServer //: public Server
//{
//	sockaddr_in _service;
//	TCPSocket _listen;
//public:
//	TCPSocket _accept;
//	TCPServer(const char* inAddr, USHORT inPort);
//	~TCPServer();
//
//	//void Accept();
//	bool ServerListen();
//	bool ServerBind();
//	//void Send();
//};
//
