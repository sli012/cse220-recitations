OUTBIN  = r0

.PHONY: clean build debug memcheck

clean:
	rm -f $(OUTBIN)

build:
	gcc ./r0.c -o $(OUTBIN)

# The linking order matters! r0.c must come before test.c as it defines the add() function
test:
	gcc r0.c test_r0.c -lcriterion
	./a.out --verbose

ro:
	gcc ./r0.c -o $(OUTBIN)

memcheck: 
	gcc -g valgrind.c -o $(OUTBIN)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(OUTBIN)

