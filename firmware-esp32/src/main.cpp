#include <Arduino.h>
#include <MQTT.h>
#include <config.h>
#include <encoder.h>

void setup()
{
  Serial.begin(115200);

  encoderSetup();

  pinMode(LED_PIN, OUTPUT);

  setup_wifi();
  mqtt_connect();

  ledcSetup(LED_CHANNEL, LED_FREQ, LED_RES);
  ledcAttachPin(LED_PIN, LED_CHANNEL);
  ledcWrite(LED_CHANNEL, 0);
}

void loop()
{
  if (!client.connected())
  {
    reconnect();
  }
  client.loop();

  if (!digitalRead(ENC_SW))
  {
    encSwitch();
    pubState();
    delay(100);
  }

  if (ledState)
  {
    ledcWrite(LED_CHANNEL, counter);
  }
  else if (!ledState)
  {
    ledcWrite(LED_CHANNEL, 0);
  }

  pubBrilho();
  Serial.print(ledState);
  Serial.print(", ");
  Serial.println(counter);
  delay(100);
}