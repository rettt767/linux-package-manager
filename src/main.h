#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <string.h>
#include "operation/help.h"
#include "operation/version.h"
#include "io/write.h"

void choose_operation(char* argv[]);
void choose_pkg_operation(char* argv[]);

#endif