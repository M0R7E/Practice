clear:
	rm -rf *.o *.a *_test

check_fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"` --dry-run --Werror

fmt:
	clang-format -style=LLVM -i `find -regex ".+\.[ch]"`

#--- quadratic solver
quad.o: quad.c quad.h
	gcc -g -c quad.c -o quad.o
quad.a: quad.o
	ar rc quad.a quad.o
quad_test.o: quad_test.c
	gcc -g -c quad_test.c -o quad_test.o
quad_test: quad_test.o quad.a
	gcc -g -o quad_test quad_test.o quad.a -lm
#--- 	

test: quad_test
	@for test in $(shell find . -maxdepth 1 -type f -regex '.*_test$$'); do \
		echo "$$test"; \
		./$$test || exit 1; \
	done
	