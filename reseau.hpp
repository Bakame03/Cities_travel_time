#ifndef __RESEAU__
#define __RESEAU__

#include <string>
#include <vector>

// juste une structure de base pour le stockage d'une ville
struct Ville {
    std::string nom;
    size_t id;  
};

// cette fonction lis le fichier villes.csv
// ca prend juste le nom du fichier en parametre et retourne un tableau de type structure ville
std::vector<Ville> lireVilles(const std::string& nomFichier);

#endif