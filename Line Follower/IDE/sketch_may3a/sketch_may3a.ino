// line following car using L293D and 2 IR Sensor


//L293D
const int enable_pin_a = 11;
const int enable_pin_b = 3;


//left motor
const int motorPin1  = 5;  // Pin 4 of L293D
const int motorPin2  = 6;  // Pin 7 of L293D
//Right motor
const int motorPin3  = 8; // Pin  8 of L293D
const int motorPin4  = 7;  // Pin  9 of L293D
// for IR Sensor
const int IR_R= 2;  // pin 2 for Right IR sensor
const int IR_L= 4;   // pin 4 for left IR sensor
void setup()
{
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(enable_pin_a,OUTPUT);
    pinMode(enable_pin_b,OUTPUT);
   
    //set pins as input
    pinMode(IR_R,INPUT);
    pinMode(IR_L,INPUT);
    Serial.begin(9600);
 
}
void loop ()
{
 
  int left_IR = digitalRead(IR_L);
  Serial.print("Left IR");
  Serial.println(left_IR);
  int right_IR = digitalRead(IR_R);
  Serial.print("Right IR");
  Serial.println(right_IR);
  //delay(1000);
  if ((left_IR==LOW)&&(right_IR==LOW)) //forward
  {
    forward();
  }
  else if ((left_IR==LOW)&&(right_IR==HIGH)) //left
  {
    right();
  }
  else if ((left_IR==HIGH)&&(right_IR==HIGH)) //left
  {
    forward();
  }
  else if ((left_IR==HIGH)&&(right_IR==LOW)) //right
  {
    left();
  }
  else //stop
  {
    stop();
  }
}
void forward()  // move forward
{
    digitalWrite(motorPin1,HIGH);
    digitalWrite(motorPin2,LOW);
    digitalWrite(motorPin3,HIGH);
    digitalWrite(motorPin4,LOW);
    analogWrite(enable_pin_a, 100);
    analogWrite(enable_pin_b, 100);
}
void backward()
{
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2,HIGH);
    digitalWrite(motorPin3,LOW);
    digitalWrite(motorPin4,HIGH);
    analogWrite(enable_pin_a, 70);
    analogWrite(enable_pin_b, 70);
}
void left()  // move left
{  
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2,HIGH);
    digitalWrite(motorPin3,HIGH);
    digitalWrite(motorPin4,LOW);
    analogWrite(enable_pin_a, 100);
    analogWrite(enable_pin_b, 100);
}
void right() // move right
{
    digitalWrite(motorPin1,HIGH);
    digitalWrite(motorPin2,LOW);
    digitalWrite(motorPin3,LOW);
    digitalWrite(motorPin4,HIGH);
    analogWrite(enable_pin_a, 100);
    analogWrite(enable_pin_b, 100);
}
void stop() // stop
{
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2,LOW);
    digitalWrite(motorPin3,LOW);
    digitalWrite(motorPin4,LOW);
}
