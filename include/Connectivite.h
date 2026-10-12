//
// Created by Laurent Giustignano on 08/10/2026.
//

#ifndef UNTITLED2_CONNECTIVITE_H
#define UNTITLED2_CONNECTIVITE_H
#include <WiFiNINA.h>
#include "PubSubClient.h"

class Connectivite {
private:
    WiFiClient wifiClient;
    PubSubClient mqttClient;

public:
    Connectivite();
    void connectWiFi();
    void setBroker();
    void reconnectMQTT();
    void loop();
    bool isConnected();
    void publish(const char * topic, const char * payload);
};


#endif //UNTITLED2_CONNECTIVITE_H
