

void setup() {
    Serial.begin(9600);
}

void loop() {
    printf("hi");
    if(Serial.available() > 0) {
        String reqType = Serial.readString();
        
        if(reqType == "ph")
            Serial.println(analogRead(A0));
        else
            Serial.println(analogRead(A0));
        delay(2000);
    }
    else {
        Serial.println("no req");
        delay(2000);
    }
    
}
