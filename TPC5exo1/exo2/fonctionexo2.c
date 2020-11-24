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

int incrementArraySize(Tableau* tab, int incrementValue) {
	if (tab->elt)

}