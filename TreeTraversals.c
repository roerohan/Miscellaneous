#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node
{
	int key;
	struct Node* left;
	struct Node* right;
}Node;

Node *newNode(int item)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	if(temp == NULL)
	    return NULL;

	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}



 Node* insert( Node* node, int key)
{
	if (node == NULL) return newNode(key);


	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

Node* search(Node* root, int key)
{
    if (root == NULL || root->key == key)
       return root;

    if (root->key < key)
       return search(root->right, key);

    return search(root->left, key);
}

bool del(Node **root){
    if(*root == NULL)
        return true;

    Node *current = *root;
    Node *rootRight = (*root)->right;
    Node *rootLeft = (*root)->left;

    //delete root
    free(current);

    //delete left tree
    del(&rootLeft);

    //delete right tree
    del(&rootRight);
}

void printPostorder(Node* node)
{
	if (node == NULL)
		return;

	printPostorder(node->left);

	printPostorder(node->right);

	printf("%d ", node->key);
}


void printInorder(Node* node)
{
	if (node == NULL)
		return;


	printInorder(node->left);


	printf("%d ", node->key);


	printInorder(node->right);
}


void printPreorder(Node* node)
{
	if (node == NULL){
		return;
    }


	printf(" %d ", node->key);

	printPreorder(node->left);


	printPreorder(node->right);
}


int createSampleTree()
{
	Node *root = newNode(1);
	root->left			 = newNode(2);
	root->right		 = newNode(3);
	root->left->left	 = newNode(4);
	root->left->right = newNode(5);

	printf("\nPreorder traversal of binary tree is \n");
	printPreorder(root);

	printf("\nInorder traversal of binary tree is \n");
	printInorder(root);

	printf("\nPostorder traversal of binary tree is \n");
	printPostorder(root);
    del(&root);

	getchar();
	return 0;
}

int main(){
    int choice;
        Node *root = NULL;
        Node* searchNode = NULL;
        int key;
    do{
        printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", "Choose one of the following options:",
        "1. Add a Node to the tree.",
        "2. Perform preorder traversal.",
        "3. Perform inorder traversal.",
        "4. Perform postorder traversal.",
        "5. Search an item in the tree.",
        "6. Create sample tree.",
        "0. Exit."
        );
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\nEnter the value to be inserted: ");
                int value;
                scanf("%d", &value);
                if (root==NULL){
                    root = insert(root, value);
                }
                else{
                    insert(root, value);
                }
                break;
            case 2:
                printPreorder(root);
                break;
            case 3:
                printInorder(root);
                break;
            case 4:
                printPostorder(root);
                break;
            case 5:
            printf("\nEnter item to search:\n");
            scanf("%d", &key);
            searchNode = search(root, key);
            if (searchNode == NULL) {
                printf("Not Found");
            } else if (searchNode->key == key) {
                printf("Found");
            }
            break;

            case 6: createSampleTree();
            break;

            case 0:
            printf("Exiting program. Bye :) \n");
            del(&root);
            exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    }while(choice!=0);
}
