/******************************************************************************
 * SerialExtended lirary example.
 *
 * Little Sketch to test and give examples about the extended serial library.
 *
 ******************************************************************************
 * Autors
 * HeinrichAD
 *
 ******************************************************************************
 * License
 * GNU General Public License v3.0, see LICENSE file.
 *
 ******************************************************************************
 * Source code
 * https://github.com/HeinrichAD/Arduino-SerialExtended
 *
******************************************************************************/

#include <SerialExtended.h>

// Baudrate for serial monitor.
#define SERIAL_BAUD 9600


void setup() {
  // put your setup code here, to run once:
  // set up the serial port
  Serial.begin(SERIAL_BAUD);
}


void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
  	// Read user string
    String text = Serial.readString();

    // Set terminal attributes
    SuperSerial.SetAttributeMode(2, 41, 5);
    // or
    //SuperSerial.SetAttributeMode(41); // Red background color
    //SuperSerial.SetAttributeMode(5);  // Text blink
    // or
    //SuperSerial.SetAttributeMode(SerialExtended::DisplayAttributes::B_Red);
    //SuperSerial.SetAttributeMode(SerialExtended::DisplayAttributes::Blink);
    // or 
    //SuperSerial.SetAttributeMode(SuperSerial.DisplayAttributes::B_Red);
    //SuperSerial.SetAttributeMode(SuperSerial.DisplayAttributes::Blink);
    // or
    //SuperSerial.SetAttributeMode(2, SuperSerial::DisplayAttributes::B_Red, SerialExtended::DisplayAttributes::Blink);
    // or 
    //SuperSerial.SetAttributeMode(2, SuperSerial.DisplayAttributes::B_Red, SuperSerial.DisplayAttributes::Blink);
    // or
    // ...

    // Output user string
    Serial.print("Com: ");
    Serial.println(text);

    // Output some ASCCI charaters
    SuperSerial.SendASCIICode(65); // A
    SuperSerial.NewLine();
    SuperSerial.SendASCIICode(3, 65, 66, 67); // A, B, C
    SuperSerial.NewLine();

    // Reset all terminal attributes
    SuperSerial.SetAttributeMode(0);

    // Wait a little (0.5 seconds)
    delay(500);

    // Write 999 and change it to 777
    Serial.print(999);
    delay(1000); // Wait a little more (1 second)
    SuperSerial.Backspace(3);
    Serial.println(777);

    SuperSerial.NewLine();
  }
}