#include "piSer.h"
#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

int main() {
	piSer ps;

	while(true) {
		string ph = ps.getPH();
		cout << ph << "\n";
		fflush(stdout);
	}
}