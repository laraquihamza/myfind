#include "header.h"
void find(char *path, int mode, enum OPTION option,struct vector * vec){
    struct stat tmp;
    lstat(path,&tmp);
    if(S_ISLNK(tmp.st_mode)==1 && (option==P)){
        printf("%s\n",path);
        return;
    }
    DIR * a= open_directory(path);
    if (!a)
        return ;

    struct dirent *entry=readdir(a);
    if(option!=D){
        if(mode==0){
            printf("%s\n",path);
        }
    }
    char c='/';
    size_t i=0;
    char * file;
    while(entry){
        if (i>1){
            if (path[my_strlen(path)-1]=='/')
                c='\0';
            if(option==D){
                if (entry->d_type ==DT_DIR || (entry->d_type==0 && option== L)){
                    if(is_in(vec,entry->d_ino)==0){
                        vector_append(vec,entry->d_ino);
                        file=concatenate(path,entry->d_name);
                        find(file,1,option,vec);
                    }
                    else{
                        printf("loop detected\n");
                    }
                }
                printf("%s%c%s\n",path,c,entry->d_name);                
            }
            else{
                printf("%s%c%s\n",path,c,entry->d_name);
                if (entry->d_type ==DT_DIR || (entry->d_type==0 && option== L)){
                    if(is_in(vec,entry->d_ino)==0){
                        vector_append(vec,entry->d_ino);
                        file=concatenate(path,entry->d_name);
                        find(file,1,option,vec);
                    }
                    else{
                        printf("loop detected\n");
                    }
                }
            }
        }
        entry=readdir(a);
        i++;
    }
    if(option==D){
        if(mode==0){
            printf("%s\n",path);
        }
    }

    if(mode==1){
        free(path);
    }
}
