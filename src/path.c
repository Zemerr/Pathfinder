#include <stdio.h>
#include <stdlib.h>
#include "../inc/libmx.h"

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

result_list *create_result(char *path, char *Route, char *distance) {
	result_list *new = (result_list *)malloc(sizeof(result_list));
	new->Path = path;
	new->Route = Route;
	new->Distance = distance;
	new->next = NULL;
	return new;
}


void mx_push_back_res(result_list **list, char **info) {	
    result_list *front = create_result(info[0], info[2], info[1]);
    result_list  *buf = *list;
	
	if (buf == 0) {
		*list  = front;
		return;
	}

    while ( buf->next != NULL)
        buf = buf -> next;
    buf -> next = front;
	
}

int find_my_index_two(char *Route_1, char *Route_2, t_list **l) {
	char *two = mx_strfind(Route_1, Route_2);
	char **two_p = mx_strsplit(two, ' ');
	char *two_point = NULL;
	int secondi = 0;

	if (two_p[1] == NULL) {
		mx_del_strarr(&two_p);
		return -1;
	}

	two_point = two_p[0];
	secondi = mx_find_index(l, two_point);
	mx_del_strarr(&two_p);
	return secondi;
}

int find_my_index_one(char *Route_1, char *Route_2, t_list **l) {
	char *two = mx_strfind(Route_1, Route_2);
	char **two_p = mx_strsplit(two, ' ');
	char *two_point = two_p[0];
	int secondi = mx_find_index(l, two_point);
	mx_del_strarr(&two_p);
	return secondi;
}

void creat_arr_list(char *Route_1, char *Route_2, t_list **l, int **arr) {
	int secondi = find_my_index_two(Route_1, Route_2, l);
	int firsti = find_my_index_one(Route_2, Route_1, l);

	(*arr)[0] = 0;
	(*arr)[1] = firsti;
	(*arr)[2] = secondi;

}

int *for_place_list() {
	int *arr = (int *)malloc(sizeof(int)*3);
	arr[0] = 0;
	arr[1] =  0;
	arr[2] =  0;
	return arr;
}

void push_in_list(result_list *buf, result_list *node, int *arr) {
	node->next =  buf->next;
    buf->next = node;
    free(arr);
}






void mx_push_onpalce(result_list **list, char **info, t_list **l) {	
	result_list *node = create_result(info[0], info[2], info[1]);
    result_list  *buf = *list;
    int *arr = for_place_list();
	
	if (buf == 0) {
		*list  = node;
		return;
	}
    for ( ; buf->next != NULL; buf = buf -> next) {
    	if ((buf->next != NULL && mx_strcmp(buf->next->Path, info[0]) == 0) || arr[0] == 1) {    		
    		creat_arr_list(info[2], buf->next->Route, l, &arr);
    		if (arr[1] > arr[2] || arr[2] == -1)
    			break;
    		if (arr[1] < arr[2] && buf->next->next != NULL 
    			&& mx_strcmp(buf->next->next->Path, info[0]) == 0)
    			arr[0] = 1;
    		else {
    			buf = buf -> next;
    			break;
    		}		
    	}    	
    }
    push_in_list(buf, node, arr);    
}

int reflection_result_Route(result_list **list, char *Route) {	
	if(*list == NULL)
		return 0;
	result_list *buf = *list;
	while(buf != NULL) {
		if(mx_strcmp(buf->Route, Route) == 0)
			return 1;
		buf = buf->next;
	}
	return 0;

}

int reflection_result_Path(result_list **list, char *Path) {	
	if(*list == NULL)
		return 0;
	result_list *buf = *list;
	while(buf != NULL) {
		if(mx_strcmp(buf->Path, Path) == 0)
			return 1;
		buf = buf->next;
	}
	return 0;

}





char *find_char(t_list **list, int index) {
	if (*list == NULL)
		return NULL;
	t_list *buf = *list;
	while (buf != NULL) {
		if (index == buf->count) {
			return buf->data;
		}
		buf = buf->next;
	}
	return NULL;

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
	small_matrix = (int **)malloc(sizeof(int *) *n+1);	
	for (int i = 0; i < 3; i++) {
		small_matrix[i] = (int *)malloc(sizeof(int) *n+1);
	}	
	for (int i = 0; i < 3; i++){		
		for (int j = 0; j < n; j++) {			
			if (i == 0) {
				//printf("%d       \n", matrix[iter][j]);
				small_matrix[i][j] = matrix[iter][j];
			}
			else 
				small_matrix[i][j] = 0;
			}
	}	  	
	return small_matrix;
}

int findmin(int **small_matrix, int n) {
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


void for_dextra_mat_one(int ***allmat, int y, int iter) {
  
			if (allmat[1][0][y] > allmat[1][0][iter] + allmat[0][iter][y] 
				|| allmat[1][0][y] == -1)

	     	{
		        if (allmat[0][iter][y] != -1) {		        
		            allmat[1][0][y] = allmat[1][0][iter] + allmat[0][iter][y];
		            allmat[1][1][y] = iter;
	           
	       		 }
	   		 }	
}

int ***create_second_dextra(int ***allmat, int iter, int y, int n) {
	int ***second = (int ***)malloc(sizeof(int ***) *n);
	second[1] = (int **)malloc(sizeof(int **) *n);

	for (int g = 0; g < 3; g++) {
		second[1][g] = (int *)malloc(sizeof(int) *n);
	}
	for (int g = 0; g < 3; g++){
		for (int j = 0; j < n; j++) {
			second[1][g][j] = allmat[1][g][j];			
		}
	}
	second[1][0][y] = second[1][0][iter] + allmat[0][iter][y];
    second[1][1][y] = iter;
    second[0] = allmat[0];
    second[2] = allmat[2];

    return second;
}

int *create_dextra_arr(int iter, int i, int n) {

	int *second_num = (int *)malloc(sizeof(int)*3);
	second_num[0] = i;
	second_num[1] =  iter;
	second_num[2] =  n;

	return second_num;

}

bool valid_for_second(int ***allmat, int y, int iter) {
	if (allmat[1][0][y] == allmat[1][0][iter] + allmat[0][iter][y] 
        && allmat[1][0][y] != -1 
        && allmat[0][iter][y] != -1 && allmat[1][1][y] != iter) 
	{
		return true;
	}
	return false;

}

bool valid_for_dextra(int ***allmat, int y, int iter) {
	if (allmat[1][2][y] != 1) {
        if ((allmat[1][0][y] != -1 && allmat[0][iter][y] != -1) 
        || (allmat[1][0][y] != -1 || allmat[0][iter][y] != -1)) 
        {
        	return true;
        }
    }
    return false;

}

bool update_cycle(int ***allmat, int n, int *y) {
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

char *path_creat(t_list **list, int i, int j) {
	char *path = NULL;
	char *one = NULL;
	char *two = NULL;
	
	one = find_char(list, i);
    two = find_char(list, j);
    
    path = mx_strjoin(DELIM, two);
    path = mx_strjoin_two(one, path);
    return path;

}

char *Route_creat(t_list **list, int i, int j, int ***allmat) {
	char *Route = NULL;
 	char *buf = NULL; 	
 	int in = j; 	
 	int count = 0; 	
 	char *two = NULL; 

 	two = find_char(list, j); 	
 	Route = mx_strjoin(Route, two);
 	while (in != i) {         		
 		count = allmat[1][1][in];
 		buf = find_char(list, count);
 		Route = mx_strjoin_two(DELIM, Route);
 		Route = mx_strjoin_two(buf, Route);
 		in = count;
 	}

 	return Route;
}

char *Distance_create(int i, int j, int ***allmat){   	
    int count = 0;
    char *distance = mx_itoa(allmat[1][0][j]);
    char *buf_dis = NULL;
    int point = j;

 	for (int in = j; in != i;) {
 		count = allmat[1][1][in];
 		if (count != i && in == j) 
 			distance = mx_strjoin_two(IS, distance);  		
 		if (count != i || (count == i && in != j)) {
 			buf_dis = mx_itoa(allmat[0][count][point]);
 			distance = mx_strjoin_both(buf_dis, distance);
 			if (count != i)
 		 		distance = mx_strjoin_two(PLUS, distance);
     		point = count;     	
    	 }
 		in = count;
 	}
 	return distance;
}
char **create_tmp_arr(char *path, char *distance, char *Route) {
	char **tmp_info = (char **)malloc(sizeof(char *) *4);
	tmp_info[0] = mx_strdup(path);
	tmp_info[1] = mx_strdup(distance);
	tmp_info[2] = mx_strdup(Route);
	tmp_info[3] = NULL;
	return tmp_info;

}


void write_in_list(result_list **l, char **tmp_info, char *path, t_list **list) {
	if (reflection_result_Path(l, path) == 0) {
		mx_push_back_res(l, tmp_info);
	}
	else {
		mx_push_onpalce(l, tmp_info, list);
	}     		
	free(tmp_info);
}


 

void write_result(int *numbers, result_list **l, t_list **list, int ***allmat) {
	int i = numbers[0];	
	char *path = NULL;
	char *Route = NULL;
	char *distance = NULL;
	char **tmp_info = NULL;

	for (int j = i+1; j < numbers[2]; j++) {         
    	path = path_creat(list, i, j);
       	Route = Route_creat(list, i, j, allmat);
      	distance = Distance_create(i, j, allmat);        
     	if (reflection_result_Route(l, Route) == 0) {
     		tmp_info = create_tmp_arr(path, distance, Route);
     		write_in_list(l, tmp_info, path, list);     		
     	}     	 	
	     	mx_strdel(&path);
	     	mx_strdel(&Route);
	     	mx_strdel(&distance);
    }    
	mx_del_intarr(&allmat[1], 3);	
}

void delete_two(char **str1, char **str2) {
	mx_del_strarr(&str1);
	mx_del_strarr(&str2);

}
void free_two(int *second_num, int ***second){
	free(second_num);
    free(second);
}

void dextra_mat(int *numbers, result_list **l, t_list **list, int ***allmat) {
	int ***second = NULL;
	int *second_num = NULL;

    for (int y = 0; y < numbers[2]; y++) {	            	
        if (valid_for_dextra(allmat, y, numbers[1])) {
             	for_dextra_mat_one(allmat, y, numbers[1]);		                 	
                if (valid_for_second(allmat, y, numbers[1])) {     
                	second = create_second_dextra(allmat, numbers[1], y, numbers[2]);						
					second_num = create_dextra_arr(numbers[1], numbers[0], numbers[2]);
                	dextra_mat(second_num, l, list, second);                        	
                	free_two(second_num, second);              
                }
            }        
        allmat[1][2][numbers[1]] = 1;
        if (update_cycle(allmat, numbers[2], &y)) {                
                numbers[1] = findmin(allmat[1], numbers[2]);		                
            }		      
    }        	
    write_result(numbers, l, list, allmat);
}

int  **rebuilt_small_mat(int **small_mat, int n, int i) {	
		
	for(int q = 0; q < n; q++) {
		small_mat[1][q] = i;
	}			
	small_mat[0][i] = 0;	
	small_mat[2][i] = 1;
	return small_mat;

}

void write_list(result_list *res) {
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

void find_path(int **matrix, char **myarr, t_list **list, int n) {	
	int **small_mat = NULL;
	int iter = 0;
	int *numbers = NULL;
	result_list *res = NULL;	
	int ***allmat = (int ***)malloc(sizeof(int ***)*2);
	
	for (int i = 0; i < n; i++) {				
		small_mat = small_matrix(matrix, myarr, i);				
		iter = findmin(small_mat, n);		
		small_mat = rebuilt_small_mat(small_mat, n, i);
		numbers = create_dextra_arr(iter, i, n);
		allmat[0] = matrix;
		allmat[1] = small_mat;		
		dextra_mat( numbers, &res, list, allmat);		
		free(numbers);
		write_list(res);
		mx_freeOutput(&res);		
	}	
	free(allmat);
}

bool validation_one(int i) {
	if (i == 1) {
		mx_printstr_err("usage: ./pathfinder [filename]\n");
		return false;
	}
	return true;
}

bool validation_two(char *myarr, char *name) {
	if (myarr == NULL) {
		mx_printstr_err("error: file ");
		mx_printstr_err(name);
		mx_printstr_err(" does not exist\n");
		return false;
	}
	return true;
}

bool validation_three(char *myarr) {
	if (mx_strlen(myarr) <= 0) {
		mx_printstr_err("error: file empty is empty\n");
		return false;
	}
	return true;
}

bool reflect_alpha(char *str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (!mx_isalpha(str[i]))
			return false;		
	}
	return true;
}

bool reflect_digit(char *str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (!mx_isdigit(str[i]))
			return false;		
	}
	return true;
}

void print_error_line(int i, char **myarr) {
	mx_del_strarr(&myarr);
	mx_printstr_err("error: line ");
	mx_printint_err(i+1);
	mx_printstr_err(" is not valid\n");

}

bool valid_delim(char **myarr) {
	int count_one = 0;
	int count_two = 0;

	for(int i = 1; myarr[i] != NULL; i++) {
		count_one = 0;
		count_two = 0;
		for (int j = 0; myarr[i][j] != '\0'; j++) {
			if (myarr[i][j] == '-') {
				count_one++;
				if (count_two > 0) {
					print_error_line(i, myarr);
					return false;
				}
			}
			if (myarr[i][j] == ',') 
				count_two++;
			}
			if (count_one != 1 || count_two != 1) {
				print_error_line(i, myarr);
				return false;
			}		
	}
	return true;
}





bool valid_island(char **myarr) {
	char **bufarr = NULL;
	char **bufarr2 = NULL;	

	for (int i = 1; myarr[i] != NULL; i++) {
		bufarr = mx_strsplit(myarr[i], '-');
			if (bufarr[1] == NULL ||reflect_alpha(bufarr[0]) == 0) {
				mx_del_strarr(&bufarr);
				print_error_line(i, myarr);				
				return false;				
			}
			bufarr2 = mx_strsplit(bufarr[1], ',');
			if (bufarr2[1] == NULL || reflect_alpha(bufarr2[0]) == 0 || !reflect_digit(bufarr2[1])) {
				delete_two(bufarr, bufarr2);				
				print_error_line(i, myarr);
				return false;
			}		
			delete_two(bufarr, bufarr2);
		}
	return true;
} 

bool validation_four(char *file) {
	
	char **myarr = mx_strsplit(file, '\n');	
	
	if (!mx_digit_str(myarr[0])) {
		mx_printstr_err("error: line 1 is not valid\n");
		mx_del_strarr(&myarr);
		return false;
	}
	if (!valid_delim(myarr))
		return false;	
	if (!valid_island(myarr))
		return false;	
	mx_del_strarr(&myarr);
	return true;
}



bool allvalid(int i, char *myarr, char *name) {
	if (!validation_one(i) || !validation_two(myarr, name) 
		|| !validation_three(myarr) || !validation_four(myarr)) 
		return false;
	return true;
}




int main(int argc, char **argv ) {
	t_list *my_list = NULL;
	char **myarr = NULL;
	int **matrix = NULL;
	char *file = NULL;
	int n = 0;
	file = mx_file_to_str(argv[1]);	

	if (allvalid(argc, file, argv[1])) {		
		myarr = mx_strsplit(file, '\n');		
		n = mx_atoi(myarr[0]);	
		my_list = buildlist(myarr);		
		if (n != mx_list_size(my_list)) {			
			mx_printstr_err("error: invalid number of islands\n");			
			return 0;
		}		
		matrix = builmatrix(myarr);
		matrix = writematrix(my_list, matrix, myarr);		
		find_path(matrix, myarr, &my_list, n);		
	}
	
	system("leaks -q a.out");
	return 0;
}	
