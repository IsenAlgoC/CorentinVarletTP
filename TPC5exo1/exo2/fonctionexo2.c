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

int setElement(Tableau* tab, int pos, int element) {// ajout d'un élément
	if (pos > tab->size) {// si le tableau est trop petit
		incrementArraySize(tab, pos - tab->size);// alors on l'agrandit
	}
	if (pos < 1) {// si on veut ajouter une valeur dans une case impossible
		return 0;
	}
	tab->elt[pos - 1] = element;// on ajoute l'element à la position souhaité
	return pos;
}

int displayElements(Tableau* tab, int startPos, int  endPos) {//affiche une partie du tableau
	if (startPos >= endPos) {// on inverse les deux valeurs si la position de début est plus grande que la position de fin
		int tpm = startPos;
		startPos = endPos;
		endPos = tpm;
	}
	if (tab->elt == NULL) {
		return -1;
	}
	if ((endPos > tab->size) || (startPos < 1)) {//on vérifie si les valeurs ne sont pas incohérente
		return -1;
	}
	int compt = startPos;
	for (compt = startPos; compt < (endPos + 1); compt++) {//on affiche les éléments à la suite
		printf_s("\n%d", tab->elt[compt-1]);
	}
	return 0;
}

int deleteElements(Tableau* tab, int startPos, int endPos) {
	if (startPos >= endPos) {// on inverse les deux valeurs si la position de début est plus grande que la position de fin
		int tpm = startPos;
		startPos = endPos;
		endPos = tpm;
	}
	if (tab->elt == NULL) {
		return -1;
	}
	if ((endPos > tab->size) || (startPos < 1)) {//on vérifie si les valeurs ne sont pas incohérente
		return -1;
	}
	int *tab2 = tab->elt;
	int compteur = 0;
	int i = 0;
	for (i = 0; i < tab->size; i++) {
		if (i<(startPos - 1) || i>(endPos - 1)) {// on change les valeurs dans le tableau
			tab->elt[compteur] = tab2[i];
			compteur++;
		}
	}
	return (tab->size - endPos - startPos + 1);



}