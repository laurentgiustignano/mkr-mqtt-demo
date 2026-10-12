//
// Created by Laurent Giustignano on 08/10/2026.
//

#ifndef UNTITLED2_CONFIG_H
#define UNTITLED2_CONFIG_H

namespace Settings {
    constexpr auto mqttIdCommunication = "NodeMCUClient";
    constexpr auto mqttBroker = "ip de votre broker mqtt";
    constexpr auto mqttPort = 1883;
    constexpr auto mqttTopic = "compteur";
    constexpr auto incrementTimer = 1000;
    constexpr auto publishTimer = 3000;

}

namespace ConfigWifi {
    constexpr auto ssid = "votre wifi";
    constexpr auto password = "votre mdp";
}


#endif //UNTITLED2_CONFIG_H
