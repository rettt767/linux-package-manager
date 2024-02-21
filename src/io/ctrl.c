#include "files.h"

char* substr(char* srcstr, int offset, int length)
{
    assert(length > 0);
    assert(srcstr != NULL);
 
    int total_length = strlen(srcstr);//首先获取srcstr的长度
    //判断srcstr的长度减去需要截取的substr开始位置之后，剩下的长度
    //是否大于指定的长度length，如果大于，就可以取长度为length的子串
    //否则就把从开始位置剩下的字符串全部返回。
    int real_length = ((total_length - offset) >= length ? length : (total_length - offset)) + 1;
    char *tmp;
    if (NULL == (tmp=(char*) malloc(real_length * sizeof(char))))
    {
        printf("Memory overflow . \n");
        exit(0);
    }
    strncpy(tmp, srcstr+offset, real_length - 1);
    tmp[real_length - 1] = '\0';
    return tmp;
}


char* get_last_dir(const char* path) {
    char str[500];
    sprintf(str, "%s", path);
    int len = strlen(str);
    int i;
    for (i = len; ( len - i) <= len; i--) {
        if (str[i] == '/') {
            break;
        }
    }
    return substr(path, i + 1, len - i);
}


void get_dirs(const char* path) {
    if (root_path == NULL) {
        char strs[500];
        sprintf(strs, "%s", path);
        int len = strlen(strs);
        int i;
        for (i = len; (len - i) <= len; i-- ) {
            if (strs[i] == '/') {
                break;
            }
        }
        root_path = substr(path, i + 1, len - i);
        sprintf(root_path_ver, "%s", root_path);
    }
    struct dirent *dirp = NULL;
    DIR *dir = opendir(path);
    struct stat st;
    char path2[500];
    char path3[500];
    while (dirp=readdir(dir)) {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0) continue;
        strcpy(path2, path);
        strcat(path2, "/");
        strcat(path2, dirp->d_name);
        stat(path2, &st);
        char* res = strstr(path2, root_path_ver);

        if (!S_ISDIR(st.st_mode)) {
            printf("name: %s type: %ld size: %ld path: %s\n", dirp->d_name, st.st_mode, st.st_size, res);
        }
        
        if (S_ISDIR(st.st_mode)) {
            get_dirs(path2);
        }
    }
    closedir(dir);

}
// The INFO
// int main() {
//     get_dirs("/home/retriblet/code/projects/java/market-server");
//     return 0;
// }