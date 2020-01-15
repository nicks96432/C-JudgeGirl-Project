#ifndef POLYNOMIAL_H

#define POLYNOMIAL_H
#define MAX_COEFFICIENT 4096
typedef struct _Polynomial
{
	int count;
	int coefficient[MAX_COEFFICIENT];
} Polynomial;
void init(Polynomial *poly, int coefficient[], int n);
Polynomial add(Polynomial *poly1, Polynomial *poly2);
Polynomial multiply(Polynomial *poly1, Polynomial *poly2);
void print(Polynomial *poly);

#endif /* POLYNOMIAL_H */