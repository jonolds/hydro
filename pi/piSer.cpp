#include "piSer.h"
#include <wiringSerial.h>
#include <drcSerial.h>
#include <cstdio>
#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <wiringPi.h>
#include <cstdio>

using namespace std;

piSer::piSer() {
	fd = serialOpen(deviceName, baud);
	if(fd < 0) {
		fprintf(stderr,"Unable to open serial device: %s\n",strerror(errno));
		exit(1);
	}
	serialDataAvail(fd);
}

string piSer::getPH() {
	cout << "in getPH().\n";
	string ph;
	char ch;
	while(serialDataAvail(fd)) {
		putchar(ch = serialGetchar(fd));
		ph += ch;
		delay(100);
	}
	
	return ph;
}

//float piSer::getTDS() {
//	//serialPutchar(fd, 'p');
//	//sensorValue = serialGetchar(fd);
//	//float phValue = sensorValue*(14.0/1023.0);
//	return getPH();
//}