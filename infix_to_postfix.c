#include <stdio.h>
#include <stdlib.h>
#define size 7

int top = -1;
char stack[size];

int isEmpty(){
    return (top == -1);
}

int isFull(){
    return (top == size - 1);
}

void push(char ch){
    if(!isFull()){
        top = top + 1;
        stack[top] = ch;
    }
}

char pop(){
    if(!isEmpty()){
        char temp = stack[top];
        top = top - 1;
        return temp;
    }
    return '\0'; // Indicates empty stack
}

int display(){
    printf("The Elements of the Stack are: ");
    for(int i = top; i >= 0; i--){
        printf("%c   ", stack[i]);
    }
    return 0;
}

int icp(char ch){
    if(ch == '+' || ch == '-') return 1;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '^') return 4;
    else if(ch == '(') return 5;
    else return 0;
}

int isp(char ch){
    if(ch == '+' || ch == '-') return 1;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '^') return 3;
    else return 0;
}

void toPostfix(char infix[]){
    char postfix[20];
    int k = 0, i = 0;
    char tkn = infix[i];
    while(tkn != '\0'){
        if(tkn != '+' && tkn != '-' && tkn != '*' && tkn != '/' && tkn != '(' && tkn != '^' && tkn != ')'){
            postfix[k] = infix[i];
            k++;
        }
        else{
            if(tkn == '(')
                push('(');
            else{
                if(tkn == ')'){
                    char temp;
                    while((temp = pop()) != '('){
                        postfix[k] = temp;
                        k++;
                    }
                }
                else{
                    while(!isEmpty() && isp(stack[top]) >= icp(tkn)){
                        postfix[k] = pop();
                        k++;
                    }
                    push(tkn);
                }
            }
        }
        i++;
        tkn = infix[i];
    }
    while(!isEmpty()){
        postfix[k] = pop();
        k++;
    }
    postfix[k] = '\0';
    printf("Postfix Expression is: %s\n", postfix);
}

int main(){
    char infix[20];
    printf("Enter the Infix Expression: ");
    scanf("%s", infix);
    toPostfix(infix);
    return 0;
}
