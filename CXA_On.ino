#include <IRremote.h>
#include <IRremoteInt.h>

/* 
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */


#include <IRremote.h>

IRsend irsend;
char buf[80];
int command_itr = 0;

// See CXA IR Remote Codes for documentation on command codes
// CXA System code (address) is 16

const int address = 16;

const int PWR_TOGGLE = 12;
const int PWR_ON = 14;
const int PWR_OFF = 15;

const int MUTE_TOGGLE = 13;
const int MUTE_ON = 50;
const int MUTE_OFF = 51;

const int VOL_UP = 16;
const int VOL_DOWN = 17;

const int LCD_TOGGLE = 72;
const int LCD_MAX = 18;
const int LCD_DIM = 19;
const int LCD_OFF = 71;

const int SPKR_TOGGLE = 20;
const int SPKR_AB = 30;
const int SPKR_A = 35;
const int SPKR_B = 39;

const int ANALOGUE_DIR = 78;

const int SRC_UP = 99;
const int SRC_DOWN = 126;
const int SRC_A1 = 100;
const int SRC_A2 = 101;
const int SRC_A3 = 102;
const int SRC_A4 = 103;
const int SRC_A1BAL = 104;

const int SRC_D1 = 105;
const int SRC_D2 = 106;
const int SRC_D3 = 107;
const int SRC_MP3 = 108;
const int SRC_USB = 114;
const int SRC_BLT = 115;

//send RC5 rpt number of times
void pushRC5(int RC5command, int rpt = 3){
   digitalWrite(13, HIGH);   //light up while transmitting
   for(int i = 0; i < rpt; i++){
    irsend.sendRC5ext(address, RC5command, 0);
    delay(20);
   }
   Serial.println("Sent");
   Serial.println(RC5command);
   digitalWrite(13 , LOW);   //turn off once done transmitting
}

int readline(int readch, char *buffer, int len) {
    static int pos = 0;
    int rpos;

    if (readch > 0) {
        switch (readch) {
            case '\r': // Ignore CR
                break;
            case '\n': // Return on new-line
                rpos = pos;
                pos = 0;  // Reset position index ready for next time
                return rpos;
            default:
                if (pos < len-1) {
                    buffer[pos++] = readch;
                    buffer[pos] = 0;
                }
        }
    }
    return 0;
}

void setup()
{
  pinMode(13, OUTPUT); 
  Serial.begin(9600);


  int repeat = 8;
  for (int i = 0; i <= repeat; i++){
    delay(1000);
    //send RC code
    pushRC5(PWR_ON);
  }


   
}

void loop() {
  if (readline(Serial.read(), buf, 80) > 0) {
        Serial.print("You entered: >");
        Serial.print(buf);
        String command = buf;
//        command.trim;
        Serial.println("<");
        
        
        switch (strcmp("A", buf)
        
        if(strcmp("A", buf) == 0){
          command_itr++;
          pushRC5(command_itr);
        }
        if(strcmp("Z", buf) == 0){
          command_itr--;
          pushRC5(command_itr);
         }
         if(strcmp("Q", buf) == 0){
          pushRC5(command_itr);
        }    
    }
}
 
