#include <assert.h>
#include "mybool.h"
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath) {
    unsigned int length;
    //abrir archivo
    FILE * file;
    file = fopen(filepath, "r");
    //tamaño
    fscanf(file, "%u", &length);
    //verifico que el maxsize este bien y sino toma el valor de length
    if(max_size < length) {
        length = max_size;
    }
    //lectura y agregado de los numeros
    for(unsigned int i = 0; i < length; i = i + 1) {
        fscanf(file, "%d", &array[i]);
    }
    //cerrado del archivo
    fclose(file);
    return length;
    
    }


void array_dump(int a[], unsigned int length) {
    printf("[");
    for(unsigned int i = 0; i < length; i = i + 1) {
        if (i != length-1) {
            printf(" %d,", a[i]);
        }
        else {
            printf(" %d", a[i]);
        }
    }
    printf("]\n");
}

mybool array_is_sorted(int a[], unsigned int length) {
    int arrayvalue = -1874919424;
    mybool ordenado = true; 
    for(unsigned int i = 0; i < length; i = i + 1) {
        if (a[i] < arrayvalue) {
            ordenado = false;
        }
        arrayvalue = a[i];
    }
    return ordenado;

}
void array_swap(int a[], unsigned int i, unsigned int j) {
    int guardadordevalordelai = a[i];
    a[i] = a[j];
    a[j] = guardadordevalordelai;
}


