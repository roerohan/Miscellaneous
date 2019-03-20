#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int key;
	struct node* left;
	struct node* right;
};

struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}



struct node* insert(struct node* node, int key)
{
	if (node == NULL) return newNode(key);


	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

struct node* search(struct node* root, int key)
{
    if (root == NULL || root->key == key)
       return root;

    if (root->key < key)
       return search(root->right, key);

    return search(root->left, key);
}
void printPostorder(struct node* node)
{
	if (node == NULL)
		return;

	printPostorder(node->left);

	printPostorder(node->right);

	printf("%d ", node->key);
}


void printInorder(struct node* node)
{
	if (node == NULL)
		return;


	printInorder(node->left);


	printf("%d ", node->key);


	printInorder(node->right);
}


void printPreorder(struct node* node)
{
	if (node == NULL){
		return;
    }


	printf("-%d-", node->key);

	printPreorder(node->left);


	printPreorder(node->right);
}


int createSampleTree()
{
	struct node *root = newNode(1);
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

	getchar();
	return 0;
}

int main(){
    int choice;
        struct node *root = NULL;
        struct node* searchNode = NULL;
        int key;
    do{
        printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", "Choose one of the following options:",
        "1. Add a node to the tree.",
        "2. Perform preorder traversal.",
        "3. Perform inorder traversal.",
        "4. Perform postorder traversal.",
        "5. Search an item in the tree.",
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
            scanf("%d", &key);
            searchNode = search(root, key);
            if (searchNode == NULL) {
                printf("Not Found");
            } else if (searchNode->key == key) {
                printf("Found");
            }
            break;
            case 0:
            printf("Exiting program. Bye :) \n");
            exit(0);
            break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    }while(choice!=0);
}
