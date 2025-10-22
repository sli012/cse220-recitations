define RUN_AND_CLEAN
	@gcc -I include $1
	@./a.out
	@rm a.out
endef


r7: r7.c
	gcc r7_helper.c r7.c -o r7 -Iinclude
	./r7

enum: enum.c
	$(call RUN_AND_CLEAN,$<)

struct: struct.c
	$(call RUN_AND_CLEAN,$<)

union: union.c
	$(call RUN_AND_CLEAN,$<)