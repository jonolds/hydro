#include "HydroController.h"
#include <chrono>
#include <wiringPi.h>
#include <cerrno>
#include <iostream>
#include <unistd.h>

using namespace std;


void HydroController::start() {
	string ph, tds;
	while(true) {
		cout << "ph:  " << (ph = ps.getPH()) << "\n";
		cout << "tds: " << (tds = ps.getTDS()) << "\n";
		updateServer(ph, tds);
		sleep(5);
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

std::string HydroController::getPH() {
	return ps.getPH();
}

std::string HydroController::getTDS() {
	return ps.getTDS();
}

void HydroController::updateServer(string ph, string tds) {
	string command = "curl \"http://csce.uark.edu/~jolds/hydro/test.php?ph=" + ph + "&tds=" + tds + "\"";
	system(command.c_str());
}