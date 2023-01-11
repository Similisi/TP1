#ifndef LECTEUR_H
#define LECTEUR_H
#include <vector>
#include <string>
#include <iostream>
class Lecteur{
    public:
        Lecteur();
        Lecteur(std::string id,std::string nom, std::string prenom);
        void AffichageData();
        std::string getId();
        std::string getNom();
        std::string getPrenom();
        std::string operator<< (const Lecteur& lecteur) const; 
    private:
        std::string _id;
        std::string _nom;
        std::string _prenom;
        std::vector<int> _listeISBN;

};
#endif