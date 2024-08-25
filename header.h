#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct student *head = NULL;
struct student {
	int id;
	char name[25];
	int age;
    float mark;
	int deleted;
	struct student *next;
};

typedef struct student STUDENT;

//variables;
STUDENT *current;
STUDENT *temporalNode, *newnode;
int age, deleted, id;
float mark;
char name[25];

void initilize(STUDENT *s);
void print_header();
void display(STUDENT *s);
void displayList(STUDENT *s);
void edit(STUDENT *s, int id);
void editMark(STUDENT *s, float newMark);
void softDelete(STUDENT *s);
void showSingleResult(STUDENT *s);
void sortByMarks();
void sortById();
void sortByAge();
int inputID();
void displayMenu();
void searchByName(STUDENT *head, const char input[15]);
STUDENT *searchByID(STUDENT *s, int key);
void removeByID(STUDENT *s, int key);
void edit(STUDENT *head, int key);
int isEmpty(STUDENT *s);

void display(STUDENT *s){
    if (s == NULL) {
        printf("<-------------------------------- Empty ------------------------------------>");
        return;
    }
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
	int option  = 1;
	while(option)
  {
	
	newnode = (STUDENT*) malloc(sizeof(STUDENT));
    int candidateID;

    do {
        printf("Enter the id: ");
        scanf("%d", &candidateID);

        if (!searchByID(head, candidateID)){
            newnode->id = candidateID;
            break;
        }

        printf("Sorry! Id already exist.\n");

;    }while (searchByID(head, candidateID));

	printf("Enter the name: ");
	getchar();
	gets(newnode->name);
	printf("Enter the age: ");
	scanf("%d", &newnode->age);
	printf("Enter the marks: ");
	scanf("%f", &newnode->mark);

	newnode->next = NULL;
	newnode->deleted = 0;
	if( head == NULL)
	{
		head = temporalNode = newnode;
	}
	else
	{
		temporalNode->next = newnode;
		temporalNode = newnode;
	}
	printf("\n\nStudent added Successfully!\n");
	print_header();
	display(temporalNode);
	
	printf("\n\nDo you want to add another student? if yes, press 1, otherwise press 0: ");
	scanf("%d", &option);
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
        printf("The list is empty\n");
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

    current = head;

    while (current != NULL) {
        if (current->id == key) {
            return current;
            break;
        }

        current = current->next;
    }

    return NULL;
}



void searchByName(STUDENT *head, const char input[15]){

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
        printf("<-------------------------------- Empty ------------------------------------>");
}
void removeByID(STUDENT *head, int key) {

    if (isEmpty(head)) {
        printf("List is empty please.......\n");
        return;
    }
    STUDENT *target;
    target = searchByID(head, key);

    if (!target) {
        printf("Sorry! student not found!");
        return;
    }

    current = head;

    while (current < target) {
        if (current->next = target) {
            current->next = target->next;
            free(target);
        }
        current = current->next;
    }
}

void edit(STUDENT *head, int key) {
	system("cls");
	int selection = 1;
	while(selection){
	
	int selection;

    STUDENT *target;
    target = searchByID(head, key);

    // I check whether the student exists
    if (!target) {
        printf("Sorry! Student not found.\n");
        return;
    }

    printf("The student is:\n");
    showSingleResult(target);
    int choice;
    printf("Press 1 to edit student mark\n");
    printf("Press 2 to soft delete student\n");
	printf("Press 3 to go back to the menu.");
    scanf("%d", &choice);

    float newMark;
    int option;

    switch (choice) {

        case 1:
            printf("Enter new mark: ");
            scanf("%f", &newMark);
            editMark(target, newMark);
            break;

        case 2:
            printf("Press 1 to delete\nPress 0 to cancel\n");
            scanf("%d", &option);
            option == 1 ? softDelete(target) : displayMenu();
            break;
		case 3: displayMenu();
        default:
            printf("Invalid option.");
            break;
    }

    printf("\nUpdated record successfully!");
    showSingleResult(target);
    printf("\n\nDo you want to edit again? if yes, press 1, otherwise press 0: ");
    scanf("%d", &selection);
  }
}

void editMark(STUDENT *student, float newMark) {
    student->mark = newMark;
}

void softDelete(STUDENT *student) {
    student->deleted = 1;
}

void showSingleResult(STUDENT *student) {
    print_header();
    display(student);
}

int length(STUDENT *head) {
    current = head;
    int count = 0;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}


 void sortByMarks()
{
	if(head == NULL || head->next == NULL)
		return; // checks whether list is null or contains a single node.
	STUDENT * sortedList = NULL;
	STUDENT* current = head;
	while(current != NULL)
	{
		STUDENT* nextNode = current->next;
		if(sortedList == NULL || current->mark <= sortedList->mark)
		{
			current->next = sortedList;
			sortedList = current;
		}
		else{
			STUDENT* temp = sortedList;
			while(temp->next != NULL && temp->next->mark < current->mark)
			 temp = temp->next;
			 current->next = temp->next;
			 temp->next  = current;
		}
		current = nextNode;
	}
    head = sortedList;

}



void sortByName()
{
	if(head == NULL || head->next == NULL)
	{
		return;
	}
	STUDENT *sortedList = NULL;
	STUDENT *current = head;
	while(current != NULL)
	{
		STUDENT *nextNode = current->next;
		if(sortedList == NULL || strcmp(current->name, sortedList->name) <= 0)
		{
			current->next = sortedList;
			sortedList = current;
		}else{
			STUDENT *temp = head;
			while(temp->next != NULL && strcmp(temp->next->name, current->name) < 0)
			temp = temp->next;
			current->next = temp->next;
			temp->next = current;
		}
		current = nextNode;
	}
	head = sortedList;

}

//sorting by id

void sortById()
{
	if(head == NULL|| head->next == NULL)
	{
		return;//checking if head is null or list contains only  one node.
	}
	STUDENT *sortedList = NULL;
	STUDENT *current = head;
	while(current != NULL)
	{
		STUDENT *nextNode = current->next;
		if(sortedList == NULL || current->id <= sortedList->id)
		{
			current->next = sortedList;
			sortedList = current;
		}
		else{
			STUDENT *temp = head;
			while(temp->next != NULL && temp->next->id < current->id)
			 temp = temp->next;
			 current->next = temp->next;
			 temp->next = current;
		}
		current = nextNode;
	}
	head = sortedList;

}


void sortByAge()
{
	if(head == NULL|| head->next == NULL)
	{
		return;
	}
	STUDENT *sortedList = NULL;
	STUDENT *current = head;
	while(current != NULL)
	{
		STUDENT *nextNode = current->next;
		if(sortedList == NULL || current->age <= sortedList->age)
		{
			current->next = sortedList;
			sortedList = current;
		}
		else{
			STUDENT *temp = head;
			while(temp->next != NULL && temp->next->age < current->age)
			 temp = temp->next;
			 current->next = temp->next;
			 temp->next = current;
		}
		current = nextNode;
	}
	head = sortedList;

}


void sortMenu()
{
    system("cls");
	int choice, option = 1;

	while(option){
		printf("\n*******Select the sorting you want*******\n\n");
		printf("-------------------------------------------------|\n");
		printf("\t1\t | Sort by name.\n");
		printf("-------------------------------------------------|\n");
		printf("\t2\t | Sort by marks\n");
		printf("-------------------------------------------------|\n");
		printf("\t3\t | Sort by age\n");
		printf("-------------------------------------------------|\n");
		printf("\t4\t | Sort by ID\n");
		printf("-------------------------------------------------|\n");
		printf("\t5\t | Go back to main menu\n");
		printf("-------------------------------------------------|\n");

		printf("Please Enter prefered choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: sortByName();
					displayList(head);
					break;
			case 2: sortByMarks();
					displayList(head);
					break;
			case 3: sortByAge();
					displayList(head);
					break;
			case 4: sortById();
					displayList(head);
					break;
			case 5: displayMenu();
			default: sortMenu();
					break;

	    }

        printf("\nDo you want to continue sorting? if yes, (press 1, otherwise press 0)");
        scanf("%d", &option);

    }
}

void searchMenu()
{
	system("cls");
	int choice, option = 1;
	while(option)
	{
		printf("\n*******CHOOSE THE WAY TO SEARCH*******\n\n");
		printf("-------------------------------------------------|\n");
		printf("\t1\t | search by Name.\n");
		printf("-------------------------------------------------|\n");
		printf("\t2\t | search by ID\n");
		printf("-------------------------------------------------|\n");
		printf("\t3\t | Go back to main menu.\n");
		printf("-------------------------------------------------|\n");
		printf("\nEnter choice of search: ");
		scanf("%d", &choice);

		switch(choice)
		{   int id;
			char name[15];

			case 1:
			    getchar();
			    printf("Enter the new name: ");
			    gets(name);
			    searchByName(head, name);
					break;
			case 2: id = inputID();
				showSingleResult(searchByID(head, id));
					break;
			case 3: displayMenu();
					break;
			default: searchMenu();
					break;
		}
			printf("\n\nDo you want to continue searching? (if yes, press 1, otherwise press 0): ");
			scanf("%d", &option);

	}
}

void displayMenu()
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
		{   int id;

			case 1: initilize(head);
					break;
			case 2: head = addToList(head);
					break;
			case 3: displayList(head);
					break;
			case 4: sortMenu();
					break;
			case 5: searchMenu();
					break;
			case 6: id = inputID();
				edit(head, id);
				break;
			case 7: exit(0);
			default: printf("invalid choice\n");
					break;
		}
	}
}


int inputID() {
    int id;
    printf("Enter student ID: ");
    scanf("%d", &id);
    return id;
}


