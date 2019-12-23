#include "../inc/libmx.h"
//#include <string.h>

void *mx_memchr(const void *s, int c, size_t n) {
	char *s_ = (char *) s;
	for (unsigned long i = 0; *s_ != 0 && i < n; s_++ && i++) {
		if (*s_ == c)
			return s_;
	}
	return NULL;
}
