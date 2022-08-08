#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5

struct Stack{
    int arr[SIZE];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isFull( struct Stack *s) {
    return s->top == SIZE-1;
}

void push( struct Stack *s, int num){
    s->top++;
    s->arr[s->top] = num;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int pop(struct Stack *s){
    int e = s->arr[s->top];
    s->top--;
    return e;
}

int peek(const struct Stack *s){
    return s->arr[s->top];
}

void display(struct Stack *s){
    int i;
    for(i=s->top; i>=0; i--) {
        printf("Stack elements are %d\n",s->arr[i]);
    }
}

int main(){
    int a,f;
    int choice;
    printf("Create Stack");
    struct Stack s;
    initStack(&s);
    while(1){
        printf("Operations on stack");
        printf("\n 1. Push Operation \n 2. Pop Operation \n 3.Peek Operation \n 4. Display Stack \n 5.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: if(isFull(&s)) {
                     printf("Stack overflow\n");
                    }
                    else {
                        printf("Enter the element to be pushed\n");
                        scanf("%d",&a);
                        push(&s,a);
                    }
                    break;
            case 2: if(isEmpty(&s)) {
                     printf("Stack underflow\n");
                    }
                    else {
                        pop(&s);
                    }
                    break;
            case 3: if(isEmpty(&s)) {
                     printf("Stack underflow\n");
                    }
                    else {
                       f =  peek(&s);
                       printf("Top element of the stack is %d\n",f);
                    }
                    break;
            case 4: if(isEmpty(&s)) {
                     printf("Stack underflow");
                    }
                    else {
                        display(&s);
                    }
                    break;
            case 5: exit(0);
            default: printf("Invalid option");
        }
    }
}

#Output
Create StackOperations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
1
Enter the element to be pushed
1
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
1
Enter the element to be pushed
2
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
1
Enter the element to be pushed
3
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
1
Enter the element to be pushed
4
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
1
Enter the element to be pushed
5
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
1
Stack overflow
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
3
Top element of the stack is 5
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
2
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
2
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
3
Top element of the stack is 3
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
4
Stack elements are 3
Stack elements are 2
Stack elements are 1
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
1
Enter the element to be pushed
4
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice 1
1
Enter the element to be pushed
5
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
1
Stack overflow
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
4
Stack elements are 5
Stack elements are 4
Stack elements are 3
Stack elements are 2
Stack elements are 1
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
2
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
5.Exit
Enter the choice
2
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
2
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
2
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
2
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
2
Stack underflow
Operations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
4
Stack underflowOperations on stack
 1. Push Operation 
 2. Pop Operation 
 3.Peek Operation 
 4. Display Stack 
 5.Exit
Enter the choice
5
