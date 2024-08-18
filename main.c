#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#include "header.h"

STUDENT *head;

int main(void)
{
	//1. Allocate memory using malloc()
	//2. make head point to the first node
	STUDENT *node1 = malloc(sizeof(STUDENT));
	head = node1;

    head->id = 1;
	head->age = 34;
	strcpy(head->name, "CLOVIS-KUDY");
	head->deleted = 0;

	// These are manually added students.
	// Should be taken care of by the Add method.
	// Adding at the end
	STUDENT *node2 = malloc(sizeof(STUDENT));
	STUDENT *node3 = malloc(sizeof(STUDENT));

	node1->next = node2;
	node2->next = node3;

	node2->id = 2;
	strcpy(node2->name, "EDDY-RYAN");
	node2->age = 25;
	node2->deleted = 1;

	node3->id = 3;
	strcpy(node3->name, "DEFFO-RYAN");
	node3->age = 25;
	node3->deleted = 1;



	//initialize(head);

	//sortAsc(head);

	displayList(head);



	return 0;
}



