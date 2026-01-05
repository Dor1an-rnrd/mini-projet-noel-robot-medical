#include "algo/glouton.h"
#include <limits.h>

int glouton_plus_proche_voisin(const Graphe* g, int depart, int* chemin) {
    int n = g->nb_sommets;
    int visite[MAX_SOMMETS] = {0};

    int courant = depart;
    chemin[0] = courant;
    visite[courant] = 1;

    int cout = 0;

    for (int i = 1; i < n; i++) {
        int prochain = -1;
        int min = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (!visite[j] && g->matrice[courant][j] > 0 &&
                g->matrice[courant][j] < min) {
                min = g->matrice[courant][j];
                prochain = j;
            }
        }

        if (prochain == -1)
            return -1;

        chemin[i] = prochain;
        visite[prochain] = 1;
        cout += min;
        courant = prochain;
    }

    return cout;
}
