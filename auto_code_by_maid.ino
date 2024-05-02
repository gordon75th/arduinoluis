// Pin defines
const int pedTasterPin = 2;
const int autoRotPin = 3;
const int GelbesAUTO = 4;
const int autoGruenPin = 5;
const int pedRotPin = 6;
const int pedGruenPin = 7; 

// Timers, wenn du irgendwas so schreibst, es wird so definiert sein. z.B: roteDauer ist gleich 5000, aso wenn ich roteDauer(); irgendwo schreibe, dann ist es gleich als ich 5000 geschrieben hatte.
const int roteDauer = 5000;
const int gelbeDauer = 2000;
const int grueneDauer = 5000;

// Yeah, the setup and einstellungen, it defines what everything is
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

// Main loop, nothing really to explain
void loop() {
  // Now we get to the cool shit. So, this "if" checks if "pedTasterPin == LOW" (Low = taster is pressed) is and if it is, it runs the code. 
  if (digitalRead(pedTasterPin) == LOW) {
    // It changes(writes) the constants into new values. Rote lichter werden eingeschaltet und gelb/gruen aus.
    digitalWrite(autoRotPin, HIGH);
    digitalWrite(GelbesAUTO, LOW);
    digitalWrite(autoGruenPin, LOW);

    // Same shit as up there ^^, but different way. Gruen on, Rot aus. 
    digitalWrite(pedRotPin, LOW);
    digitalWrite(pedGruenPin, HIGH);
    
    // Activates a delay with a value of "grueneDauer", we defined it earlier, line #12. Aso, "delay(grueneDauer)" ist gleich wie "delay(5000)". Hope u get it <3
    delay(grueneDauer);
    // Calls a function defined later. You write functions so that u dont have to write the code all the time. Write the code one time and just use it like this by calling the function. 
    aendereDieLichter();
    
  } else {
    // If the "pedTasterPin" kein druck hat, dann werden die pedestrian lichter ausgeschalted und the car lights are turned on by calling the "gradualAendereDieLichter" function.
    digitalWrite(pedRotPin, HIGH);
    digitalWrite(pedGruenPin, LOW);
    gradualAendereDieLichter();
  }
}

void aendereDieLichter() {
  //Changes the lights like in real life. Goes red, gelb then green with a delay. Not much to explain here.
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

void gradualAendereDieLichter() {
  // Same shit but only car lights.
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
