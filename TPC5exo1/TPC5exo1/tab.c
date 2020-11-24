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


int afficheTab(int* tab, int size, int nbElts) {// on affiche les premiers éléments du tableau
	if (tab != NULL && size > 0 && size > nbElts) {
		int compt = 0;
		for (compt = 0; compt < nbElts; compt++) {
			printf_s("%d\n", *(tab + compt));
		}
		return 0;
	}
	else return -1;// renvoie une erreur si une des conditions n'est pas respectée
}


int * ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if (tab == NULL) {// on vérifie que le tableau n'est pas vide
		return NULL;
	}
	if (*nbElts < *size) {// on vérifie le cas qui nous arrange pour éviter d'agrandir le tableau
		tab [*nbElts] = element;
		nbElts++;
		return tab;
	}
	else {
		int* myTab = NULL;// on crée un autre tableau 
		myTab = realloc(tab,(*size + TAILLEAJOUT));
		if (myTab == NULL) {// on vérifie que notre nouveau tableau ne soit pas vide
			printf_s("memoire insuffisante");
			return NULL;
		}
		else {
			tab = myTab;
			*size += TAILLEAJOUT;
			tab[*nbElts] = element;
			nbElts++;
			return tab;
		}

	}

}
