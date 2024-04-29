#include <stdlib.h>
#include "Type_info.h"
#include "Print_functions.h"
#include "Add_and_mult_func.h"
#include "Complex.h"

struct type_info* create_type_info(size_t size_of_element, binary_operation add_up_elements, binary_operation multiply_elements, element_setter read_element, void (*print_element)(const element_ptr))
{
	struct type_info* info = malloc(sizeof(struct type_info));
	info->size = size_of_element;
	info->add = add_up_elements;
	info->multiply = multiply_elements;
	info->get_from_console = read_element;
	info->print = print_element;
	return info;
}

const struct type_info* get_type_info_int(void) {
	struct type_info* info = create_type_info(sizeof(int), &add_int, &mult_int, &read_int, &print_int);
	return info;
}
const struct type_info* get_type_info_float(void) {
	struct type_info* info = create_type_info(sizeof(float), &add_float, &mult_float, &read_float, &print_float);
	return info;
}
const struct type_info* get_type_info_double(void) {
	struct type_info* info = create_type_info(sizeof(double), &add_double, &mult_double, &read_double, &print_double);
	return info;
}
const struct type_info* get_type_info_complex(void) {
	struct type_info* info = create_type_info(sizeof(complex), &add_complex, &mult_complex, &read_complex, &print_complex);
	return info;
}