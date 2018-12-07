#include <wiringPi.h>
int main (void) {
	wiringPiSetup () ;
	pinMode (0, OUTPUT) ;
	for (;;) {
		digitalWrite (0, HIGH) ; delay (3000) ;
		digitalWrite (0,	LOW) ; delay (3000) ;
	}
	return 0 ;
}