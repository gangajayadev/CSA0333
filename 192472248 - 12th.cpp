#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100
char stack[SIZE];
int top = -1;
void push(char ch) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}
char pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;
    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        } else {
            while (precedence(ch) <= precedence(stack[top]) && top != -1) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int evalPostfix(char postfix[]) {
    int valStack[SIZE];
    int i, val1, val2;
    int valTop = -1;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            valStack[++valTop] = postfix[i] - '0';
        } else {
            val2 = valStack[valTop--];
            val1 = valStack[valTop--];
            switch (postfix[i]) {
                case '+': valStack[++valTop] = val1 + val2; break;
                case '-': valStack[++valTop] = val1 - val2; break;
                case '*': valStack[++valTop] = val1 * val2; break;
                case '/': valStack[++valTop] = val1 / val2; break;
            }
        }
    }
    return valStack[valTop];
}
int main() {
    char infix[SIZE], postfix[SIZE];
    printf("Enter an infix expression (use single-digit operands only): ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    printf("Evaluation of postfix: %d\n", evalPostfix(postfix));
    return 0;
}
