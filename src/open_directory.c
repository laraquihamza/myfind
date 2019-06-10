#include "header.h"
DIR * open_directory( char * path){
    DIR *res=opendir(path);
    if(!res){
        if (errno==ENOTDIR){
            printf("%s\n",path);
        }
        else{
            fprintf(stderr,"fail open :%s!\n",path);
        }
    }
    return res;
}
