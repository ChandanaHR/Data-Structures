//GRAPH REPRESENTATION USING LINKED LIST
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct Graph {
    int vertices;
    struct node **arr;
};

int v;

struct node  *createNode(int a) {
  struct node *newnode = malloc(sizeof(struct node));
  newnode->data = a;
  newnode->next = NULL;
  return newnode;
}

struct Graph *creategraph(int v)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->vertices = v;
    graph->arr = malloc(v*sizeof(struct node *));
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
        while(temp)
        {
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void addedge(struct Graph *graph,int s,int d,int option)
{
    if(option==1)
    {
    struct node *newnode = createNode(d);
    newnode->next = graph->arr[s];
    graph->arr[s] = newnode;
    
    newnode = createNode(s);
    newnode->next = graph->arr[d];
    graph->arr[d] = newnode;
    }
    else if(option ==2)
    {
        struct node *newnode = createNode(d);
        newnode->next = graph->arr[s];
        graph->arr[s] = newnode;
    }
    else
    {
        printf("Invalid option\n");
    }
}

int main()
{
    struct Graph *graph;
    int choice,s,d,option;
    printf("1.Create graph\n");
    printf("2.Display graph\n ");
    printf("3.Add edge\n");
    printf("4.Exit\n");
    while(1)
    {
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the number of vertices\n");
                    scanf("%d",&v);
                    graph = creategraph(v);
                    break;
            case 2: displaygraph(graph);
                    break;
            case 3: printf("Enter the source vertex\n");
                    scanf("%d",&s);
                    printf("Enter the destination vertex\n");
                    scanf("%d",&d);
                    printf("Press 1 for undirected graph---Press 2 for directed graph\n");
                    scanf("%d",&option);
                    addedge(graph,s,d,option);
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0; 
}
