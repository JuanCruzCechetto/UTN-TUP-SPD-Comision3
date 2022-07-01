// C++ code
//
// Código Ejemplo
int Led_Pin = 13;
void setup()
{
// Configurar Pin como Salida
pinMode(Led_Pin, OUTPUT);
}
void loop()
{
// Encender Led
digitalWrite(Led_Pin, HIGH);
// Esperar 1 Segundo
delay(1000);
// Apagar Led
digitalWrite(Led_Pin, LOW);
// Esperar 1 Segundo
delay(1000);
}