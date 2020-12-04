//
// Created by MAGUENDJI Freud on 12/2/20.
//

#include "TPClient.h"
//StaticJsonDocument<500> doc;
TPClient::TPClient() {

}

bool TPClient::connect() {
    if (WiFi.status() == WL_NO_MODULE) {
        Serial.println("Communication with WiFi module failed!");
        return false;
    }
    status = WiFi.begin(SSID_,PASSWORD_);
    return status==WL_CONNECTED;
}

bool TPClient::isConnected() {
    return client.connected();
}

bool TPClient::connectToServeur() {
    return client.connect(IP_ADDRESS, 8081);


}

void TPClient::disconnectServeur() {
    client.stop();
}

bool TPClient::writePoint(Point point) {
    return client.println(point.toJson())<=0;
}

int TPClient::available() {

    return client.available();
}

JSONVar TPClient::readData(char *data, size_t lengh) {
    client.read((uint8_t *)data,lengh);
    JSONVar myObject = JSON.parse(data);
    return myObject;
}


