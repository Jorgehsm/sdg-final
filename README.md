# 💡 Controle de LED com ESP32-C3 Supermini via MQTT e Encoder

Projeto desenvolvido como trabalho final da disciplina **Sistemas Embarcados II / Sistemas Digitais**.

O dispositivo consiste em um **ESP32-C3 Supermini** que controla o brilho de uma LED de alto brilho por **PWM**, onde o **duty cycle** pode ser ajustado de duas formas:
- **Remotamente** via protocolo **MQTT**  
- **Localmente** por meio de um **encoder rotativo com botão**  

---

## 🚀 Funcionalidades
- Controle de brilho da LED (0–255) por PWM (5 kHz, 8 bits de resolução)  
- Alteração de estado da LED (ON/OFF)  
- Ajuste de duty cycle via:
  - MQTT (tópicos `status` e `brilho`)  
  - Encoder rotativo local  
- Comunicação MQTT feita com a biblioteca [PubSubClient](https://pubsubclient.knolleary.net/)  
- Broker MQTT implementado com **Mosquitto**  

---

## 🛠️ Componentes utilizados
- **ESP32-C3 Supermini** (11 GPIOs, suporte a PWM, UART, I2C, SPI)  
- **Encoder rotativo com botão** (20 pulsos por revolução, leitura em quadratura)  
- **LED 5mm alto brilho** + resistor de limitação calculado (330 Ω) 

---

## 📐 Esquema de conexões

| Dispositivo   | GPIO |
|---------------|------|
| Encoder A     | 10   |
| Encoder B     | 20   |
| Encoder Switch| 21   |
| LED           | 3    |

---

## 📲 Interface MQTT
- **Broker**: Mosquitto rodando em um notebook com Ubuntu  
- **Cliente**: Aplicativo **IoT MQTT Panel**  
- **Tópicos**:  
  - `status` → controla estado da LED (ON/OFF)  
  - `brilho` → controla duty cycle (0–255)  

---
#     Protoboard e resultado final

<p align="center">
  <img src="https://github.com/user-attachments/assets/416bcfc9-3e4c-4d5c-9a4d-5d09253b523a" alt="Imagem 1" width="848" height="606"/>
  <img src="https://github.com/user-attachments/assets/f7b8dcc7-d59a-44d1-8ae3-8b9ada1bedd9" alt="Resultado final" width="848" height="606"/>
</p>

---

## 🔧 Programação da ESP32-C3 Supermini
> ⚠️ Importante: a placa **não possui conversor USB** integrado.  
Para colocar no modo bootloader:
1. Pressione e segure o botão **BOOT**  
2. Pressione o botão **RST**  
3. Solte o botão **BOOT**  
4. Faça upload do código  
5. Pressione ambos **BOOT + RST** e solte juntos para executar
