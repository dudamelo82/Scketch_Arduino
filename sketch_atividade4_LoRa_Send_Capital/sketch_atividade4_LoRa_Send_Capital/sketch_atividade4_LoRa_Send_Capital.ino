/*LoRa sender*/#include<SPI.h>/*comunicação serial*/#include<LoRa.h>/*comunicação wifi*/#include<Wire.h>/*comunicação i2c*/#include "SSD1306.h"/*comunicação com o display*//*Definição dos pinos*/#define SCK 5#define MISO 19#define SS 18#define RST 14#define DI00 26 /*Interrompe a requisição*/#define BAND 915E6 /*Frequencia de radio - Podemos usar também a 433E6 e a 868E6*/#define PABOOST trueunsigned int counter = 0;SSD1306 display(0x3c,4,15);/*Construtor do objeto que controla o display*/String rssi = "RSSI --"String packSize = "--"String packet;void setup() {  // Configura os pinos de saidapinMode(16, OUTPUT);pinMode(25,OUTPUT);digitalWrite(16,LOW);//Resetdelay(50);digitalWrite(16,HIGH);display.init(); //inicializa o displaySPI.begin(SCK,MISO,MOSSI,SS);// Inicia a comunicaçãoLoRa.setPins(SS,RST,DI00);/*Verificando se o display iniciou corretamente*/if(!LoRa.begin(BAND,PABOOST)){  display.drawString(0,0,"Erro ao iniciar o LoRa");  display.display();//Mostra o conteúdo na telawhile(1);  }display.drawString(0,0,"LoRa iniciado com sucesso!");display.display();delay(1000);    }void loop() {  /*Apaga o conteúdo do display*/display.clear();display.drawString(0,0,"Enviando")display.drawString(40,26,String(counter));display.display();LoRa.beginPacket();LoRa.print("Hello World!");LoRa.print(counter);LoRa.endPacket();counter++;digitalWrite(25, HIGH);// Liga o LED indicativodelay(500);digitalWrite(25,LOW);//Desliga o LED indicativodelay(500);    }