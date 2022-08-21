#We have to see the array stack sortable or not

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10

struct Stack{
    int arr[SIZE];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int peek(const struct Stack *s){
    return s->arr[s->top];
}


int pop(struct Stack *s){
    int e = s->arr[s->top];
    s->top--;
    return e;
}

void push( struct Stack *s, int num){
    s->top++;
    s->arr[s->top] = num;
}

int stacksortable(int arr[],int n)
{
    struct Stack s;
    initStack(&s);
    int i;
    int end=0;
    for(i=0;i<n;i++) {
        if(!isEmpty(&s)) {
           int top = peek(&s);
           while(top==end+1) {
               end = end+1;
               int a = pop(&s);
               if(isEmpty(&s)) {
                   break;
               }
               top = peek(&s);
           }
           if(isEmpty(&s)) {
               push(&s,arr[i]);
           }
           else {
               top = peek(&s);
               if(arr[i]<top) {
                   push(&s,arr[i]);
               }
               else {
                   return 0;
               }
           }
        }
        else {
            push(&s,arr[i]);
        }
    }
    return 1;
}

int main()
{
    int ch;
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    if((stacksortable(arr,n)) == 1)
    {
        printf("Stack is sortable");
    }
    else
    {
        printf("Stack is not sortable");
    }
    return 0;
}

Output
3
3 2 1
Stack is sortable

3
2 3 1
Stack is not sortable

4
4 1 2 3
Stack is sortable
