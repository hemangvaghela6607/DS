#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 20
char infix[50],postfix[50],st[MAX];
int top=-1,i=0,j=0;
void push(char ch){
    int k;
    if(top==MAX-1){
        printf("Stack Overflow.");
        exit(0);
    }
    top++;
    st[top]=ch;
    printf("\nStack is: ");
    for(k=0;k<=top;k++)
        printf("%c ",st[k]);
}
char pop(){
    if(top==-1){
        printf("Stack underflow");
        exit(0);
    }
    top--;
    return(st[top+1]);
}
int priority(char ch){
    switch(ch){
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 2;
        case '$':
        case '^': return 3;
    }
}
void infix_to_postfix(){
    char temp;
    strcat(infix,")");
    printf("\nStep1:");
    puts(infix);
    push('(');
    while(infix[i]!=NULL){
        if(isalnum(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else if(infix[i]=='('||infix[i]=='$'||infix[i]=='^')
                    push(infix[i++]);
        else if(infix[i]==')'){
            while(top!=-1 && st[top]!='(')
                    postfix[j++]=pop();
            if(top==-1){
                printf("Invalid Expression.");
                exit(0);
            }
            temp=pop();
            i++;
        }
        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='%'){
            while(top!=-1 && priority(st[top])>= priority(infix[i]))
                postfix[j++]=pop();
            if(top==-1){
                printf("Invalid Expression.");
                exit(0);
            }
            push(infix[i]);
            i++;
        }
        else if(infix[i]==' ')
                i++;
        else {
            printf("Invalid Expression.");
                exit(0);
        }
    }
    postfix[j]==NULL;
}
void main(){
    printf("Enter an infix Expression:");
    gets(infix);
    infix_to_postfix();
    printf("\nPostfix Expression is: ");
    puts(postfix);
}
