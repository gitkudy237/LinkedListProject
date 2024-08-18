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

// searchByID will return a pointer to the target node.
// The reason is to be able to maniplulate the output flexibly.
// To see the output, use the display function declared above.
STUDENT *searchByID(STUDENT *s, int key); 
void removeByID(STUDENT *s, int key);
int isEmpty(STUDENT *s);


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

    if (isEmpty(head)) {
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

int isEmpty(STUDENT *head){
    return head == NULL ? 1 : 0;
}

STUDENT *searchByID(STUDENT *head, int key) {
    if (isEmpty(head)) {
        printf("List is empty");
        exit;
    }
    
    STUDENT *current;
    current = head;

    while (current != NULL) {
        if (current->id == key) {
            return current;
            break;
        }

        current = current->next;
    }
}

void removeByID(STUDENT *head, int key) {

    STUDENT *current, *target;
    target = searchByID(head, key);
    current = head;

    while (current < target) {
        if (current->next = target) {
            current->next = target->next;
            free(target);
        }
        current = current->next;
    }
}



