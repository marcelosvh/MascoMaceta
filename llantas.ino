int IN1 = 22;      // IN1 a pin digital 22
int IN2 = 23;      // IN2 a pin digital 23
int ENA1 = 5;      // ENA a pin digital 5
int IN3 = 24;      // IN3 a pin digital 24
int IN4 = 25;      // IN4 a pin digital 25
int ENB1 = 4;      // ENA a pin digital 4

int IN5 = 26;      // IN1 a pin digital 26
int IN6 = 27;      // IN2 a pin digital 27
int ENA2 = 3;      // ENA a pin digital 3
int IN7 = 28;      // IN3 a pin digital 28
int IN8 = 29;      // IN4 a pin digital 29
int ENB2 = 2;      // ENA a pin digital 2

int VELOCIDAD;      // variable para almacenar valor de velocidad

void setup(){
  pinMode(IN1, OUTPUT);    // IN1 como salida  
  pinMode(IN2, OUTPUT);   // IN2 como salida
  pinMode(ENA1, OUTPUT);   // ENA como salida
  pinMode(IN3, OUTPUT);   // IN3 como salida
  pinMode(IN4, OUTPUT);   // IN4 como salida
  pinMode(ENB1, OUTPUT);   // ENB como salida

  pinMode(IN5, OUTPUT);    // IN1 como salida  
  pinMode(IN6, OUTPUT);   // IN2 como salida
  pinMode(ENA2, OUTPUT);   // ENA como salida
  pinMode(IN7, OUTPUT);   // IN3 como salida
  pinMode(IN8, OUTPUT);   // IN4 como salida
  pinMode(ENB2, OUTPUT);   // ENB como salida
}

void loop(){
  VELOCIDAD = 100;    // valor de velocidad para PWM de ENA y ENB
  
  aAvanceAdelante(VELOCIDAD);   // funcion de avance del motor A
  bAvanceAdelante(VELOCIDAD);   // funcion de avance del motor B
  delay(1000);      // demora de 3 seg.
  
  detieneAmbos();   // funcion que detiene ambos motores
  delay(2000);      // demora de 2 seg.

  aAvanceAtras(VELOCIDAD);   // funcion de avance del motor A
  bAvanceAtras(VELOCIDAD);   // funcion de avance del motor B
  delay(1000);      // demora de 3 seg.
  
  detieneAmbos();   // funcion que detiene ambos motores
  delay(2000);      // demora de 2 seg.

}

void aAvanceAdelante(int veloc){  // funcion para avance adelante de motor A
  analogWrite(ENA1, veloc);  // velocidad mediante PWM en ENA
  digitalWrite(IN1, LOW); // IN1 a cero logico
  digitalWrite(IN2, HIGH);  // IN2 a uno logico

  analogWrite(ENA2, veloc);  // velocidad mediante PWM en ENA
  digitalWrite(IN5, LOW); // IN1 a cero logico
  digitalWrite(IN6, HIGH);  // IN2 a uno logico
}

void bAvanceAdelante(int veloc){  // funcion para avance adelante de motor B
  analogWrite(ENB1, veloc);  // velocidad mediante PWM en ENB
  digitalWrite(IN3, LOW); // IN3 a cero logico
  digitalWrite(IN4, HIGH);  // IN4 a uno logico

  analogWrite(ENB2, veloc);  // velocidad mediante PWM en ENA
  digitalWrite(IN7, LOW); // IN1 a cero logico
  digitalWrite(IN8, HIGH);  // IN2 a uno logico
}

void aAvanceAtras(int veloc){  // funcion para avance adelante de motor A
  analogWrite(ENA1, veloc);  // velocidad mediante PWM en ENA
  digitalWrite(IN1, HIGH); // IN1 a uno logico
  digitalWrite(IN2, LOW);  // IN2 a cero logico

  analogWrite(ENA2, veloc);  // velocidad mediante PWM en ENA
  digitalWrite(IN5, HIGH); // IN1 a cero logico
  digitalWrite(IN6, LOW);  // IN2 a uno logico
}

void bAvanceAtras(int veloc){  // funcion para avance adelante de motor B
  analogWrite(ENB1, veloc);  // velocidad mediante PWM en ENB
  digitalWrite(IN3, HIGH); // IN3 a uno logico
  digitalWrite(IN4, LOW);  // IN4 a cero logico

  analogWrite(ENA2, veloc);  // velocidad mediante PWM en ENA
  digitalWrite(IN5, HIGH); // IN1 a cero logico
  digitalWrite(IN6, LOW);  // IN2 a uno logico
}


void detieneAmbos(){    // funcion que detiene ambos motores
  analogWrite(ENA1, 0);    // deshabilita motor A
  analogWrite(ENB1, 0);    // deshabilita motor B
  analogWrite(ENA2, 0);
  analogWrite(ENB2, 0);
}