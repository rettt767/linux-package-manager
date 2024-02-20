#ifndef __FILES_H__
#define __FILES_H__

#define PATH_LEN 256

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

typedef struct PATH_INFO {
    struct PATH_INFO * pre;
    struct PATH_INFO * next;
    bool is_dir;
    char name[PATH_LEN];
    
} PathInfo;

PathInfo *init_head_node();
void free_memory(PathInfo *path_info);
int read_dir(const char *dir_path, PathInfo *path_info);
int read_dir_ex(const char *dir_path, PathInfo *path_info);
int read_file_path(const char *dir_path, PathInfo *path_info);
int read_file_path_ex(const char *dir_path, PathInfo *path_info);

#endif