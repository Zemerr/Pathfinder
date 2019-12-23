#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
	int end = size - 1;
	int start = 0;
	int middle = 0;
	*count = 0;

	while (start <= end) {
		middle = (start + end)/2;
		*count += 1;
		if (mx_strcmp(s, arr[middle]) < 0)
			end = middle - 1;
		else if (mx_strcmp(s, arr[middle]) > 0)
			start = middle + 1;
		else 
			return middle;
	}

	*count = 0;
	return -1;
}
