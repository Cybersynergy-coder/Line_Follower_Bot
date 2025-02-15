#define IR_RIGHT 11
#define IR_LEFT 12
#define MOTOR_SPEED 180

int enablerightmotor =5;
int rightmotorpin1 =7;
int rightmotorpin2 =8;

int enableleftmotor =6;
int leftmotorpin1 =9;
int leftmotorpin2 =10;


void setup() {
  
  TCCR0B = TCCR0B & B11111000 | B00000010 ; //For setting the pwm frequency. 
  
  // put your setup code here, to run once:
  pinMode(enablerightmotor, OUTPUT);
  pinMode(rightmotorpin1, OUTPUT);
  pinMode(rightmotorpin2, OUTPUT);

  pinMode(enableleftmotor, OUTPUT);
  pinMode(leftmotorpin1, OUTPUT);
  pinMode(leftmotorpin2, OUTPUT);

  pinMode(IR_RIGHT, INPUT);
  pinMode(IR_LEFT, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int IR_R = digitalRead(IR_RIGHT);
  int IR_L = digitalRead(IR_LEFT);
  if(IR_L==LOW && IR_R==LOW){
    //Bot goes forward.
    rm(MOTOR_SPEED,MOTOR_SPEED);
  }
  else if (IR_L==HIGH && IR_R==LOW){
    //Bot goes right.
    rm( MOTOR_SPEED , -MOTOR_SPEED);
  }
  else if (IR_L==LOW && IR_R==HIGH){
    //Bot goes left.
    rm( -MOTOR_SPEED, MOTOR_SPEED);
  }
  else{
    //Bot stops.
    rm(0, 0);
  }
}

//rm is a function controlling rotation of motor
void rm(int left_motor_s , int right_motor_s){
  
  //For rotation of left motor
  if(left_motor_s<0){
    //Reverse motion
    digitalWrite(leftmotorpin1,LOW);
    digitalWrite(leftmotorpin2,HIGH);
  }
  else if(left_motor_s>0){
    //Forward motion
    digitalWrite(leftmotorpin1,HIGH);
    digitalWrite(leftmotorpin2,LOW);
  }
  else{
    //Stop
    digitalWrite(leftmotorpin1,LOW);
    digitalWrite(leftmotorpin2, LOW);
  }

  //For rotation of right motor
  if(right_motor_s<0){
    //Reverse motion
    digitalWrite(rightmotorpin1,LOW);
    digitalWrite(rightmotorpin2,HIGH);
  }
  else if(right_motor_s>0){
    //Forward motion
    digitalWrite(rightmotorpin1,HIGH);
    digitalWrite(rightmotorpin2,LOW);
  }
  else{
    //Stop
    digitalWrite(rightmotorpin1,LOW);
    digitalWrite(rightmotorpin2, LOW);
  }
}