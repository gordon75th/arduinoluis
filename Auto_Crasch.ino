bool TasterDruck = false;
int Autorot=2;
int Autogelb=3;
int Autogrun=4;
int Fussrot=5;
int Fussgrun=6;
int Taster=7;
int Tasterstatus=0;
void setup() {
pinMode(Autorot, OUTPUT);
pinMode(Autogelb, OUTPUT);
pinMode(Autogrun, OUTPUT);
pinMode(Fussrot, OUTPUT);
pinMode(Fussgrun, OUTPUT);
pinMode(Taster, INPUT);
}

void loop() {
  if(TasterDruck == true){
    pinMode(Taster, HIGH);
    pinMode(Autorot, LOW);
    pinMode(Autogelb, HIGH);
    pinMode(Autogrun, LOW);
    delay(1500);
    pinMode(Autorot, HIGH);
    pinMode(Autogelb, LOW);
    pinMode(Autogrun, LOW);
    pinMode(Fussrot, LOW);
    pinMode(Fussgrun, HIGH);
    delay(5000);
  }
  
  else(TasterDruck == false); {
    pinMode(Autorot, HIGH);
    pinMode(Autogelb, LOW);
    pinMode(Autogrun, LOW);
    pinMode(Fussrot, HIGH);
    pinMode(Fussgrun, LOW);
    delay(2000);
    pinMode(Autorot, HIGH);
    pinMode(Autogelb, HIGH);
    pinMode(Autogrun, LOW);
    delay(2000);
    pinMode(Autorot, LOW);
    pinMode(Autogelb, LOW);
    pinMode(Autogrun, HIGH);
  }
}
