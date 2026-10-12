//
// Created by Laurent Giustignano on 08/10/2026.
//

#include "Connectivite.h"
#include "Config.h"


Connectivite::Connectivite() : mqttClient(wifiClient) {
}

void Connectivite::connectWiFi() {
    WiFi.begin(ConfigWifi::ssid, ConfigWifi::password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
}

void Connectivite::reconnectMQTT() {
    while (!mqttClient.connected()) {
        if (mqttClient.connect("ArduinoMKR")) {
        } else {
            delay(2000);
        }
    }
}

void Connectivite::loop() {
    mqttClient.loop();
}

bool Connectivite::isConnected() {
    return mqttClient.connected();
}

void Connectivite::publish(const char *topic, const char *payload) {
    mqttClient.publish(topic, payload);
}

void Connectivite::setBroker() {
    mqttClient.setServer(Settings::mqttBroker, Settings::mqttPort);
}
