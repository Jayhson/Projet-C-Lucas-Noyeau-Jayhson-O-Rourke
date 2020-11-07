#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structures.c"

void load(char * chemin, arbre * A);
//permet de récupérer l'arbre chargé en mémoire par load
arbre lancementLoad(char * chemin)
{
	arbre retour;
	retour = malloc(sizeof(struct noeud));
	strcpy(retour->fichier,chemin);
	retour->gauche = NULL;
	retour->droit = NULL;
	load(chemin,&retour);
	return retour;
}
