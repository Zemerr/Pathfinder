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


void mx_push_back_res(result_list **list, char *Route, char *path, char *distance) {	
    result_list *front = create_result(path, Route, distance);
    result_list  *buf = *list;
	
	if (buf == 0) {
		*list  = front;
		return;
	}

    while ( buf->next != NULL)
        buf = buf -> next;
    buf -> next = front;
	
}

void mx_push_onpalce(result_list **list, char *Route, char *path, char *distance, t_list **l) {	
	result_list *node = create_result(path, Route, distance);
    result_list  *buf = *list;
    int flag = 0;
	
	if (buf == 0) {
		*list  = node;
		return;
	}
    while ( buf->next != NULL) {

    	if ((buf->next != NULL && mx_strcmp(buf->next->Path, path) == 0) || flag == 1) {
    		flag = 0;
    		
    		char *two = mx_strfind(Route, buf->next->Route);
    		char *one = mx_strfind(buf->next->Route, Route);

    		char **one_p = mx_strsplit(one, ' ');
    		char **two_p = mx_strsplit(two, ' ');

    		char *one_point = one_p[0];
    		char *two_point = two_p[0];

    		if (two_p[1] == NULL){
    			mx_del_strarr(&one_p);
    			mx_del_strarr(&two_p);
    			break;
    		}

    		int firsti = mx_find_index(l, one_point);
    		int secondi = mx_find_index(l, two_point);

    		mx_del_strarr(&one_p);
    		mx_del_strarr(&two_p);

    		//printf("%s  -  %d\n", one_point, firsti);
    		//printf("%s  -  %d\n", two_point, secondi);

    		if (firsti > secondi)
    				break;
    		if (firsti < secondi && buf->next->next != NULL && mx_strcmp(buf->next->next->Path, path) == 0)
    			flag = 1;
    		else {
    			buf = buf -> next;
    			break;
    		}


    		
    	}
    	 buf = buf -> next;
    }





    		

    	

    	// 	flag = -1;    		
    	// }
    	// if (flag == -1) {    		
    	// 	while (buf->next != NULL && mx_strcmp(buf->next->Path, path) == 0)

    	// 		buf = buf -> next;
    	// 	break;
    	// }
    //    buf = buf -> next;
        
  //  }
    node->next =  buf->next;
    buf->next = node;
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
//	printf("joker");				
	for (int i = 1; myarr[i] != NULL; i++) {
		bufarr = mx_strsplit(myarr[i], '-');
		first = mx_find_index(&my_list, bufarr[0]);
		bufarr2 = mx_strsplit(bufarr[1], ',');
		second = mx_find_index(&my_list, bufarr2[0]);
		count = mx_atoi(bufarr2[1]);
//		printf("chek\n");
//		printf("%d---", first);
//		printf("%d==", second);
//		printf("%d\n", count);
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
	  	
	return small_matrix;
}

int findmin(int **small_matrix, int n) {
	int num = 2147483647;
	int iter = 0;
	
	for (int i = 0; i < n; i++) {
		if (small_matrix[0][i] < num && small_matrix[0][i] != -1 && small_matrix[2][i] != 1) {
			num = small_matrix[0][i];
			iter = i;
		}
	}
	return iter;
}

void dextra_mat(int **matrix, int **small_mat, int *numbers, result_list **l, t_list **list) {

	int i = numbers[0];
	int iter = numbers[1];

 	//int copy = iter;

	int n =  numbers[2];
	int **second = NULL;
	int *second_num = NULL;
	            for (int y = i; y < n; y++) {

                if (small_mat[2][y] != 1) {

                    if ((small_mat[0][y] != -1 && matrix[iter][y] != -1) || (small_mat[0][y] != -1 || matrix[iter][y] != -1)) {
       
                        if (small_mat[0][y] > small_mat[0][iter] + matrix[iter][y] || small_mat[0][y] == -1)

                         {
                            if (matrix[iter][y] != -1) {
                            
                                small_mat[0][y] = small_mat[0][iter] + matrix[iter][y];
                                small_mat[1][y] = iter;
                            }
  

                        }

                        if (small_mat[0][y] == small_mat[0][iter] + matrix[iter][y] && small_mat[0][y] != -1 && matrix[iter][y] != -1 && small_mat[1][y] != iter) {
                        	second = (int **)malloc(sizeof(int *) *n);

							for (int g = 0; g < 3; g++) {
								second[g] = (int *)malloc(sizeof(int) *n);
							}
	
							for (int g = 0; g < 3; g++){
								for (int j = 0; j < n; j++) {
									second[g][j] = small_mat[g][j];
									
								}

							}

							
							
							second_num = (int *)malloc(sizeof(int)*3);
							second_num[0] = i;
							second_num[1] =  iter;
							second_num[2] =  n;

							       
                            second[0][y] = second[0][iter] + matrix[iter][y];
                            second[1][y] = iter;
                            

                        	dextra_mat(matrix, second, second_num, l, list);
                        	//printf("rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr\n\n\n");
                        	free(second_num);
                        	


                        }

                    }



            }
           
                small_mat[2][iter] = 1;


                if (y == n - 1) {
                    int flag = 0;
                    for (int z = 0; z < n; z++) {
                        if (small_mat[2][z] != 1) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1) {
                        y = 0;
                        iter = findmin(small_mat, n);
                    
                    }
                }

        }	

     //   printf("nnnop\n");
     //   printf("%d\n", i);
  //        for (int i = 0; i < 3; i++) {
  //        for (int j = 0; j < 5; j++) {
  //           printf("%d   ", small_mat[i][j]);

  //        }
  //       printf("\n");
  //       printf("\n");
  //    }


		// printf("\n");
  //       printf("\n"); 

		
         for (int j = i+1; j < n; j++) {
         	
        // 	printf("========================================\n");
         	char *one = find_char(list, i);
         	char *two = find_char(list, j);
         	char *delim = " -> ";
         	

         	char *path = mx_strjoin(delim, two);
         	path = mx_strjoin_two(one, path);


         	char *Route = NULL;
         	char *buf = NULL;
         	char *distance = mx_itoa(small_mat[0][j]);
         	char *is = " = ";
         	char *plus = " + ";
         	int in = j;
         	char *buf_dis = NULL;
         	int count = 0;
         	int point = j;
         	
         	Route = mx_strjoin(Route, two);
         	
         	



         	//printf("%s\n", Route);
         	while (in != i) {
         		
         		count = small_mat[1][in];
         		buf = find_char(list, count);
         		Route = mx_strjoin_two(delim, Route);
         		Route = mx_strjoin_two(buf, Route);




         		if (count != i && in == j) {
         			distance = mx_strjoin_two(is, distance);
         			
         		}

         		if (count != i || (count == i && in != j)) {
         			buf_dis = mx_itoa(matrix[count][point]);
         			distance = mx_strjoin_both(buf_dis, distance);
         			if (count != i)
         		 		distance = mx_strjoin_two(plus, distance);


		     		point = count;
		     	
		     	
		    	 }
		  

         		in = count;

         	}

         //	printf("Suka1");

         	

         	char *tmp_Route =  NULL;
         	char *tmp_distance =  NULL;
         	char *tmp_Path = NULL;

         	if (reflection_result_Route(l, Route) == 0) {
         	//	printf("Suka2 ");
         		tmp_Path = mx_strdup(path);
         		tmp_distance = mx_strdup(distance);
         		tmp_Route = mx_strdup(Route);
         	//	printf("Suka");
         		if (reflection_result_Path(l, path) == 0) {


         			mx_push_back_res(l, tmp_Route, tmp_Path, tmp_distance);
         		}
         		else {
         			mx_push_onpalce(l, tmp_Route, tmp_Path, tmp_distance, list);
         		}

         	}

  //         	result_list *bufff = *l;

  //         	while(bufff != NULL) {
		// 	printf("========================================\n");
		// 	printf("Path: %s\n", bufff->Path);
		// 	printf("Route: %s\n", bufff->Route);
		// 	printf("Distance: %s\n", bufff->Distance);
		// 	printf("========================================\n");
		// 	bufff = bufff->next;
		// }

         	

         //	printf("\n%s\n", path);
         //	printf("%s\n", Route);
        //	printf("%s\n", distance);


         	mx_strdel(&path);
         	mx_strdel(&Route);
         	mx_strdel(&distance);

         //	printf("Teeest%d\n", j);
         //	printf("Teeest%d\n", n);


         	//printf("cccccccccccccccccfdsfgdfhbthbdtrrbggerververgverbdez\n");


         	

        	}
        	








  //       for (int i = 0; i < 3; i++) {
  //        for (int j = 0; j < 5; j++) {
  //           printf("%d   ", small_mat[i][j]);

  //        }
  //       printf("\n");
  //       printf("\n");
  //    }


		// printf("\n");
  //       printf("\n");


mx_del_intarr(&small_mat, 3);

}



void find_path(int **matrix, char **myarr, t_list **list) {	
	int **small_mat = NULL;
	int iter = 0;
	int *numbers = NULL;
	result_list *res = NULL;
	result_list *buf = NULL;	
	int n = mx_atoi(myarr[0]);

	for (int i = 0; i < n; i++) {
		
		small_mat = small_matrix(matrix, myarr, i);	
		iter = findmin(small_mat, n);
		for(int q = 0; q < n; q++) {
			small_mat[1][q] = i;
		}		

		
		small_mat[0][i] = 0;
		small_mat[1][i] = i;
		small_mat[2][i] = 1;

		
		small_mat[1][iter] = i;
    
		numbers = (int *)malloc(sizeof(int)*3);
		numbers[0] = i;
		numbers[1] =  iter;
		numbers[2] =  n;
		dextra_mat(matrix, small_mat, numbers, &res, list);
		free(numbers);
		buf = res;
		while(buf != NULL) {
			printf("========================================\n");
			printf("Path: %s\n", buf->Path);
			printf("Route: %s\n", buf->Route);
			printf("Distance: %s\n", buf->Distance);
			printf("========================================\n");
			buf = buf->next;
		}
		mx_freeOutput(&res);
		//mx_del_intarr(&small_mat, 3);
		
	}
}




int main() {
	t_list *my_list = NULL;
	char **myarr = NULL;
	int **matrix = NULL;
	char *file = mx_file_to_str("test2");
//	int **small_mat = NULL;

	myarr = mx_strsplit(file, '\n');
	
	
	my_list = buildlist(myarr);
	matrix = builmatrix(myarr);
	matrix = writematrix(my_list, matrix, myarr);
	//  for (int i = 0; i < 5; i++) {
 //         for (int j = 0; j < 5; j++) {
 //            printf("%d   ", matrix[i][j]);
 //         }
 //        printf("\n");
 //    }
	// printf("\n");
 //    printf("\n");	

    // int n = 4;
    // mx_del_intarr(&matrix, n);

	
	find_path(matrix, myarr, &my_list);
	system("leaks -q a.out");
	return 0;
}	
