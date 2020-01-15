#include "../inc/pathfinder.h"



static int *for_place_list() {
    int *arr = (int *)malloc(sizeof(int)*3);
    arr[0] = 0;
    arr[1] =  0;
    arr[2] =  0;
    return arr;
}

static void push_in_list(t_result_list *buf, t_result_list *node, int *arr) {
    node->next =  buf->next;
    buf->next = node;
    free(arr);
}



static void cycle_list(t_result_list  **buf, int *arr, char **info, t_list **l) {
    for ( ; (*buf)->next != NULL; (*buf) = (*buf) -> next) {
         if (((*buf)->next != NULL && mx_strcmp((*buf)->next->Path, info[0]) == 0) || arr[0] == 1) {           
             mx_creat_arr_list(info[2], (*buf)->next->Route, l, &arr);
             if (arr[1] > arr[2] || arr[2] == -1)
                 break;
             if (arr[1] < arr[2] && (*buf)->next->next != NULL 
                 && mx_strcmp((*buf)->next->next->Path, info[0]) == 0)
                 arr[0] = 1;
             else {
                 (*buf) = (*buf) -> next;
                 break;
             }       
         }       
    }
}

void mx_push_onpalce(t_result_list **list, char **info, t_list **l) {	
	t_result_list *node = mx_create_result(info[0], info[2], info[1]);
    t_result_list  *buf = *list;
    int *arr = for_place_list();
    
	
	if (buf == 0) {
		*list  = node;
		return;
	}
    cycle_list(&buf, arr, info, l);
    push_in_list(buf, node, arr);
}

