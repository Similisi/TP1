#include "Lecteur.h"
Lecteur::Lecteur(){}
Lecteur::Lecteur(std::string id,std::string nom, std::string prenom):_id(id),_nom(nom),_prenom(prenom){}
//méthode pour afficher les info du lecteur
void Lecteur::AffichageData(){
    std::cout << "id : " << _id << std::endl;
    std::cout << "nom : " << _nom << std::endl;
    std::cout << "prenom : " << _prenom << std::endl;
}
//surcharge de l'operateur <<
std::string Lecteur::operator<< (const Lecteur& lecteur) const { 
    std::string resultat;
    resultat = "Lecteur :\n";
    resultat += "id : " + lecteur._id + "\n";
    resultat += "nom : " + lecteur._nom + "\n";
    resultat +="prenom : " + lecteur._prenom + "\n";
    return resultat;
}
//retourne l'id du lecteur
std::string Lecteur::getId(){
    return _id;
}
//retourne le nom du lecteur
std::string Lecteur::getNom(){
    return _nom;
}
//retourne le prenom du lecteur
std::string Lecteur::getPrenom(){
    return _prenom;
}
//retourne la liste des ISBN emprunté du lecteur
std::vector<int> Lecteur::getListISBN(){
    return _listeISBN;
}
//ajouter un emprunt a la liste des lecteur
void Lecteur::addEmprunt(int ISBN){
    _listeISBN.push_back(ISBN);
}