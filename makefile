CC = gcc
CFLAGS = -I.
DEPS = alphabet_soup.h
OBJ = main.o alphabet_soup.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

alphabet: $(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS)
