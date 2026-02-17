


#include <stdio.h>
#include <stdlib.h>

#define SIZE 50
int arr[SIZE];
int n = 0;

void insert();
void deleteElement();
void search();
void display();

int main()
{
    int choice;

    while(1)
    {
        printf("\n--- ARRAY MENU ---\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: insert(); break;
            case 2: deleteElement(); break;
            case 3: search(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice, try again.\n");
        }
    }
}

void insert()
{
    if(n >= SIZE)
    {
        printf("Array full! Cannot insert.\n");
        return;
    }
    int val;
    printf("Enter value to insert: ");
    scanf("%d",&val);
    arr[n++] = val;
    printf("Insertion successful.\n");
}

void deleteElement()
{
    if(n == 0)
    {
        printf("Array empty! Cannot delete.\n");
        return;
    }
    int pos,i;
    printf("Enter position to delete (0 to %d): ", n-1);
    scanf("%d",&pos);
    if(pos < 0 || pos >= n)
    {
        printf("Invalid position.\n");
        return;
    }
    for(i = pos; i < n-1; i++)
        arr[i] = arr[i+1];
    n--;
    printf("Deletion successful.\n");
}

void search()
{
    if(n == 0)
    {
        printf("Array empty! Cannot search.\n");
        return;
    }
    int key,i;
    printf("Enter value to search: ");
    scanf("%d",&key);
    for(i = 0; i < n; i++)
        if(arr[i] == key)
        {
            printf("Value found at position %d.\n",i);
            return;
        }
    printf("Value not found.\n");
}

void display()
{
    if(n == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    int i;
    printf("Array elements: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
