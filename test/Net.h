/*
Simple Network Library from "Networking for Game Programmers"
http://www.gaffer.org/networking-for-game-programmers
Author: Glenn Fiedler <gaffer@gaffer.org>
*/

#ifndef NET_H
#define NET_H

// platform detection

#define PLATFORM_WINDOWS  1
#define PLATFORM_MAC      2
#define PLATFORM_UNIX     3

#if defined(_WIN32)
#define PLATFORM PLATFORM_WINDOWS
#elif defined(__APPLE__)
#define PLATFORM PLATFORM_MAC
#else
#define PLATFORM PLATFORM_UNIX
#endif

#if PLATFORM == PLATFORM_WINDOWS

#include <winsock2.h>
#pragma comment( lib, "wsock32.lib" )

#elif PLATFORM == PLATFORM_MAC || PLATFORM == PLATFORM_UNIX

#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

#else

#error unknown platform!

#endif


namespace net{
	// sockets

	inline bool InitializeSockets(){
		if (PLATFORM == PLATFORM_WINDOWS){
			WSADATA WsaData;
			return WSAStartup(MAKEWORD(2, 2), &WsaData) == NO_ERROR;
		}
		return true;
	}

	inline void ShutdownSockets(){
		if (PLATFORM == PLATFORM_WINDOWS){
			WSACleanup();
		}
	}
}

#endif
