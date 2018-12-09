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
#include <string>

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
	int delayTime = 35;
	int sampleSize = 3;
	float vals[sampleSize + 2];
	int ch;
	//serialPutchar(fd, 'p');
	for(int i = 0; i < (sampleSize + 2); i++) {
		string ph;
		while(serialGetchar(fd) != '[')
			delay(delayTime);
		while((ch = serialGetchar(fd)) != ']') {
			ph += ch;
			delay(delayTime);
		}
		vals[i] = stof(ph);
	}
	float averagePh = 0.0;
	for(int i = 2; i < sampleSize + 2; i++) {
		averagePh = averagePh + vals[i];
	}
	averagePh = averagePh/(float)sampleSize;
	return std::to_string(averagePh);
}

string piSer::getTDS() {
	int delayTime = 35;
	int sampleSize = 3;
	float vals[sampleSize + 2];
	int ch;
	//serialPutchar(fd, 'p');
	for(int i = 0; i < (sampleSize + 2); i++) {
		string tds;
		while(serialGetchar(fd) != '<')
			delay(delayTime);
		while((ch = serialGetchar(fd)) != '>') {
			tds += ch;
			delay(delayTime);
		}
		vals[i] = stof(tds);
	}
	float averagePh = 0.0;
	for(int i = 2; i < sampleSize + 2; i++) {
		averagePh = averagePh + vals[i];
	}
	averagePh = averagePh/(float)sampleSize;
	return std::to_string(averagePh);
}


//string piSer::getPH() {
//	string ph;
//	char ch;
//	//serialPutchar(fd, 'p');
//	while(serialGetchar(fd) != '[')
//		delay(100);
//	while((ch = serialGetchar(fd)) != ']') {
//		ph += ch;
//		delay(100);
//	}
//	return ph;
//}










//float piSer::getTDS() {
//	//serialPutchar(fd, 'p');
//	//sensorValue = serialGetchar(fd);
//	//float phValue = sensorValue*(14.0/1023.0);
//	return getPH();
//}