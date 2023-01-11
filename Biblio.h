#ifndef BIBLIO_H
#define BIBLIO_H
#include "Livre.h"
#include "Lecteur.h"
#include "Emprunt.h"
class Biblio
{
private:
    std::vector<Livre> _listeLivre;
    std::vector<Lecteur> _listeLecteur;
    std::vector<Emprunt> _listeEmprunt;
    std::vector<Auteur> _listeAuteur;
public:
    void AjoutLivre(Livre livre);
    void AjoutLecteur(Lecteur lecteur);
    void AjoutEmprunt(Emprunt emprunt);
    void AjoutAuteur(Auteur auteur);
    void EnleverDisponibilite(std::string ISBN);
    void RemiseDeDisponibilite(std::string ISBN,std::string datestr);
    Livre findLivre(std::string ISBN);
    void AjoutDateFinEmprunt(std::string ISBN,std::string date);
    void affichageListeLivre();
    void AffichageListeEmprunt();
    bool verifDispo(std::string ISBN);
    std::vector<Livre> getListLivre();
    void LivresAuteur(std::string auteur);
    Biblio();
};
#endif