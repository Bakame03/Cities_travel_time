#include "FenetrePrincipale.hpp"

// le constructeur : c'est ici qu'on build notre fenetre quand l'appli se lance
FenetrePrincipale::FenetrePrincipale(QWidget *parent) : QMainWindow(parent) {
    
    // on donne un petit titre a notre fenetre
    setWindowTitle("Calculateur de Temps de Trajet");
    
    // on set la taille de depart (largeur, hauteur)
    resize(600, 400);

    // on cree notre bouton en memoire dynamique avec 'new'
    // le 'this' veut dire "ton parent c'est la fenetre". 
    // et comme dans le .hpp on a fait QPushButton * , la fenetre vas le delete automatically a la fin
    boutonTest = new QPushButton("Mon Premier Bouton !", this);

    // et dans un QMainWindow, on doit lui dire 
    // quel widget vas prendre toute la place au milieu de l'ecran
    setCentralWidget(boutonTest);
}

// le destructeur : on a rien a ecrire here coz the parent (QMainWindow) 
// s'occupe de tuer ses enfants (notre bouton) all by itself comme un grand car we used * on them
FenetrePrincipale::~FenetrePrincipale() {
}