#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
	int i = 0;
	t_list *p = list;
	
	while (p != NULL) {
		i++;
		p = p->next;
		
	}
	return i;
}
