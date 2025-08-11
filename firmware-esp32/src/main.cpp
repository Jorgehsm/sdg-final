#include <WiFi.h>
#include <PubSubClient.h>


const char* ssid = "SUA_REDE_WIFI";
const char* password = "SUA_SENHA_WIFI";


const char* mqtt_server = "...";
const char* topic_onoff = "meu_led/onoff";
const char* topic_brilho = "meu_led/brilho";

WiFiClient espClient;
PubSubClient client(espClient);


#define LED_PIN 5       
#define LED_CHANNEL 0   
#define LED_FREQ 5000   
#define LED_RES 8       

int brilho = 0;         
bool ledLigado = false; 


void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado");
  Serial.println("IP: ");
  Serial.println(WiFi.localIP());
}


void callback(char* topic, byte* payload, unsigned int length) {
  String msg;
  for (int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }
  msg.trim();

  Serial.print("Mensagem recebida [");
  Serial.print(topic);
  Serial.print("]: ");
  Serial.println(msg);

  if (String(topic) == topic_onoff) {
    if (msg.equalsIgnoreCase("ON")) {
      ledLigado = true;
      ledcWrite(LED_CHANNEL, brilho);
    } 
    else if (msg.equalsIgnoreCase("OFF")) {
      ledLigado = false;
      ledcWrite(LED_CHANNEL, 0);
    }
  }

  if (String(topic) == topic_brilho) {
    int valor = msg.toInt();
    if (valor >= 0 && valor <= 255) {
      brilho = valor;
      if (ledLigado) {
        ledcWrite(LED_CHANNEL, brilho);
      }
    }
  }
}


void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conectar ao MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("Conectado");
      client.subscribe(topic_onoff);
      client.subscribe(topic_brilho);
    } else {
      Serial.print("Falha, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  
  ledcSetup(LED_CHANNEL, LED_FREQ, LED_RES);
  ledcAttachPin(LED_PIN, LED_CHANNEL);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
} 