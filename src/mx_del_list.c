#include "../inc/pathfinder.h"

void mx_freeOutput(result_list **outputList) {
    while(*outputList) {
        result_list *tmp = (*outputList)->next;
        free((*outputList)->Distance);
        free((*outputList)->Path);
        free((*outputList)->Route);

        free((*outputList));
        *outputList = tmp;
    }
}
