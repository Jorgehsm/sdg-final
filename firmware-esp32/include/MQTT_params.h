#ifndef MQTT_PARAMS
#define MQTT_PARAMS

const char *ssid = "Jorge";
const char *password = "12345678";

IPAddress staticIP(10, 42, 0, 20);
IPAddress gateway(10, 42, 0, 255);    
IPAddress subnet(255, 255, 255, 0);   

const char *mqtt_server = "10.42.0.1";
const char *topic_onoff = "status";
const char *topic_brilho = "brilho";

#endif