#include "WSAAutoClean.hpp"


WSAAutoClean::WSAAutoClean(void)
{
	if (count == 0)
	{
		WSADATA wsaData;
		int iResult = WSAStartup( MAKEWORD(2,2), &wsaData);
		if(iResult != 0)
		{
			std::cerr<< "WSAStartup failed: " << iResult << std::endl;
		}
	}
	++count;
}


WSAAutoClean::~WSAAutoClean(void)
{
	--count;
	if (count == 0)
		WSACleanup();
}

//initialize the bla count to 0 for linker
int WSAAutoClean::count =0;