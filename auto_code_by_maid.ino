const int pedTasterPin = 2;
const int autoRotPin = 3;
const int GelbesAUTO = 4;
const int autoGruenPin = 5;
const int pedestrianRedPin = 6;
const int pedestrianGreenPin = 7; 

const int roteDauer = 5000;
const int gelbeDauer = 2000;
const int grueneDauer = 5000;

void setup() {
  pinMode(pedTasterPin, INPUT_PULLUP);
  pinMode(autoRotPin, OUTPUT);
  pinMode(GelbesAUTO, OUTPUT);
  pinMode(autoGruenPin, OUTPUT);
  pinMode(pedestrianRedPin, OUTPUT);
  pinMode(pedestrianGreenPin, OUTPUT);
  
  digitalWrite(autoRotPin, HIGH);
  digitalWrite(GelbesAUTO, LOW);
  digitalWrite(autoGruenPin, LOW);
  
  digitalWrite(pedestrianRedPin, HIGH); 
  digitalWrite(pedestrianGreenPin, LOW);
}

void loop() {
  if (digitalRead(pedTasterPin) == LOW) {
    digitalWrite(autoRotPin, HIGH);
    digitalWrite(GelbesAUTO, LOW);
    digitalWrite(autoGruenPin, LOW);

    digitalWrite(pedestrianRedPin, LOW);
    digitalWrite(pedestrianGreenPin, HIGH);
    
    delay(grueneDauer);
    changeTheFuckingLights();
    
  } else {
    digitalWrite(pedestrianRedPin, HIGH);
    digitalWrite(pedestrianGreenPin, LOW);
    gradualchangeTheFuckingLights();
  }
}

void changeTheFuckingLights() {
  digitalWrite(pedestrianRedPin, HIGH);
  digitalWrite(pedestrianGreenPin, LOW);
  digitalWrite(autoRotPin, HIGH);
  digitalWrite(GelbesAUTO, LOW);
  digitalWrite(autoGruenPin, LOW);
  delay(roteDauer);
  digitalWrite(autoRotPin, LOW);
  digitalWrite(GelbesAUTO, HIGH);
  delay(gelbeDauer);
  digitalWrite(GelbesAUTO, LOW);
  digitalWrite(autoGruenPin, HIGH);
  delay(grueneDauer);
}

void gradualchangeTheFuckingLights() {
  digitalWrite(autoRotPin, HIGH);
  digitalWrite(GelbesAUTO, LOW);
  digitalWrite(autoGruenPin, LOW);
  delay(roteDauer);
  digitalWrite(autoRotPin, LOW);
  digitalWrite(GelbesAUTO, HIGH);
  delay(gelbeDauer);
  digitalWrite(GelbesAUTO, LOW);
  digitalWrite(autoGruenPin, HIGH);
  delay(grueneDauer);
}
