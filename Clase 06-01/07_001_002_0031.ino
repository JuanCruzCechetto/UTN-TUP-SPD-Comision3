 	
#include <IRremote.h>

const int RECV_PIN = 2;
const int led = 13;
unsigned int power = 255;
int estadoConfiguracion = 0;
int estadoFoco = 0;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); 
}

void loop() {
 
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    
    if (results.decode_type == NEC) {
      Serial.print("NEC: ");
    } else if (results.decode_type == SONY) {
      Serial.print("SONY: ");
    } else if (results.decode_type == RC5) {
      Serial.print("RC5: ");
    } else if (results.decode_type == RC6) {
      Serial.print("RC6: ");
    } else if (results.decode_type == UNKNOWN) {
      Serial.print("UNKNOWN: ");
    }
    Serial.println(value);
   
    if(value == power && estadoFoco == 0){	
      Serial.print("ON ");
     digitalWrite(led, HIGH);
      estadoFoco = 1;	
    }else if(value == power && estadoFoco == 1 ){ 
      Serial.print("OFF ");
      digitalWrite(led, LOW); 
      estadoFoco = 0;			
    }
    if(estadoConfiguracion == 1){ 
      power = results.value;		
      estadoConfiguracion = 0;		
      Serial.println("configurando");
    } 
    
    if(value == 12495){				
      estadoConfiguracion = 1; 
      Serial.print("estado");
    }
    
    
    irrecv.resume(); 
    
    
  
  }
  
}
