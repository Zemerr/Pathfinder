#include "../inc/pathfinder.h"

int *mx_create_dextra_arr(int iter, int i, int n, int y) {
	int *second_num = (int *)malloc(sizeof(int)*4);

	second_num[0] = i;
	second_num[1] = iter;
	second_num[2] = n;
	second_num[3] = y;
	return second_num;
}

