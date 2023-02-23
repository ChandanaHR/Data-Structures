#BASIC DOUBLY LINKED LIST OPERATIONS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node {
    int data;
    struct node *prev,*next;
};

struct node *head;
struct node *temp;
int n;

void createdlist()
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
            newnode->next = head;
            head = newnode;
            temp = head;
            for(int i=1;i<n;i++)
            {
                printf("Enter the data to be inserted\n");
                scanf("%d",&info);
                struct node *newnode = (struct node *)malloc(sizeof(struct node));
                newnode->data = info;
                temp->next = newnode;
                newnode->prev = temp;
                temp = temp->next;
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
   if(head==NULL)
   {
     printf("List is empty\n");
     return;
   }
   else
   {
     temp = head;
     while(temp!=NULL)
     {
        printf("%d-->",temp->data);
        temp = temp->next;
     }
   }
}

void insertfront()
{
   int info;
   struct node *newnode;
   newnode = (struct node *)malloc(sizeof(struct node));
   printf("Enter the data to be inserted\n");
   scanf("%d",&info);
   newnode->data = info;
   newnode->prev = NULL;
   newnode->next = head;
   head = newnode;
}

void insertend()
{
  int info;
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  temp = (struct node *)malloc(sizeof(struct node));
  newnode->prev = NULL;
  newnode->next = NULL;
  printf("Enter the data to be inserted\n");
  scanf("%d",&info);
  newnode->data = info;
  temp = head;
   if(head==NULL)
   {
     head = newnode;
   }
   else
   {
     while(temp->next != NULL)
     {
       temp = temp->next;
     }
     newnode->prev = temp;
     temp->next = newnode;
   }
}

void insertatpos()
{
   int info,pos,i=1;
   struct node *newnode;
   newnode = (struct node *)malloc(sizeof(struct node));
   temp = (struct node *)malloc(sizeof(struct node));
   newnode->next = NULL;
   newnode->prev = NULL;
   printf("Enter position\n");
   scanf("%d",&pos);
   if(head==NULL)
   {
      head = newnode;
      newnode->prev = NULL;
      newnode->next = NULL;
   }
   else if(pos==1)
   {
      insertfront();
   }
   else
   {
      printf("Enter the data to be inserted\n");
      scanf("%d",&info);
      newnode->data = info;
      temp = head;
      while(i<pos-1)
      {
         temp = temp->next;
         i++;
      }
      newnode->next = temp->next;
      newnode->prev = temp;
      temp->next = newnode;
      temp->next->prev = newnode;
   }
}

void deletefront()
{
     temp = (struct node *)malloc(sizeof(struct node));
     if(head==NULL)
     {
        printf("List is empty\n");
     }
     else
     {
        temp = head;
        head = head->next;
        if(head != NULL)
        {
          head->prev = NULL;
        }
        free(temp);
     }
}

void deleteend()
{
      temp = (struct node *)malloc(sizeof(struct node));
      if(head == NULL)
      {
          printf("List is empty\n");
      }
      temp = head;
      while(temp->next != NULL)
      {
         temp = temp->next;
      }
      if(head->next==NULL)
      {
         head = NULL;
      }
      else
      {
         temp->prev->next = NULL;
         free(temp);
      }
}

void deleteatpos()
{
      int pos,i=1;
      struct node *position;
      temp = head;
      if(head==NULL)
      {
         printf("List is empty\n");
      }
      else
      {
         printf("Enter position\n");
         scanf("%d",&pos);
         if(pos==1)
         {
            deletefront();
            if(head!=NULL) {
               head->prev = NULL;
            }
            free(position);
            return;
         }
         while(i<pos-1)
         {
            temp = temp->next;
            i++;
         }
         position = temp->next;
         if(position->next != NULL)
         {
            position->next->prev = temp;
         }
         temp->next = position->next;
         free(position);
      }
}

int main()
{
   int choice;
   printf("Doubly linked list operations\n");
   printf("1. Create doubly linked list\n");
   printf("2. Display doubly linked list\n");
   printf("3. Insert at beginning\n");
   printf("4. Insert at end\n");
   printf("5. Insert at position\n");
   printf("6. Delete at beginning\n");
   printf("7. Delete at end\n");
   printf("8. Delete at position\n");
   printf("10. Exit\n");
   while(1)
   {
     printf("Enter the choice\n");
     scanf("%d",&choice);
     switch(choice)
     {
        case 1: createdlist();
                break;
        case 2: traverse();
                break;
        case 3: insertfront();
                break;
        case 4: insertend();
                break;
        case 5: insertatpos();
                break;
        case 6: deletefront();
                break;
        case 7: deleteend();
                break;
        case 8: deleteatpos();
                break;
        case 10: exit(0);
        default: printf("Invalid choice\n");
     }
   }
} 
