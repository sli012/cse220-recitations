OUTBIN  = r0

# PHONY tells make that these steps do not produce any files, Make will always run these steps.
.PHONY: clean build debug memcheck

clean:
	rm -f $(OUTBIN)

build:
	gcc ./r0.c -o $(OUTBIN)

# This step will do nothing when the file "ro" is up to date
# This will not work right now as main is not defined in r0.c
# It is this way because Criterion defines main when you link it. As shown in make test.
ro:
	gcc ./r0.c -o $(OUTBIN)

# Criterion
# The linking order matters! r0.c must come before test.c as it defines the add() function
test:
	gcc r0.c test_r0.c -lcriterion
	./a.out --verbose

# Valgrind
memcheck: 
	gcc -g valgrind.c -o $(OUTBIN)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(OUTBIN)

