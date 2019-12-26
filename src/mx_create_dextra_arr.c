#include "../inc/pathfinder.h"

int *mx_create_dextra_arr(int iter, int i, int n) {

	int *second_num = (int *)malloc(sizeof(int)*3);
	second_num[0] = i;
	second_num[1] =  iter;
	second_num[2] =  n;

	return second_num;

}

