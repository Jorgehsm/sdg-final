#include <Arduino.h>
#include <MQTT.h>
#include <Config.h>  

void setup() {
  Serial.begin(115200);
  
  ledcSetup(LED_CHANNEL, LED_FREQ, LED_RES);
  ledcAttachPin(LED_PIN, LED_CHANNEL);

  setup_wifi();
  mqtt_connect();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
} 