#include "header.h"
struct vector * vector_init(){
    struct vector * res=malloc(sizeof(struct vector));
    res->tab=malloc(sizeof(ino_t)*256);
    res->capacity=256;
    res->size=0;
    return res;
}
void vector_append(struct vector * vec,ino_t elt){
    if (vec->size==vec->capacity){
        vec->tab=realloc(vec->tab,(vec->capacity+256)*sizeof(ino_t));
        vec->capacity+=256;
    }
    vec->tab[vec->size]=elt;
    vec->size++;
}
int is_in(struct vector *vec, ino_t elt){
    if(vec->size==0)
        return 0;
    for(size_t i=0; i<vec->size; i++){
        if(vec->tab[i]==elt)
            return 1;
    }
    return 0;
}
