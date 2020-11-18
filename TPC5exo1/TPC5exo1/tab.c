#include <stdio.h>
#include <stdlib.h>
#include "tab.h"
# define TAILLEAJOUT 50


int initTab(int* tab, int size) {//on initialise le tableau avec des 0
	if (tab != NULL && size > 0) {
		int compteur = 0;
		for (compteur = 0; compteur < size; compteur++) {
			*(tab + compteur) = 0;
		}
		return size;
	}
	else return -1;
}


int afficheTab(int* tab, int size, int nbElts) {// on affiche les premiers �l�ments du tableau
	if (tab != NULL && size > 0 && size > nbElts) {
		int compt = 0;
		for (compt = 0; compt < nbElts; compt++) {
			printf_s("%d\n", *(tab + compt));
		}
		return 0;
	}
	else return -1;// renvoie une erreur si une des conditions n'est pas respect�e
}


int * ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if (*nbElts < *size) {// on v�rifie le cas qui nous arrange pour �viter d'agrandir le tableau
		*(tab + *nbElts + 1) = element;
		*nbElts++;
		return nbElts;
	}
	else {
		int* myTab = NULL;// on cr�e un autre tableau 
		myTab = realloc(tab, TAILLEAJOUT);
		if (myTab == NULL) {// on v�rifie que notre nouveau tableau ne soit pas vide
			printf_s("memoire insuffisante");
			return NULL;
		}
		else {
			*(myTab + *nbElts + 1) = element;
			*nbElts++;
			*size += TAILLEAJOUT;
			return myTab;
		}

	}

}
