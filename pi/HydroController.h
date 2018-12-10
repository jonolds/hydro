#ifndef HYDRO_CONTROLLER
#define HYDRO_CONTROLLER
#include "piSer.h"


class HydroController {
public:
	//STATE
	bool pump_ON;
	bool light_ON;

	//SETTINGS




	piSer ps;

	HydroController() = default;
	void start();
	void cycle();

	bool setPump(bool);
	bool setLight(bool);


	static long getEpochstamp();
	static std::string epochToTimeDate(long epoch);
};

#endif