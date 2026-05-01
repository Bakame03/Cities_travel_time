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

// -------------------------------------------------------------------------------------------------------
// ca c'est pour la constante pour représenter l'infini donc when pas de route directe
const int INFINI = 999999;

// ca c'est pour juste lire le fichier temps.csv et retourner une matrice 2D
// la tailleMax va etre le nombre total de ville
std::vector<std::vector<int>> lireTemps(const std::string& nomFichier, size_t tailleMax);

// -------------------------------------------------------------------------------------------------------
// now on applique l'algorithme de Floyd-Warshall pour trouver les plus courts chemins
// ici on passe la matrice par référence car on ne veut pas le recopier il est lourd, et on met pas le const car on veut le modifier
void appliquerFloydWarshall(std::vector<std::vector<int>>& matrice);

#endif