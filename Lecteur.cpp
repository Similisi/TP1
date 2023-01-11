#include "Lecteur.h"
Lecteur::Lecteur(){}
Lecteur::Lecteur(std::string id,std::string nom, std::string prenom):_id(id),_nom(nom),_prenom(prenom){}
void Lecteur::AffichageData(){
    std::cout << "id : " << _id << std::endl;
    std::cout << "nom : " << _nom << std::endl;
    std::cout << "prenom : " << _prenom << std::endl;
}

std::string Lecteur::operator<< (const Lecteur& lecteur) const { 
    std::string resultat;
    resultat = "Lecteur :\n";
    resultat += "id : " + lecteur._id + "\n";
    resultat += "nom : " + lecteur._nom + "\n";
    resultat +="prenom : " + lecteur._prenom + "\n";
    return resultat;
}

std::string Lecteur::getId(){
    return _id;
}
std::string Lecteur::getNom(){
    return _nom;
}
std::string Lecteur::getPrenom(){
    return _prenom;
}