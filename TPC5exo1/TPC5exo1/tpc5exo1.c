#include <stdio.h>
#include <stdlib.h>



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


int afficheTab(int* tab, int size, int nbElts) {
	if (tab != NULL && size > 0 && size > nbElts) {
		int compt = 0;
		for (compt = 0; compt < nbElts; compt++) {
			printf_s("%d", *(tab + compt));
		}
		return 0;
	}
	else return -1;
}


int main() {
	int myTab1[10];


}