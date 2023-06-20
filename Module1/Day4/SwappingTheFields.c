#include <stdio.h>
struct Point 
{
    int x;
    int y;
};
void swapStructures(struct Point* ptr1, struct Point* ptr2) {
    int temp = ptr1->x;
    ptr1->x = ptr2->x;
    ptr2->x = temp;
    temp = ptr1->y;
    ptr1->y = ptr2->y;
    ptr2->y = temp;
}
int main() 
{
    struct Point point1, point2;
    printf("Enter the x-coordinate of point1: ");
    scanf("%d", &(point1.x));
    printf("Enter the y-coordinate of point1: ");
    scanf("%d", &(point1.y));
    printf("Enter the x-coordinate of point2: ");
    scanf("%d", &(point2.x));
    printf("Enter the y-coordinate of point2: ");
    scanf("%d", &(point2.y));
    printf("\nOriginal Structures:\n");
    printf("Point 1: (%d, %d)\n", point1.x, point1.y);
    printf("Point 2: (%d, %d)\n", point2.x, point2.y);
    swapStructures(&point1, &point2);
    printf("\nStructures after Swapping:\n");
    printf("Point 1: (%d, %d)\n", point1.x, point1.y);
    printf("Point 2: (%d, %d)\n", point2.x, point2.y);
    return 0;
}