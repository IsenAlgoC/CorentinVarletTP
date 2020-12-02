#include <stdio.h>
#include <stdlib.h>

typedef struct SingleLinked{//cr�ation de la structure maillon
	int data;
	struct SingleLinked *next;
}SingleLinked;


typedef struct LinkedList {//cr�ation de la structure liste chain�e
	SingleLinked *head;
	int size;
	SingleLinked *tail;
}LinkedList;

LinkedList* NewLinkedList();
SingleLinked* NewLinkedListItem(int value);
int AddElemToSingleLinkedList(LinkedList* list, SingleLinked* elem);
int RemoveElemFromSingleLinkedList(LinkedList* list, SingleLinked* elem);




