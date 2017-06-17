#include <Servo.h>

// Blue   -> pins 1,2 (Analogue)
// Brown  -> pins 3,4 (Analogue)
// 5V
// servos:-> Servo holding LDR's -> 3
//        -> Other servo -> 5

Servo mot1;
Servo mot2;

int LDR1 = 1;
int LDR2 = 2;
int LDR3 = 4;
int LDR4 = 3;

int val1=0 ;
int val2=0 ;
int val3=0 ;
int val4=0 ;

int pos1 =90;
int pos2 =90;

int n=2;
int delayNum=25;
double e=0.1;

int AverageValList[]={0,0,0,0};

void setup() {
  mot1.attach(3);
  mot2.attach(5);
  Serial.begin(9600);
  mot1.write(pos1);
  mot2.write(pos2);
  

}

void loop() {
 
  Average(n);
  val1=AverageValList[0];
  val2=AverageValList[1];
  val3=AverageValList[2];
  val4=AverageValList[3];
  
  if (val1 > val2 && pos1>5 ) {
    if (!(abs(((double)(val1-val2)/val2)) < e)){
      pos1 = pos1 - 1;
    }
  }
  if (val1 < val2 && pos1<175) {
    if (!(abs(((double)(val1-val2)/val2)) < e)){
      pos1 = pos1 + 1;
    }
  }
  
  if (val3 < val4 && pos2>5) {
    if (!(abs(((double)(val1-val2)/val2)) < e)){
      pos2 = pos2 - 1;
    }
  }
  if (val3 > val4 && pos2<175) {
    if (!(abs(((double)(val1-val2)/val2)) < e)){
      pos2 = pos2 + 1;
    }
  }
  

  Serial.println(val1);
  Serial.println(val2);  
  Serial.println(val3);
  Serial.println(val4);
  
  Serial.print("Pos 1 : ");
  Serial.println(pos1);
  Serial.print("Pos 2 : ");
  Serial.println(pos2);

  mot1.write(pos1);
  mot2.write(pos2);
  Serial.println("");
  delay(delayNum);

}

int Average(int n){
  val1=0;
  val2=0;
  val3=0;
  val4=0;
  
  for(int i=1; i<n ;i++){
    val1=val1+analogRead(LDR1);   
    val2=val2+analogRead(LDR2);   
    val3=val3+analogRead(LDR3);   
    val4=val4+analogRead(LDR4);   
  }
  AverageValList[0]=val1/n;
  AverageValList[1]=val2/n;
  AverageValList[2]=val3/n;
  AverageValList[3]=val4/n;
}

