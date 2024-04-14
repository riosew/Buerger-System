void rutina(int hraActual, int mins) {

Serial.println(hraActual);


  if (hraActual == deManana && EEPROM.read(dir_manana) == 0) {                 //alerta inicial
    EEPROM.write(dir_manana, 1);
    //    Serial.println(EEPROM.read(dir_manana));
    digitalWrite(rele, HIGH);
    ejercicio1();
    ejercicio2();
    ejercicio3();
    ejercicio1();
    ejercicio2();
    ejercicio3();
    ejercicio1();
    ejercicio2();
    ejercicio3();

    myDFPlayer.play(7);                                  //aqui terminamos
    cuentaSeg(10);
    digitalWrite(rele, LOW);
  }

  if (hraActual == deTarde && EEPROM.read(dir_tarde) == 0) {                 //alerta inicial
    EEPROM.write(dir_tarde, 1);
    digitalWrite(rele, HIGH);
    ejercicio1();
    ejercicio2();
    ejercicio3();
    ejercicio1();
    ejercicio2();
    ejercicio3();
    ejercicio1();
    ejercicio2();
    ejercicio3();

    myDFPlayer.play(7);                                  //aqui terminamos
    cuentaSeg(10);
    digitalWrite(rele, LOW);
  }


  if (EEPROM.read(dir_tarde) > 0 && EEPROM.read(dir_manana) > 0  && hraActual > deTarde) {
    EEPROM.write(dir_tarde, 0);
    EEPROM.write(dir_manana, 0);
  }



}
