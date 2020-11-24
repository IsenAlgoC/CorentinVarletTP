#include <stdio.h>
#include <stdlib.h>
#include "exo2tp5.h"

Tableau newArray() {// creation d'un tableau vide 
	Tableau tab;
	tab.size = TAILLEINITIALE;
	tab.eltsCount = 0;
	tab.elt = malloc(TAILLEINITIALE * sizeof(int));// on crée de la place pour le tableau
	int compt = 0;
	for (compt = 0; compt < TAILLEINITIALE; compt++) {// on remplit les cases du tableau avec des 0
		tab.elt[compt] = 0;
	}
	return tab;
}

int incrementArraySize(Tableau* tab, int incrementValue) {// vérifie et agrandit si possible le tableau
	int* tmp = tab->elt;
	tab->elt = (int*)realloc(tab->elt + incrementValue, sizeof(int));
	if (tab->elt == NULL) {// on vérifie si l'adresse n'est pas vide
		tab->elt = tmp;
		return -1;
	}
	int compt = 0;
	for (compt = 0; compt < incrementValue; compt++) {// on remplit les nouvelles cases du tableau
		tab->elt[tab->size + compt] = 0;
	}
	return tab->size + incrementValue ; // on renvoie la nouvelle taille du tableau

}