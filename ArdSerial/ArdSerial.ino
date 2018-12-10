void setup() {
    Serial.begin(9600);
    while(!Serial) {;}
}

void loop() {

    String phWithTokens = '[' + String(getPH()) + ']';
    String tdsWithTokens = '<' + String(getTDS()) + '>';
    
    Serial.println(phWithTokens + tdsWithTokens);
    delay(200);
}

float getPH(){
    
    //Get int value from analog sensor. values range from 0 to 1023;
    int a0value = analogRead(A0);
    
    //convert raw analog value to scale from 0 to 14 (range of ph values)
    float ph = a0value * (14.0 / 1023.0);

    return ph;
}

float getTDS(){
    
    //Get int value from analog sensor. values range from 0 to 1023;
    int a1value = analogRead(A1);
    
    return a1value;
}
