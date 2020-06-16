#include <IRremote.h>
#include <Servo.h>
int Remote=5;
int SPos;
int SCtrlPin=3;
int Speed;
int RLED=7;
int BLED=9;
IRrecv irrecv(Remote);
decode_results results;
Servo Intensity;

void setup() {

irrecv.enableIRIn();
Intensity.attach(SCtrlPin);
SPos=0;
Speed=0;
pinMode(RLED,OUTPUT);
pinMode(BLED,OUTPUT);

}

void loop() {

Intensity.write(SPos);

if(Speed==0){
  digitalWrite(BLED,LOW);
    digitalWrite(RLED,LOW);
}else{digitalWrite(BLED,HIGH);digitalWrite(RLED,HIGH);}

if(irrecv.decode(&results)){
  Serial.println(results.value,HEX);
  delay(50);  
  switch(results.value){



case 0x73:
  if(Speed==0){
    Speed=1;
        delay(500);
                    break;}else{
                                  Speed=0;
                                      delay(500);
                                        break;}

case 0x873:
  if(Speed==0){
              Speed=1;
                  delay(500);
                    break;}else{
                                  Speed=0;
                                      delay(500);
                                        break;}



       case 0x85B:
    if(SPos>=5&&Speed==0){
     SPos=SPos-5;
      
          break;}
              if(SPos>=5 && Speed==1){
                   SPos=SPos-10;
                          break;}
      if(SPos<=5){digitalWrite(RLED,HIGH);delay(200);digitalWrite(RLED,LOW); break;}



       case 0x5B:
    if(SPos>=5&&Speed==0){
     SPos=SPos-5;
          break;}
          
              if(SPos>=5&&Speed==1){
                   SPos=SPos-10;
                          break;}
      if(SPos<=5){digitalWrite(RLED,HIGH);delay(200);digitalWrite(RLED,LOW); break;}



    case 0x85C:
      if(SPos<=175&&Speed==0){
        SPos=SPos+5;
    break;}
    
          if(SPos<=175&&Speed==1){
        SPos=SPos+10;
    break;}
    
    if(SPos>=175){digitalWrite(BLED,HIGH);delay(200);digitalWrite(BLED,LOW); break;}



       case 0x5C:
      if(SPos<=175&&Speed==0){
        SPos=SPos+5;
    break;}
    
          if(SPos<=175&&Speed==1){
        SPos=SPos+10;
    break;}
    
    if(SPos>=175){digitalWrite(BLED,HIGH);delay(200);digitalWrite(BLED,LOW); break;}

    case 0x859:
      SPos=175;
      break;

      case 0x59:
      SPos=175;
      break;

      case 0x858:
      SPos=0;
      break;

      case 0x58:
      SPos=0;
      break;

      case 0x871:
      SPos=90;
      break;

      case 0x71:
      SPos=90;
      break;
    
  }
  irrecv.resume();
}
}
