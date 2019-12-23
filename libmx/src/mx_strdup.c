#include "../inc/libmx.h"

char *mx_strdup(const char *str) {
	char *strnew;

	strnew = mx_strnew(mx_strlen(str));
	strnew = mx_strcpy(strnew, str);
	return strnew;
}
