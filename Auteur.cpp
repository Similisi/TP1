#include "Auteur.h"
Auteur::Auteur(std::string idauteur, std::string nomauteur,std::string prenomauteur,Date date) : _id(idauteur),_nom(nomauteur),_prenom(prenomauteur),_date_naissance(date){
}
Auteur::Auteur(){}

//Méthode permettant de retourner sous forme de string le nom et le prénom de l'auteur
std::string Auteur::toString(){
    return _nom +" "+  _prenom;
}
//surcharge de l'operateur <<
std::string Auteur::operator<< (const Auteur& auteur) const { 
    std::string resultat;
    resultat = "Auteur :\n";
    resultat += "id : " + auteur._id + "\n";
    resultat += "nom : " + auteur._nom + "\n";
    resultat +="prenom : " + auteur._prenom + "\n";
    return resultat;
}