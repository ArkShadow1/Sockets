#include <Socket.hpp>
#include <exception>

TCPSocket::TCPSocket(void)
{
	_connection = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
	if( _connection == INVALID_SOCKET ) {
		std::cerr << "Error: socket(): " << WSAGetLastError() << std::endl;
	}
	_service.sin_family = AF_INET;
	_service.sin_addr.s_addr = inet_addr("127.0.0.1");
	_service.sin_port = htons(12000);
}

TCPSocket::TCPSocket(LPCSTR inAddr, USHORT inPort)
{
	_connection = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
	if( _connection == INVALID_SOCKET ) {
		std::cerr << "Error: socket(): " << WSAGetLastError() << std::endl;
	}

	_service.sin_family = AF_INET;
	_service.sin_addr.s_addr = inet_addr(inAddr);
	_service.sin_port = htons(inPort);
}

TCPSocket::~TCPSocket(void)
{
	closesocket( _connection );
}

SOCKET TCPSocket::GetMainHandle()
{
	return _connection;
}
SOCKET TCPSocket::GetMessageHandle()
{
	return _message;
}
void TCPSocket::Accept()
{
	_message = SOCKET_ERROR;
	while(_message == SOCKET_ERROR)
	{
		_message = accept(_connection,NULL,NULL);
	}
}
bool TCPSocket::Bind()
{
	if( bind(_connection,(SOCKADDR*)&_service,sizeof(_service))!=SOCKET_ERROR )
	{
		return true;
	}
	std::cerr << "Failed to bind() " << WSAGetLastError() << std::endl;
	return false;

}
void TCPSocket::Connect()
{
	if( connect( _connection, (SOCKADDR*)&_service, sizeof(_service) ) == SOCKET_ERROR)
	{	std::cerr <<"Error: Connect() " << WSAGetLastError() <<std::endl;}
	//std::cerr << "ERROR: Connect() " << WSAGetLastError() << std::endl;	
}

bool TCPSocket::Listen()
{
	if(listen(_connection,SOMAXCONN)!=SOCKET_ERROR)
		return true;
	return false;
}

void TCPSocket::Send(char data[])
{
	strcpy_s(_buf,"Hello");
	int t = send(_connection,_buf,strlen(_buf)+1,0);
	int i =t;
}

void TCPSocket::Recv()
{

}
///******************CLIENT***************/
//TCPClient::TCPClient(const char* inAddr, USHORT inPort)
//{
//	_service.sin_family = AF_INET;
//	_service.sin_addr.s_addr = inet_addr(inAddr);
//	_service.sin_port = htons(inPort);
//}
//
//bool TCPClient::Connect()
//{
//	if( connect( _socket._connection, (SOCKADDR*)&_service, sizeof(_service) ) != SOCKET_ERROR)
//		return true;
//	std::cerr << "ERROR: Connect() " << WSAGetLastError() << std::endl;
//	return false;
//	
//}
//
//
//int TCPClient::Send(char data[])
//{
//	strcpy_s(_buf,data);
//	return send(_socket._connection,(const char*)&_buf,strlen(_buf)+1,0);
//}
//
//TCPClient::~TCPClient(void){}
//
//
///******************SERVER***************/
//TCPServer::TCPServer(const char* inAddr, USHORT inPort)
//{
//	_service.sin_family = AF_INET;
//	_service.sin_addr.s_addr = inet_addr(inAddr);
//	_service.sin_port = htons(inPort);
//}
//
//bool TCPServer::ServerBind()
//{
//	if(bind(_listen._connection, (SOCKADDR*)&_service, sizeof(_service)) != SOCKET_ERROR)
//		return true;
//	std::cerr << "ERROR: ServerBind() " << WSAGetLastError() << std::endl;
//	return false;
//}
//
//bool TCPServer::ServerListen()
//{
//	if(listen(_listen._connection,1)!=SOCKET_ERROR)
//	{
//		_accept = _listen.Accept();
//		return true;
//	}
//	std::cerr << "ERROR: ServerListen() " << WSAGetLastError() << std::endl;
//	return false;
//}
//
// TCPServer::~TCPServer(void){}
//
