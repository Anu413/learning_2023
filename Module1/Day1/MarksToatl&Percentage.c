#include <stdio.h>
#include <string.h>
void main()
{
    int RollNo,Physics,Chemistry,Maths,total;
    float percentage;
    char name[30];
    printf("Enter the Roll Number : ");
    scanf("%d",&RollNo);
    printf("Enter the Name  : ");
    scanf("%s",name);
    printf("Enter the Physics marks : ");
    scanf("%d",&Physics);
    printf("Enter the Chemistry marks : ");
    scanf("%d",&Chemistry);
    printf("Enter the Maths marks : ");
    scanf("%d",&Maths);
    total =Physics+Chemistry+Maths ;
    percentage = total/3.0;
    printf("Total marks = %d\n",total);
    printf("Percentage = %5.2f\n",percentage);
    if (percentage>=60)
    {
        printf("Rank = First");
    }
    else if (percentage<60 && percentage>=48)
    {
        printf("Rank = Second");
    }
    else if (percentage<48 && percentage>=36)
    {
        printf("Rank = Third");
    }
    else
    {
        printf("Rank = Fail");
    }
}