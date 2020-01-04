#include "../inc/pathfinder.h"



static char *path_creat(t_list **list, int i, int j) {
	char *path = NULL;
	char *one = NULL;
	char *two = NULL;
	
	one = mx_find_char(list, i);
    two = mx_find_char(list, j);
    
    path = mx_strjoin(DELIM, two);
    path = mx_strjoin_two(one, path);
    return path;

}

static char *Route_creat(t_list **list, int i, int j, int ***allmat) {
	char *Route = NULL;
 	char *buf = NULL; 	
 	int in = j; 	
 	int count = 0; 	
 	char *two = NULL; 

 	two = mx_find_char(list, j); 	
 	Route = mx_strjoin(Route, two);
 	while (in != i) {         		
 		count = allmat[1][1][in];
 		buf = mx_find_char(list, count);
 		Route = mx_strjoin_two(DELIM, Route);
 		Route = mx_strjoin_two(buf, Route);
 		in = count;
 	}

 	return Route;
}

static char *Distance_create(int i, int j, int ***allmat){   	
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

static int reflection_result_Route(t_result_list **list, char *Route) {	
	if(*list == NULL)
		return 0;
	t_result_list *buf = *list;
	while(buf != NULL) {
		if(mx_strcmp(buf->Route, Route) == 0)
			return 1;
		buf = buf->next;
	}
	return 0;

}

void mx_write_result(int *numbers, t_result_list **l, t_list **list, int ***allmat) {
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
     		tmp_info = mx_create_tmp_arr(path, distance, Route);
     		mx_write_in_list(l, tmp_info, path, list);     		
     	}     	 	
	     	mx_strdel(&path);
	     	mx_strdel(&Route);
	     	mx_strdel(&distance);
    }    
	mx_del_intarr(&allmat[1], 3);	
}

