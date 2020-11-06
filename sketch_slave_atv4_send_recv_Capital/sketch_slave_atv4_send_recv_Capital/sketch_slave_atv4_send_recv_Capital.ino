#ifdef MASTER

  int count = 0;
  
  void setup(){
    Serial.begin(115200);
    
    setupDisplay();
    setupLoRa();
    display.clear();
    display.drawString(0,0,"Slave esperando");
    display.display();
    
  }
  
  void loop(){
     int packetSize = LoRa.parsePacket();
     
     if(packetSize == GETDATA.length()){
       
       String received = "";
       
        while(LoRa.available()){
          
          received += (char)LoRa.read();
          
        }
        
        if(received.equals(GETDATA)){
          String data = readData();
          Serial.println("Criando pacote para envio");
          
          LoRa.beginPacket();
          LoRa.print(SETDATA + data);
          
          LoRa.endPacket();
          
          display.clear();
          display.drawString(0,0, "Enviou" + String(data));
          display.display();
        }
       
     }
     
  }
  String readData(){
    return Strign(count++);
  }
  #endif