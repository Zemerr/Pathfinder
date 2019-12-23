#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
	
    int n = 0;
	int len_rep = 0;
	int len_str = 0;
	int j = 0;
	int y = 0;
	int count = 0;
	int new_len = 0;
	char *newstr = NULL;	
	
	if (sub == NULL || str == NULL || replace == NULL)
		return NULL;

	n = mx_strlen(sub);
    len_rep = mx_strlen(replace);
    len_str = mx_strlen(str);       
    count = mx_count_substr(str, sub);
    new_len = len_str - (count * n) + (count * len_rep);
    newstr = mx_strnew(new_len);

	
    for (; *str != '\0'; str++) {
        if ( *str == *sub) {
            if ( mx_strncmp(str, sub, n) == 0) {
				y = 0;
                while ( replace[y] != '\0') {
        			newstr[j] = replace[y];
					y++;
					j++;
				}
			str = str + n - 1;
			}
			else {
				newstr[j] = *str;
 	            j++;
			}		
		}
		else {
			newstr[j] = *str;
			j++;
		}
	}
    
	return newstr;
}
