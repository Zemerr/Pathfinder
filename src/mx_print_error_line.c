#include "../inc/pathfinder.h"

void mx_print_error_line(int i, char **myarr) {
	if (myarr != NULL)
		mx_del_strarr(&myarr);
	mx_printstr_err("error: line ");
	mx_printint_err(i+1);
	mx_printstr_err(" is not valid\n");

}
