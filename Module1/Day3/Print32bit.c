#include <stdio.h>
void printBits(unsigned int num) 
{
    int size = sizeof(num) * 8; 
    for (int i = size - 1; i >= 0; i--) 
    {
        unsigned int mask = 1u << i; 
        if (num & mask)
            printf("1");
        else
            printf("0");
        if (i % 8 == 0)
            printf(" ");
    }
    printf("\n");
}
int main() 
{
    unsigned int num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);
    printf("Binary representation: ");
    printBits(num);
    return 0;
}