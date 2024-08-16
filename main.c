#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#include "header.h"

STUDENT *head;

int main(void)
{
	//1. Allocate memory using malloc()
	//2. make head point to the first node
	STUDENT *node = malloc(sizeof(STUDENT));
	head = node;
	
	head->age = 34;	
	strcpy(head->name, "CLOVIS-KUDY");
	
	initialize(head);
		
	sortAsc(head);
	
	display(head);
	
	printf("This has been added locally");
	
	return 0;
}



