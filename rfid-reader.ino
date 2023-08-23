#include <SPI.h>
#include <MFRC522.h>

#define rst 9
#define sda 10

MFRC522 mfrc522(sda,rst);

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  mfrc522.PCD_DumpVersionToSerial();
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop()
{
  if(!(mfrc522.PICC_IsNewCardPresent()))
  {
    return;
  }
  if(!(mfrc522.PICC_ReadCardSerial()))
  {
    return;
  }
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}
