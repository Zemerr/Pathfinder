#include "../inc/pathfinder.h"

char **mx_create_tmp_arr(char *path, char *distance, char *Route) {
	char **tmp_info = (char **)malloc(sizeof(char *) *4);
	tmp_info[0] = mx_strdup(path);
	tmp_info[1] = mx_strdup(distance);
	tmp_info[2] = mx_strdup(Route);
	tmp_info[3] = NULL;
	return tmp_info;

}
