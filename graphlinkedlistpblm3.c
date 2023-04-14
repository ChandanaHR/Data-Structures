//DEPTH FIRST SEARCH
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct Graph {
    int vertices;
    struct node **arr;
    int *visited;
};

int v;

struct Graph *creategraph(int v)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->vertices = v;
    graph->arr = malloc(v*sizeof(struct node *));
    graph->visited = malloc(v*sizeof(int));
    for(int i=0;i<v;i++)
    {
        graph->arr[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void display(struct Graph *graph)
{
    int i;
    for(i=0;i<graph->vertices;i++)
    {
        struct node *temp = graph->arr[i];
        printf("Vertex : %d->",i);
        while(temp)
        {
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void addedge(struct Graph *graph,int s,int d,int option)
{
    if(option == 1)
    {
       struct node *newnode = createnode(d);
       newnode->next = graph->arr[s];
       graph->arr[s] = newnode;
       
       newnode = createnode(s);
       newnode->next = graph->arr[d];
       graph->arr[d] = newnode;
    }
    else if(option == 2)
    {
       struct node *newnode = createnode(d);
       newnode->next = graph->arr[s];
       graph->arr[s] = newnode;
    }
    else
    {
        printf("Invalid option\n");
    }
}

void dfs(struct Graph *graph,int startvertex)
{
    struct node *temp = graph->arr[startvertex];
    graph->visited[startvertex] = 1;
    printf("Visited vertex: %d ",startvertex);
    while(temp != NULL)
    {
        int connectedvertex = temp->data;
        if(graph->visited[connectedvertex] == 0)
        {
            dfs(graph,connectedvertex);
        }
        temp = temp->next;
    }
}

int main()
{
    int choice,option,s,d,startvertex;
    struct Graph *graph;
    printf("1. Create Graph\n");
    printf("2. Display Graph\n");
    printf("3. Add edge\n");
    printf("4. Depth first search\n");
    printf("5. Exit\n");
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
            case 2: display(graph);
                    break;
            case 3: printf("Enter the source vertex\n");
                    scanf("%d",&s);
                    printf("Enter the destination vertex\n");
                    scanf("%d",&d);
                    printf("Press 1 for undirected graph: Press 2 for directed graph\n");
                    scanf("%d",&option);
                    addedge(graph,s,d,option);
                    break;
            case 4: printf("Enter the startvertex\n");
                    scanf("%d",&startvertex);
                    dfs(graph,startvertex);
                    break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
