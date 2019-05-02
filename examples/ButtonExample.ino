void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  addButton(50, 70, 200, 100, "Button1", 1); //add button
  drawButton(1, 0xFFFF); //draw Button1;
  
  addTextButton(50, 370, 200, 100, "Textbutton1", 1);
  
  Serial.begin(9600);
}
void loop(){
String pressed = buttonPressed(PUT_HERE_THE_X_AND_Y_COORDINATES_FROM_TOUCHSCREEN);
if(pressed != "-1"){
    Serial.println(pressed);
  }
}
