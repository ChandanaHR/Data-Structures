//FINDING TRANSITIVE CLOSURE OF A GRAPH 
#include<stdio.h>
#include<stdlib.h>

int n;

void addedge(int arr[][n],int option)
{
    int s,d;
    if(option == 1)
    {
        printf("Enter the source vertex\n");
        scanf("%d",&s);
        printf("Enter the destination vertex\n");
        scanf("%d",&d);
        arr[s][d] = 1;
    }
    else if(option == 2)
    {
        printf("Enter the source vertex\n");
        scanf("%d",&s);
        printf("Enter the destination vertex\n");
        scanf("%d",&d);
        arr[s][d] = 1;
        arr[d][s] = 1;
    }
    else
    {
        printf("Invalid option\n");
    }
}

void displaygraph(int arr[][n])
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void transitiveclosure(int arr[][n])
{
    int result[n][n],i,j,k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            result[i][j] = arr[i][j];
        }
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                result[i][j] = (result[i][j] || (result[i][k] && result[k][j]));
            }
        }
    }
    printf("\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int choice,i,j,option;
    printf("How many vertices\n");
    scanf("%d",&n);
    int arr[n][n];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            arr[i][j] = 0;
        }
    }
    printf("-----MATRIX REPRESENTATION-----\n");
    printf("1. Add edge\n");
    printf("2. Display graph\n");
    printf("3. Find transitive closure of a graph\n");
    printf("4. Exit\n");
    while(1)
    {
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Press 1 for directed graph\t Press 2 for undirected graph\n");
                    scanf("%d",&option);
                    addedge(arr,option);
                    break;
            case 2: displaygraph(arr);
                    break;
            case 3: transitiveclosure(arr);
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
