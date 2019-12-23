#include "../inc/libmx.h"

bool mx_cmp(void *s1, void *s2) {
    char *s1_ = (char *) s1;
    char *s2_ = (char *) s2;
    if (mx_strcmp(s1_, s2_) > 0)
        return true;
    else
        return false;
}
