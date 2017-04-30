#include <EnableInterrupt.h>

#define pinInt A8
int times[5];
int ctr, last, ref, rate;
float timeref;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  
  pinMode(pinInt, INPUT_PULLUP);
  enableInterrupt(pinInt, isr, RISING);

}

void loop() {
  // put your main code here, to run repeatedly:x
  /*
  if(ctr%4==0){
    float summationOfTimes = 0;
    for(int i=0; i < 5;i++)
      summationOfTimes += times[i];

    //Serial.print("BPM: ");  
    //Serial.println((ctr/summationOfTimes)*60000);
    //delay(3000);
  }*/
  Serial.println(ctr);
}


void isr(void){    
  ctr++;
/*
 // time = millis();
 // if(ctr == 0)
 //   timeref = time;
  Serial.print("interrupt ");
  Serial.println(ctr);
  times[ctr] = millis();
  last = ctr;
  ctr++;
  if(ctr==5) ctr = 0;
  */
}

