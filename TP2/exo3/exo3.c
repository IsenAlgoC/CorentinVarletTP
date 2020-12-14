#include <stdlib.h> 
#include <stdio.h>


int main() {
	
	unsigned short int annee;
	int c = 1;

	printf("Veuillez saisir une annee svp :\n");
	scanf_s("%hu", &annee);

	if (((annee % 400 != 0) & (annee % 100 == 0)) || (annee % 4 != 0))
		printf("L'annee %d n'est pas bissextile\n", annee);
	else
		printf("L'annee %d est bissextile\n", annee);


	
}