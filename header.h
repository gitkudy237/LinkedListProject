#include <stdio.h>

struct student {
	int id;
	int age;
	char name[15];
	int deleted;
	struct student *next;
};

typedef struct student STUDENT;

void initilize(STUDENT *s);
void display(STUDENT *s);
void displayList(STUDENT *s);
void sortAsc(STUDENT *s);


void display(STUDENT *s){
	printf("\n*******************************\n");
	printf("\nId: %d", s->id);
	printf("\nAge: %d", s->age);
	printf("\nDeleted: %d", s->deleted);
	printf("\nName: %s", s->name);
}

void initilize(STUDENT *head){
    head = NULL;
}

void sortAsc(STUDENT *head){

}

void displayList(STUDENT *head){

    if (head == NULL) {
        printf("The list is empty");
        return;
    }

    STUDENT *current;
    current = head;

    while (current != NULL) {

        printf("\nId: %d", current->id);
        printf("\nAge: %d", current->age);
        printf("\nDeleted: %d", current->deleted);
        printf("\nName: %s", current->name);
        printf("\n*******************************\n");

        current = current->next;
    }

}

// End of Kudy's changes
