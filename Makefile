CC = gcc
CFLAGS = -Wall -g

all: test1 test2 test3

test1: tests_pt1.c llist.c
	$(CC) $(CFLAGS) tests_pt1.c llist.c -o test1

test2: tests_pt2.c llist.c
	$(CC) $(CFLAGS) tests_pt2.c llist.c -o test2

test3: ll_tst.c llist.c
	$(CC) $(CFLAGS) ll_tst.c llist.c -o test3

clean:
	rm -f test1 test2 test3