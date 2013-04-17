#include <Socket.hpp>

TCPSocket::TCPSocket(void)
{
	_hSocket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
	if( _hSocket == INVALID_SOCKET ) {
		std::cerr << "Error: socket(): " << WSAGetLastError() << std::endl;
	}
}

TCPSocket::~TCPSocket(void)
{
	closesocket( _hSocket );
}

TCPSocket TCPSocket::Accept()
{
	TCPSocket newSocket;
	newSocket._hSocket = SOCKET_ERROR;
	while(newSocket._hSocket == SOCKET_ERROR)
	{
		newSocket._hSocket = accept(_hSocket,NULL,NULL);
	}
	return newSocket;
}

/******************CLIENT***************/
TCPClient::TCPClient(const char* inAddr, USHORT inPort)
{
	_service.sin_family = AF_INET;
	_service.sin_addr.s_addr = inet_addr(inAddr);
	_service.sin_port = htons(inPort);
}

bool TCPClient::Connect()
{
	if( connect( _socket._hSocket, (SOCKADDR*)&_service, sizeof(_service) ) != SOCKET_ERROR)
		return true;
	std::cerr << "ERROR: Connect() " << WSAGetLastError() << std::endl;
	return false;
	
}


int TCPClient::Send(char data[])
{
	strcpy_s(_buf,data);
	return send(_socket._hSocket,(const char*)&_buf,strlen(_buf)+1,0);
}

TCPClient::~TCPClient(void){}


/******************SERVER***************/
TCPServer::TCPServer(const char* inAddr, USHORT inPort)
{
	_service.sin_family = AF_INET;
	_service.sin_addr.s_addr = inet_addr(inAddr);
	_service.sin_port = htons(inPort);
}

bool TCPServer::ServerBind()
{
	if(bind(_listen._hSocket, (SOCKADDR*)&_service, sizeof(_service)) != SOCKET_ERROR)
		return true;
	std::cerr << "ERROR: ServerBind() " << WSAGetLastError() << std::endl;
	return false;
}

bool TCPServer::ServerListen()
{
	if(listen(_listen._hSocket,1)!=SOCKET_ERROR)
	{
		_accept = _listen.Accept();
		return true;
	}
	std::cerr << "ERROR: ServerListen() " << WSAGetLastError() << std::endl;
	return false;
}

 TCPServer::~TCPServer(void){}

