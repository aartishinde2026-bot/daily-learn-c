#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char x) {
    stack[++top] = x;
}

// Pop
char pop() {
    return stack[top--];
}

// Priority function
int priority(char x) {
    if (x == '+' || x == '-')
       return 1;
    if (x == '*' || x == '/')
       return 2;
    return 0;
}

int main() {
    char exp[100], postfix[100];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i])) {
            postfix[j++] = exp[i];
        }
        else if (exp[i] == '(') {
            push(exp[i]);
        }
        else if (exp[i] == ')') {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();  // remove '('
        }
        else {
            while (top != -1 && priority(stack[top]) >= priority(exp[i]))
                postfix[j++] = pop();
            push(exp[i]);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  // Null-terminate string

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
