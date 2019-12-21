#include "../inc/libmx.h"


void mx_del_intarr(int ***arr, int n) {
	int **j = *arr;
	for (int i = 0; i < n; i++) {
		free(j[i]);
	}
	free(*arr);
	*arr = NULL;
}


