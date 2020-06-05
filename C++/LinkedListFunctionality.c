#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

#define NAMESIZE 50
#define ADDRESSSIZE 100

#include <string.h>
 // A linked list node
 typedef struct Node {
    char name[NAMESIZE];

    int age;

    char address[ADDRESSSIZE];
    int yearsOfExperience;
    struct Node* next;
}Node;

//Prototypes

bool push( Node**, int , char [], char [], int);
bool append( Node** , int , char [], char [], int );
int input(int* , int* , char [], char []);
int search(Node* , int , int );
bool reverse(Node** );
void printList(Node* );
bool delList(Node **);
int sampleLinkedList();
bool delete_node(Node **, int , Node **);




int main() {
    /* Start with the empty list */
    Node* head = NULL;
    int choice = 0;
    int age = 0, yearsOfExperience = 0;
    char name[50];
    char address[100];
    int key = 0;
    do{
        printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", "1. Create a linked list", "2. Insert an item at the beginning",
               "3. Insert an item at the end", "4. Search an item based on age", "5. Reverse the list", "6. Print the list","7. Delete an item from list", "0. Exit");
        scanf("%d", &choice);
        switch(choice){
            case 1: sampleLinkedList();
                break;

            case 2: input(&age, &yearsOfExperience, name, address);
                push(&head, age, name, address, yearsOfExperience);
                break;

            case 3: input(&age, &yearsOfExperience, name, address);
                append(&head, age, name, address, yearsOfExperience);
                break;

            case 4:
                printf("\nEnter the age to be searched: ");
                scanf("%d", &key);
                int index = search(head, key, 0);
                if(index == -1){
                    printf("Element not found");
                }
                else{
                    printf("Element found at position %d", index + 1);
                }
                break;



            case 5: reverse(&head);
                printList(head);
                break;

            case 6: printList(head);
                break;

            case 7:
                printf("\nEnter the age to be deleted: ");
                scanf("%d", &key);
                if( delete_node(&head, key, NULL) == true){
                    printf("Item deleted sucessfully :)\n");
                }else
                    printf("Item not not found or not deleted :(\n");
                break;


            case 0:  delList(&head);
                exit(EXIT_SUCCESS);

            default: printf("You've entered a wrong number\n");

        }

    }while(choice!=0);
    return 0;
}


/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. */
bool push( Node** head_ref, int new_age, char name[NAMESIZE], char address[ADDRESSSIZE], int yearsOfExperience) {
    /* 1. allocate Node*/
     Node* new_node = (Node* ) malloc(sizeof(Node));
     if(new_node == NULL)
         return false;

    /* 2. put in the age */
    new_node -> age = new_age;
    new_node -> yearsOfExperience = yearsOfExperience;

    //preventing buffer overflow using strncpy
    strncpy(new_node -> name, name, sizeof(char) * NAMESIZE);
    strncpy(new_node -> address, address, sizeof(char) * ADDRESSSIZE);

    /* 3. Make next of new node as head */
    new_node -> next = ( * head_ref);

    /* 4. move the head to point to the new Node*/
    ( * head_ref) = new_node;
    return true;
}

/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end */
bool append( Node** head_ref, int new_age, char name[NAMESIZE], char address[ADDRESSSIZE], int yearsOfExperience) {
    /* 1. allocate Node*/
    Node* new_node = (Node* ) malloc(sizeof(Node));
    if(new_node == NULL)
        return false;

    Node* last = * head_ref; /* used in step 5*/

    /* 2. put in the age */
    new_node -> age = new_age;
    new_node -> yearsOfExperience = yearsOfExperience;
    strcpy(new_node -> name, name);
    strcpy(new_node -> address, address);

    /* 3. This new node is going to be the last node, so make next
    	of it as NULL*/
    new_node -> next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if ( * head_ref == NULL) {
        * head_ref = new_node;
        return true;
    }

    /* 5. Else traverse till the last Node*/
    while (last -> next != NULL)
        last = last -> next;

    /* 6. Change the next of last Node*/
    last -> next = new_node;
    return true;
}

/* Checks whether the value x is present in linked list */
int search(Node* head, int x, int pos) {
    // Base case
    if (head == NULL)
        return -1;

    // If key is present in current node, return true
    if (head -> age == x)
        return pos;

    // Recur for remaining list
    return search(head -> next, x, ++pos);
}

/* Function to reverse the linked list */
bool reverse(Node** head_ref)
{
    Node* first;
    Node* rest;

    /* empty list */
    if (*head_ref == NULL)
       return false;

    first = *head_ref;
    rest  = first->next;

    if (rest == NULL)
       return true;

    reverse(&rest);
    first->next->next  = first;

    first->next  = NULL;

    *head_ref = rest;
}

void printList(Node* node) {
    printf("\n The list is printed in the order: age, years of experience, name, address\n");
    while (node != NULL) {
        printf("[ %d %d %s %s ]->", node -> age, node -> yearsOfExperience, node -> name, node -> address);
        node = node -> next;
    }
    printf("\n");
}

bool delList(Node **head){
    if(*head == NULL)
        return  true;

    Node *current = *head;
    *head = (*head)->next;
    free(current);
    delList(&(*head));

}

/* Driver program to test above functions*/
int sampleLinkedList(){
    Node* head = NULL;

    append( &head, 6, "Name1", "Address1", 10);


    push( &head, 2, "Name2", "Address2", 11);


    push( &head, 3, "Name3", "Address3", 9);


    append( &head, 10, "Name4", "Address4", 2);

    printf("\nSearched age = 10");

    int value = search(head, 10, 0);
    printf("\nPresent at position: %d", value);

    printf("\n Created Linked list is: ");
    printList(head);

    printf("\nThe reversed list is:");
    reverse(&head);
    printList(head);
    printf("\n");
    delList(&head);
}


bool delete_node(Node **head, int age , Node **previous){
  // Base case
    if (*head == NULL)
        return false;

    Node *next_node = (*head) ->next, *temp;
    // If key is present in current node, delete current node and return true
    if ((*head) -> age == age){
	    //ack confirmation for deletion, since there can exist several with the same age.
	    char response[3];
	    printf("WARMING: Do you really want delete employee with name: %s living in %s [No/yes]?", (*head) ->name, (*head) ->address);
	     fflush(stdout);
	     scanf("%s", &response);
	    if(response[0] == 'y' || response[0] == 'Y'){
		//deleting happening here.

		    if(previous != NULL && *previous != NULL) {

                (*previous)->next = next_node;
            } else {
                previous = head; //just to reference previous to non-null value
                *previous = next_node;
            }
		    //delete node
		    free(*head);

		    //update head
		    head = &(*previous);

		    return true;
	    }
    }

    // Recur for remaining list
    return delete_node(&((*head) -> next), age, &(*head));


}



int input(int* age, int* yearsOfExperience, char name[], char address[]){
    printf("Enter the following fields respectively: 1) Name, 2) Address, 3) Age, 4) Years of Experience:\n");
    scanf("%s%s%d%d", name, address, age, yearsOfExperience);
}
