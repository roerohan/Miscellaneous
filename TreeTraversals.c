#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A binary tree node has key, pointer to left child
and a pointer to right child */
struct node
{
	int key;
	struct node* left;
	struct node* right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}



/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;

    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}
/* Given a binary tree, print its nodes according to the
"bottom-up" postorder traversal. */
void printPostorder(struct node* node)
{
	if (node == NULL)
		return;

	// first recur on left subtree
	printPostorder(node->left);

	// then recur on right subtree
	printPostorder(node->right);

	// now deal with the node
	printf("%d ", node->key);
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the key of node */
	printf("%d ", node->key);

	/* now recur on right child */
	printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node)
{
	if (node == NULL){
		return;
    }

	/* first print key of node */
	printf("-%d-", node->key);
	/* then recur on left sutree */
	printPreorder(node->left);

	/* now recur on right subtree */
	printPreorder(node->right);
}

/* Driver program to test above functions*/
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
        printf("\n%s\n%s\n%s\n%s\n%s\n%s\n", "Choose one of the following options:",
        "1. Create a sample tree.",
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
                root = insert(root, 50);
                insert(root, 30);
                insert(root, 20);
                insert(root, 40);
                insert(root, 70);
                insert(root, 60);
                insert(root, 80);
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
            printf("Exitting program. Bye :) \n");
            exit(0);
            break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    }while(choice!=0);
}
