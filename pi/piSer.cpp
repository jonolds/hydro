#include "piSer.h"

using namespace std;

piSer::piSer() {
	fd = getSerialConnection();
}

const int piSer::getSerialConnection() {
	int fd = serialOpen(deviceName, baud);
	if(fd < 0) {
		fprintf(stderr,"Unable to open serial device: %s\n",strerror(errno));
		exit(1);
	}
	cout << "fd: " << fd << endl;
	return fd;
}

float piSer::getPH() {
	serialPuts(fd, "ph");
	int sensorValue = serialGetchar(fd);
	cout << "sensorValue: " << sensorValue << "\n";
	float phValue = sensorValue*(14.0/1023.0);
	return phValue;
}

float piSer::getTDS() {
	//serialPutchar(fd, 'p');
	//sensorValue = serialGetchar(fd);
	//float phValue = sensorValue*(14.0/1023.0);
	return getPH();
}
