#include "Emprunt.h"
Emprunt::Emprunt(){}
Emprunt::Emprunt(Date dateEmpr,std::string ISBN,std::string idLec):_dateEmprunt(dateEmpr),_idLect(idLec){
    _ISBN = std::stoi(ISBN,nullptr);
}
void Emprunt::FinEmprunt(Date dateFin){
    _dateFinEmprunt = dateFin;
}
//méthode pour afficher les info de l'emprunt
void Emprunt::AffichageData(){
    std::cout << _dateEmprunt.affichageDate() << std::endl;
    std::cout << _dateFinEmprunt.affichageDate() << std::endl;
    std::cout << _ISBN << std::endl;
    std::cout << _idLect << std::endl;
}
//retourne l'isbn
int Emprunt::getISBN(){
    return _ISBN;
}
//retourne l'id du lecteur
std::string Emprunt::getIDLecteur(){
    return _idLect;
}

//retourne la date d'emprunt
Date Emprunt::getdateEmprunt(){
    return _dateEmprunt;
}

//retourne la date de fin d'emprunt
Date Emprunt::getdateFinEmprunt(){
    return _dateFinEmprunt;
}
