#include<stdio.h>
#include<stdlib.h>

int main() {

	int a = 0, s = 0, b = 0;

	for (int n = 1; n <= 100; n++) {
		s = (n + s);

		printf("\nValeur de n : %d, somme : %d\n", n, s);
	}

	do {
		a = a + 1;
		b = a + b;
	} while (a < 100);

	printf("\nValeur de n : %d, somme : %d\n", a, b);

	while (a < 100) {
		a = a + 1;
		b = a + b;
	}
	printf("\nValeur de n : %d, somme : %d\n", a, b);



	while (b < 65535) {
		a = a + 1;
		b = a + b;
	}
	printf("\n valeur de n max %d\n", a);


	unsigned short int  n, s;
	s = 0;
	scanf_s("%hu", &n);

	for (int n = 0; n < 100; n++) {
		s = (n + s);
	}
	printf("\nValeur de n : %d, somme : %d\n", n, s);



	unsigned short int t = 0;
	int u;
	int n;
	printf_s("enter a value for n : ");
	scanf_s("%d", &n);
	while (n > 361) {
		printf("enter a smaller value");
		scanf_s("%d", &n);
	}
	for (u = 1; u <= n; ++u) {
		t = t + u;
		printf("\n%hu", t);
	}
	



}