#ifndef __FENETREPRINCIPALE__
#define __FENETREPRINCIPALE__

// on inclut les trucs de base de Qt dont on va avoir besoin
#include <QMainWindow>
#include <QPushButton>

// on inclut notre back-end coz on en aura besoin plus tard pour lier l'interface aux calculs
#include "reseau.hpp"

// ca c'est notre fenetre principale, elle herite de QMainWindow
class FenetrePrincipale : public QMainWindow {
    // so here we put the magic word pour que la fenetre puisse comprendre les clics de souris
    Q_OBJECT
    public:
        // le constructeur, il prend un parent nul par defaut coz c'est la fenetre de base
        FenetrePrincipale(QWidget *parent = nullptr);
        // le destructeur
        ~FenetrePrincipale();

    private:
        // pour l'instant on declare juste un petit bouton pour tester
        // c'est un pointeur coz Qt prefere gerer la memoire dynamiquement
        // ici ca vas nous permettre when we make a new de ne pas faire le delete le QWidget parent le fera on it's own
        // ce qui vas faire qu'il vas faire aussi les delete de ses enfants     
        QPushButton *boutonTest;
};

#endif