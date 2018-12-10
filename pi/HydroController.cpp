#include "HydroController.h"
#include <chrono>

#include <cerrno>


using namespace std;


void HydroController::start() {}

void HydroController::cycle() {}

long HydroController::getEpochstamp() {
	return chrono::system_clock::to_time_t(chrono::system_clock::now()); 
}

std::string HydroController::epochToTimeDate(long epoch) {
	return ctime(&epoch);
}
