#include <Stream.h>
#include <SoftwareSerial.h>



#define SOFT_RX 4
#define SOFT_TX 5

// Serial baud rate
// Default for HC-05: 38400 (line ending: NL+CR)
// Default for HM-10: 9600  (line ending: NL+CR)
#define SOFT_BAUD_RATE 9600
#define HARD_BAUD_RATE 9600


SoftwareSerial SoftSerial(SOFT_RX, SOFT_TX); // RX, TX

void setup()
{
  Serial.begin(HARD_BAUD_RATE);      // Hardware serial port to PC
  SoftSerial.begin(SOFT_BAUD_RATE);  // Software serial port to Bluetooth module
  Serial.println("+ + +  S E R I A L  R E P E A T E R  + + +");
}


void loop() {
  static char c;

  if (SoftSerial.available()) {
    c = SoftSerial.read();
    Serial.print(c);
  }

  if (Serial.available()) {
    c = Serial.read();
    SoftSerial.print(c);
    Serial.print(c);
  }
}




/*
void setup() {
  Serial.begin(HARD_BAUD_RATE);    // hardware serial for the USB-PC
  BtSerial.begin(SOFT_BAUD_RATE);  // software serial Arduino to HC-06 (38400 is default)

  // print instructions
#ifdef HM_10
  Serial.println("HM-10 AT Command Programmer");
#else
  Serial.println("HC-05 AT Command Programmer");
#endif

  Serial.print("For Arduino Rx use pin ");
  Serial.println(SOFT_RX);

  Serial.print("For Arduino Tx use pin ");
  Serial.println(SOFT_TX);

  Serial.println(" -- Command Reference ---");
  Serial.println("To Read use '?', Like AT+PSWD?");
  Serial.println("AT (simply checks connection)");
  Serial.println("AT+VERSION (requests the firmware verison)");
  Serial.println("AT+ROLE=x (0 =Slave role, 1 =  Master role, 2 = Slave-Loop role  default = 0)");
  Serial.println("AT+NAME=xxxxx (to change name to xxxxx default=HC-05");
  Serial.println("AT+PSWD=nnnn (to change password to 4 digit nnnn default = 1234");
  Serial.println("AT+UART=nnnn,s,p (nnnn=Baud, s=stop bits (0=1, 1=2), p=parity (0=None, 1=Odd, 2=Even)");
  Serial.println("AT+POLAR=a,b (a=PIO8 (LED), b=PIO9 for both 0=low turn on, 1 = high turn on.");
  Serial.println("AT+ORGL (reset all parameters to defaults)");
  Serial.println("AT+RESET (restarts the HC-05. Will not be in AT mode afterward unless button held");


}

void loop() {
  static char c = ' ';

  // Read from HC-05
  if (BtSerial.available()) {
    while(BtSerial.available()) {
      c = BtSerial.read();
      Serial.print(c);
      }
  }

  // Read from PC
  if (Serial.available()){
    delay(10);
    c = Serial.read();

#ifdef HM_10
    // do not send line end characters to the HM-10
    if (c != 10 && c != 13 ) {
         BtSerial.write(c);
    }

    // Echo the user input to the main window.
    // If there is a new line print the ">" character.
    if (c == 10) {
      Serial.print("\r\n>");
    }
    Serial.write(c);


#else
    BtSerial.print(c); // show the HC-05 responce
    Serial.print(c);   // echo it back to the PC
#endif
  }
}

*/
