#include "../inc/pathfinder.h"

static int find_my_index_two(char *Route_1, char *Route_2, t_list **l) {
	char *two = mx_strfind(Route_1, Route_2);
	char **two_p = mx_strsplit(two, ' ');
	char *two_point = NULL;
	int secondi = 0;

	// if (two_p[1] == NULL) {
	// 	mx_del_strarr(&two_p);
	// 	return -1;
	// }

	two_point = two_p[0];
	secondi = mx_find_index(l, two_point);
	mx_del_strarr(&two_p);
	return secondi;
}

static int find_my_index_one(char *Route_1, char *Route_2, t_list **l) {
	char *two = mx_strfind(Route_1, Route_2);
	char **two_p = mx_strsplit(two, ' ');
	char *two_point = two_p[0];
	int secondi = mx_find_index(l, two_point);
	mx_del_strarr(&two_p);
	return secondi;
}

void mx_creat_arr_list(char *Route_1, char *Route_2, t_list **l, int **arr) {
	int secondi = find_my_index_two(Route_1, Route_2, l);
	int firsti = find_my_index_one(Route_2, Route_1, l);

	(*arr)[0] = 0;
	(*arr)[1] = firsti;
	(*arr)[2] = secondi;

}

