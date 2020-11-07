#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <dirent.h>
#include "../structures.c"

arbre creationArbre (char * chemin);
//on définit les fils (=contenu) d'un répertoire à sa droite et les frères d'un fichier ou d'un répertoire à sa gauche dans la fonction load
void load(char * chemin, arbre * A)	
{
	DIR * D;
	//nouveau chemin de taille FILENAME_MAX, défini par le système
	char newpath[FILENAME_MAX];

	//ouverture du répertoire
	D = opendir(chemin);
	assert(D!=NULL);
	
	struct dirent *dir;
	arbre tmpfrere;
	int fils;
	fils=1;
	
	//lecture du répertoire racine	
	while( (dir=readdir(D)) != NULL)
	{
		//si c'est un fils on ajoute à droite
		if (fils==1)
		{
			//si le premier fichier est dossier (et pas dossier parent ou courant)
			if ( (dir->d_type == DT_DIR) && (strcmp(dir->d_name,"..")) && (strcmp(dir->d_name,".")) )
			{
				//on rajoute la racine au dossier trouvé pour la récursivité
				sprintf(newpath,"%s/%s",chemin,dir->d_name);
				//nouveau dossier donc création d'un nouvel arbre
				arbre arbreFils = creationArbre(dir->d_name);
				//on l'ajoute à l'arbre actuel
				(*A)->droit = arbreFils;
				//on le marque pour ajouter ses frères à gauche par la suite
				tmpfrere = arbreFils;
				
				
				/*idée de réc pour plus tard
				tmpfils = arbreFils->droit;*/
				load(newpath,&arbreFils);
			}
			//si le premier fichier est un fichier régulier
			else if (dir->d_type == DT_REG )
			{
				//nouveau fichier donc création d'un nouvel arbre
				arbre arbreFils = creationArbre(dir->d_name);
				//on l'ajoute à l'arbre actuel
				(*A)->droit = arbreFils;
				//on le marque pour ajouter ses frères à gauche par la suite
				tmpfrere = arbreFils;
			}
			++fils;
		}
		//sinon c'est un frère on ajoute à gauche
		else
		{
			if ( (dir->d_type == DT_DIR) && (strcmp(dir->d_name,"..")) && (strcmp(dir->d_name,".")) )
			{
				//on rajoute la racine au dossier trouvé pour la récursivité
				sprintf(newpath,"%s/%s",chemin,dir->d_name);
				//nouveau dossier donc création d'un nouvel arbre
				arbre arbreFrere = creationArbre(dir->d_name);
				//on l'ajoute à l'arbre actuel
				tmpfrere->gauche = arbreFrere;
				//on le marque pour ajouter ses éventuels frères à gauche par la suite
				tmpfrere = arbreFrere;
				
				/*idée de réc pour plus tard
				tmpfils = arbreFrere->droit;*/
				load(newpath,&arbreFrere);
			}
			else if (dir->d_type == DT_REG )
			{
				//nouveau fichier donc création d'un nouvel arbre
				arbre arbreFrere = creationArbre(dir->d_name);
				//on l'ajoute à l'arbre actuel
				tmpfrere->gauche = arbreFrere;
				//on le marque pour ajouter ses frères éventuels à gauche par la suite
				tmpfrere = arbreFrere;
			}
			
		}
	}
	//fermeture du répertoire
	closedir(D);
}

