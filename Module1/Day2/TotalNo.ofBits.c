#include <stdio.h>
int countSetBitsHex(unsigned int num) 
{
    int count = 0;
    while (num != 0) 
    {
        count += num & 1;
        num >>= 1;
    }
    return count;
}
int totalSetBitsHex(unsigned int arr[], size_t size) 
{
    int totalBits = 0;
    for (size_t i = 0; i < size; ++i) 
    {
        totalBits += countSetBitsHex(arr[i]);
    }
    return totalBits;
}
int main() 
{
    unsigned int arr[100]; 
    size_t arraySize;
    printf("Enter the size of the array: ");
    scanf("%zu", &arraySize);
    printf("Enter the elements of the array (in hexadecimal):\n");
    for (size_t i = 0; i < arraySize; ++i) 
    {
        scanf("%x", &arr[i]);
    }
    int totalBits = totalSetBitsHex(arr, arraySize);
    printf("Total number of set bits in the array: %d\n", totalBits);
    return 0;
}