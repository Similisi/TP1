#include"Livre.h"
Livre::Livre(){}
Livre::Livre(std::string titre, std::string auteur,std::string langue, std::string genre,Date d):_titre(titre),_auteur(auteur),_langue(langue),_genre(genre),_estDispo(true),_datepub(d)
{
    srand(time(NULL));
    _ISBN = rand()% 100000000;
}
void Livre::affichageData(){
    std::cout << "ISBN : " << _ISBN <<std::endl;
    std::cout << "titre : " << _titre <<std::endl;
    std::cout << "auteur : " << _auteur <<std::endl;
    std::cout << "langue : " << _langue <<std::endl;
    std::cout << "date : " << _datepub.affichageDate() <<std::endl;
    if(_estDispo){
        std::cout << "Ce livre est dispo" <<std::endl;
    }else{
        std::cout << "Ce livre n'est pas dispo" <<std::endl;
    }
}

void Livre::pasDispo(){
    _estDispo = false;
}
void Livre::Dispo(){
    _estDispo = true;
}


std::string Livre::getTitre(){
    return _titre;
}


int Livre::getISBN(){
    return _ISBN;
}