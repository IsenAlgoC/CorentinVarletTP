#include <stdio.h>
#include <stdlib.h>
#include "tab.h"
#define nbElts 4
#define TAB2SIZE 100


int main() {
	int myTab1[10], myTab2 = NULL;
	initTab(&myTab1, 10);
	afficheTab(&myTab1, 10, nbElts);
	
	
	myTab2 = (int*)malloc(TAB2SIZE);//création de place en mémoire pour myTab2
	if (myTab2 != NULL) {
		initTab(myTab2, TAB2SIZE);
	}
	else {
		printf_s("memoire insuffisante");
		return -1;
	}
		
	int compteur = 0;
	for (compteur = 0; compteur < 20; compteur++) {// on remplace les 20 premières valeurs 
		*(&myTab2 + compteur) = compteur + 1;
	}

	afficheTab(&myTab2, TAB2SIZE, 20); // puis on les affiche
	free (myTab2); // on détruit le tableau
}