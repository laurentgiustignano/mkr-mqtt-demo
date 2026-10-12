//
// Created by Laurent Giustignano on 08/10/2026.
//

#ifndef UNTITLED2_COMPTEUR_H
#define UNTITLED2_COMPTEUR_H
#include <api/String.h>


class Compteur {

    private:
    unsigned long compteur;

    public:
    Compteur();
    Compteur(unsigned long cpt);

    void setCompteur(unsigned long cpt);
    unsigned long getCompteur() const;
    void increment();
    String toString() const;

};




#endif //UNTITLED2_COMPTEUR_H
