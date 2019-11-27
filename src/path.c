#include <stdio.h>
#include <stdlib.h>
#include "../inc/libmx.h"


int mx_find_index(t_list **list, char *str) {
	t_list *buf = *list;
    while (buf != NULL) {
        if (mx_strcmp(str, buf->data) == 0) {
            return buf->count;
        }
        buf = buf->next;
    }
    return -1;
}

int reflectlist(t_list **list, char *str) {
	
	if (*list == NULL)
		return 0;
	t_list *buf = *list;
	while (buf != NULL) {
		if (mx_strcmp(str, buf->data) == 0) {
			return 1;
		}
		buf = buf->next;
	}
	return 0;
}
	

t_list *buildlist(char **myarr) {
	char **bufarr = NULL;
	char **bufarr2 = NULL;
	int count = 0;
	t_list *my_list = NULL;
	char *tmp = NULL;	
	for (int i = 1; myarr[i] != NULL; i++) {
		bufarr = mx_strsplit(myarr[i], '-');
		
			if (reflectlist(&my_list, bufarr[0]) == 0) {
				tmp = mx_strdup(bufarr[0]);
				mx_push_back(&my_list, tmp, count);
				count++;
			}

			bufarr2 = mx_strsplit(bufarr[1], ',');
			if (reflectlist(&my_list, bufarr2[0]) == 0) {
				tmp =  mx_strdup(bufarr2[0]);
	        	mx_push_back(&my_list, tmp, count);
				count++;
			}
		
			mx_del_strarr(&bufarr);
			mx_del_strarr(&bufarr2);
		}
	return my_list;
}

int **builmatrix(char **str) {
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
	
int **writematrix(t_list *my_list, int **matrix, char **myarr) {
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

int **small_matrix(int **matrix, char **myarr, int iter) {
	int n = 0;
    int **small_matrix = NULL;
    n = mx_atoi(myarr[0]);
	small_matrix = (int **)malloc(sizeof(int *) *n);

	for (int i = 0; i < 3; i++) {
		small_matrix[i] = (int *)malloc(sizeof(int) *n);
	}
	
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < n; j++) {
			if (i == 0) 
				small_matrix[i][j] = matrix[iter][j];
			else 
				small_matrix[i][j] = 0;
			}
	}
	   /* for (int i = 0; i < 3; i++) {
         for (int j = 0; j < 5; j++) {
            printf("%d   ", small_matrix[i][j]);
         }
        printf("\n");
		printf("\n");*/
//     }
	
	return small_matrix;

}

int findmin(int **small_matrix, int n) {
	int num = 2147483647;
	int iter = 0;
	
	for (int i = 0; i < n; i++) {
		if (small_matrix[0][i] < num && small_matrix[0][i] != -1) {
			num = small_matrix[0][i];
			iter = i;
		}
	}
	return iter;
}

void find_path(int **matrix, char **myarr) {
	int n = 0;
	int **small_mat = NULL;
	int iter = 0;

	n = mx_atoi(myarr[0]);
	for (int i = 0; i < n; i++) {
		small_mat = small_matrix(matrix, myarr, i);	
		iter = findmin(small_mat, n);
		
		printf("%d\n\n", iter);
		
		small_mat[0][i] = 0;
		small_mat[1][i] = i;
		small_mat[2][i] = 1;

		
		small_mat[1][iter] = i;
    //    small_mat[2][i] = 1;

			for (int y = 0; y < n; y++) {
				if (small_mat[2][y] != 1) {
					printf("Chhhheeek\n");
					if (small_mat[0][y] < small_mat[0][iter] + matrix[iter][y])
// &&
//						 (small_mat[0][y] != -1 && matrix[iter][y] != -1))
					 {
						printf("Chhhheeekkk1\n");
						small_mat[0][y] = small_mat[0][iter] + matrix[iter][y];
						small_mat[1][y] = iter;
						
	
					}
					
					else
						small_mat[1][y] = i;
					
					}
			}
		small_mat[2][iter] = 1;

		for (int i = 0; i < 3; i++) {
         for (int j = 0; j < 5; j++) {
            printf("%d   ", small_mat[i][j]);
         }
        printf("\n");
        printf("\n");
     }				
			
		printf("\n");
        printf("\n");
	}
}






int main() {
	t_list *my_list = NULL;
	char **myarr = NULL;
	int **matrix = NULL;
//	int **small_mat = NULL;

	myarr = mx_strsplit(mx_file_to_str("test"), '\n');
	
	
	my_list = buildlist(myarr);
	matrix = builmatrix(myarr);
	matrix = writematrix(my_list, matrix, myarr);
	 for (int i = 0; i < 5; i++) {
         for (int j = 0; j < 5; j++) {
            printf("%d   ", matrix[i][j]);
         }
        printf("\n");
     }
	printf("\n");
    printf("\n");	
	
	find_path(matrix, myarr);
	system("leaks -q a.out");
	return 0;
}	
