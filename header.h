#include <stdio.h>

struct student {
	int id;
	int age;
	char name[15];
	int deleted;
	struct student *next;
};

typedef struct student STUDENT;


void display(STUDENT *s){
	printf("\n*******************************\n");
	printf("\nId: %d", s->id);
	printf("\nAge: %d", s->age);
	printf("\nDeleted: %d", s->deleted);
	printf("\nName: %s", s->name);
}

void sortAsc(STUDENT *head){
	
}
void initilize(STUDENT *head){
	
}
