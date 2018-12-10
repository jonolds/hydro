#ifndef PI_SER
#define PI_SER
#include <iosfwd>
#include <string>


class piSer {
public:
	int fd;
	const int baud = 9600;
	const char* deviceName = "/dev/ttyACM0";

	int delayTime = 35;
	int sampleSize = 3;

	piSer();
	std::string getPH();
	std::string getTDS();
};

#endif