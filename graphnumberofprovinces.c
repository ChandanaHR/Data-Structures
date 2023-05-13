Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]
Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.
  
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
    arr[d][s] = 1;
}

void display(int arr[][n])
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

void dfs(int curr,int arr[][n],int *visited)
{
    int i;
    visited[curr] = 1;
    for(i=1;i<=n;i++)
    {
        if(arr[curr][i]==1 && visited[i]==0)
        {
            dfs(i,arr,visited);
        }
    }
}

void numberofprovinces(int arr[][n])
{
    int i,provinces=0;
    int *visited = (int *)malloc(n*sizeof(int));
    for(i=1;i<=n;i++)
    {
        visited[i] = 0;
    }
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            provinces++;
            dfs(i,arr,visited);
        }
    }
    printf("Number of provinces in given graph is---%d",provinces);
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
    printf("----MATRIX REPRESENTATION----\n");
    printf("1. Add edge\n");
    printf("2. Display graph\n");
    printf("3. Find number of provinces\n");
    printf("4. Exit\n");
    while(1)
    {
        printf("\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: addedge(arr);
                    break;
            case 2: display(arr);
                    break;
            case 3: numberofprovinces(arr);
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
