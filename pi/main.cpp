#include "piSer.h"
#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

int main() {
	piSer ps;

	while(true) {
		const char* ph = ps.getPH().c_str() + 'n';
		cout << std::strlen(ph) << endl;
		printf("ph: %s", ph);
		fflush(stdout);
	}
}