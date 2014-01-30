const int  buttonPin = 12;    // the pin that the pushbutton is attached to
const int  data=13;

const int out0=0;
const int out1=1;
const int out2=2;
const int out3=3;
const int out4=4;
const int out5=5;
const int out6=6;
const int out7=7;
const int out8=8;
const int out9=9;

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 1;     // previous state of the button
int datainfo=0;
int zerocounter=0;
int onecounter=0;
int numcounter=0;
int decNO[17];
int i=0;
int temp[100];
   int cache[5];
int m=0;
int j=0;
boolean initial=true;
int k=0;
int xx=0;
int time=10000;


void setup() {
 // initialize the button pin as a input:
 pinMode(buttonPin, INPUT);
 // initialize the LED as an output:
 pinMode(data,INPUT);


 pinMode(out2, OUTPUT);
 pinMode(out3, OUTPUT);
 pinMode(out4, OUTPUT);
 pinMode(out5, OUTPUT);
 pinMode(out6, OUTPUT);
 pinMode(out7, OUTPUT);
 pinMode(out8, OUTPUT);
 pinMode(out9, OUTPUT);
 
 // initialize serial communication:
Serial.begin(9600);
}


void loop() {
 // read the pushbutton input pin:
 buttonState = digitalRead(buttonPin);
 datainfo=digitalRead(data);

 // compare the buttonState to its previous state


 if (buttonState != lastButtonState) {
   // if the state has changed, increment the counter
   if(buttonState==LOW)
   {
     if(datainfo==LOW)
         datainfo=1;
     else
       datainfo=0;
        
        
   if(initial) 
   { 
     temp[i]=datainfo;
     
     
     if(i>=4)
     {
      if(temp[i-4]==1 && temp[i-3]==1 && temp[i-2]==0 && temp[i-1]==1 && temp[i]==0 )
      {
       initial=false; 
       j=1;
       m=0;
      }
     }
     i++;
   }
   
   
   //////////////////////////////////////////////////////////////////////////////////////////////////
   //here we goes into real work
   if(!initial && k==1)
   {
     if(m==4)
     {
       cache[m]=datainfo;
     
     // Serial.println(datainfo);
     decNO[j]=cache[0]+cache[1]*2+cache[2]*4+cache[3]*8;
     
     if(j==1) 
     {
       if(decNO[1]!=6)
      { if(xx==0)
        {Serial.println("direction reversed!");
        xx++;
        }
        initial=true;
        i=0; 
        k=0;
     }
     else xx=0;
   }
     
     j++;
     m=0;
     }
     else 
     {
       //Serial.print(datainfo);
       cache[m]=datainfo;
       m++;
     }
    
     if(j==17)
     {
      
        showgame(decNO);
       
       Serial.println("done once");
       lastButtonState = 1;
       j=1;
       m=0;
       initial=true;
       i=0;
       k=0;
     }
   }

if(!initial) k=1;

   }
   }

 lastButtonState = buttonState;
}


void showgame(int decNO[])
{
   for(i=1;i<=16;i++)
       {
   Serial.print("Dec goes here :");
   Serial.println(decNO[i]);
   realshow(decNO[i]);
  
       }
}

void realshow(int a)
{
  switch(a)
  {
    case 0:
    digitalWrite(out2, HIGH);
    digitalWrite(out3,HIGH);
     digitalWrite(out7,HIGH);
     digitalWrite(out4,HIGH);
     digitalWrite(out6,HIGH);
     digitalWrite(out5,HIGH);
                    
     delay(time);
     digitalWrite(out2, LOW);
     digitalWrite(out3, LOW);
     digitalWrite(out7, LOW);
     digitalWrite(out4, LOW);
     digitalWrite(out6, LOW);
     digitalWrite(out5, LOW);
      break;
      
       case 1:
     digitalWrite(out3, HIGH);
     digitalWrite(out4, HIGH);
     delay(time);
     digitalWrite(out3, LOW);
     digitalWrite(out4, LOW);
      break;
      
       case 2:
     digitalWrite(out2, HIGH);
    digitalWrite(out8,HIGH);
     digitalWrite(out7,HIGH);
     digitalWrite(out4,HIGH);
     digitalWrite(out5,HIGH);
     delay(time);
     digitalWrite(out2, LOW);
     digitalWrite(out8, LOW);
     digitalWrite(out7, LOW);
     digitalWrite(out4, LOW);
     digitalWrite(out5, LOW);
      break;
      
       case 3:
       digitalWrite(out2, HIGH);
    digitalWrite(out8,HIGH);
     digitalWrite(out7,HIGH);
     digitalWrite(out6,HIGH);
     digitalWrite(out5,HIGH);
     delay(time);
      digitalWrite(out2, LOW);
     digitalWrite(out8, LOW);
     digitalWrite(out7, LOW);
     digitalWrite(out6, LOW);
     digitalWrite(out5, LOW);
      break;
      
       case 4:
      digitalWrite(out3, HIGH);
    digitalWrite(out8,HIGH);
     digitalWrite(out7,HIGH);
     digitalWrite(out6,HIGH);
     delay(time);
      digitalWrite(out3, LOW);
     digitalWrite(out8, LOW);
     digitalWrite(out7, LOW);
     digitalWrite(out6, LOW);
      break;
      
       case 5:
         digitalWrite(out2, HIGH);
    digitalWrite(out8,HIGH);
     digitalWrite(out3,HIGH);
     digitalWrite(out6,HIGH);
     digitalWrite(out5,HIGH);
     delay(time);
       digitalWrite(out2, LOW);
     digitalWrite(out8, LOW);
     digitalWrite(out3, LOW);
     digitalWrite(out6, LOW);
     digitalWrite(out5, LOW);
      break;
      
       case 6:
     digitalWrite(out2, HIGH);
    digitalWrite(out8,HIGH);
     digitalWrite(out3,HIGH);
     digitalWrite(out6,HIGH);
     digitalWrite(out5,HIGH);
     digitalWrite(out4,HIGH);
     delay(time);
      digitalWrite(out2, LOW);
     digitalWrite(out8, LOW);
     digitalWrite(out3, LOW);
     digitalWrite(out6, LOW);
     digitalWrite(out5, LOW);
     digitalWrite(out4, LOW);
      break;
      
       case 7:
       digitalWrite(out2, HIGH);
    digitalWrite(out7,HIGH);
     digitalWrite(out6,HIGH);
     delay(time);
      digitalWrite(out2, LOW);
     digitalWrite(out7, LOW);
     digitalWrite(out6, LOW);
      break;
      
       case 8:
    digitalWrite(out2, HIGH);
    digitalWrite(out8,HIGH);
     digitalWrite(out3,HIGH);
     digitalWrite(out6,HIGH);
     digitalWrite(out5,HIGH);
     digitalWrite(out4,HIGH);
      digitalWrite(out7,HIGH);
     delay(time);
     digitalWrite(out2, LOW);
     digitalWrite(out8, LOW);
     digitalWrite(out3, LOW);
     digitalWrite(out6, LOW);
     digitalWrite(out5, LOW);
     digitalWrite(out4, LOW);
     digitalWrite(out7, LOW);
      break;
      
       case 9:
       digitalWrite(out2, HIGH);
    digitalWrite(out8,HIGH);
     digitalWrite(out3,HIGH);
     digitalWrite(out6,HIGH);
     digitalWrite(out5,HIGH);
      digitalWrite(out7,HIGH);
     delay(time);
      digitalWrite(out2, LOW);
     digitalWrite(out8, LOW);
     digitalWrite(out3, LOW);
     digitalWrite(out6, LOW);
     digitalWrite(out5, LOW);
     digitalWrite(out7, LOW);
      break;
      
  }
}
/*
boolean reverse(int x)
{
  if(x==6) 
  return false;
  
  else 
  {
    Serial.println("lohahahahaha!!!!!!!!! Please check direction!!!!!!!!!!");
    return true;
}
}*/
