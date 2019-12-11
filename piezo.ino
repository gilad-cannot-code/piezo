// these constants won't change:

const int piezo = A0; // the piezo is connected to analog pin 0
//const int threshold = 100;  // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int piezoReading = 0;      // variable to store the value read from the sensor pin
int tones = 0;

void setup() {
  Serial.begin(9600);       // use the serial port
}

void loop() {
  // read the piezo and store it in the variable piezoReading:
    piezoReading = analogRead(piezo);

//  Serial.println(piezoReading);

    // map to tones
    tones = map(piezoReading, 10, 100, 0, 500);
    // second to is frequency range
    
    Serial.println(tones);

    tone(12, tones);
    // 12 is digital pin the output is connected to, make sure this digital pin is connected to the audio jack
  delay(100);  // delay to avoid overloading the serial port buffer

  if (tones >= 50){

    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(13,LOW);
  }
}
