
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// very incomplete small test program...

int main() {
    LIST *lst1;
    int i;
    
    lst1 = lst_create();
    
    for(i=0; i<5; i++) {
        lst_push_front(lst1, i);
    }
    for(i=0; i<5; i++) {
        lst_push_back(lst1, i);
    }
    
    printf("lst_length(lst1) : %i\n", lst_length(lst1));
    printf("lst1 contents: ");
    lst_print(lst1);
    
    lst_pop_front(lst1);
    lst_pop_front(lst1);
    printf("lst1 contents after two pops: ");
    lst_print(lst1);
    
    printf("\n");
    printf("TESTING EQUAL:\n");
    LIST *listONE;

    listONE = lst_create();
    LIST *listTWO;
    listTWO = lst_create();
    
    printf("check\n");
    for(i=0; i<5; i++) {
        lst_push_back(listONE, i);
    }
    printf("check2\n");
    
    for(i=0; i<5; i++) {
        lst_push_back(listTWO, i);
    }
     
    lst_print(listONE);
    lst_print(listTWO);
    printf("Are listONE and listTWO equal? %d\n\n", lst_are_equal(listONE, listTWO));
    
    
    printf("\n");
    printf("TESTING PRINT REVERSE:\n");
    lst_print_rev(listONE);
    
    
    printf("\n");
    printf("TESTING LENGTH:\n");
    printf("%d\n", lst_length(listONE));
    printf("%d\n", lst_length(listTWO));
    
    printf("\n");
    printf("TESTING LIST COUNT:\n");
    lst_push_back(listONE, 1);
    printf("%d\n", lst_count(listONE, 1));
    printf("%d\n", lst_length(listONE));
    printf("%d\n", lst_length(listTWO));
    
    printf("CHECK\n");
    
    printf("\n");
    printf("TESTING POP BACK:\n");
    lst_print(listONE);
    lst_pop_back(listONE);
    lst_print(listONE);
    lst_pop_back(listONE);
    lst_print(listONE);
    
    printf("\n");
    printf("TESTING _REVERSE:\n");
    lst_push_back(listONE, 4);
    lst_print(listONE);
    lst_reverse(listONE);
    lst_print(listONE);
    
    printf("\n");
    printf("TESTING REMOVE ALL FAST\n");
    lst_push_back(listONE, 4);
    lst_push_back(listONE, 4);
    lst_push_back(listONE, 4);
    lst_push_back(listONE, 4);
    lst_push_back(listONE, 4);
    lst_print(listONE);
    printf("removing all 4's...\n");
    lst_remove_all_fast(listONE, 4);
    lst_print(listONE);
    printf("freeing list..\n");
    lst_free(listONE);
    listONE = lst_create();
    lst_remove_all_fast(listONE, 4);
    printf("printing empty..\n");
    printf("Length: %d\n", lst_length(listONE));
    lst_print(listONE);
    printf("pushing back....\n");
    lst_push_back(listONE, 4);
    printf("HEY1Length: %d\n", lst_length(listONE));
    lst_print(listONE);
    printf("removing all 4's...\n");
    lst_remove_all_fast(listONE, 4);
    printf("HEY2 Length: %d\n", lst_length(listONE));
    lst_print(listONE);
    
    printf("\n");
    printf("TESTING INSERT SORTED\n");
    lst_push_back(listONE, 1);
    lst_push_back(listONE, 2);
    lst_push_back(listONE, 3);
    lst_print(listONE);
    lst_insert_sorted(listONE, 2);
    lst_print(listONE);
    
    
    printf("\n");
    printf("TESTING MERGE SORTED\n");
    LIST *a = lst_create();
    LIST *b = lst_create();
    lst_push_back(a, 1);
    lst_push_back(a, 2);
    lst_push_back(a, 5);
    
    lst_push_back(b, 3);
    lst_push_back(b, 4);
    lst_push_back(b, 6);
    lst_merge_sorted(a, b);
    lst_print(a);
    
    printf("\n");
    printf("TESTING LIST CLONE\n");
    
    LIST* clonedList = lst_clone(a);
    lst_print(a);
    lst_print(clonedList);
    
    
    printf("\n");
    printf("TESTING FROM ARRAY\n");
    int array[5] = {1,3,5,7,9};
    printf("array: ");
    for (int i = 0; i < 5; i++) {
        printf(FORMAT, array[i]);
    }
    printf("\n");
    LIST* fromArray = lst_from_array(array, 5);
    lst_print(fromArray);
    

    
    printf("\n");
    printf("TESTING TO ARRAY\n");
    int* newArray = lst_to_array(fromArray);
    for (int i = 0; i < 5; i++) {
        printf(FORMAT, newArray[i]);
    }
    printf("\n");
    
    printf("\n");
    printf("TESTING PREFIX with k = 5 \n");
    LIST* prefix = lst_prefix(fromArray, 5);
    printf("prefix: ");
    lst_print(prefix);
    printf("original: ");
    lst_print(fromArray);
    printf("prefix size: %d\n", lst_length(prefix));
    printf("orig size: %d\n", lst_length(fromArray));
    printf("\n");
    
    
    printf("\n");
    printf("TESTING FILTER LES EQ\n");
    
    LIST *filter = lst_create();
    lst_push_back(filter, 5);
    lst_push_back(filter, 8);
    lst_push_back(filter, 8);
    lst_push_back(filter, 8);
    lst_push_back(filter, 4);
    lst_push_back(filter, 8);
    lst_push_back(filter, 8);
    lst_push_back(filter, 8);
    lst_push_back(filter, 8);
    lst_push_back(filter, 1);
    
    lst_print(filter);
    LIST * filtered = lst_filter_leq(filter, 4);
    lst_print(filter);
    lst_print(filtered);
    
    printf(" size: %d\n", lst_length(filter));
    printf(" size: %d\n", lst_length(filtered));
    
    
    printf("\n");
    LIST * A = lst_create();
    LIST * B = lst_create();
    lst_push_back(A, 4);
    lst_push_back(A, 5);
    lst_push_back(A, 6);
    
    lst_push_back(B, 1);
    lst_push_back(B, 2);
    lst_push_back(B, 3);
    
    lst_concat(A, B);
    lst_print(A);
    lst_print(B);
    printf(" size: %d\n", lst_length(A));
    printf(" size: %d\n", lst_length(B));
    
    
    
    printf("sanity1 %d\n", lst_sanity1(b));
    printf("sanity2 %d\n", lst_sanity2(b));
    printf("sanity3 %d\n", lst_sanity3(b));
    
 
    printf("number of 3's = %i\n", lst_count(lst1, 3));
    printf("number of 0's = %i\n", lst_count(lst1, 0));
    
    
    
    /** test code for lst_print_rev **/
    
    
    
    
    
    /** test code for lst_push_back **/
    
    printf("CHECK!\n");
    lst_free(lst1);
    printf("CHECK2!\n");
    
    
}

