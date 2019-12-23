#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
	char *dst_ = (char *) dst;
    char *src_ = (char *) src;
	
	char *temp = mx_strnew(len);
	for(unsigned int i = 0; i < len; i++)
        temp[i] = src_[i];
    for(unsigned int i = 0; i < len; i++)
        dst_[i] = temp[i];
	free(temp); 
	return dst_;
	
}
