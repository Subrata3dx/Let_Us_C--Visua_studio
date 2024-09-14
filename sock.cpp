#include<iostream>
#include<winsock.h>
#define PORT 9909

using namespace std;

struct sockaddr_in srv;
fd_set fr, fw, fe;
int nMaxFd;



int main()
{

	int nRet = 0;

	//Initialize the WSA variables
	WSADATA ws;
	if (WSAStartup(MAKEWORD(2, 2), &ws) < 0)
	{
		cout << endl << "WSA failed to initialized.";
	}
	else
	{
		cout << endl << "WSA initialized.";
	}

	// Initialize the socket
	int nSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (nSocket < 0)
	{
		cout << endl << "The Socket not opened.";
	}
	else
	{
		cout << endl << "The socket opened successfully. "<<nSocket;
	}

	//Initialize the environment for sockaddr structure
	srv.sin_family = AF_INET;
	srv.sin_port = htons(PORT);
	//srv.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	srv.sin_addr.s_addr = INADDR_ANY;
	memset(&(srv.sin_zero), 0, 8);

	//Bind the socket to the local port
	nRet = bind(nSocket, (sockaddr*)&srv, sizeof(sockaddr));
		if(nRet < 0)
		{
			cout << endl << " Fail to bind to the local port";
			exit(EXIT_FAILURE);
		}
		else
		{
			cout << endl << "Successfully bind to the local port";
		}

	// Listten to the request from client (queues the requests)
	nRet = listen(nSocket, 5);
		if (nRet < 0)
		{
			cout << endl << " Failed to start listen to the local port";
			exit(EXIT_FAILURE);
		}
		else
		{
			cout << endl << "Started lisstening to the local port";
		}
		

		nMaxFd = nSocket;
		struct timeval tv;
		tv.tv_sec = 1;
		tv.tv_usec = 0;

		
		while (1)
		{
			FD_ZERO(&fr);
			FD_ZERO(&fw);
			FD_ZERO(&fe);

			FD_SET(nSocket, &fr);
			FD_SET(nSocket, &fe);

			cout << endl << "Before select call:" << fr.fd_count;

			// Keep waiting for new requests and proceed as per the request
			nRet = select(nMaxFd + 1, &fr, &fw, &fe, &tv);
			if (nRet > 0)
			{
				//when someone connnects or communicate with a message over a dedicated connection
			}

			else if (nRet == 0)
			{
				//No connection or any communication request made or you can say that none of the socket descriptors are ready
				cout << endl << "Nothing on port " << PORT;
			}
			else
			{
				//it failed and your application should show some useful message
				cout << endl << " I failded";
				exit(EXIT_FAILURE);
			}

			cout << endl << "After the select call:" << fr.fd_count;
			Sleep(1000);
		}
}