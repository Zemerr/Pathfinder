#include "../inc/libmx.h"


void mx_printstr_err(const char *s) {
	for(int i = 0; i < mx_strlen(s); i++)
		write(2, &s[i], 1);
	
}
