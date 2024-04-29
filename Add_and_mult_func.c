#include "Add_and_mult_func.h"
#include "Complex.h"

void add_int(element_ptr res, const element_ptr a, const element_ptr b)
{
	*(int*)res = *(int*)a + *(int*)b;
}

void add_float(element_ptr res, const element_ptr a, const element_ptr b)
{
	*(float*)res = *(float*)a + *(float*)b;
}

void add_double(element_ptr res, const element_ptr a, const element_ptr b)
{
	*(double*)res = *(double*)a + *(double*)b;
}

void add_complex(element_ptr res, const element_ptr a, const element_ptr b)
{
	(*(complex*)res).re = (*(complex*)a).re + (*(complex*)b).re;
	(*(complex*)res).im = (*(complex*)a).im + (*(complex*)b).im;
}

void mult_int(element_ptr res, const element_ptr a, const element_ptr b)
{
	*(int*)res = *(int*)a * *(int*)b;
}

void mult_float(element_ptr res, const element_ptr a, const element_ptr b)
{
	*(float*)res = *(float*)a * *(float*)b;
}

void mult_double(element_ptr res, const element_ptr a, const element_ptr b)
{
	*(double*)res = *(double*)a * *(double*)b;
}

void mult_complex(element_ptr res, const element_ptr a, const element_ptr b)
{
	(*(complex*)res).re = (*(complex*)a).re * (*(complex*)b).re - (*(complex*)a).im * (*(complex*)b).im;
	(*(complex*)res).im = (*(complex*)a).re * (*(complex*)b).im + (*(complex*)a).im * (*(complex*)b).re;
}
