#Check for Balanced Paranthesis in an expression using Stack

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define SIZE 20

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

void push( struct Stack *s, int num){
    s->top++;
    s->arr[s->top] = num;
}

int peek(const struct Stack *s){
    return s->arr[s->top];
}

int pop(struct Stack *s){
    int e = s->arr[s->top];
    s->top--;
    return e;
}

int balanced(char str[]) {
    struct Stack s;
    initStack(&s);
    for(int i=0;i<strlen(str);i++) {
        if(isEmpty(&s)) {
            push(&s,str[i]);
        }
        else if((peek(&s)=='(' && str[i]==')') || (peek(&s)=='[' && str[i]==']') || (peek(&s)=='{' && str[i]=='}')) {
            pop(&s);
        }
        else {
            push(&s,str[i]);
        }
    }
    if(isEmpty(&s)) {
        return true;
    }
    return false;
}

int main() {
    char str[20];
    scanf("%[^\n]s",str);
    if(balanced(str) == true) {
        printf("Balanced Paranthesis");
    }
    else {
        printf("Not Balanced Paranthesis");
    }
    return 0;
}

#Output
 [()]{}{[()()]()}
 Balanced Paranthesis
 
 [(])
 Not Balanced Paranthesis
