#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
	
	if (str == NULL || sub == NULL)
		return -2;	

	int n = mx_strlen(sub);
	for (int i = 0; str; str++ && i++) {
		if ( *str == '\0')
			return -1;
		if ( *str == *sub) {
			if ( mx_strncmp(str, sub, n) == 0) 
				return i;
		}
	}
	return -2;
}
