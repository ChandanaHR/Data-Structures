//GRAPH REPRESENTATION USING LINKED LIST
#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *next;
};

void read(struct node **arr,int n)
{
    int i,j;
    int reply;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *p = (struct node *)malloc(sizeof(struct node));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Vertices %d and %d are adjacent",i,j);
            scanf("%d",&reply);
            if(reply==1 || reply==1)
            {
                printf("%d-->%d\n",i,j);
                newnode->data = j;
                newnode->next = NULL;
                if(arr[i] == NULL)
                {
                    arr[i] = newnode;
                }
                else
                {
                    p = arr[i];
                    while(p->next != NULL)
                    {
                        p = p->next;
                    }
                    p->next = newnode;
                }
            }
        }
    }
}


int main()
{
    int choice,i,n;
    printf("How many vertices\n");
    scanf("%d",&n);
    struct node *arr[n];
    for(i=0;i<n;i++)
    {
        arr[i] = NULL;
    }
    printf("---GRAPH LINKED LIST REPRESENTATION---\n");
    printf("1. Read Graph\n");
    printf("2. Exit\n");
    while(1)
    {
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: read(arr,n);
                    break;
            case 2: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
