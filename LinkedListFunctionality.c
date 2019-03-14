#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

#include <string.h>
 // A linked list node
struct Node {
    char name[50];

    int age;

    char address[100];
    int yearsOfExperience;
    struct Node * next;
};


/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. */
void push(struct Node ** head_ref, int new_age, char name[50], char address[100], int yearsOfExperience) {
    /* 1. allocate node */
    struct Node * new_node = (struct Node * ) malloc(sizeof(struct Node));

    /* 2. put in the age */
    new_node -> age = new_age;
    new_node -> yearsOfExperience = yearsOfExperience;
    strcpy(new_node -> name, name);
    strcpy(new_node -> address, address);

    /* 3. Make next of new node as head */
    new_node -> next = ( * head_ref);

    /* 4. move the head to point to the new node */
    ( * head_ref) = new_node;
}

/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end */
void append(struct Node ** head_ref, int new_age, char name[50], char address[100], int yearsOfExperience) {
    /* 1. allocate node */
    struct Node * new_node = (struct Node * ) malloc(sizeof(struct Node));

    struct Node * last = * head_ref; /* used in step 5*/

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
        return;
    }

    /* 5. Else traverse till the last node */
    while (last -> next != NULL)
        last = last -> next;

    /* 6. Change the next of last node */
    last -> next = new_node;
    return;
}

/* Checks whether the value x is present in linked list */
int search(struct Node * head, int x, int pos) {
    // Base case
    if (head == NULL)
        return -1;

    // If key is present in current node, return true
    if (head -> age == x)
        return pos;

    // Recur for remaining list
    return search(head -> next, x, ++pos);
}

void printList(struct Node * node) {
    while (node != NULL) {
        printf("[ %d %d %s %s ]->", node -> age, node -> yearsOfExperience, node -> name, node -> address);
        node = node -> next;
    }
}

/* Driver program to test above functions*/
int main() {
    /* Start with the empty list */
    struct Node * head = NULL;


    append( & head, 6, "Name1", "Address1", 10);


    push( & head, 2, "Name2", "Address2", 11);


    push( & head, 3, "Name3", "Address3", 9);


    append( & head, 10, "Name4", "Address4", 2);

    printf("\nSearched age = 10");

    int value = search(head, 1, 0);
    printf("\nPresent at position: %d", value);

    printf("\n Created Linked list is: ");
    printList(head);

    return 0;
}
