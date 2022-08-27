//Color Sensor interface with Arduino 
//Aman Shaikh 

// Define Colour senor pins with arduino 
#define S0 4   //Digital(PWM) Pin(any betn 2-13) of Arduino(any)
#define S1 5   //Digital(PWM) Pin(any betn 2-13) of Arduino(any)
#define S2 6   //Digital(PWM) Pin(any betn 2-13) of Arduino(any)
#define S3 7   //Digital(PWM) Pin(any betn 2-13) of Arduino(any)
#define OUT 8  //Digital(PWM) Pin(any betn 2-13) of Arduino(any)


// Define Led with arduino 
#define LedRed    A2   //Analog Pin(any betn A0- A5) of Arduino(any)
#define LedGreen  A0   //Analog Pin(any betn A0- A5) of Arduino(any)
#define LedBlue   A1   //Analog Pin(any betn A0- A5) of Arduino(any)

//Declare integer 
int R,G,B = 0;

void setup() 
{
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

  pinMode(LedRed, OUTPUT);
  pinMode(LedGreen, OUTPUT);
  pinMode(LedBlue, OUTPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);

  for (int i=0; i<=5; i++){
    digitalWrite(LedRed, !digitalRead(LedRed));
    digitalWrite(LedGreen, !digitalRead(LedGreen));
    digitalWrite(LedBlue, !digitalRead(LedBlue));
    delay(250);
  }
}

void loop() 
{
  // Setting red filtered photodiodes to be read Red frequency
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  R = pulseIn(OUT, LOW);  // Reading the output Red frequency
  delay(100); 
  // Setting Green filtered photodiodes to be read Green frequency
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  G = pulseIn(OUT, LOW);  // Reading the output Green frequency
  delay(100);
  // Setting Blue filtered photodiodes to be read Blue frequency
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  B = pulseIn(OUT, LOW);  // Reading the output Blue frequency
  delay(100);
  
  //----------------------------------------------------------
  //Detect colors based on sensor values
  if (R>20 && R<35 && G>80 && G<105 && B>70 && B<90){       // to detect red
    digitalWrite(LedRed, HIGH);
  }
  else if (R>75 && R<100 && G>60 && G<85 && B>75 && B<95){  // to detect green
    digitalWrite(LedGreen, HIGH);
  }
  else if (R>95 && R<115 && G>70 && G<95 && B>30 && B<55){  // to detect blue
    digitalWrite(LedBlue, HIGH);
  }
  else{
    digitalWrite(LedRed, LOW);
    digitalWrite(LedGreen, LOW);
    digitalWrite(LedBlue, LOW);
  }
  //----------------------------------------------------------

  // Print RGB Sensor Values
  Serial.print("R= ");
  Serial.print(R);
  Serial.print(" | ");
  Serial.print("G= ");
  Serial.print(G);
  Serial.print(" | ");
  Serial.print("B= ");
  Serial.print(B);
  Serial.println();
  delay(200);
}
