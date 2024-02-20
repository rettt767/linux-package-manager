#include "main.h"

int main(int argc, char* argv[]) {
    choose_operation(argv);
    return 0;
}

void choose_operation(char* argv[]){
    if (strcmp("help", argv[1]) == 0 || strcmp("-h", argv[1]) == 0){
        run_op_help();
    } else if (strcmp("version", argv[1]) == 0 || strcmp("-v", argv[1])) {
        show_version();
    } else if (strcmp("pkg", argv[1]) == 0 || strcmp("-P", argv[1]) == 0) {
        choose_pkg_operation(argv);
    } else if (strcmp("test", argv[1]) == 0) {
        create_file(argv[1]);
    } else {
        printf("ERR: CAN NOT FIND THE COMMAND: %s\n", argv[1]);
    }
}

void choose_pkg_operation(char* argv[]){
    if (strcmp("--main", argv[2]) == 0) {

    } else if (strcmp("--config", argv[2]) == 0) {

    } else if (strcmp("--icon", argv[2]) == 0) {

    } else {
        
    }
}