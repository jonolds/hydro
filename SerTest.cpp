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
	serialPutchar(fd, 'a');
    putchar(serialGetchar(fd));

    fflush(stdout);
	
  }
  usleep(2000);
}
