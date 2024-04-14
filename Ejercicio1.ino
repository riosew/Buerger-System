void ejercicio1() {
  myDFPlayer.play(1);
  while (digitalRead(btn) == HIGH) {   // espera al usuario
       tone(6, 440, 100);
  }
  myDFPlayer.play(2);
  cuentaSeg(180);  //         ejercicios 3mins

}
