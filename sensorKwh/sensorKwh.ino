#include <PZEM004Tv30.h>
#define id "123456789"

SoftwareSerial Serial1(10, 11); // RX, TX
PZEM004Tv30 pzem(8,9);

void setup() {
   Serial.begin(115200);
   Serial1.begin(9600);
}

void loop() {
     float voltage = pzem.voltage();
     if(voltage != NAN){
         Serial.print("{\"V");
         Serial.print(id);
         Serial.print("\":");
         Serial.print(voltage);
         Serial.print(","); 
         
         Serial1.print("{\"V");
         Serial1.print(id);
         Serial1.print("\":");
         Serial1.print(voltage);
         Serial1.print(","); 
          
     } else {
         Serial.println("Error reading voltage");
     }

     float current = pzem.current();
     if(current != NAN){
         
         Serial.print("\"A");
         Serial.print(id);
         Serial.print("\":");
         Serial.print(current);
         Serial.print(","); 
      
         Serial1.print("\"A");
         Serial1.print(id);
         Serial1.print("\":");
         Serial1.print(current);
         Serial1.print(","); 
       
         
     } else {
         Serial.println("Error reading current");
     }

     float power = pzem.power();
     if(current != NAN){

         Serial.print("\"W");
         Serial.print(id);
         Serial.print("\":");
         Serial.print(power);
         Serial.print(",");

         Serial1.print("\"W");
         Serial1.print(id);
         Serial1.print("\":");
         Serial1.print(power);
         Serial1.print(",");
         
     } else {
         Serial.println("Error reading power");
     }

     float energy = pzem.energy();
     if(current != NAN){

         Serial.print("\"KWH");
         Serial.print(id);
         Serial.print("\":");
         Serial.print(energy);
         Serial.print(","); 

         Serial1.print("\"KWH");
         Serial1.print(id);
         Serial1.print("\":");
         Serial1.print(energy);
         Serial1.print(",");
         
     } else {
         Serial.println("Error reading energy");
     }


     float pf = pzem.pf();
     if(current != NAN){

         Serial.print("\"FactorP");
         Serial.print(id);
         Serial.print("\":");
         Serial.print(pf);
         Serial.print("}");

         Serial1.print("\"FactorP");
         Serial1.print(id);
         Serial1.print("\":");
         Serial1.print(pf);
         Serial1.print("}");
         delay(5000);

         
     } else {
         Serial.println("Error reading power factor");
     }

     Serial.println();
     delay(2000);
 }
