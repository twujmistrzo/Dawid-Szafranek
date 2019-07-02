#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#ifndef X_CS_PIN
  #define X_CS_PIN         53
#endif

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#ifndef Y_CS_PIN
  #define Y_CS_PIN         49
#endif

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#ifndef Z_CS_PIN
  #define Z_CS_PIN         40
#endif
#ifndef X_MAX_PIN
  #define X_MAX_PIN         2
#endif
#define Y_MAX_PIN          15
#define Z_MAX_PIN          19

bool flaga=0;
//nazwy globalne

int licznik=0; //licznik krokow
int kierunek=0; // aktualny kierunek
String wiadomosc;
int krokx=0, kroky=0, krokz=0;
int kierx=0, kiery=0, kierz=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(X_ENABLE_PIN, OUTPUT);
  digitalWrite(X_ENABLE_PIN, LOW);
  
   pinMode(Y_ENABLE_PIN, OUTPUT);
  digitalWrite(Y_ENABLE_PIN, LOW);
  
   pinMode(Z_ENABLE_PIN, OUTPUT);
  digitalWrite(Z_ENABLE_PIN, LOW);
  
  pinMode(X_DIR_PIN, OUTPUT);
  digitalWrite(X_DIR_PIN, LOW);
  
  pinMode(Y_DIR_PIN, OUTPUT);
  digitalWrite(Y_DIR_PIN, LOW);
  
  pinMode(Z_DIR_PIN, OUTPUT);
  digitalWrite(Z_DIR_PIN, LOW);
  
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Z_STEP_PIN, OUTPUT);
  
  pinMode(X_MAX_PIN, INPUT_PULLUP);
  pinMode(Y_MAX_PIN, INPUT_PULLUP);
  pinMode(Z_MAX_PIN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if((digitalRead((X_MAX_PIN)==0 && kierunek==0) || kierunek==1)&&krokx>0)
  {
    digitalWrite(X_STEP_PIN, LOW);
    krokx--;
  }
    if((digitalRead((Y_MAX_PIN)==0 && kierunek==0) || kierunek==1)&&kroky>0)
  {
      digitalWrite(Y_STEP_PIN, LOW);
      kroky--;
  }
    if((digitalRead((Z_MAX_PIN)==0 && kierunek==0) || kierunek==1)&&krokz>0)
  {
    digitalWrite(Z_STEP_PIN, LOW);
    krokz--;
  }  
 delay(1);
  
  if(digitalRead(X_MAX_PIN)==0)
  digitalWrite(X_STEP_PIN, HIGH);
  
  if(digitalRead(Y_MAX_PIN)==0)
  digitalWrite(Y_STEP_PIN, HIGH);
  
  if(digitalRead(Z_MAX_PIN)==0)
  digitalWrite(Z_STEP_PIN, HIGH);
  delay(1);

//licznik++;
//  if(licznik==200)
// {
//  kierunek=! kierunek;
//  digitalWrite(X_DIR_PIN, kierunek);
//  digitalWrite(Y_DIR_PIN, kierunek);
//  digitalWrite(Z_DIR_PIN, kierunek);
//  
//  licznik=0;
//   
// }
 while (Serial.available () > 0)
 {
  wiadomosc = Serial.readStringUntil('\n');
  sscanf(wiadomosc.c_str(), "x %d y %d z %d", &krokx, &kroky, &krokz);
  flaga=1;
  kierx = krokx < 0;
  digitalWrite(X_DIR_PIN, kierx);
  krokx = abs(krokx);

  kiery = kroky < 0;
  digitalWrite(Y_DIR_PIN, kiery);
  kroky = abs(kroky);

  kierz = krokz < 0;
  digitalWrite(Z_DIR_PIN, kierz);
  krokz = abs(krokz);
 }
 if(krokx==0 && kroky==0 && krokz==0 && flaga==1)
  {
    Serial.print("OK \n");
    flaga=0;
  }
 
}

  //Serial.println(digitalRead(X_MAX_PIN));(podglad)

matlab:
% s=serial('/dev/ttyUSB0')
% s.BaudRate=115200
% fopen(s)
% s
%fclose(s)
% while(1)
%     fprintf(s, 'x -200 y -200 z -200');
%     pause(1)
%     fprintf(s, 'x 200 y 200 z 200');
%     pause(1)
% end

% while(s.BytesAvailable)
%     fscanf(s)
% end 
% while(1)
%     fprintf(s, 'x 200 y 200 z 200')
%     while(s.BytesAvailable==0), end
%     fscanf(s)
%     
%     fprintf(s, 'x -200 y -200 z -200')
%     while(s.BytesAvailable==0), end
%     fscanf(s)
% end

b=0;
b1=0;
b2=0;
for t=0: 0.1: 6.28
    a = round(500*sin(t))
    c = round(500*sin(t+2*pi/3))
    d = round(500*sin(t+4/3*pi))

    fprintf(s, 'x %d y %d z %d \n', [a-b,c-b1,d-b2])
    while(s.BytesAvailable==0), end
    fscanf(s)
    b=a;
    b1=c;
    b2=d;
end
