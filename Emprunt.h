#ifndef EMPRUNT_H
#define EMPRUNT_H
#include <string>
#include "Date.h"
class Emprunt{
    public:
        Emprunt();
        Emprunt(Date dateEmpr,std::string ISBN,std::string idLec);
        void FinEmprunt(Date dateFin);
        int getISBN();
        std::string getIDLecteur();
        Date getdateEmprunt();
        Date getdateFinEmprunt();
        void AffichageData();
    private:
        Date _dateEmprunt;
        Date _dateFinEmprunt;
        int _ISBN;
        std::string _idLect;
};
#endif