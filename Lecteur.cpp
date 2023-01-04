#include "Lecteur.h"
Lecteur::Lecteur(){}
Lecteur::Lecteur(std::string id,std::string nom, std::string prenom):_id(id),_nom(nom),_prenom(prenom){}
void Lecteur::AffichageData(){
    std::cout << "id : " << _id << std::endl;
    std::cout << "nom : " << _nom << std::endl;
    std::cout << "prenom : " << _prenom << std::endl;
}