#include "../inc/pathfinder.h"

void mx_freeOutput(t_result_list **outputList) {
    while(*outputList) {
        t_result_list *tmp = (*outputList)->next;
        free((*outputList)->Distance);
        free((*outputList)->Path);
        free((*outputList)->Route);

        free((*outputList));
        *outputList = tmp;
    }
}
