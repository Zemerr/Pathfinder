#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
	t_list *buf = NULL;
	t_list *buft = NULL;
	void  *tmp = NULL;

	for (buft = lst; buft != NULL; buft = buft->next) {
		for (buf = buft->next; buf != NULL; buf = buf->next) { 
			if (cmp(buf->data, buft->data) == 1) {
				tmp = buft->data;
				buft->data = buf->data;
				buf->data = tmp;
				
				
			}
	
		}
	}
	return lst;
}
