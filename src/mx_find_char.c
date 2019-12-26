#include "../inc/pathfinder.h"

char *mx_find_char(t_list **list, int index) {
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

