#include "../inc/libmx.h"

static int numer( int i, int number) {
	if ( number == 0 ) {
		i = 1;
		return i;
	}	
	while (number >= 1) {
        i++;
        number = number/10;
    }
	return i;	
}

char *mx_itoa(int number) {
	int copy = number;
	int i = 0;
	char *num;
	int flag = 0;

	if (number == -2147483648){
		num = "-2147483648";
		return num;
	}
	if (number < 0) { 
		number = number * -1;
		copy = copy *-1;
		flag = 1;
		i++;
	}
	i = numer(i , number);
	num = mx_strnew(i);
	for (int y = 1; y <= i; y++) {
		num[i-y] = (copy % 10) + 48;
		copy = copy/10;
	}
	if (flag == 1) {
		num[0] = '-';
	}
	return num;	
}
