#Reverse individual characters in string using stack in c
#Approach - a) Input a string, Create a empty stack.
#           b) Iterate a string, if it is a character then push it to the stack, if space encounters then pop all elements from stack and print it.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50

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

int peek(const struct Stack *s){
    return s->arr[s->top];
}

int pop(struct Stack *s){
    int e = s->arr[s->top];
    s->top--;
    return e;
}

void reverse(char str[]) {
    int f;
    struct Stack s;
    initStack(&s);
    for(int i=0;i<strlen(str);++i) 
    {
       if(str[i]!=' ')
       {
           push(&s,str[i]);
       }
       else
       {
           while(!isEmpty(&s))
           {
               f = peek(&s);
               printf("%c",f);
               pop(&s);
           }
           printf(" ");
       }
    }
    printf(" ");
    while(!isEmpty(&s))
           {
               f= peek(&s);
               printf("%c",f);
               pop(&s);
           }
}

int main()
{
    char str[50];
    //gets(str);
    scanf("%[^\n]s",str);
    /*for(int i=0;i<strlen(str);i++) {
        printf("%c\n",str[i]);
    }*/
    printf("%ld\n",strlen(str));
    reverse(str);
}


#Output
1.Hello Asha! How are you
  23
  olleH !ahsA woH era  uoy
  
2.we need to print reverse of individual words.
  45
  ew deen ot tnirp esrever fo laudividni  .sdrow
