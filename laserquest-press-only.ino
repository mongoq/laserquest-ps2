#include <PS2X_lib.h>

PS2X ps2x;

int error = 0; 
byte type = 0;
byte vibrate = 0;

void setup(){
 Serial.begin(57600);

// error = ps2x.config_gamepad(13,11,10,12, true, true);   //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
 error = ps2x.config_gamepad(12,11,10,13, false, true);   //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
 
 if(error == 0){
   Serial.println("\nWelcome to Laserquest PS2 Control!\n");
   Serial.println("Found Controller, configured successful");
 }
   
  else if(error == 1)
   Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
   
  else if(error == 2)
   Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");
   
  else if(error == 3)
   Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
   
   type = ps2x.readType(); 
     switch(type) {
       case 0:
        Serial.println("Unknown Controller type");
       break;
       case 1:
        Serial.println("DualShock Controller found");
       break;
       case 2:
         Serial.println("GuitarHero Controller found");
       break;
     }
  
}

void loop(){
      
 if(error == 1) //skip loop if no controller found
  return; 

 if(type != 2){
  
    ps2x.read_gamepad(false, vibrate);          //read controller and set large motor to spin at 'vibrate' speed
    
    if (ps2x.NewButtonState())
    {
        if(ps2x.Button(PSB_L1))
         Serial.println("L1 pressed");
        if(ps2x.Button(PSB_R1))
         Serial.println("R1 pressed");
        if(ps2x.Button(PSB_L3))
         Serial.println("L3 pressed");
        if(ps2x.Button(PSB_R3))
         Serial.println("R3 pressed");
        if(ps2x.Button(PSB_L2))
         Serial.println("L2 pressed");
        if(ps2x.Button(PSB_R2))
         Serial.println("R2 pressed");
        if(ps2x.Button(PSB_GREEN)){
         Serial.println("Triangle pressed");
//         digitalWrite(2, HIGH);
//         delay(500);
//         digitalWrite(2, LOW);
//         delay(500);
        } 
        if(ps2x.Button(PSB_RED))        
         Serial.println("Circle pressed");
        if(ps2x.Button(PSB_PINK))            
         Serial.println("Square pressed");     
        if(ps2x.Button(PSB_BLUE))            
         Serial.println("X pressed");    
        if(ps2x.Button(PSB_START))             
         Serial.println("Start pressed");
        if(ps2x.Button(PSB_SELECT))
         Serial.println("Select pressed");
        if(ps2x.Button(PSB_PAD_UP))         
          Serial.println("Up pressed");
        if(ps2x.Button(PSB_PAD_DOWN))
          Serial.println("Down pressed");
        if(ps2x.Button(PSB_PAD_RIGHT))
          Serial.println("Right pressed");
        if(ps2x.Button(PSB_PAD_LEFT))
         Serial.println("Left pressed");
    }   
 }
 delay(50); // WICHTIG !!!  
}
