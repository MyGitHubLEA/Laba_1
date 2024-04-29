#pragma once
#include <stdio.h> 

typedef void* element_ptr;

typedef void (*binary_operation)(element_ptr result, const element_ptr arg1, const element_ptr arg2);
typedef void (*element_setter)(element_ptr value);

typedef struct type_info {
	size_t size; 
	binary_operation add;
	binary_operation multiply;
	element_setter get_from_console;
	void (*print)(const element_ptr value);
};

struct type_info* create_type_info(size_t, binary_operation, binary_operation, element_setter, void (*)(const element_ptr));


const struct type_info* get_type_info_int(void);
const struct type_info* get_type_info_float(void);
const struct type_info* get_type_info_double(void);
const struct type_info* get_type_info_complex(void);
