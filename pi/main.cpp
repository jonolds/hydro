#include "piSer.h"
#include <iostream>
#include <string.h>
#include <cstring>
#include <chrono>

using namespace std;

int main() {
	 piSer ps;


	auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now()); 
  
    cout << ctime(&timenow) << endl; 

	 while(true) {
		 cout << "ph:  " << ps.getPH() << "\n";
		 cout << "tds: " << ps.getTDS() << "\n";
	 }
}