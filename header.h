#include <stdio.h>
#include <stdlib.h>

struct student {
	int id;
	int age;
	char name[15];
	int deleted;
	float marks;
	struct student *next;
};

typedef struct student STUDENT;


void display(STUDENT *s){
	printf("\n*******************************\n");
	printf("\nId: %d", s->id);
	printf("\nAge: %d", s->age);
	printf("\nDeleted: %d", s->deleted);
	printf("\nName: %s", s->name);
	printf("\nMarks: %f", s->marks);
}
void AddStudent()
{
   
    STUDENT *head = NULL;
		
	STUDENT *std;//std stands for the new node

	int add;
	
	
	 // Adding elements at the beginning of the list
	    	 STUDENT *std = malloc(sizeof(STUDENT));
	        head = std;
	        std->next = NULL;
	    	printf("Enter student id\n");
	    	scanf("%d",&std->id);
	    	printf("Enter student age\n");
	    	scanf("%d",&std->age);
	    	printf("Enter 1 if student is deleted and 0 if student not deleted\n ");
	    	scanf("%d",&std->deleted);
	    	printf("Enter student name\n");
	    	scanf("%d",&std->name);
	    	printf("Enter student marks\n");
	    	scanf("%f",&std->marks);
	    
      
         	
        std = std->next;
		printf("Do you want to add another student? If 'Yes' press 1 if 'No' press 0");
		scanf("%d",&add);
	do{
		//Adding elements at the end of the linklist
			current = head;
			while (current->next != NULL)
			{
				current = current->next;
			}
			STUDENT *std = malloc(sizeof(STUDENT));
			current->next = std;
			std->next = NULL;
			printf("Enter student id\n");
	    	scanf("%d",&std->id);
	    	printf("Enter student age\n");
	    	scanf("%d",&std->age);
	    	printf("Enter 1 if student is deleted and 0 if student not deleted\n ");
	    	scanf("%d",&std->deleted);
	    	printf("Enter student name\n");
	    	scanf("%s",&std->name);
	    	printf("Enter student marks\n");
	    	scanf("%f",&std->marks);
	    
         // The diplay function 
         	displayList(std);
         	std = std->next;
	  	printf("Do you want to add another student? If 'Yes' press 1 if 'No' press 0\n");
		scanf("%d",&add);
	}while(add == 1);// Repeating the code until when the user enters 0
	
}
void SortByMarks(STUDENT *m)
{
	// declaring a varriable for the sorting
		float a;
		//varriables to hold the address of student(std)
	STUDENT *temp1;
	STUDENT *temp2;
	for(temp1 = std; temp1 != NULL; temp1 = temp1->next)
	{
		for(temp2 = temp1->next;temp2 != NULL; temp2 = temp2->next)
		{
			// Comparing and sorting the elements
			if(temp1 > temp)
		    {
		    	
		    	a = temp1->marks
			temp1->marks = temp2->marks;
			temp2->marks = a;
			}
		}
	}
	// Displaying the sorted list
	std = head;
	while(std != NULL)
	{
	displayList(std)
		std = std->next;
	}

	
}


	
	



void sortAsc(STUDENT *head){
	
}
void initilize(STUDENT *head){
	
}
