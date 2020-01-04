#include "../inc/pathfinder.h"



static int **builmatrix(char **str) {
	int n = 0;
	int **matrix = NULL;
	
	n = mx_atoi(str[0]);
	matrix = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++) {
		matrix[i] = (int *)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        matrix[i][j] = -1;
	     }
	}
	return matrix;
}
	
static int **writematrix(t_list *my_list, int **matrix, char **myarr) {
	int first = 0;
	int second = 0;
	int count = 0;
	char **bufarr = NULL;
    char **bufarr2 = NULL;
			
	for (int i = 1; myarr[i] != NULL; i++) {
		bufarr = mx_strsplit(myarr[i], '-');
		first = mx_find_index(&my_list, bufarr[0]);
		bufarr2 = mx_strsplit(bufarr[1], ',');
		second = mx_find_index(&my_list, bufarr2[0]);
		count = mx_atoi(bufarr2[1]);
		matrix[first][second] = count;
		matrix[second][first] = count;	
		mx_del_strarr(&bufarr);
        mx_del_strarr(&bufarr2);	
	}
	return matrix;
}	



int main(int argc, char **argv) {
	t_list *my_list = NULL;
	char **myarr = NULL;
	int **matrix = NULL;
	char *file = NULL;
	int n = 0;
	file = mx_file_to_str(argv[1]);	

	if (mx_allvalid(argc, file, argv[1])) {		
		myarr = mx_strsplit(file, '\n');		
		n = mx_atoi(myarr[0]);	
		my_list = mx_buildlist(myarr);		
		if (n != mx_list_size(my_list)) {			
			mx_printstr_err("error: invalid number of islands\n");			
			return 0;
		}		
		matrix = builmatrix(myarr);
		matrix = writematrix(my_list, matrix, myarr);		
		mx_find_path(matrix, myarr, &my_list, n);		
	}	
	return 0;
}	
