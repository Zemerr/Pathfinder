#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
	int i = 0;
	int count = 0;

	if (str == NULL)
		return -1;
	for (; str[i] != '\0'; i++) {
		
		if (str[i] == c && str[i+1] != '\0' && str[i+1] != c)
             count++;
	}
	if ((count != 0 && str[0] != c) || (count == 0 && str[i-1] == c && str[0] != c))
		count++;
	return count;
}

