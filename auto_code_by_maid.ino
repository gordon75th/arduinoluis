const int pedTasterPin = 2;
const int autoRotPin = 3;
const int GelbesAUTO = 4;
const int autoGruenPin = 5;
const int pedRotPin = 6;
const int pedGruenPin = 7; 

const int roteDauer = 5000;
const int gelbeDauer = 2000;
const int grueneDauer = 5000;

void setup() {
  pinMode(pedTasterPin, INPUT_PULLUP);
  pinMode(autoRotPin, OUTPUT);
  pinMode(GelbesAUTO, OUTPUT);
  pinMode(autoGruenPin, OUTPUT);
  pinMode(pedRotPin, OUTPUT);
  pinMode(pedGruenPin, OUTPUT);
  
  digitalWrite(autoRotPin, HIGH);
  digitalWrite(GelbesAUTO, LOW);
  digitalWrite(autoGruenPin, LOW);
  
  digitalWrite(pedRotPin, HIGH); 
  digitalWrite(pedGruenPin, LOW);
}

void loop() {
  if (digitalRead(pedTasterPin) == LOW) {
    digitalWrite(autoRotPin, HIGH);
    digitalWrite(GelbesAUTO, LOW);
    digitalWrite(autoGruenPin, LOW);

    digitalWrite(pedRotPin, LOW);
    digitalWrite(pedGruenPin, HIGH);
    
    delay(grueneDauer);
    aendereDieLichter();
    
  } else {
    digitalWrite(pedRotPin, HIGH);
    digitalWrite(pedGruenPin, LOW);
    gradualaendereDieLichter();
  }
}

void aendereDieLichter() {
  digitalWrite(pedRotPin, HIGH);
  digitalWrite(pedGruenPin, LOW);
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

void gradualaendereDieLichter() {
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
