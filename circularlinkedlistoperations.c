//BASIC CIRCULAR LINKED LIST OPERATIONS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;
struct node *temp;
int n;

void create()
{
    int info;
    if(head==NULL)
    {
        printf("Enter the number of nodes\n");
        scanf("%d",&n);
        if(n!=0)
        {
            printf("Enter the data to be inserted\n");
            scanf("%d",&info);
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = info;
            newnode->next = NULL;
            head = newnode;
            temp = head;
            for(int i=1;i<n;i++)
            {
                printf("Enter the data to be inserted\n");
                scanf("%d",&info);
                struct node *newnode = (struct node *)malloc(sizeof(struct node));
                newnode->data = info;
                newnode->next = NULL;
                temp->next = newnode;
                temp = temp->next;
            }
            temp->next = head;
        }
    }
}

void display()
{
   struct node *tmp;
   tmp = (struct node *)malloc(sizeof(struct node));
   if(head == NULL)
   {
       printf("No data is present\n");
   }
   else
   {
       tmp = head;
       do{
           printf("%d ",tmp->data);
           tmp = tmp->next;
       }while(tmp!=head);
   }
}

void exchange()
{
    int tmp;
    if(head==NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        tmp = head->data;
        head->data = temp->data;
        temp->data = tmp;
    }
}

void split()
{
    int mid = n/2;
    int count=0;
    struct node *first = (struct node *)malloc(sizeof(struct node));
    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    first = head;
    while(first->next != NULL)
    {
        count++;
        first = first->next;
        if(count==mid)
        {
            break;
        }
    }
    head1 = first->next;
    first->next = head;
    temp->next = head1;
    
    struct node *tmp;
    struct node *cmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    cmp = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
       printf("No data is present\n");
    }
    else
    {
       tmp = head;
       do{
           printf("%d ",tmp->data);
           tmp = tmp->next;
       }while(tmp!=head);
    }
    printf("\n");
    if(head1 == NULL)
    {
       printf("No data is present\n");
    }
    else
    {
       cmp = head1;
       do{
           printf("%d ",cmp->data);
           cmp = cmp->next;
       }while(cmp!=head1);
    }
}

int main()
{
    int choice;
    printf("----CIRCULAR LINKED LIST OPERATIONS----\n");
    printf("1. Create Linked List\n");
    printf("2. Display linked list\n");
    printf("3. Exchange first and last node data in Circular linked list\n");
    printf("4. Split a cll with middle and display two linked list\n");
    printf("5. Exit\n");
    while(1)
    {
       printf("\n\nEnter the choice\n");
       scanf("%d",&choice);
       switch(choice)
       {
            case 1: create();
                   break;
            case 2: display();
                    break;
            case 3: exchange();
                    break;
            case 4: split();
                    break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
       }
    }
}
