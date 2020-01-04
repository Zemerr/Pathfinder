#include "../inc/pathfinder.h"

t_result_list *mx_create_result(char *path, char *Route, char *distance) {
    t_result_list *new = (t_result_list *)malloc(sizeof(t_result_list));
    new->Path = path;
    new->Route = Route;
    new->Distance = distance;
    new->next = NULL;
    return new;
}
