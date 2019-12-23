#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
	char *haystack = (char *) big;
	char *needle = (char *) little;



	if ( big_len > little_len && little_len > 0 && big_len > 0) {
	  

		for (; *haystack; ++haystack) {
    	    if ( *haystack == *needle) {
        	    if (mx_strncmp(haystack, needle, little_len) == 0)
            	    return (char*)haystack;
       		}

   		}
	}	
    return NULL;
}
