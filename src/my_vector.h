#if !defined(DYNAMIC_ARRAY)
#define DYNAMIC_ARRAY

#include <stdlib.h>
#include <stdio.h>

#define OBJECT_STRUCT_SIZE sizeof(Object)

// Object structure (change the object as you need)
typedef struct Object{
    int data;  // the data can be of any type
}Object;

// Dynamic List Structure (AKA Vector)
typedef struct Vector{
    size_t size; // the amount of object in the list
    Object* data;  // the data can be of any type
}Vector;

Vector new_vector()
{
    Vector vector;
    vector.size = 0;
    vector.data = NULL;
    return vector;
}

void delete_vector(Vector* vector)
{
    free(vector->data);
}

Object at_vector(Vector* vector, size_t index)
{
    if (vector->data == NULL || vector->size == 0) {
        printf("Operation on uninitialize vector\n");
        exit(1);
    }

    if (index < 0 || index >= vector->size) {
        printf("Index out of range\n");
        exit(1);
    }

    return vector->data[index];
}

void add_vector(Vector *vector, Object object)
{
    vector->data = (Object*)realloc(vector->data, vector->size * OBJECT_STRUCT_SIZE + OBJECT_STRUCT_SIZE);
    ++vector->size;

    if (vector->data == NULL || vector->size == 0) {
        printf("Operation on uninitialize vector\n");
        exit(1);
    }
    vector->data[vector->size - 1] = object;
}

#endif // DYNAMIC_ARRAY
