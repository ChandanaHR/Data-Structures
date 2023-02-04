#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
   int data;
   struct node *link;
};

struct node *head;
struct node *temp;
int n;

void createlist()
{
   if(head==NULL)
   {
      printf("Enter the number of nodes\n");
      scanf("%d",&n);
      if(n!=0)
      {
         struct node *newnode;
         int info;
         newnode = (struct node *)malloc(sizeof(struct node));
         temp = (struct node *)malloc(sizeof(struct node));
         printf("Enter the data to be inserted\n");
         scanf("%d",&info);
         newnode->data = info;
         newnode->link = NULL;
         head = newnode;
         temp = head;
         for(int i=1;i<n;i++)
         {
            struct node *newnode;
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter the data to be inserted\n");
            scanf("%d",&info);
            newnode->data = info;
            newnode->link = NULL;
            temp->link = newnode;
            temp = newnode;
         }
         temp->link = head;
      }
   }
}

void displaylist()
{
   struct node *tmp;
   tmp = (struct node *)malloc(sizeof(struct node));
   if(head == NULL)
   {
     printf("No data present\n");
   }
   else
   {
     tmp = head;
     do 
     {
        printf("%d ",tmp->data);
        tmp = tmp->link;
     }while(tmp!=head);
   }
}

void insertbegin()
{
   int info;
   struct node *newnode;
   newnode = (struct node *)malloc(sizeof(struct node));
   printf("Enter the data to be inserted\n");
   scanf("%d",&info);
   newnode->data = info;
   newnode->link = NULL;
   if(head==NULL)
   {
      head = newnode;
      newnode->link = head;
   }
   else
   {
      newnode->link = head;
      temp->link = newnode;
      head = newnode;
   }
}

void insertend()
{
   int info;
   struct node *newnode;
   newnode = (struct node *)malloc(sizeof(struct node));
   printf("Enter the data to be inserted\n");
   scanf("%d",&info);
   newnode->data = info;
   newnode->link = NULL;
   if(head == NULL)
   {
       head = newnode;
       newnode->link = head;
   }
   else
   {
       temp->link = newnode;
       newnode->link = head;
       temp = newnode;
   }
}

void insertpos()
{
    int pos,i=1,info;
    struct node *newnode;
    struct node *tmp;
    newnode = (struct node *)malloc(sizeof(struct node));
    tmp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to be inserted\n");
    scanf("%d",&info);
    newnode->data = info;
    newnode->link = NULL;
    if(head==NULL)
    {
       printf("List is empty\n");
    }
    else
    {
    printf("Enter the position\n");
    scanf("%d",&pos);
    tmp = head;
    while(i<pos-1)
    {
       tmp = tmp->link;
       i++;
    }
    newnode->link = tmp->link;
    tmp->link = newnode;
    }
}

void deletefront()
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
       printf("List is empty\n");
    }
    else
    {
    tmp = head;
    head = head->link;
    temp->link = head;
    free(tmp);
    }
}

void deleteend()
{
   struct node *tmp;
   struct node *last;
   tmp = (struct node *)malloc(sizeof(struct node));
   last = (struct node *)malloc(sizeof(struct node));
   if(head == NULL)
   {
      printf("List is empty\n");
   }
   else
   {
     tmp = head;
     last = temp;
     while(tmp->link != last)
     {
       tmp = tmp->link;
     }
     tmp->link = head;
     temp = tmp;
     free(last);
   }
}

void deletepos()
{
   int pos,i=1;
   struct node *tmp;
   struct node *mid;
   tmp = (struct node *)malloc(sizeof(struct node));
   mid = (struct node *)malloc(sizeof(struct node));
   if(head == NULL)
   {
      printf("List is empty\n");
   }
   else
   {
      printf("Enter the position\n");
      scanf("%d",&pos);
      tmp = head;
      while(i<pos-1)
      {
          tmp = tmp->link;
          i++;
      }
      mid = tmp->link;
      tmp->link = mid->link;
      free(mid);
   }
}

int main()
{
   int choice;
   printf("-------CIRCULAR LINKED LIST OPERATIONS-------\n");
   printf("1. Create Linked List\n");
   printf("2. Display linked list\n");
   printf("3. Insert at beginning\n");
   printf("4. Insert at end\n");
   printf("5. Insert at position\n");
   printf("6. Delete at beginning\n");
   printf("7. Delete at end\n");
   printf("8. Delete at position\n");
   printf("9. Exit\n");
   while(1)
   {
      printf("Enter the choice\n");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1: createlist();
                 break;
         case 2: displaylist();
                 break;
         case 3: insertbegin();
                 break;
         case 4: insertend();
                 break;
         case 5: insertpos();
                 break;
         case 6: deletefront();
                 break;
         case 7: deleteend();
                 break;
         case 8: deletepos();
                 break;
         case 9: exit(0);
         default: printf("Invalid\n");
      }
   }
   return 0;
}
