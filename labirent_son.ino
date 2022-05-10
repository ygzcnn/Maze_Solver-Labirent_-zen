const int trigPin1 = 11; // orta sensör

const int echoPin1 = 10; // orta sensör

const int trigPin2 = A3;  // sağ sensör

const int echoPin2 = A4; // sağ sensör

const int in1 = 8; // motor 1 ileri 

const int in2 = 9; // motor 1 geri

const int in3 = 3; // motor 2 ileri

const int in4 = 4; // motor 2 geri

const int enA = 5; // motor 1 hız 

const int enB = 6; // motor 2 hız 

#define DISF 17 // ön sensör mesafe
#define DISR 18 // sağ sensör mesafe

void setup() 

{

 pinMode(trigPin1, OUTPUT); // cıkış olarak 

 pinMode(echoPin1, INPUT);  // giriş olarak
 

 pinMode(trigPin2, OUTPUT);

 pinMode(echoPin2, INPUT);

 pinMode (in1, OUTPUT); //m1 ileri

 pinMode (in2, OUTPUT); // m1 geri

 pinMode (in3, OUTPUT); // m2 ileri

 pinMode (in4, OUTPUT);  // m2 geri

 pinMode (enA, OUTPUT); // sol

 pinMode (enB, OUTPUT); // sağ

}


void loop()

{ 

if (FrontSensor() >DISF && RightSensor () >DISR ) 

 {
        forward();
  
        delay(300);

 }

 else if (RightSensor () <DISR ) 

 {

 turn_left (); 

 }
 else if ( FrontSensor() < DISF )
 {
        turn_left ();
 }

 else if ( FrontSensor() < DISF && RightSensor () <DISF ) 
 {

        reverse (); 

        delay(150);


 }
 else if (FrontSensor() >DISF && RightSensor () <DISR )

 {

        turn_left (); 


        delay(125);

 }

 else 

 {

 forward();

 }

}

void forward ()

{

 digitalWrite(in1, HIGH);

 digitalWrite(in2, LOW);

 digitalWrite(in3, HIGH);

 digitalWrite(in4, LOW);

 analogWrite(enA, 110); 

 analogWrite(enB, 75);

}

void turn_left () 

{

 digitalWrite(in1, HIGH);

 digitalWrite(in2, LOW);

 digitalWrite(in3, LOW);

 digitalWrite(in4, HIGH);

 analogWrite(enA, 80); 

 analogWrite(enB, 80);

}

void turn_right () 

{

 digitalWrite(in1, LOW); 
 digitalWrite(in2, HIGH);

 digitalWrite(in3, HIGH);

 digitalWrite(in4, LOW);

 analogWrite(enA, 80);

 analogWrite(enB, 80);

}

void reverse ()

{

 digitalWrite(in1, LOW);

 digitalWrite(in2, HIGH);

 digitalWrite(in3, LOW);

 digitalWrite(in4, HIGH);

 analogWrite(enA, 95 );

 analogWrite(enB, 90);

}

void stop()

{

 digitalWrite(in1, LOW);

 digitalWrite(in2, LOW);

 digitalWrite(in3, LOW);

 digitalWrite(in4, LOW);

 analogWrite(enA, LOW);

 analogWrite(enB, LOW);

}

long FrontSensor ()

{

long dur;

 digitalWrite(trigPin1, LOW); 

 delayMicroseconds(2); 

 digitalWrite(trigPin1, HIGH);

 delayMicroseconds(10); 

 digitalWrite(trigPin1, LOW);

 dur = pulseIn(echoPin1, HIGH);

 return (dur/62);

}

long RightSensor () 

{

long dur;

 digitalWrite(trigPin2, LOW);

 delayMicroseconds(2); 

 digitalWrite(trigPin2, HIGH);

 delayMicroseconds(10); 
 
 digitalWrite(trigPin2, LOW);

 dur = pulseIn(echoPin2, HIGH);

 return (dur/62);

}
