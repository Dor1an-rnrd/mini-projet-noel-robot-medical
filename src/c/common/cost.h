#ifndef COST_H
#define COST_H

#include "common/graphe.h"

/*
 * Calcule le coût total d'un chemin.
 * path : tableau des sommets visités
 * len  : longueur du chemin
 * Retourne -1 si le chemin est invalide.
 */
int cout_chemin(const Graphe* g, const int* path, int len);

#endif // COST_H