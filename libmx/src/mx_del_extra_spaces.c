#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
	char *newstr;
	char *laststr;	
	int delim = 0;
	int chars = 0;
	int i = 0;
	newstr = mx_strtrim(str);
	for (;	newstr[i] != '\0'; i++) {
		if (mx_isprint(newstr[i]) == 1 && mx_isspace(newstr[i+1]) == 1)
			delim ++;
		if (mx_isprint(newstr[i]) == 1)
			chars++;
	}
	if (mx_isspace(newstr[i-1]) == 1)
		delim--;
	int p =  delim + chars;
	laststr = mx_strnew(p);
	
	int j = 0;
	for (int x = 0; newstr[x] != '\0'; x++) {
		if (mx_isspace(newstr[x]) != 1)  {
			laststr[j] = newstr[x];
			j++;
		}
		if (mx_isspace(newstr[x]) == 1 && mx_isprint(newstr[x-1]) == 1 && mx_isspace(newstr[x-1]) == 0) {
			laststr[j] = ' ';
             j++;
         }
	}
	free(newstr);
	return laststr; 
}
