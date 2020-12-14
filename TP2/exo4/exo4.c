#include <stdlib.h>
#include <stdio.h>


int main() {
	int essai = 1;
	int joueur;
	int devinette = rand() % 100;
	printf("%d\n", devinette);
  
	printf("entre un nombre entier :\n");
	scanf_s("%d", &joueur);


	while (joueur != devinette) {
		if (joueur < devinette) {
			printf("trop petit essaye encore :\n");
			scanf_s("%d", &joueur);
			essai++;
		}
		else {
			printf("trop grand essaye encore :\n");
			scanf_s("%d", &joueur);
			essai++;
		}


	}

	printf("BRAVO, tu as l'as trouve en %d essais", essai);
}