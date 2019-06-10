#include "header.h"
#include "tree.h"
enum TYPE get_type (char *t){
    if(!t)
        return ERROR_TYPE;
    switch(t[0]){
    case 'b':
        return BLOCK;
    break;
    case 'c':
        return CHAR;
    break;
    case 'd':
        return DIREC;
    break;
    case 'l':
        return SYM;
    break;
    case 'f':
        return REG;
    break;
    case 'p':
        return PIPE;
    break;
    case 's':
        return SOCK;
    break;
    default:
        return ERROR_TYPE;
    }
}

struct tree * tree_init(void){
    struct tree * res=malloc(sizeof(struct tree));
    res->left=NULL;
    res->right=NULL;
    res->data=NULL;
    return res;
}
