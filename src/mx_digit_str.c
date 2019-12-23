#include "../inc/pathfinder.h"

bool mx_digit_str(char *str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (!mx_isdigit(str[i]))
			return false;
	}
	return true;
}
