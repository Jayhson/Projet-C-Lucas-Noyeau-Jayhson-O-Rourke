#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structures nécessaires à la création de l'arbre
struct noeud
{
	 char fichier[FILENAME_MAX];
	 struct noeud * gauche;
	 struct noeud * droit;
};
typedef struct noeud * arbre;
