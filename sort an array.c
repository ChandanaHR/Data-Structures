#Sort an array using stack in c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 7

struct Stack{
    int arr[SIZE];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
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

void sortArray(int arr[], int n) {
    int i;
    struct Stack s,temp;
    initStack(&s);
    initStack(&temp);
    for(i=0;i<n;i++) {
        if(isEmpty(&s)) {
             push(&s,arr[i]);  }  
        else {
            if(arr[i]<peek(&s)) {
                push(&s,arr[i]); }
            else {
                    while(!isEmpty(&s) && arr[i]>peek(&s)) {
                            push(&temp,pop(&s)); }
                    push(&s,arr[i]);
                    while(!isEmpty(&temp)) {
                            push(&s,pop(&temp)); }
                 }
             }
    }
    int j=0;
    while(!isEmpty(&s)) {
        arr[j] = pop(&s);
       j++;
   }
}

void displayArray(int arr[], int n) {
    int i;
    for(i=0;i<n;i++) {
        printf(" %d",arr[i]);
    }
}

int main() {
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sortArray(arr,n);
    displayArray(arr,n);
}
