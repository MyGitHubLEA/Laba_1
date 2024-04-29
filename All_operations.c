#include <stdlib.h> 
#include <string.h>
#include "Type_info.h" 
#include "Vector.h"
 
vector* vector_create(const struct type_info* type, int vector_length)
{
	vector* new_vector = malloc(sizeof(vector));
	new_vector->info = type;
	new_vector->length = vector_length;
	new_vector->ptr = malloc(type->size * vector_length);
	return new_vector;
}

element_ptr get(vector* vec, int i) 
{
	element_ptr value = malloc(vec->info->size);
	memcpy(value, (char*)vec->ptr + i * vec->info->size, vec->info->size);
	return value;
}

void set(vector* vec, int i, element_ptr value)
{
	memcpy((char*)vec->ptr + i * vec->info->size, value, vec->info->size);
}


void read_from_console(vector* vec)
{
	int len = vec->length;
	element_ptr value = malloc(vec->info->size);
	for (int i = 0; i < len; ++i) 
	{   
		vec->info->get_from_console(value);
		set(vec, i, value);
	}
	value = NULL;
	free(value);
}

void print(vector* vec)
{
	int len = vec->length;
	for (int i = 0; i < len; ++i)
		vec->info->print(get(vec, i));
}

void sum(vector* a, vector* b, vector* result)
{
	int len = a->length;
	element_ptr interim = malloc(sizeof(result->info->size));
	for (int i = 0; i < len; ++i)
	{
		result->info->add(interim, get(a, i), get(b, i));
		set(result, i, interim);
	}
	interim = NULL;
	free(interim);
}

void mult(vector* a, vector* b, element_ptr result)
{
	element_ptr interim = malloc(sizeof(a->info->size));
	memset(result, 0, a->info->size);
	int len = a->length;
	for (int i = 0; i < len; ++i)
	{
		a->info->multiply(interim, get(a, i), get(b, i));
		a->info->add(result, interim, result);
	}
	interim = NULL;
	free(interim);
}

void delete_vector(vector* vec)
{
	vec->ptr = NULL;
	free(vec->ptr);
	vec = NULL;
	free(vec);
}