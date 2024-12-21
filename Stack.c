#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top = -1;

int isFull()
{
    return (top == MAX - 1);
}

int isEmpty()
{
    return (top == -1);
}

void push(int data)
{
    if (isFull())
    {
        printf("Stack overflow\n");
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
    printf("Pushed %d onto the stack\n", data);
}

int pop()
{
    if (isEmpty())
    {
        printf("Stack underflow\n");
        return -1;
    }
    int value = stack_arr[top];
    top = top - 1;
    return value;
}

int peek()
{
    if (isEmpty())
    {
        printf("Stack underflow\n");
        return -1;
    }
    return stack_arr[top];
}

void print()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack_arr[i]);
}

int main()
{
    int choice, data;

    do
    {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element\n");
        printf("4. Print all the elements\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            data = pop();
            if (data != -1)
                printf("The deleted element is %d\n", data);
            break;

        case 3:
            data = peek();
            if (data != -1)
                printf("The topmost element is %d\n", data);
            break;

        case 4:
            print();
            break;

        case 5:
            printf("Exiting program. Goodbye!\n");
            break;

        default:
            printf("Wrong choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
