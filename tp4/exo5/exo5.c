#include <stdio.h>
#include <stdlib.h>

int main() {
	char phrase[50];
	printf_s("entrez une phrase\n");
	gets(phrase);

	int compteur = 0;
	int i = 0;
	int mot = 1;

	for (i = 0; i < strlen(phrase); i++) {
		if (phrase[i] == ' ') {
			compteur++;
			mot++;
		}
	}

	float moyenne;
	float longueur = (strlen(phrase) - compteur);
	moyenne = longueur / mot;

	printf("La taille sans espaces est %f\n", longueur);
	printf("vous avez entre %d mots\n", mot);
	printf("La longeur moyenne des mots est %f\n", moyenne);

}