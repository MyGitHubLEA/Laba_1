#include <stdio.h>
#include <string.h>
#include "Print_Functions.h"
#include "Complex.h"

void print_int(const element_ptr pointer)
{
    printf("%d ", *(int*)pointer);
}

void print_float(const element_ptr pointer)
{
	printf("%f ", *(float*)pointer);
}

void print_double(const element_ptr pointer)
{
	printf("%lf ", *(double*)pointer);

}

void print_complex(const element_ptr pointer)
{
	printf("%lf + i%lf ", (*(complex*)pointer).re, (*(complex*)pointer).im);
}

void read_int(element_ptr ptr)
{
	int res;
	scanf_s("%d", &res);
	memcpy(ptr, &res, sizeof(int));
}
void read_float(element_ptr ptr)
{
	float res = 0;
	scanf_s("%f", &res);
	memcpy(ptr, &res, sizeof(float));
}
void read_double(element_ptr ptr)
{   
	double res = 0;
	scanf_s("%lf", &res);
	memcpy(ptr, &res, sizeof(double));
}
void read_complex(element_ptr ptr)
{
	complex res = {0, 0};
	scanf_s("%lf%lf", &res.re, &res.im);
	memcpy(ptr, &res, sizeof(complex));
}