#include <wiringSerial.h>
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {
	int ser = serialOpen("/dev/ttyUSB0",115200);
	while(true) {

		serialPutchar(ser, 'C');
		if(serialGetchar(ser) ==  '[') {
			string s = "";
			while(serialDataAvail(ser) > 0)
				s+= (char)serialGetchar(ser);
			cout << s << "\n";
			usleep(500);
		}
	}
	serialClose(ser);
}