//Running Motor Drivers with:
//power = pwm out
//direction = switch out
//rotation = encoder in

//define pin name
#define dir_LF A0
#define dir_RF A1
#define pwm_LF 3
#define pwm_RF 2
#define encoder_LF A6
#define encoder_RF A7

#define dir_RB A4
#define dir_LB A5
#define pwm_RB 4
#define pwm_LB 5
#define encoder_LB A2
#define encoder_RB A3

//#define switch_1b
//#define switch_2b
void setup() {
  //declare pins as INPUT/OUTPUT
  //Motor A = LEft
  pinMode(pwm_RF, OUTPUT);
  pinMode(dir_RF, OUTPUT);
  pinMode(encoder_RF, INPUT);
  pinMode(pwm_LF, OUTPUT);
  pinMode(dir_LF, OUTPUT);
  pinMode(encoder_LF, INPUT);

  //Motor B = Right
  pinMode(pwm_RB, OUTPUT);
  pinMode(dir_RB, OUTPUT);
  pinMode(encoder_RB, INPUT);
  pinMode(pwm_LB, OUTPUT);
  pinMode(dir_LB, OUTPUT);
  pinMode(encoder_LB, INPUT);
  

  //pinMode(switch_1b, INPUT);
  //pinMode(switch_2b, INPUT);
  Serial.begin(9600);  //I am using Serial Monitor instead of LCD display
  Serial.println("Ended Setup");
}
void loop() {
  int pwm_value;
  runMotors(30, 20, 30, 20, 1, 1);
  //swivel_right(30, 20); 
  //swivel_left(-30,20);
//  while (1) continue; //terminate the program
}

void runRight(int speed_val_front, int speed_val_back, int DirR){
//  motor from 0 to 255
  if(DirR > 0){
    digitalWrite(dir_RF, digitalRead(encoder_RF));
    digitalWrite(dir_RB, digitalRead(encoder_RB));
    analogWrite(pwm_RB,speed_val_back);          
    analogWrite(pwm_RF,speed_val_front);         
  }
  if(DirR < 0){  
    digitalWrite(dir_RF, !digitalRead(encoder_RF));
    digitalWrite(dir_RB, !digitalRead(encoder_RB));
    analogWrite(pwm_RB,speed_val_back);          
    analogWrite(pwm_RF,speed_val_front); 
  }
   
  //Serial.println("Right PWM:");
  //Serial.println(speed_val);  //Display the value of PWM
}

void runLeft(int speed_val_front,int speed_val_back, int DirL){
//  motor from 0 to 255
  if(DirL > 0 ){
    digitalWrite(dir_LF, digitalRead(encoder_LF));
    digitalWrite(dir_LB, digitalRead(encoder_LB));
    analogWrite(pwm_LB,speed_val_back);          
    analogWrite(pwm_LF,speed_val_front); 
  }        
  if(DirL < 0 ){
    digitalWrite(dir_LF, !digitalRead(encoder_LF));
    digitalWrite(dir_LB, !digitalRead(encoder_LB));
    analogWrite(pwm_LB,speed_val_back);          
    analogWrite(pwm_LF,speed_val_front); 
  }       
  //Serial.println("Right PWM:");
  //Serial.println(speed_val);  //Display the value of PWM
}

void runMotors(int rpm_RightFront, int rpm_LeftFront, int rpm_RightBack, int rpm_LeftBack, int DirL, int DirR){ 
  delay(20);
  runRight(rpm_RightFront, rpm_RightBack, DirL);
  delay(20);
  runLeft(rpm_LeftFront, rpm_LeftBack, DirR);
  }
