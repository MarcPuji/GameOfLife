CC = g++
CFLAGS = -Wall -I/usr/include/ -I.
LDFLAGS = -lncurses
OBJ = main.o database.o plotter.o configuration_v2.o R_pentomino_insert.o Diehard_insert.o Acorn_insert.o
DEPS = plotter.h configuration_v2.h include/database.h include/R_pentomino_insert.h include/Diehard_insert.h include/Acorn_insert.h
DEPS2 = include/database.h include/R_pentomino_insert.h include/Diehard_insert.h include/Acorn_insert.h

main.o: main.c plotter.h configuration_v2.h include/database.h
	$(CC) $(CFLAGS) -c -o $@ $<

configuration_v2.o: configuration_v2.c $(DEPS2)
	$(CC) $(CFLAGS) -c -o $@ $<

R_pentomino_insert.o: include/R_pentomino_insert.c include/database.h
	$(CC) $(CFLAGS) -c -o $@ $<

Diehard_insert.o: include/Diehard_insert.c include/database.h
	$(CC) $(CFLAGS) -c -o $@ $<

Acorn_insert.o: include/Acorn_insert.c include/database.h
	$(CC) $(CFLAGS) -c -o $@ $<

plotter.o: plotter.c include/database.h
	$(CC) $(CFLAGS) -c -o $@ $<

database.o: include/database.c
	$(CC) $(CFLAGS) -c -o $@ $<

gameoflife: $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ) gameoflife
