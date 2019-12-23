#include "../inc/pathfinder.h"


char *mx_strfind (const char *haystack, const char *needle) {	
	
	for (; *haystack; haystack++, needle++)  {
		if ( *haystack != *needle)			
				return (char*)haystack;


	}
	return NULL;
}
