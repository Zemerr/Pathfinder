#include "../inc/pathfinder.h"

result_list *mx_create_result(char *path, char *Route, char *distance) {
    result_list *new = (result_list *)malloc(sizeof(result_list));
    new->Path = path;
    new->Route = Route;
    new->Distance = distance;
    new->next = NULL;
    return new;
}
