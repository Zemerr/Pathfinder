#include "../inc/pathfinder.h"


static int reflectlist(t_list **list, char *str) {
	
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

static void for_buf(char **bufarr2, char **bufarr, int *count, t_list *my_list) {
	char *tmp = NULL;

	if (reflectlist(&my_list, bufarr2[0]) == 0) {
			tmp =  mx_strdup(bufarr2[0]);
        	mx_push_back(&my_list, tmp, *count);
			(*count)++;
		}		
		mx_del_strarr(&bufarr);
		mx_del_strarr(&bufarr2);

}


t_list *mx_buildlist(char **myarr) {
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
			for_buf(bufarr2, bufarr, &count, my_list);
		}
	return my_list;
}
