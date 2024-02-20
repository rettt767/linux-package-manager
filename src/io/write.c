#include "write.h"

void create_file (char * file_name) {
    FILE *file;
    file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Can not open the file");
    }

    fprintf(file, "Hello");

    if (fclose(file) != 0) {
        printf("Can not close the file");
    }

}

