#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
	char *dst_ = (char *) dst;
    char *src_ = (char *) src;
    unsigned long  i = 0;
	if ( n <= 0)
		return dst;
    for (; src_[i] != '\0' && i < n; i++) {
		
        dst_[i] = src_[i];
		if (src_[i] == c && c != 0)
			return dst_+i+1;
    }
    
    return NULL;
}
