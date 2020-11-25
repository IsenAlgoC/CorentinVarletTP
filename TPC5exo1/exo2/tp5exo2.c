#include <stdio.h>
#include <stdlib.h>
#include "exo2tp5.h"

int main() {
	Tableau tab;
	tab = newArray();
	setElement(&tab, 1, 4);
	setElement(&tab, 3, 5);
	setElement(&tab, 2, 12);
	displayElements(&tab, 1, 3);
	setElement(&tab, 4, 56);
	deleteElements(&tab, 1, 3);
	displayElements(&tab, 1, 5);

}