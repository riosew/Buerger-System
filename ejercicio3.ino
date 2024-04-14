void ejercicio3() {
  myDFPlayer.play(5);
  while (digitalRead(btn) == HIGH) {
    tone(6, 440, 100);
  }
  myDFPlayer.play(6);
  cuentaSeg(180);  //         ejercicios 3mins
}
