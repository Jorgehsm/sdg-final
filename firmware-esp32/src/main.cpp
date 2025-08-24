#include <Arduino.h>
#include <MQTT.h>
#include <config.h>
#include <encoder.h>

void setup()
{
  Serial.begin(115200);

  ledcSetup(LED_CHANNEL, LED_FREQ, LED_RES);
  ledcAttachPin(LED_PIN, LED_CHANNEL);
  ledcWrite(LED_CHANNEL, 0);


  //setup_wifi();
  //mqtt_connect();
}

void loop()
{
 /* if (!client.connected())
  {
    reconnect();
  }
  client.loop();
  */

  if (ledState)
  {
    ledcWrite(LED_CHANNEL, counter);
  }
  else if (!ledState)
  {
    ledcWrite(LED_CHANNEL, 0);
  }

  Serial.print(ledState);
  Serial.print(", ");
  Serial.println(counter);
}