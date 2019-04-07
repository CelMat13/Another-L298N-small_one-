/* 
  ANOTHER L298N MOTOR  
 */

 // motor A

 int enA = 3;
 int in1 = 2;
 int in2 = 4;

 //motor B

 int enB = 9;
 int in3 = 8;
 int in4 = 7;

 void setup()

 {
  pinMode (enA, OUTPUT);
  pinMode (enB, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
 }

void demo0()
{
  //turn on motor A
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  analogWrite(enA, 200);

  //turn on motor B

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enB, 200);

  delay(2000);

  // change motor directions

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  delay(2000);

  //turn off motors

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}


void demo1()
{
  // turn on motors

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  //accelerate from 0 to max speed

  for (int i = 0; i<256; i++)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);

    delay(20);
  }

  //decelerate from max speed to 0

  for (int i = 255; i>=0; --i)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);

    delay(20);
  }

//turnoff motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}

void loop()
{
  demo0();
  delay(1000);

  demo1();
  delay(3000);
}
