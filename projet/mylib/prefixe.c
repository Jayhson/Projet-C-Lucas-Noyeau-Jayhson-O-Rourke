#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structures.c"

//parcours d'affichage préfixe d'un arbre
void prefixe(arbre A)
{
	if(A!=NULL)
	{
		printf("%s\n",A->fichier);
		prefixe(A->gauche);
		prefixe(A->droit);
	}
}
