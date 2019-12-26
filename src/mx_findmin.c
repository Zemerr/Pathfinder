#include "../inc/pathfinder.h"

int mx_findmin(int **small_matrix, int n) {
	int num = 2147483647;
	int iter = 0;
	int flag = 0;
	int max_iter = 0;
	
	for (int i = 0; i < n; i++) {
		if (small_matrix[0][i] < num && small_matrix[0][i] != -1 && small_matrix[2][i] != 1) {
			num = small_matrix[0][i];
			iter = i;
		}
		if (small_matrix[0][i] == -1 && small_matrix[2][i] != 1 && flag == 0) {
			flag = 1;
			max_iter = i;
		}
	}
	if (num == 2147483647 && flag == 1)
		iter = max_iter;
	return iter;
}

