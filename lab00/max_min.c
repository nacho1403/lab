//Laboratorio 0 Scavuzzo Ignacio

//Ejercicio 1

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>



struct max_min_result {
int max_value;
int min_value;
unsigned int max_position;
unsigned int min_position;
};

struct max_min_result compute_max_min(int array[], unsigned int length) {
    struct max_min_result result;
    assert(length > 0);
    int i = 0;
    result.max_value = -1000000000;
    result.min_value = 1000000000; 
    result.max_position = 0; 
    result.min_position = 0;
    while (length > i) {
        if (array[i] > result.max_value) {
            result.max_value = array[i];
            result.max_position = i;
        }
        if (array[i] < result.min_value) {
            result.min_value = array[i];
            result.min_position = i;
        }
        i = i + 1;
    }
    
return result;
}

int main() {    
    int length;
    int array[length];
    int i = 0;
    #define length 4
    while (length > i) {
        printf("Introduzca el valor a introducir en el arreglo: ");
        scanf("%d", &array[i]);
        i = i + 1;
    };
    struct max_min_result result = compute_max_min(array, length);
    printf("El maximo valor es: %d\n", result.max_value); 
    printf("El minimo valor es: %d\n", result.min_value); 
    printf("La posicion del maximo valor es: %u\n", result.max_position); 
    printf("La posicion del minimo valor es: %u\n", result.min_position);
    return 0;
}
