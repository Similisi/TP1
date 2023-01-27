#include"Livre.h"
Livre::Livre(){}
Livre::Livre(std::string isbn,std::string titre, Auteur auteur,std::string langue, std::string genre,Date d):_ISBN(isbn),_titre(titre),_auteur(auteur),_langue(langue),_genre(genre),_estDispo(true),_datepub(d)
{}
//méthode pour afficher les info du Livre
void Livre::affichageData(){
    std::cout << "ISBN : " << _ISBN <<std::endl;
    std::cout << "titre : " << _titre <<std::endl;
    std::cout << "auteur : " << _auteur.toString() <<std::endl;
    std::cout << "langue : " << _langue <<std::endl;
    std::cout << "date : " << _datepub.affichageDate() <<std::endl;
    if(_estDispo){
        std::cout << "Ce livre est dispo" <<std::endl;
    }else{
        std::cout << "Ce livre n'est pas dispo" <<std::endl;
    }
}
//méthode pour enlever la disponibilité
void Livre::pasDispo(){
    _estDispo = false;
}
//méthode pour ajouter la disponibilité d'un livre
void Livre::Dispo(){
    _estDispo = true;
}
//retourne la disponibilité
bool Livre::getDispo(){
    return _estDispo;
}

//retourne le titre
std::string Livre::getTitre(){
    return _titre;
}
//retourne l'auteur
Auteur Livre::getAuteur(){
    return _auteur;
}

//retourne l'isbn du livre
std::string Livre::getISBN(){
    return _ISBN;
}
//surcharge de l'operateur <<
std::string Livre::operator<< (const Livre& livre) const { 
    std::string resultat;
    
    resultat = "Livre :\n";
    resultat += "ISBN : " + livre._ISBN+ "\n";
    resultat += "nom : " + livre._titre + "\n";
    resultat += "nom : " + livre._genre + "\n";
    resultat += "nom : " + livre._langue + "\n";
    if(livre._estDispo){
        resultat +="Le livre est dispo \n";
    }else{
        resultat +="Le livre n'est pas dispo \n";
    }
    return resultat;
}