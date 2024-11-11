#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define size 20

int top = -1;
char s[20][20];

int isEmpty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isfull() {
    if (top == size - 1) {
        return 1;
    } else {
        return 0;
    }
}

void push(char str[size]) {
    if (isfull()) {
        printf("Stack is full\n");
    } else {
        strcpy(s[++top], str);
    }
}

void pop(char str[size]) {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        strcpy(str, s[top--]);
    }
}

void post_in(char postfix[size]) {
    char s1[size], s2[size], s3[size], inf[size];
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        s1[0] = postfix[i];
        s1[1] = '\0';
        
        if (isalpha(postfix[i]) != 0) {
            push(s1);
        } else {
            pop(s2);
            pop(s3);
            strcpy(inf, "(");
            strcat(inf, s3);
            strcat(inf, s1);
            strcat(inf, ")");
            push(inf);
        }
    }
    
    pop(inf);
    printf("The infix expression is: %s\n", inf);
}

int main() {
    char postfix[20];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    post_in(postfix);
    return 0;
}
