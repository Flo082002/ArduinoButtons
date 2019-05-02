# ArduinoButtons
1. Copy the Buttons.ino file in the scetch folder
2. Reopen your project
3. Open find and open Buttons.ino in the Arduino tabs
4. Edit Buttons.ino: #define MAXBUTTONCOUNT "YOUR_BUTTON_COUNT"
5. Add button with addButton(int x, int y, int w, int h, String Name, int adress);
6. Add buttonPressed(int pressX, int pressY); to void loop()
7. If a button is pressed, buttonPressed will return the name of the button;
