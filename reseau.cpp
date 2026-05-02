#include "reseau.hpp"
#include <iostream>
#include <fstream>
#include <algorithm> 

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

std::vector<std::vector<int>> lireTemps(const std::string& nomFichier, size_t tailleMax) {
    // ici on cree la matrice 2D 
    // et cette syntaxe veut dire, cree moi tailleMax lignes, et pour chaque ligne, cree 
    // un tableau(vecteur) de taille tailleMax et le remplir avec des INFINI.
    std::vector<std::vector<int>> matrice(tailleMax, std::vector<int>(tailleMax, INFINI));

    // ici on met 0 pour les cases sur la diagonale 
    // vu que le temps de trajet d'une ville à elle meme est 0
    for (size_t i = 0; i < tailleMax; i++) {
        matrice[i][i] = 0;
    }

    // now on lit le fichier temps.csv pour remplir la matrice
    std::ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << nomFichier << std::endl;
        return matrice; 
    }

    size_t id1, id2;
    int temps;
    char virgule;

    while (fichier >> id1 >> virgule >> id2 >> virgule >> temps) {
        
        // ici on vérifie juste que les ID ne dépassent pas la taille de notre matrice
        if (id1 < tailleMax && id2 < tailleMax) {
            // et comme le graphe n'est pas orienter la route peut se prendre dans les deux sens
            matrice[id1][id2] = temps;
            matrice[id2][id1] = temps;
        }
    }

    fichier.close();
    return matrice;
}

void appliquerFloydWarshall(std::vector<std::vector<int>>& W) {
    size_t n = W.size();

    for (size_t k = 0; k < n; k++) {
        for (size_t u = 0; u < n; u++) {
            for (size_t v = 0; v < n; v++) {
                W[u][v] = std::min(W[u][v], W[u][k] + W[k][v]);
            }
        }
    }
}

size_t trouverIdVille(const std::string& nomCible, const std::vector<Ville>& listeVilles) {
    // On parcourt tout le tableau des villes
    for (size_t i = 0; i < listeVilles.size(); i++) {
        // Si le nom correspond à ce qu'on cherche
        if (listeVilles[i].nom == nomCible) {
            return listeVilles[i].id; // On retourne son ID et on quitte la fonction
        }
    }
    // Si la boucle se termine sans avoir fait de 'return', c'est que la ville n'existe pas
    return -1; 
}