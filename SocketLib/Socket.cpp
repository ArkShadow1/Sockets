#include "Socket.hpp"

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

TCPClient::TCPClient(const char* inAddr, USHORT inPort)
{
	_service.sin_family = AF_INET;
	_service.sin_addr.s_addr = inet_addr(inAddr);
	_service.sin_port = htons(inPort);
}

bool TCPClient::Connect()
{
	if( connect( _socket._hSocket, (SOCKADDR*)&_service, sizeof(_service) ) == SOCKET_ERROR)
		return false;
	return true;
}

TCPServer::TCPServer(const char* inAddr, USHORT inPort)
{
	_service.sin_family = AF_INET;
	_service.sin_addr.s_addr = inet_addr(inAddr);
	_service.sin_port = htons(inPort);
}



bool TCPServer::Accept()
{
	accept(_accept._hSocket,NULL,NULL);
}

