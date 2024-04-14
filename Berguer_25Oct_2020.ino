#include "Arduino.h"   //librerias
#include "RTClib.h"    //real time clock

#include "SoftwareSerial.h" 
#include "DFRobotDFPlayerMini.h"     //libreria del reproductor MP3
#include <EEPROM.h>                //manejo de memoria EPROM (no volatil)

RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
int deManana = 13;             // Horario de Rutina
int deTarde = 17;
int btn = 8;
int rele = 7;
boolean btnPress = false;
int dir_manana = 0;
int dir_tarde = 1;

DateTime now;
SoftwareSerial mySoftwareSerial(10, 11);               // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup(void) {
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  pinMode (btn, INPUT_PULLUP);
  pinMode (rele, OUTPUT);
  digitalWrite(rele, LOW);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  DateTime now = rtc.now();
//    //   AJUSTAR HORA Y FECHA
//          Serial.println("RTC lost power, lets set the time!");
//          // following line sets the RTC to the date & time this sketch was compiled
//          rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  Serial.println("Setup Ok.");


  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true) {
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  //Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
  EEPROM.write(dir_manana,0);
  EEPROM.write(dir_tarde,0);
  
}

void loop(void) {
  now = rtc.now();


  rutina(now.hour(), now.minute());

}// loop
