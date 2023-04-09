//BREADTH FIRST SEARCH
#include<stdio.h>
#include<stdlib.h>
#define SIZE 40

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

struct queue {
    int items[SIZE];
    int front;
    int rear;
};

struct queue *createqueue()
{
    struct queue *q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(struct queue *q,int item)
{
    if(q->rear == SIZE-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if(q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = item;
    }
}

int isempty(struct queue *q)
{
    if(q->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int dequeue(struct queue *q)
{
    int value;
    if(isempty(q))
    {
        printf("Queue is empty\n");
        value = -1;
    }
    else
    {
        value = q->items[q->front];
        q->front++;
        if(q->front>q->rear)
        {
            printf("Resetting queue\n");
            q->front = q->rear = -1;
        }
    }
    return value;
}

void printqueue(struct queue *q)
{
    int i=q->front;
    if(isempty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue contains\n");
        for(i=q->front;i<q->rear+1;i++)
        {
            printf("%d ",q->items[i]);
        }
    }
}

void bfs(struct Graph *graph,int startvertex)
{
    struct queue *q = createqueue();
    graph->visited[startvertex] = 1;
    enqueue(q,startvertex);
    while(!isempty(q))
    {
        printqueue(q);
        int currentvertex = dequeue(q);
        printf("Visited Vertex: %d\n",currentvertex);
        struct node *temp = graph->arr[currentvertex];
        while(temp)
        {
            int adjvertex = temp->data;
            if(graph->visited[adjvertex] == 0)
            {
                graph->visited[adjvertex] = 1;
                enqueue(q,adjvertex);
            }
            temp = temp->next;
        }
    }
}

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

struct node *createnode(int a)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = a;
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
       //newnode->next = graph->arr[s];
       graph->arr[s] = newnode->next;
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
    int choice,s,d,option,startvertex;
    printf("1. Create Graph\n");
    printf("2. Display Graph\n");
    printf("3. Add edge\n");
    printf("4. Breadth first search\n");
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
                    printf("Press 1 for undirected graph---Press 2 for directed graph\n");
                    scanf("%d",&option);
                    addedge(graph,s,d,option);
                    break;
            case 4: printf("Enter the start vertex\n");
                    scanf("%d",&startvertex);
                    bfs(graph,startvertex);
                    break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
