#include "../inc/libmx.h"

t_list *mx_create_node(char *data, int count) {
	t_list *new = (t_list *)malloc(sizeof(t_list));
	new->data = data;
	new->count = count;
	new->next = NULL;
	return new;
}
