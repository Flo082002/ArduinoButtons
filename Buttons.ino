#define MAXBUTTONCOUNT 40
#define TastaturTextSize 6

int ButtonX[MAXBUTTONCOUNT], ButtonY[MAXBUTTONCOUNT];
int ButtonW[MAXBUTTONCOUNT], ButtonH[MAXBUTTONCOUNT];
String ButtonName[MAXBUTTONCOUNT];
int buttonCount = 0;


void addButton(int x, int y, int w, int h, String Name, int adress){
        ButtonX[adress] = x;
        ButtonY[adress] = y;
        ButtonW[adress] = w;
        ButtonH[adress] = h;
        ButtonName[adress] = Name;
        #ifdef DEBUG
        freeMemory("addButton :" + Name + ": " + String(adress) );
        #endif

        if (buttonCount < adress) buttonCount = adress;
        #ifdef ADDBUTTON_DEBUG
        Serial.print(F("addButton :"));
        Serial.print(Name);
        Serial.print(": " + String(adress));
        Serial.println(" ");
        #endif
}

void addTextButton(int x, int y, int w, int h, char Name, int adress){

        addTextButton(x, y, w, h, String(Name), adress);
        #ifdef ADDBUTTON_DEBUG
        Serial.print(F("addTextCharButton :"));
        Serial.print(Name);
        Serial.print(": " + String(adress));
        Serial.println(" ");
        #endif
}

void addTextButton(int x, int y, int w, int h, String Name, int adress){

        addButton(x, y, w, h, Name, adress);
        drawButton(adress,0xB7E0);
        drawButtonText(adress, textColor);
        #ifdef DEBUG
        freeMemory("addTextStringButton :" + Name + ": " + String(adress) );
        #endif

        #ifdef ADDBUTTON_DEBUG
        Serial.print(F("addTextStringButton :"));
        Serial.print(Name);
        Serial.print(": " + String(adress));
        Serial.println(" ");
        #endif
}

void addTextButton(int x, int y, int w, int h, String Name, int adress, uint16_t BG_color){
        addButton(x, y, w, h, Name, adress);
        drawBgButton(adress, 0xB7E0, BG_color);
        drawButtonText(adress, textColor);
        #ifdef DEBUG
        freeMemory("addTextStringButtonBg :" + Name + ": " + String(adress) );
        #endif

        #ifdef ADDBUTTON_DEBUG
        Serial.print(F("addTextStringButtonBg :"));
        Serial.print(Name);
        Serial.print(": " + String(adress));
        Serial.println(" ");
        #endif


}

void drawButton(int adress, uint16_t color){

        tft.drawRoundRect(ButtonX[adress], ButtonY[adress], ButtonW[adress], ButtonH[adress],8, color);
}

void drawBgButton(int adress, uint16_t color, uint16_t bg){
        tft.fillRoundRect(ButtonX[adress], ButtonY[adress], ButtonW[adress], ButtonH[adress],8, bg);
        drawButton(adress, color);
        //tft.drawRoundRect(ButtonX[adress], ButtonY[adress], ButtonW[adress], ButtonH[adress],8, color);
}



void drawButton(String ButtonName, uint16_t color){
        int i = 0;
        while(ButtonName != ButtonName[i] and i < buttonCount+2) i++;
        if(ButtonName == ButtonName[i]) {
                drawButton(i, color);
        }
}

void drawButtonText(int adress, uint16_t color){
  tft.setTextColor(color);
        int x = ButtonX[adress];
        int y = ButtonY[adress];
        int w = ButtonW[adress];
        int h = ButtonH[adress];
        String Name = ButtonName[adress];

        int textSize = tft.getTextSize();
        int xStart = x + ((w - (textSize*6*Name.length()))/2);
        int yStart = y + ((h-(textSize*7))/2);
        tft.setCursor(xStart,yStart);
        tft.println(Name);

}

void deleteButton(int adress, uint16_t color){
        tft.fillRect(ButtonX[adress], ButtonY[adress], ButtonW[adress], ButtonH[adress], color);
        ButtonX[adress] = 0;
        ButtonY[adress] = 0;
        ButtonW[adress] = 0;
        ButtonH[adress] = 0;
        ButtonName[adress] = "-1";
}

void deleteButtonFromTo(int adress1, int adress2, uint16_t color){
        int i = adress1;
        while (i >= adress2) {
                deleteButton(i, color);
                i++;
        }

}



String buttonPressed(){
        int found = 0;

  #ifdef DEBUG
        Serial.println("Start for schleife");
  #endif

        for(int i = 0; i < MAXBUTTONCOUNT; i++) {

          #ifdef DEBUG
                Serial.println("i= "+ String(i));
          #endif
                int _x = ButtonX[i];
                int _y = ButtonY[i];
                int _w = ButtonW[i];
                int _h = ButtonH[i];
                if(isBetween(_x, pressX, _x + _w) and isBetween(_y, pressY, _y + _h)) {
                        return ButtonName[i];
                        found = 1;
                }
        }
        if(found == 0) return "-1";
}


bool isBetween(long i1, long x, long i2){
        if(x>i1 && i2>x) return true;
        else return false;
}

String getButtonName(int adress){
        return ButtonName[adress];
}

void renameButton(int adress, String name){
        ButtonName[adress] = name;
}

void printButtonName(int adress){
        Serial.println(ButtonName[adress]);
}
