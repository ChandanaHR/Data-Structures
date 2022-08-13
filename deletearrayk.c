#Delete array elements which are smaller than next or become smaller
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

int getsize(struct Stack *s) {
    return s->top;
}

void deletearrayk(int arr[], int n, int k)
{
    struct Stack s;
    initStack(&s);
    int i,count=0;
    for(i=0;i<n;i++){
        while(!isEmpty(&s) && peek(&s)<arr[i] && count<k) {
            pop(&s);
            count++;
        }
        push(&s,arr[i]);
    }
    int j=0;
    while(!isEmpty(&s) && j<n) {
        arr[j] = pop(&s);
        printf(" %d",arr[j]);
        j++;
    }
}



int main()
{
    int i,n,a;
    int arr[n];
    scanf("%d",&n);
    scanf("%d",&a);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    deletearrayk(arr,n,a);
}
