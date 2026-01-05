#include "common/graphe.h"
#include <stdio.h>   // Pour printf
#include <stdlib.h>  // Pour malloc, realloc, free

void initGraphe(Graphe* g, int nb_sommets) {
    g->nb_sommets = nb_sommets;
    for (int i = 0; i < nb_sommets; i++)
        for (int j = 0; j < nb_sommets; j++)
            g->matrice[i][j] = 0;
}

void ajouterArete(Graphe* g, int src, int dest, int poids) {
    g->matrice[src][dest] = poids;
    g->matrice[dest][src] = poids;
}

void afficherGraphe(const Graphe* g) {
    for (int i = 0; i < g->nb_sommets; i++) {
        for (int j = 0; j < g->nb_sommets; j++)
            printf("%d ", g->matrice[i][j]);
        printf("\n");
    }
}