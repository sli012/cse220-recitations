.PHONY: preprocess clean

hello:hello.c
	gcc hello.c -o hello

preprocess:
	gcc -E hello.c > hello.i.c

clean:
	rm -f dos hello bitwise

dos:dos.c
	gcc dos.c -o dos
	./dos

bitwise:bitwise.c
	gcc bitwise.c -o bitwise
	./bitwise

