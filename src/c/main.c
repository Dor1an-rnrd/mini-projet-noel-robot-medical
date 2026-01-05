#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "common/graphe.h"
#include "common/io.h"
#include "common/cost.h"
#include "algo/glouton.h"
#include "algo/mst.h"

double time_greedy(int (*algo)(const Graphe*, int, int*),
                   const Graphe* g, int start,
                   int* chemin, int* result) {
    clock_t t0 = clock();
    *result = algo(g, start, chemin);
    clock_t t1 = clock();
    return (double)(t1 - t0) / CLOCKS_PER_SEC;
}

double time_mst(int (*algo)(const Graphe*, int*),
                const Graphe* g,
                int* parent, int* result) {
    clock_t t0 = clock();
    *result = algo(g, parent);
    clock_t t1 = clock();
    return (double)(t1 - t0) / CLOCKS_PER_SEC;
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <fichier_graphe>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Graphe g;

    if (!lireGraphe(argv[1], &g)) {
        fprintf(stderr, "Erreur lors de la lecture du graphe\n");
        return EXIT_FAILURE;
    }

    printf("=== Graphe chargé ===\n");
    afficherGraphe(&g);

    int chemin[MAX_SOMMETS];
    int parent[MAX_SOMMETS];
    int depart = 0;

    /* Glouton normal */
    int cost_greedy = glouton_plus_proche_voisin(&g, depart, chemin);

    printf("\n=== Algorithme Glouton ===\n");
    printf("Coût     : %d\nChemin   : ", cost_greedy);
    for (int i = 0; i < g.nb_sommets; i++)
        printf("%d ", chemin[i]);
    printf("\n");

    /* Approximation MST normale */
    int cost_approx = prim_mst(&g, parent);

    printf("\n=== Algorithme Approximation (MST) ===\n");
    printf("Coût     : %d\n", cost_approx);

    /* Comparaison avec mesure de temps */
    int r1, r2;
    double t1 = time_greedy(glouton_plus_proche_voisin, &g, depart, chemin, &r1);
    double t2 = time_mst(prim_mst, &g, parent, &r2);

    printf("\n=== Comparaison C ===\n");
    printf("Algo                 | Coût | Temps (s)\n");
    printf("---------------------+------+------------\n");
    printf("Glouton              | %3d  | %.6f\n", r1, t1);
    printf("Approximation (MST)  | %3d  | %.6f\n", r2, t2);

    return EXIT_SUCCESS;
}
