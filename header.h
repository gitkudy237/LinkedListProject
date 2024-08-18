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
		
	STUDENT *std;

	int add;
	do{
	
	 
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
	    
      
         	display(std);
        
		printf("Do you want to add another student? If 'Yes' press 1 if 'No' press 0");
		scanf("%d",&add);
	}while(add == 1);
	
	
	
}


	
	



void sortAsc(STUDENT *head){
	
}
void initilize(STUDENT *head){
	
}
