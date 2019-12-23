#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
	int i = 0;
	while (s1[i])
		i++;
	
	for (int j = 0; s2[j] != '\0'; j++) {
		s1[i] = s2[j];
		i++;
	}
	s1[i] = '\0';
	return s1;
	
}
