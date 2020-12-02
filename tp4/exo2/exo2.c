#include <stdio.h>
#include <stdlib.h>

#define SEPARATEUR '/'
#define TAILLETAB1 20

int main() {
	int MyTab1[TAILLETAB1];
	int pos = 0;
	int i = 1;

	for (i = 1; i < 21; i++)
	{
		MyTab1[pos] = i;
		i++;
	}

	int position = 0;
	for (position = 0; position < 19; position++) {
		printf_s("%d%c", MyTab1[position], SEPARATEUR);

	}
	int* MyPtr1 = &MyTab1[19];

	while (*MyPtr1 > 1) {
		printf_s("%d%c", *MyPtr1, SEPARATEUR);
		MyPtr1--;
	}
	printf("%d", MyTab1[0]);


}