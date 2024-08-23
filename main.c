#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "header.h"

STUDENT *head;

int main(void)
{
	//1. Allocate memory using malloc()
	//2. make head point to the first node
	initilize(head);

	

	STUDENT *node1 = malloc(sizeof(STUDENT));
	head = node1;

    node1->id = 1;
	node1->age = 34;
	node1->mark = 18.0;
	strcpy(node1->name, "CLOVIS BIN");
	node1->deleted = 0;
	

	// These are manually added students.
	// Should be taken care of by the Add method.
	// Adding at the end
	STUDENT *node2 = malloc(sizeof(STUDENT));
	STUDENT *node3 = malloc(sizeof(STUDENT));
	STUDENT *node4 = malloc(sizeof(STUDENT));

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;

	node2->id = 2;
	strcpy(node2->name, "EDDY RYAN");
	node2->age = 25;
	node2->mark = 18.5;
	node2->deleted = 1;

	node3->id = 3;
	strcpy(node3->name, "JETHRO BLAIRE");
	node3->age = 16;
	node3->mark = 16.5;
	node3->deleted = 1;
	
	node4->id = 4;
	strcpy(node4->name, "EDMON LOWE");
	node4->age = 26;
	node4->mark = 19.5;
	node4->deleted = 0;

	// removeByID(head, 2);
	displayList(head);

	seacrchByName(head);

	

	return 0;
}