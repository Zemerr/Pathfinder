#ifndef PATHFINDER
#define PATHFINDER

#include "../libmx/inc/libmx.h"

#define DELIM " -> " 
#define IS " = "
#define PLUS " + "





typedef struct my_result 
{
char *Path;
char *Route;
char *Distance;
struct my_result *next;
} result_list;



int mx_atoi(const char *str);
bool mx_isdigit(int c);


char *mx_strjoin( char *s1,  char *s2);
char *mx_strjoin_one( char *s1,  char *s2);
char *mx_strjoin_two( char *s1,  char *s2);
char *mx_strjoin_both( char *s1,  char *s2);
void mx_del_intarr(int ***arr, int n);
void mx_freeOutput(result_list **outputList);
char *mx_strfind (const char *haystack, const char *needle);
void secod_mat_use(int ***allmat,  int *numbers, result_list **l, t_list **list);
int findmin(int **small_matrix, int n);
void mx_printstr_err(const char *s);
bool mx_digit_str(char *str);
void mx_printchar_err(char c);
void mx_printint_err(int n);
bool mx_isalpha(int c);

#endif
