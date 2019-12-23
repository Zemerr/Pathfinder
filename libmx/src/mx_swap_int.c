#include "../inc/libmx.h"

void mx_swap_int( int *i, int *y) {
    int buf = *i;
    *i = *y;
    *y = buf;
}
