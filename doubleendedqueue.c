#Double ended queue
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 6

struct Queue {
    int elements[100];
    int front;
    int rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isqfull(struct Queue *q){
    if(((q->rear+1)%SIZE)==q->front){
        return 1;
    }
    else {
        return 0;
    }
}

void enqueuerear(struct Queue *q,int a){
    q->rear = (q->rear+1)%SIZE;
    q->elements[q->rear] = a;
    if(q->front==-1){
        q->front=0;
    }
}

void enqueuefront(struct Queue *q,int a){
    q->front--;
    if(q->front<0){
        q->front =  SIZE-1;
    }
    q->elements[q->front] = a;
    if(q->rear==-1) {
        q->rear = SIZE-1;
    }
}

int isqempty(struct Queue *q){
    return q->front==-1;
}

int dequeuefront(struct Queue *q) {
    int e = q->elements[q->front];
    if(q->front==q->rear){
        q->front = q->rear = -1;
    }
    else {
        q->front = ((q->front)+1)%SIZE;
        return e;
    }
}

int dequeuerear(struct Queue *q) {
    int e = q->elements[q->rear];
    if(q->front==q->rear) {
        q->front=q->rear=-1;
    }
    else {
        q->rear--;
        if(q->rear<0) {
            q->rear = SIZE-1;
        }
        return e;
    }
}

int getfront(struct Queue *q) {
    return q->elements[q->front];
}

int getrear(struct Queue *q) {
    return q->elements[q->rear];
}

int display(struct Queue *q) {
    int i;
    for(int i=q->front;i!=q->rear;i=(i+1)%SIZE) {
        printf("%d\n",q->elements[i]);
    }
    if(q->front!=-1){
    printf("%d\n",q->elements[i]); }
}
 
int main() {
    int a;
    int choice;
    struct Queue q;
    initQueue(&q);
    while(1){
        printf("Operations on Queue\n");
        printf("\n 1.Insert Operation at rear end \n 2.Insert Operation at front end \n 3.Delete Operation at front end \n 4.Delete Operation at rear end \n 5.Get Front Operation \n 6.Get Rear Operation\n 7.Display Queue \n 8.Exit");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1: if(isqfull(&q)) {
                        printf("Queue full error\n");
                    }
                    else {
                        printf("Enter the element to be enqueued\n");
                        scanf("%d",&a);
                        enqueuerear(&q,a);
                    }
                    break;
            case 2: if(isqfull(&q)) {
                        printf("Queue full error\n");
                    }
                    else {
                        printf("Enter the element to be enqueued\n");
                        scanf("%d",&a);
                        enqueuefront(&q,a);
                    }
                    break;
            case 3: if(isqempty(&q)) {
                        printf("Queue empty error\n");
                     }
                     else {
                        int e = dequeuefront(&q);
                         printf("%d\n",e);
                     }
                     break;
            case 4: if(isqempty(&q)) {
                        printf("Queue empty error\n");
                     }
                     else {
                         int e = dequeuerear(&q);
                         printf("%d\n",e);
                     }
                     break;
            case 5: if(isqempty(&q)) {
                        printf("Queue empty error\n");
                    }
                    else {
                        int e = getfront(&q);
                        printf("%d\n",e);
                    }
                    break;
            case 6: if(isqempty(&q)) {
                        printf("Queue empty error\n");
                    }
                    else {
                        int e = getrear(&q);
                        printf("%d\n",e);
                    }
                    break;
            case 7: if(isqempty(&q)) {
                        printf("Queue empty error\n");
                    }
                    else {
                        display(&q);
                    }
                    break;
            case 8: exit(0);
            default: printf("Invalid option");
        }
    }
}


#Output
Operations on Queue

 1.Insert Operation at rear end 
 2.Insert Operation at front end 
 3.Delete Operation at front end 
 4.Delete Operation at rear end 
 5.Get Front Operation 
 6.Get Rear Operation
 7.Display Queue 
 8.ExitEnter the choice
1
Enter the element to be enqueued
10
Operations on Queue

 1.Insert Operation at rear end 
 2.Insert Operation at front end 
 3.Delete Operation at front end 
 4.Delete Operation at rear end 
 5.Get Front Operation 
 6.Get Rear Operation
 7.Display Queue 
 8.ExitEnter the choice
1
Enter the element to be enqueued
20
Operations on Queue

 1.Insert Operation at rear end 
 2.Insert Operation at front end 
 3.Delete Operation at front end 
 4.Delete Operation at rear end 
 5.Get Front Operation 
 6.Get Rear Operation
 7.Display Queue 
 8.ExitEnter the choice
1
Enter the element to be enqueued
30
Operations on Queue
1.Insert Operation at rear end 
 2.Insert Operation at front end 
 3.Delete Operation at front end 
 4.Delete Operation at rear end 
 5.Get Front Operation 
 6.Get Rear Operation
 7.Display Queue 
 8.ExitEnter the choice
2
Enter the element to be enqueued
40
Operations on Queue

 1.Insert Operation at rear end 
 2.Insert Operation at front end 
 3.Delete Operation at front end 
 4.Delete Operation at rear end 
 5.Get Front Operation 
 6.Get Rear Operation
 7.Display Queue 
 8.ExitEnter the choice
2
Enter the element to be enqueued
50
Operations on Queue

 1.Insert Operation at rear end 
 2.Insert Operation at front end 
 3.Delete Operation at front end 
 4.Delete Operation at rear end 
 5.Get Front Operation 
 6.Get Rear Operation
 7.Display Queue 
 8.ExitEnter the choice
2
Enter the element to be enqueued
60
Operations on Queue

 1.Insert Operation at rear end 
 2.Insert Operation at front end 
 3.Delete Operation at front end 
 4.Delete Operation at rear end 
 5.Get Front Operation 
 6.Get Rear Operation
 7.Display Queue 
 8.ExitEnter the choice
3
60
Operations on Queue

 1.Insert Operation at rear end 
 2.Insert Operation at front end 
 3.Delete Operation at front end 
 4.Delete Operation at rear end 
 5.Get Front Operation 
 6.Get Rear Operation
 7.Display Queue 
 8.ExitEnter the choice
3
50
Operations on Queue

 1.Insert Operation at rear end 
 2.Insert Operation at front end 
 3.Delete Operation at front end 
 4.Delete Operation at rear end 
 5.Get Front Operation 
 6.Get Rear Operation
 7.Display Queue 
 8.ExitEnter the choice
4
30
Operations on Queue

 1.Insert Operation at rear end 
 2.Insert Operation at front end 
 3.Delete Operation at front end 
 4.Delete Operation at rear end 
 5.Get Front Operation 
 6.Get Rear Operation
 7.Display Queue 
 8.ExitEnter the choice
4
20
Operations on Queue

 1.Insert Operation at rear end 
 2.Insert Operation at front end 
 3.Delete Operation at front end 
 4.Delete Operation at rear end 
 5.Get Front Operation 
 6.Get Rear Operation
 7.Display Queue 
 8.ExitEnter the choice
5
40
Operations on Queue

 1.Insert Operation at rear end 
 2.Insert Operation at front end 
 3.Delete Operation at front end 
 4.Delete Operation at rear end 
 5.Get Front Operation 
 6.Get Rear Operation
 7.Display Queue 
 8.ExitEnter the choice
6
10
