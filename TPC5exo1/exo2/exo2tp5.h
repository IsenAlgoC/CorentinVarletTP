#define TAILLEINITIALE 100

typedef struct Tableau {
	int* elt;// le tableau d'entier
	int size; // la taille  de ce tableau
	int eltsCount; //nombre d elements dans le tableau
}Tableau;

Tableau newArray();
int incrementArraySize(Tableau* tab, int incrementValue);
int setElement(Tableau* tab, int pos, int element);
int displayElements(Tableau* tab, int startPos, int endPos);
int deleteElements(Tableau* tab, int startPos, int endPos);