CC = g++
CFLAGS = -Wall -I/usr/include/ -I.
LDFLAGS = -lncurses 
OBJ = main.o database.o plotter.o configuration_v2.o Acorn_insert.o Diehard_insert.o R_pentomino_insert.o
DEPS = database.h configuration_v2.h plotter.h 

main.o: main.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

configuration_v2.o: configuration_v2.c database.h 
	$(CC) $(CFLAGS) -c -o $@ $<

Acorn_insert.o: Acorn_insert.c database.h 
	$(CC) $(CFLAGS) -c -o $@ $<

Diehard_insert.o: Diehard_insert.c database.h 
	$(CC) $(CFLAGS) -c -o $@ $<

R_pentomino_insert.o: R_pentomino_insert.c database.h 
	$(CC) $(CFLAGS) -c -o $@ $<

plotter.o: plotter.c database.h
	$(CC) $(CFLAGS) -c -o $@ $<

database.o: database.c
	$(CC) $(CFLAGS) -c -o $@ $<

gameoflife: $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ) gameoflife
