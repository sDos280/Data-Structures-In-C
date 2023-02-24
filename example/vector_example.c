#include "../src/my_vector.h"

int main()
{
    Vector vector = new_vector();

    add_vector(&vector, (Object){6});
    add_vector(&vector, (Object){-6});
    add_vector(&vector, (Object){67});
    add_vector(&vector, (Object){167});

    for (size_t i = 0; i < vector.size; i++){
        printf("%i\n", at_vector(&vector, i));
    }
    
    delete_vector(&vector);
}