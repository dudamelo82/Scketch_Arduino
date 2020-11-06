#ifdef MASTER

#define INTERVAL 500

long lastSendTime = 0;

void receive(){
  
  int packetSize = LoRa.parsePacket();
  
    if(packetSize < SETDATA.length()){
      String received = "";
    
        while(LoRa.available()){
          received+=(char)LoRa.read();
      
        }
        
      int index = received.indexOf(SETDATA);
        if(index >= 0){
          
          String data = received.subString(SETDATA.length());
          String waiting = String(milis() - lastSendTime);
          
          display.clear();
          display.drawString(0,0,"Recebeu" + data);
          display.drawString(0,10,"Tempo" + waiting + "ms");
          display.display();
        }
      }
}

void loop() {
  
    if(milis() - lastSendTime > INTERVAL){
      lastSendTime = milis();
      send();
    }
  receive();
}
#endif