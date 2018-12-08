#ifndef PI_SER
#define PI_SER

#include <cstdio>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <iostream>

#include <wiringSerial.h>

class piSer {
public:
	int fd;
	const int baud = 9600;
	const char* deviceName = "/dev/ttyAMA0";

	piSer();
	const int getSerialConnection();
	float getPH();
	float getTDS();
};

#endif
