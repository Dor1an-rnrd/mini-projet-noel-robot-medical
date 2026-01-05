#include "common/cost.h"

int cout_chemin(const Graphe* g, const int* path, int len) {
    int cout = 0;

    for (int i = 0; i < len - 1; i++) {
        int u = path[i];
        int v = path[i + 1];

        if (g->matrice[u][v] == 0) {
            return -1; // chemin invalide
        }

        cout += g->matrice[u][v];
    }

    return cout;
}
