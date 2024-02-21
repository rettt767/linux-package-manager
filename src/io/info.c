#include "files.h"

FileInfo *init()
{
    FileInfo *info = NULL;
    return info;
}

FileInfo *add(char file_name[], long size, char path[], FileInfo *fileInfo)
{
    if (fileInfo != NULL)
    {
        FileInfo *next;
        next->file_name = file_name;
        next->size = size;
        next->path = path;
        next->start_position = fileInfo->end_position + 1;
        next->end_position = fileInfo->end_position + 1 + size;
        next->next = NULL;
        while (fileInfo->next == NULL)
        {
            fileInfo = fileInfo->next;
        }
    }else{
        fileInfo->file_name = file_name;
        fileInfo->size = size;
        fileInfo->path = path;
        fileInfo->start_position = 0;
        fileInfo->end_position = size;
        fileInfo->next = NULL;
    }
    return fileInfo;
}