define RUN_AND_CLEAN
	@gcc -I include $1
	@./a.out
	@rm a.out
endef

main: main.c
	gcc main.c -o main_demo

string: string.c
	$(call RUN_AND_CLEAN,$<)

examples: string_examples.c
	$(call RUN_AND_CLEAN,$<)