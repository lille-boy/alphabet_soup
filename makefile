CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
DEPS = alphabet_soup.h tests.h
OBJ = main.o alphabet_soup.o tests.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

alphabet: $(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS)

clean:
	rm *.o
