#ifndef BIBLIO_H
#define BIBLIO_H
#include "Livre.h"
#include "Lecteur.h"
#include "Emprunt.h"
#include <algorithm> 
class Biblio
{
private:
    std::vector<Livre> _listeLivre;
    std::vector<Lecteur> _listeLecteur;
    std::vector<Emprunt> _listeEmprunt;
    std::vector<Auteur> _listeAuteur;
public:
    std::vector<Lecteur> getListLecteur();
    void AjoutLivre(Livre livre);
    void AjoutLecteur(Lecteur lecteur);
    void AjoutEmprunt(Emprunt emprunt,Lecteur &lecteur);
    void AjoutAuteur(Auteur auteur);
    void EnleverDisponibilite(std::string ISBN);
    void RemiseDeDisponibilite(std::string ISBN,std::string datestr);
    Livre findLivre(std::string ISBN);
    void AjoutDateFinEmprunt(std::string ISBN,std::string date);
    void affichageListeLivre();
    void AffichageListeEmprunt();
    bool verifDispo(std::string ISBN);
    std::vector<Livre> getListLivre();
    void LivresAuteur(Auteur auteur);
    void CalculLivreEmprunte();
    void RechercheLivreEmpruntes(Lecteur lect);
    void ClassementLecteur();
    Biblio();
};
#endif