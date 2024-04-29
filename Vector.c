#include "Vector.h"
#include "Print_Functions.h"
#include "Type_info.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

vector* all_users_vectors[10000];
int amount_of_vectors = 0;


void creat_new_vector() {
    char user_answer[10];
    int size_of_vector;
    printf ("what type of vector do you want to create?(int/float/double/complex)\n");
    gets(user_answer);
    printf("what size vector do you want to create?\n");
    scanf_s("%d", &size_of_vector);
    const struct type_info* type_of_vector = NULL;
    switch (user_answer[0])
    {
    case('i'):
        type_of_vector = get_type_info_int();
        break;
    case('f'):
        type_of_vector = get_type_info_float();
        break;
    case('d'):
        type_of_vector = get_type_info_double();
        break;
    case('c'):
        type_of_vector = get_type_info_complex();
        break;
    }
    vector* user_vector = vector_create(type_of_vector, size_of_vector);
    printf("enter the values of the vector coordinates\n");
    read_from_console(user_vector);
    ++amount_of_vectors;
    all_users_vectors[amount_of_vectors] = user_vector;
    printf("A vector with a number %d was created\n", amount_of_vectors);
}

void summarise_vectors()
{
    int vec1, vec2;
    printf("select the vectors you want to add up\n");
    scanf_s("%d%d", &vec1, &vec2);
    vector* users_vector_sum = vector_create(all_users_vectors[vec1]->info, all_users_vectors[vec1]->length);
    sum(all_users_vectors[vec1] , all_users_vectors[vec2] , users_vector_sum);
    ++amount_of_vectors;
    all_users_vectors[amount_of_vectors] = users_vector_sum;
    printf("A vector with a number %d was created: ", amount_of_vectors);
    print(users_vector_sum);
    printf("\n");
}

void print_vector()
{
    int number;
    printf("select the number of the vector to be output\n");
    scanf_s("%d", &number);
    print(all_users_vectors[number]);
}

void multiply_vectors() {
    int vec1, vec2;
    printf("select the vectors you want to multiply\n");
    scanf_s("%d%d", &vec1, &vec2);
    element_ptr ptr = malloc(all_users_vectors[vec1]->info->size);
    mult(all_users_vectors[vec1], all_users_vectors[vec2], ptr);
    printf("the result of the multiplication is ");
    all_users_vectors[vec1]->info->print(ptr);
    ptr = NULL;
    free(ptr);
}

void delete_user_vector() 
{
    int number;
    printf("Specify the number of the vector you want to delete\n");
    scanf_s("%d", &number);
    delete_vector(all_users_vectors[number]);
    printf ("The vector with the number %d has been deleted\n", number);
}

void GetCommand(char* s)
{
    if (strncmp(s, "create_vector", 13)==0) creat_new_vector();
    if (strncmp(s, "summarise_vectors", 17)==0) summarise_vectors();
    if (strncmp(s, "multiply_vectors", 16)==0) multiply_vectors();
    if (strncmp(s, "print_vector", 12)==0) print_vector();
    if (strncmp(s, "delete_vector", 13) == 0) delete_user_vector();
}



int main() {
    char command[20];
    while (1) {
        printf("select an action: create_vector/summarise_vectors/multiply_vectors/print_vector/delete_vector\n");
        gets(command);
        GetCommand(command);
    }
}