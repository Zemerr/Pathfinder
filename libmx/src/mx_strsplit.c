#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
	const char *first;
	char **arr = NULL;
	int count = 0;
	int len;
	int st;
	int l = 0;

	if (s == NULL) {
        return NULL;
    }
	int word = mx_count_words(s, c);
	
	first = s;
	arr = (char **)malloc(sizeof (char *) * word + 1);
	
	for	(int i = 0; first[i] != '\0'; i++) {
		if ((first[i] == c &&  first[i+1] != c && first[i+1] != '\0') || (i == 0 && first[i] != c))  {
			if (i != 0 || (i == 0 && first[i]  == c))
				i++;
			count = i;
			while (first[count]  != c && first[count]  != '\0')
				count++;
			len = count - i;
			arr[l] = mx_strnew(len);
			st = 0;
			while (first[i] !=c && first[i]  != '\0') {
				arr[l][st] = first[i];
				st++;
				i++;
			}
			i--;
			l++;
		}
	}
	arr[l] = NULL;
	return arr;
	
}
