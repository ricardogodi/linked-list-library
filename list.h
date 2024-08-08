

//

/** ElemType may be changed for application
 * specific needs.
 *
 * However, it should be a numeric type.
 */

typedef int ElemType;
#define FORMAT " %i "
#define DEFAULT 0

// hidden implementation of list_struct
typedef struct list_struct LIST;

extern LIST *lst_create(void);
extern void lst_free(LIST *l);
extern void lst_print(LIST *l); 

extern void lst_push_front(LIST *l, ElemType val); 
extern void lst_push_back(LIST *l, ElemType val); 

/** TODO
 * function:  lst_length
 *
 * description:  returns the length of the given list.
 *
 * CONSTRAINTS:
 *
 *      runtime:  O(1)
 *		  (you will rewrite the THETA(n) version
 *		  already given to you).
 *
 * NOTES:
 *
 *      since the LIST struct is "hidden" in the .c file,
 *      you ARE free to change it; this will almost certainly
 *      be necessary to achive the O(1) runtime.
 *
 *      furthermore, the real work you do to make this work
 *	in O(1) time will be in _other_ functions which affect
 *	the length of lists.
 */
extern int lst_length(LIST *l);

extern int lst_is_empty(LIST *l);

/** TODO
 *    function:  lst_count
 *     description:  Counts number of occurrences 
 *     		of x in the list and returns 
 *     		that value.
 */
extern int lst_count(LIST *l, ElemType x); 

// sanity checker functions - DONE
extern int lst_sanity1(LIST *l);
extern int lst_sanity2(LIST *l);
extern int lst_sanity3(LIST *l);

extern ElemType lst_pop_front(LIST *l); 


/** TODO
 * function:  lst_pop_back
 *
 * description:  removes last element from list
 * 	and returns that value.
 *
 * Note:  if list is empty, the return value is
 * 	implementation specific -- i.e., caller's
 * 	fault.  Optionally, your implementation can
 *	print a message to stderr
 *
 * RUNTIME:  THETA(n)
 */
extern ElemType lst_pop_back(LIST *l);

/**
 *
 * TODO:  
 *   function:  lst_are_equal
 *   description:  returns true(1) if lst1 and lst2
 *      contain exactly the same sequenc of values.
 *      Returns 0 otherwise.
 **/
int lst_are_equal(LIST *lst1, LIST *lst2);

/** TODO
 * function:  lst_print_rev
 *
 * description:  prints the elements of the list
 * 	but in reverse order.
 */
extern void lst_print_rev(LIST *l); 


/** TODO 
 * function:  lst_reverse
 *
 * description:  reverses the given list.
 * 	this is different from printing it
 * 	in reverse order!
 *
 * 	The ordering of the actual list is
 * 	reversed.
 *
 * constraints:  
 *
 *	for full credit,  NO MEMORY ALLOCATION is 
 *	allowed in this function; it just re-links 
 *	the already existing nodes
 *
 *	RUNTIME:  THETA(n)
 */
extern void lst_reverse(LIST *l); 


/**  DONE
 * function:  lst_remove_first
 *
 * Description:  The FIRST OCCURRENCE of x 
 *    in list (if any) is removed.
 *    If x not in list, list is unchanged.
 *
 *    NOT THE SAME AS lst_pop_front
 *
 * returns 1 if removal made; 0 otherwise
 */ 
extern ElemType lst_remove_first(LIST *l, ElemType x) ;


/** DONE
 * function:  lst_remove_all_slow
 *
 * description:  removes all occurrences of x
 *    from list and returns number of matches.
 *
 * implementation:  simply repeatedly calls 
 *    lst_remogve_first on x until it fails.
 *
 * why is it slow?
 *
 *   The number of operations this function performs
 *   may depends on:
 *              n:  the length of the list
 *              m:  the number of matches of x
 *              maybe the structure of the list
 *                 (e.g., where in the list the
 *                 matches occur).
 *
 *   It seems like we should be able to perform
 *   the operation in time proportional to n.
 *
 *   However, I claim that there are cases for which
 *   the approach of lst_remove_all_slow takes time
 *   proportional to n^2 
 */
extern ElemType lst_remove_all_slow(LIST *l, ElemType x) ;

/** 
 * DONE  
 * function: lst_sra_bad_case (sra:  slow_remove_all)
 *
 * description: constructs a list of length n such that 
 * the above function takes quadratic time to remove
 * all occurrences of a specified value. 
 *
 * By convention, the specified value will be 0
 */
extern LIST *lst_sra_bad_case(int n); 

/** TODO
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
extern int lst_remove_all_fast(LIST *l, ElemType x) ;

/** DONE
 * function:  lst_is_sorted
 *
 * description:  returns 1 if the list is sorted in 
 * 	non-decreasing order; 0 otherwise
 */
extern int lst_is_sorted(LIST *l);


/** TODO
 * function:  lst_insert_sorted
 *
 * description:  assumes given list is already in sorted order
 *	   and inserts x into the appropriate position
 * 	   retaining sorted-ness.
 * Note 1:  duplicates are allowed.
 *
 * Note 2:  if given list not sorted, behavior is undefined/implementation
 * 		dependent.  We blame the caller.
 * 		So... you don't need to check ahead of time if it is sorted.
 */
extern void lst_insert_sorted(LIST *l, ElemType x);

/** TODO
 * function:  lst_merge_sorted
 *
 * description:  assumes both list a and b are in
 * 	sorted (non-descending) order and merges them
 * 	into a single sorted list with the same
 * 	elements.  
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
 * 	nodes -- it should just re-link existing
 * 	nodes.
 *
 * 	Must be linear time in the |a|+|b| -- i.e.,
 * 	the total number of elements being processed.
 */
extern void lst_merge_sorted(LIST *a, LIST *b);

/**
 *
 * TODO
 *
 * function:  lst_clone
 *
 * description:  makes a "deep copy" of the given list a
 *   and returns it (as a LIST pointer).
 *
 */
extern LIST * lst_clone(LIST *a);

/**
 * TODO
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
extern LIST * lst_from_array(ElemType a[], int n); 

/**
 * TODO
 *
 * function:  lst_to_array 
 *
 * description:  allocates an array of ElemType and populates
 *         it with the elements in the given list (as with
 *         lst_from_array elements are in the same order in
 *         both data structures).
 *
 * runtime requirement:  THETA(n)
 *
 */
extern ElemType * lst_to_array(LIST *lst);

/**
 * TODO
 * function:  lst_prefix
 *
 * description:  removes the first k elements from the
 *               given list which are used to form a new list
 *		which is then returned.
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
extern LIST * lst_prefix(LIST *lst, unsigned int k);

/**
 * TODO
 *
 * function:  lst_filter_leq
 *
 * description:  removes all elements of the given list (lst) which
 *		are less than or equal to a given value (cutoff)
 *		
 *		A list containing the removed elements is returned.
 *
 * examples:
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
extern LIST * lst_filter_leq(LIST *lst, ElemType cutoff);

/**
 * TODO
 * function:  lst_concat
 *
 * description:  concatenates lists a and b; resulting
 *    concatenation is reflected in list a; list b becomes
 *    empty.
 *
 *    example:
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
extern void lst_concat(LIST *a, LIST *b);
