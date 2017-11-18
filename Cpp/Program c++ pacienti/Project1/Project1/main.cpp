#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include "SerialPort.h"
#include <unordered_map>
#include <string>
#include <vector>
//#include <mysql_common.h>
//#include <mysql_devapi.h>
//#include <mysql_driver.h>
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/resultset.h>
//#include <cppconn/statement.h>
//#include <mysql_xapi.h>

using std::cout;
using std::endl;

/*Portname must contain these backslashes, and remember to
replace the following com port*/
char *port_name = "\\\\.\\COM3";

//String for incoming data
char incomingData[MAX_DATA_LENGTH];


//void SimpleQuery() {
//	sql::mysql::MySQL_Driver *driver;
//	sql::Connection *con;
//	sql::Statement *stmt;
//
//	driver = sql::mysql::get_mysql_driver_instance();
//	con = driver->connect("tcp://127.0.0.1:3306", "user", "password");
//
//	stmt = con->createStatement();
//	stmt->execute("USE  EXAMPLE_DB");
//	stmt->execute("DROP TABLE IF EXISTS test");
//	stmt->execute("CREATE TABLE test(id INT, label CHAR(1))");
//	stmt->execute("INSERT INTO test(id, label) VALUES (1, 'a')");
//
//	delete stmt;
//	delete con;
//}

std::unordered_map < std::string, std::vector<double> > copiiInternati;
std::string comanda;

int main(int argc, char** argv) {
	SerialPort arduino(port_name);
	if (arduino.isConnected()) cout << "Connection Established" << endl;
	else cout << "ERROR, check port name";

	//arduino.writeSerialPort("3", 1);

	for (int i = 0; i < 50 && arduino.isConnected(); i++) {
		arduino.writeSerialPort("@", 1);
		//Check if data has been read or not
		int read_result = arduino.readSerialPort(incomingData, MAX_DATA_LENGTH);
		//prints out data
		//printf("%s\n", incomingData);
		//wait a bit
		Sleep(500);
		cout << "Data recieved\n";
	}

	while (arduino.isConnected()) {
		arduino.writeSerialPort("@",1);
		//Check if data has been read or not
		int read_result = arduino.readSerialPort(incomingData, MAX_DATA_LENGTH);
		//prints out data
		//printf("%s\n",incomingData);
		comanda = "D:/Work/Important work/Polihack/POLIHACK/Python/insert.py " + read_result;
		system(comanda.c_str());
		//wait a bit
		Sleep(500);
		cout << "Data recieved\n";
	}

	system("PAUSE");
	return 0;
}