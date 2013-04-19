#include <Socket.hpp>
#include<iostream>
using namespace std;

int main()
{
	TCPSocket serv("127.0.0.1",USHORT(13000));
	if (serv.Bind())
	{
	if(serv.Listen())
		serv.Accept();
	else
	{
		std::cerr  << "ERROR: listen() " << WSAGetLastError() << std::endl;
		return 0;
	}
	}
	else
	{
		std::cerr << "ERROR: bind() " << WSAGetLastError() << std::endl;
		return 0;
	}
	unsigned int const MAX = 256;
	char buf[MAX];

	int bytesRecv = recv( serv.GetMessageHandle(),buf, strlen(buf), 0);

	cout << "Recieved " << bytesRecv << " bytes" << endl;
	cout << "Msg: " << buf << endl;
}

