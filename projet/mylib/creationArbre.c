#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structures.c"

//fonction créant automatiquement un arbre avec pour racine le chemin donné
arbre creationArbre (char * chemin)
{
	arbre A = NULL;
	A = malloc(sizeof(struct noeud));
	strcpy(A->fichier,chemin);
	A->gauche = NULL;
	A->droit = NULL;
	return A;
}
