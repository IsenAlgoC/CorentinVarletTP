#include <stdio.h>
#include <stdlib.h>

int main() {
	char sexe;
	char s;
	char prenom[20];
	char nom[20];

	printf_s("etes vous un homme ou une femme ? H,F");
	do
	{
		sexe = getchar();
	} while ((sexe != 'H') && (sexe != 'F'));
	switch (sexe)
	{
	case 'H':
		s = "monsieur";
		break;
	case 'F':
		s = "madame";
		break;
	}
	printf_s("quel est votre prenom\n");
	scanf_s("%s", &prenom, 20);
	printf_s("quel est votre nom\n");
	scanf_s("%s", &nom, 20);

	print_s("%s%s%s", s, prenom, nom);

}