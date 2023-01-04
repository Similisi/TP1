#include <vector>
#include <string>
#include <iostream>
class Lecteur{
    public:
        Lecteur();
        Lecteur(std::string id,std::string nom, std::string prenom);
        void AffichageData();
    private:
        std::string _id;
        std::string _nom;
        std::string _prenom;
        std::vector<int> _listeISBN;

};