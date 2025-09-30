/*Control Temperatura*/
/*Cristian Castro Lagos*/
#include <Wire.h>
uint32_t LoopTimer;
int Pin =  9; //led que marca muestreo
float Temp; //Temperatura medida
float Temp_1=0.0;
float a=0.9391; // parametro filtro IIR
float ref=30.0;  //Referencia temperatura
float u=0.0,u_1=0.0;//Se_al de control
float e=0.0,e_1=0.0;// error resp
float K0=7.6634,K1=-7.6488; //parametros control PI discreto
float tiempo=0;
void setup() {
  Serial1.begin(57600);
  //Serial.begin(38400);
  pinMode(Pin, OUTPUT);
  ref=(float(analogRead(Tmed))*3.3/1023.0-0.5)/0.01;
  LoopTimer=micros();
}


void loop() {
  digitalWrite(Pin, !digitalRead(Pin));
  Temp = (1.0-a)*(float(analogRead(A0))*3.3/1023.0-0.5)/0.01+a*Temp_1; // fitro digital medicion temperatura
  Temp_1=Temp;
  if (tiempo>=200){
    ref=35.0;
  }
  e=(ref-Temp); //cierre de lazo de control  

  // Control PI
  u = u_1 + K0*e + K1*e_1; //controlador PI discreto
  if (u >= 100.0){      //saturacion
    u = 100.0;
  } 
  
  if (u <= 0.0 || ref==0.0){
    u = 0.0;
  }
  e_1=e;
  u_1=u;
  //control signal
  analogWrite(3,map(u,0,100,0,255));
  Serial1.print(Temp);  
  Serial1.print(","); 
  Serial1.print(u);
  Serial1.print(",");
  Serial1.print(ref);
  Serial1.print(",");
  Serial1.println(tiempo);
    while ( micros() - LoopTimer< 100000); // el codigo se bloquea o no avanza hasta que se cumpla la condicion
  LoopTimer=micros();
  tiempo=tiempo+0.1;
}