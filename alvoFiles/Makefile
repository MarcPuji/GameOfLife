CC = g++
CFLAGS = -Wall -I/usr/include/ -I.
LDFLAGS = -lncurses 
OBJ = main.o updater.o config_ini.o
DEPS = database.h tryingfunc.h 

database.o: database.c database.h
	$(CC) $(CFLAGS) -c -o $@ $<

tryingfunc.o: tryingfunc.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

updater.o: updater.c cellstruct.h
	$(CC) $(CFLAGS) -c -o $@ $<

GOF: $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ) GOF 
