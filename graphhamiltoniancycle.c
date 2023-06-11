//DETECT A HAMILTONIAN CYCLE IN UNDIRECTED GRAPH
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
    arr[d][s] = 1;
}

void display(int arr[][v])
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void printcycle(int *path)
{
    for(int i=0;i<v;i++)
    {
        printf("%d ",path[i]);
    }
    printf("%d ",path[0]);
    printf("\n");
}

int check(int a,int arr[][v],int *path,int pos)
{
    if(arr[path[pos-1]][a]==0)
    {
        return 0;
    }
    for(int i=0;i<pos;i++)
    {
        if(path[i]==a)
        {
            return 0;
        }
    }
    return 1;
}

int hamilutil(int arr[][v],int *path,int pos)
{
    if(pos==v)
    {
        if(arr[path[pos-1]][path[0]]==1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    for(int a=1;a<v;a++)
    {
        if(check(a,arr,path,pos))
        {
           path[pos] = a;
           if(hamilutil(arr,path,pos+1)==1)
           {
               return 1;
           }
           path[pos] = -1;
        }
    }
    return 0;
}

int hamilcycle(int arr[][v])
{
    int *path = (int *)malloc(v*sizeof(int));
    for(int i=0;i<v;i++)
    {
        path[i] = -1;
    }
    path[0] = 0;
    if(hamilutil(arr,path,1)==0)
    {
        return 0;
    }
    printcycle(path);
    return 1;
}

int main()
{
    int i,j,choice;
    printf("How many vertices\n");
    scanf("%d",&v);
    int arr[v][v];
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            arr[i][j] = 0;
        }
    }
    printf("----MATRIX REPRESENTATION---- \n");
    printf("1. Add edge\n");
    printf("2. Display graph\n");
    printf("3. Detect hamiltonian cycle\n");
    printf("4. Exit\n");
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
            case 3: if(hamilcycle(arr))
                    {
                        printf("Cycle exists\n");
                    }
                    else
                    {
                        printf("Cycle doesn't exists\n");
                    }
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
