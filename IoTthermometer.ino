#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

void setup() 
{
  pinMode(2,INPUT_PULLUP);
  pinMode(5,OUTPUT);
  Serial.begin(115200);
  dht.begin();
}

void loop()
{
  delay(2000);
  float p = analogRead(2);
  float t2 = map(p,0,4095,0,30);
  float t = dht.readTemperature();
  if (isnan(t)) 
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  if (t2 > t)
  {
    digitalWrite(5,HIGH);
  }
  else
    digitalWrite(5,LOW);
  Serial.print("temperature: ");
  Serial.println(t);
  Serial.print("Chosen temperature: ");
  Serial.println(t2);
}
