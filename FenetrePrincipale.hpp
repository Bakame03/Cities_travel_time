#ifndef __FENETREPRINCIPALE__
#define __FENETREPRINCIPALE__

// ici on inclut les trucs de base de Qt dont on va avoir besoin
#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

// on inclut notre back-end pour lier l'interface aux calculs
#include "reseau.hpp"

// ca c'est notre fenetre principale, elle herite de QMainWindow
class FenetrePrincipale : public QMainWindow {
    // so here we put the magic word pour que la fenetre puisse comprendre les clics de souris
    Q_OBJECT

    public:
        // le constructeur, il prend un parent nul par defaut coz c'est la fenetre de base
        // et prends aussi les villes et la matrice de temps
        FenetrePrincipale(std::vector<Ville> villes, std::vector<std::vector<int>> matrice, QWidget *parent = nullptr);

        // le destructeur
        ~FenetrePrincipale();

    private:
        QComboBox *comboDepart;
        QComboBox *comboArrivee;
        QPushButton *boutonCalculer;
        QLabel *labelResultat;
        
        // Le layout qui va ranger tout ca de haut en bas
        QVBoxLayout *layoutPrincipal;
        
        // Le widget central qui va servir de conteneur global pour le layout
        QWidget *widgetCentral;

        // ici c'est la ou on vas stocker les villes et la matrice de temps pour pouvoir les utiliser quand on veux        
        std::vector<Ville> listeVilles;
        std::vector<std::vector<int>> matriceTemps;         

    // ici on defini la section des fonctions qui vont ecouter l'interface
    private slots:
        // ici on declare le slot qui va etre appeler quand on clique sur le bouton "Calculer le trajet"
        void calculerTrajet();
};

#endif