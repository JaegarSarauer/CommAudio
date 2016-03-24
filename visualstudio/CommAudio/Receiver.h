#pragma once

#define MAXLEN					65000	//Buffer length
#define DATA_BUFSIZE			1024
#define COMM_TIMEOUT			1000

typedef struct _SOCKET_INFORMATION {
	OVERLAPPED Overlapped;
	SOCKET Socket;
	CHAR Buffer[DATA_BUFSIZE*64];
	INT Head = 0;
	INT Tail = 0;
	WSABUF DataBuf;
	DWORD BytesSEND;
	DWORD BytesRECV;
	DWORD Timeout;

} SOCKET_INFORMATION, *LPSOCKET_INFORMATION;

DWORD WINAPI startUDPServer(LPVOID);
DWORD WINAPI startTCPServer(LPVOID);
void cleanUpServer();