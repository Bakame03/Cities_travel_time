#include <iostream>
#include <vector>
#include "reseau.hpp"

int main() {
    std::vector<Ville> mesVilles = lireVilles("villes.csv");

    // pour verifier si le vecteur est vid
    if (mesVilles.empty()) {
        std::cout << "La liste de villes est vide. Le programme va s'arrêter." << std::endl;
        return 1; // On quitte le programme avec un code d'erreur (1)
    }

    // juste pour afficher le nombre total de villes lu
    std::cout << "Nombre total de villes : " << mesVilles.size() << std::endl;

    // juste pour afficher les 5 premier ville pour verifier que les donnes sont bonnes
    std::cout << "--- Affichage des 5 premieres villes ---" << std::endl;
    
    for (size_t i = 0; i < 5; i++) {
        std::cout << "Ville ID : " << mesVilles[i].id << " --- Nom : " << mesVilles[i].nom << std::endl;
    }

    return 0; 
}