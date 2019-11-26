#include "../inc/libmx.h"


void mx_del_my_arr(char ***arr) {
	for (int i = 0; i < 2; i++) 
		mx_strdel(&(*arr)[i]);
	free(*arr);
	*arr = NULL;
}
