// Codigo Ejemplo
int Led_Pin = 3;
int Fot_Pin = A0;
int sensorValue = 0;
int outputValue = 0;
int Led_Pin2 = 5;
int Fot_Pin2 = A1;
int sensorValue2 = 0;
int outputValue2 = 0;
void setup()
{
Serial.begin(9600);
pinMode(Led_Pin, OUTPUT);
Serial.begin(9600);
pinMode(Led_Pin2, OUTPUT);
}
void loop()
{
 digitalWrite(Led_Pin, HIGH);
 sensorValue = analogRead(Fot_Pin);
 outputValue = map(sensorValue, 0, 1023, 0, 255);
 analogWrite(Led_Pin, outputValue);
 Serial.print("Lectura: ");
 Serial.println(sensorValue);
 Serial.print("Mapeado: ");
 Serial.println(outputValue);
 delay(250);
 digitalWrite(Led_Pin, LOW);
 delay(250);
 sensorValue = analogRead(A1);
 outputValue = map(sensorValue, 0, 1023, 0, 255);  
 analogWrite(Led_Pin2, outputValue);
 Serial.print("Lectura = ");
 Serial.print(sensorValue2);
 Serial.print("Mapeado: = ");
 Serial.println(outputValue2);
 delay(250);
}