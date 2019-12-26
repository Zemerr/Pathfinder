#include "../inc/pathfinder.h"

static int  **rebuilt_small_mat(int **small_mat, int n, int i) {	
		
	for(int q = 0; q < n; q++) {
		small_mat[1][q] = i;
	}			
	small_mat[0][i] = 0;	
	small_mat[2][i] = 1;
	return small_mat;

}

static int **small_matrix(int **matrix, char **myarr, int iter) {	
	int n = 0;
    int **small_matrix = NULL;
    n = mx_atoi(myarr[0]);
	small_matrix = (int **)malloc(sizeof(int *) *n+1);	
	for (int i = 0; i < 3; i++) {
		small_matrix[i] = (int *)malloc(sizeof(int) *n+1);
	}	
	for (int i = 0; i < 3; i++){		
		for (int j = 0; j < n; j++) {			
			if (i == 0) {				
				small_matrix[i][j] = matrix[iter][j];
			}
			else 
				small_matrix[i][j] = 0;
			}
	}	  	
	return small_matrix;
}

static void write_list(result_list *res) {
	result_list *buf = res;
	
	while(buf != NULL) {
		mx_printstr("========================================\n");
		mx_printstr("Path: ");
		mx_printstr(buf->Path);
		mx_printstr("\n");
		mx_printstr("Route: ");
		mx_printstr(buf->Route);
		mx_printstr("\n");
		mx_printstr("Distance: ");
		mx_printstr(buf->Distance);
		mx_printstr("\n");
		mx_printstr("========================================\n");
		buf = buf->next;
		}
}

void mx_find_path(int **matrix, char **myarr, t_list **list, int n) {	
	int **small_mat = NULL;
	int iter = 0;
	int *numbers = NULL;
	result_list *res = NULL;	
	int ***allmat = (int ***)malloc(sizeof(int ***)*2);
	
	for (int i = 0; i < n; i++) {				
		small_mat = small_matrix(matrix, myarr, i);				
		iter = mx_findmin(small_mat, n);		
		small_mat = rebuilt_small_mat(small_mat, n, i);
		numbers = mx_create_dextra_arr(iter, i, n);
		allmat[0] = matrix;
		allmat[1] = small_mat;		
		mx_dextra_mat( numbers, &res, list, allmat);		
		free(numbers);
		write_list(res);
		mx_freeOutput(&res);		
	}	
	free(allmat);
}
