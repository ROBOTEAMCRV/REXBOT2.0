#include <NewPing.h> // Librería ultrasónica
#include <Servo.h>   // Librería del servo
#include "HUSKYLENS.h"
#include "SoftwareSerial.h"

#define ENA 5
#define IN1 8  // Pines del driver
#define IN2 7
#define ECHO A1
#define TRIG A2

Servo myservo;
HUSKYLENS huskylens;
SoftwareSerial mySerial(10, 12); // RX, TX

int ID0 = 0, ID1 = 1, ID2 = 2;
int pepe = 0;       // Número de obstáculos esquivados
int velocidad = 0;  // Velocidad del coche
int middleDistance = 0;

void setup() {
    Serial.begin(115200);
    mySerial.begin(9600);
    while (!huskylens.begin(mySerial)) {
        Serial.println(F("Error al iniciar Huskylens. Verifica conexión y protocolo."));
        delay(100);
    }

    myservo.attach(3);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(41, INPUT);
    pinMode(40, OUTPUT);
    digitalWrite(40, HIGH);
}

void loop() {
    if (pepe == 0) {  // Configuración inicial
        myservo.write(128);
        stop();
        delay(1000);
        pepe++;
    }

    if (velocidad < 250) {
        velocidad++;
        analogWrite(ENA, velocidad);
        Serial.println(velocidad);
    }

    forward();

    if (pepe > 15) {  // Detener el coche después de 15 obstáculos
        stop();
        delay(1000000000);
    }

    middleDistance = getDistance();
    if (middleDistance > 1 && middleDistance <= 50) {
        Serial.println(middleDistance);

        if (huskylens.request()) {
            Serial.println("Objetos detectados por Huskylens:");

            for (int i = 0; i < huskylens.count(); i++) {
                HUSKYLENSResult result = huskylens.get(i);
                handleObjectDetection(result);
            }
        } else {
            Serial.println("Falló la detección en Huskylens.");
        }
        delay(1000);
    }

    delay(300);
}

void forward() {
    digitalWrite(ENA, HIGH);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    Serial.println("Avanzando - " + String(middleDistance));
}

void back() {
    digitalWrite(ENA, HIGH);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    Serial.println("Retrocediendo");
}

void stop() {
    digitalWrite(ENA, LOW);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
}

int getDistance() {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    return pulseIn(ECHO, HIGH) / 58;
}

void handleObjectDetection(HUSKYLENSResult result) {
    Serial.println("ID detectado: " + String(result.ID));

    if (result.ID == ID1 && result.height > 130) {
        Serial.println("Objeto rojo detectado");

        if (result.xOrigin < 100) {
            moveServoAndAdvance(101, 150);
        } else if (result.xOrigin < 200) {
            moveServoAndAdvance(101, 150);
        } else {
            moveServoAndAdvance(101, 150);
        }
    } else if (result.ID == ID2 && result.height > 130) {
        Serial.println("Objeto verde detectado");

        if (result.xOrigin < 100) {
            moveServoAndAdvance(150, 101);
        } else if (result.xOrigin < 200) {
            moveServoAndAdvance(150, 101);
        } else {
            moveServoAndAdvance(150, 101);
        }
    } else {
        Serial.println("No se identificó color relevante.");
        pepe++;
        adjustServoByDirection();
    }
}

void moveServoAndAdvance(int pos1, int pos2) {
    myservo.write(pos1);
    delay(100);
    forward();
    delay(800);
    myservo.write(pos2);
    delay(100);
    forward();
    delay(400);
    myservo.write(120);
}

void adjustServoByDirection() {
    if (digitalRead(41)) {
        myservo.write(100);
        delay(500);
        myservo.write(120);
    } else {
        myservo.write(100);
        delay(520);
        myservo.write(128);
        delay(500);
    }
}

