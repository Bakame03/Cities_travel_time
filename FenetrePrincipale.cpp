#include "FenetrePrincipale.hpp"

// le constructeur : c'est ici qu'on build notre fenetre quand l'appli se lance
FenetrePrincipale::FenetrePrincipale(std::vector<Ville> villes, std::vector<std::vector<int>> matrice, QWidget *parent) 
    : QMainWindow(parent), listeVilles(villes), matriceTemps(matrice) {
    
    // pour donner le titre a la fenetre
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

    // pour remplir les combobox avec les noms des villes
    for (size_t i = 0; i < listeVilles.size(); i++) {
        // on utilise QString::fromStdString pour traduire du C++ classique vers Qt
        comboDepart->addItem(QString::fromStdString(listeVilles[i].nom));
        comboArrivee->addItem(QString::fromStdString(listeVilles[i].nom));
    }

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