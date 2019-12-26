#include "../inc/pathfinder.h"

bool mx_update_cycle(int ***allmat, int n, int *y) {
	int flag = 0;

	if ((*y) == n - 1) {     
		for (int z = 0; z < n; z++) {
		    if (allmat[1][2][z] != 1) {
		        flag = 1;
		        break;
		    }
		}
		if (flag == 1) {
			(*y) = 0;
		    return true;
		}
	}
	return false;
}

