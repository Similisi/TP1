#ifndef LIVRE_H
#define LIVRE_H
#include<vector>
#include "Auteur.h"
#include <stdlib.h>
class Livre
{
private:
    std::string _ISBN;
    std::string _titre;
    Auteur _auteur;
    std::string _langue;
    std::string _genre;
    bool _estDispo;
    Date _datepub;
    std::vector<int> _listeEmprunt;
    /* data */
public:
    void affichageData();
    Livre();
    Livre(std::string isbn,std::string titre, Auteur auteur,std::string langue, std::string genre,Date d);
    void pasDispo();
    void Dispo();
    bool getDispo();
    std::string getISBN();
    Auteur getAuteur();
    std::string getTitre();
    std::string operator<< (const Livre& livre) const; 
};
#endif