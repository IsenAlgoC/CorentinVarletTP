#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#define TAILLETAB1 19

int main() {
	char mot[TAILLETAB1];
	printf_s("entrez un mot\n");
	scanf_s("%s", mot, _countof(mot));

	int i = 0;
	int tablen;
	do {
		mot[i] = toupper(mot[i]);
		i++;
	} while (mot[i] != 0);

	int palindrome = 1;
	int j = strlen(mot) - 1;
	i = 0;
	while (i < strlen(mot) / 2 && palindrome == 1) {
		if (mot[i] != mot[j]) {
			palindrome = 0;
		}
		i++, j--;
	}

	if (palindrome) {
		printf("C'est un palindrome");
	}
	else {
		printf("Ce n'est pas un palindrome");
	}
}