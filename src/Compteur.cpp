//
// Created by Laurent Giustignano on 08/10/2026.
//

#include "Compteur.h"


Compteur::Compteur() {
    this->compteur = 0;
}

Compteur::Compteur(const unsigned long cpt) {
    this->compteur = cpt;
}

void Compteur::setCompteur(const unsigned long cpt) {
    this->compteur = cpt;
}

unsigned long Compteur::getCompteur() const {
    return this->compteur;
}

void Compteur::increment() {
    this->compteur++;
}

String Compteur::toString() const {
    return String(this->compteur);
}
