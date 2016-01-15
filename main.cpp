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

	int port = 30000;

	cout << "creating socket on port " << port << endl;

	Socket socket;

	if (!socket.Open(port)){
		cout << "failed to create socket!" << endl;
		return 1;
	}

	// send and receive packets to ourself until the user ctrl-breaks...
	
	while (true){

		char data[] = "Hello World!";

		Address ip(127, 0, 0, 1, port);

		socket.Send(ip, data, sizeof(data));

		while (true){
			Address sender;
			unsigned char buffer[256];
			int bytes_read = socket.Receive(sender, buffer, sizeof(buffer));
			if (!bytes_read)
				break;
			printf("received packet from %d.%d.%d.%d:%d (%d bytes)\n",
				sender.GetA(), sender.GetB(), sender.GetC(), sender.GetD(),
				sender.GetPort(), bytes_read);
		}
		socket.wait(0.25f);
	}
	// shutdown socket layer

	ShutdownSockets();

	return 0;
}
