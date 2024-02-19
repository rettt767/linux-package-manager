#include "help.h"

void run_op_help() {
    printf("The usage of the lpk command: \n\n\n");
    printf("Basic command: \n");
    printf("\tinstall [Package Name]\n");
    printf("\t-i [Package Name]\n");
    printf("\t\tTo install the package\n\n");
    printf("\tuninstall [Package Name]\n");
    printf("\t-u [Package Name]\n");
    printf("\t\tTo uninstall the installed package\n\n");
    printf("\tpkg [directory name] [package name]\n");
    printf("\t-P [directory name] [package name]\n");
    printf("\t\tpackage the application\n\n");
    printf("\tunpkg [package name] [directory name]\n");
    printf("\t-p [package name] [directory name]\n");
    printf("\t\tunpackage the application package into a directory\n");
}