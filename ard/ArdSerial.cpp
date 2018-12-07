
using namespace std;

int main() {
    setup();
    loop();
}

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