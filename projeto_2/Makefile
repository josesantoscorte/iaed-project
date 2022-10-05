all: main.c
	gcc -Wall -Wextra -Werror -ansi -pedantic -o run main.c parsing.c aeroportos.c sorting.c
	./run

zip:
	rm proj2.zip
	zip proj2.zip main.c parsing.c parsing.h aeroportos.c aeroportos.h