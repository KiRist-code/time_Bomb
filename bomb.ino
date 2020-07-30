int segPin[] = {2,3,4,5,6,7,8};
int seg[] = {0,0,0,0,1,0,0 //9
            ,0,0,0,0,0,0,0 //8
            ,0,0,0,1,1,1,1 //7
            ,0,1,0,0,0,0,0 //6
            ,0,1,0,0,1,0,0 //5
            ,1,0,0,1,1,0,0 //4
            ,0,0,0,0,1,1,0 //3
            ,0,0,1,0,0,1,0 //2
            ,1,0,0,1,1,1,1 //1
            ,0,0,0,0,0,0,1}; //0
int hz[] = {262,330,392,523,648}; //소리
int randNumber;
int k=0;
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A5));
  for(int i=2;i<9;i++){ //segment
    pinMode(i,OUTPUT);
  }
  for(int i=9;i<15;i++){ //switching port
    pinMode(i,INPUT);
  }
  pinMode(15,OUTPUT); //speaker
  randNumber = random(0,6); //랜덤 숫자
}

void loop() {
  Serial.println(randNumber); //랜덤숫자 출력
  if(digitalRead(9) == 1){
    Serial.println("1-1");
    if(digitalRead(10) == 1){
      Serial.println("2-1");
      if(digitalRead(11) == 1){
        Serial.println("3-1");
        if(digitalRead(12) == 1){
          Serial.println("4-1");
          if(digitalRead(13) == 1){
            Serial.println("5-1");
            if(digitalRead(14) == 1){
              Serial.println("6-1");
              tone(15,hz[4],500);
              delay(1000);
              for(int j=7*k;j<7*(k+1);j++){
                digitalWrite(segPin[j%7],seg[j]); // 카운트 다운 숫자 출력
                if(j==69){
                 tone(15,hz[4],5000);
                  delay(10000);
                  k=0;
                }
              }
              k++;
            }
            else if(digitalRead(randNumber + 8) == 1) {
            
              for(int i=0;i<4;i++){
                tone(15,hz[i],500);
                delay(500);
              }
            }
            else{
              for(int j=64;j<70;j++){
                digitalWrite(segPin[j%7],seg[j]);
              }
              tone(15,hz[4],500);
            }
          }
          else if(digitalRead(randNumber + 8)==1) {
            for(int i=0;i<4;i++){
              tone(15,hz[i],500);
              delay(500);
            }
          }
          else{
            for(int j=64;j<70;j++){
              digitalWrite(segPin[j%7],seg[j]);
            }
            tone(15,hz[4],500);
          }
        }
        else if(randNumber + 8 == 12) {
          for(int i=0;i<4;i++){
            tone(15,hz[i],500);
            delay(500);
          }
        }
        else{
          for(int j=64;j<70;j++){
            digitalWrite(segPin[j%7],seg[j]);
          }
          tone(15,hz[4],500);
        }
      }
      else if(randNumber + 8 ==11) {
        for(int i=0;i<4;i++){
          tone(15,hz[i],500);
          delay(500);
        }
      }
      else{
        for(int j=64;j<70;j++){
          digitalWrite(segPin[j%7],seg[j]);
        }
        tone(15,hz[4],500);
      }
    }
    else if(randNumber + 8 == 10) {
      for(int i=0;i<4;i++){
        tone(15,hz[i],500);
        delay(500);
      }
    }
    else{
      for(int j=64;j<70;j++){
        digitalWrite(segPin[j%7],seg[j]);
      }
      tone(15,hz[4],500);
    }
  }
  else if(randNumber + 8 == 9) {
    for(int i=0;i<4;i++){
      tone(15,hz[i],500);
      delay(500);
    }
  }
  else{
    for(int j=64;j<70;j++){
      digitalWrite(segPin[j%7],seg[j]);
    }
    tone(15,hz[4],500);
  }
//          }}}}}
}
