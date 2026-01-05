#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_SOMMETS 100

typedef struct {
    int matrice[MAX_SOMMETS][MAX_SOMMETS];
    int nb_sommets;
} Graphe;

void initGraphe(Graphe* g, int nb_sommets);
void ajouterArete(Graphe* g, int src, int dest, int poids);
void afficherGraphe(const Graphe* g);

#endif // GRAPHE_H