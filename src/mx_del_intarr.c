#include "../inc/libmx.h"


void mx_del_intarr(int ***arr, int n) {
	int **j = *arr;
	for (int i = 0; i < n; i++) {
		free(j[i]);
	}
	free(*arr);
	*arr = NULL;
}



// int main() {
// 	int n = 0;
// 	int **matrix = NULL;
	
// 	n = 5;
// 	matrix = (int **)malloc(sizeof(int *) * n);
// 	for (int i = 0; i < n; i++) {
// 		matrix[i] = (int *)malloc(sizeof(int) * n);
// 	}


//  for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             matrix[i][j] = -1;
//          }
//     }


	
// mx_del_intarr(&matrix, n);
// }
