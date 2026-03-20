#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

//Push
void push(int x) {
    stck[++top] = x;
}

//Pop
int pop() {
    return stack[top--];
}

int main() {
    char exp[100];
    int i, a, b, result;

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++) {

        if (isdigit(exp[i])) {
            push(exp[i] - '0'); // convert char to int
        }
        else {
            b = pop();
            a = pop();

            switch (exp[i]) {
                case '+': push(a + b);
                break;
                case '-': push(a - b);
                break;
                case '*': push(a * b);
                break;
                case '/': push(a / b);
                break;
            }
        }
    }

    result = pop();
    printf("Result = %d\n", result);
    return 0;
}