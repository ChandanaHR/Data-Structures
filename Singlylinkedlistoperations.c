#SINGLY LINKED LIST OPERATIONS

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

void create()
{
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
            newnode->link = NULL;
            head = newnode;
            temp = head;
            for(int i=1;i<n;i++)
            {
                printf("Enter the data to be inserted\n");
                scanf("%d",&info);
                struct node *newnode = (struct node *)malloc(sizeof(struct node));
                newnode->data = info;
                newnode->link = NULL;
                temp->link = newnode;
                temp = temp->link;
            }
        }
    }
}

void traverse()
{
    temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
}

void search()
{
    int count = 0,info,flag=0;
    temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    printf("Enter the data to be searched\n");
    scanf("%d",&info);
    while(temp != NULL)
    {
        if(temp->data == info)
        {
            flag = 1;
            break;
        }
        temp = temp->link;
        count = count+1;
    }
    if(flag == 1)
    {
        printf("Element found at position: %d ",count+1);
    }
    else
    {
        printf("Element not found in linked list\n");
    }
}

void reversesll()
{
    struct node *prevnode = (struct node *)malloc(sizeof(struct node));
    struct node *currnode = (struct node *)malloc(sizeof(struct node));
    temp = (struct node *)malloc(sizeof(struct node));
    if(head != NULL)
    {
        prevnode = head;
        head = head->link;
        currnode = head;
        prevnode->link = NULL;
        while(head!=NULL)
        {
            head = head->link;
            currnode->link = prevnode;
            prevnode = currnode;
            currnode = head;
        }
        head = prevnode;
    }
    temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
}

void printnthnode()
{
    int count=0,index;
    printf("Enter the index\n");
    scanf("%d",&index);
    temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    if(index == 0)
    {
        printf("Element at given index is: %d ",temp->data);
    }
    else
    {
    while(temp != NULL)
    {
        temp = temp->link;
        count++;
        if(count == index)
        {
            printf("Element at given index is: %d ",temp->data);
        }
    }
    }
}

void middle()
{
    int l=0,count=0,mid;
    struct node *odd = (struct node *)malloc(sizeof(struct node));
    struct node *even = (struct node *)malloc(sizeof(struct node));
    temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    odd = head;
    even = head;
    while(temp != NULL)
    {
        l = l+1;
        temp = temp->link;
    }
    mid = (l/2);
    if(l%2 != 0)
    {
        while(odd->link != NULL)
        {
            count = count+1;
            odd = odd->link;
            if(count == mid)
            {
                printf("%d ",odd->data);
            }
        }
    }
    else
    {
        while(even->link != NULL)
        {
            count = count+1;
            even = even->link;
            if(count == mid)
            {
                printf("%d ",even->data);
            }
        }
    }
}

void countno()
{
    int count=0,info,flag = 0;
    temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    printf("Enter the value\n");
    scanf("%d",&info);
    while(temp != NULL)
    {
        if(temp->data == info)
        {
            flag = 1;
            count++;
        }
        temp = temp->link;
    }
    if(flag == 1)
    {
        printf("Count of the given value: %d\n",count);
    }
    else
    {
        printf("Given element is not present\n");
    }
}

void sort()
{
    int temp;
    struct node *outer = (struct node *)malloc(sizeof(struct node));
    struct node *inner = (struct node *)malloc(sizeof(struct node));
    outer = head;
    while(outer != NULL)
    {
        inner = outer->link;
        while(inner != NULL)
        {
            if(inner->data < outer->data)
            {
                temp = inner->data;
                inner->data = outer->data;
                outer->data = temp;
            }
            inner = inner->link;
        }
        outer = outer->link;
    }
}

void duplicates()
{
    temp = (struct node *)malloc(sizeof(struct node));
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    struct node *present = (struct node *)malloc(sizeof(struct node));
    temp = head;
    while(temp != NULL)
    {
        curr = temp->link;
        while(curr != NULL)
        {
            if(temp->data == curr->data)
            {
                present = curr;
                temp->link = curr->link;
                curr = curr->link;
                free(present);
            }
            else
            {
                curr = curr->link;
            }
        }
        temp = temp->link;
    }
}

void rotate()
{
    int k,count=1;
    printf("Enter the k value in which list has to be rotated\n");
    scanf("%d",&k);
    temp = (struct node *)malloc(sizeof(struct node));
    struct node *current = (struct node *)malloc(sizeof(struct node));
    temp = head;
    while(count<k && temp!=NULL)
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
    head = current->link;
    current->link = NULL;
}

int main()
{
    int choice;
    printf("1. Create Linked list\n");
    printf("2. Traverse Linked list\n");
    printf("3. Search an element\n");
    printf("4. Reverse a Singly linked list\n");
    printf("5. Print nth node in Singly linked list\n");
    printf("6. Print middle element of Singly linked list\n");
    printf("7. Count the number of times a given int occurs\n");
    printf("8. Sorting a Singly linked list\n");
    printf("9. Removing duplicates from a Sorted Singly linked list\n");
    printf("10. Rotating a singly linked list\n");
    printf("11. Exit\n");
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
            case 3: search();
                    break;
            case 4: reversesll();
                    break;
            case 5: printnthnode();
                    break;
            case 6: middle();
                    break;
            case 7: countno();
                    break;
            case 8: sort();
                    break;
            case 9: duplicates();
                    break;
            case 10: rotate();
                    break;
            case 11: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
