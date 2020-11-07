#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//sépare une chaîne de caractères en deux avec pour séparateur "="
int parse(char *s, char *root, char *chemin)
{
	return sscanf(s,"%[^=]=%s",root,chemin)==2;
}
