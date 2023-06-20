#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student 
{
    int rollno;
    char name[20];
    float marks;
};
void searchByName(struct Student* students, int size, const char* searchName) 
{
    int found = 0;
    for (int i = 0; i < size; i++) 
    {
        if (strcmp(students[i].name, searchName) == 0) 
        {
            printf("Student found:\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
        }
    }
    if (!found) 
    {
        printf("Student not found.\n");
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
    char searchName[20];
    printf("Enter the name of the student to search: ");
    scanf("%s", searchName);
    searchByName(students, size, searchName);
    free(students);
    return 0;
}