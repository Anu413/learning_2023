#include <stdio.h>
void exponent_part(double x) 
{
    unsigned long long* ptr = (unsigned long long*)&x;
    unsigned long long bits = *ptr;
    unsigned long long exponent = (bits >> 52) & 0x7FF;
    printf("Hexadecimal: 0x%llx\n", exponent);
    printf("Binary: 0b");
    for (int i = 11; i >= 0; i--) 
    {
        unsigned long long bit = (exponent >> i) & 1;
        printf("%lld", bit);
    }
    printf("\n");
}
int main()
{
    double x ;
    printf("enter x value");
    scanf("%lf",&x);
    exponent_part(x);
    return 0;
}