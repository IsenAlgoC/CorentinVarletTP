#include <stdio.h>
#include <stdlib.h>

int main() {
	int MyTab[100];
	int traquee;
	int i = 0;
	for (i = 0; i < 101; i++) {
		MyTab[i] = (rand() % 21);
	}

	int j = 0;
	printf_s("voici le tableau genere\n");
	for (j = 0; j < 101; j++) {
		printf_s("%d\t", MyTab[j]);
	}

	int* ptr = &MyTab[0];
	printf_s("entree la valeur recherchee (entre 0 et 20)\n");
	scanf_s("%d", &traquee);

	int valTrouve = 0;
	int placement = 0;

	printf_s("la valeur %d a ete trouvee en", traquee);
	while (placement < 100) {
		if (ptr == traquee) {
			printf_s("%d\t", placement);
			valTrouve++;
		}
		ptr++;
		placement++;


	}
	if (valTrouve == 0) {
		printf_s("le valeur %d n'est pas dans le tableau", traquee);
	}

}