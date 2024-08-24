#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "header.h"

//STUDENT *head;

int main(void)
{
	int choice;
	while(1)
	{	printf("********************\n");
		printf("0. Add student\n");
		printf("1. display list\n");
		printf("2. sort list by marks\n");
		printf("3. sort list by name\n");
		printf("4. Search by name\n");
		printf("5. *** To exit ***\n");
		
		printf("\ntake a choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 0: addStudent();
					break;
			case 1: displayList(head);
					break;
			case 2: sortedListByMarks();
					break;
			case 3: sortedListByName();
					break;
			case 4: searchByName(head, "n");
					break;
			case 5: exit(0);
			default: printf("invalid choice\n");
					break;
		}
	}
	//1. Allocate memory using malloc()
	//2. make head point to the first node
	initilize(head);

	

	/*STUDENT *node1 = malloc(sizeof(STUDENT));
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

	node2->id = 7;
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
*/
	// removeByID(head, 2);
	//displayList(head);

	//seacrchByName(head, "be");

	//sortedListByMarks(head);
	//displayList(head);

	

	return 0;
}