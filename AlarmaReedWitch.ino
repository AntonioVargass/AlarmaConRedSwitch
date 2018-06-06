
//Empezamos definidnedo las variables

int led=13;
int reedwitch=5;
int buzzer=8;
int val=0;
int potenciometro=A0;//la variable donde se almacenara lo valores leeidos del potenciometro para luego utilizarlos como parametros de la  frecuencia
int frecuencia;
int tono;// El valor que se leea en el potenciometro sera almacenado en esta vriable
int duracion=500;


void setup() {
  // Definimos las salidas y entradas
pinMode(led,OUTPUT);
pinMode(reedwitch,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(tono,INPUT);

Serial.begin(9600);
}

void loop() {

// put your main code here, to run repeatedly:
val=digitalRead(reedwitch);//lee el valor en el reedwitch
if(val==LOW){
 digitalWrite(led,HIGH);
 digitalWrite(buzzer,HIGH);
 delay(250);
 digitalWrite(led,LOW);
 digitalWrite(buzzer,LOW);

 tono=analogRead(potenciometro);
 frecuencia=map(tono,0,1023,100,3000);//Aqui se denota el alcance que tendra la frecuencia
 tone(buzzer,frecuencia,duracion);
 Serial.print("Frecuencia= ");
 Serial.println(frecuencia);
 delay(100);//si aumenta el delay la frecuencia sera menor y si se disminuye sera mayo
  }
  else{
   digitalWrite(led,LOW);
   digitalWrite(buzzer,LOW);
    
    }
}
