#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student 
{
    int rollno;
    char name[20];
    float marks;
};
void initializeArray(struct Student* students, int size, const char* input) 
{
    char* token;
    int i = 0;
    char buffer[100];
    strncpy(buffer, input, sizeof(buffer));
    token = strtok(buffer, " ");
    while (token != NULL && i < size) 
    {
        students[i].rollno = atoi(token);
        token = strtok(NULL, " ");
        strncpy(students[i].name, token, sizeof(students[i].name) - 1);
        token = strtok(NULL, " ");
        students[i].marks = atof(token);
        token = strtok(NULL, " ");
        i++;
    }
}
int main() 
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    while (getchar() != '\n');
    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));
    char input[100];
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    initializeArray(students, size, input);
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