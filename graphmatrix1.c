//GRAPH PROBLEM 1 USING MATRIX
#include<stdio.h>
#include<stdlib.h>
int n;

void addedge(int arr[][n])
{
    int s,d;
    printf("Enter the source vertex\n");
    scanf("%d",&s);
    printf("Enter the destination vertex\n");
    scanf("%d",&d);
    arr[s][d] = 1;
}

void display(int arr[][n])
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            //printf("%d ",arr[i][j]);
            if(arr[i][j] == 1)
            {
                printf("%d-->%d\n",i,j);
            }
        }
        printf("\n");
    }
}

int main()
{
    int choice,i,j;
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
    printf("---MATRIX GRAPH REPRESENTATION---\n");
    printf("1. Add edge\n");
    printf("2. Display graph\n");
    printf("3. Exit\n");
    while(1)
    {
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: addedge(arr);
                    break;
            case 2: display(arr);
                    break;
            case 3: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
