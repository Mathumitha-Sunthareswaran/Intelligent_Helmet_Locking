const int ir_read = 2;      //pin ir sensor
const int clip_read = 3;
const int Buzzer =13;

void setup() {
  // put your setup code here, to run once:
 pinMode(ir_read,INPUT);
 pinMode(clip_read,INPUT);
 pinMode(Buzzer,OUTPUT);
 Serial.begin(9600);
}



void loop() {
  // put your main code here, to run repeatedly:
  bool ir_state;
  bool clip_state;
  bool overall_state;
  ir_state = digitalRead(ir_read);
  clip_state = digitalRead(clip_read);
  overall_state =  !(ir_state) &  (clip_state);    //
  
  Serial.print(ir_state);
  Serial.print(clip_state);
  Serial.print(overall_state);  
  Serial.println();
  

//if (ir_read == LOW)
//  delay(20000);
  
if (overall_state == HIGH)
{
  digitalWrite(Buzzer,HIGH);
  delay(100);
  digitalWrite(Buzzer,LOW);
  delay(20000);
  while(clip_state == HIGH){
    clip_state = digitalRead(clip_read);
    Serial.print(clip_state);  
    Serial.println();
    digitalWrite(Buzzer,HIGH);
    delay(100);
    digitalWrite(Buzzer,LOW);
    delay(100);
  } 
}
else
{
  digitalWrite(Buzzer,LOW);
}
}
