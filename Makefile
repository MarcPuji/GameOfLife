CC = g++
CFLAGS = -Wall -I/usr/include/ -I.
LDFLAGS = -lncurses 
OBJ = main.o database.o plotter.o config_ini.o
DEPS = database.h config_ini.h plotter.h 

main.o: main.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

config_ini.o: config_ini.c database.h 
	$(CC) $(CFLAGS) -c -o $@ $<

plotter.o: plotter.c database.h
	$(CC) $(CFLAGS) -c -o $@ $<

database.o: database.c
	$(CC) $(CFLAGS) -c -o $@ $<

gameoflife: $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ) GOF 
