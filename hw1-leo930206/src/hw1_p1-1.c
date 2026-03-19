#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_EXP_SIZE 100

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char ch) {
    switch(ch) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return -1;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX_EXP_SIZE + 1];
    int stackTop = -1, postfixIndex = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        if (isspace(current)) continue;

        if (isalnum(current)) {
            postfix[postfixIndex++] = current;
        } else if (current == '(') {
            stack[++stackTop] = current;
        } else if (current == ')') {
            while (stackTop != -1 && stack[stackTop] != '(') {
                postfix[postfixIndex++] = stack[stackTop--];
            }
            if (stackTop != -1) stackTop--; // Pop '(' from stack
        } else if (isOperator(current)) {
            while (stackTop != -1 && precedence(stack[stackTop]) >= precedence(current)) {
                if (precedence(stack[stackTop]) > precedence(current) || current != '^') {
                    postfix[postfixIndex++] = stack[stackTop--];
                }
            }
            stack[++stackTop] = current;
        }
    }

    while (stackTop != -1) {
        if (stack[stackTop] == '(') {
            printf("Invalid expression!");
            exit(EXIT_FAILURE);
        }
        postfix[postfixIndex++] = stack[stackTop--];
    }
    postfix[postfixIndex] = '\0';
}

int main() {
    char infix[MAX_EXP_SIZE + 1], postfix[MAX_EXP_SIZE + 1];
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("%s", postfix);
    return 0;
}