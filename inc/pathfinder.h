#ifndef PATHFINDER
#define PATHFINDER

#include "../libmx/inc/libmx.h"

#define DELIM " -> " 
#define IS " = "
#define PLUS " + "





typedef struct s_my_result 
{
char *Path;
char *Route;
char *Distance;
struct s_my_result *next;
} t_result_list;



int mx_atoi(const char *str);
bool mx_isdigit(int c);


char *mx_strjoin( char *s1,  char *s2);
char *mx_strjoin_one( char *s1,  char *s2);
char *mx_strjoin_two( char *s1,  char *s2);
char *mx_strjoin_both( char *s1,  char *s2);
void mx_del_intarr(int ***arr, int n);
void mx_freeOutput(t_result_list **outputList);
char *mx_strfind (const char *haystack, const char *needle);





void mx_printstr_err(const char *s);
bool mx_digit_str(char *str);
void mx_printchar_err(char c);
void mx_printint_err(int n);
bool mx_isalpha(int c);

void mx_find_path(int **matrix, char **myarr, t_list **list, int n);
int *mx_create_dextra_arr(int iter, int i, int n, int y);
void mx_dextra_mat(int *numbers, t_result_list **l, t_list **list, int ***allmat);
void mx_free_two(int *second_num, int ***second);
bool mx_update_cycle(int ***allmat, int n, int *y);
int mx_findmin(int **small_matrix, int n);
void mx_write_result(int *numbers, t_result_list **l, t_list **list, int ***allmat);
char *mx_find_char(t_list **list, int index);
char **mx_create_tmp_arr(char *path, char *distance, char *Route);
void mx_write_in_list(t_result_list **l, char **tmp_info, char *path, t_list **list);
void mx_push_onpalce(t_result_list **list, char **info, t_list **l);
void mx_creat_arr_list(char *Route_1, char *Route_2, t_list **l, int **arr);
int mx_find_index(t_list **list, char *str);
t_result_list *mx_create_result(char *path, char *Route, char *distance);
t_list *mx_buildlist(char **myarr);
bool mx_allvalid(int i, char *myarr, char *name);
bool mx_validation_four(char *file);
bool mx_valid_island(char **myarr);
void mx_print_error_line(int i, char **myarr);


#endif
