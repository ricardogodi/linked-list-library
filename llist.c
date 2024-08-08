#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
 * Author: Ricardo Gonzalez
 *
 * CS 211 - John Lillis
 * Project #4 - Linked List Functions
 *
 */

typedef struct node {
    ElemType val;
    struct node *next;
} NODE;

struct list_struct {
    NODE *front;
    NODE *back;
    int size;
};

/*
 * returns pointer to newly created empty list
 */
LIST *lst_create() {
    
    LIST *l = malloc(sizeof(LIST));
    
    l->front = NULL;
    l->back = NULL;
    l->size = 0;
    
    return l;
}

void lst_free(LIST *l) {
    
    NODE *p = l->front;
    NODE *pnext;
    
    while(p != NULL) {
        pnext = p->next;   // keeps us from de-referencing a freed ptr
        free(p);
        p = pnext;
    }
    
    free(l); // now free LIST
    l->size = 0;
}

void lst_print(LIST *l) {
    NODE *p = l->front;
    printf("[");
    while(p != NULL) {
        printf(FORMAT, p->val);
        p = p->next;
    }
    printf("]\n");
}

/**
 *   function:  lst_are_equal
 *   description:  returns true(1) if lst1 and lst2
 *            contain exactly the same sequenc of values.
 *            Returns 0 otherwise.
 **/
int lst_are_equal(LIST *lst1, LIST *lst2) {
    
    NODE* cur1 = lst1->front;
    NODE* cur2 = lst2->front;
    
    while ((cur1 != NULL) && (cur2 != NULL)) {
        if (cur1->val != cur2->val) {
            return 0;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    
    if ((cur1 != NULL) || (cur2 != NULL)) {
        return 0;
    }
    
    return 1;
}


void _printReverse(NODE *cur) {
    if (cur == NULL) {
        return;
    } else {
        _printReverse(cur->next);
        printf(FORMAT, cur->val);
    }
}

/**
 * print in reverse order
 * Hints:  recursive helper function
 */
void lst_print_rev(LIST *l) {
    NODE* cur = l->front;
    printf("[");
    _printReverse(cur);
    printf("]\n");
}

void lst_push_front(LIST *l, ElemType val) {
    
    NODE *p = malloc(sizeof(NODE));
    
    p->val = val;
    p->next = l->front;
    
    l->front = p;
    
    if(l->back == NULL)  { // was empty, now has one element
        l->back = p;
    }
    
    l->size++;
}

void lst_push_back(LIST *l, ElemType val) {
    
    NODE *p;
    
    if(l->back == NULL) {   // list empty - same as push_front
        lst_push_front(l, val);
    } else {  // at least one element before push
        
        p = malloc(sizeof(NODE));
        
        p->val = val;
        p->next = NULL;
        l->back->next = p;
        
        l->back = p;
        l->size++;
    }
}

/**
 *   modifications to enable this operation
 *   to execute in O(1) time.  (You will almost
 *   certainly modify other functions and the
 *   data structure itself -- see header).
 **/
int lst_length(LIST *l) {
    return l->size;
}

int lst_is_empty(LIST *l) {
    return l->front == NULL;
}

/**
 *    function:  lst_count
 *     description:  Counts number of occurrences
 *     		    of x in the list and returns
 *     		    that value.
 */
int lst_count(LIST *l, ElemType x) {
    
    NODE* cur = l->front;
    
    int nOccurrences = 0;
    
    while(cur != NULL) {
        if (cur->val == x) {
            nOccurrences++;
        }
        cur = cur->next;
    }
    
    return nOccurrences;
}

/* These are "sanity checker" functions that check to see
 *     list invariants hold or not.
 */
int lst_sanity1(LIST *l) {
    if(l->front == NULL && l->back != NULL){
        fprintf(stderr, "lst_sanity1 error:  front NULL but back non-NULL\n");
        return 0;
    }
    if(l->back == NULL && l->front != NULL){
        fprintf(stderr, "lst_sanity1 error:  back NULL but front non-NULL\n");
        return 0;
    }
    return 1;
}

int lst_sanity2(LIST *l) {
    if(l->back != NULL && l->back->next != NULL) {
        fprintf(stderr, "lst_sanity2 error:  back elem has a non-NULL next?\n");
        return 0;
    }
    return 1;
}

/*
 * function:  find_back()
 * description:  returns a pointer to the last
 *               node of the given list.
 *		Note that we are operating at
 *		the "node level".
 *
 *		if p is NULL, NULL is returned.
 *
 * purpose:  mostly for debugging -- enables sanity3
 */
static NODE * find_back(NODE *p) {
    
    if(p ==  NULL)
        return NULL;
    
    while(p->next != NULL) {
        p = p->next;
    }
    
    return p;
}

/*
 *   makes sure that the back pointer is also the last reachable
 *    node when you start walking from front.
 *    HINT:  use pointer comparison
 */
int lst_sanity3(LIST *l) {
    NODE *real_back;
    real_back = find_back(l->front);
    return (real_back == l->back);
}

ElemType lst_pop_front(LIST *l) {
    
    ElemType ret;
    NODE *p;
    
    if(lst_is_empty(l))
        return DEFAULT;   // no-op
    
    ret = l->front->val;
    
    if(l->front == l->back) {  // one element
        free(l->front);
        l->front = NULL;
        l->back = NULL;
    }
    else {
        p = l->front;  // don't lose node being deleted
        l->front = l->front->next;  // hop over
        free(p);
    }
    l->size--;
    return ret;
}

/*
 *    if list is empty, we do nothing and return arbitrary value
 *    otherwise, the last element in the list is removed and its
 *    value is returned.
 */
ElemType lst_pop_back(LIST *l) {
    
    ElemType ret;
    NODE *p = l->front;
    
    if(lst_is_empty(l)) {
        return DEFAULT;   // no-op
    }
    
    ret = l->back->val;
    
    if(l->front == l->back) {  // one element
        
        free(l->front);
        l->front = NULL;
        l->back = NULL;
        l->size--;
        
    } else {
        
        while(p->next->next != NULL) {
            p = p->next;
        }
        
        p->next = NULL;
        free(l->back);
        l->back = p;
        l->size--;
    }
    return ret;
}

void _reverse2(LIST* l, NODE* cur, NODE* prev) {
    
    NODE *tempNext = cur->next;
    
    if(l->front == cur) {
        l->back = l->front;
    }
    
    if (cur->next == NULL) {
        cur->next = prev;
        l->front = cur;
        return;
    }
    
    cur->next = prev;
    _reverse2(l, tempNext, cur);
    return;
}

/*
 * Recursive helper function
 */
void _reverse(LIST* l, NODE* pHead) {
    
    if (pHead->next == NULL) {
        l->front = pHead;
    } else {
        _reverse(l, pHead->next);
        pHead->next->next = pHead;
    }
}

/*
 *  You cannot allocate any new memory!
 *
 *  description:  self-evident
 */
void lst_reverse(LIST *l) {
    
    if (lst_length(l) == 1 || lst_length(l) == 0 ) {
        return;
    }
    
    NODE* temp = l->front;
    _reverse(l, l->front);
    temp->next = NULL;
    l->back = temp;
}

/*
 *   removes first occurrence of x (if any).  Returns
 *   0 or 1 depending on whether x was found
 */
int lst_remove_first(LIST *l, ElemType x) {
    
    NODE *p;
    NODE *tmp;
    
    if(l->front == NULL) return 0;
    if(l->front->val == x) {
        lst_pop_front(l);
        return 1;
    }
    
    // lst non-empty; no match on 1st elem
    p = l->front;
    
    while(p->next != NULL) {
        if(x == p->next->val) {
            tmp = p->next;
            p->next = tmp->next;
            if(tmp == l->back)
                l->back = p;
            free(tmp);
            return 1;
        }
        p = p->next;
    }
    return 0;
}

/**
 * function: lst_remove_all_slow
 * description:  removes all occurrences of x
 *   from given list (if any).
 *   Returns number of occurrences (i.e., deletions).
 *
 * notes:  it is called "slow" because in the worst
 *   case, it takes quadratic time.
 *   (Discussion of why and when this happens is a
 *   lecture topic).
 */
int lst_remove_all_slow(LIST *l, ElemType x) {
    int n=0;
    while(lst_remove_first(l, x)) {
        n++;
    }
    return n;
}

/** 
 * function: lst_sra_bad_case (sra:  slow_remove_all)
 *
 * description: constructs a list of length n such that
 * the above function takes quadratic time to remove
 * all occurrences of a specified value.
 *
 * By convention, the specified value will be 0
 */
LIST *lst_sra_bad_case(int n) {
    LIST *l = lst_create();
    int i;
    int k=n/2;
    
    for(i=0; i<k; i++) {
        lst_push_front(l, 0);
    }
    for(i=0; i<n-k; i++) {
        lst_push_front(l, 1);
    }
    return l;
}

/**
 *   function:  lst_remove_all_fast
 *   description:  same behavior/semantics as
 *      lst_remove_all_slow.  However, this function
 *      must guarantee linear time worst case
 *      runtime (hence, "fast").
 *
 *   REQUIREMENT:  linear worst-case runtime.
 *
 *   Note:  your solution may be either recursive or
 *   iteratieve.
 **/
int lst_remove_all_fast(LIST *l, ElemType x) {
    
    NODE *cur;
    NODE *prev = NULL;
    int n = 0;
    
    if(l->front == NULL) {
        return 0;
    }
    
    cur = l->front;
    
    while(cur != NULL) {
        
        if(x == cur->val) {
            
            if(cur == l->front && cur == l->back) {
                l->back = NULL;
                l->front = NULL;
                free(cur);
                cur = NULL;
            } else if(cur == l->front) {
                l->front = cur->next;
                free(cur);
                cur = l->front;
            } else if(cur == l->back) {
                l->back = prev;
                prev->next = NULL;
                free(cur);
                cur = NULL;
            } else {
                prev->next = cur->next;
                free(cur);
                cur = prev;
            }
            
            n++;
            l->size--;
            
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return n;
}

int lst_is_sorted(LIST *l){
    
    NODE *p = l->front;
    
    while(p!=NULL && p->next != NULL) {
        if(p->val > p->next->val)
            return 0;
        p = p->next;
    }
    
    return 1;
}

/**
 * function:  lst_insert_sorted
 *
 * description:  assumes given list is already in sorted order
 *	        and inserts x into the appropriate position
 * 	        retaining sorted-ness.
 * Note 1:  duplicates are allowed.
 *
 * Note 2:  if given list not sorted, behavior is undefined/implementation
 * 		dependent.  We blame the caller.
 * 		So... you don't need to check ahead of time if it is sorted.
 */
void lst_insert_sorted(LIST *l, ElemType x) {
    NODE* cur = l->front;
    NODE* prev = NULL;
    if(l->front == NULL) {
        lst_push_back(l, x);
        return;
    }
    if(x >= l->back->val) {
        lst_push_back(l, x);
        return;
    }
    if(x <= l->front->val) {
        lst_push_front(l, x);
        return;
    }
    while (cur != NULL) {
        if(x < cur->val ) {
            NODE *newNode = malloc(sizeof(NODE));
            newNode->val = x;
            newNode->next = cur;
            prev->next = newNode;
            l->size++;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}


// TRY WITH:
/*
 2 3
 1 4 5
 
 4 5
 1 2 3
 
 1 2
 3 4 5
 
 1 5
 2 3 4
 
 1 3 5
 2 4
 
 2 4
 1 3 5
 
 */

/**
 * function:  lst_merge_sorted
 *
 * description:  assumes both list a and b are in
 *      	sorted (non-descending) order and merges them
 * 	        into a single sorted list with the same
 *      	elements.
 *
 * 	This single sorted list is stored in a while
 * 	b becomes empty.
 *
 * 	if either of given lists are not sorted,
 * 	we blame the caller and the behavior is
 * 	implementation dependent -- i.e., don't worry
 * 	about it!
 *
 * 	Example:
 *
 * 		a:  [2 3 4 9 10 30]
 * 		b:  [5 8 8 11 20 40]
 *
 * 		after call on (a,b)
 *
 * 		a:  [2 3 4 5 8 8 9 10 11 20 30 40]
 * 		b:  []
 *
 * implementation:  should not allocate ANY new list
 *             nodes -- it should just re-link existing
 * 	           nodes.
 *
 * 	Must be linear time in the |a|+|b| -- i.e.,
 * 	the total number of elements being processed.
 */

void lst_merge_sorted(LIST *a, LIST *b){
    
    if(a->front == NULL) {
        a->front = b->front;
        a->back = b->back;
        b->back = NULL;
        b->front = NULL;
        return;
    }
    
    NODE* aCur = a->front;
    NODE* aPrev = NULL;
    NODE* bCur = b->front;
    a->size = a->size + b->size;
    
    while(b->size != 0) {
        
        if (bCur->val < aCur->val) {
            
            b->front = b->front->next;
            b->size--;
            bCur->next = aCur;
            
            if (aCur == a->front) {
                
                a->front = bCur;
                aPrev = a->front;
                
            } else {
                
                aPrev->next = bCur;
                aPrev = bCur;
            }
            
            bCur = b->front;
            
        } else {
            
            if (aCur == a->back) { // reached the end of a
                
                aCur->next = bCur;
                a->back = b->back;
                b->size = 0;
                
            } else {
                
                aPrev = aCur;
                aCur = aCur->next;
            }
        }
    }
    b->back = NULL;
    b->front = NULL;
}

/**
 * function:  lst_clone
 *
 * description:  makes a "deep copy" of the given list a
 *          and returns it (as a LIST pointer).
 */
LIST * lst_clone(LIST *a) {
    
    NODE* cur = a->front;
    LIST* newList = lst_create();
    
    while (cur != NULL) {
        lst_push_back(newList, cur->val);
        cur = cur->next;
    }
    return newList;
}

/**
 *
 * function:  lst_from_array
 *
 * description:  creates a new list populated with the
 *      elements of array a[] in the same order as
 *      they appear in a[] (element at a[0] will be the
 *      first element in the list and so-on).  List is
 *      returned as a LIST pointer.
 *
 *      Parameter n indicates the length of the given array.
 *
 * runtime requirement:  THETA(n)
 */
LIST * lst_from_array(ElemType a[], int n) {
    LIST* newList = lst_create();
    for (int i = 0; i < n; i++) {
        lst_push_back(newList, a[i]); // push_back is O(1)
    }
    return newList;
}

// IF THERE WASN'T A POINTER TO BACK(
// THETA(logn)   KIND OF REPEAT PUSH BACK!
LIST * lst_from_arrayOTHER(ElemType a[], int n) {
    LIST* newList = lst_create();
    for (int i = 0; i < n; i++) {
    }
    return newList;
}

/**
 * function:  lst_to_array
 *
 * description:  allocates an array of ElemType and populates
 *          it with the elements in the given list (as with
 *          lst_from_array elements are in the same order in
 *          both data structures).
 *
 * runtime requirement:  THETA(n)
 */
ElemType * lst_to_array(LIST *lst) {
    NODE *cur = lst->front;
    int n = lst->size;
    ElemType* arr = malloc(sizeof(ElemType) * n);
    
    for (int i = 0; i < n; i++) {
        arr[i] = cur->val;
        cur = cur->next;
    }
    return arr;
}

/**
 * function:  lst_prefix
 *
 * description:  removes the first k elements from the
 *          given list which are used to form a new list
 *		    which is then returned.
 *
 *		if n is the length of the given list, we have the
 *		following boundary conditions:
 *
 *		  if k==0:
 *			lst unchanged and an empty list returned
 *		  if k>=n:
 *			lst becomes empty and a list containing
 *			all elements previously in lst is returned.
 *
 *		examples:
 *
 *		  EX1:  lst:  [2, 3, 9, 7, 8]
 *			k:    3
 *
 *			after call:
 *			   lst:  [7, 8]
 *			   returned list:  [2, 3, 9]
 *
 *		  EX2  lst:  [2, 3, 9, 7, 8]
 *			k:    0
 *
 *			after call:
 *			   lst:  [2, 3, 9, 7, 8]  (unchanged)
 *			   returned list:  []
 *
 *		  EX3  lst:  [2, 3, 9, 7, 8]
 *			k:    5
 *
 *			after call:
 *			   lst:  []
 *			   returned list:  [2, 3, 9, 7, 8]
 *
 * REQUIREMENTS:
 *
 *	RUNTIME:  THETA(n) worst case where n is the length of the given list
 *
 *       ORDERING:  the ordering of the returned prefix should be the same as
 *                  in the given list
 *
 *       MEMORY:    for full credit, no new nodes should be allocated or deallocated;
 *		   you should just "re-use" the existing nodes.  HOWEVER, you will
 *		   need to allocate a LIST structure itself (i.e., for the returned
 *		   list).
 */

LIST * lst_prefix(LIST *lst, unsigned int k) {
    
    LIST* newList = lst_create();
    
    if (k > 0 && k < lst->size) {
        
        NODE* cur = lst->front;
        
        for (int i = 1; i < k; i++) {
            cur = cur->next;
        }
        
        newList->front = lst->front;
        newList->back = cur;
        
        lst->front = cur->next;
        cur->next = NULL;
        
        newList->size = k;
        lst->size = lst->size - k;
        
    } else if (k <= lst->size) {
        
        newList->front = lst->front;
        newList->back = lst->back;
        
        lst->front = NULL;
        lst->back = NULL;
        
        newList->size = lst->size;
        lst->size = 0;
    }
    
    return newList;
    
}

// Previous prefix function:
/*
 LIST* newList = lst_create();
 
 if (k == 0 || lst->front == NULL) {
 return newList;
 }
 
 NODE* cur = lst->front;
 newList->front = lst->front;
 
 for (int i = 1; i < k; i++) {
 cur = cur->next;
 }
 
 lst->front = cur->next;
 newList->back = cur;
 newList->size = k;
 lst->size = lst->size - k;
 
 if(cur != NULL) {
 cur->next = NULL;
 }
 
 return newList;
 */


/**
 * function:  lst_filter_leq
 *
 * description:  removes all elements of the given list (lst) which
 *		    are less than or equal to a given value (cutoff)
 *
 *	A list containing the removed elements is returned.
 *
 * Examples:
 *
 *	EX1: 	lst:  [4, 9, 2, 4, 8, 12, 7, 3]
 *		cutoff:  4
 *
 *		after call:
 *			lst:  [9, 8, 12, 7]
 *			returned list:  [4, 2, 4, 3]
 *
 *       -----------------------------------------
 *	EX2: 	lst:  [6, 5, 2, 1]
 *		cutoff:  6
 *
 *		after call:
 *			lst:  []
 *	 		returned list:  [6, 5, 2, 1]
 *
 * REQUIREMENTS:
 *
 *	RUNTIME:  THETA(n) where n is the length of the given list
 *
 *       ORDERING:  the ordering of the returned list should be the same as
 *                  in the given list
 *
 *       MEMORY:    for full credit, no new nodes should be allocated or deallocated;
 *		   you should just "re-use" the existing nodes.  HOWEVER, you will
 *		   need to allocate a LIST structure itself (i.e., for the returned
 *		   list).
 *
 */
/*
 LIST * lst_filter_leq(LIST *lst, ElemType cutoff) {
 
 LIST* newList = lst_create();
 NODE* cur = lst->front;
 NODE* prev = NULL;
 
 while(cur != NULL) {
 
 if(cur->val <= cutoff) {
 
 if(newList->size == 0) {
 
 newList->front = cur;
 newList->back = cur;
 
 if (cur == lst->front) {
 lst->front = cur->next;
 cur =  lst->front;
 } else {
 prev->next = cur->next;
 cur = prev->next;
 }
 newList->back->next = NULL;
 
 } else {
 
 newList->back->next = cur;
 newList->back = cur;
 
 if (cur == lst->front) {
 cur = cur->next;
 lst->front = cur;
 } else {
 prev->next = cur->next;
 cur = cur->next;
 }
 newList->back->next = NULL;
 }
 
 lst->size--;
 newList->size++;
 
 } else {
 prev = cur;
 cur = cur->next;
 }
 }
 return newList;
 }
 */


LIST * lst_filter_leq(LIST *lst, ElemType cutoff) {
    
    LIST* newList = lst_create();
    NODE* cur = lst->front;
    
    NODE* prev = NULL;
    
    while (cur != NULL) {
        
        if (cur->val <= cutoff) {
            
            if (newList->size == 0) {
                newList->front = cur;
            } else {
                newList->back->next = cur;
            }
            
            newList->back = cur;

            if (cur == lst->back && cur == lst->front) {
                lst->back = NULL;
                lst->front = NULL;
            } else if (cur == lst->front) {
                lst->front = cur->next;
            } else if (cur == lst->back) {
                lst->back = prev;
                lst->back->next = NULL;
            } else {
                prev->next = cur->next;
            }
            
            cur = cur->next;
            
            newList->back->next = NULL; // Unlink
            
            lst->size--;
            newList->size++;
            
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return newList;
}













/**
 * function:  lst_concat
 *
 * description:  concatenates lists a and b; resulting
 *          concatenation is reflected in list a; list b becomes
 *          empty.
 *
 *  Example:
 *
 *	EX1:  a: [2, 9, 1]
 *	      b: [5, 1, 2]
 *
 *	after call:
 *
 *		a: [2, 9, 1, 5, 1, 2]
 *		b: []
 *
 * REQUIREMENTS:
 *
 *     runtime:  O(1)
 *
 *     sanity:  this operation makes sense when a and b
 *		are distinct lists.  For example, we don't
 *		want/allow the caller to do something like
 *		this:
 *
 *			LIST *my_list;
 *
 *			lst_push_front(my_lst, 4);
 *			lst_push_front(my_lst, 2);
 *
 *			lst_concat(my_lst, my_lst);
 *
 *		your implementation must detect if it is being
 *		called this way.  If so the function does nothing
 *		and (optionally) prints an error message to
 *		stderr.
 *
 */
void lst_concat(LIST *a, LIST *b) {
    
    if(a == b || b->front == NULL) {
        return;
    } else if (a->front == NULL) {
        a->front = b->front;
        a->back = b->back;
    } else {
        a->back->next = b->front;
        a->back = b->back;
        a->size = a->size + b->size;
        b->size = 0;
    }
    b->front = NULL;
    b->back = NULL;
}
