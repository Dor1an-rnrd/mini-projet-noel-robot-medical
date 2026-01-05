#ifndef IO_H
#define IO_H

#include "common/graphe.h"

/*
 * Charge un graphe depuis un fichier.
 * Retourne 0 si succès, -1 sinon.
 */
int lireGraphe(const char* nom_fichier, Graphe* g);

#endif // IO_H
