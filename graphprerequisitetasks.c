There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.


Example 1:

Input: 
N = 4, P = 3
prerequisites = {{1,0},{2,1},{3,2}}
Output:
Yes
Explanation:
To do task 1 you should have completed
task 0, and to do task 2 you should 
have finished task 1, and to do task 3 you 
should have finished task 2. So it is possible.
Example 2:

Input:
N = 2, P = 2
prerequisites = {{1,0},{0,1}}
Output:
No
Explanation:
To do task 1 you should have completed
task 0, and to do task 0 you should
have finished task 1. So it is impossible.
  
#include<stdio.h>
#include<stdlib.h>

int v;
int p;

struct node {
    int data;
    struct node *next;
};

struct Graph {
    int vertices;
    struct node **array;
    int *visited;
    int *recursionstack;
};

struct Graph *creategraph(int v)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->vertices = v;
    graph->array = malloc(v*sizeof(struct node *));
    graph->visited = malloc(v*sizeof(int));
    graph->recursionstack = malloc(v*sizeof(int));
    for(int i=0;i<v;i++)
    {
        graph->array[i] = NULL;
        graph->visited[i] = 0;
        graph->recursionstack[i] = 0;
    }
    return graph;
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
    newnode->next = graph->array[s];
    graph->array[s] = newnode;
}

void display(struct Graph *graph)
{
    for(int i=0;i<graph->vertices;i++)
    {
        struct node *temp = graph->array[i];
        printf("Vertex: %d->",i);
        while(temp)
        {
            printf("%d-> ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void reverse(struct Graph *graph)
{
    struct node *prevnode = (struct node *)malloc(sizeof(struct node));
    struct node *currnode = (struct node *)malloc(sizeof(struct node));
    struct node *head = (struct node *)malloc(sizeof(struct node));
    for(int i=0;i<graph->vertices;i++)
    {
        head = graph->array[i];
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
            graph->array[i] = head;
        }
    }
}

int dfsdetectcycle(struct Graph *graph,int node)
{
    if(graph->recursionstack[node]==1)
    {
        return 1; //there exists cycle
    }
    if(graph->visited[node]==1)
    {
        return 0;  //that node has already been visited
    }
    graph->visited[node]=1;
    graph->recursionstack[node]=1;
    struct node *temp = graph->array[node];
    while(temp!=NULL)
    {
        if(dfsdetectcycle(graph,temp->data))
        {
            return 1;
        }
        temp = temp->next;
    }
    graph->recursionstack[node] = 0;
    return 0;
}

int prerequisitetask(int arr[][p])
{
    struct Graph *graph;
    graph =  creategraph(v);
    for(int i=0;i<p;i++)
    {
        addedge(graph,arr[i][0],arr[i][1]);
    }
    reverse(graph);
    display(graph);
    for(int i=0;i<v;i++)
    {
        if(dfsdetectcycle(graph,i))
        {
            return 1;  //there exists cycle
        }
    }
    return 0;
}

int main()
{
    printf("Enter the total number of tasks\n");
    scanf("%d",&v);
    printf("Enter the prerequiste value\n");
    scanf("%d",&p);
    int arr[p][p];
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<2;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int a = prerequisitetask(arr);
    if(a==0)
    {
        printf("All the tasks has been completed and there is no cycle\n");
    }
    else
    {
        printf("There exists cycle\n");
    }
}
