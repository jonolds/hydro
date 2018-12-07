/*** C++ ***/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <wiringSerial.h>

int main () {
  int fd;

  if((fd=serialOpen("/dev/ttyACM0",9600))<0){
    fprintf(stderr,"Unable to open serial device: %s\n",strerror(errno));
    return 1;
  }

  serialFlush(fd);
  while(true) {
	serialPutchar(fd, 'p');
    putchar(serialGetchar(fd));

    fflush(stdout);
	
  }
  usleep(900000);
}

/*** ARDUINO ***/

void setup() {
    Serial.begin(9600); //opens serial port, sets data rate to 9600 baud
}

void loop() {

    if(Serial.available()>0) {
		strnSerial.readString()
        int sensorValue = analogRead(A0);
        float voltage = sensorValue * (14.0/1023.0);
        Serial.println(voltage);
    }
    else {
        Serial.println("no Request");
    }
    delay(2000);
}

/***  OUTPUT ***/
pppppppppppp
12.13
ppppppppppppppppppppp
12.13
pppppppppppppppppppppppppppppp
12.13
ppppppppppppppppppppppppppppppppppppppp
12.13
pppppppppppppppppppppppppppppppppppppppppppppppp
12.11
ppppppppppppppppppppppppppppppppppppppppppppppppppppppppp
12.13
ppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp
12.13
ppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp
12.13
ppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp
12.13
