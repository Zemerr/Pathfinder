#include "../inc/libmx.h"

void mx_printint(int n) {
	if ( n == -2147483648)
        write(1, "-2147483648", 11);
	else {
		if (n < 0) {
			n = n * -1;
			mx_printchar('-');
		}
		if (n/10 >= 1) {
			mx_printint(n/10);
		}
		mx_printchar(n%10+48);	
	}
}
