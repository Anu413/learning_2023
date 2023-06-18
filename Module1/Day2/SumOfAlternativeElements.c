#include <stdio.h>
int sumAlternateElements(int arr[], size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i += 2)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int arr[100];
    size_t arraySize;
    printf("Enter the size of the array: ");
    scanf("%zu", &arraySize);
    printf("Enter the elements of the array:\n");
    for (size_t i = 0; i < arraySize; ++i) 
    {
        scanf("%d", &arr[i]);
    }
    int sum = sumAlternateElements(arr, arraySize);
    printf("Sum of alternate element: %d\n", sum);
    return 0;
}