CFLAGS= -Wall -Wextra -Werror -pedantic -std=c99
SRC= $(wildcard src/*.c)
OBJ= ${SRC:.c=.o}

all: myfind
myfind: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o myfind
clean:
	rm $(OBJ) myfind
