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
    printf("\t\t--main [main runner]\t\t Choose the main execution file\n");
    printf("\t\t--config [config directory]\t Choose the configuration directory\n");
    printf("\t\t--icon [icon file or directory]\t Choose the icon file or directory\n");
    printf("\t\tpackage the application\n\n");
    printf("\tunpkg [package name] [directory name]\n");
    printf("\t-p [package name] [directory name]\n");
    printf("\t\tunpackage the application package into a directory\n\n");
    printf("\tlist\n");
    printf("\t-l\n");
    printf("\t\tShow the list of the installed package.\n");
}