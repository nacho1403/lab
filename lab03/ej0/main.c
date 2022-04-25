#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

unsigned int data_from_file(
  const char *path,
  unsigned int indexes[],
  char letters[],
  unsigned int max_size) {

  FILE *file = fopen(path, "r"); 

  unsigned int i;
  for(i=0; i<max_size && !feof(file); i=i+1 ){
    fscanf(file, "%u '%c'\n", &indexes[i], &letters[i]);
  }

  return i;
  //devuelve la length
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

void sort_letters(unsigned int indexes[], char letters[], unsigned int length) {
  for(unsigned int i=0; i<length; i++){
    unsigned int j = i;
    //Se incrementa j hasta que se encuentra la letra en posicion j que debe ir en la posicion i
    while(indexes[j] != i){
      j=j+1;
    }

    char tmpc;
    unsigned int tmpi;

    //Swap
    tmpi = indexes[j];
    tmpc = letters[j];

    indexes[j] = indexes[i];
    letters[j] = letters[i];

    indexes[i] = tmpi;
    letters[i] = tmpc;

  }
}

int main(int argc, char *argv[]) {
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    unsigned int length=0; 
    char *filepath = parse_filepath(argc, argv);

    length = data_from_file(filepath, indexes, letters, MAX_SIZE);
    sort_letters(indexes, letters, length);

    dump(letters, length);

    return EXIT_SUCCESS;
}



