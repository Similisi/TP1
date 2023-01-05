#include "Biblio.h"

Biblio::Biblio(){}
void Biblio::AjoutLivre(Livre livre){
    _listeLivre.push_back(livre);
}
void Biblio::AjoutLecteur(Lecteur lecteur){
    _listeLecteur.push_back(lecteur);
}
void Biblio::AjoutEmprunt(Emprunt emprunt){
    _listeEmprunt.push_back(emprunt);
}

Livre Biblio::findLivre(std::string ISBN){
    Livre livre;
    int taille = _listeLivre.size();
    for(int index = 0; index < taille;index ++){
        if(std::to_string(_listeLivre.at(index).getISBN()) == ISBN){
            livre = _listeLivre.at(index);
        }
    }
    return livre;
}

void Biblio::affichageListeLivre(){
    for(Livre livre : _listeLivre){
        std::cout << livre.getISBN() << " : " << livre.getTitre() << std::endl;
    }
}

void Biblio::EnleverDisponibilite(std::string ISBN){
        int taille = _listeLivre.size();
    for(int index = 0; index < taille;index ++){
        if(std::to_string(_listeLivre.at(index).getISBN()) == ISBN){
            _listeLivre.at(index).pasDispo();
        }
    }
}