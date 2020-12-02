#include "listes.h"

LinkedList* NewLinkedList(){//nouvelle liste
	LinkedList * tmp;
	tmp = (LinkedList*)malloc(sizeof (LinkedList));
	if (tmp != NULL) {
		tmp->head = NULL;
		tmp->tail = NULL;
		tmp->size = 0;
	}
}

SingleLinked* NewLinkedListItem(int value) {//nouveau maillon
	SingleLinked* tmp;
	tmp = (SingleLinked*)malloc(sizeof(SingleLinked));
	if (tmp != NULL) {
		tmp->data = value;
		tmp->next = NULL;
	}
}

int AddElemToSingleLinkedList(LinkedList* list, SingleLinked* elem) {
	if ((list == NULL) || (elem == NULL) || (elem->next == NULL)) {
		return 0;
	}
	if (list->tail == NULL) {
		list->tail = elem;
		list->head = elem;
		list->size = 1;
	}
	else {
		list->tail->next = elem;
		list->tail = elem;
		list->size += 1;
	}
	return 1;
}

int RemoveElemFromSingleLinkedList(LinkedList* list, SingleLinked* elem) {
	if (list == NULL)return(0);
	if ((list->head == NULL) || (list->tail == NULL)) return(0);
	if ((list->head == list->tail) && (list->size != 1)) return(0);
	if ((list->size == 0) || (elem == NULL))return(0);

	SingleLinked* tmp = list->head;
	SingleLinked* previous = NULL;
	if ((elem == list->head) && (elem == list->tail)) {
		list->head = NULL;
		list->tail = NULL;
		list->size = 0;
		free(elem);
		return(1);
	}

	if (elem == list->head) {
		list->head = elem->next;
		list->size--;
		free(elem);
		return(1);
	}

	while ((tmp != NULL) && (tmp != elem)) {
		previous = tmp;
		tmp = tmp->next;
	}
	if ((previous != NULL) && (tmp == elem) && (tmp->next == NULL)) {
		list->tail = previous;
		previous->next = NULL;
		list->size--;
		free(elem);
		return(1);
	}
	if ((previous != NULL) && (tmp == elem) && (tmp->next != NULL)) {
		previous->next = elem->next;
		list->size--;
		free(elem);
		return(1);
	}
	return(0);
}