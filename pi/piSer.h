#ifndef PI_SER
#define PI_SER
#include <iosfwd>
#include <string>


class piSer {
public:
	int fd;
	const int baud = 9600;
	const char* deviceName = "/dev/ttyACM1";

	piSer();
	std::string getPH();
	//float getTDS();
};

#endif