

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* insert(struct Node* root, int val);
void inorder(struct Node* root);

int main()
{
    struct Node* root = NULL;
    int choice, val;

    printf("\n:: Binary Search Tree ::\n");
    while(1)
    {
        printf("\n****** MENU ******\n");
        printf("1. Insert Node\n2. Display (Inorder Traversal)\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("Node inserted.\n");
                break;
            case 2:
                printf("BST Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Wrong selection! Please try again.\n");
        }
    }
}

struct Node* insert(struct Node* root, int val)
{
    if(root == NULL)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void inorder(struct Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
