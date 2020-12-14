#include <stdio.h>
#include<stdlib.h>

int main() {
	float longueur, largeur, profondeur;
	printf_s("entrer une valeur pour la longueur de la longueur : ");
	scanf_s("%f", &longueur);

	printf_s("entrer une valeur pour la longueur de la largeur : ");
	scanf_s("%f", &largeur);

	printf_s("entrer une valeur pour la profondeur de la longueur : ");
	scanf_s("%f", &profondeur);

	if (1 > longueur) {
		printf_s("entrer une valeur plus grande pour la longueur");
		scanf_s("%f", &longueur);

	}

	if (longueur > 150) {
		printf_s("entrer une valeur plus petite pour la longueur");
		scanf_s("%f", &longueur);

	}

	if (1 > largeur) {
		printf_s("entrer une valeur plus grande pour la largeur");
		scanf_s("%f", &largeur);
	}

	if (largeur > 150) {
		printf_s("entrer une valeur plus petite pour la largeur");
		scanf_s("%f", &largeur);
	}

	if (1 > profondeur) {
		printf_s("entrer une valeur plus grande pour la profondeur");
		scanf_s("%f", &profondeur);
	}

	if (profondeur > 150) {
		printf_s("entrer une valeur plus petite pour la profondeur");
		scanf_s("%f", &profondeur);
	}

	if (longueur < 55 && largeur < 35 && profondeur < 25) {
		printf_s("\nVALIDE\n");
	}

	else {
		printf_s("\nNON VALIDE\n");
	}


	
}