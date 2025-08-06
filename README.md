Repositório destinado ao projeto final da matéria de sistemas digitais

O sistema proposto é composto por um ESP32, encoder incremental e LED
O encoder possui um botão e é utilizado para ligar/desligar a LED, assim como controlar seu brihlo
Foi feita uma interface em **** onde também é possível controlar o LED. A troca de informações entre ESP32 e interface acontece via MQTT.
Um broker mosquitto foi implementado para comunicação MQTT
