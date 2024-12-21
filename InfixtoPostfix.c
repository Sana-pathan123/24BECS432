#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Function to push an element to the stack
void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

// Function to pop an element from the stack
char pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to return the precedence of an operator
int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

// Function to check if a character is an operator
int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char c;
    for (i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];

        // If the scanned character is an operand, add it to the postfix expression
        if (isalnum(c))
        {
            postfix[j++] = c;
        }
        // If the scanned character is '(', push it to the stack
        else if (c == '(')
        {
            push(c);
        }
        // If the scanned character is ')', pop and output until '(' is encountered
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            if (top == -1)
            {
                printf("Invalid expression: unmatched parentheses\n");
                exit(1);
            }
            pop(); // Pop '(' from the stack
        }
        // If the scanned character is an operator
        else if (isOperator(c))
        {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
            {
                postfix[j++] = pop();
            }
            push(c);
        }
        else
        {
            printf("Invalid character in expression: %c\n", c);
            exit(1);
        }
    }

    // Pop all the remaining operators from the stack
    while (top != -1)
    {
        if (stack[top] == '(')
        {
            printf("Invalid expression: unmatched parentheses\n");
            exit(1);
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("The corresponding postfix expression is: %s\n", postfix);

    return 0;
}
