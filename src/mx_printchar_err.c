#include "../inc/libmx.h"

void mx_printchar_err(char c) {	
    write(2, &c, 1);
}

