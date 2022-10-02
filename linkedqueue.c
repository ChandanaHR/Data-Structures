#Queue using Linked list
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node {
    int data;
    struct node*next;
};

struct Queue {
    struct node*front;
    struct node*rear;
};

void initQueue(struct Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(struct Queue *q, int a) {
    struct node*p = (struct node *)malloc(sizeof(struct node));
    if(p==NULL){
        printf("Memory full");
        return;
    }
    p->data = a;
    p->next = NULL;
    if(q->rear == NULL) {
        q->rear = p;
        q->front = p;
    }
    else {
        (q->rear)->next = p;
        q->rear = p;
    }
}

int isempty(struct Queue *q) {
    return q->front == NULL;
}

int dequeue(struct Queue *q) {
    struct node *p = q->front;
    q->front = p->next;
    int d = p->data;
    free(p);
    return d;
}

int getfront(struct Queue *q) {
    return (q->front)->data;
}

void display(struct Queue *q) {
    struct node *p = q->front;
    while(p!=NULL) {
        printf("%d\n",p->data);
        p = p->next;
    }
}

int qsize(struct Queue *q) {
    int count = 0;
    struct node *p = q->front;
    while(p!=NULL) {
        count++;
        p = p->next;
    }
    printf("%d",count);
}

int main() {
    int a;
    int choice;
    struct Queue q;
    initQueue(&q);
    while(1) {
        printf("\nOperations on linked queue\n");
        printf("1. Insert Operation\n 2.Delete Operation\n 3.Get Front Operation\n 4.Display Operation\n 5. Size\n 6.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Enter the element to be inserted");
                    scanf("%d",&a);
                    enqueue(&q,a);
                    break;
            case 2: if(isempty(&q)) {
                       printf("Queue empty error");
                    }
                    else {
                        int e = dequeue(&q);
                        printf("%d",e);
                    }
                    break;
            case 3: if(isempty(&q)) {
                       printf("Queue empty error");
                    }
                    else {
                        int d = getfront(&q);
                        printf("%d",d);
                    }
                    break;
            case 4: if(isempty(&q)) {
                        printf("Queue empty error");
                    }
                    else {
                        display(&q);
                    }
                    break;
            case 5: qsize(&q);
            case 6: exit(0);
            default : printf("Invalid");
        }
    }
}

#Output
Operations on linked queue
1. Insert Operation
 2.Delete Operation
 3.Get Front Operation
 4.Display Operation
 5. Size
6.Exit
Enter the choice
1
Enter the element to be inserted
10
Operations on linked queue
1. Insert Operation
 2.Delete Operation
 3.Get Front Operation
 4.Display Operation
 5. Size
 6.Exit
Enter the choice
1
Enter the element to be inserted
20
Operations on linked queue
1. Insert Operation
 2.Delete Operation
 3.Get Front Operation
 4.Display Operation
 5. Size
 6.Exit
Enter the choice
1
Enter the element to be inserted
30
Operations on linked queue
1. Insert Operation
 2.Delete Operation
 3.Get Front Operation
 4.Display Operation
 5. Size
 6.Exit
Enter the choice
1
Enter the element to be inserted
40
Operations on linked queue
1. Insert Operation
 2.Delete Operation
 3.Get Front Operation
 4.Display Operation
 5. Size
 6.Exit
Enter the choice
2
10
Operations on linked queue
1. Insert Operation
 2.Delete Operation
 3.Get Front Operation
 4.Display Operation
 5. Size
 6.Exit
Enter the choice
2
0
Operations on linked queue
1. Insert Operation
 2.Delete Operation
 3.Get Front Operation
 4.Display Operation
 5. Size
 6.Exit
Enter the choice
3
30
Operations on linked queue
1. Insert Operation
 2.Delete Operation
 3.Get Front Operation
 4.Display Operation
 5. Size
 6.Exit
Enter the choice
3
30
Operations on linked queue
1. Insert Operation
 2.Delete Operation
 3.Get Front Operation
 4.Display Operation
 5. Size
 6.Exit
Enter the choice
4
30
40

Operations on linked queue
1. Insert Operation
 2.Delete Operation
 3.Get Front Operation
 4.Display Operation
 5. Size
 6.Exit
Enter the choice
5
2
