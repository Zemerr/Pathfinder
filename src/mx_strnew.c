#include "../inc/libmx.h"

char *mx_strnew(const int size) {
	int i = 0;
	char *str = (char*)malloc(sizeof(char) * size + 1);

	if (str == NULL)
		return NULL;

	while (i < size) {
		str[i] = '\0';
		i++;
	}

	str[i] = '\0';
	return str;
}
