#include "../inc/pathfinder.h"

static char *reslut_both(char *s1,  char *s2){
    char *res = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    res = mx_strcat(res, s1);
    res = mx_strcat(res, s2);
    mx_strdel(&s2);
    mx_strdel(&s1);
    return res;

}

char *mx_strjoin_both(char *s1,  char *s2) {
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
        mx_strdel(&s1);
        
    }
    else 
        res = reslut_both(s1, s2);   
   return res;
}
