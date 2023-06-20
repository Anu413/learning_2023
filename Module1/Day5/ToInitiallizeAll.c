#include <stdio.h>
#include <string.h>
struct Student 
{
    int rollno;
    char name[20];
    float marks;
};
void initializeArray(struct Student* students, int size) 
{
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
}
int main() 
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));
    initializeArray(students, size);
    printf("\nInitialized Array of Structures:\n");
    for (int i = 0; i < size; i++) 
    {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }
    free(students);
    return 0;
}