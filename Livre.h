#include<vector>
#include "Emprunt.h"
#include <stdlib.h>
#include <time.h>
class Livre
{
private:
    std::string _titre;
    std::string _auteur;
    std::string _langue;
    std::string _genre;
    bool _estDispo;
    Date _datepub;
    int _ISBN;
    std::vector<int> _listeEmprunt;
    /* data */
public:
    void affichageData();
    Livre();
    Livre(std::string titre, std::string auteur,std::string langue, std::string genre,Date d);
    void pasDispo();
    void Dispo();
    int getISBN();
    std::string getAuteur();
    std::string getTitre();
};