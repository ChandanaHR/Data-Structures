//DETECT CYCLE IN UNDIRECTED GRAPH USING DFS(depth first search)
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct Graph {
    int vertices;
    int *visited;
    struct node **arr;
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
    for(int i=0;i<graph->vertices;i++)
    {
        struct node *temp = graph->arr[i];
        printf("Vertex : %d->",i);
        while(temp)
        {
            printf("%d ->",temp->data);
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

void addedge(struct Graph *graph,int s,int d)
{
    struct node *newnode = createnode(d);
    newnode->next = graph->arr[s];
    graph->arr[s] = newnode;
    
    newnode = createnode(s);
    newnode->next = graph->arr[d];
    graph->arr[d] = newnode;
    
}

void reverse(struct Graph *graph)
{
    struct node *prevnode = (struct node *)malloc(sizeof(struct node));
    struct node *currnode = (struct node *)malloc(sizeof(struct node));
    struct node *head = (struct node *)malloc(sizeof(struct node));
    for(int i=0;i<graph->vertices;i++)
    {
        head = graph->arr[i];
        if(head != NULL)
        {
            prevnode = head;
            head = head->next;
            currnode = head;
            prevnode->next = NULL;
            while(head != NULL)
            {
                head = head->next;
                currnode->next = prevnode;
                prevnode = currnode;
                currnode = head;
            }
            head = prevnode;
            graph->arr[i] = head;
        }
    }
}

int dfs(int node,int parent,struct Graph *graph)
{
    graph->visited[node] = 1;
    struct node *curr = graph->arr[node];
    while(curr != NULL)
    {
        if(graph->visited[curr->data]==0)
        {
            if(dfs(curr->data,node,graph))
            {
                return 1;
            }
        }
        else if(curr->data != parent)
        {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

int detectcycle(struct Graph *graph)
{
    for(int i=0;i<v;i++)
    {
        if(graph->visited[i]==0)
        {
            if(dfs(i,-1,graph))
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int choice,s,d;
    struct Graph *graph;
    printf("1. Create graph\n");
    printf("2. Display graph\n");
    printf("3. Add edge\n");
    printf("4. Reverse\n");
    printf("5. Detect cycle\n");
    printf("6. Exit\n");
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
                    addedge(graph,s,d);
                    break;
            case 4: reverse(graph);
                    break;
            case 5: int a = detectcycle(graph);
                    if(a==1)
                    {
                        printf("Cycle exists\n");
                    }
                    else
                    {
                        printf("Cycle doesn't exists\n");
                    }
            case 6: exit(0);
            default : printf("Invalid choice\n");
        }
    }
}
