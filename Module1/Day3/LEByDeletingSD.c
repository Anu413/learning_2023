#include <stdio.h>
int findLargestNumber(int num) 
{
    int largest = 0;
    int divisor = 1;
    int temp = num;
    while (divisor <= num) 
    {
        int digit = temp / divisor;
        int remainingNum = (temp / (divisor * 10)) * divisor + (temp % divisor);
        if (remainingNum > largest)
        {
            largest = remainingNum;
        }
        temp = num;
        divisor *= 10;
    }
    return largest;
}
int main() 
{
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);
    if (num < 1000 || num > 9999) 
    {
        printf("Invalid input. Please enter a 4-digit number.\n");
        return 1;
    }
    int largestNumber = findLargestNumber(num);
    printf("The largest number obtained by deleting a single digit: %d\n", largestNumber);
    return 0;
}