//PROBLEM STATEMENT - DETECT A CYCLE IN GRAPH USING DISJOINT SET UNIT (UNION-FIND ALGORITHM)
/* Disjoint set - Two or more set with nothing in common A=[1 2 3] B=[4 5] A intersection B is Null
Absolute root - A=[1 2 3] are indexes with values [-1 -1 -1] absolute root of 1 is 1 bcz its value is -1, absolute root of 2 is 2 bcz its value is -1
Suppose A=[1 2 3] are indexes with values [2 -1 -1] absolute root of 1 is 2 and absolute root of 2 is 2 only bcz its value is -1
FIND(i,j) - If absolute root of i and j is same then it belongs to same set here in this case also if absolute root of i and j is same then it forms a cycle in graph*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int data;
    struct node *next;
};

struct Graph {
    int vertices;
    struct node **arr;
};

int v;

struct Graph *creategraph(int v)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->vertices = v;
    graph->arr = (struct node **)malloc(v*sizeof(struct node *));
    for(int i=0;i<v;i++)
    {
        graph->arr[i] = NULL;
    }
    return graph;
}

void displaygraph(struct Graph *graph)
{
    int i;
    for(i=0;i<graph->vertices;i++)
    {
        struct node *temp = graph->arr[i];
        printf("Vertex: %d->",i);
        while(temp != NULL)
        {
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

struct node *createnode(int d)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = NULL;
    return newnode;
}

int find(int *parent,int i)
{
    if(parent[i] == -1)
    {
        return i;
    }
    return find(parent,parent[i]);
}

void Union(int *parent,int s,int d)
{
    parent[s] = d;
}


void addedge(struct Graph *graph,int s,int d)
{
    struct node *newnode = createnode(d);
    newnode->next = graph->arr[s];
    graph->arr[s] = newnode; 
    
}

int iscycle(struct Graph *graph)
{
    int *parent = (int *)malloc(v * sizeof(int));
    for(int i=0;i<v;i++)
    {
        parent[i] = -1;
    }
    for(int i=0;i<graph->vertices;i++)
    {
        struct node *temp = graph->arr[i];
        printf("\n");
        while(temp != NULL)
        {
            printf("%d\n",temp->data);
            int x = find(parent,i);
            printf("%d\n",x);
            int y = find(parent,temp->data);
            printf("%d\n",y);
            if(x==y && (x!=-1 && y!=-1))
            {
                return 1;
            }
            Union(parent,x,y);
            for(int i=0;i<v;i++)
            {
                printf("%d ",parent[i]);
            }
            temp = temp->next;
        }
    }
    return 0;
}


int main()
{
    struct Graph *graph;
    int choice,s,d;
    printf("Enter the number of vertices\n");
    scanf("%d",&v);
    printf("\n");
    printf("1. Create graph\n");
    printf("2. Display graph\n");
    printf("3. Add edge\n");
    printf("4. Detect cycle\n");
    printf("5. Exit\n");
    while(1)
    {
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: graph = creategraph(v);
                    break;
            case 2: displaygraph(graph);
                    break;
            case 3: printf("Enter the source vertex\n");
                    scanf("%d",&s);
                    printf("Enter the destination vertex\n");
                    scanf("%d",&d);
                    addedge(graph,s,d);
                    break;
            case 4: if(iscycle(graph))
                    {
                        printf("yes\n");
                    }
                    else
                    {
                        printf("no\n");
                    }
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
