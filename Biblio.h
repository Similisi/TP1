#include "Livre.h"
#include "Lecteur.h"
class Biblio
{
private:
    std::vector<Livre> _listeLivre;
    std::vector<Lecteur> _listeLecteur;
    std::vector<Emprunt> _listeEmprunt;
public:
    void AjoutLivre(Livre livre);
    void AjoutLecteur(Lecteur lecteur);
    void AjoutEmprunt(Emprunt emprunt);
    void EnleverDisponibilite(std::string ISBN);
    Livre findLivre(std::string ISBN);
    void affichageListeLivre();
    Biblio();
};