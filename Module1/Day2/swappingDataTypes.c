#include <stdio.h>
#include <string.h>
void swap(void* a, void* b, size_t size) 
{
    char* temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}
void printIntArray(int arr[], size_t size) 
{
    for (size_t i = 0; i < size; ++i) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() 
{
    int x,y;
    printf("Enter x and y:");
    scanf("%d%d",&x,&y);
    printf("Before swapping: x = %d, y = %d\n", x, y);
    swap(&x, &y, sizeof(int));
    printf("After swapping: x = %d, y = %d\n", x, y);
    float a,b;
    printf("Enter a and b:");
    scanf("%f%f",&a,&b);
    printf("Before swapping: a = %f, b = %f\n", a, b);
    swap(&a, &b, sizeof(float));
    printf("After swapping: a = %f, b = %f\n", a, b);
    char str1[20],str2[20];
    printf("enter strings:");
    scanf("%s %s",&str1,&str2);
    printf("Before swapping: str1 = %s str2 = %s\n", str1, str2);
    swap(&str1, &str2, sizeof(char*));
    printf("After swapping: str1 = %s str2 = %s\n", str1, str2);
    int intArray[] = {1, 2, 3, 4, 5};
    size_t arraySize = sizeof(intArray) / sizeof(int);
    printf("Before swapping: intArray = ");
    printIntArray(intArray, arraySize);
    swap(&intArray[1], &intArray[3], sizeof(int));
    printf("After swapping: intArray = ");
    printIntArray(intArray, arraySize);
    return 0;
}