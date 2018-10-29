CC = g++
CFLAGS = -Wall -I/usr/include/ -I.
LDFLAGS = -lncurses
OBJ = main.o updater.o configuration_arr.o R_pentomino_insert_arr.o Diehard_insert_arr.o Acorn_insert_arr.o
DEPS = updater.h include/cellstruct.h include/configuration_arr.h include/R_pentomino_insert_arr.h include/Diehard_insert_arr.h include/Acorn_insert_arr.h
DEPS2 = include/cellstruct.h include/R_pentomino_insert_arr.h include/Diehard_insert_arr.h include/Acorn_insert_arr.h

main.o: main.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

configuration_arr.o: include/configuration_arr.c $(DEPS2)
	$(CC) $(CFLAGS) -c -o $@ $<

R_pentomino_insert_arr.o: include/R_pentomino_insert_arr.c include/cellstruct.h
	$(CC) $(CFLAGS) -c -o $@ $<

Diehard_insert_arr.o: include/Diehard_insert_arr.c include/cellstruct.h
	$(CC) $(CFLAGS) -c -o $@ $<

Acorn_insert_arr.o: include/Acorn_insert_arr.c include/cellstruct.h 
	$(CC) $(CFLAGS) -c -o $@ $<

updater.o: updater.c include/cellstruct.h
	$(CC) $(CFLAGS) -c -o $@ $<

gameoflife: $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ) gameoflife
