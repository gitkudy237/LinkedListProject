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
STUDENT *current;

void initilize(STUDENT *s);
void print_header();
void display(STUDENT *s);
void displayList(STUDENT *s);
 void sortByMarks();
void sortById();
void sortByAge();
void searchByName(STUDENT *head, char input[15]);

// searchByID will return a pointer to the target node.
// The reason is to be able to maniplulate the output flexibly.
// To see the output, use the display function declared above.
STUDENT *searchByID(STUDENT *s, int key); 
void removeByID(STUDENT *s, int key);
void Edit(STUDENT *head, int key);
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
	newnode = (STUDENT*) malloc(sizeof(STUDENT));
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

void searchByName(STUDENT *head, char input[15]){
    
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
        printf("List is empty please.......\n");
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

void addStudent()
{
	int option = 1;
	while(option){
	
	STUDENT *temp;
	temp = (STUDENT*)malloc(sizeof(STUDENT));
	printf("\nEnter Id: ");
	scanf("%d", &temp->id);
	printf("\nEnter name: ");
	getchar();
	gets(temp->name);
	printf("\nEnter the age: ");
	scanf("%d",  &temp->age);
	printf("\nEnter marks: ");
	scanf("%f", &temp->mark);
	temp->next = NULL;
	if(head == NULL){
		head = temp;
		return;
	}
	else{
		STUDENT *ptr = head;
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
	printf("Do you still want to add a student? If yes( press 1), no( press 0)");
	scanf("%d", &option);  
  }
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
		return;
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
	displayList(head);
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
	displayList(head);
}

void sortedListByMarks()
{	sortByMarks();
	displayList(head);
}

void sortedListByName()
{
	 sortByName();
	displayList(head);
}

void sort()
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
		printf("\t5\t | **to exit sort***\n");
		printf("-------------------------------------------------|\n");
		
		printf("Please Enter prefered choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: sortedListByName();
					break;
			case 2: sortedListByMarks();
					break;
			case 3: sortByAge();
					break;
			case 4: sortById();
					break;
			case 5: exit(0);
			default: printf("\nsort option is invalid!!\n");
					break;
					
	}
	printf("\nDo you want to continue sorting? if yes, press 1, otherwise press 0");
	scanf("%d", &option);

  }
}

void search()
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
		printf("\t3\t | **to exit the search");
		
		printf("\nEnter choice of search: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: searchByName(head, "no");
					break;
			case 2: searchByID(head, 11);
			case 3: exit(0);
			default: printf("\nsearch option is invalid!! you may stop searching by pressing 3\n");
					break;
		}
		printf("\n\nDo you want to continue searching? (if yes, press 1, otherwise press 0)");
		scanf("%d", &option);
		
	}
}