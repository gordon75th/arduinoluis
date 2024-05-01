bool TasterDruck = false;
int Autorot = 2;
int Autogelb = 3;
int Autogrun = 4;
int Fussrot = 5;
int Fussgrun = 6;
int Taster = 7;
int Tasterstatus = 0;

void setup() {
  pinMode(Autorot, OUTPUT);
  pinMode(Autogelb, OUTPUT);
  pinMode(Autogrun, OUTPUT);
  pinMode(Fussrot, OUTPUT);
  pinMode(Fussgrun, OUTPUT);
  pinMode(Taster, INPUT);
}

void loop() {
  Tasterstatus = digitalRead(Taster);
  
  if (Tasterstatus == HIGH) {
    TasterDruck = true;
  } else {
    TasterDruck = false;
  }
  
  if (TasterDruck == true) {
    digitalWrite(Autorot, LOW);
    digitalWrite(Autogelb, HIGH);
    digitalWrite(Autogrun, LOW);
    delay(1500);
    digitalWrite(Autorot, HIGH);
    digitalWrite(Autogelb, LOW);
    digitalWrite(Autogrun, LOW);
    digitalWrite(Fussrot, LOW);
    digitalWrite(Fussgrun, HIGH);
    delay(5000);
  } else {
    digitalWrite(Autorot, HIGH);
    digitalWrite(Autogelb, LOW);
    digitalWrite(Autogrun, LOW);
    digitalWrite(Fussrot, HIGH);
    digitalWrite(Fussgrun, LOW);
    delay(2000);
    digitalWrite(Autorot, HIGH);
    digitalWrite(Autogelb, HIGH);
    digitalWrite(Autogrun, LOW);
    delay(2000);
    digitalWrite(Autorot, LOW);
    digitalWrite(Autogelb, LOW);
    digitalWrite(Autogrun, HIGH);
  }
}
