

//bibiliotecas
#include <DHT11.h>
#include <DHT.h>
#include <DHT_U.h>

 #define DHTPIN A1 //definimos qual sera o pino para o sensor
#define DHTTYPE DHT11

DHT dht( DHTPIN, DHT11); //pinMode

//variaveis
const int PIR = 2;
const int ledBranco = 13;
//
const int MQ135 = A0; //pino analogico do mq-135
const int buzzer = 12;


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

void verificarVazamentoDeGas(){
int estadoMQ135 = analogRead(MQ135);

//if - verificar a intensidade do valor do estadoMQI135 >= 600
// sim - ativar o alarme
// nao - desativar o alarme 

if ( estadoMQ135 >= 10 ){
  alarme_dois_tons();
} else {
  noTone(buzzer);
}

Serial.println(estadoMQ135);
delay(100);
}

void alarme_dois_tons() {
  int freqAlta = 2000;
  int freqBaixa = 800;
  int duracaoTom = 250;

  tone(buzzer, freqAlta, duracaoTom);
  delay(duracaoTom);
  tone(buzzer, freqBaixa, duracaoTom);
  delay(duracaoTom);
}

void verificarTemperaturaEUmidade(){
float umidade = dht.readHumidity();
float temperatura = dht.readTemperature(); 

Serial.println("Umidade: " + String(umidade) + "%");
Serial.println("Temperatura: " + String(temperatura) + "C");

}

void setup() {
Serial.begin(9600);
pinMode(ledBranco, OUTPUT);
pinMode(MQ135, INPUT);
pinMode(buzzer, OUTPUT);

dht.begin();

Serial.println("Calibrando os sensores");
delay(100);
Serial.println("Sensores calibrados! Pode testar.");
}

void loop() {
//As instrucoes no loop sera somente chamada de funcoes
verificarTemperaturaEUmidade();

}
