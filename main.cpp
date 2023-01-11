#include "Biblio.h"
#include "Emprunt.h"
#include <cstdlib>
int main(){
    Biblio b;
    Date d;
    Auteur a1,a2,a3;
    Livre l1,l2,l3,l4,l5,l6,l7,l8,l9,l10;
    Lecteur lec1,lec2,lec3;
    d = Date("31/07/1965");
    a1 = Auteur("1","Rowling","JK",d);
    d = Date("29/06/1900");
    a2 = Auteur("2","de Saint-Exupery","Antoine",d);
    d = Date("15/01/1622");
    a3 = Auteur("3","Poquelin","Jean-Baptiste",d);
    b.AjoutAuteur(a1);
    b.AjoutAuteur(a2);
    b.AjoutAuteur(a3);
    l1 = Livre("1","Harry Potter a l’ecole des sorciers", a1,"FR","Fantastique",d);
    l2 = Livre("2","Harry Potter et la Chambre des secrets", a1,"FR","Fantastique",d);
    l3 = Livre("3","Harry Potter et le Prisonnier d’Azkaban", a1,"FR","Fantastique",d);
    l4 = Livre("4","Harry Potter et la Coupe de feu", a1,"FR","Fantastique",d);
    l5 = Livre("5","Harry Potter et l’Ordre du phenix", a1,"FR","Fantastique",d);
    l6 = Livre("6","Harry Potter et le Prince de sang-mele", a1,"FR","Fantastique",d);
    l7 = Livre("7","Harry Potter et les Reliques de la Mort", a1,"FR","Fantastique",d);
    l8 = Livre("8","Harry Potter et l'Enfant maudit", a1,"FR","Fantastique",d);
    l9 = Livre("9","Le petit prince", a2,"FR","Aventure",d);
    l10 = Livre("10","Les misserables", a3,"FR","Fantastique",d);
    b.AjoutLivre(l1);
    b.AjoutLivre(l2);
    b.AjoutLivre(l3);
    b.AjoutLivre(l4);
    b.AjoutLivre(l5);
    b.AjoutLivre(l6);
    b.AjoutLivre(l7);
    b.AjoutLivre(l8);
    b.AjoutLivre(l9);
    b.AjoutLivre(l10);
    lec1 = Lecteur("1","Pichon","Paul");
    lec2 = Lecteur("2","Brun","Guillaume");
    lec3 = Lecteur("3","Parigot","Tom");
    b.AjoutLecteur(lec1);
    b.AjoutLecteur(lec2);
    b.AjoutLecteur(lec3);
    std::string visu = lec1<<lec1 ;
    std::cout << visu << std::endl;
    visu = l2<<l2 ;
    std::cout << visu << std::endl;
    visu = a3<<a3 ;
    std::cout << visu << std::endl;
    Emprunt emprunt(d,l2.getISBN(),lec1.getId());
    Emprunt emprunt2(d,l2.getISBN(),lec2.getId());
    b.AjoutEmprunt(emprunt);
    visu = b.getListLivre()[1]<<b.getListLivre()[1] ;
    std::cout << visu << std::endl;
    b.AjoutEmprunt(emprunt2);
    std::cout << "remise disponibilité"<<std::endl;
    b.RemiseDeDisponibilite(l2.getISBN(),d.affichageDate());
    visu = b.getListLivre()[1]<<b.getListLivre()[1] ;
    std::cout << visu << std::endl;
     std::cout << "Afficher livre auteur" << std::endl;
    b.LivresAuteur(a1);
    std::cout << "Pourcentage avec 2 livre sur 10 emprunté" << std::endl;
    emprunt = Emprunt(d,l1.getISBN(),lec2.getId());
    emprunt2 = Emprunt(d,l2.getISBN(),lec2.getId());
    b.AjoutEmprunt(emprunt);
    b.AjoutEmprunt(emprunt2);
    b.CalculLivreEmprunte();
    while(true){
    }
}