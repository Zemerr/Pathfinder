#include "../inc/pathfinder.h"



static bool for_cycle(char **myarr, int *count_one, int *count_two, int i) {
	for (int j = 0; myarr[i][j] != '\0'; j++) {
		if (myarr[i][j] == '-') {
			(*count_one)++;
			if ((*count_two) > 0) {
				mx_print_error_line(i, myarr);
				return false;
			}
		}
		if (myarr[i][j] == ',') 
			(*count_two)++;
		}
	return true;

}

static bool valid_delim(char **myarr) {
	int count_one = 0;
	int count_two = 0;

	for(int i = 1; myarr[i] != NULL; i++) {
		count_one = 0;
		count_two = 0;
		if (!for_cycle(myarr, &count_one, &count_two, i))
			return false;	
		if (count_one != 1 || count_two != 1) {
			mx_print_error_line(i, myarr);
			return false;
		}		
	}
	return true;
}

 

bool mx_validation_four(char *file) {
	
	char **myarr = mx_strsplit(file, '\n');	
	
	if (!mx_digit_str(myarr[0])) {
		mx_printstr_err("error: line 1 is not valid\n");
		mx_del_strarr(&myarr);
		return false;
	}
	if (!valid_delim(myarr))
		return false;	
	if (!mx_valid_island(myarr))
		return false;	
	mx_del_strarr(&myarr);
	return true;
}
