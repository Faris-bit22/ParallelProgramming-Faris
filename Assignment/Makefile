assignment: main.c
	gcc -g -Wall -Wextra -o assignment main.c

valgrind: assignment
	valgrind --leak-check=full --track-origins=yes ./assignment 5

clean:
	rm -f assignment