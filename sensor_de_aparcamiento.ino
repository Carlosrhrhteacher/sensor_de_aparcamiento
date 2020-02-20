const int EchoPin = 5;
const int TriggerPin = 6;
const int ZumbadorPin = 9;
const int Ledrojo = 2;
const int Ledamarillo = 3;
const int Ledverde = 4;
const int distancia1 = 20;
const int distancia2 = 50;
const int distancia3 = 100;
int x;

void setup() {
 Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   pinMode(ZumbadorPin, OUTPUT);
   pinMode(Ledrojo, OUTPUT);
   pinMode(Ledamarillo, OUTPUT);
   pinMode(Ledverde, OUTPUT);

  // Apagamos todos los LEDs
  apagarLEDs();

}

void loop() {
  noTone(9);
  int cm = ping(TriggerPin, EchoPin);
   Serial.print("Distancia: ");
   Serial.println(cm);

   
  // Apagamos todos los LEDs
  apagarLEDs();

  
while(cm <= distancia1) {
 digitalWrite (Ledrojo, HIGH);
  analogWrite(9,50);
  
  tone(ZumbadorPin, 2500);
  delay(400);
  cm = ping(TriggerPin, EchoPin);
  Serial.println(cm);
    
  }
 while(cm > distancia1 && cm <= distancia3 ) {
  //map (value, fromLow, fromHigh, toLow, toHigh)
 x = map (cm, 20, 100, 70, 400);
 
 analogWrite(9,50);
 
 tone(ZumbadorPin, 2500);
 
 //Duracion de cada pitido
 
  delay(x);
  
 //Tiempo ente cada pitido
 
  noTone(9);
  
  delay(x);
  
  cm = ping(TriggerPin, EchoPin);
  Serial.println(cm);

  if(cm>distancia1 && cm<=distancia2){
    digitalWrite(Ledamarillo, HIGH);
    digitalWrite(Ledverde, LOW);
    digitalWrite(Ledrojo, LOW);
    }

  else if(cm>distancia2 && cm<= distancia3 ){
    digitalWrite(Ledverde, HIGH);
    digitalWrite(Ledamarillo, LOW);
    digitalWrite(Ledrojo, LOW);
      }
  }
}




// Apaga todos los LEDs
void apagarLEDs()
{
  // Apagamos todos los LEDs
  digitalWrite(Ledverde, LOW);
  digitalWrite(Ledamarillo, LOW);
  digitalWrite(Ledrojo, LOW);
}



// Método que calcula la distancia a la que se encuentra un objeto.
// Devuelve la distancia
int ping(int TriggerPin, int EchoPin) {
   long duration, distancia;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distancia = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distancia;
}
