#include <PubSubClient.h>
#include "Compteur.h"
#include "Config.h"
#include "Connectivite.h"

Connectivite *connecteur;
Compteur *compteur;
static unsigned long lastMessage = 0;
static unsigned long lastIncrement = 0;

void setup() {
    connecteur = new Connectivite();
    compteur = new Compteur();

    connecteur->connectWiFi();
    connecteur->setBroker();
}

void loop() {
    if (!connecteur->isConnected()) {
        connecteur->reconnectMQTT();
    }

    connecteur->loop();

    unsigned long currentMillis = millis();

    if (currentMillis - lastIncrement >= Settings::incrementTimer) {
        compteur->increment();
        lastIncrement = currentMillis;
    }

    if (currentMillis - lastMessage >= Settings::publishTimer) {
        String message = compteur->toString();
        connecteur->publish(Settings::mqttTopic, message.c_str());
        lastMessage = currentMillis;
    }
}
