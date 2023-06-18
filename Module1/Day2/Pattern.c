#include <stdio.h>
void printNumbers(int n) 
{
    for (int i = 1; i <= n; i++) 
    {
        printf("%d", i);
    }
}
void printSpaces(int n) 
{
    for (int i = 1; i <= n; i++) 
    {
        printf(" ");
    }
}
void printReverseNumbers(int n) 
{
    for (int i = n; i >= 1; i--) 
    {
        printf("%d", i);
    }
}
int main() 
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    for (int i = n; i >= 1; i--) 
    {
        printNumbers(i);
        printSpaces(2 * (n - i));
        printReverseNumbers(i);
        printf("\n");
    }
    return 0;
}