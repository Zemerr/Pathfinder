#include "../inc/pathfinder.h"



static bool validation_one(int i) {
	if (i != 2) {
		mx_printstr_err("usage: ./pathfinder [filename]\n");
		return false;
	}
	return true;
}

static bool validation_two(char *myarr, char *name) {
	if (myarr == NULL) {
		mx_printstr_err("error: file ");
		mx_printstr_err(name);
		mx_printstr_err(" does not exist\n");
		return false;
	}
	return true;
}

static bool validation_three(char *myarr, char *name) {
	if (mx_strlen(myarr) <= 0) {
		mx_printstr_err("error: file ");
		mx_printstr_err(name);
		mx_printstr_err(" is empty\n");
		return false;
	}
	return true;
}


static bool enter_valid(char *file) {
	int num = 0;
	int i = 0;
	
	for (; file[i] != '\0'; i++) {		
		if (file[i] == '\n') 
			num++;		
		if (file[0] == '\n') {			
			mx_print_error_line(0, NULL);
			return false;
		}
		if (file[i] == '\n' && file[i+1] == '\n')  {
			mx_print_error_line(num, NULL);
			return false;
		}
	}
	if (file[i-1] != '\n') {
		mx_print_error_line(num, NULL);
		return false;
	}
	return true;
}

bool mx_allvalid(int i, char *myarr, char *name) {
	if (!validation_one(i) || !validation_two(myarr, name) 
		|| !validation_three(myarr, name) ||
		 !mx_validation_four(myarr) || !enter_valid(myarr)) 
		return false;
	return true;
}
