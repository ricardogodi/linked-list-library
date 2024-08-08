/**
 * 
 * Tests included:
 * 0 Example rests for provided function lst_push_backk.
 * 1 lst_print_rev
 * 2 lst_count
 * 3 lst_pop_back
 * 4 lst_reverse
 * 5 lst_is_sorted
 * 6 lst_insert_sorted
 * 7 lst_length
 * 8 lst_merge_sorted
 * 9 lst_clone
 * 10 lst_from_array
 * 11 lst_to_array
 * 12 lst_prefix
 * 13 lst_filter_leq
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

#define FREE(x) lst_free(x)


void helper_arr_print_no_newline(int *arr, int n) {
    printf("[");
    for (int i=0; i<n; i++) {
      printf(" %d ", arr[i]);
    } printf("]\n");
}

int main() {
  // Test values.
  LIST *empty = lst_create();
  LIST *anotherEmptyList = lst_create();
  LIST *one = lst_create();  // List of one element [ 5 ].
  LIST *medium = lst_create();  // List of ten elements [ 1 2 ... 9 10 ].
  LIST *evenList;  // Lst of five even elements [ 2 4 6 8 10 ].
  LIST *oddList;  // List of five odd elements [ 1 3 5 7 9 ].
  LIST *dupsOfevenList; // List of some even duplicate elements [ 4 8 12 16 20 ].
  LIST *resultList;

  srand(time(NULL));
  lst_push_back(one, 5);
  for(int i = 1; i <= 10; ++i) { lst_push_back(medium, i); }

  /**
  * Unit test for void lst_push_back(LIST *l, ElemType val);
  */
  printf("\n\nTest: 0A\nDescription: Testing lst_push_back with List of length 0 with elements [] and val=42\nExpected output: [ 42 ]\n");
  printf("Your output:");
  lst_push_back(empty, 42);
  lst_print(empty);
  FREE(empty);
  empty = lst_create();

  printf("\n\nTest: 0B\nDescription: Testing lst_push_back with List of length 1 with elements [ 5 ] and val=42\nExpected output: [ 5 42 ]\n");
  printf("Your output:");
  lst_push_back(one, 42);
  lst_print(one);
  FREE(one);
  one = lst_create();
  lst_push_back(one, 5); // Reset one for later tests.

  evenList = lst_create();
  for (int i=1; i<=5; ++i) { lst_push_back(evenList, i*2); }
  printf("\n\nTest: 0C\nDescription: Testing lst_push_back with List of length 5 with elements [2 4 6 8 10] and val=42\nExpected output: [ 2 4 6 8 10 42 ]\n");
  printf("Your output:");
  lst_push_back(evenList, 42);
  lst_print(evenList);
  FREE(evenList);


  /**
   * 2. Unit tests on function: int lst_count(LIST *l, ElemType x);
   */ 
  printf("\n\nTest: 2A\nDescription: Testing lst_count with List of length 0 and x=5\nExpected output: 0\n");
  printf("Your output: %d\n",  lst_count(empty, 5));

  printf("\n\nTest: 2B\nDescription: Testing lst_count with List of length 10 and x=-5\nExpected output: 0\n");
  printf("Your output: %d\n", lst_count(medium, -5));

  printf("\n\nTest: 2C\nDescription: Testing lst_count with List of length 10 and x=5\nExpected output: 1\n");
  printf("Your output: %d\n", lst_count(medium, 5));

  lst_push_front(medium, 10);
  printf("\n\nTest: 2D\nDescription: Testing lst_count with List of length 10 and x=10\nExpected output: 2\n");
  printf("Your output: %d\n", lst_count(medium, 10));
  lst_pop_front(medium); // Reset value for later tests.


  /**
   * 4. Unit tests on function: void lst_reverse(LIST *l);
   */
  printf("\n\nTest: 4A\nDescription: Testing lst_reverse with List of length 0\nExpected output: []\n");
  printf("Your output: ");
  lst_reverse(empty);
  lst_print(empty);

  printf("\n\nTest: 4B\nDescription: Testing lst_reverse with List of length 1\nExpected output: [ 5 ]\n");
  printf("Your output: ");
  lst_reverse(one);
  lst_print(one);

  printf("\n\nTest: 4C\nDescription: Testing lst_reverse with List of length 10\nExpected output: [ 10  9  8  7  6  5  4  3  2  1 ]\n");
  printf("Your output: ");
  lst_reverse(medium);
  lst_push_back(medium, 99);
  lst_pop_back(medium); // Check for tail correctness.
  lst_print(medium);
  FREE(medium);

  /**
   * 6. Unit tests on void lst_insert_sorted(LIST *l, ElemType x);
   */
  evenList = lst_create();
  for(int i=1; i<=5; ++i) { lst_push_back(evenList, i*2); }
  printf("\n\nTest: 6A\nDescription: Testing lst_insert_sorted with List of length 0 and x=5\nExpected output: [ 5 ]\n");
  printf("Your output: ");
  lst_insert_sorted(empty, 5);
  lst_print(empty);
  FREE(empty);
  empty = lst_create(); // Resets value for later tests.

  printf("\n\nTest: 6B\nDescription: Testing lst_insert_sorted with List of length 5 and x=5\nExpected output: [ 2  4  5  6  8  10 ]\n");
  printf("Your output: ");
  lst_insert_sorted(evenList, 5);
  lst_print(evenList);
  FREE(evenList);
  evenList = lst_create();
  for(int i=1; i<=5; ++i) { lst_push_back(evenList, i*2); }

  printf("\n\nTest: 6C\nDescription: Testing lst_insert_sorted with List of length 5 and x=0\nExpected output: [ 0  2  4  6  8  10 ]\n");
  printf("Your output: " );
  lst_insert_sorted(evenList, 0);
  lst_print(evenList);
  FREE(evenList);
  evenList = lst_create();
  for(int i=1; i<=5; ++i) { lst_push_back(evenList, i*2); }

  printf("\n\nTest: 6D\nDescription: Testing lst_insert_sorted with List of length 5 and x=12\nExpected output: [ 2  4  6  8  10  12 ]\n");
  printf("Your output: ");
  lst_insert_sorted(evenList, 12);
  lst_print(evenList);
  FREE(evenList);
  evenList = lst_create();
  for(int i=1; i<=5; ++i) { lst_push_back(evenList, i*2); } // Reset value for later tests.


  /**
   * 8. Unit tests on void lst_merge_sorted(LIST *a, LIST *b);
   */
  printf("\n\nTest: 8A\nDescription: Testing lst_merge_sorted with List a of length 0 with elements [] and List b of length 0 with elements []\n");
  printf("Your output:");
  lst_merge_sorted(anotherEmptyList, empty);
  lst_print(anotherEmptyList);
  FREE(anotherEmptyList);
  FREE(empty);
  empty = lst_create();

  printf("\n\nTest: 8B\nDescription: Testing lst_merge_sorted with List a of length 1 with elements [ 5 ] and List b of length 0 with elements []\n");
  printf("\nExpected output: [ 5 ]\n");
  printf("Your output: ");
  lst_merge_sorted(one, empty);
  lst_print(one);
  FREE(one);
  FREE(empty);
  one = lst_create();
  empty = lst_create();
  lst_push_back(one, 10);

  printf("\n\nTest: 8C\nDescription: Testing lst_merge_sorted with List a of length 0 with elements [] and List b of length 1 with elements [ 10 ]\n");
  printf("\nExpected output: [ 10 ]\n");
  printf("Your output: ");
  lst_merge_sorted(empty, one);
  lst_print(empty);
  FREE(empty);
  FREE(one);
  empty = lst_create();
  one = lst_create();
  lst_push_back(one, 5);

  oddList = lst_create();
  for(int i=0; i<5; ++i) { lst_push_back(oddList, i*2+1); }
  printf("\n\nTest: 8D\nDescription: Testing lst_merge_sorted with List a of length 5 with elements [ 2  4  6  8  10 ] and List b of length 5 with elements [ 1  3  5  7  9 ]");
  printf("\nExpected output: [ 1  2  3  4  5  6  7  8  9  10 ]\n");
  printf("Your output: ");
  lst_merge_sorted(evenList, oddList);
  lst_print(evenList);
  FREE(evenList);
  FREE(oddList);

  evenList = lst_create();
  dupsOfevenList = lst_create();
  for (int i=1; i<=5; ++i) { lst_push_back(evenList, i*2); lst_push_back(dupsOfevenList, i*4); }
  printf("\n\nTest: 8E\nDescription: Testing lst_merge_sorted with List a of length 5 with elements [ 2  4  6  8  10 ] and List b of length 5 with elements [ 4  8  12  16  20 ]\n");
  printf("\nExpected output: [ 2  4  4  6  8  8  10  12  16  20 ]\n");
  printf("Your output: ");
  lst_merge_sorted(evenList, dupsOfevenList);
  lst_print(evenList);
  FREE(evenList);
  FREE(dupsOfevenList);


  /**
   * 10. Unit tests on LIST * lst_from_array(ElemType a[], int n);
   **/
  int emptyArray[] = {};
  int oneArray[] = {5};
  int manyArray[] = {1,2,3,4,5};

  printf("\n\nTest: 10A\nDescription: Testing lst_from_array with array of length 0 with elements [] and n=0\nExpected output: []\n");
  printf("Your output:");
  resultList = lst_from_array(emptyArray, 0);
  if (resultList) { lst_print(resultList); } else { printf("SEG FAULT. No List returned.\n"); }
  if (resultList) { FREE(resultList);}

  printf("\n\nTest: 10B\nDescription: Testing lst_from_array with Array of length 1 with elements [ 5 ] and n=1\nExpected output: [ 5 ]\n");
  printf("Your output:");
  resultList = lst_from_array(oneArray, 1);
  if (resultList) { lst_print(resultList); } else { printf("SEG FAULT. No List returned.\n"); }
  if (resultList) { FREE(resultList); }

  printf("\n\nTest: 10C\nDescription: Testing lst_from_array with Array of length 5 with elements [ 1  2  3  4  5 ] and n=5\nExpected output: [ 1  2  3  4  5 ]\n");
  printf("Your output:");
  resultList = lst_from_array(manyArray, 5);
  if (resultList) { lst_print(resultList); } else { printf("SEG FAULT. No List returned.\n"); }
  if (resultList) { FREE(resultList); }


  /**
   * 12. Unit tests for LIST * lst_prefix(LIST *lst, unsigned int k);
   */
  printf("\n\nTest: 12A\nDescription: Testing lst_prefix with List of length 0 with elements [] and k=0\nExpected output: []\n");
  printf("Expected return value: []\n");
  printf("Your output:");
  resultList = lst_prefix(empty, 0);
  lst_print(empty);
  printf("Your return value: ");
  if (resultList) { lst_print(resultList); } else { printf("SEG FAULT. No List returned.\n"); }
  if (resultList) { FREE(resultList); }
  FREE(empty);
  empty = lst_create();

  printf("\n\nTest: 12B\nDescription: Testing lst_prefix with List of length 0 with elements [] and k=3\nExpected output: []\n");
  printf("Expected return value: []\n");
  printf("Your output:");
  resultList = lst_prefix(empty, 3);
  lst_print(empty);
  printf("Your return value: ");
  if (resultList) { lst_print(resultList); } else { printf("SEG FAULT. No List returned.\n"); }
  if (resultList) { FREE(resultList); }
  FREE(empty);
  empty = lst_create();

  printf("\n\nTest: 12C\nDescription: Testing lst_prefix with List of length 1 with elements [ 5 ] and k=0\nExpected output: [ 5 ]\n");
  printf("Expected return value: []\n");
  printf("Your output:");
  resultList = lst_prefix(one, 0);
  lst_print(one);
  printf("Your return value: ");
  if (resultList) { lst_print(resultList); } else { printf("SEG FAULT. No List returned.\n"); }
  if (resultList) { FREE(resultList); }
  FREE(one);
  one = lst_create();
  lst_push_back(one, 5);

  evenList = lst_create();
  for(int i=1; i<=5; i++) { lst_push_back(evenList, i*2); }
  printf("\n\nTest: 12D\nDescription: Testing lst_prefix with List of length 5 with elements [ 2  4  6  8  10 ] and k=3\nExpected output: [ 8 10 ]\n");
  printf("Expected return value: [ 2  4  6 ]\n");
  printf("Your output: ");
  resultList = lst_prefix(evenList, 3);
  lst_print(evenList);
  printf("Your return value: ");
  if (resultList) { lst_print(resultList); } else { printf("SEG FAULT. No List returned.\n"); }
  if (resultList) { FREE(resultList); }
  FREE(evenList);


  /**
   * 14. Unit test for void lst_concat(LIST *a, LIST *b);
   */
  anotherEmptyList = lst_create();
  evenList = lst_create();
  oddList = lst_create();
  for(int i=1; i<=5; i++) { lst_push_back(evenList, i*2); lst_push_back(oddList, i*2-1); }  // 2 4 6 8 10
  printf("\n\nTest: 14A\nDescription: Testing lst_concat with List a of length 0 with elements [] and List b of length 0 with elements []\nExpected output: []\n");
  printf("Your output:");
  lst_concat(anotherEmptyList, empty);
  lst_print(anotherEmptyList);
  FREE(anotherEmptyList);
  FREE(empty);

  anotherEmptyList = lst_create();
  printf("\n\nTest: 14B\nDescription: Testing lst_concat with List a of length 1 with elements [ 5 ] and List b of length 0 with elements []\nExpected output: [ 5 ]\n");
  printf("Your output:");
  lst_concat(one, anotherEmptyList);
  lst_print(one);
  FREE(one);
  FREE(anotherEmptyList);
  anotherEmptyList = lst_create();
  one = lst_create();
  lst_push_back(one, 10);

  printf("\n\nTest: 14C\nDescription: Testing lst_concat with List a of length 0 with elements []");
  printf(" and List b of length 1 with elements [ 10 ]\nExpected output: [ 10 ]\n");
  printf("Your output:");
  lst_concat(anotherEmptyList, one);
  lst_print(anotherEmptyList);
  FREE(anotherEmptyList);
  FREE(one); 

  printf("\n\nTest: 14D\nDescription: Testing lst_concat with List a of length 5 with elements [ 2  4  6  8  10]");
  printf(" and List b of length 5 with elements [ 1  3  5  7  9 ]\nExpected output: [ 2  4  6  8  10  1  3  5  7  9 ]\n");
  printf("Your output:");
  lst_concat(evenList, oddList);
  lst_print(evenList);
  FREE(evenList);
  FREE(oddList);

  evenList = lst_create();
  dupsOfevenList = lst_create();
  for(int i=1; i<=5; ++i) { lst_push_back(evenList, i*2); lst_push_back(dupsOfevenList, i*4); }
  printf("\n\nTest: 14E\nDescription: Testing lst_concat with List a of length 5 with elements [ 2  4  6  8  10 ] and List b of length 5 with elements [ 4  8  12  16  20 ]\n"
    "Expected output: [ 2  4  6  8  10  4  8  12  16  20 ]\n");
  printf("Your output:");
  lst_concat(evenList, dupsOfevenList);
  lst_print(evenList);
  FREE(evenList);
  FREE(dupsOfevenList);
}
