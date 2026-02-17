#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int queue[SIZE];
int front=-1, rear=-1;

void enqueue();
void dequeue();
void display();

int main()
{
    int choice;
    printf("\n:: Queue using Array ::\n");
    while(1)
    {
        printf("\n****** MENU ******\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Wrong selection! Please try again.\n");
        }
    }
}

void enqueue()
{
    int val;
    if(rear == SIZE-1)
    {
        printf("Queue is Full! Cannot insert.\n");
        return;
    }
    printf("Enter value to enqueue: ");
    scanf("%d",&val);
    if(front==-1) front=0;
    queue[++rear] = val;
    printf("Enqueue successful.\n");
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue is Empty! Cannot delete.\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front++]);
    if(front > rear) front = rear = -1; // Reset if queue empty
}

void display()
{
    if(front == -1 || front > rear)
    {
        printf("Queue is Empty.\n");
        return;
    }
    int i;
    printf("Queue elements: ");
    for(i=front;i<=rear;i++)
        printf("%d ",queue[i]);
    printf("\n");
}
