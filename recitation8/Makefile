CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lcriterion

all: test_r8

test_r8: test_r8.c r8.c
	$(CC) $(CFLAGS) -o test_r8 test_r8.c r8.c $(LDFLAGS)

test: test_r8
	./test_r8

clean:
	rm -f test_r8

.PHONY: all test clean