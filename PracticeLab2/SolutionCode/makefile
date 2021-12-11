all : main.o battle.o
	gcc -std=c11 -g -Wall -Werror main.o battle.o -L. -o practicelab2

main.o : main.c battle.h
	gcc -std=c11 -g -Wall -Werror -c main.c

battle.o : battle.c battle.h
	gcc -std=c11 -g -Wall -Werror -c battle.c

clean:
	@rm -f *.o
	@rm -f practicelab2
	@echo "All clean!"