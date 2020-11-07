#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <dirent.h>
#include "structures.c"
#include "mylib/lib.h"

#define L 150


int main(int nbarg, char *arg[])
{
	//vérification des paramètres
	if (nbarg != 2)
	{
		printf("un seul argument obligatoire est accepté (le nom du fichier recherché)\n");
		return 1;
	}
	
	//ouverture du fichier (+ déclaration)
	
	char s[L];
	FILE * source;
	source = fopen("tree.conf","r");
	
	//erreur s'il y a un problème à l'ouverture
	
	if (source==NULL)
	{
		perror("tree.conf");
		return 2;
	}
	
	//déclaration des variables qui vont récupérer l'arborescence
	
	char root[10], chemin[100];
	int result;
	
	//lecture du fichier
	
	while(fgets(s,L-1,source)!=NULL)
	{
		printf("%s\n",s);
		//si la ligne n'est pas un commentaire ou n'est pas vide
		if ( (s[0]!='#') || (strlen(s)!=1) )
		{
			//on parse les variables
			result=parse(s,root,chemin);
			if(result==1){printf("root='%s', chemin='%s' result=%d\n",root,chemin,result) ;}
		}
	}
	
	//fermeture du fichier
	fclose(source);
	
	//déclaration arbre
	arbre ret;
	//mise en mémoire de l'arbre à partir du chemin donné
	ret = lancementLoad(chemin);
	//un affichage pour pouvoir regarder le contenu de l'arbre
	prefixe(ret);
	
	//on passe un chemin vide en paramètre qui se complètera au fil du parcours pour pouvoir afficher le chemin du fichier trouvé
	char path[FILENAME_MAX];
	//recherche du fichier passé en argument au main dans l'arbre ret
	search(arg[1],ret,path);

	return 0;
}
