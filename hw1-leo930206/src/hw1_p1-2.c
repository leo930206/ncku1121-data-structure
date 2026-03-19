#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_EXP_SIZE 101

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* buildExpressionTree(char postfix[]) {
    Node* stack[MAX_EXP_SIZE];
    int top = -1;

    for (int i = 0; postfix[i]; ++i) {
        char ch = postfix[i];
        Node* newNode = createNode(ch);

        if (isalnum(ch)) {
            stack[++top] = newNode;
        } else {
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            stack[++top] = newNode;
        }
    }
    return stack[top];
}

void printPrefix(Node* root) {
    if (root) {
        printf("%c", root->data);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

int main() {
    char postfix[MAX_EXP_SIZE];
    scanf("%s", postfix);
    Node* expressionTree = buildExpressionTree(postfix);
    printPrefix(expressionTree);
    return 0;
}