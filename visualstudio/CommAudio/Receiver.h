#pragma once

#define MAXLEN					65000	//Buffer length
#define DATA_BUFSIZE			65000
#define COMM_TIMEOUT			1000

typedef struct _SOCKET_INFORMATION {
	OVERLAPPED Overlapped;
	SOCKET Socket;
	CHAR Buffer[DATA_BUFSIZE];
	WSABUF DataBuf;
	DWORD BytesSEND;
	DWORD BytesRECV;
	DWORD Timeout;

} SOCKET_INFORMATION, *LPSOCKET_INFORMATION;

DWORD WINAPI startUDPServer(LPVOID);
DWORD WINAPI startTCPServer(LPVOID);
void cleanUpServer();