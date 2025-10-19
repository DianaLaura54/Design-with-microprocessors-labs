#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
// Character matrix for the first character: every line is a
//row of pixels of the character
byte line1[8] = {
 B10000,
 B10000,
 B10000,
 B10000,
 B10000,
 B10000,
 B10000,
 B10000,
};
// Matrix for the second character
byte line2[8] = {
 B00000,
 B00000,
 B00000,
 B00000,
 B00000,
 B00000,
 B00000,
 B11111,
};
byte line3[8] = {
 B00001,
 B00001,
 B00001,
 B00001,
 B00001,
 B00001,
 B00001,
 B00001,
};
byte line4[8] = {
 B11111,
 B00000,
 B00000,
 B00000,
 B00000,
 B00000,
 B00000,
};
void setup() {
 lcd.begin(16, 2);
 // The 2 character are stored in the CGROM, user defined
 //area, pos. 0 and 1
 lcd.createChar(0, line1);
 lcd.createChar(1, line2);
  lcd.createChar(2, line3);
   lcd.createChar(3, line4);
 // Display the first line: a string followed by the 1-
 //stuser defined char
 lcd.setCursor(0, 0);
 lcd.write(byte(0));
 delay(2000);
 lcd.setCursor(0, 0);
 lcd.write(byte(1));
 delay(2000);
 lcd.setCursor(0, 0);
 lcd.write(byte(2));
 delay(2000);
 lcd.setCursor(0, 0);
 lcd.write(byte(3));
 delay(2000);

  // See the difference between print
 //and write
 /* When you are referring the “0” user defined char you
 must write a cast to the “byte”
type, otherwise the compiler throws an error. Exception
is the case when you are referring a varaiable:
 byte zero = 0;
 lcd.write(zero);
 */
 // Display the second line
 // when you are referring other characters
 //then “0” it is not necessary to cast
}
void loop()
{ }
