#include "main.h"

int main(int argc, char* argv[]) {
    chose_operation(argv);
    return 0;
}

void chose_operation(char* argv[]){
    if (strcmp("help", argv[1]) == 0 || strcmp("-h", argv[1]) == 0){
        run_op_help();
    } else if (strcmp("version", argv[1]) == 0 || strcmp("-v", argv[1])) {
        show_version();
    } else {
        printf("ERR: CAN NOT FIND THE COMMAND: %s\n", argv[1]);
    }
}