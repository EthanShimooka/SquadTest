/*
Sending and Receiving Packets Example (Simple version!)
From "Networking for Game Programmers" - http://www.gaffer.org/networking-for-game-programmers
Author: Glenn Fiedler <gaffer@gaffer.org>
*/
#include <iostream>
#include <string>

#include "Net.h"
#include "Socket.h"

using namespace std;
using namespace net;

int main(int argc, char * argv[]){
	// initialize socket layer

	if (!InitializeSockets()){
		cout << "failed to initialize sockets" << endl;
		return 1;
	}
	// create socket

	int port = 30001;

	cout << "creating socket on port " << port << endl;

	Socket socket;

	if (!socket.Open(port)){
		cout << "failed to create socket!" << endl;
		return 1;
	}

	// send and receive packets to ourself until the user ctrl-breaks...
	char data[255];
	cout << "type something: ";
	while (cin.getline(data, 256)){
		//char data[] = "Hello World!";
		//cout << data;

		Address ip(127, 0, 0, 1, 30000);

		socket.Send(ip, data, sizeof(data));

	}
	// shutdown socket layer

	//ShutdownSockets();

	return 0;
}
