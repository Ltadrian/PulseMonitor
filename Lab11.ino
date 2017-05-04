#include <EnableInterrupt.h>

#define pinInt A8
int times[5];
int ctr, last, ref, rate;
float timeref,timeend;
void setup() {
  Serial.begin(115200);

  int i;
  for(i=22;i<30; i++){ //set up pins 22-29
    pinMode(i, OUTPUT);
  }
  pinMode(pinInt, INPUT_PULLUP);
  enableInterrupt(pinInt, isr, RISING);

}

void loop() {
  delay(5000);
  int count=ctr;
  if(count >= 5){
    int i,j;
    ctr=0;
    timeend=millis();
    float bpm = ( (count/(timeend-timeref)) * 60000);
    Serial.print("bpm: ");
    Serial.println(bpm);

    int tens, ones;
    //For tens
    tens = ((int)bpm)/10;
    //For ones
    ones = ((int)bpm)%10;

    for(j = 0; j < 4; j++){
      if(bitRead(tens,j) == 1){
        digitalWrite(j+22,HIGH);
      }
      else{
         digitalWrite(j+22,LOW);
      }
    }

    for(j = 0; j < 4; j++){
      if(bitRead(ones,j) == 1){
        digitalWrite(j+26,HIGH);
      }
      else{
         digitalWrite(j+26,LOW);
      }
    }
    
  }
}


void isr(void){    
  if(ctr==0)
    timeref=millis();
  ctr++;
}

