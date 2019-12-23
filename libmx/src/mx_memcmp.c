#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
	char *s1_ = (char *) s1;
	char *s2_ = (char *) s2;
	unsigned int i = 0;
	for (; s1_[i] != '\0' &&  s2_[i] != '\0' && s1_[i] == s2_[i] && i < n-1; i++) {
	}
	return s1_[i]-s2_[i];
}
