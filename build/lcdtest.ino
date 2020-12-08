/*
 * lCD DRAWING ROBOT CONTROLLER
 * 
 * PURPOSE: SEND BASIC GRBL COMMANDS THROUGH THE USE OF A MENU INTERFACE ON A LCD SCREEN TO
 * AN ARDUINO UNO RUNNING GRBL WITH A CNC SHIELD
 * 
 * CREATED NOVEMBER 28,2020. (BASIC KEYPAD CONTROLS AND MAPPING TO STATES)
 * MODIFIED NOVEMBER 29,2020. (MENU INTERFACE)
 * MODIFIED DECEMBER 2,2020.  (ADDITION OF SEOFTWARESERIAL FOR COMMUNICATON BETWEEN ARDUINO UNOS)
 * MODIFIED DECEMBER 3,2020.  (SENDING GRBL COMMANDS FROM THE LCD TO DRAWING MACHINE) 
 * 
 * by ONAOPEMIPO ADIGUN
 */
//library code:
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

uint8_t i=0;
//States for the menu.
int currentMenuItem = 0;
int lastState = 0;
SoftwareSerial mySerial(2, 3); //RX,TX

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }
  
  mySerial.begin(115200);
  mySerial.println("Hello, world?");
  lcd.begin(16, 2);
  lcd.print ("Initializing...");
  delay(2500);
  lcd.clear ();
  clearPrintTitle();
  lcd.setBacklight(WHITE);
  
}

void loop() 
{
  // put your main code here, to run repeatedly:
   if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
  mainMenu();
  
}

void clearPrintTitle() 
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DRAWING ROBOT");
  lcd.setCursor(0,1); 
}

void mainMenu() {
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
  //State = 0 every loop cycle.
  int state = 0;
  
  //Set the Row 0, Col 0 position.
  lcd.setCursor(0,0);

  uint8_t buttons = lcd.readButtons();
  if (buttons) {
    lcd.clear();
    lcd.setCursor(0,0);
  if (buttons & BUTTON_UP) {
      //lcd.print("UP ");
      state = 1;
    }
  if (buttons & BUTTON_DOWN) {
      //lcd.print("DOWN ");
      state = 2;
    }
  if (buttons & BUTTON_LEFT) {
      //lcd.print("LEFT ");
      state = 4;
    }
  if (buttons & BUTTON_RIGHT) {
      //lcd.print("RIGHT ");
      state = 5;
    }
  if (buttons & BUTTON_SELECT) {
      //lcd.print("SELECT ");
      state = 3;
    }
}
  
  //If we are out of bounds on the menu then reset it.
  if (currentMenuItem < 0 || currentMenuItem >=7) 
  {
   currentMenuItem = 0; 
  }

  
   //If we have changed Index, saves re-draws.
   if (state != lastState) {
      if (state == 1) {
         //If Up
          currentMenuItem = currentMenuItem - 1; 
          displayMenu(currentMenuItem);
      } else if (state == 2) {
         //If Down
          currentMenuItem = currentMenuItem + 1;  
          displayMenu(currentMenuItem);
      } else if (state == 3) {
         //If Selected
         selectMenu(currentMenuItem); 
      }
      //Save the last State to compare.
      lastState = state;
   } 
    delay(10);
}   

void displayMenu(int x) {
     switch (x) {
      case 1:
        clearPrintTitle();
        lcd.print ("-> Home");
        delay(100);
        break;
      case 2:
        clearPrintTitle();
        lcd.print ("-> Zero Axes");
        delay(100);
        break;
       case 3:
        clearPrintTitle();
        lcd.print ("-> Test Run ");
        delay(100);
        break;
      case 4:
        clearPrintTitle();
        lcd.print ("-> Pause Job");
        delay(100);
        break;
      case 5:
        clearPrintTitle();
        lcd.print ("-> Resume Job");
        delay(100);
        break;
      case 6:
        clearPrintTitle();
        lcd.print ("-> RESET GRBL");
        delay(100);
        break;
      case 7:
        clearPrintTitle();
        lcd.print ("-> UNLOCK GRBL");
        delay(100);
        break;
    }
}

//Show the selection on Screen.
void selectMenu(int x) {
   switch (x) {
      case 1:
        clearPrintTitle();
        lcd.print ("Homing...");
        delay(2500);
        mySerial.println("$H");
        clearPrintTitle();
        displayMenu(currentMenuItem);
        //Send command to GRBL to software reset
        break;
      case 2:
        clearPrintTitle();
        lcd.print ("Zeroing Axes...");
        delay(2500);
        mySerial.println("G92 X0 Y0");
        clearPrintTitle();
        displayMenu(currentMenuItem);
        //Send command to GRBL to zero position
        break;
       case 3:
        clearPrintTitle();
        lcd.print ("Test Running...");
        delay(2500);
        mySerial.println("G1 X10 Y50 F2000");
        clearPrintTitle();
        displayMenu(currentMenuItem);
        //Send command to grbl to go home
        break;
      case 4:
        clearPrintTitle();
        lcd.print ("Pausing...");
        delay(2500);
        mySerial.println("!");
        clearPrintTitle();
        displayMenu(currentMenuItem);
        //Send command to GRBL to Pause Job Queue
        break;
      case 5:
        clearPrintTitle();
        lcd.print ("Resuming...");
        delay(2500);
        mySerial.println("~");
        clearPrintTitle();
        displayMenu(currentMenuItem);
        //Send command to GRBL to Resume Job Queue
        break;
      case 6:
        clearPrintTitle();
        lcd.print ("GRBL Resetting...");
        delay(2500);
        mySerial.println("CTRL+X");
        clearPrintTitle();
        displayMenu(currentMenuItem);
        //Call the function that belongs to Option 4
        break;
      case 7:
        clearPrintTitle();
        lcd.print ("Unlocking...");
        delay(2500);
        mySerial.println("$X");
        clearPrintTitle();
        displayMenu(currentMenuItem);
        //Call the function that belongs to Option 4
        break;
    }
}
