#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <ArduinoJson.h>

#define DHTPIN 2 //

#define DHTTYPE DHT11 // DHT 11
DHT_Unified dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  delay(1500);

  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature))
  {
    Serial.println(F("Error de lectura de temperatura"));
  }
  else
  {
    Serial.print(F("Temperatura: "));
    Serial.print(event.temperature);
    Serial.println(F(" Â°C"));
  float temperatura = dht.readTemperature();
  }
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity))
  {
    Serial.println(F("Error de lectura de humedad"));
  }
  else
  {
    Serial.print(F("Humedad: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  float humedad = dht.readHumidity();
  }
  StaticJsonDocument<200> doc;
  doc["Temperatura:"] = temperatura;
  doc["Humedad:"] = humedad;
  
  serializeJson(doc, Serial);
  Serial.println();
  
  delay(1000);
}
