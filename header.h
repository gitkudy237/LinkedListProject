#include <stdio.h>

struct student {
	int id;
	char name[25];
	int age;
    float mark;
	int deleted;
	struct student *next;
};

typedef struct student STUDENT;
STUDENT *current;

void initilize(STUDENT *s);
void print_header();
void display(STUDENT *s);
void displayList(STUDENT *s);
void seacrchByName(STUDENT *s, char input[15]);

// searchByID will return a pointer to the target node.
// The reason is to be able to maniplulate the output flexibly.
// To see the output, use the display function declared above.
STUDENT *searchByID(STUDENT *s, int key); 
void removeByID(STUDENT *s, int key);
int isEmpty(STUDENT *s);
STUDENT *temporalNode, *newnode;
//variables;
int age, deleted, id;
float mark;
char name[25];

void display(STUDENT *s){

	printf("%s\t\t", s->name);
	printf("%d\t\t", s->id);
	printf("%d\t\t", s->age);
	printf("%.2f\t\t", s->mark);
    printf("%d\n", s->deleted);
    printf("---------------------------------------------------------------------------------\n");
}

void initilize(STUDENT *head){
    head = NULL;
}


STUDENT *addToList(STUDENT *head)
{
	newnode = malloc(sizeof(STUDENT));
	printf("Enter the name:");
	gets(newnode->name);
	printf("Enter the age:");
	scanf("%d", &newnode->age);
	printf("Enter the id:");
	scanf("%d", &newnode->id);
	printf("Enter the marks:");
	scanf("%f", &newnode->mark);
	printf("Enter 1 if deleted or 0 if not:");
	scanf("%d", &newnode->deleted);
	
	newnode->next = NULL;
	
	if( head == NULL)
	{
		head = temporalNode = newnode;
	}
	else
	{
		temporalNode->next = newnode;
		temporalNode = newnode;
	}
	return head;
}

void print_header() {
    printf("\nStudentName\t\tId\t\tAge\t\tMark\t\tDeleted\n");
    printf("---------------------------------------------------------------------------------\n");

}
void displayList(STUDENT *head){
    
    system("cls");
    if (isEmpty(head)) {
        printf("The list is empty");
        return;
    }

    current = head;
    printf("\nList of students:\n");
    print_header();
    while (current != NULL) {
        display(current);
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

    current = head;

    while (current != NULL) {
        if (current->id == key) {
            return current;
            break;
        }

        current = current->next;
    }
}

void seacrchByName(STUDENT *head, char input[15]){
    
    current = head;
    int results = 0;

    printf("\nThe search result for \"%s\" is:\n", input);
    print_header();
    while (current != NULL) {
        char test_input[15];
        char test_current[15];

        strcpy(test_input, input);
        strcpy(test_current, current->name);

        if (strstr(strlwr(test_current), strlwr(test_input)) != NULL) {
            display(current);
            results++;
        }
        current = current->next;
    }

    if (results == 0)
        printf("<---------- Empty ---------->");
}
void removeByID(STUDENT *head, int key) {

    if (isEmpty(head)) {
        printf("List is empty");
        return;
    }
    STUDENT *target;
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



