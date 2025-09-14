define RUN_AND_CLEAN
	@gcc -I include $1
	@./a.out
	@rm a.out
endef

loop: bit_loop.c
	$(call RUN_AND_CLEAN,$<)

array: array.c
	$(call RUN_AND_CLEAN,$<)

string: string.c
	$(call RUN_AND_CLEAN,$<)

extra: extra.c
	$(call RUN_AND_CLEAN,$<)
	
header_demo: header_demo.c
	$(call RUN_AND_CLEAN,$<)

header_preprocess: header_demo.c
	@gcc -E -I include header_demo.c > header_demo.i.c

