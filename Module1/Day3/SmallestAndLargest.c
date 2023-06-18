#include <stdio.h>
void findSmallestLargestDigits(int numbers[], int count) 
{
    for (int i = 0; i < count; i++) 
    {
        int num = numbers[i];
        int smallestDigit = 9;  
        int largestDigit = 0;   
        if (num <= 0) 
        {
            printf("Number %d: Not Valid\n", num);
            continue;
        }
        while (num != 0) 
        {
            int digit = num % 10;
            if (digit < smallestDigit) 
            {
                smallestDigit = digit;
            }
            if (digit > largestDigit) 
            {
                largestDigit = digit;
            }
            num /= 10;
        }
        printf("Number %d: Smallest digit = %d, Largest digit = %d\n", numbers[i], smallestDigit, largestDigit);
    }
}
int main() 
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n <= 0) 
    {
        printf("Not Valid\n");
        return 0;
    }
    int numbers[n];
    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &numbers[i]);
    }
    findSmallestLargestDigits(numbers, n);
    return 0;
}