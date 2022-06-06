 for (p=array; p < array+ARRAY_SIZE; p++) {
        p[0] = 0;
    }
    
 //p[n] mueve a p n unidades de memoria a la derecha
 //p=array pone el puntero en el inicio del array
 //array+ARRAYSIZE es la direccion de memoria del array + el tamaño del array
 //p++ mueve el puntero a la derecha porque le suma 1 a la direccion de memoria
 
 void set_name(name_t new_name, data_t *d) {
    for(unsigned int i=0u; i<sizeof(name_t); i++) {
      d->name[i] = new_name[i];
    }
}

//data_t *d significa que el puntero d apunta a algo del tipo data_t
//sizeof()devuelve el tamaño de algo en bytes

    set_name(messi_full_name, &messi); 
//&var devuelve la direccion de memoria de var

  printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", sizeof(messi.name), sizeof(messi.age), sizeof(messi.height), sizeof(messi));

&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

typedef struct s_pair_t pair_t;

struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(int x, int y) {
  pair_t pair = {x, y};
  return pair;
}


int pair_first(pair_t p) {
  return p.fst;
}

int pair_second(pair_t p) {
  return p.snd;
}

pair_t pair_swapped(pair_t p) {
  pair_t s = {p.snd, p.fst};
  return s;
}

pair_t pair_destroy(pair_t p) {
  return p;
}

