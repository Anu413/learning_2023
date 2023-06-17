#include <stdio.h>
int main() 
{
    int operand1, operand2;
    char operator;
    printf("Enter operand1: ");
    scanf("%d", &operand1);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter operand2: ");
    scanf("%d", &operand2);
    switch (operator)
    {
        case '+':
            printf("%d + %d = %d", operand1, operand2, operand1 + operand2);
            break;
        case '-':
            printf("%d - %d = %d", operand1, operand2, operand1 - operand2);
            break;
        case '*':
            printf("%d * %d = %d", operand1, operand2, operand1 * operand2);
            break;
        case '/':
            if (operand2 != 0)
            {
                printf("%d / %d = %d", operand1, operand2, operand1 / operand2);
            }
            else
            {
                printf("Error! Division by zero is not allowed.");
            }
            break;
        default:
            printf("Error! Operator is not correct.");
            break;
    }

    return 0;
}