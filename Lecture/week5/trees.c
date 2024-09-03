#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
typedef struct node
{
    int value;          // The data stored in the node
    struct node *left;  // Pointer to the left child
    struct node *right; // Pointer to the right child
} node;

// Function to create a new node
node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
node *insertNode(node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->value)
    {
        root->left = insertNode(root->left, value);
    }
    else
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Function to perform an in-order traversal of the binary tree
void inOrderTraversal(node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);  // Traverse left subtree
        printf("%d ", root->value);    // Print the value of the current node
        inOrderTraversal(root->right); // Traverse right subtree
    }
}

// Main function to demonstrate the tree operations
int main()
{
    node *root = NULL;

    // Insert nodes into the binary tree
    root = insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 8);

    // Print the nodes in in-order traversal
    printf("In-order traversal of the binary tree:\n");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
