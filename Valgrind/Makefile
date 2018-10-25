CC = gcc
CFLAGS = -Wall -I/usr/include/ -I.
LDFLAGS = -lncurses 
OBJ = main.o updater.o config_ini.o
DEPS = cellstruct.h config_ini.h updater.h 

main.o: main.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

config_ini.o: config_ini.c cellstruct.h 
	$(CC) $(CFLAGS) -c -o $@ $<

updater.o: updater.c cellstruct.h
	$(CC) $(CFLAGS) -c -o $@ $<

GOF: $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ) GOF 
