#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student 
{
    int rollno;
    char name[20];
    float marks;
};
int compareByMarksDesc(const void* a, const void* b) 
{
    const struct Student* studentA = (const struct Student*)a;
    const struct Student* studentB = (const struct Student*)b;
    if (studentA->marks < studentB->marks) 
    {
        return 1;   // Return 1 if marks of studentB are greater
    }
    else if (studentA->marks > studentB->marks) 
    {
        return -1;  // Return -1 if marks of studentA are greater
    }
    else 
    {
        return 0;   // Return 0 if marks are equal
    }
}
void sortArrayByMarksDesc(struct Student* students, int size) 
{
    qsort(students, size, sizeof(struct Student), compareByMarksDesc);
}
void displayArray(struct Student* students, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }
}
int main() 
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));
    for (int i = 0; i < size; i++) 
    {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollno);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
        printf("\n");
    }
    sortArrayByMarksDesc(students, size);
    printf("\nSorted Array of Structures (Descending Order):\n");
    displayArray(students, size);
    free(students);
    return 0;
}