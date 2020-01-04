#include "../inc/pathfinder.h"


static char *result(char *s1,  char *s2) {
    char *res = NULL;
    res = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    res = mx_strcat(res, s1);
    res = mx_strcat(res, s2);
    mx_strdel(&s2);
    return res;
}

char *mx_strjoin_two( char *s1,  char *s2) {
    char *res = NULL;

    if (!s1 && !s2)
        return NULL;
    else if (!s1) {
        res = mx_strnew(mx_strlen(s2));
        res = mx_strcat(res, s2);
        mx_strdel(&s2);
       
    }
    else if (!s2) {
        res = mx_strnew(mx_strlen(s1));
        res = mx_strcat(res, s1);
        
    }
    else      
        res = result(s1, s2);    
   return res;
}
