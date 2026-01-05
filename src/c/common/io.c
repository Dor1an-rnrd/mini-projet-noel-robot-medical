#include "common/io.h"
#include <stdio.h>

int lireGraphe(const char* filename, Graphe* g) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        perror("Erreur ouverture fichier");
        return 0;
    }

    int n;
    fscanf(f, "%d", &n);
    initGraphe(g, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(f, "%d", &g->matrice[i][j]);
        }
    }

    fclose(f);
    return 1;
}
