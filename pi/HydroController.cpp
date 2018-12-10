#include "HydroController.h"
#include <chrono>
#include <wiringPi.h>
#include <cerrno>
#include <iostream>

using namespace std;


void HydroController::start() {
	while(true) {
		 cout << "ph:  " << ps.getPH() << "\n";
		 cout << "tds: " << ps.getTDS() << "\n";
	 }
}

void HydroController::cycle() {}

bool HydroController::setPump(bool) {
	// TODO: add code to toggle pump GPIO pin
	return pump_ON;
}

bool HydroController::setLight(bool) {
	// TODO: add code to toggle light GPIO pin
	return light_ON;
}

long HydroController::getEpochstamp() {
	return chrono::system_clock::to_time_t(chrono::system_clock::now()); 
}

std::string HydroController::epochToTimeDate(long epoch) {
	return ctime(&epoch);
}
