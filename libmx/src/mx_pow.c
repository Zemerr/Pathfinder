#include "../inc/libmx.h"


double mx_pow(double n, unsigned int pow) {
	double num = 1;

	for (unsigned int i = 0; i < pow; i++)
		num = num * n;

	return num;
}
