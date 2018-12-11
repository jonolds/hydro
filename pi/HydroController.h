#ifndef HYDRO_CONTROLLER
#define HYDRO_CONTROLLER
#include "piSerial.h"

class HydroController {
public:
	//STATE
	bool pump_ON;
	bool light_ON;

	//SETTINGS


	piSerial ps;

	HydroController() = default;
	void start();
	void cycle();

	bool setPump(bool);
	bool setLight(bool);

	void updateServer(std::string, std::string);
	static long getEpochstamp();
	static std::string epochToTimeDate(long epoch);

	std::string getPH();
	std::string getTDS();
};

#endif