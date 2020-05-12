#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int find_file_or_folder(char *, char *);
int file_or_folder(char *, char*);

int main(){
    
    
    char *cur_path;
    cur_path = malloc(sizeof(char)*2000);
    
    strcpy(cur_path,".");
    
    char target_name[260];
    
    printf("Please input the file/folder name:\n");
    gets(target_name);
    
    find_file_or_folder(cur_path,target_name);
    
    printf("%s does not exist.\n",target_name);
    
    return 0;
}

int find_file_or_folder(char *path_name, char *target_name){
    
    DIR *p_dir;
    p_dir = opendir(path_name);
    
    if(p_dir == NULL){
        return -1;
    }
    
    struct dirent* p_entry = NULL;
    
    int len = strlen(path_name);
    
    while((p_entry = readdir(p_dir)) != NULL){
        
        if(strcmp(p_entry->d_name,".")==0 || 
            strcmp(p_entry->d_name,"..")==0){
            continue;
        }
        
        strcat(path_name,"/");
        strcat(path_name,p_entry->d_name);
        
        if(strcmp(p_entry->d_name,target_name)==0){
            
            file_or_folder(path_name,target_name);//print ans and exit
            
        }
        
        find_file_or_folder(path_name,target_name);
        
        path_name[len] = '\0';
    }
    
    closedir(p_dir);
    
    return 0;
}

int file_or_folder(char *path_name, char *target_name){
    
    DIR *p_dir;
    p_dir = opendir(path_name);
    if(p_dir != NULL){
        printf("%s is a sub-directory\n",target_name);
        closedir(p_dir);
    }
    else{
        FILE *p_file ;
        p_file = fopen(path_name,"r");
        
        if(p_file != NULL){
            printf("%s is a file\n",target_name);
        }
        else{
            printf("ERROR: %s is not a file or directory\n",target_name);
            exit(-1);
        }
        fclose(p_file);
    }
    exit(0);
    
}
