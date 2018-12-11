#ifndef PI_SERIAL
#define PI_SERIAL
#include <string>


class piSerial {
public:
	int fd;
	const int baud = 9600;
	const char* deviceName = "/dev/ttyACM0";

	int delayTime = 35;
	int sampleSize = 3;

	piSerial();
	std::string getPH();
	std::string getTDS();
};

#endif