#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../structures.c"

//recherche d'un fichier dans un arbre
void search (char * fichier, arbre A, char * path)
{
	
	char newpath[FILENAME_MAX];
	//si l'arbre est nul on ne fait rien et on affiche erreur
	if (A==NULL)
	{
		printf("Erreur, arbre nul");
	}
	//si le noeud contient le fichier qu'on cherche on l'affichage précédé de son chemin
	else if (!strcmp(A->fichier,fichier))
	{
		sprintf(newpath,"%s/%s",path,A->fichier);
		printf("Fichier trouvé : %s \n",newpath); 
	}
	//récursivité pour la recherche
	else
	{
		//seuls les dossiers ont un fils à droite, on les repère ainsi donc on peut concaténer au chemin path
		if (A->droit != NULL)
		{
			sprintf(newpath,"%s/%s",path,A->fichier);
			search(fichier,A->droit,newpath);
		}
		if (A->gauche != NULL)
		{
			search(fichier,A->gauche,path);
		}
	}
}
