define RUN_AND_CLEAN
	@gcc -I include $1
	@./a.out
	@rm a.out
endef


arithmetic: pointer_arithmetic.c
	$(call RUN_AND_CLEAN,$<)

string: pointer_strings.c
	$(call RUN_AND_CLEAN,$<)

op: pointer_operators.c
	$(call RUN_AND_CLEAN,$<)