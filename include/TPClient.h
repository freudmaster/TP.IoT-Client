//
// Created by MAGUENDJI Freud on 12/2/20.
//

#ifndef UNTITLED4_TPCLIENT_H
#define UNTITLED4_TPCLIENT_H

#define SSID_ "FREUD_HOME"
#define PASSWORD_ "jesuislemotdepasse"
#define IP_ADDRESS "192.168.1.37"
#include <SPI.h>
#include "Point.h"
#include "../.pio/libdeps/nano_33_iot/Arduino_JSON/src/Arduino_JSON.h"
#include "../.pio/libdeps/nano_33_iot/WiFiNINA/src/WiFiClient.h"
#include "../.pio/libdeps/nano_33_iot/WiFiNINA/src/utility/wl_definitions.h"
#include "../.pio/libdeps/nano_33_iot/WiFiNINA/src/WiFi.h"

class TPClient {
public:
    TPClient();
    bool connect();
    bool isConnected();
    bool connectToServeur();
    bool writePoint(Point point);
    void disconnectServeur();
    int available();
    JSONVar readData(char* data,size_t lenght);

private:
    int status = WL_IDLE_STATUS;
    String server;
    WiFiClient client;

};


#endif //UNTITLED4_TPCLIENT_H
