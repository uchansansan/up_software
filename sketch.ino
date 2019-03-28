#define PIN_TRIG 12 
#define PIN_ECHO 11 
#define SPEED_2 6 
#define DIR_2 7 
long duration, cm; 

void setup() { 

pinMode(PIN_TRIG, OUTPUT); 
pinMode(PIN_ECHO, INPUT); 
pinMode(6, OUTPUT); 
pinMode(7, OUTPUT); 
} 

void loop() { 

digitalWrite(PIN_TRIG, LOW); 
delayMicroseconds(5); 
digitalWrite(PIN_TRIG, HIGH); 

delayMicroseconds(10); 
digitalWrite(PIN_TRIG, LOW); 

duration = pulseIn(PIN_ECHO, HIGH); 

cm = (duration / 2) / 29.1; 
if (cm<=20){ 
digitalWrite(DIR_2, LOW); 
analogWrite(SPEED_2, 255); 
} 
else if (cm<=40 && cm>20){ 
digitalWrite(DIR_2, HIGH); 
analogWrite(SPEED_2, 255); 
} 
else if (cm>40){ 

analogWrite(SPEED_2, 0); 
} 
delay(250); 
}
