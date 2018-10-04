#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  tulisEeprom("MKJAYA12");
  for(int i=0; i < 1024; i++){
    Serial.println(char(EEPROM.read(i)));
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

void tulisEeprom(String ID){
  int startIndex = bacaTerakhir();
  if(ID.length() == 8){
    tulis(startIndex, ID);
  } 
}

int bacaTerakhir(){
  for(int i=0; i<EEPROM.length(); i++){
    if(EEPROM.read(i) == 0){
      return i;
    }
  }
}

void tulis(int startIndex, String data){
  int indexData = startIndex%8;
  while(indexData < data.length()){
    EEPROM.write(startIndex, data[indexData]);
    startIndex ++;
    indexData ++;
  }
}

String bacaEeprom(int startIndex){
  String data = "";
  for(int i = startIndex; i<startIndex+8; i++){
    data.concat(char(EEPROM.read(i)));
  }
  return data;
}


