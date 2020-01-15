#include "../inc/pathfinder.h"

static int reflection_result_Path(t_result_list **list, char *Path) {	
	if(*list == NULL)
		return 0;
	t_result_list *buf = *list;
	while(buf != NULL) {
		if(mx_strcmp(buf->Path, Path) == 0)
			return 1;
		buf = buf->next;
	}
	return 0;

}

static void push_back_res(t_result_list **list, char **info) {	
    t_result_list *front = mx_create_result(info[0], info[2], info[1]);
    t_result_list  *buf = *list;
	
	if (buf == 0) {
		*list  = front;
		return;
	}

    while (buf->next != NULL)
        buf = buf -> next;
    buf -> next = front;
	
}



void mx_write_in_list(t_result_list **l, char **tmp_info, char *path, t_list **list) {
	if (reflection_result_Path(l, path) == 0) {	
		push_back_res(l, tmp_info);
	}
	else {
		mx_push_onpalce(l, tmp_info, list);	
	}   		
	free(tmp_info);
}

