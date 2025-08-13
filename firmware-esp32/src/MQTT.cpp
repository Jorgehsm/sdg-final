#include <MQTT.h>
#include <MQTT_params.h>

WiFiClient espClient;
PubSubClient client(espClient);

void mqtt_connect()
{
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
}

void setup_wifi()
{
    delay(10);
    Serial.println();
    Serial.print("Conectando-se a ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi conectado");
    Serial.println("IP: ");
    Serial.println(WiFi.localIP());
}

void callback(char *topic, byte *payload, unsigned int length)
{
    String msg;
    for (int i = 0; i < length; i++)
    {
        msg += (char)payload[i];
    }
    msg.trim();

    Serial.print("Mensagem recebida [");
    Serial.print(topic);
    Serial.print("]: ");
    Serial.println(msg);

    if (String(topic) == topic_onoff)
    {
        if (msg.equalsIgnoreCase("ON"))
        {
            ledState = true;
            ledcWrite(LED_CHANNEL, counter);
        }
        else if (msg.equalsIgnoreCase("OFF"))
        {
            ledState = false;
            ledcWrite(LED_CHANNEL, 0);
        }
    }

    if (String(topic) == topic_brilho)
    {
        int valor = msg.toInt();
        if (valor >= 0 && valor <= 255)
        {
            counter = valor;
            if (ledState)
            {
                ledcWrite(LED_CHANNEL, counter);
            }
        }
    }
}

void reconnect()
{
    while (!client.connected())
    {
        Serial.print("Tentando conectar ao MQTT...");
        if (client.connect("ESP32Client"))
        {
            Serial.println("Conectado");
            client.subscribe(topic_onoff);
            client.subscribe(topic_brilho);
        }
        else
        {
            Serial.print("Falha, rc=");
            Serial.print(client.state());
            Serial.println(" Tentando novamente em 5 segundos");
            delay(5000);
        }
    }
}