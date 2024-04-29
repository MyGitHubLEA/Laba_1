#pragma once

typedef struct {
	void* ptr; //elements
	int length;
	const struct type_info* info;
}vector;

typedef void* element_ptr;
element_ptr get (vector*, int);
void set(vector*, int, element_ptr);
vector* vector_create(const struct type_info* type, int vector_size);
void mult(vector*, vector*, element_ptr);
void sum(vector*, vector*, vector*);
void read_from_console(vector*);
void print(vector*);
void delete_vector(vector*);

// ------------------------------------
