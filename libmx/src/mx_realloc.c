#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
	char *temp;
	char *ptr_ = (char *) ptr;
	unsigned int len = mx_strlen(ptr_);
	if (ptr == NULL)
		ptr = mx_strnew(size);
	else if (ptr != NULL && size == 0) {
		free(ptr);
		return NULL;
	}
		
	else if (ptr != NULL && size > len) {
		
		temp = mx_strnew(len);
		temp = mx_memcpy(temp, ptr, len);
		ptr = mx_strnew(size);
		ptr = mx_memcpy(ptr, temp, len); 
		free(temp);
	}
	else if (ptr != NULL && size <= len && size > 0) {
		temp = mx_strnew(size);
        temp = mx_memcpy(temp, ptr, size);
        ptr = mx_strnew(size);
        ptr = mx_memcpy(ptr, temp, len);
        free(temp);
	}
	return ptr;
}
