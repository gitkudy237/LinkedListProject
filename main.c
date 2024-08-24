#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "header.h"

STUDENT *head;

int main(void)
{

	//initilize(head);

	head = addToList(head);

	//displayList(head);

	edit(head, 1);

	//seacrchByName(head, "dy");



	return 0;
}



