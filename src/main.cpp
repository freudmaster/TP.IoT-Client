#include <Arduino.h>
#define NUM_JOY 2
#define MIN_VAL 0
#define MAX_VAL 1023
#include "../.pio/libdeps/nano_33_iot/Arduino_JSON/src/Arduino_JSON.h"
#include "Point.h"
#include "TPClient.h"

//Parameters
int VRx = A6;
int VRy = A7;
int SW = 8;
int maxWidth=0;
int minWidth=800;
int maxHeight=600;
int minHeight=100;
int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int positionColor=0;
const int SIZE_COLOR=9;
const String colors[]={"0.0.0","86.101.115","220.118.51","244.208.63","130.224.170","93.173.226","165.105.189","231.76.60","0.128.128"};
TPClient client;
bool connected=false;
int sizeData=0;

Point readJoystick();
void printWifiStatus();
int joyRawToPhys(int raw,int min,int max);

void setup() {
    Serial.begin(9600);
    delay(2000);
    Serial.begin(9600);

    Serial.println(F("Initialize System"));
    pinMode(VRx, INPUT);
    pinMode(VRy,INPUT);
    pinMode(SW,INPUT_PULLUP);
    client.connect();
    delay(1000);
    if(client.isConnected())
        Serial.println("Connexion to Wifi Successfull");
    pinMode(LED_BUILTIN, OUTPUT);
    connected=client.connectToServeur();
}

void loop() {
    if (client.isConnected()) {
        if((sizeData=client.available())){
            char data[sizeData];
            JSONVar json=client.readData(data, sizeData);
            if (json.hasOwnProperty("width"))
                minWidth=(int) json["width"];

            if (json.hasOwnProperty("height"))
                maxHeight=(int) json["height"];

            Serial.println(data);
        }
        int read=digitalRead(SW);
        if(read==0) {
            positionColor++;
            positionColor = positionColor % SIZE_COLOR;
        }
        Point p=readJoystick();
        client.writePoint(p);
        if(digitalRead(LED_BUILTIN)==LOW)
            digitalWrite(LED_BUILTIN,HIGH);

        delay(100);
    }else{
        Serial.println();
        Serial.println("disconnecting from server.");
        Serial.print("You're connected to the network");
        if(digitalRead(LED_BUILTIN)==HIGH)
            digitalWrite(LED_BUILTIN, LOW);
        if((connected=client.connectToServeur()))
            Serial.print("You're connected to the network");
        else
            delay(10000);
    }

}
Point readJoystick() {
    xPosition=analogRead(VRx);
    yPosition=analogRead(VRy);
    SW_state=digitalRead(SW);
    Point p((float)(joyRawToPhys(xPosition,minWidth,maxWidth)),(float)joyRawToPhys(yPosition,minHeight,maxHeight));

    p.setColor(colors[positionColor]);
    //Serial.println(p.toJson());
    return p;
}

int joyRawToPhys(int raw,int min,int max) {
    int phys = map(raw, MIN_VAL, MAX_VAL,min,max);
    return phys;
}
