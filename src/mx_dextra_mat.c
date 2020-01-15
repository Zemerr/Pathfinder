#include "../inc/pathfinder.h"


static bool valid_for_dextra(int ***allmat, int y, int iter) {
	if (allmat[1][2][y] != 1) {
        if ((allmat[1][0][y] != -1 && allmat[0][iter][y] != -1) 
        || (allmat[1][0][y] != -1 || allmat[0][iter][y] != -1)) 
        {
        	return true;
        }
    }
    return false;

}

static void for_dextra_mat_one(int ***allmat, int y, int iter) {
  
			if (allmat[1][0][y] > allmat[1][0][iter] + allmat[0][iter][y] 
				|| allmat[1][0][y] == -1)

	     	{
		        if (allmat[0][iter][y] != -1) {		        
		            allmat[1][0][y] = allmat[1][0][iter] + allmat[0][iter][y];
		            allmat[1][1][y] = iter;
	           
	       		 }
	   		 }	
}

static bool valid_for_second(int ***allmat, int y, int iter) {
	if (allmat[1][0][y] == allmat[1][0][iter] + allmat[0][iter][y] 
        && allmat[1][0][y] != -1 
        && allmat[0][iter][y] != -1 && allmat[1][1][y] != iter && allmat[1][2][y] != 1) 
	{
		return true;
	}
	return false;

}

static int ***create_second_dextra(int ***allmat, int iter, int y, int n) {
	int ***second = (int ***)malloc(sizeof(int ***) *n);
	second[1] = (int **)malloc(sizeof(int **) *n);

	for (int g = 0; g < 3; g++) {
		second[1][g] = (int *)malloc(sizeof(int) *n);
	}
	for (int g = 0; g < 3; g++){
		for (int j = 0; j < n; j++) {
			second[1][g][j] = allmat[1][g][j];			
		}
	}
	second[1][0][y] = second[1][0][iter] + allmat[0][iter][y];
    second[1][1][y] = iter;
    second[0] = allmat[0];
    second[2] = allmat[2];

    return second;
}

void mx_dextra_mat(int *numbers, t_result_list **l, t_list **list, int ***allmat) {
	int ***second = NULL;
	int *second_num = NULL;

    for (int y = numbers[3]; y < numbers[2]; y++) {	            	
        if (valid_for_dextra(allmat, y, numbers[1])) {
             	for_dextra_mat_one(allmat, y, numbers[1]);		                 	
                if (valid_for_second(allmat, y, numbers[1])) {     
                	second = create_second_dextra(allmat, numbers[1], y, numbers[2]);						
					second_num = mx_create_dextra_arr(numbers[1], numbers[0], numbers[2], y);
                	mx_dextra_mat(second_num, l, list, second);                        	
                	mx_free_two(second_num, second);                	              
                }
            }        
        allmat[1][2][numbers[1]] = 1;
        if (mx_update_cycle(allmat, numbers[2], &y)) {                
                numbers[1] = mx_findmin(allmat[1], numbers[2]);		                
            }		      
    }         	
    mx_write_result(numbers, l, list, allmat);
}

