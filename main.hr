#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include "SerialPort.h"

using std::cout;
using std::endl;

/*Portname must contain these backslashes, and remember to
replace the following com port*/
char *port_name = "\\\\.\\COM3";

//String for incoming data
char incomingData[MAX_DATA_LENGTH];


int main(int argc, char** argv) {
	SerialPort arduino(port_name);
	if (arduino.isConnected()) cout << "Connection Established" << endl;
	else cout << "ERROR, check port name";

	while (arduino.isConnected()) {
		//Check if data has been read or not
		int read_result = arduino.readSerialPort(incomingData, MAX_DATA_LENGTH);
		//prints out data
		puts(incomingData);
		//wait a bit
		Sleep(10);
	}
	system("PAUSE");
	return 0;
}