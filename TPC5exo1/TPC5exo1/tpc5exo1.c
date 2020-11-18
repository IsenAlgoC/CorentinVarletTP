#include <stdio.h>
#include <stdlib.h>
#include "tab.h"
#define nbElts 4
#define TAB2SIZE 100


int main() {
	int myTab1[10];
	initTab(myTab1, 10);
	afficheTab(myTab1, 10, nbElts);
	int myTab2[TAB2SIZE];
	initTab(myTab2, TAB2SIZE);
	
	int compteur = 0;
	for (compteur = 0; compteur < 20; compteur++) {// on remplace les 20 premières valeurs 
		*(myTab2 + compteur) = compteur + 1;
	}

	afficheTab(myTab2, TAB2SIZE, 20); // puis on les affiche
	free (myTab2); // on détruit le tableau
}