#include "../inc/pathfinder.h"

void mx_free_two(int *second_num, int ***second) {
	free(second_num);
    free(second);
}
