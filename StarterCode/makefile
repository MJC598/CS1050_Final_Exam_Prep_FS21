all : main.o finalexamprep.o
	gcc -std=c11 -g -Wall -Werror main.o finalexamprep.o -L. -o finalexampreptest

main.o : main.c finalexamprep.h
	gcc -std=c11 -g -Wall -Werror -c main.c

finalexamprep.o : finalexamprep.c finalexamprep.h
	gcc -std=c11 -g -Wall -Werror -c finalexamprep.c

clean:
	@rm -f *.o
	@rm -f finalexampreptest
	@echo "All clean!"