# Compteur IoT MQTT

Un compteur connecté publié via MQTT, exécuté sur une **Arduino MKR WiFi 1010**.

## Fonctionnalités

- Connexion WiFi au réseau
- Connexion à un broker MQTT 
- Reconnexion automatique en cas de perte de connexion
- Incrémentation du compteur toutes les **1 seconde**
- Publication de la valeur du compteur sur le topic `"compteur"` toutes les **5 secondes**

## Matériel

- **Carte** : Arduino MKR WiFi 1010 (processeur SAM D21 ARM Cortex-M0+)
- **Connectivité** : Module WiFi NINA W102 via SPI

## Architecture du projet

```
untitled2/
├── src/
│   ├── main.cpp          # Point d'entrée du programme
│   ├── Compteur.cpp      # Implémentation de la logique de comptage
│   └── Connectivite.cpp  # Implémentation de la connexion WiFi + MQTT
├── include/
│   ├── Config.h          # Configuration (SSID, mot de passe, broker MQTT)
│   ├── Compteur.h        # Déclaration de la classe Compteur
│   └── Connectivite.h    # Déclaration de la classe Connectivite
└── platformio.ini        # Configuration PlatformIO
```

### Classes

| Classe | Rôle |
|--------|------|
| `Config` | Constantes de configuration : SSID WiFi, mot de passe, adresse du broker MQTT, port, topic |
| `Compteur` | Gestion d'un compteur `unsigned long` avec incrémentation et conversion en chaîne |
| `Connectivite` | Abstraction réseau : connexion WiFi, connexion MQTT, publication de messages |

## Dépendances

| Bibliothèque | Version | Usage |
|--------------|---------|-------|
| `PubSubClient` | `^2.8` | Client MQTT léger |
| `WiFiNINA` | `^2.1.1` | Gestion du module WiFi intégré |

## Prérequis

- [PlatformIO](https://platformio.org/) installé (extension CLI ou IDE)
- CLion avec le plugin PlatformIO (optionnel)

## Configuration

Modifier les constantes dans `include/Config.h` :

- `ssid` : nom du réseau WiFi
- `password` : mot de passe WiFi
- `mqttBroker` : adresse IP du broker MQTT
- `mqttPort` : port MQTT (défaut : 1883)
- `mqttTopic` : topic MQTT de publication

## Build et upload

```bash
# Lister les ports USB disponibles
pio device list

# Compiler le projet
pio run

#Uploader sur la carte
pio run -t upload

# Ouvrir le moniteur série
pio run -t monitor
```

Ports configurés dans `platformio.ini` :

- Upload : `/dev/cu.usbmodem2101` à 115200 bauds
- Monitor : `/dev/cu.usbmodem2101` à 115200 bauds

## Commentaire

Ce projet est un exemple simple de dispositif IoT publié via MQTT. La structure modulaire permet de facilement étendre les fonctionnalités (ajout de capteurs, changements de fréquence de publication, etc.).
