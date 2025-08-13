#ifndef MQTT_H
#define MQTT_H

#include <WiFi.h>
#include <PubSubClient.h>
#include <Config.h>
#include <stdint.h>
#include <Encoder.h>

void setup_wifi();
void callback(char* topic, byte* payload, unsigned int length);
void reconnect();
void mqtt_connect();

//extern WiFiClient espClient;
extern PubSubClient client;

#endif