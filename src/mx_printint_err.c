#include "../inc/pathfinder.h"

void mx_printint_err(int n) {
	if ( n == -2147483648)
        write(1, "-2147483648", 11);
	else {
		if (n < 0) {
			n = n * -1;
			mx_printchar_err('-');
		}
		if (n/10 >= 1) {
			mx_printint_err(n/10);
		}
		mx_printchar_err(n%10+48);	
	}
}
