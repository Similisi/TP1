#ifndef AUTEUR_H
#define AUTEUR_H
#include "Date.h"
class Auteur
{
    private:
        std::string _id;
        std::string _nom;
        std::string _prenom;
        Date _date_naissance;

    public:
        Auteur();
        Auteur(std::string idauteur, std::string nomauteur,std::string prenomauteur,Date date);
        std::string toString();
        std::string operator<< (const Auteur& auteur) const; 
};
#endif

