#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
	if (s1 == NULL)
		return NULL;
	char *str = mx_strnew(n);
	str = mx_strncpy(str, s1, n);
	return str;
}
