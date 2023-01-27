#include "Biblio.h"

Biblio::Biblio(){}

//retourne la liste de lecteur
std::vector<Lecteur> Biblio::getListLecteur(){
    return _listeLecteur;
}
//ajouter un livre a la liste de livre
void Biblio::AjoutLivre(Livre livre){
    _listeLivre.push_back(livre);
}
//ajouter un lecteur a la liste de lecteur
void Biblio::AjoutLecteur(Lecteur lecteur){
    _listeLecteur.push_back(lecteur);
}
//ajouter un emprunt a la liste d'emprunt en ajoutant aussi l'isbn du livre emprunté chez le lecteur
void Biblio::AjoutEmprunt(Emprunt emprunt,Lecteur &lecteur){
    if(verifDispo(std::to_string(emprunt.getISBN()))){
        _listeEmprunt.push_back(emprunt);
        EnleverDisponibilite(std::to_string(emprunt.getISBN()));
        for(long unsigned int index =0; index < _listeLecteur.size(); index ++){
            if(_listeLecteur.at(index).getId() == lecteur.getId()){
                _listeLecteur.at(index).addEmprunt(emprunt.getISBN());
            }
        }
        
        std::cout << "Emprunt effectué" << std::endl;
    }else{
        std::cout << "Livre non disponnible" << std::endl;
    }
}
//méthode de verification des disponibilité coté bibliothèque
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
//méthode d'ajout d'auteur
void Biblio::AjoutAuteur(Auteur auteur){
    _listeAuteur.push_back(auteur);
}


//méthode de recherche des livres
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
//methode pour afficher les livre 1 a 1
void Biblio::affichageListeLivre(){
    for(Livre livre : _listeLivre){
        std::cout << livre.getISBN() << " : " << livre.getTitre() << std::endl;
    }
}
//methode pour afficher les emprunt 1 a 1
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
//Méthode pour enlever une disponibilité d'un livre en fonction de l'isbn
void Biblio::EnleverDisponibilite(std::string ISBN){
    int taille = _listeLivre.size();
    for(int index = 0; index < taille;index ++){
        if(_listeLivre.at(index).getISBN() == ISBN){
            _listeLivre.at(index).pasDispo();
        }
    }
}
//Méthode pour remettre une disponibilité d'un livre en fonction de l'isbn et d'une date de remise 
void Biblio::RemiseDeDisponibilite(std::string ISBN,std::string date){
    int taille = _listeLivre.size();
    for(int index = 0; index < taille;index ++){
        if(_listeLivre.at(index).getISBN() == ISBN){
            _listeLivre.at(index).Dispo();
        }
    }
    AjoutDateFinEmprunt(ISBN,date);
}
//Méthode pour ajouter une date de fin d'emprunt
void Biblio::AjoutDateFinEmprunt(std::string ISBN,std::string date){
    for(Emprunt emprunt : _listeEmprunt){
        if(std::to_string(emprunt.getISBN()) == ISBN){
            Date d(date);
            emprunt.FinEmprunt(date);
        }
    }
}
//retourne la liste de livre
std::vector<Livre> Biblio::getListLivre(){
    return _listeLivre;
}
//méthode permettant de chercher tous les livres d'un auteur.
void Biblio::LivresAuteur(Auteur auteur){
    int taille = _listeLivre.size();
    for(int index = 0; index < taille;index ++){
        if(_listeLivre.at(index).getAuteur().toString() == auteur.toString()){
            std::cout << _listeLivre.at(index).getTitre() << std::endl;
        }
    }
}
//méthode permettant de chercher tous les livres empruntés et de calculer le pourcentage de livres empruntés
void Biblio::CalculLivreEmprunte(){
    int totalLivre = _listeLivre.size();
    int nblivreEmprunte = 0;
    std::string resultat = "";
    for(Livre livre : _listeLivre){
        if(!livre.getDispo()){
            resultat += livre.getTitre()+"\n";
            nblivreEmprunte++;
        }
    }
    std::cout << resultat << std::endl;
    std::cout << "il y a " << (nblivreEmprunte*100) / totalLivre << "% des livres emprunte."<< std::endl;
}
//méthode permettant de chercher tous les livres empruntés par un lecteur.
void Biblio::RechercheLivreEmpruntes(Lecteur lect){
    for(Emprunt emprunt : _listeEmprunt){
        if(lect.getId() == emprunt.getIDLecteur()){
            for(Livre livre : _listeLivre){
                if(livre.getISBN() == std::to_string(emprunt.getISBN())){
                    std::cout << livre.getTitre() << std::endl;
                }
            }
        }
    }
}
//méthode permettant d'établir le classement des lecteurs en fonction du nombre de livres empruntés
void Biblio::ClassementLecteur(){
    std::vector<std::pair<std::string, int>> resultat;
    //init du tableau resultat
    for(Lecteur lecteur: _listeLecteur){
        std::pair<std::string, int> lec(lecteur.getNom(),lecteur.getListISBN().size());
        resultat.push_back(lec);
    }
    std::sort(resultat.begin(), resultat.end(),[](std::pair<std::string, int> a, std::pair<std::string, int> b){
        return a.second > b.second;
    });
    for(std::pair<std::string, int> lecteur: resultat){
        std::cout<< lecteur.first << " " <<lecteur.second<<std::endl;
    }
}

