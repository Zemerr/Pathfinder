#include "../inc/libmx.h"

static char *convert(unsigned long copy, char *hex, int num, int i) {
	while (copy > 0) {
        num  = copy % 16;
        if (num >= 10) {
            hex[i--] = (copy % 16) + 87;
        }
        else
            hex[i--] = (copy % 16) + 48;
        copy = copy/16;
    }
    return hex;
}
	

char *mx_nbr_to_hex(unsigned long nbr) {
	int i = 0;
	int num = 0;
	unsigned long copy = nbr;
	char *hex = NULL;

	if (nbr == 0) {
		hex = mx_strnew(1);
		hex[0] = '0';
		return hex;
	}
	
	while (nbr/16 >= 1) {
		nbr = nbr/16;
		i++;
	}
	hex = mx_strnew(i+1);
	hex = convert(copy, hex, num, i);	
	return hex;
}
