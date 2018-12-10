#ifndef HYDRO_CONTROLLER
#define HYDRO_CONTROLLER
#include <iosfwd>
#include <string.h>
#include "piSer.h"


class HydroController {
public:
	piSer ps;

	HydroController() = default;
	void start();
	void cycle();
	long getEpochstamp();
	std::string epochToTimeDate(long epoch);


};

#endif