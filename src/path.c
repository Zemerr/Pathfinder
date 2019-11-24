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
	
	for (int i = 1; myarr[i] != NULL; i++) {
		bufarr = mx_strsplit(myarr[i], '-');
		
			if (reflectlist(&my_list, bufarr[0]) == 0) {
				mx_push_back(&my_list, bufarr[0], count);
				count++;
			}

			bufarr2 = mx_strsplit(bufarr[1], ',');
			if (reflectlist(&my_list, bufarr2[0]) == 0) {
	        	mx_push_back(&my_list, bufarr2[0], count);
				count++;
			}
	}	
	mx_del_strarr(&bufarr);
	mx_del_strarr(&bufarr2);
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
			
	}
	return matrix;
}	


int main() {
	t_list *my_list = NULL;
	char **myarr = NULL;
	int **matrix = NULL;

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
	return 0;
}	
