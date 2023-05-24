// This #include statement was automatically added by the Particle IDE.
#include <HC_SR04.h>


int led = D7;  // The on-board LED
int trigPin = D4;
int echoPin = D5;

double distance = 25.0;   
double minDist = 10.0; 
double rangeInCm;
String parked = "no";

HC_SR04 rangeFinder = HC_SR04(trigPin, echoPin);

void setup()
{
	Serial.begin(9600);       
}

void loop()
{
    delay(200);
    Serial.print(parked);
    
        delay(300);
        rangeInCm = rangeFinder.getDistanceCM();   
        Serial.print(rangeInCm);        
        Serial.println(" centimeters");
        delay(300);
        
        
        Particle.publish("ultra", String(rangeInCm), PRIVATE);
        if(float(rangeInCm) < 20)
        {
            digitalWrite(led, HIGH);
        }
        else
        {
            digitalWrite(led, LOW);
        }
        
    
        // if(rangeInCm < distance && rangeInCm > minDist)
        // {
        //   parked = "yes";
        //   Particle.publish("ultra", String(rangeInCm), PRIVATE);
        // }
        // else
        // {
        //   parked = "no";
        //   Particle.publish("ultra", String(rangeInCm), PRIVATE);

}
