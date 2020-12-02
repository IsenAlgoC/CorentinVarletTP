#include<stdlib.h>
#include<stdio.h>
#include "tp4.h"

int main() {
	HEURE HeureDebut, HeureFin, Duree;
	HeureDebut.heure = 12;
	HeureDebut.minute = 30;
	Duree.heure = 0;
	Duree.minute = 45;

	HeureFin.minute = (HeureDebut.minute + Duree.minute) % 60;
	HeureFin.heure = (HeureDebut.heure + Duree.heure) + (HeureDebut.minute + Duree.minute) / 60;

	printf("HeureDebut = %d:%d\n", HeureDebut.heure, HeureDebut.minute);
	printf("HeureFin = %d:%d\n", HeureFin.heure, HeureFin.minute);
	printf("Duree = %d:%d\n", Duree.heure, Duree.minute);

	return (EXIT_SUCCESS);
}
