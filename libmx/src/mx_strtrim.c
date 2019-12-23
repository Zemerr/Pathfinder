#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
	if ( str != NULL) {
		int i = 0;
		int n = mx_strlen(str);
		int len = 0;
		char *newstr;
		while (mx_isspace(str[n-1]) == 1)
            n--;
		while (mx_isspace(*str) == 1) {
			i++;
			str++;
		}
	
		len = n - i;
		newstr = mx_strnew(len);
		newstr = mx_strncpy(newstr, str, len);
		return newstr;
	}
	
	return NULL;
}
