void cuentaSeg(int goal) {
  int c = 0;
  now = rtc.now();
  int sec = now.second();
  //    Serial.println(sec);
  while (c < goal) {
    now = rtc.now();
    if (sec != now.second()) {
      sec = now.second();
      c++;
      tone(6, 440, 100);
//
//      Serial.println(c);
    }
  }

}
