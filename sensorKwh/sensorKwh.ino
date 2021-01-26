#include <PZEM004Tv30.h>

PZEM004Tv30 pzem(11, 12);

void setup() {
   Serial.begin(115200);
   Serial1.begin(9600);
}

void loop() {
     float voltage = pzem.voltage();
     if(voltage != NAN){
         Serial.print("Voltage: "); 
         Serial.print(voltage);
         Serial.println("V");
         
         Serial1.print("{\"V\":");
         Serial1.print(voltage);
         Serial1.print("}");
         delay(60000);
          
     } else {
         Serial.println("Error reading voltage");
     }

     float current = pzem.current();
     if(current != NAN){
         Serial.print("Current: ");
         Serial.print(current);
         Serial.println("A");
         
         Serial1.print("{\"A\":");
         Serial1.print(current);
         Serial1.print("}");
         delay(60000);
         
     } else {
         Serial.println("Error reading current");
     }

     float power = pzem.power();
     if(current != NAN){
         Serial.print("Power: ");
         Serial.print(power);
         Serial.println("W");

         Serial1.print("{\"W\":");
         Serial1.print(power);
         Serial1.print("}");
         delay(60000);
         
     } else {
         Serial.println("Error reading power");
     }

     float energy = pzem.energy();
     if(current != NAN){
         Serial.print("Energy: ");
         Serial.print(energy,3);
         Serial.println("kWh");

         Serial1.print("{\"KWH\":");
         Serial1.print(energy);
         Serial1.print("}");
         delay(60000);
         
     } else {
         Serial.println("Error reading energy");
     }

     float frequency = pzem.frequency();
     if(current != NAN){
         Serial.print("Frequency: ");
         Serial.print(frequency, 1);
         Serial.println("Hz");
     } else {
         Serial.println("Error reading frequency");
     }

     float pf = pzem.pf();
     if(current != NAN){
         Serial.print("PF: ");
         Serial.println(pf);

         Serial1.print("{\"FactorP\":");
         Serial1.print(pf);
         Serial1.print("}");
         delay(60000);

         
     } else {
         Serial.println("Error reading power factor");
     }

     Serial.println();
     delay(2000);
 }
