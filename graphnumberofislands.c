n this problem, an island is nothing but a group of connected one's in Boolean 1D, 2D or multidimensional (n-D) array. In this problem, we have to find the number of islands (group of 1's) in a boolean matrix. Note that 1 denotes land.

The statement can be rewritten as follows.

Given a boolean 2D matrix in which 1's denotes land and 0's denotes water. In this matrix, we have to count the number of islands. An island is a place that is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. Assume all four edges of the grid are all surrounded by water.
  
  
#include<stdio.h>
#include<stdlib.h>

int v;

void addedge(int arr[][v])
{
    int s,d;
    printf("Enter the source vertex\n");
    scanf("%d",&s);
    printf("Enter the destination vertex\n");
    scanf("%d",&d);
    arr[s][d] = 1;
}

void display(int arr[][v])
{
    int i,j;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void dfs(int arr[][v],int x,int y)
{
    if(x>=0 && y>=0 && x<v && y<v && arr[x][y]==1)
    {
        arr[x][y] = 2;
        dfs(arr,x,y+1);
        dfs(arr,x,y-1);
        dfs(arr,x+1,y);
        dfs(arr,x-1,y);
    }
}

void islands(int arr[][v])
{
    int i,j,noofislands=0;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(arr[i][j]==1)
            {
                dfs(arr,i,j);
                noofislands++;
            }
        }
    }
    printf("No of islands--> %d ",noofislands);
}

int main()
{
    int choice,i,j;
    printf("Enter the number of vertices\n");
    scanf("%d",&v);
    int arr[v][v];
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            arr[i][j] = 0;
        }
    }
    printf("1. Add edge\n");
    printf("2. Display graph\n");
    printf("3. Detect number of islands\n");
    printf("4. Exit\n");
    while(1)
    {
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : addedge(arr);
                     break;
            case 2:  display(arr);
                     break;
            case 3 : islands(arr);
                     break;
            case 4 : exit(0);
            default : printf("Invalid choice\n");
        }
    }
    return 0;
}
