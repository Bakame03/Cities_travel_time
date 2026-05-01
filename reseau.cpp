#include "reseau.hpp"
#include <iostream>
#include <fstream>

std::vector<Ville> lireVilles(const std::string& nomFichier) {
    std::vector<Ville> listeVilles;
    std::ifstream fichier(nomFichier);

    if (!fichier.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << nomFichier << std::endl;
        return listeVilles;
    }

    std::string poubelle;
    // il faut ignorer la première ligne qui contient l'entete du fichier villes.csv
    std::getline(fichier, poubelle);

    Ville v;
    // la on lit juste le nom de la ville jusqu'à la première virgule
    while (std::getline(fichier, v.nom, ',')) {
        
        // et la on lis le id de la ville est on s'arrete avant la virgule
        fichier >> v.id;

        // now Il faut ignorer cette virgule pour que le prochain
        // getline ne soit pas bloquer
        char virgule;
        fichier >> virgule;

        // now on ignore le reste de la ligne (jusqu'au '\n') vu qu'on veut juste le nom et l'id de la ville
        std::getline(fichier, poubelle); 

        // now on ajoute la ville à notre liste de villes
        listeVilles.push_back(v);
    }

    fichier.close();
    return listeVilles;
}