CC = gcc
CFLAGS = -Wall -I/usr/include/ -I.
LDFLAGS = -lncurses
OBJ = main.o updater.o configuration_arr.o R_pentomino_insert_arr.o Diehard_insert_arr.o Acorn_insert_arr.o
DEPS = cellstruct.h configuration_arr.h updater.h R_pentomino_insert_arr.h Diehard_insert_arr.h Acorn_insert_arr.h

main.o: main.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

configuration_arr.o: configuration_arr.c cellstruct.h R_pentomino_insert_arr.h Diehard_insert_arr.h Acorn_insert_arr.h
	$(CC) $(CFLAGS) -c -o $@ $<

R_pentomino_insert_arr.o: R_pentomino_insert_arr.c cellstruct.h
	$(CC) $(CFLAGS) -c -o $@ $<

Diehard_insert_arr.o: Diehard_insert_arr.c cellstruct.h
	$(CC) $(CFLAGS) -c -o $@ $<

Acorn_insert_arr.o: Acorn_insert_arr.c cellstruct.h 
	$(CC) $(CFLAGS) -c -o $@ $<

updater.o: updater.c cellstruct.h
	$(CC) $(CFLAGS) -c -o $@ $<

gameoflife: $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ) gameoflife
