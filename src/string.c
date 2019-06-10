#include "header.h"
size_t my_strlen(char *s){
    size_t i=0;
    for(;s[i];i++);
    return i;
}
int my_strcmp(char *s1, char *s2){
    if(my_strlen(s1)!=my_strlen(s2))
        return 1;
    else{
        for(size_t i=0;s1[i]; i++){
            if(s1[i]!=s2[i]){
                return 1;
            }
        }
    }
    return 0;
}
char * concatenate(char *s1, char *s2){
    char *s3=calloc( (my_strlen(s1)+my_strlen(s2)+2), sizeof(char));
    size_t i=0;
    for(; s1[i]; i++){
        s3[i]=s1[i];
    }
    if(s3[i-1]!='/'){
        s3[i]='/';
        i++;
    }
    size_t j=0;
    for(; s2[j]; j++){
        s3[i+j]=s2[j];
    }
    return s3;
}
