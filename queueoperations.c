#Basic Queue operations

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 4

struct Queue {
    int elements[100];
    int front;
    int rear;
};

void initQueue(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isqfull(struct Queue *q){
    return q->rear==SIZE-1;
}

void enqueue(struct Queue *q,int a){
    q->rear++;
    q->elements[q->rear] = a;
}

int isqempty(struct Queue *q) {
    return q->front==SIZE;
}

int dequeue(struct Queue *q) {
    int f = q->elements[q->front];
    q->front++;
    return f;
}

int getfront(struct Queue *q) {
    return q->elements[q->front];
}

void display(struct Queue *q) {
    for(int i=q->front;i<=q->rear;i++) {
        printf("%d\n",q->elements[i]);
    }
}

int getsize(const struct Queue *q) {
    int d= ((q->rear)-(q->front))+1;
    printf("%d\n",d);
}

int main(){
    int a;
    int choice;
    struct Queue q;
    initQueue(&q);
    while(1){
        printf("Operations on Queue\n");
        printf("\n 1.Insert Operation \n 2.Delete Operation \n 3.Getfront operation \n 4.Display Operation \n 5.Size \n 6.Exit\n ");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1: if(isqfull(&q)) {
                        printf("Queue full error\n");
                    }
                    else {
                        printf("Enter the element to be enqueued\n");
                        scanf("%d",&a);
                        enqueue(&q,a);
                    }
                    break;
            case 2: if(isqempty(&q)) {
                        printf("Queue empty error\n");
                     }
                     else {
                         dequeue(&q);
                     }
                     break;
            case 3: if(isqempty(&q)) {
                        printf("Queue empty error\n");
                     }
                     else {
                         getfront(&q);
                     }
                     break;
            case 4: if(isqempty(&q)) {
                        printf("Queue empty error\n");
                     }
                     else {
                         display(&q);
                     }
                     break;
            case 5: if(isqempty(&q)) {
                        printf("Queue empty error\n");
                    }
                    else {
                        getsize(&q);
                    }
                    break;
            case 6: exit(0);
            default: printf("Invalid option");
        }
    }
}

#Output
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
1
Enter the element to be enqueued
10
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
1
Enter the element to be enqueued
20
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
1
Enter the element to be enqueued
30
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
1
Enter the element to be enqueued
40
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
1
Queue full error
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
4
10
20
30
40
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
5
4
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
2
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
4
20
30
40
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
5
3
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
2
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
4
30
40
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
2
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
5
1
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
2
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
2
Queue empty error
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
4
Queue empty error
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
 Enter the choice
5
Queue empty error
Operations on Queue

 1.Insert Operation 
 2.Delete Operation 
 3.Getfront operation 
 4.Display Operation 
 5.Size 
 6.Exit
Enter the choice
6
