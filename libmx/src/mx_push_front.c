#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data, int count) {
	t_list *front = mx_create_node(data, count);
	front->next = *list;
	*list  = front;
}
