#include "FenetrePrincipale.hpp"

// so that we can be able to use sort function
#include <algorithm> 

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

    // Le tri des villes
    // il faut trier la liste de villes par ordre alphabetique
    // ici j'utilise une fonction "lambda" pour dire a std::sort 
    // qu'il doit comparer le champ 'nom' de chaque structure Ville.
    std::sort(listeVilles.begin(), listeVilles.end(), [](const Ville& a, const Ville& b) {
        return a.nom < b.nom;
    });

    // pour remplir les combobox avec les noms des villes
    for (size_t i = 0; i < listeVilles.size(); i++) {
        // on utilise QString::fromStdString pour traduire du C++ classique vers Qt
        comboDepart->addItem(QString::fromStdString(listeVilles[i].nom));
        comboArrivee->addItem(QString::fromStdString(listeVilles[i].nom));
    }
    
    // on rend les listes "editables" (on peut taper dedans pour filtrer visuellement)
    comboDepart->setEditable(true);
    comboArrivee->setEditable(true);

    // on bloque l'insertion pour empecher le user d'ajouter des villes car c'est pas lui l'admin
    comboDepart->setInsertPolicy(QComboBox::NoInsert);
    comboArrivee->setInsertPolicy(QComboBox::NoInsert);

    // pour brancher le signal (clic) au slot  
    // Ca se lit : "Connecte le boutonCalculer, sur son action 'clicked', a cette fenetre ('this'), en lancant 'calculerTrajet'"
    connect(boutonCalculer, &QPushButton::clicked, this, &FenetrePrincipale::calculerTrajet);

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

// ici on execute le code quand on clique sur le bouton 
void FenetrePrincipale::calculerTrajet() {
    
    // on lit ce qu'il y a d'ecrit dans les deux QComboBox
    // on traduit le texte Qt en std::string classique de C++
    std::string nomDepart = comboDepart->currentText().toStdString();
    std::string nomArrivee = comboArrivee->currentText().toStdString();

    // on demande au back-end (reseau.cpp) de nous trouver les IDs correspondants
    size_t idDepart = trouverIdVille(nomDepart, listeVilles);
    size_t idArrivee = trouverIdVille(nomArrivee, listeVilles);

    // now maintenant we can chercher le temps de trajet dans notre matrice de Floyd-Warshall
    int temps = matriceTemps[idDepart][idArrivee];

    // on met a jour l'affichage en bas de la fenetre
    if (temps == INFINI) {
        labelResultat->setText("Il n'y a pas de trajet possible entre ces deux villes.");
    } else if (temps == 0) {
        labelResultat->setText("Vous etes deja a destination !");
    } else {
        // QString::number() convertit un int en texte Qt
        QString message = "Le trajet le plus rapide prend : " + QString::number(temps) + " minutes.";
        labelResultat->setText(message);
    }
}