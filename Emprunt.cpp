#include "Emprunt.h"
Emprunt::Emprunt(){}
Emprunt::Emprunt(Date dateEmpr,std::string ISBN,std::string idLec):_dateEmprunt(dateEmpr),_idLect(idLec){
    _ISBN = std::stoi(ISBN,nullptr);
}
void Emprunt::FinEmprunt(Date dateFin){
    _dateFinEmprunt = dateFin;
}

void Emprunt::AffichageData(){
    std::cout << _dateEmprunt.affichageDate() << std::endl;
    std::cout << _dateFinEmprunt.affichageDate() << std::endl;
    std::cout << _ISBN << std::endl;
    std::cout << _idLect << std::endl;
}