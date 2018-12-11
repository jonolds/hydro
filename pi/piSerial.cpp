#include "piSerial.h"
#include <wiringSerial.h>
#include <cstdio>
#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <wiringPi.h>
#include <cstdio>

using namespace std;

piSerial::piSerial() {
	fd = serialOpen(deviceName, baud);
	if(fd < 0) {
		fprintf(stderr,"Unable to open serial device: %s\n",strerror(errno));
		exit(1);
	}
	serialDataAvail(fd);
}

string piSerial::getPH() {

	float vals[sampleSize + 2];
	int ch;
	for(int i = 0; i < (sampleSize + 2); i++) {
		string ph;
		while(serialGetchar(fd) != '[')
			delay(delayTime);
		while((ch = serialGetchar(fd)) != ']') {
			ph += (char)ch;
			delay(delayTime);
		}
		vals[i] = stof(ph);
	}
	float averagePh = 0.0;
	for(int i = 2; i < sampleSize + 2; i++)
		averagePh += vals[i];

	averagePh /= (float)sampleSize;
	return to_string(averagePh);
}

string piSerial::getTDS() {
	float vals[sampleSize + 2];
	int ch;
	for(int i = 0; i < (sampleSize + 2); i++) {
		string tds;
		while(serialGetchar(fd) != '<')
			delay(delayTime);
		while((ch = serialGetchar(fd)) != '>') {
			tds += (char)ch;
			delay(delayTime);
		}
		vals[i] = stof(tds);
	}
	
	float averagePh = 0.0;
	for(int i = 2; i < sampleSize + 2; i++)
		averagePh += vals[i];

	averagePh /= (float)sampleSize;
	return to_string(averagePh);
}