#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "header.h"

//STUDENT *head;

int main(void)
{
	int choice;
	while(1)
	{	printf("*************SELECT OPERATION FROM MENU**********\n\n");
		printf("-------------------------------------------------|\n");
		printf("\t1\t | initialize list\n");
		printf("-------------------------------------------------|\n");
		printf("\t2\t | Add student\n");
		printf("-------------------------------------------------|\n");
		printf("\t3\t | Display List\n");
		printf("-------------------------------------------------|\n");
		printf("\t4\t | Sort\n");
		printf("-------------------------------------------------|\n");
		printf("\t5\t | Search\n");
		printf("-------------------------------------------------|\n");
		printf("\t5\t | Remove Student\n ");
		printf("------------------------------------------------|\n");
		printf("\t6\t | Edit\n");
		printf("-------------------------------------------------|\n");
		printf("\t7\t | *** To exit ***\n");
		printf("-------------------------------------------------|\n");
		
		printf("\nMake a choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: initilize(head);
					break;
			case 2: addStudent();
					break;
			case 3: displayList(head);
					break;
			case 4: sort();
					break;
			case 5: search();
					break;
		//	case 6: Edit(head, 1);
			//		break;
			case 6: exit(0);
			default: printf("invalid choice\n");
					break;
		}
	}
	//1. Allocate memory using malloc()
	//2. make head point to the first node
	initilize(head);

head = addToList(head);

edit(head, 1);
	

	return 0;
}