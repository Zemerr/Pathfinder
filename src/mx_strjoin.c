#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
	char *new_s = NULL;
	if (s1 == NULL && s2 != NULL) {
		new_s = mx_strnew(mx_strlen(s2));
		new_s = mx_strcat(new_s, s2);
	}
	else if (s2 == NULL && s1 != NULL) {
    	new_s = mx_strnew(mx_strlen(s1));
    	new_s = mx_strcat(new_s, s1);
	}
	else if (s1 == NULL && s2 == NULL)
		return NULL;
	else {
		new_s = mx_strnew(mx_strlen(s1) + mx_strlen(s1));
		new_s = mx_strcat(mx_strcat(new_s, s1), s2);
	}
	return new_s;
}
