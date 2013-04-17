#include <Socket.hpp>
#include<iostream>
using namespace std;

int main()
{
	TCPServer serv("127.0.0.1",USHORT(13000));
	if(serv.ServerBind())
	{
		cout << "Server boundeded..." <<endl;
		if(serv.ServerListen())
		{
			cout << "Server listeninining...." <<endl;
		}
	}
	unsigned int const MAX = 256;
	char buf[MAX];

	int bytesRecv = recv( serv._accept._hSocket,(char*)&buf, MAX, 0);

	cout << "Recieved " << bytesRecv << " bytes" << endl;
	cout << "Msg: " << buf << endl;
}

