#include "../inc/libmx.h"


char *mx_strfind (const char *haystack, const char *needle) {

	
	//int n = mx_strlen(needle);
	
	for (; *haystack; haystack++, needle++)  {
		if ( *haystack != *needle)			
				return (char*)haystack;


	}
	return NULL;
}

// int main() {
// 	char *test = "A-B -> C";
// 	char *test1 = "A-D -> C";
// 	printf("%s\n ", mx_strfind(test1, test));
// 	system("leaks -q a.out");
// }
