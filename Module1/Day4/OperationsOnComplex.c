#include <stdio.h>
struct Complex 
{
    float real;
    float imaginary;
};
void readComplex(struct Complex* complexPtr) 
{
    printf("Enter the real part of the complex number: ");
    scanf("%f", &(complexPtr->real));
    printf("Enter the imaginary part of the complex number: ");
    scanf("%f", &(complexPtr->imaginary));
}
void writeComplex(struct Complex complex) 
{
    printf("Complex number: %.2f + %.2fi\n", complex.real, complex.imaginary);
}
struct Complex addComplex(struct Complex complex1, struct Complex complex2) 
{
    struct Complex result;
    result.real = complex1.real + complex2.real;
    result.imaginary = complex1.imaginary + complex2.imaginary;
    return result;
}
struct Complex multiplyComplex(struct Complex complex1, struct Complex complex2) 
{
    struct Complex result;
    result.real = (complex1.real * complex2.real) - (complex1.imaginary * complex2.imaginary);
    result.imaginary = (complex1.real * complex2.imaginary) + (complex1.imaginary * complex2.real);
    return result;
}
int main() 
{
    struct Complex complex1, complex2;
    printf("Enter the first complex number:\n");
    readComplex(&complex1);
    printf("Enter the second complex number:\n");
    readComplex(&complex2);
    printf("First complex number:\n");
    writeComplex(complex1);
    printf("Second complex number:\n");
    writeComplex(complex2);
    struct Complex addition = addComplex(complex1, complex2);
    printf("Addition of the two complex numbers:\n");
    writeComplex(addition);
    struct Complex multiplication = multiplyComplex(complex1, complex2);
    printf("Multiplication of the two complex numbers:\n");
    writeComplex(multiplication);
    return 0;
}
