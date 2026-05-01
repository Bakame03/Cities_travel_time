#include <iostream>
#include <vector>
#include "reseau.hpp"

int main() {
    // ------------------------------------------------------------------------------------------------------
    // --- TEST DE LA PARTIE 1 : LECTURE DU FICHIER VILLES.CSV ---

    std::vector<Ville> mesVilles = lireVilles("villes.csv");

    // pour verifier si le vecteur est vide
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

    // ------------------------------------------------------------------------------------------------------
    // --- TEST DE LA PARTIE 2 : LECTURE DU FICHIER TEMPS.CSV ---

    // ici on passe le nombre de villes qu'on a trouvé (mesVilles.size()) 
    // pour avoir une matrice 2D de meme dimension que le nombre total de ville
    std::vector<std::vector<int>> matriceTemps = lireTemps("temps.csv", mesVilles.size());

    // Et pour tester si la matrice est bonne, on prend juste deux villes au hasard 
    // Et on affiche le temps entre les deux
    std::cout << "\n--- Test Matrice ---" << std::endl;
    std::cout << "Temps entre ID 5 et ID 62 : " << matriceTemps[5][62] << " minutes." << std::endl;
    
    // Et un test pour une ville sans route directe vers une autre (par exemple 0 et 1)
    if (matriceTemps[0][1] == INFINI) {
        std::cout << "Temps entre ID 0 et ID 1 : Pas de route directe (INFINI)" << std::endl;
    } else {
        std::cout << "Temps entre ID 0 et ID 1 : " << matriceTemps[0][1] << " minutes." << std::endl;
    }
    

    return 0; 
}