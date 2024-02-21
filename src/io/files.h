#ifndef __FILES_H__
#define __FILES_H__


#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

#define FILENAME_LEN 255
#define PATH_NAME_LEN 500

typedef struct FILE_INFO {
    char file_name[FILENAME_LEN];
    long size;
    char path[PATH_NAME_LEN];
    long start_position;
    long end_position;
    struct FILE_INFO *next;
} FileInfo;

char* root_path;
char root_path_ver[500];

void get_dirs(const char * path);

FileInfo *infos;

FileInfo *init();
FileInfo *add(char file_name[], long size, char path[], FileInfo *fileInfo);

#endif