#include "header.h"
int main(int argc,char **argv){
    char * path;
    int start=1;
    enum OPTION opt=P;
    struct vector * vec;
    if (argc==1){
        path=".";
        vec=vector_init();
        find(path,0,opt,vec);
        free(vec);
    }
    else{
        start++;
        if (my_strcmp(argv[1],"-H")==0){
            opt=H;
        }
        else if (my_strcmp(argv[1],"-d")==0){
            opt=D;
        }
        else if (my_strcmp(argv[1],"-L")==0){
            opt=L;
        }
        else if (my_strcmp(argv[1],"-P")==0){
            opt=P;
        }
        else if(argv[1][0]=='-'){
            printf("wrong option\n");
            return 1;
        }
            
        else{
            start--;
        } 
    }
    if(argc==2 && start==2){
        vec=vector_init();
        find(".",0,opt,vec);
        free(vec);
    }
    for(int i=start; i<argc; i++){
        vec=vector_init();
        path=argv[i];
        find(path,0,opt,vec);
        free(vec);
    }
    
    
    return 0;
}
