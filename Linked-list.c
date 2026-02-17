

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void insertBegin();
void insertEnd();
void insertAtPosition();
void display();

int main()
{
    int choice;
    printf("\n:: Singly Linked List ::\n");
    while(1)
    {
        printf("\n****** MENU ******\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: insertBegin(); break;
            case 2: insertEnd(); break;
            case 3: insertAtPosition(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Wrong selection! Please try again.\n");
        }
    }
}

void insertBegin()
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    int val;
    printf("Enter value to insert: ");
    scanf("%d",&val);
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    printf("Inserted at beginning.\n");
}

void insertEnd()
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head;
    int val;
    printf("Enter value to insert: ");
    scanf("%d",&val);
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL) head = newNode;
    else
    {
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted at end.\n");
}

void insertAtPosition()
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head;
    int val, pos, i;
    printf("Enter value to insert: ");
    scanf("%d",&val);
    printf("Enter position to insert: ");
    scanf("%d",&pos);

    newNode->data = val;

    if(pos == 1)
    {
        newNode->next = head;
        head = newNode;
        printf("Inserted at position %d.\n", pos);
        return;
    }

    for(i=1;i<pos-1 && temp!=NULL;i++)
        temp = temp->next;

    if(temp == NULL) printf("Invalid position.\n");
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted at position %d.\n", pos);
    }
}

void display()
{
    struct Node *temp = head;
    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Linked list: ");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
