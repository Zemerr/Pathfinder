#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
	char *s_ = (char *) s;
	for (unsigned int i = n-1; i > 0; i--) {
		if (s_[i] == c)
			return s_ + i;
	}
	if (s_[0] == c)
		return s_;
	return NULL;
}
