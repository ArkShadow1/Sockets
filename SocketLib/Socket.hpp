#pragma once

#include <iostream>
#include <WinSock2.h>
#pragma comment (lib,"ws2_32.lib")
#include "WSAAutoClean.hpp"
#include <iostream>

class TCPSocket
{
public:
	SOCKET _hSocket;
	TCPSocket(void);
	~TCPSocket(void);

	void Send();
	void Recv();
};

class Client
{
public:
	virtual ~Client();
	virtual bool Connect();
	virtual void Send();
};

class TCPClient : public Client
{
	sockaddr_in _service;
	TCPSocket _socket;
public:
	TCPClient(const char* inAddr, USHORT inPort);
	~TCPClient();

	bool Connect();
};

class TCPServer //: public Server
{
	sockaddr_in _service;
	TCPSocket _listen;
	TCPSocket _accept;
public:
	TCPServer(const char* inAddr, USHORT inPort);
	~TCPServer();

	bool Accept();
	void Listen();
	void Send();
};