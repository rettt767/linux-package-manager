#include "read.h"



void io_main(char* path, char* packname){
    FILE * read_files;
    FILE * package;


}


PathInfo * init_head_node() {
    PathInfo * head_info = (PathInfo *) malloc(sizeof(PathInfo));
    if (!head_info) {
        return NULL;
    }
    head_info -> pre = NULL;
    head_info -> next = NULL;
    return head_info;
}

void free_memory(PathInfo * path_info) {
    if (!path_info) {
        return;
    }
    PathInfo *info = path_info;
    PathInfo *info1;
    while (info) {
        info1 = info -> next;
        info->pre = NULL;
        info->next = NULL;
        free(info);
        info = info1;
    }
    

}

int read_dir(const char *dir_path, PathInfo *path_info)
{
    DIR *dir = NULL;
    struct dirent *entry;
    struct stat sta;
    char path[PATH_LEN];
    PathInfo *pre = NULL, *last = NULL;
    int ret_val = 0;
    if(!dir_path || !path_info) {
        return -1;
    }
    dir = opendir(dir_path);
    if(dir == NULL) {
        return -2;
    }
    // 头节点存储用户输入的目录信息
    path_info->pre = NULL;
    path_info->next = NULL;
    path_info->is_dir = true;
    memset(path_info->name, 0, sizeof(path_info->name));
    memcpy(path_info->name, dir_path, MIN(strlen(dir_path), PATH_LEN - 1));
    while(1) {
        entry = readdir(dir);
        if(entry == NULL) {
            break;
        }
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        memset(path, 0, sizeof(path));
        strcpy(path, dir_path);
        if(path[strlen(path) - 1] != '/') {
            strcat(path, "/");
        }
        strcat(path, entry->d_name);
        if(stat(path, &sta) < 0) {
            ret_val = -3;
            break;
        }
        if(last) {
            pre = last;
        }
        last = (PathInfo *)malloc(sizeof(PathInfo));
        //printf("%s : malloc_memory = %p\n", __FUNCTION__, last);
        if(S_ISDIR(sta.st_mode)) {
            last->is_dir = true;
        }
        else {
            last->is_dir = false;
        }
        last->pre = pre;
        last->next = NULL;
        memset(last->name, 0, PATH_LEN);
        memcpy(last->name, entry->d_name, MIN(strlen(entry->d_name), PATH_LEN - 1));
        path_info->pre = last;
        if(pre) {
            pre->next = last;
        }
        else {
            path_info->next = last;
        }
    }
    closedir(dir);
    return ret_val;
}

int read_file_path(const char *dir_path, PathInfo *path_info)
{
    int ret_val;
    PathInfo info, *info2, info3, *info4;
    PathInfo *pre = NULL, *last = NULL;
    if(!dir_path || !path_info) {
        return -1;
    }
    // 头节点存储用户输入的目录信息
    path_info->pre = NULL;
    path_info->next = NULL;
    path_info->is_dir = true;
    memset(path_info->name, 0, sizeof(path_info->name));
    memcpy(path_info->name, dir_path, MIN(strlen(dir_path), PATH_LEN - 1));
    ret_val = read_dir_ex(dir_path, &info);
    if(ret_val == 0) {
        info2 = info.next;
        while(info2) {
            if(last) {
                pre = last; // 后续继续追加链表数据，在这里记录一下最后一个节点
            }
            if(info2->is_dir) {
                ret_val = read_file_path(info2->name, &info3);
                if(ret_val != 0) {
                    break;
                }
                if(info3.next) {
                    if(path_info->next) { // 头节点不为空，找到最后一个节点，将读取到的链表追加到最后一个节点后面
                        info3.next->pre = path_info->pre;
                        path_info->pre->next = info3.next;
                        path_info->pre = info3.pre;
                    }
                    else { // 头节点为空，直接将读取到的链表添加到头节点
                        path_info->pre = info3.pre;
                        path_info->next = info3.next;
                    }
                    last = path_info->pre;
                }
            }
            else {
                if(last) {
                    info2->pre = last;
                    last = info2;
                }
                else {
                    last = info2;
                }
                path_info->pre = last;
                if(pre) {
                    pre->next = last;
                }
                else {
                    path_info->next = last;
                }
            }
            info4 = info2;
            info2 = info2->next;
            // 释放目录信息结构体的内存
            if(info4->is_dir) {
                info4->pre = NULL;
                info4->next = NULL;
                //printf("%s : free_memory = %p\n", __FUNCTION__, info4);
                free(info4);
            }
        }
    }
    return ret_val;
}

int read_file_path_ex(const char *dir_path, PathInfo *path_info)
{
    int ret_val;
    PathInfo info, *info2, info3, *info4;
    PathInfo *pre = NULL, *last = NULL;
    if(!dir_path || !path_info) {
        return -1;
    }
    // 头节点存储用户输入的目录信息
    path_info->pre = NULL;
    path_info->next = NULL;
    path_info->is_dir = true;
    memset(path_info->name, 0, sizeof(path_info->name));
    memcpy(path_info->name, dir_path, MIN(strlen(dir_path), PATH_LEN - 1));
    ret_val = read_dir_ex(dir_path, &info);
    if(ret_val == 0) {
        info2 = info.next;
        while(info2) {
            if(last) {
                pre = last; // 后续继续追加链表数据，在这里记录一下最后一个节点
            }
            if(info2->is_dir) {
                ret_val = read_file_path_ex(info2->name, &info3);
                if(ret_val != 0) {
                    break;
                }
                if(info3.next) {
                    if(path_info->next) { // 头节点不为空，找到最后一个节点，将读取到的链表追加到最后一个节点后面
                        info3.next->pre = path_info->pre;
                        path_info->pre->next = info3.next;
                        path_info->pre = info3.pre;
                    }
                    else { // 头节点为空，直接将读取到的链表添加到头节点
                        path_info->pre = info3.pre;
                        path_info->next = info3.next;
                    }
                    last = path_info->pre;
                }
                else {
                    // 空文件夹
                    info4 = info2;
                    info2 = info2->next;
                    if(path_info->next) { // 头节点不为空，找到最后一个节点，将读取到的链表追加到最后一个节点后面
                        info4->pre = path_info->pre;
                        info4->next = NULL;
                        path_info->pre->next = info4;
                        path_info->pre = info4;
                    }
                    else { // 头节点为空，直接将读取到的链表添加到头节点
                        path_info->pre = info4;
                        path_info->next = info4;
                    }
                    last = path_info->pre;
                    continue; // 跳过下面的操作，继续处理下一个节点
                }
            }
            else {
                if(last) {
                    info2->pre = last;
                    last = info2;
                }
                else {
                    last = info2;
                }
                path_info->pre = last;
                if(pre) {
                    pre->next = last;
                }
                else {
                    path_info->next = last;
                }
            }
            info4 = info2;
            info2 = info2->next;
            // 释放目录信息结构体的内存
            if(info4->is_dir) {
                info4->pre = NULL;
                info4->next = NULL;
                //printf("%s : free_memory = %p\n", __FUNCTION__, info4);
                free(info4);
            }
        }
    }
    return ret_val;
}

int get_file_info(const char *file_path, struct stat *sta)
{
    if(!file_path || !sta) {
        return -1;
    }
    if(stat(file_path, sta) != 0) {
        return -2;
    }
    return 0;
}

void time_to_str(char *str, const size_t size, const time_t t)
{
    struct tm *tminfo = localtime(&t);
    strftime(str, size, "%Y-%m-%d %H:%M:%S", tminfo);
}