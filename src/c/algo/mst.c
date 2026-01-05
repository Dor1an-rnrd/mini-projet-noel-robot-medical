#include "algo/mst.h"
#include <limits.h>

int prim_mst(const Graphe* g, int* parent) {
    int n = g->nb_sommets;
    int key[MAX_SOMMETS];
    int in_mst[MAX_SOMMETS] = {0};

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[0] = 0;
    int cout_total = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        int min = INT_MAX;

        for (int v = 0; v < n; v++) {
            if (!in_mst[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        if (u == -1)
            break;

        in_mst[u] = 1;
        cout_total += key[u];

        for (int v = 0; v < n; v++) {
            if (g->matrice[u][v] > 0 && !in_mst[v] &&
                g->matrice[u][v] < key[v]) {
                key[v] = g->matrice[u][v];
                parent[v] = u;
            }
        }
    }

    return cout_total;
}