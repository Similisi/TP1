#include "Biblio.h"
#include <cstdlib>
int main(){
    Biblio b;
    while(true){
        int choix,choixaff = 0;
        std::string choixsubaff = "";
        std::cout << "Gestionnaire de Biblio" << std::endl;
        std::cout << "Ajout utilisateur (1), Ajout livre (2), Ajout Emprunt (3),Enlever Emprunt (4), Afficher data (5)"<< std::endl;
        std::cin >> choix;
        std::string ISBN,id,nom,prenom,titre,auteur,genre,langue,datestr = "";
        Lecteur lecteur;
        Emprunt emprunt;
        Livre livre;
        Date date;
        switch (choix)
        {
        case 1:
            std::system("clear");
            std::cout << "un id ?"<< std::endl;
            std::cin >> id;
            std::cout << "un nom ?"<< std::endl;
            std::cin >> nom;
            std::cout << "un prenom ?"<< std::endl;
            std::cin >> prenom;
            lecteur = Lecteur(id,nom,prenom);
            lecteur.AffichageData();
            b.AjoutLecteur(lecteur);
            std::cout << "Ajout du lecteur" << std::endl;
            std::cout << std::endl;
            break;
        case 2:
            std::system("clear");
            std::cout << "un titre ?"<< std::endl;
            std::cin >> titre;
            std::cout << "un auteur ?"<< std::endl;
            std::cin >> auteur;
            std::cout << "un genre ?"<< std::endl;
            std::cin >> genre;
            std::cout << "une langue ?"<< std::endl;
            std::cin >> langue;

            std::cout << "une date ?"<< std::endl;
            std::cin >> datestr;
            date = Date(datestr);
            livre = Livre(titre,auteur,langue,genre,date);
            livre.affichageData();
            std::cout << "Ajout du livre" << std::endl;
            b.AjoutLivre(livre);
            std::cout << std::endl;
            break;
        case 3:
            std::system("clear");
            std::cout << "ISBN du livre ?"<< std::endl;
            std::cin >> ISBN;
            std::cout << "id du Lecteur ?"<< std::endl;
            std::cin >> id;
            std::cout << "date du jour ?"<< std::endl;
            std::cin >> datestr;
            b.EnleverDisponibilite(ISBN);
            date = Date(datestr);
            emprunt = Emprunt(date,ISBN,id);
            emprunt.AffichageData();
            b.AjoutEmprunt(emprunt);
            std::cout << std::endl;
            break;
        case 4:
            std::system("clear");
            b.AffichageListeEmprunt();
            std::cout << "ISBN du livre ?"<< std::endl;
            std::cin >> ISBN;
            std::cout << "date du jour ?"<< std::endl;
            std::cin >> datestr;
            b.RemiseDeDisponibilite(ISBN,datestr);
            b.AffichageListeEmprunt();
            std::cout << std::endl;
            break;
        case 5:
            std::system("clear");
            std::cout << "livre(1) ? lecteur(2) ?"<< std::endl;
            std::cin >> choixaff;
            switch (choixaff)
            {
            case 1:
                b.affichageListeLivre();
                std::cout << "ISBN du livre qui vous interresse : " << std::endl;
                std::cin >> choixsubaff;
                livre = b.findLivre(choixsubaff);
                livre.affichageData();
                break;
            case 2:
                break;
            default:
                std::cout << "valeur fausse" << std::endl;
                break;
            }
            break;
        default:
            std::cout << "valeur fausse"<< std::endl;
            break;
        }
        //Date d("1/01/1943");
        //Livre l("le petit prince","Antoine de Saint-Exupéry","Fr","Aventure Fantasy",d);
        //Lecteur lec("JF","Fouchard","Johann");
        //l.affichageData();
        //lec.AffichageData();
    }
}