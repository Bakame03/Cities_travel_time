#include "FenetrePrincipale.hpp"

// le constructeur : c'est ici qu'on build notre fenetre quand l'appli se lance
FenetrePrincipale::FenetrePrincipale(QWidget *parent) : QMainWindow(parent) {
    
    // pour donner le titre a la fenetre
    // pour donner le titre de la fenetre
    setWindowTitle("Calculateur de Temps de Trajet");
    
    // pour donner aussi la taille de depart (largeur, hauteur)
    resize(600, 400);

    // pour la creation du widget central
    widgetCentral = new QWidget(this);

    // creation des widgets necessaire pour l'interface
    comboDepart = new QComboBox(widgetCentral);
    comboArrivee = new QComboBox(widgetCentral);
    boutonCalculer = new QPushButton("Calculer le trajet", widgetCentral);
    labelResultat = new QLabel("Le resultat s'affichera ici...", widgetCentral);

    // (juste pour tester l'affichage, on met des fausses villes pour l'instant)
    comboDepart->addItem("Paris");
    comboDepart->addItem("Lyon");
    comboArrivee->addItem("Marseille");
    comboArrivee->addItem("Bordeaux");

    // pour la creation du layout (rangeur de boites vertical)
    layoutPrincipal = new QVBoxLayout();

    // ici on fait le rangement des widgets en ajoutant des labels explicatifs
    layoutPrincipal->addWidget(new QLabel("Ville de depart :", widgetCentral));
    layoutPrincipal->addWidget(comboDepart);
    
    layoutPrincipal->addWidget(new QLabel("Ville d'arrivee :", widgetCentral));
    layoutPrincipal->addWidget(comboArrivee);
    
    layoutPrincipal->addWidget(boutonCalculer);
    layoutPrincipal->addWidget(labelResultat);

    // on ajoute du coup le layout au widget central
    widgetCentral->setLayout(layoutPrincipal);

    // on dit a la fenetre que sa partie principale, c'est ce widget central
    setCentralWidget(widgetCentral);
}

// le destructeur : on a rien a ecrire here coz the parent (QMainWindow) 
// s'occupe de tuer ses enfants (les QWidgets) all by itself comme un grand car on a utiliser * sur eux
FenetrePrincipale::~FenetrePrincipale() {
}