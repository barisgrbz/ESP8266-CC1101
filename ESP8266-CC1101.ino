#include <ELECHOUSE_CC1101_SRC_DRV.h>
#include <RCSwitch.h>
#include <SPI.h>
int RXpin = 4; // int for Receive pin.
int TXpin = 5:// int for Transmitter pin.
bool receiverMode = true; 
bool sendRequested = false; 
RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);



  if (ELECHOUSE_cc1101.getCC1101()){       // Check the CC1101 Spi connection.
  Serial.println("Connection OK");
  }else{
  Serial.println("Connection Error");
  }

//CC1101 Settings:                (Settings with "//" are optional!)
  ELECHOUSE_cc1101.Init();            // must be set to initialize the cc1101!
//ELECHOUSE_cc1101.setRxBW(812.50);  // Set the Receive Bandwidth in kHz. Value from 58.03 to 812.50. Default is 812.50 kHz.
//ELECHOUSE_cc1101.setPA(10);       // set TxPower. The following settings are possible depending on the frequency band.  (-30  -20  -15  -10  -6    0    5    7    10   11   12)   Default is max!
  ELECHOUSE_cc1101.setMHZ(433.92); // Here you can set your basic frequency. The lib calculates the frequency automatically (default = 433.92).The cc1101 can: 300-348 MHZ, 387-464MHZ and 779-928MHZ. Read More info from datasheet.
  
  
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'r') {
      mySwitch.enableReceive(RXpin);
      ELECHOUSE_cc1101.SetRx();  
      receiverMode = true;
      Serial.println("Alıcı mod aktif");
    } else if (command == 't') {
      mySwitch.enableTransmit(TXpin);
      ELECHOUSE_cc1101.SetTx();  
      receiverMode = false;
      sendRequested = true;
      Serial.println("Verici mod aktif");
    }
  }
 if (receiverMode) {
    receiveModeFunction();
  } else {
    if (sendRequested) {
      transmitModeFunction(); 
      sendRequested = false; 
    }
  }
}

void receiveModeFunction() {

  if (mySwitch.available()) {
    output(mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength(), mySwitch.getReceivedDelay(), mySwitch.getReceivedRawdata(),mySwitch.getReceivedProtocol());
    mySwitch.resetAvailable();
  }
}
void transmitModeFunction() {
  mySwitch.send("101010101010101010101010");
  delay(1000);
  Serial.println("Gönderildi");
}