#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define FREE(x) lst_free(x)

void print_arr(int *arr, int n) {
		int i = 0;
		printf("[");
		for(; i < n; i++) {
			printf(" %d ", arr[i]);
		}
		printf("]\n");
}

int main() {
    printf("REMINDER: This test suite is NOT exhaustive\n");
    printf("   Passing all of these tests does NOT mean you will get 100%% on the project.\n");
    srand(time(NULL));
    
int i;	
	/********* 0 lst_is_empty  **********/
	LIST *empty = lst_create();
	LIST *one = lst_create();
	LIST *large = lst_create();
	lst_push_back(one, 5);
	int rand_size = rand() % 20;
	for(i = 0; i < rand_size; i++) {
		lst_push_back(large, i);
	}
	printf("\n\nTest: 0A\nDescription: Testing lst_is_empty with List of length 0\nExpected output: 1\n");
	printf("Your output: %d\n", lst_is_empty(empty));
	printf("\n\nTest: 0B\nDescription: Testing lst_is_empty with List of length 1\nExpected output: 0\n");
	printf("Your output: %d\n", lst_is_empty(one));
	printf("\n\nTest: 0CnDescription: Testing lst_is_empty with List of length %d\nExpected output: %d\n", rand_size, ((rand_size == 0) ? 1 : 0));
	printf("Your output: %d\n", lst_is_empty(large));

	FREE(large);
	FREE(one);
	FREE(empty);

	/********* 1 lst_print_rev **********/
    
	LIST *rev1 = lst_create();
	LIST *rev2 = lst_create();
	for(i = 0; i < 5; i++) {
		lst_push_back(rev2, i);
	}
	printf("\n\nTest: 1A\nDescription: Testing lst_print_rev with List of length 5\nExpected output: \n[4, 3, 2, 1, 0]\n");
	printf("Your output\n");
	lst_print_rev(rev2);
	printf("\n\nTest: 1B\nDescription: Testing lst_print_rev with List of length 0\nExpected output: \n[ ]\n");
	printf("Your output\n");
	lst_print_rev(rev1);
    
    FREE(rev1);
    FREE(rev2);

    /********** 3 lst_pop_back ***********/
    
    large = lst_create();
    one = lst_create();
    empty = lst_create();
    for(i = 0; i < 8; i++) {
        lst_push_back(large, i);
    }
    lst_push_back(one, 6);
    
    printf("\n\nTest: 3A\nDescription: Testing lst_pop_back with List of length 0\nExpected output: <some arbitrary number (NO SEG FAULT!)>\n");
    printf("Your output: %d\n", lst_pop_back(empty));
    printf("\n\nTest: 3B\nDescription: Testing lst_pop_back with List of length 1\nExpected output: 6\n");
    printf("Your output: %d\n", lst_pop_back(one));
    printf("\n\nTest: 3C\nDescription: Testing lst_pop_back with List of length 8\nExpected output: 7\n");
    printf("Your output: %d\n", lst_pop_back(large));
    
    FREE(large);
    FREE(one);
    FREE(empty);
    
    /********** 5 lst_is_sorted ***********/
    empty = lst_create();
    LIST *sorted = lst_create();
    LIST *unsorted = lst_create();
    for(i = 0; i < 10; i++) {
        lst_push_back(sorted, i);
        lst_push_back(unsorted, i);
    }
    lst_push_back(unsorted, 5);
    printf("\n\nTest: 5A\nDescription: Testing lst_is_sorted with List of length 0\nExpected output: 1\n");
    printf("Your output: %d\n", lst_is_sorted(empty));
    printf("\n\nTest: 5B\nDescription: Testing lst_is_sorted with List of length 11\nExpected output: 0\n");
    printf("Your output: %d\n", lst_is_sorted(unsorted));
    printf("\n\nTest: 5C\nDescription: Testing lst_is_sorted with List of length 10\nExpected output: 1\n");
    printf("Your output: %d\n", lst_is_sorted(sorted));
    
    FREE(empty);
    FREE(sorted);
    FREE(unsorted);
    
    /********** 7 lst_length ***********/
    
    empty = lst_create();
    rand_size = rand() % 100;
    LIST *small = lst_create();
    large = lst_create();
    for(i = 0; i < rand_size; i++) {
        lst_push_back(large, rand() % 1000);
    }
    lst_push_back(small, 3);
    
    printf("\n\nTest: 7A\nDescription: Testing lst_length with List of length 0\nExpected output: 0\n");
    printf("Your output: %d\n", lst_length(empty));
    printf("\n\nTest: 7B\nDescription: Testing lst_length with List of length 1\nExpected output: 1\n");
    printf("Your output: %d\n", lst_length(small));
    printf("\n\nTest: 7C\nDescription: Testing lst_length with List of length %d\nExpected output: %d\n", rand_size, rand_size);
    printf("Your output: %d\n", lst_length(large));
    
    FREE(empty);
    FREE(small);
    FREE(large);
    
    /********** 9 lst_clone ***********/
    
    empty = lst_create();
    small = lst_create();
    large = lst_create();
    lst_push_back(small, 3);
    rand_size = rand() % 10;
    for(i = 0; i < rand_size; i++) {
        lst_push_back(large, rand() % 500);
    }
    
    printf("\n\nTest 9A\nDescription: Testing lst_clone with List of length 0\nExpected output:\n");
    lst_print(empty);
    printf("Your output: \n");
    LIST *empty_clone = lst_clone(empty);
    lst_print(empty_clone);
    printf("\n\nTest 9B\nDescription: Testing lst_clone with List of length 1\nExpected output:\n");
    lst_print(small);
    printf("Your output: \n");
    LIST *small_clone = lst_clone(small);
    lst_print(small_clone);
    printf("\n\nTest 9C\nDescription: Testing lst_clone with List of random size\nExpected output:\n");
    lst_print(large);
    printf("Your output: \n");
    LIST *large_clone = lst_clone(large);
    lst_print(large_clone);


		FREE(empty);
		FREE(small);
		FREE(large);
		FREE(empty_clone);
		FREE(large_clone);
		FREE(small_clone);

    /********** 11 lst_to_array ***********/
		

		large = lst_create();
		rand_size = rand() % 50;
		for(i = 0; i < rand_size; i++) {
			lst_push_back(large, rand() % 100);
		}
		printf("\n\nTest 11A\nDescription: Testing lst_to_array with List of length %d\nExpected output:\n", rand_size);
    lst_print(large);
    printf("Your output: \n");
  	int *arr = lst_to_array(large);
		print_arr(arr, lst_length(large));

		FREE(large);
		free(arr);

    /********** 13 lst_filter_leq ***********/
		

		large = lst_create();
		empty = lst_create();
		small = lst_create();
		lst_push_back(small, 7);
		for(i = 0; i < 10; i++) {
			lst_push_back(large, i);
		}
		printf("\n\nTest 13A\nDescription: Testing lst_filter_leq with List of length 0 and cutoff of 5\nExpected output for original List after call to lst_filter_leq:\n");
		LIST *leq_empty = lst_filter_leq(empty, 5);
		printf("[ ]\n");
		printf("Your output of original List:\n");
		lst_print(empty);
		printf("Expected output for new list of leq elements:\n");
		printf("[ ]\n");
		printf("Your output of new list of leq elements:\n");
		lst_print(leq_empty);
    
    
    
		printf("\n\nTest 13B\nDescription: Testing lst_filter_leq with List of length 1 and cutoff of 7\nExpected output for original List after call to lst_filter_leq:\n");
		LIST *leq_small = lst_filter_leq(small, 5);
		printf("[ 7 ]\n");
		printf("Your output of original List:\n");
		lst_print(small);
		printf("Expected output for new list of leq elements:\n");
		printf("[ ]\n");
		printf("Your output of new list of leq elements:\n");
		lst_print(leq_small);
    
    
    
    
    
		printf("\n\nTest 13C\nDescription: Testing lst_filter_leq with List of length 0 and cutoff of 5\nExpected output for original List after call to lst_filter_leq:\n");
		LIST *leq_large = lst_filter_leq(large, 5);
		printf("[ 6  7  8  9 ]\n");
		printf("Your output of original List:\n");
		lst_print(large);
		printf("Expected output for new list of leq elements:\n");
		printf("[ 0  1  2  3  4  5 ]\n");
		printf("Your output of new list of leq elements:\n");
		lst_print(leq_large);

		FREE(leq_empty);
		FREE(leq_small);	
		FREE(leq_large);
		FREE(empty);
		FREE(small);
		FREE(large);


return 0;
}

