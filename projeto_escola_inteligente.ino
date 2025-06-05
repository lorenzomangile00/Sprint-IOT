const int PIR = 2;
const int ledBranco = 13;


void acenderLEDAoDetectarPresenca(){
int estadoPIR = digitalRead(PIR);//Le o pino digital 2

//HIGH = 1 e LOW = 0
if(estadoPIR == HIGH){
digitalWrite(ledBranco, HIGH);
Serial.println("LED ligado");
delay(5000);
}
else {
digitalWrite(ledBranco, LOW);
Serial.println("LED apagado");
delay(5000);
}

}


void setup() {
Serial.begin(9600);
pinMode(ledBranco, OUTPUT);

Serial.println("Calibrando os sensores");
delay(10000);
Serial.println("Sensores calibrados! Pode testar.");
}

void loop() {
//As instrucoes no loop sera somente chamada de funcoes
acenderLEDAoDetectarPresenca();
}
