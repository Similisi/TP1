#include "Biblio.h"

Biblio::Biblio(){}
void Biblio::AjoutLivre(Livre livre){
    _listeLivre.push_back(livre);
}
void Biblio::AjoutLecteur(Lecteur lecteur){
    _listeLecteur.push_back(lecteur);
}
void Biblio::AjoutEmprunt(Emprunt emprunt){
    if(verifDispo(std::to_string(emprunt.getISBN()))){
        _listeEmprunt.push_back(emprunt);
        EnleverDisponibilite(std::to_string(emprunt.getISBN()));
        std::cout << "Emprunt effectué" << std::endl;
    }else{
        std::cout << "Livre non disponnible" << std::endl;
    }
}

bool Biblio::verifDispo(std::string ISBN){
    bool res;
    int taille = _listeLivre.size();
    for(int index = 0; index < taille;index ++){
        if(_listeLivre.at(index).getISBN() == ISBN){
            res = _listeLivre.at(index).getDispo();
        }
    }
    return res;

}

void Biblio::AjoutAuteur(Auteur auteur){
    _listeAuteur.push_back(auteur);
}



Livre Biblio::findLivre(std::string ISBN){
    Livre livre;
    int taille = _listeLivre.size();
    for(int index = 0; index < taille;index ++){
        if(_listeLivre.at(index).getISBN() == ISBN){
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

void Biblio::AffichageListeEmprunt(){
    for(Emprunt emprunt : _listeEmprunt){
        std::cout << emprunt.getISBN() << " : " << emprunt.getIDLecteur() << " date d'emprunt : " << emprunt.getdateEmprunt().affichageDate();
        if(emprunt.getdateFinEmprunt().affichageDate() != "1/1/0"){
            std::cout << " date fin d'emprunt : " << emprunt.getdateFinEmprunt().affichageDate()<< std::endl;
        }else{
            std::cout << std::endl;
        }
    }
}

void Biblio::EnleverDisponibilite(std::string ISBN){
    int taille = _listeLivre.size();
    for(int index = 0; index < taille;index ++){
        if(_listeLivre.at(index).getISBN() == ISBN){
            _listeLivre.at(index).pasDispo();
        }
    }
}

void Biblio::RemiseDeDisponibilite(std::string ISBN,std::string date){
    int taille = _listeLivre.size();
    for(int index = 0; index < taille;index ++){
        if(_listeLivre.at(index).getISBN() == ISBN){
            _listeLivre.at(index).Dispo();
        }
    }
    AjoutDateFinEmprunt(ISBN,date);
}

void Biblio::AjoutDateFinEmprunt(std::string ISBN,std::string date){
    for(Emprunt emprunt : _listeEmprunt){
        if(std::to_string(emprunt.getISBN()) == ISBN){
            Date d(date);
            emprunt.FinEmprunt(date);
        }
    }
}

std::vector<Livre> Biblio::getListLivre(){
    return _listeLivre;
}

void Biblio::LivresAuteur(Auteur auteur){
    int taille = _listeLivre.size();
    for(int index = 0; index < taille;index ++){
        if(_listeLivre.at(index).getAuteur().toString() == auteur.toString()){
            std::cout << _listeLivre.at(index).getTitre() << std::endl;
        }
    }
}