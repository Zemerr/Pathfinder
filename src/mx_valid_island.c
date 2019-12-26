#include "../inc/pathfinder.h"

static void delete_two(char **str1, char **str2) {
	mx_del_strarr(&str1);
	mx_del_strarr(&str2);

}

static bool reflect_alpha(char *str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (!mx_isalpha(str[i]))
			return false;		
	}
	return true;
}

static bool reflect_digit(char *str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (!mx_isdigit(str[i]))
			return false;		
	}
	return true;
}

static bool reflect_buff(char **bufarr2, char **bufarr, char **myarr, int i) {
	if (bufarr2[1] == NULL || reflect_alpha(bufarr2[0]) == 0 || !reflect_digit(bufarr2[1])) {
			delete_two(bufarr, bufarr2);				
			mx_print_error_line(i, myarr);
			return false;
		}
		if (mx_strcmp(bufarr[0], bufarr2[0]) == 0) {
			delete_two(bufarr, bufarr2);				
			mx_print_error_line(i, myarr);
			return false;
		}
	return true;

}


bool mx_valid_island(char **myarr) {
	char **bufarr = NULL;
	char **bufarr2 = NULL;

	for (int i = 1; myarr[i] != NULL; i++) {
		bufarr = mx_strsplit(myarr[i], '-');
			if (bufarr[1] == NULL ||reflect_alpha(bufarr[0]) == 0) {
				mx_del_strarr(&bufarr);
				mx_print_error_line(i, myarr);				
				return false;				
			}
			bufarr2 = mx_strsplit(bufarr[1], ',');
			if (!reflect_buff(bufarr2, bufarr, myarr, i))
				return false;			
			delete_two(bufarr, bufarr2);
		}
	return true;
}
