all: main.c
	gcc -Wall -Wextra -Werror -ansi -pedantic -o run *.c
	./run

clean:
	gcc -o run *.c
	./run

zip:
	rm proj2.zip
	zip proj2.zip *.c *.h

test:
	gcc -Wall -Wextra -Werror -ansi -pedantic -o run *.c
	sudo python3 tester.py ./run