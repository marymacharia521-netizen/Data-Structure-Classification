


#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int graph[MAX][MAX];
int n;

void createGraph();
void displayGraph();

int main()
{
    int choice;
    printf("\n:: Graph Using Adjacency Matrix ::\n");

    while(1)
    {
        printf("\n****** MENU ******\n");
        printf("1. Create Graph\n2. Display Graph\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: createGraph(); break;
            case 2: displayGraph(); break;
            case 3: exit(0);
            default: printf("Wrong selection! Please try again.\n");
        }
    }
}

void createGraph()
{
    int i, j;
    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &n);

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            printf("Edge from %d to %d (0/1): ", i, j);
            scanf("%d", &graph[i][j]);
        }

    printf("Graph created successfully.\n");
}

void displayGraph()
{
    int i,j;
    printf("Adjacency Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}
