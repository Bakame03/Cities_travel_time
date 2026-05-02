#include <iostream>
#include <vector>

// ici c'est pour le moteur global de Qt
#include <QApplication>

#include "reseau.hpp"
#include "FenetrePrincipale.hpp"

int main(int argc, char *argv[]) {
    // ici on initialise l'appli Qt pour que ca s'affiche et que ca reste ouvert pour qu'on puisse interagir avec elle
    QApplication app(argc, argv);

    // on garde le moteur pour etre ready
    std::cout << "--- DEMARRAGE DU MOTEUR ---" << std::endl;
    std::vector<Ville> mesVilles = lireVilles("villes.csv");
    if (!mesVilles.empty()) {
        std::vector<std::vector<int>> matriceTemps = lireTemps("temps.csv", mesVilles.size());
        appliquerFloydWarshall(matriceTemps);
        std::cout << "Moteur initialise ! Les donnees sont pretes en arriere-plan.\n" << std::endl;
    }
    // ----------------------------------------------

    // ici on cree la fenetre principale qui vas etre parent des autres QWidgets
    FenetrePrincipale fenetre;

    // par defaut une fenetre est invisible, so on demande de l'afficher
    fenetre.show();
                
    // ici la boucle infinie : ca bloque le programme ici et ca ecoute les clics de l'user.
    // quand on ferme la fenetre, ca return 0 et ca termine le programme
    return app.exec();
}