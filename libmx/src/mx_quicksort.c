#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
	int l = left;
	int r = right;
	int p = left + (right - left)/2;
	int count = 0;
	
	if (arr == NULL)
		return -1;
	while (l < r) {
		
		for (int i = left; i <= p; i++) {
			
			if (mx_strlen(arr[i]) > mx_strlen(arr[p])) {
				l = i;
				break;
			}
		}
		for (int j = right; j >= p; j--) {

			if (mx_strlen(arr[j]) < mx_strlen(arr[p])) {
        	    r = j;
            	break;
			}
			 
		}

		if (mx_strlen(arr[l]) > mx_strlen(arr[r])) {
			mx_swap_str(&arr[l], &arr[r]);
			count++;
		}
	
	l++;
    r--;
	}
	
	if (l != right)
		count = count + mx_quicksort(arr, l, right);
	if (r != left)
		count = count + mx_quicksort(arr, left, r);	

	return count;
}
