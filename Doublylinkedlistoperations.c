//VARIOUS DOUBLY LINKED LIST OPERATIONS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node {
    int data;
    struct node *link,*prev;
};

struct node *temp;
struct node *head;
int n;

void create()
{
    temp = (struct node *)malloc(sizeof(struct node));
    int info;
    if(head == NULL)
    {
        printf("Enter the number of nodes\n");
        scanf("%d",&n);
        if(n!=0)
        {
            printf("Enter the data to be inserted\n");
            scanf("%d",&info);
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = info;
            newnode->prev = NULL;
            newnode->link = head;
            head = newnode;
            temp = head;
            for(int i=1;i<n;i++)
            {
                printf("Enter the data to be inserted\n");
                scanf("%d",&info);
                struct node *newnode = (struct node *)malloc(sizeof(struct node));
                newnode->data = info;
                temp->link = newnode;
                newnode->prev = temp;
                temp = temp->link;
            }
        }
        printf("The list is created\n");
    }
    else
    {
        printf("The list is already created\n");
    }
}

void traverse()
{
    temp = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->link;
        }
    }
}

void reverse()
{
    temp = NULL;
    struct node *current = (struct node *)malloc(sizeof(struct node));
    current = head;
    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->link;
        current->link = temp;
        current = current->prev;
    }
    if(temp != NULL)
    {
        head = temp->prev;
    }
}

void sort()
{
    int temp;
    struct node *first,*second;
    first = head;
    second = head;
    while(first != NULL)
    {
        second = first->link;
        while(second != NULL)
        {
            if(second->data<first->data)
            {
                temp = second->data;
                second->data = first->data;
                first->data = temp;
            }
            second = second->link;
        }
        first = first->link;
    }
}

void pairs()
{
    int x;
    printf("Enter the value\n");
    scanf("%d",&x);
    int found = false;
    struct node *first,*second;
    first = head;
    second = head;
    while(second->link != NULL)
    {
        second = second->link;
    }
    while(first!=second && second->link!=first)
    {
        if((first->data+second->data)==x)
        {
            found = true;
            printf("(%d %d) ",first->data,second->data);
            first = first->link;
            second = second->prev;
        }
        else
        {
            if((first->data+second->data)<x)
            {
                first = first->link;
            }
            else
            {
                second = second->prev;
            }
        }
    }
    if(found==false)
    {
        printf("No pair found\n");
    }
}

void insert()
{
    int info;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *previous = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to be inserted\n");
    scanf("%d",&info);
    newnode->data = info;
    temp = head;
    while(temp->link!=NULL && temp->link->data < info)
    {
        temp = temp->link;
    }
    newnode->link = temp->link;
    newnode->link->prev = newnode;
    temp->link = newnode;
    newnode->prev = temp;
}

void rotate()
{
    struct node *current = (struct node *)malloc(sizeof(struct node));
    int a,count=1;
    printf("Enter the number of rotations\n");
    scanf("%d",&a);
    temp = head;
    while(temp != NULL && count<a)
    {
        temp = temp->link;
        count++;
    }
    current = temp;
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = head;
    temp->link->prev = temp;
    head = current->link;
    head->prev = NULL;
    current->link = NULL;
}

int main()
{
    int choice;
    printf("----DOUBLY LINKED LIST OPERATIONS----\n");
    printf("1. Create doubly linked list\n");
    printf("2. Traverse a doubly linked list\n");
    printf("3. Reverse a doubly linked list\n");
    printf("4. Sorting a doubly linked list\n");
    printf("5. Finding a pairs which is equal to value\n");
    printf("6. Insert value in sorted way in sorted doubly linked list\n");
    printf("7. Rotate a doubly linked list\n");
    printf("8. Exit\n");
    while(1)
    {
        printf("\n\nEnter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: create();
                    break;
            case 2: traverse();
                    break;
            case 3: reverse();
                    break;
            case 4: sort();
                    break;
            case 5: pairs();
                    break;
            case 6: insert();
                    break;
            case 7: rotate();
                    break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
